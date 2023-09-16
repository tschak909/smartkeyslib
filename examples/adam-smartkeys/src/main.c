#include <video/tms99x8.h>
#include <smartkeys.h>
#include <conio.h>

void main(void)
{
  smartkeys_set_mode();
  cprintf("THIS IS THE SYSTEM FONT.\n\n\n\n\n");  
  smartkeys_puts(1,16,"THIS IS THE SMARTKEYS FONT\nIT IS PROPORTIONAL.");
  
  cprintf("ALL ITEMS. PRESS ANY KEY.\n");
  smartkeys_display(" ITEM 1\n LINE 2"," ITEM 2\n LINE 2"," ITEM3\n LINE 3"," ITEM 4\n LINE 4"," ITEM5 \n LINE 5"," ITEM 6\n LINE 6");
  cgetc();

  cprintf("ITEMS AND STATUS. PRESS ANY KEY.\n");
  smartkeys_display(NULL,NULL,NULL,"RED","BLUE","GREEN");
  smartkeys_status("WHAT IS\nYOUR FAVORITE COLOR?");
  cgetc();
  
  cprintf("ONLY STATUS. PRESS ANY KEY.\n");
  smartkeys_display(NULL,NULL,NULL,NULL,NULL,NULL);
  smartkeys_status("ADAM IS CURRENTLY PROCESSING YOUR REQUEST.\nPLEASE WAIT.\n");

  cprintf("PROGRAM DONE.\n");
  
}
