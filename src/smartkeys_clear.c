#include <msx.h>

/**
 * @brief clear the bitmap for the smartkeys area
 */
void smartkeys_clear(void)
{
  msx_vfill(0x1500,0x00,768);
}
