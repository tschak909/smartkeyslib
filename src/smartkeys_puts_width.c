/**
 * smartkeys_puts_width.c - Calculate total width of string
 */

#include <stdlib.h>

extern unsigned char smartkeys_font[];

/**
 * @brief calculate total # of horizontal pixels (width) given string *c
 * @param string of text
 * @return total # of pixels (0-255) for text.
 */
unsigned char smartkeys_puts_width(const char *c)
{
  int total_width=0;
  
  while (*c != NULL)
    total_width += smartkeys_font[((*c)*9)];

  return (total_width > 255 ? 255 : total_width);
}
