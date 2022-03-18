#include <msx.h>
#include "smartkeys.h"

/**
 * @brief Display smartkeys
 * @param I   Text for the I keycap, NULL = YELLOW.
 * @param II  Text for the II keycap, NULL = YELLOW.
 * @param III Text for the III keycap, NULL = YELLOW.
 * @param IV  Text for the IV keycap, NULL = YELLOW.
 * @param V   Text for the V keycap, NULL = YELLOW.
 * @param VI  Text for the VI keycap, NULL = YELLOW.
 */
void smartkeys_display(const char *I, const char *II, const char *III, const char *IV, const char *V, const char *VI)
{
  // Clear smartkeys
  smartkeys_clear();
  
  // Paint attributes
  smartkeys_attrs(I != NULL, II != NULL, III != NULL, IV != NULL, V != NULL, VI != NULL);
  
  // Write legends
  if (I != NULL)
    {
      smartkeys_caps(1);
      msx_color(15,5,0x77);
      smartkeys_puts(0,176,I);
    }

  if (II != NULL)
    {
      smartkeys_caps(2);
      msx_color(15,4,0x77);
      smartkeys_puts(48,176,II);
    }

  if (III != NULL)
    {
      smartkeys_caps(3);
      msx_color(15,5,0x77);
      smartkeys_puts(88,176,III);
    }

  if (IV != NULL)
    {
      smartkeys_caps(4);
      msx_color(15,4,0x77);
      smartkeys_puts(128,176,IV);
    }

  if (V != NULL)
    {
      smartkeys_caps(5);
      msx_color(15,5,0x77);
      smartkeys_puts(168,176,V);
    }

  if (VI != NULL)
    {
      smartkeys_caps(6);
      msx_color(15,4,0x77);
      smartkeys_puts(208,176,VI);
    }

  msx_color(1,0x77,0x77);
}
