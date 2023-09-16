/**
 * @brief Initialize EOS sound system to use SmartKeys sounds.
 * @note this must be called before any smartkeys_sound_play() commands.
 */

#include <video/tms99x8.h>
#include <eos.h>
#include <intrinsic.h>
#include <interrupt.h>
#include <arch/z80.h>

/* Sound data pulled from the SmartWriter ROM */

static unsigned char output1[10], output2[10], output3[10], output4[10], output5[10], output6[10];

static unsigned char sound0[] = {0x40,0x87,0x50,0x03,0x42,0x8F,0x30,0x0A,0x17,0x11,0x50};                                                   // 0E74 [0]
static unsigned char sound1[] = {0x80,0xD6,0x50,0x03,0x82,0xE2,0x30,0x0A,0x17,0x11,0x90};                                                   // 0E7F [1]
static unsigned char sound2[] = {0x02,0x63,0x0A,0x00,0x00,0x10};                                                                            // 0E8A [2]
static unsigned char sound3[] = {0xC0,0x4C,0xF0,0x0A,0xD0};                                                                                 // 0E90 [3]
static unsigned char sound4[] = {0x02,0x67,0x02,0x00,0x00,0x10};                                                                            // 0E95 [4]
static unsigned char sound5[] = {0xC0,0x0A,0xF0,0x02,0xD0};                                                                                 // 0E9B [5]
static unsigned char sound6[] = {0x41,0x40,0x60,0x02,0x55,0x15,0x40,0x80,0x60,0x05,0x50,0x81,0x57,0x63,0x02,0x44,0xa3,0x90};                // 0EA0 [6]
static unsigned char sound7[] = {0x41,0x40,0x40,0x02,0x33,0xFC,0x41,0x40,0x40,0x02,0x33,0xfc,0x42,0x40,0x40,0x09,0x1d,0x11,0x50};           // 0EB2 [7]
static unsigned char sound8[] = {0x81,0x4C,0x20,0x02,0x33,0xFB,0x81,0x4C,0x81,0x4C,0x20,0x02,0x33,0xFB,0x82,0x4C,0x20,0x09,0x1D,0x11,0x90}; // 0EC5 [8]
static unsigned char sound9[] = {0xC1,0x60,0x20,0x02,0x33,0xFA,0xC1,0x60,0x20,0x02,0x33,0xFA,0xC2,0x60,0x20,0x09,0x1D,0x11,0xD0};          // 0ED8 [9]
static unsigned char sound10[] = {0x42,0x20,0x40,0x10,0x24,0x14,0x42,0x20,0x30,0x14,0x24,0x16,0x50};                                        // 0EEB [10]
static unsigned char sound11[] = {0x82,0x40,0x40,0x10,0x18,0x13,0x82,0x40,0x30,0x14,0x18,0x15,0x90};                                        // 0EF8 [11]
static unsigned char sound12[] = {0xC2,0x80,0x40,0x10,0x18,0x12,0xC2,0x80,0x30,0x14,0x18,0x11,0xD0};                                        // 0F05 [12]
static unsigned char sound13[] = {0x82,0x40,0x40,0x0F,0x18,0x15,0x90,0x42,0x20,0x30,0x14,0x26,0x1B,0x50,0x82,0x40,0x30,0x14,0x1B,0x19,0x90}; // 0F12 [13]
static unsigned char sound14[] = {0x82,0xD6,0x70,0x40,0x32,0x12,0x90};                                                                                 // 0F2E [14]
static unsigned char sound15[] = {0x82,0xCA,0x70,0x04,0x32,0x12,0x90};                                                                       // 0F35 [15]

static unsigned short soundTable[32];

static void nmi_play(void)
{
  M_PRESERVE_ALL;
  eos_play_sound();
  M_RESTORE_ALL;
}

void smartkeys_sound_init(void)
{
  Z80_registers r;
    
  r.Bytes.B = 6; // 6 output tables
  r.UWords.HL = &soundTable;

  // 16 sound fragments
  
  soundTable[0]=&sound10; soundTable[1]=&output1;
  soundTable[2]=&sound11; soundTable[3]=&output2;
  soundTable[4]=&sound12; soundTable[5]=&output3;
  soundTable[6]=&sound0; soundTable[7]=&output1;
  soundTable[8]=&sound1; soundTable[9]=&output2;
  soundTable[10]=&sound7; soundTable[11]=&output4;
  soundTable[12]=&sound8; soundTable[13]=&output5;
  soundTable[14]=&sound9; soundTable[15]=&output6;
  soundTable[16]=&sound2; soundTable[17]=&output4;
  soundTable[18]=&sound3; soundTable[19]=&output5;
  soundTable[20]=&sound4; soundTable[21]=&output1;
  soundTable[22]=&sound5; soundTable[23]=&output2;
  soundTable[24]=&sound6; soundTable[25]=&output2;
  soundTable[26]=&sound14; soundTable[27]=&output1;
  soundTable[28]=&sound15; soundTable[29]=&output1;
  soundTable[30]=&sound13; soundTable[31]=&output2;
  
  AsmCall(0xFD50,&r,REGS_ALL,REGS_ALL);
  add_raster_int(nmi_play);
}
