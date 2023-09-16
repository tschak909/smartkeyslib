#include <video/tms99x8.h>

/**
 * @brief clear the bitmap for the smartkeys area
 */
void smartkeys_clear(void)
{
  vdp_vfill(0x1500,0x00,768);
}
