#ifndef LAYERS_H__
#define LAYERS_H__

uint64_t layer0[44] = {
    KEY_Q,        KEY_W,              KEY_E,                  KEY_R,                  KEY_T,                0,        KEY_Y,          KEY_U,            KEY_I,      KEY_O,      KEY_P,
    KEY_A,        KEY_S,              KEY_D,                  KEY_F,                  KEY_G,                0,        KEY_H,          KEY_J,            KEY_K,      KEY_L,      KEY_SEMICOLON,
    KEY_ESC,      KEY_TAB,            KEY_CTRL,               KEY_SHIFT,              KEY_SPACE,            KEY_GUI,  KEY_BACKSPACE,  PRE_FUNCTION(1),  KEY_MINUS,  KEY_QUOTE,  KEY_ENTER,
    KEY_Z,        KEY_X,              KEY_C,                  KEY_V,                  KEY_B,                KEY_ALT,  KEY_N,          KEY_M,            KEY_COMMA,  KEY_PERIOD, KEY_SLASH };

uint64_t layer1[44] = {
    SHIFT(KEY_1), SHIFT(KEY_2),       SHIFT(KEY_LEFT_BRACE),  SHIFT(KEY_RIGHT_BRACE), SHIFT(KEY_BACKSLASH), 0,        KEY_UP,         KEY_7,            KEY_8,      KEY_9,      SHIFT(KEY_8),
    SHIFT(KEY_3), SHIFT(KEY_4),       SHIFT(KEY_9),           SHIFT(KEY_0),           KEY_TILDE,            0,        KEY_DOWN,       KEY_4,            KEY_5,      KEY_6,      SHIFT(KEY_EQUAL),
    FUNCTION(2),  SHIFT(KEY_INSERT),  KEY_CTRL,               KEY_SHIFT,              KEY_SPACE,            KEY_GUI,  KEY_BACKSPACE,  PRE_FUNCTION(1),  KEY_PERIOD, KEY_0,      KEY_EQUAL,
    SHIFT(KEY_5), SHIFT(KEY_6),       KEY_LEFT_BRACE,         KEY_RIGHT_BRACE,        SHIFT(KEY_TILDE),     KEY_ALT,  SHIFT(KEY_7),   KEY_1,            KEY_2,      KEY_3,      KEY_BACKSLASH };

uint64_t layer2[44] = {
    KEY_HOME,     KEY_UP,             KEY_END,                KEY_INSERT,             KEY_PAGE_UP,          0,        KEY_UP,         KEY_F7,           KEY_F8,     KEY_F9,     KEY_F10,
    KEY_LEFT,     KEY_DOWN,           KEY_RIGHT,              KEY_DELETE,             KEY_PAGE_DOWN,        0,        KEY_DOWN,       KEY_F4,           KEY_F5,     KEY_F6,     KEY_F11,
    LAYER(0),     0,                  KEY_CTRL,               KEY_SHIFT,              KEY_SPACE,            KEY_GUI,  KEY_BACKSPACE,  PRE_FUNCTION(1),  0,          0,          FUNCTION(0),
    0,            0,                  0,                      0,                      0,                    KEY_ALT,  0,              KEY_F1,           KEY_F2,     KEY_F3,     KEY_F12 };

uint64_t *layers[] = {layer0, layer1, layer2};

#endif
