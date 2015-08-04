#ifndef KEYS_H__
#define KEYS_H__

/*
 * Every key can be one of the following:
 * * A real key as defined in USB HID (see usb-keys-mapping.md)
 * * A pre-function
 * * A function
 * * A layer switcher
 *
 * Each key can have associated modifiers (e.g. you can define Ctrl-Alt-Del on
 * a single key).
 */


#define REGULAR_KEY_FLAG  0x0100000000000000
#define REGULAR_KEY_MASK  0x00000000000000ff
#define MODIFIER_KEY_FLAG 0x0200000000000000
#define MODIFIER_KEY_MASK 0x000000000000ff00
#define PRE_FUNCTION_FLAG 0x0400000000000000
#define PRE_FUNCTION_MASK 0x00000000000000ff
#define FUNCTION_FLAG     0x0800000000000000
#define FUNCTION_MASK     0x00000000000000ff
#define LAYER_FLAG        0x1000000000000000
#define LAYER_MASK        0x00000000000000ff

#define REGULAR_KEY(x)  ((uint64_t)( x | REGULAR_KEY_FLAG  ))
#define MODIFIER_KEY(x) (uint64_t)( x | MODIFIER_KEY_FLAG )
#define LAYER(x)        (uint64_t)( x | LAYER_FLAG        )
#define FUNCTION(x)     (uint64_t)( x | FUNCTION_FLAG     )
#define PRE_FUNCTION(x) (uint64_t)( x | PRE_FUNCTION_FLAG )


#define MODIFIER_LEFT_CTRL   ( 0x0000000000000100 )
#define MODIFIER_LEFT_SHIFT  ( 0x0000000000000200 )
#define MODIFIER_LEFT_ALT    ( 0x0000000000000400 )
#define MODIFIER_LEFT_GUI    ( 0x0000000000000800 )
#define MODIFIER_RIGHT_CTRL  ( 0x0000000000001000 )
#define MODIFIER_RIGHT_SHIFT ( 0x0000000000002000 )
#define MODIFIER_RIGHT_ALT   ( 0x0000000000004000 )
#define MODIFIER_RIGHT_GUI   ( 0x0000000000008000 )
#define MODIFIER_CTRL        MODIFIER_LEFT_CTRL
#define MODIFIER_SHIFT       MODIFIER_LEFT_SHIFT
#define MODIFIER_ALT         MODIFIER_LEFT_ALT
#define MODIFIER_GUI         MODIFIER_LEFT_GUI

#define CTRL(key)   ( MODIFIER_CTRL  | key )
#define SHIFT(key)  ( MODIFIER_SHIFT | key )
#define ALT(key)    ( MODIFIER_ALT   | key )
#define GUI(key)    ( MODIFIER_GUI   | key )

#define MODIFIERS(x) (uint8_t)( (x & MODIFIER_KEY_MASK) >> 8 )
#define KEY(x)       (uint8_t)( x & REGULAR_KEY_MASK )

