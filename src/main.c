#include "WProgram.h"
#include "usb_dev.h"
#include "usb_keyboard.h"
//#include "debug.h"


// set this for layer changes that need to persist beyond one cycle
unsigned char current_layer_number = 0;


unsigned char row_pins[] = { 0, 1, 2, 3 };
unsigned char column_pins[] = { 6, 7, 8, 9, 10,  14, 15, 16, 17, 18, 19 };
#define ROW_COUNT     ( sizeof(row_pins) / sizeof(row_pins[0]) ) // 4
#define COLUMN_COUNT  ( sizeof(column_pins) / sizeof(column_pins[0]) ) //11
#define KEY_COUNT     ( ROW_COUNT * COLUMN_COUNT )

#include "layout.h"

unsigned char matrix_state[KEY_COUNT * LAYER_COUNT];



void clear_keys() {
  keyboard_modifier_keys = 0;

  int i;
  for (i = 0; i < 6; i++) {
    keyboard_keys[i] = 0;
  }
}



// Matrix scanning logic
void heat_up(uint8_t col, uint8_t row) {
  unsigned int i = current_layer_number * KEY_COUNT + row * COLUMN_COUNT + col;
  if (matrix_state[i] >= DEBOUNCE_PASSES) {
    matrix_state[i] = DEBOUNCE_PASSES * 2;
  }
  else {
    matrix_state[i]++;
  }
}

void cool_down(uint8_t col, uint8_t row) {
  unsigned int i = current_layer_number * KEY_COUNT + row * COLUMN_COUNT + col;
  if (matrix_state[i] > DEBOUNCE_PASSES) {
    matrix_state[i]--;
  }
  else {
    matrix_state[i] = 0;
  }
}

void cool_down_inactive_layers() {
  uint8_t l, k, i;

  for (l = 0; l < LAYER_COUNT; l++) {
    if (l != current_layer_number) {
      for (k = 0; k < KEY_COUNT; k++) {
        i = l * KEY_COUNT + k;
        if (matrix_state[i] > DEBOUNCE_PASSES) {
          matrix_state[i]--;
        }
        else {
          matrix_state[i] = 0;
        }
      }
    }
  }
}


void activate_row(int row) {
  digitalWrite(row_pins[row], LOW);
  delay(ROW_HEATUP); // For more stable readings
};

void deactivate_row(int row) {
  digitalWrite(row_pins[row], HIGH);
};


// Cycle functions

void scan_keys() {
  uint8_t r, c;
  for (r = 0; r < ROW_COUNT; r++) {
    activate_row(r);

    for (c = 0; c < COLUMN_COUNT; c++) {
      if (digitalRead(column_pins[c]) == LOW) {
        //record(c, r);
        heat_up(c, r);
      }
      else {
        cool_down(c, r);
      }
    }

    deactivate_row(r);
  }
}

void pre_invoke_functions() {
  uint32_t i;
  for (i = 0; i < LAYER_COUNT * KEY_COUNT; i++) {
    if (matrix_state[i] >= DEBOUNCE_PASSES ) {
      uint8_t layer = i / KEY_COUNT;
      uint8_t row = (i - layer * KEY_COUNT) / COLUMN_COUNT;
      // Keys are wired from right to left but layout goes from left to right
      uint8_t column = COLUMN_COUNT - (i - layer * KEY_COUNT - row * COLUMN_COUNT + 1);
      uint64_t keycode = layers[layer][row * COLUMN_COUNT + column];
      if (IS_PRE_FUNCTION(keycode)) {
        /*
        DEBUG("pre: ");
        debug_phex(keycode & PRE_FUNCTION_MASK);
        DEBUG("\r\n");
        */
        (layer_functions[keycode & PRE_FUNCTION_MASK])();
      }
    }
  }
  per_cycle();
}

