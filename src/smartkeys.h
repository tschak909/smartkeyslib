#ifndef SMARTKEYS_H
#define SMARTKEYS_H

#include <stdbool.h>

/**
 * Set SmartKeys mode and palette
 */
void smartkeys_set_mode(void);

/**
 * @brief Display smartkeys
 * @param I   Text for the I keycap, NULL = YELLOW.
 * @param II  Text for the II keycap, NULL = YELLOW.
 * @apram III Text for the III keycap, NULL = YELLOW.
 * @param IV  Text for the IV keycap, NULL = YELLOW.
 * @param V   Text for the V keycap, NULL = YELLOW.
 * @param VI  Text for the VI keycap, NULL = YELLOW.
 */
void smartkeys_display(const char *I, const char *II, const char *III, const char *IV, const char *V, const char *VI);

/**
 * @brief paint smartkeys attrs into vram
 * @param I   Display I key or status?
 * @param II  Display II key or status?
 * @param III Display III key or status?
 * @param IV  Display IV key or status?
 * @param V   Display V key or status?
 * @param VI  Display VI key or status?
 */
void smartkeys_attrs(bool I, bool II, bool III, bool IV, bool V, bool VI);

/**
 * @brief Write string to VRAM using SmartKeys proportional font
 * @param x Column (0-255)
 * @param y Row (0-191)
 * @param c NULL terminated string to display
 */
void smartkeys_puts(unsigned char x, unsigned char y, const char *c);

/**
 * @brief Display text in yellow smartkeys color (for status)
 * @param NULL terminated string to display
 */
void smartkeys_status(const char *c);

/**
 * @brief clear the bitmap for the smartkeys area
 */
void smartkeys_clear(void);

/**
 * @brief Draw smartkeys caps
 * @param k keycap # to draw
 */
void smartkeys_caps(unsigned char k);

#endif /* SMARTKEYS_H */
