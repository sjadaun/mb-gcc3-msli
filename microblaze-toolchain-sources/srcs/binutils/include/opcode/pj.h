/* Definitions for decoding the picoJava opcode table.
   Copyright (C) 1999 Free Software Foundation, Inc.
   Contributed by Steve Chamberlain of Transmeta (sac@pobox.com).

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */


/* Names used to describe the type of instruction arguments, used by
   the assembler and disassembler.  Attributes are encoded in various fields. */

/*            reloc  size pcrel    uns */
#define O_N    0
#define O_16  (1<<4 | 2 | (0<<6) | (0<<3))
#define O_U16 (1<<4 | 2 | (0<<6) | (1<<3))
#define O_R16 (2<<4 | 2 | (1<<6) | (0<<3))
#define O_8   (3<<4 | 1 | (0<<6) | (0<<3))
#define O_U8  (3<<4 | 1 | (0<<6) | (1<<3))
#define O_R8  (4<<4 | 1 | (0<<6) | (0<<3))
#define O_R32 (5<<4 | 4 | (1<<6) | (0<<3))
#define O_32  (6<<4 | 4 | (0<<6) | (0<<3))

#define ASIZE(x)  ((x) & 0x7)
#define PCREL(x)  (!!((x) & (1<<6)))
#define UNS(x)    (!!((x) & (1<<3)))

                  
typedef struct 
{
  short opcode;
  short opcode_next;
  char len;
  unsigned char arg[2];
  const char *name;
} pj_opc_info_t;