#define KEY_A           REGULAR_KEY( 4   )
#define KEY_B           REGULAR_KEY( 5   )
#define KEY_C           REGULAR_KEY( 6   )
#define KEY_D           REGULAR_KEY( 7   )
#define KEY_E           REGULAR_KEY( 8   )
#define KEY_F           REGULAR_KEY( 9   )
#define KEY_G           REGULAR_KEY( 10  )
#define KEY_H           REGULAR_KEY( 11  )
#define KEY_I           REGULAR_KEY( 12  )
#define KEY_J           REGULAR_KEY( 13  )
#define KEY_K           REGULAR_KEY( 14  )
#define KEY_L           REGULAR_KEY( 15  )
#define KEY_M           REGULAR_KEY( 16  )
#define KEY_N           REGULAR_KEY( 17  )
#define KEY_O           REGULAR_KEY( 18  )
#define KEY_P           REGULAR_KEY( 19  )
#define KEY_Q           REGULAR_KEY( 20  )
#define KEY_R           REGULAR_KEY( 21  )
#define KEY_S           REGULAR_KEY( 22  )
#define KEY_T           REGULAR_KEY( 23  )
#define KEY_U           REGULAR_KEY( 24  )
#define KEY_V           REGULAR_KEY( 25  )
#define KEY_W           REGULAR_KEY( 26  )
#define KEY_X           REGULAR_KEY( 27  )
#define KEY_Y           REGULAR_KEY( 28  )
#define KEY_Z           REGULAR_KEY( 29  )
#define KEY_1           REGULAR_KEY( 30  )
#define KEY_2           REGULAR_KEY( 31  )
#define KEY_3           REGULAR_KEY( 32  )
#define KEY_4           REGULAR_KEY( 33  )
#define KEY_5           REGULAR_KEY( 34  )
#define KEY_6           REGULAR_KEY( 35  )
#define KEY_7           REGULAR_KEY( 36  )
#define KEY_8           REGULAR_KEY( 37  )
#define KEY_9           REGULAR_KEY( 38  )
#define KEY_0           REGULAR_KEY( 39  )
#define KEY_ENTER       REGULAR_KEY( 40  )
#define KEY_ESC         REGULAR_KEY( 41  )
#define KEY_BACKSPACE   REGULAR_KEY( 42  )
#define KEY_TAB         REGULAR_KEY( 43  )
#define KEY_SPACE       REGULAR_KEY( 44  )
#define KEY_MINUS       REGULAR_KEY( 45  )
#define KEY_EQUAL       REGULAR_KEY( 46  )
#define KEY_LEFT_BRACE  REGULAR_KEY( 47  )
#define KEY_RIGHT_BRACE REGULAR_KEY( 48  )
#define KEY_BACKSLASH   REGULAR_KEY( 49  )
#define KEY_NON_US_NUM  REGULAR_KEY( 50  )
#define KEY_SEMICOLON   REGULAR_KEY( 51  )
#define KEY_QUOTE       REGULAR_KEY( 52  )
#define KEY_TILDE       REGULAR_KEY( 53  )
#define KEY_COMMA       REGULAR_KEY( 54  )
#define KEY_PERIOD      REGULAR_KEY( 55  )
#define KEY_SLASH       REGULAR_KEY( 56  )
#define KEY_CAPS_LOCK   REGULAR_KEY( 57  )
#define KEY_F1          REGULAR_KEY( 58  )
#define KEY_F2          REGULAR_KEY( 59  )
#define KEY_F3          REGULAR_KEY( 60  )
#define KEY_F4          REGULAR_KEY( 61  )
#define KEY_F5          REGULAR_KEY( 62  )
#define KEY_F6          REGULAR_KEY( 63  )
#define KEY_F7          REGULAR_KEY( 64  )
#define KEY_F8          REGULAR_KEY( 65  )
#define KEY_F9          REGULAR_KEY( 66  )
#define KEY_F10         REGULAR_KEY( 67  )
#define KEY_F11         REGULAR_KEY( 68  )
#define KEY_F12         REGULAR_KEY( 69  )
#define KEY_PRINTSCREEN REGULAR_KEY( 70  )
#define KEY_SCROLL_LOCK REGULAR_KEY( 71  )
#define KEY_PAUSE       REGULAR_KEY( 72  )
#define KEY_INSERT      REGULAR_KEY( 73  )
#define KEY_HOME        REGULAR_KEY( 74  )
#define KEY_PAGE_UP     REGULAR_KEY( 75  )
#define KEY_DELETE      REGULAR_KEY( 76  )
#define KEY_END         REGULAR_KEY( 77  )
#define KEY_PAGE_DOWN   REGULAR_KEY( 78  )
#define KEY_RIGHT       REGULAR_KEY( 79  )
#define KEY_LEFT        REGULAR_KEY( 80  )
#define KEY_DOWN        REGULAR_KEY( 81  )
#define KEY_UP          REGULAR_KEY( 82  )
#define KEY_NUM_LOCK    REGULAR_KEY( 83  )
#define KEYPAD_SLASH    REGULAR_KEY( 84  )
#define KEYPAD_ASTERIX  REGULAR_KEY( 85  )
#define KEYPAD_MINUS    REGULAR_KEY( 86  )
#define KEYPAD_PLUS     REGULAR_KEY( 87  )
#define KEYPAD_ENTER    REGULAR_KEY( 88  )
#define KEYPAD_1        REGULAR_KEY( 89  )
#define KEYPAD_2        REGULAR_KEY( 90  )
#define KEYPAD_3        REGULAR_KEY( 91  )
#define KEYPAD_4        REGULAR_KEY( 92  )
#define KEYPAD_5        REGULAR_KEY( 93  )
#define KEYPAD_6        REGULAR_KEY( 94  )
#define KEYPAD_7        REGULAR_KEY( 95  )
#define KEYPAD_8        REGULAR_KEY( 96  )
#define KEYPAD_9        REGULAR_KEY( 97  )
#define KEYPAD_0        REGULAR_KEY( 98  )
#define KEYPAD_PERIOD   REGULAR_KEY( 99  )
#define KEY_MENU        REGULAR_KEY( 101 )
#define KEY_F13         REGULAR_KEY( 104 )
#define KEY_F14         REGULAR_KEY( 105 )
#define KEY_F15         REGULAR_KEY( 106 )
#define KEY_F16         REGULAR_KEY( 107 )
#define KEY_F17         REGULAR_KEY( 108 )
#define KEY_F18         REGULAR_KEY( 109 )
#define KEY_F19         REGULAR_KEY( 110 )
#define KEY_F20         REGULAR_KEY( 111 )
#define KEY_F21         REGULAR_KEY( 112 )
#define KEY_F22         REGULAR_KEY( 113 )
#define KEY_F23         REGULAR_KEY( 114 )
#define KEY_F24         REGULAR_KEY( 115 )

