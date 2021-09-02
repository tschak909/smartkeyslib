#include <eos.h>

/**
 * @brief play a sound from the smartkeys table. 
 * @param the sound number to play (1-9)
 * @note smartkeys_sound_init() must have been called, prior to using this routine
 */

static void *table;
static void *nextnote;
static void *end;

static void _play(unsigned char n)
{  
  eos_start_sound(n,end,nextnote,table);
}

void smartkeys_sound_play(unsigned char n)
{
  switch(n)
    {
    case 1:
      _play(11);
      _play(12);
      break;
    case 2:
      _play(13);
      break;
    case 3:
      _play(16);
      break;
    case 4:
      _play(6);
      _play(7);
      _play(8);
      break;
    case 5:
      _play(1);
      _play(2);
      _play(3);
      break;
    case 6:
      _play(14);
      break;
    case 7:
      _play(15);
      break;
    case 8:
      _play(9);
      _play(10);
      break;
    case 9:
      _play(4);
      _play(5);
      break;
    default:
      break;
    }
}
