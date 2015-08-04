#define DEBOUNCE_PASSES 3

#include "keys.h"
#include "layers.h"
#include "layout_common.h"

#define LAYER_COUNT ( sizeof(layers) / sizeof(layers[0]) )

/* ROW_HEATUP is a delay that is given for current to propagate before reading
 * keys. If not given enough time readings might be inaccurate.
 *
 * I didn't try no delay and I've seen it used pretty much in all firmwares
 * I could find. I don't know what is an optimal value for this should be to get
 * stable readings.
 *
 * This is also a limiting factor for how much input you can get.
 *
 * The time for key to get registered:
 *
 *   T = ROW_COUNT * ROW_HEATUP * DEBOUNCE_PASSES
 *
 *
 * Number of characters you can enter in a minute[^1]:
 *
 *   1000 / T
 *
 * If we assume that on average word contains 5 letters your maximum speed is:
 *
 * * For 5ms - 200 wpm
 * * For 4ms - 250 wpm
 * * For 3ms - 333 wpm
 *
 *
 * [^1]: Technically this is not correct. You can enter up to 6 keys at a time but
 * for them to get registered in the right order there must pass at least one
 * full scan between key presses. But people are not robots sometimes they're
 * not as precise sp better have some margins in an extra scan or two.
 */
#define ROW_HEATUP 3
