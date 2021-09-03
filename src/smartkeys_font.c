/**
 * Font for SmartKeys output
 */

unsigned char smartkeys_font[] =
  {
   0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x33, // 0x00 WIFI1
   0x08,0x00,0x00,0x03,0x03,0x33,0x33,0x33,0x33, // 0x01 WIFI2
   0x08,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30, // 0x02 WIFI3
   0x08,0,120,135,255,255,255,255,0,             // 0x03 FOLDER
   0x08,0x00,0x1C,0x08,0x08,0x08,0x08,0x1C,0x00, // 0x04 I
   0x08,0x00,0x3E,0x14,0x14,0x14,0x14,0x3E,0x00, // 0x05 II
   0x08,0x00,0x7F,0x2A,0x2A,0x2A,0x2A,0x7F,0x00, // 0x06 III
   0x08,0x00,0xF1,0x51,0x51,0x4A,0x4A,0xE4,0x00, // 0x07 IV
   0x08,0x00,0x22,0x22,0x22,0x14,0x14,0x08,0x00, // 0x08 V
   0x08,0x00,0x8F,0x8A,0x8A,0x52,0x52,0x27,0x00, // 0x09 VI
   0x08,0xFE,0x82,0xB1,0xA9,0xB1,0x82,0xFE,0x00, // 0x0A
   0x08,0xFF,0x81,0x81,0xA5,0x81,0x81,0xFF,0x00, // 0x0B TAPE
   0x08,0xFF,0x81,0x99,0x81,0x99,0x99,0xFF,0x00, // 0x0C DISK
   0x08,0xFF,0x81,0xBD,0xBD,0xBD,0x81,0xFF,0x00, // 0x0D ROM
   0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x0E 
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x0F
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x10
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x11
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x12
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x13
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x14
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x15
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x16
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x17
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x18
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x19
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x1A
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x1B
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x1C
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x1D
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x1E
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x1F
   0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x20 5px <SPACE>
   0x02,0x00,0x80,0x80,0x80,0x80,0x00,0x80,0x00, // 0x21 !
   0x04,0x00,0xA0,0xA0,0x00,0x00,0x00,0x00,0x00, // 0x22 "
   0x06,0x50,0x50,0xF8,0x50,0xF8,0x50,0x50,0x00, // 0x23 #
   0x06,0x00,0x20,0x78,0xA0,0x70,0x28,0xF0,0x20, // 0x24 $
   0x06,0x00,0xC8,0xD0,0x20,0x20,0x58,0x98,0x00, // 0x25 %
   0x06,0x00,0x40,0xA0,0x40,0xA8,0x90,0x68,0x00, // 0x26 &
   0x04,0x20,0x20,0x20,0x00,0x00,0x00,0x00,0x00, // 0x27 '
   0x03,0x00,0x40,0x80,0x80,0x80,0x80,0x40,0x00, // 0x28 (
   0x03,0x00,0x80,0x40,0x40,0x40,0x40,0x80,0x00, // 0x29 )
   0x06,0x00,0x00,0x20,0xA8,0x70,0xA8,0x20,0x00, // 0x2A *
   0x04,0x00,0x00,0x40,0xE0,0x40,0x00,0x00,0x00, // 0x2B +
   0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80, // 0x2C ,
   0x04,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0x00, // 0x2D -
   0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00, // 0x2E .
   0x05,0x00,0x10,0x10,0x20,0x20,0x40,0x40,0x00, // 0x2F /
   0x06,0x00,0x70,0x88,0x98,0xA8,0xC8,0x70,0x00, // 0x30 0
   0x06,0x00,0x20,0x60,0x20,0x20,0x20,0x70,0x00, // 0x31 1
   0x06,0x00,0x70,0x88,0x08,0x70,0x80,0xF8,0x00, // 0x32 2
   0x06,0x00,0xF8,0x08,0x30,0x08,0x88,0x70,0x00, // 0x33 3
   0x06,0x00,0x30,0x50,0x90,0xF8,0x10,0x10,0x00, // 0x34 4
   0x06,0x00,0xF8,0x80,0xF0,0x08,0x88,0x70,0x00, // 0x35 5
   0x06,0x00,0x78,0x80,0xF0,0x88,0x88,0x70,0x00, // 0x36 6
   0x06,0x00,0xF8,0x08,0x10,0x20,0x40,0x40,0x00, // 0x37 7
   0x06,0x00,0x70,0x88,0x70,0x88,0x88,0x70,0x00, // 0x38 8
   0x06,0x00,0x70,0x88,0x88,0x78,0x08,0xF0,0x00, // 0x39 9
   0x02,0x00,0x00,0x00,0x80,0x00,0x80,0x00,0x00, // 0x3A :
   0x03,0x00,0x00,0x00,0x40,0x00,0x40,0x80,0x00, // 0x3B ;
   0x05,0x00,0x00,0x18,0x60,0x80,0x60,0x18,0x00, // 0x3C <
   0x04,0x00,0x00,0xE0,0x00,0xE0,0x00,0x00,0x00, // 0x3D =
   0x06,0x00,0x00,0xC0,0x30,0x08,0x30,0xC0,0x00, // 0x3E >
   0x06,0x70,0x88,0x10,0x20,0x20,0x00,0x20,0x00, // 0x3F ?
   0x05,0x00,0x60,0x90,0xB0,0xB0,0x80,0x60,0x00, // 0x40 @ 
   0x05,0x00,0x60,0x90,0x90,0xF0,0x90,0x90,0x00, // 0x41 A
   0x05,0x00,0xE0,0x90,0xE0,0x90,0x90,0xE0,0x00, // 0x42 B
   0x05,0x00,0x70,0x80,0x80,0x80,0x80,0x70,0x00, // 0x43 C
   0x05,0x00,0xE0,0x90,0x90,0x90,0x90,0xE0,0x00, // 0x44 D
   0x05,0x00,0xF0,0x80,0xE0,0x80,0x80,0xF0,0x00, // 0x45 E
   0x05,0x00,0xF0,0x80,0xE0,0x80,0x80,0x80,0x00, // 0x46 F
   0x05,0x00,0x60,0x90,0x80,0xB0,0x90,0x70,0x00, // 0x47 G
   0x05,0x00,0x90,0x90,0x90,0xF0,0x90,0x90,0x00, // 0x48 H
   0x02,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x00, // 0x49 I
   0x05,0x00,0x10,0x10,0x10,0x10,0x90,0x60,0x00, // 0x4A J
   0x05,0x00,0x80,0x90,0xA0,0xC0,0xA0,0x90,0x00, // 0x4B K
   0x05,0x00,0x80,0x80,0x80,0x80,0x80,0xF0,0x00, // 0x4C L
   0x06,0x00,0x88,0xD8,0xA8,0xA8,0x88,0x88,0x00, // 0x4D M
   0x05,0x00,0x90,0xD0,0xD0,0xB0,0x90,0x90,0x00, // 0x4E N
   0x05,0x00,0x60,0x90,0x90,0x90,0x90,0x60,0x00, // 0x4F O
   0x05,0x00,0xE0,0x90,0x90,0xE0,0x80,0x80,0x00, // 0x50 P
   0x05,0x00,0x60,0x90,0x90,0x90,0xB0,0x70,0x00, // 0x51 Q
   0x05,0x00,0xE0,0x90,0x90,0xE0,0xA0,0x90,0x00, // 0x52 R
   0x05,0x00,0x70,0x80,0x60,0x10,0x10,0xE0,0x00, // 0x53 S
   0x06,0x00,0xF8,0x20,0x20,0x20,0x20,0x20,0x00, // 0x54 T
   0x05,0x00,0x90,0x90,0x90,0x90,0x90,0x60,0x00, // 0x55 U
   0x06,0x00,0x88,0x88,0x88,0x50,0x50,0x20,0x00, // 0x56 V
   0x06,0x00,0x88,0x88,0xA8,0xA8,0xD8,0x88,0x00, // 0x57 W
   0x06,0x00,0x88,0x50,0x20,0x20,0x50,0x88,0x00, // 0x58 X
   0x06,0x00,0x88,0x88,0x50,0x20,0x20,0x20,0x00, // 0x59 Y
   0x05,0x00,0xF0,0x10,0x20,0x40,0x80,0xF0,0x00, // 0x5A Z
   0x03,0x00,0xC0,0x80,0x80,0x80,0x80,0xC0,0x00, // 0x5B leftbracket
   0x05,0x00,0x40,0x40,0x20,0x20,0x10,0x10,0x00, // 0x5C backslash
   0x03,0x00,0xC0,0x40,0x40,0x40,0x40,0xC0,0x00, // 0x5D rightbracket
   0x04,0x00,0x40,0xA0,0x40,0x00,0x00,0x00,0x00, // 0x5E ^
   0x05,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00, // 0x5F _
   0x03,0x00,0x80,0x40,0x00,0x00,0x00,0x00,0x00, // 0x60 grave-accent
   0x05,0x00,0x00,0x00,0x70,0x90,0x90,0x70,0x00, // 0x61 a
   0x05,0x00,0x80,0x80,0xE0,0x90,0x90,0xE0,0x00, // 0x62 b
   0x04,0x00,0x00,0x00,0x60,0x80,0x80,0x60,0x00, // 0x63 c
   0x05,0x00,0x10,0x10,0x70,0x90,0x90,0x70,0x00, // 0x64 d
   0x05,0x00,0x00,0x00,0x70,0xB0,0x80,0x70,0x00, // 0x65 e
   0x04,0x00,0x20,0x40,0xE0,0x40,0x40,0x40,0x00, // 0x66 f
   0x05,0x00,0x00,0x00,0x70,0x90,0x90,0x70,0xE0, // 0x67 g
   0x05,0x00,0x80,0x80,0xE0,0x90,0x90,0x90,0x00, // 0x68 h
   0x02,0x00,0x80,0x00,0x80,0x80,0x80,0x80,0x00, // 0x69 i 
   0x03,0x00,0x00,0x40,0x00,0x40,0x40,0x80,0x00, // 0x6A j
   0x05,0x00,0x80,0x80,0xA0,0xC0,0xA0,0x90,0x00, // 0x6B k
   0x02,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x00, // 0x6C l
   0x06,0x00,0x00,0x00,0xD0,0xA8,0xA8,0xA8,0x00, // 0x6D m
   0x05,0x00,0x00,0x00,0xE0,0x90,0x90,0x90,0x00, // 0x6E n
   0x05,0x00,0x00,0x00,0x60,0x90,0x90,0x60,0x00, // 0x6F o
   0x05,0x00,0x00,0x00,0xE0,0x90,0x90,0xE0,0x80, // 0x70 p
   0x05,0x00,0x00,0x00,0x70,0x90,0x90,0x70,0x10, // 0x71 q
   0x04,0x00,0x00,0x00,0x60,0x80,0x80,0x80,0x00, // 0x72 r
   0x04,0x00,0x00,0x00,0x60,0xC0,0x60,0xC0,0x00, // 0x73 s
   0x04,0x00,0x00,0x40,0xE0,0x40,0x40,0x60,0x00, // 0x74 t
   0x05,0x00,0x00,0x00,0x90,0x90,0x90,0x70,0x00, // 0x75 u
   0x05,0x00,0x00,0x00,0x90,0x90,0xA0,0xC0,0x00, // 0x76 v
   0x06,0x00,0x00,0x00,0xA8,0xA8,0xA8,0xD0,0x00, // 0x77 w
   0x05,0x00,0x00,0x00,0x90,0x60,0x60,0x90,0x00, // 0x78 x
   0x06,0x00,0x00,0x00,0x88,0x50,0x20,0x40,0x00, // 0x79 y
   0x05,0x00,0x00,0x00,0xF0,0x20,0x40,0xF0,0x00, // 0x7A z
   0x04,0x00,0x60,0x40,0x80,0x80,0x40,0x60,0x00, // 0x7B {
   0x02,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x00, // 0x7C |
   0x04,0x00,0xC0,0x40,0x20,0x20,0x40,0xC0,0x00, // 0x7D }
   0x05,0x00,0x50,0xA0,0x00,0x00,0x00,0x00,0x00, // 0x7E ~
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x7F
  };