#define KEY_CTRL        MODIFIER_KEY(MODIFIER_CTRL)
#define KEY_SHIFT       MODIFIER_KEY(MODIFIER_SHIFT)
#define KEY_ALT         MODIFIER_KEY(MODIFIER_ALT)
#define KEY_GUI         MODIFIER_KEY(MODIFIER_GUI)
#define KEY_LEFT_CTRL   MODIFIER_KEY(MODIFIER_LEFT_CTRL)
#define KEY_LEFT_SHIFT  MODIFIER_KEY(MODIFIER_LEFT_SHIFT)
#define KEY_LEFT_ALT    MODIFIER_KEY(MODIFIER_LEFT_ALT)
#define KEY_LEFT_GUI    MODIFIER_KEY(MODIFIER_LEFT_GUI)
#define KEY_RIGHT_CTRL  MODIFIER_KEY(MODIFIER_RIGHT_CTRL)
#define KEY_RIGHT_SHIFT MODIFIER_KEY(MODIFIER_RIGHT_SHIFT)
#define KEY_RIGHT_ALT   MODIFIER_KEY(MODIFIER_RIGHT_ALT)
#define KEY_RIGHT_GUI   MODIFIER_KEY(MODIFIER_RIGHT_GUI)


// FIXME: These keys need their own flag
#define KEY_MEDIA_VOLUME_INC    0x01
#define KEY_MEDIA_VOLUME_DEC    0x02
#define KEY_MEDIA_MUTE          0x04
#define KEY_MEDIA_PLAY_PAUSE    0x08
#define KEY_MEDIA_NEXT_TRACK    0x10
#define KEY_MEDIA_PREV_TRACK    0x20
#define KEY_MEDIA_STOP          0x40
#define KEY_MEDIA_EJECT         0x80


// Check macros
#define IS_REGULAR_KEY(x)   ( (x & REGULAR_KEY_FLAG)  != 0 )
#define IS_MODIFIER_KEY(x)  ( (x & MODIFIER_KEY_FLAG) != 0 )
#define IS_LAYER(x)         ( (x & LAYER_FLAG)        != 0 )
#define IS_FUNCTION(x)      ( (x & FUNCTION_FLAG)     != 0 )
#define IS_PRE_FUNCTION(x)  ( (x & PRE_FUNCTION_FLAG) != 0 )

#define IS_CTRL(x)   ( (x & (MODIFIER_LEFT_CTRL | MODIFIER_RIGHT_CTRL))   != 0 )
#define IS_SHIFT(x)  ( (x & (MODIFIER_LEFT_SHIFT | MODIFIER_RIGHT_SHIFT)) != 0 )
#define IS_ALT(x)    ( (x & (MODIFIER_LEFT_ALT | MODIFIER_RIGHT_ALT)      != 0 )
#define IS_GUI(x)    ( (x & (MODIFIER_LEFT_GUI | MODIFIER_RIGHT_GUI)      != 0 )

#endif