void calculate_presses() {
  uint8_t usb_presses = 0;
  uint32_t i;
  for (i = 0; i < LAYER_COUNT * KEY_COUNT; i++) {
    if (matrix_state[i] >= DEBOUNCE_PASSES ) {
      uint8_t layer = i / KEY_COUNT;
      uint8_t row = (i - layer * KEY_COUNT) / COLUMN_COUNT;
      // Keys are wired from right to left but layout goes from left to right
      uint8_t column = COLUMN_COUNT - (i - layer * KEY_COUNT - row * COLUMN_COUNT + 1);
      uint64_t keycode = layers[layer][row * COLUMN_COUNT + column];
      //DEBUG("keypress: ");
      //debug_phex64(keycode);
      //DEBUG("\r\n");
      if (IS_FUNCTION(keycode)) {
        // regular layout functions
        (layer_functions[keycode & FUNCTION_MASK])();
      } else if (IS_PRE_FUNCTION(keycode)) {
        // pre-invoke functions have already been processed
      } else if (IS_LAYER(keycode)) {
        // layer set
        //DEBUG("layer");
        current_layer_number = keycode & LAYER_MASK;
      } else if (IS_MODIFIER_KEY(keycode)) {
        // modifier keys do not take a spot in keys array
        keyboard_modifier_keys |= MODIFIERS(keycode);
      } else if (IS_REGULAR_KEY(keycode)) {
        if (usb_presses < 6) {
          keyboard_modifier_keys |= MODIFIERS(keycode);
          keyboard_keys[usb_presses++] = KEY(keycode);
        }
      }
    }
  }
}

/*
void debug_state() {
  unsigned int l, r, c;
  for (l = 0; l < LAYER_COUNT; l++) {
    if (l == layer_to_jump) {
      DEBUG("^");
    }
    else {
      DEBUG(" ");
    }
    if (l == current_layer_number) {
      DEBUG("*");
    }
    else {
      DEBUG(" ");
    }
    DEBUG(" ");
    debug_phex(fn_decay);
    DEBUG("\r\n");
    for (r = 0; r < ROW_COUNT; r++) {
      for (c = 0; c < COLUMN_COUNT; c++) {
        debug_phex(matrix_state[l * KEY_COUNT + r * COLUMN_COUNT + c]);
        DEBUG(" ");
      }

      DEBUG("\r\n");
    }

    DEBUG("\r\n");
  }

  debug_phex(current_layer_number);
  DEBUG(" | ");
  debug_phex(keyboard_modifier_keys);
  DEBUG(" | ");
  debug_phex(keyboard_keys[0]);
  DEBUG(" ");
  debug_phex(keyboard_keys[1]);
  DEBUG(" ");
  debug_phex(keyboard_keys[2]);
  DEBUG(" ");
  debug_phex(keyboard_keys[3]);
  DEBUG(" ");
  debug_phex(keyboard_keys[4]);
  DEBUG(" ");
  debug_phex(keyboard_keys[5]);
  DEBUG("\r\n");
}


void debug_layers() {
  unsigned int l, r, c;
  for (l = 0; l < LAYER_COUNT; l++) {
    for (r = 0; r < ROW_COUNT; r++) {
      for (c = 0; c < COLUMN_COUNT; c++) {
        debug_phex64(layers[l][r * COLUMN_COUNT + c]);
        DEBUG(" ");
      }

      DEBUG("\r\n");
    }

    DEBUG("\r\n");
  }
}
*/

void init() {
  //CPU_PRESCALE(0);

  uint32_t i;

  // rows
  for (i = 0; i < ROW_COUNT; i++) {
    pinMode(row_pins[i], OUTPUT);
  }


  // columns
  // activate pullup resistors on inputs
  for (i = 0; i < COLUMN_COUNT; i++) {
    pinMode(column_pins[i], INPUT_PULLUP);
  }

  usb_init();
  while (!usb_configuration) /* wait */ ;
};

int main() {
  init();
  //blink(1);
  while(1) {
    //DEBUG("\r\n");
    clear_keys();
    //debounce(DEBOUNCE_PASSES);
    scan_keys();
    cool_down_inactive_layers();
    pre_invoke_functions();
    calculate_presses();
    //b();
    //clear_screen();
    //debug_state();
    //debug_layers();
    usb_keyboard_send();
  };
};
