/**
 * smartkeys_puts_width.c - return width of character
 */

#include <stdlib.h>

extern unsigned char smartkeys_font[];

/**
 * @brief return width of requested character in pixels.
 * @param character to return. (0-255)
 * @return width in pixels (0-8)
 */
unsigned char smartkeys_putc_width(const char c)
{
  return smartkeys_font[c*9];
}
