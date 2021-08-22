#include <msx.h>
#include "smartkeys.h"

/**
 * @brief Draw smartkeys caps
 * @param k keycap # to draw
 */
void smartkeys_caps(unsigned char k)
{
  msx_color(15,1,7);

  switch(k)
    {
    case 1:
      smartkeys_puts(24,168,"\x04");
      break;
    case 2:
      smartkeys_puts(64,168,"\x05");
      break;
    case 3:
      smartkeys_puts(104,168,"\x06");
      break;
    case 4:
      smartkeys_puts(144,168,"\x07");
      break;
    case 5:
      smartkeys_puts(184,168,"\x08");
      break;
    case 6:
      smartkeys_puts(224,168,"\x09");
      break;
    }
}
