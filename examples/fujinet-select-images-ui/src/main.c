#include <msx.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <smartkeys.h>

void main(void)
{
  smartkeys_set_mode();
  
  // Welcome To Fujinet
  vdp_color(15,4,7);
  vdp_vfill(MODE2_ATTR,0xF4,256);
  vdp_vfill(MODE2_ATTR+256,0x1F,4864);
  vdp_vfill(MODE2_ATTR+4864,0xF4,256);

  smartkeys_puts(8,0,"");

  // Left side blue
  for (int i=0;i<19;i++)
    {
      vdp_vfill(MODE2_ATTR+(i<<8),0xF4,16);
    }
  
  // Loading Directory
  smartkeys_display(NULL,NULL,NULL,NULL,NULL," ABORT");
  smartkeys_status("  LOADING DIRECTORY...");
  sleep(5);

  smartkeys_display("    NEW","  COPY\n   TO"," FILTER",NULL,"  BOOT"," ABORT");
   
  // Networks
  vdp_color(1,15,7);
  smartkeys_puts(16, 8,"Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
  smartkeys_puts(16,16,"Nullam vulputate, ex in dapibus rhoncus, nisl nulla");
  smartkeys_puts(16,24,"leo, ac tincidunt risus metus non arcu. Etiam posuere");
  smartkeys_puts(16,32,"lacinia ullamcorper. Integer turpis nulla, rutrum id enim");
  smartkeys_puts(16,40,"nec, cursus hendrerit neque. In hac habitasse cursus");
  smartkeys_puts(16,48,"hendrerit neque. In hac habitasse platea dictumst.");
  smartkeys_puts(16,56,"Curabitur rutrum mi diam, eu cursus sapien condiment");
  smartkeys_puts(16,64,"Praesent tempor sodales cursus. Vivamus at consequat");
  smartkeys_puts(16,72,"lectus.");
  smartkeys_puts(16,88,"Buck Rogers - Planet of Zoom Super Game (1983) (C");
  smartkeys_puts(16,96,"Donkey Kong Super Game (1984) (Coleco).ddp");
  // Selection bar example
  vdp_vfill(MODE2_ATTR+256,0x1A,256);
}
