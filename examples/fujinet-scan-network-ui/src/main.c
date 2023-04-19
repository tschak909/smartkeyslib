#include <msx.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <smartkeys.h>

void main(void)
{
  smartkeys_set_mode();
  
  // Welcome To Fujinet
  msx_color(15,4,7);
  msx_fill(MODE2_ATTR,0xF4,256);
  msx_fill(MODE2_ATTR+256,0x1F,4864);
  msx_fill(MODE2_ATTR+4864,0xF4,256);
  
  gotoxy(6,0); cputs("WELCOME TO #FUJINET!\n");
  gotoxy(0,19); cputs("MAC:        00:1C:3D:44:F4:5C:03");

  // scan network
  smartkeys_display(NULL,NULL,NULL,NULL,NULL,"  ABORT\n  SCAN");
  smartkeys_status("  FUJINET IS SCANNING FOR NETWORKS.\n  PLEASE WAIT.");
  sleep(5);

  // select network
  smartkeys_display(NULL,NULL,NULL," RESCAN"," ENTER\n SSID","  ABORT\n  SCAN");
  smartkeys_status(" 8 NETWORK(S) FOUND\n PLEASE SELECT A NETWORK.\n USING ARROWS AND RETURN.");

  // Left side blue
  for (int i=0;i<19;i++)
    {
      msx_fill(MODE2_ATTR+(i<<8),0xF4,16);
    }
  
  // Numbers
  msx_color(15,4,7);
  for (int i=0;i<8;i++)
    {
      char tmp[3];
      itoa(i+1,tmp,10);
      smartkeys_puts(8,8*i+8,tmp);
    }

  // Networks
  msx_color(1,15,7);
  smartkeys_puts(16,  8,"\x80\x81\x82"); smartkeys_puts(40,8,"CHERRYHOMES");
  smartkeys_puts(16, 16,"\x80\x81");     smartkeys_puts(40,16,"NEIGHBOR-DAN");
  smartkeys_puts(16, 24,"\x80\x81");     smartkeys_puts(40,24,"LINKSYS");
  smartkeys_puts(16, 32,"\x80\x81");     smartkeys_puts(40,32,"FREE-WIFI-HERE");
  smartkeys_puts(16, 40,"\x80");         smartkeys_puts(40,40,"JAVAJOES");
  smartkeys_puts(16, 48,"\x80");         smartkeys_puts(40,48,"SNOOGANS");
  smartkeys_puts(16, 56,"\x80");         smartkeys_puts(40,56,"JOEY-AND-CHANDLER");
  smartkeys_puts(16, 63,"\x80");         smartkeys_puts(40,63,"RIGHTMEOW");

  // Selection bar example
  msx_fill(MODE2_ATTR+256,0x1A,256);
}
