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
      smartkeys_puts(24,168,"\xf1");
      break;
    case 2:
      smartkeys_puts(64,168,"\xf2");
      break;
    case 3:
      smartkeys_puts(104,168,"\xf3");
      break;
    case 4:
      smartkeys_puts(144,168,"\xf4");
      break;
    case 5:
      smartkeys_puts(184,168,"\xf5");
      break;
    case 6:
      smartkeys_puts(224,168,"\xf6");
      break;
    }
}
