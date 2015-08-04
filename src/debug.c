#include "debug.h"

void debug_print(const void *str, uint32_t size) {
  usb_serial_write(str, size);
  usb_serial_flush_output();
}

static void debug_phex1(uint32_t n) {
  n &= 0xf;
  if (n < 10) {
    char str = '0' + n;
    debug_print(&str, 1);
  } else {
    char str = 'A' - 10 + n;
    debug_print(&str, 1);
  }
}

void debug_phex(uint32_t n) {
  debug_phex1(n >> 4);
  debug_phex1(n);
}

void debug_phex64(uint64_t n) {
  int i;
  for (i = 15; i >= 0; i--) {
    debug_phex1(n >> (4 * i));
  }
}



void b() {
  const int ledPin = 13;

  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, HIGH);
  delay(20);
  digitalWrite(ledPin, LOW);
}

void blink(unsigned int n) {
  const int ledPin = 13;

  pinMode(ledPin, OUTPUT);

  unsigned int i;
  for (i = 1; i <= n; i++) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
    if (i % 5 == 0) {
      delay(400);
    }
  }
}

void clear_screen() {
  char esc[] = { 27 };
  debug_print(esc, 1);
  debug_print("[2J", 3);
  debug_print(esc, 1);
  debug_print("[;H", 3);
}
