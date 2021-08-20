#include <msx.h>
#include <graphics.h>
#include <conio.h>
  
/**
 * @brief set GRAPHICS II mode, and Cyan/Black background.
 */
void smartkeys_set_mode(void)
{
  msx_set_mode(2);
  msx_color(1,7,7);
  clrscr();
}
