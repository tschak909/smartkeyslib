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
 * @param c character to display
 * @return width of last character emitted.
 */
unsigned char smartkeys_putc(unsigned char x, unsigned char y, const char c);

/**
 * @brief Write string to VRAM using SmartKeys proportional font
 * @param x Column (0-255)
 * @param y Row (0-191)
 * @param c NULL terminated string to display
 * @return total width of characters emitted. 
 */
unsigned char smartkeys_puts(unsigned short x, unsigned char y, const char *c);

/**
 * @brief calculate total # of horizontal pixels (width) given string *c
 * @param string of text
 * @return total # of pixels (0-255) for text.
 */
unsigned char smartkeys_puts_width(const char *c);

/**
 * @brief return width of requested character in pixels.
 * @param character to return. (0-255)
 * @return width in pixels (0-8)
 */
unsigned char smartkeys_putc_width(const char c);

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

/**
 * @brief patch smartkeys font glyph with new data
 * @param glyph # to patch
 * @param 9 bytes of data, first byte length, followed by 8 bytes of bitmap data
 */
void smartkeys_patch(unsigned char n, unsigned char l, unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4, unsigned char b5, unsigned char b6, unsigned char b7, unsigned char b8);   


/**
 * @brief Initialize EOS sound system to use SmartKeys sounds.
 * @note this must be called before any smartkeys_sound_play() commands.
 */
void smartkeys_sound_init(void);

/**
 * @brief play a sound from the smartkeys table. 
 * @param the sound number to play (1-9)
 * @note smartkeys_sound_init() must have been called, prior to using this routine
 */
void smartkeys_sound_play(unsigned char n);

#endif /* SMARTKEYS_H */
