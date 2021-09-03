/**
 * smartkeys_puts.c - Put text using SmartKeys proportional font
 */

#include <msx.h>
#include <graphics.h>
#include <conio.h>

extern unsigned char smartkeys_font[];
extern unsigned char smartkeys_putc(unsigned char x, unsigned char y, const char c);

/**
 * @brief Write string to VRAM using SmartKeys proportional font
 * @param x Column (0-255)
 * @param y Row (0-191)
 * @param c NULL terminated string to display
 */
unsigned char smartkeys_puts(unsigned short x, unsigned char y, const char *c)
{
  unsigned char oldx=x;
  unsigned char w;
  
  // map ASCII to appropriate character
  while (*c != NULL)
    {      
      if (*c == '\n')
	{
	  x=oldx;
	  y += 8;
	  c++;
	  continue;
	}

      w = smartkeys_putc(x,y,*c);

      if ((x + w) < 255)
	{
	  x += w; // Move X right by width pixels
	  c++; // advance to next char;
	}
      else
	return 0;
    }
  return w;
}
