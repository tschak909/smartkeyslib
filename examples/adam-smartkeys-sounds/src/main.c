/**
 * Example showing how to trigger smartkeys sounds
 *
 */

#include <stdlib.h>
#include <msx.h>
#include <eos.h>
#include <smartkeys.h>
#include <conio.h>

void select(int n)
{
  msx_vfill(0x2000,0x17,5376);
  msx_vfill(0x2000+(n*512),0xF5,256);
}

void main(void)
{
  smartkeys_set_mode();

  smartkeys_sound_init();

  cprintf("        AVAILABLE SOUNDS\n\n(1) TYPEWRITER CLACK\n\n(2) SMARTKEY CONFIRM\n\n(3) SMARTKEY POSITIVE CHIME\n\n(4) OOPS\n\n(5) DOUBLE CHIME\n\n(6) LONG BEEP\n\n(7) KEY PRESS\n\n(8) NEGATIVE BUZZ\n\n(9) SMARTKEY MODE CHANGE\n");
  smartkeys_display(NULL,NULL,NULL,NULL,NULL,NULL);
  smartkeys_status("  TO HEAR A SOUND, PRESS ITS NUMBER.");

  while(true)
    {
      unsigned char k = eos_read_keyboard();

      switch(k)
        {
        case '1':
          select(1);
          smartkeys_sound_play(SOUND_TYPEWRITER_CLACK);
          break;
        case '2':
          select(2);
          smartkeys_sound_play(SOUND_CONFIRM);
          break;
        case '3':
          select(3);
          smartkeys_sound_play(SOUND_POSITIVE_CHIME);
          break;
        case '4':
          select(4);
          smartkeys_sound_play(SOUND_OOPS);
          break;
        case '5':
          select(5);
          smartkeys_sound_play(SOUND_DOUBLE_CHIME);
          break;
        case '6':
          select(6);
          smartkeys_sound_play(SOUND_LONG_BEEP);
          break;
        case '7':
          select(7);
          smartkeys_sound_play(SOUND_KEY_PRESS);
          break;
        case '8':
          select(8);
          smartkeys_sound_play(SOUND_NEGATIVE_BUZZ);
          break;
        case '9':
          select(9);
          smartkeys_sound_play(SOUND_MODE_CHANGE);
          break;
        }

    }
}
