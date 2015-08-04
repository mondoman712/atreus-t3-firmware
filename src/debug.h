#ifndef DEBUG_H__
#define DEBUG_H__

#include "WProgram.h"
#include "usb_serial.h"

void debug_print(const void *str, uint32_t size);
void debug_phex(uint32_t n);
void debug_phex64(uint64_t n);


void blink(unsigned int n);
void b();

void clear_screen();

#define DEBUG(x) debug_print(x, sizeof(x))

#endif
