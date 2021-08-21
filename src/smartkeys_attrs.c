#include <msx.h>
#include <string.h>
#include <stdbool.h>

/* Attribute macros for Smartkey character cells */
#define AON 0xF5,0xF5,0xF5,0xF5,0xF5,0xF5,0xF5,0xF5
#define AOK 0xF5,0xF1,0xF1,0xF1,0xF1,0xF1,0xF1,0xF1
#define AEN 0xF4,0xF4,0xF4,0xF4,0xF4,0xF4,0xF4,0xF4
#define AEK 0xF4,0xF1,0xF1,0xF1,0xF1,0xF1,0xF1,0xF1
#define YEL 0x1A

static unsigned char _attrs[768] =
  {
   AON,AON,AOK,AOK,AOK,AON,     AEN,AEK,AEK,AEK,AEN,    AON,AOK,AOK,AOK,AON,     AEN,AEK,AEK,AEK,AEN,     AON,AOK,AOK,AOK,AON,    AEN,AEK,AEK,AEK,AEN,AEN,
   AON,AON,AON,AON,AON,AON,     AEN,AEN,AEN,AEN,AEN,    AON,AON,AON,AON,AON,     AEN,AEN,AEN,AEN,AEN,     AON,AON,AON,AON,AON,    AEN,AEN,AEN,AEN,AEN,AEN,
   AON,AON,AON,AON,AON,AON,     AEN,AEN,AEN,AEN,AEN,    AON,AON,AON,AON,AON,     AEN,AEN,AEN,AEN,AEN,     AON,AON,AON,AON,AON,    AEN,AEN,AEN,AEN,AEN,AEN   
  };

static unsigned char _attrs_all[768] =
  {
   AON,AON,AOK,AOK,AOK,AON,     AEN,AEK,AEK,AEK,AEN,    AON,AOK,AOK,AOK,AON,     AEN,AEK,AEK,AEK,AEN,     AON,AOK,AOK,AOK,AON,    AEN,AEK,AEK,AEK,AEN,AEN,
   AON,AON,AON,AON,AON,AON,     AEN,AEN,AEN,AEN,AEN,    AON,AON,AON,AON,AON,     AEN,AEN,AEN,AEN,AEN,     AON,AON,AON,AON,AON,    AEN,AEN,AEN,AEN,AEN,AEN,
   AON,AON,AON,AON,AON,AON,     AEN,AEN,AEN,AEN,AEN,    AON,AON,AON,AON,AON,     AEN,AEN,AEN,AEN,AEN,     AON,AON,AON,AON,AON,    AEN,AEN,AEN,AEN,AEN,AEN   
  };

/**
 * @brief paint the SmartKeys Attrs onto color RAM
 * @param I true = Paint I SmartKey, false = yellow status instead
 * @param II true = Paint II SmartKey, false = yellow status instead
 * @param III true = Paint III SmartKey, false = yellow status instead
 * @param IV true = Paint IV SmartKey, false = yellow status instead
 * @param V true = Paint V SmartKey, false = yellow status instead
 * @param VI true = Paint VI SmartKey, false = yellow status instead
 */
void smartkeys_attrs(bool I, bool II, bool III, bool IV, bool V, bool VI)
{
  memcpy(&_attrs,&_attrs_all,768);

  if (I==false)
    {
      memset(&_attrs[0],YEL,48);   // Line 1
      memset(&_attrs[256],YEL,48); // Line 2
      memset(&_attrs[512],YEL,48); // Line 3
    }

  if (II==false)
    {
      memset(&_attrs[48],YEL,40);   // Line 1
      memset(&_attrs[304],YEL,40);  // Line 2
      memset(&_attrs[560],YEL,40);  // Line 3
    }

  if (III==false)
    {
      memset(&_attrs[88],YEL,40);   // Line 1
      memset(&_attrs[344],YEL,40);  // Line 2
      memset(&_attrs[600],YEL,40);  // Line 3
    }

  if (IV==false)
    {
      memset(&_attrs[128],YEL,40);  // Line 1
      memset(&_attrs[384],YEL,40);  // Line 2
      memset(&_attrs[640],YEL,40);  // Line 3
    }

  if (V==false)
    {
      memset(&_attrs[168],YEL,40);  // Line 1
      memset(&_attrs[424],YEL,40);  // Line 2
      memset(&_attrs[680],YEL,40);  // Line 3
    }

  if (VI==false)
    {
      memset(&_attrs[208],YEL,48);  // Line 1
      memset(&_attrs[464],YEL,48);  // Line 2
      memset(&_attrs[720],YEL,48);  // Line 3
    }

  // Paint the resulting attributes
  msx_vwrite(&_attrs,MODE2_ATTR+5376,sizeof(_attrs));
}
