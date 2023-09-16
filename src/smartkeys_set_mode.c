#include <video/tms99x8.h>
#include <graphics.h>
#include <conio.h>
  
/**
 * @brief set GRAPHICS II mode, and Cyan/Black background.
 */
void smartkeys_set_mode(void)
{
  vdp_set_mode(2);
  vdp_color(1,7,7);
  clrscr();
}
