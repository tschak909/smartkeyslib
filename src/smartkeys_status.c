#include <video/tms99x8.h>
#include "smartkeys.h"

/**
 * @brief Display text in yellow smartkeys color (for status)
 * @param NULL terminated string to display
 */
void smartkeys_status(const char *c)
{
  vdp_color(1,0x0a,0x77);
  smartkeys_puts(0,168,c);
  vdp_color(1,0x77,0x77);
}
