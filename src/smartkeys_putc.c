/**
 * smartkeys_putc.c - Put a character using SmartKeys proportional font
 */

#include <msx.h>
#include <graphics.h>

extern unsigned char smartkeys_font[];

/**
 * @brief Write string to VRAM using SmartKeys proportional font
 * @param x Column (0-255)
 * @param y Row (0-191)
 * @param c character to display
 * @param width of last character emitted.
 */
unsigned char smartkeys_putc(unsigned char x, unsigned char y, const char c)
{  
  // map ASCII to appropriate character
  unsigned short o;  // offset 
  unsigned char w;   // width
      
  o = c*9;
  
  w = smartkeys_font[o++]; // First byte is width, also increment past it.

  for (unsigned char i=0;i<8;i++)
    {
      unsigned char b = smartkeys_font[o+i]; // the whole row byte
      
      for (unsigned char j=0;j<w;j++)
	{
	  if (((b & 0x80) == 0x80) && ((x+j) <= 255))
	    pset(x+j,y+i);
	  
	  b <<= 1; // shift next bit to leftmost.
	}
    }
  
  return w;
}
