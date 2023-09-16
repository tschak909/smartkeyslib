/**
 * adam-tape-retension
 * 
 * A simple smartkeys example
 * 
 * Author: Thomas Cherryhomes
 *  <thom.cherryhomes@gmail.com>
 *
 * Licensed under the GNU Public License v.3
 * see LICENSE.md, for details.
 */

#include <stdlib.h>
#include <stdbool.h>
#include <video/tms99x8.h>
#include <eos.h>
#include <smartkeys.h>

#define SMARTKEY_V 0x85
#define SMARTKEY_VI 0x86
#define TAPE_1 0x08
#define TAPE_2 0x18
#define TAPE_1_MISSING 0x04
#define TAPE_2_MISSING 0x40
#define TAPE_1_EMPTY 0x03
#define TAPE_2_EMPTY 0x30
#define STATUS_MASK 0x7F

#define BEGIN_BLOCK_RIGHT 0x00
#define END_BLOCK_RIGHT 0xFF

#define BEGIN_BLOCK_CENTER 0x80
#define END_BLOCK_CENTER 0x3F

// We just need a destination for blocks, we aren't using it, and we don't want to bloat the binary to reserve space for it, so...
unsigned char *block = (unsigned char *)0x8000;

DCB *dcb;
bool tape_1_enabled = true;
bool tape_2_enabled = true;
unsigned char key;
unsigned long begin_block;
unsigned long end_block;

void sound_negative_beep(void)
{
  smartkeys_sound_play(8);
}

void sound_chime(void)
{
  smartkeys_sound_play(3);
}

void sound_mode_change(void)
{
  smartkeys_sound_play(9);
}

void sound_confirm(void)
{
  smartkeys_sound_play(2);
}

void update_status(const char *c)
{
  smartkeys_display(NULL,NULL,NULL,NULL,NULL,NULL);
  smartkeys_status(c);    
}

unsigned char check_tape_inserted(unsigned char dev)
{
  unsigned char s;
  
  eos_request_device_status(dev,dcb);
  s = eos_get_device_status(dev) & STATUS_MASK;
  
  switch (dev)
    {
    case TAPE_1: // TAPE 1
      return (s & 0x0F) != TAPE_1_EMPTY;
    case TAPE_2: // TAPE 2
      return (s & 0xF0) != TAPE_2_EMPTY;
    }
}

void rewind(unsigned char dev)
{
  dcb=eos_find_dcb(dev);
  dcb->block=0;
  dcb->status=2;
  while (dcb->status<0x80);
}

void retension(unsigned char dev)
{
  sound_chime();
  smartkeys_display(NULL,NULL,NULL,NULL," RIGHT\n DIR"," CENTER\n DIR");
  smartkeys_status("  PLEASE SPECIFY\n  TAPE TYPE:");

  key = eos_read_keyboard();

  switch(key)
    {
    case SMARTKEY_V:
      begin_block=BEGIN_BLOCK_RIGHT;
      end_block=END_BLOCK_RIGHT;
      break;
    case SMARTKEY_VI:
      begin_block=BEGIN_BLOCK_CENTER;
      end_block=END_BLOCK_CENTER;
      break;
    default:
      sound_confirm();
      update_status("  OPERATION ABORTED.");
      sleep(2);
      return;
    }

  if (check_tape_inserted(dev) == 0)
    {
      update_status("  PLEASE INSERT A TAPE INTO THE DRIVE.");
      while (check_tape_inserted(dev) == 0) { }
    }
  
  sound_confirm();
  update_status("  RETENSIONING TAPE TO END.\n  PLEASE WAIT");
  eos_read_block(dev,end_block,block);

  sound_confirm();
  update_status("  RETENSIONING TAPE BACK TO BEGINNING.\n  PLEASE WAIT");
  rewind(dev);
  
  sound_chime();
  smartkeys_display(NULL,NULL,NULL,NULL,"ANOTHER\n  TAPE"," REBOOT");
  smartkeys_status("  TAPE DONE!\n  WHAT NEXT?");

  key = eos_read_keyboard();

  switch(key)
    {
    case SMARTKEY_V:
      return;
    case SMARTKEY_VI:
      eos_init();
      break;
    default:
      sound_negative_beep();
      break;
    }
}

void main(void)
{  
  eos_scan_for_devices();
  smartkeys_set_mode();
  smartkeys_sound_init();

  eos_request_device_status(TAPE_1,dcb);
  tape_1_enabled = (eos_get_device_status(TAPE_1) & 0x7f) != 0x04;

  eos_request_device_status(TAPE_2,dcb);
  tape_2_enabled = (eos_get_device_status(TAPE_2) & 0x7f) != 0x40;
  
  smartkeys_puts(80,88,"DDP RETENSION TOOL");
  smartkeys_puts(80,96,"   VERSION 1.1");
  
  while (1)
    {
      sound_mode_change();
  
      smartkeys_display(NULL,NULL,NULL,NULL,(tape_1_enabled == true ? " TAPE 1" : NULL),(tape_2_enabled == true ? " TAPE 2" : NULL));
      smartkeys_status("  PLEASE SELECT TAPE\n  DRIVE:");

      key = eos_read_keyboard();

      switch(key)
	{
	case SMARTKEY_V:
	  retension(TAPE_1);
	  break;
	case SMARTKEY_VI:
	  retension(TAPE_2);
	  break;
	default:
	  sound_negative_beep();
	  break;
	}
    }
}
