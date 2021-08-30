/**
 * smartkeys_patch.c - Patch smartkeys font with new character
 */

#include <stdlib.h>

extern unsigned char smartkeys_font[];

/**
 * @brief patch smartkeys font glyph with new data
 * @param glyph # to patch
 * @param 9 bytes of data, first byte length, followed by 8 bytes of bitmap data
 */
void smartkeys_patch(unsigned char n, unsigned char l, unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4, unsigned char b5, unsigned char b6, unsigned char b7, unsigned char b8)
{
  unsigned char *p = &smartkeys_font[n*9];

  p[0]=l;
  p[1]=b1;
  p[2]=b2;
  p[3]=b3;
  p[4]=b4;
  p[5]=b5;
  p[6]=b6;
  p[7]=b7;
  p[8]=b8;
}
