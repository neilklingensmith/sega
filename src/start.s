#.include "variables.inc"

    | Sega Genesis ROM header
    .section .vectors    
    .long   0x00FFE000      | Initial stack pointer value
    .long   0x00000200      | Start of our program in ROM
    .long   Interrupt       | Bus error
    .long   Interrupt       | Address error
    .long   Interrupt       | Illegal instruction
    .long   Interrupt       | Division by zero
    .long   Interrupt       | CHK exception
    .long   Interrupt       | TRAPV exception
    .long   Interrupt       | Privilege violation
    .long   Interrupt       | TRACE exception
    .long   Interrupt       | Line-A emulator
    .long   Interrupt       | Line-F emulator
    .long   Interrupt       | Unused (reserved)
    .long   Interrupt       | Unused (reserved)
    .long   Interrupt       | Unused (reserved)
    .long   Interrupt       | Unused (reserved)
    .long   Interrupt       | Unused (reserved)
    .long   Interrupt       | Unused (reserved)
    .long   Interrupt       | Unused (reserved)
    .long   Interrupt       | Unused (reserved)
    .long   Interrupt       | Unused (reserved)
    .long   Interrupt       | Unused (reserved)
    .long   Interrupt       | Unused (reserved)
    .long   Interrupt       | Unused (reserved)
    .long   Interrupt       | Spurious exception
    .long   Interrupt       | IRQ level 1
    .long   Interrupt       | IRQ level 2
    .long   Interrupt       | IRQ level 3
    .long   HBlankInterrupt | IRQ level 4 (horizontal retrace interrupt)
    .long   Interrupt       | IRQ level 5
    .long   VBlankInterrupt | IRQ level 6 (vertical retrace interrupt)
    .long   Interrupt       | IRQ level 7
    .long   Interrupt       | TRAP #00 exception
    .long   Interrupt       | TRAP #01 exception
    .long   Interrupt       | TRAP #02 exception
    .long   Interrupt       | TRAP #03 exception
    .long   Interrupt       | TRAP #04 exception
    .long   Interrupt       | TRAP #05 exception
    .long   Interrupt       | TRAP #06 exception
    .long   Interrupt       | TRAP #07 exception
    .long   Interrupt       | TRAP #08 exception
    .long   Interrupt       | TRAP #09 exception
    .long   Interrupt       | TRAP #10 exception
    .long   Interrupt       | TRAP #11 exception
    .long   Interrupt       | TRAP #12 exception
    .long   Interrupt       | TRAP #13 exception
    .long   Interrupt       | TRAP #14 exception
    .long   Interrupt       | TRAP #15 exception
    .long   Interrupt       | Unused (reserved)
    .long   Interrupt       | Unused (reserved)
    .long   Interrupt       | Unused (reserved)
    .long   Interrupt       | Unused (reserved)
    .long   Interrupt       | Unused (reserved)
    .long   Interrupt       | Unused (reserved)
    .long   Interrupt       | Unused (reserved)
    .long   Interrupt       | Unused (reserved)
    .long   Interrupt       | Unused (reserved)
    .long   Interrupt       | Unused (reserved)
    .long   Interrupt       | Unused (reserved)
    .long   Interrupt       | Unused (reserved)
    .long   Interrupt       | Unused (reserved)
    .long   Interrupt       | Unused (reserved)
    .long   Interrupt       | Unused (reserved)
    .long   Interrupt       | Unused (reserved)


    | Sega string and copyright
    .ascii "SEGA MEGA DRIVE (C)MARC 2004.SEP"
    | Domestic name
    .ascii "MARCS TEST CODE                                 "
    | Overseas name
    .ascii "MARCS TEST CODE                                 "
    | GM (game), product code and serial
    .ascii "GM 12345678-01"
    | Checksum will be here
    .byte 0x81, 0xB4
    | Which devices are supported ?
    .ascii "JD              "
    | ROM start address
    .byte 0x00, 0x00, 0x00, 0x00
    | ROM end address will be here
    .byte 0x00, 0x02, 0x00, 0x00
    | Some magic values, I don't know what these mean
    .byte 0x00, 0xFF, 0x00, 0x00
    .byte 0x00, 0xFF, 0xFF, 0xFF
    | We don't have a modem, so we fill this with spaces
    .ascii "               "
    | Unused
    .ascii "                        "
    .ascii "                         "
    | Country
    .ascii "JUE             "



|-- Our code starts here (ROM offset: 0x00000200, see line 4)

    tst.l   0x00A10008      | Test on an undocumented (?) IO register ?
    bne     1f              | Branch to the next temp. label 1 if not zero
    tst.w   0x00A1000C      | Test port C control register

 1: bne     SkipSetup       | Branch to SkipSetup if not equal


 |||| Initialize some registers values

    lea     Table, %a5      | Load address of Table into A5                 | A5 = (address of Table)
    movem.w (%a5)+, %d5-%d7 | The content located at the address stored in  | D5 = 0x8000           A5 += 2
                            | A5 is moved into D5. Then A5 gets incremented | D6 = 0x3FFF           A5 += 2
                            | by two (because we've read a word which is two| D7 = 0x0100           A5 += 2
                            | bytes long) and the content of the new loca-
                            | tion is moved into D6, and again for D7
    movem.l (%a5)+, %a0-%a4 | The next four longwords (four bytes) are read | A0 = 0x00A00000       A5 += 4
                            | into A0 - A4, incrementing A5 after each      | A1 = 0x00A11100       A5 += 4
                            | operation by four                             | A2 = 0x00A11200       A5 += 4
                                                                            | A3 = 0x00C00000       A5 += 4
                                                                            | A4 = 0x00C00004       A5 += 4


 |||| Check version number

 | Version from the SEGA Technical Manual:

    move.b  0xA10001, %d0   | Read MegaDrive hardware version               | D0 =(0x00A10001)
    andi.b  #0x0F, %d0      | The version is stored in last four bytes      | D0 = 0x0000xxxx
    beq     1f              | If they are all zero we've got one the very
                            | first MegaDrives which didn't feature the
                            | protection
    move.l  #0x53454741, 0xA14000   | Move the string "SEGA" at 0xA14000


 1: clr.l   %d0             | Move 0 into D0                                | D0 = 0x00000000
    movea.l %d0, %a6        | Move address from D0 into A6 (that is, clear  | A6 = 0x00000000
                            | A6)
    move    %a6, %sp        | Setup Stack Pointer (A7)                      | A7 = 0x00000000

 2: move.l  %d0, -(%a6)     | Decrement A6 by four and and write 0x00000000 | D0 -> (A6)            A6 -= 4
                            | into (A6)
    dbra    %d6, 2b         | If D6 is not zero then decrement D6 and jump
                            | back to 1 (clear user RAM: 0xFFE00000 onward)
                                                                            | D6 = 0x00000000
                                                                            | A6 = 0xFFE00000 ?

    jsr     InitZ80         | Initialize the Z80 / sound
    jsr     InitPSG         | Initialize the PSG
    jsr     InitVDP         | Initialize the VDP




    move.b  #0x40, %d0      | Set last byte of D0 to 0x40
    move.b  %d0, 0x000A10009| We have to write 0x40 into the control ...
    move.b  %d0, 0x000A1000B| ... register of the joystick (data) ports ...
    move.b  %d0, 0x000A1000D| ... or else we might have problems reading ...
                            | ... the joypads on the real hardware





    movem.l (%a6), %d0-%d7/%a0-%a6  | Clear all registers except A7         | D0 = 0x00000000
                            | The registers get cleared because we read from| D1 = 0x00000000
                            | the area which we've set to all-zero in the   | D2 = 0x00000000
                            | "Initialize memory" section                   | D3 = 0x00000000
                                                                            | D4 = 0x00000000
                                                                            | D5 = 0x00000000
                                                                            | D6 = 0x00000000
                                                                            | D7 = 0x00000000
                                                                            | A0 = 0x00000000
                                                                            | A1 = 0x00000000
                                                                            | A2 = 0x00000000
                                                                            | A3 = 0x00000000
                                                                            | A4 = 0x00000000
                                                                            | A5 = 0x00000000
                                                                            | A6 = 0x00000000

    move    #0x2700, %sr    | Move 0x2700 into Status Register, which now
                            | has these set: no trace, A7 is Interupt Stack
                            | Pointer, no interrupts, clear condition code bits





 SkipSetup:
    jmp     main          | Initializing done, jump to main method




 |==============================================================================
 Table:
    .word   0x8000          | D5 (needed for initializing the VDP)
    .word   0x3FFF          | D6 (needed for initializing the RAM)
    .word   0x0100          | D7 (needed for initializing the VDP)
    .long   0x00A00000      | A0 (version port)
    .long   0x00A11100      | A1 (Z80 BUSREQ)
    .long   0x00A11200      | A2 (Z80 RESET)
    .long   0x00C00000      | A3 (VDP data port)
    .long   0x00C00004      | A4 (VDP control port)

    .word   0xaf01, 0xd91f  | The following stuff is for the Z80
    .word   0x1127, 0x0021
    .word   0x2600, 0xf977
    .word   0xedb0, 0xdde1
    .word   0xfde1, 0xed47
    .word   0xed4f, 0xd1e1
    .word   0xf108, 0xd9c1
    .word   0xd1e1, 0xf1f9
    .word   0xf3ed, 0x5636
    .word   0xe9e9, 0x8104
    .word   0x8f01

    .word   0x9fbf, 0xdfff  | PSG values: set channels 0, 1, 2 and 3
                            | to silence.




 |==============================================================================
 | Interrupt routines
 |==============================================================================
 Interrupt:
    rte

 HBlankInterrupt:
    add.l   #1, (VarHsync)
    rte

 VBlankInterrupt:
    add.l   #1, (VarVsync)
    rte220:
 |==============================================================================
 | Initialize the Z80 / load sound program
 |==============================================================================
 InitZ80:
         move.w  %d7, (%a1)      | Write 0x0100 into Z80 BUSREQ. This stops the  | D7 -> (0x00A11100)
                                 | Z80 so that the 68000 can access its bus.
         move.w  %d7, (%a2)      | Write 0x0100 into Z80 RESET to reset the Z80. | D7 -> (0x00A11200)

 1:
         btst    %d0, (%a1)      | Check value of the bit 0 at Z80 BUSREQ
         bne     1b              | Jump back to 1:, waiting for the Z80 until
                                 | it's ready.

         moveq   #0x25, %d2      | Write 0x25 into D2                            | D2 = 0x00000025

 2:
         move.b  (%a5)+, (%a0)+  | Move byte at (A5) into (A0) and increment both| A0 += 1               A5 += 1 * 38 ?
         dbra    %d2, 2b         | Decrement D2 and loop to 2: until D2 == -1.   | D2 -= 1

                                                                                 | D2 = 0xFFFFFFFF
                                                                                 | A0 = 0x00A00026

         move.w  %d0, (%a2)      | Write 0x0000 into Z80 RESET, clear the reset. | D0 -> (0x00A11200)
         move.w  %d0, (%a1)      | Write 0x0000 into Z80 BUSREQ, give bus access | D0 -> (0x00A11100)
                                 | back to the Z80.
         move.w  %d7, (%a2)      | Write 0x0100 into Z80 RESET, resetting it.    | D7 -> (0x00A11200)
         rts                     | Jump back to caller



 |==============================================================================
 | Initialize the Programmable Sound Generator
 | Sets all four channels to silence.
 | See http://www.smspower.org/Development/SN76489 for PSG details.
 |==============================================================================
 InitPSG:
         moveq   #0x03, %d1      | Move 0x03 into D1 to loop 4 times             | D5 = 0x00000003

 1:      move.b  (%a5)+, 0x0011(%a3)     | Write content at (A5) into 0x00C00011,|                       A5 += 1 * 4
                                 | which is the PSG (Programmable Sound Generator)
                                 | Writes 9F, BF, DF and FF which sets the the
                                 | channels 0, 1, 2 and 3 to silence.
         dbra    %d1, 1b         | If D1 is not 0 then decrement D5 and jump     | D5 -= 1
                                 | back to 1

                                                                                 | D5 = 0x00000000
         move.w  %d0, (%a2)      | Write 0x0000 into Z80 RESET ?
         rts                     | Jump back to caller


 |==============================================================================
 | Initialize VDP registers
 |==============================================================================
 InitVDP:
    moveq   #18, %d0        | 24 registers, but we set only 19
    lea     VDPRegs, %a0    | start address of register values

 1: move.b  (%a0)+, %d5     | load lower byte (register value)
    move.w  %d5, (%a4)      | write register
    add.w   %d7, %d5        | next register
    dbra    %d0, 1b         | loop

    rts                     | Jump back to caller


/*
.global      main
|==============================================================================
| MAIN
|==============================================================================
main:
     move.l  #0x00C00000, %a4        | Throughout all my code I'll use A4
     move.l  #0x00C00004, %a5        | for the VDP data port and A5 for the
                                     | VDP control port
    
     bsr     LoadPalettes
     bsr     LoadPatterns
     bsr     FillPlaneA
     bsr     FillPlaneB
     clr.l   %d6                     | Set D6 to 0
     move.w  #0x2000, %sr            | Enable the interrupts
     move.l  #0x50000003, (%a5)      | Point the VDP data port to the hori-
                                     | zontal scroll table
     move.w  #0x8F00, (%a5)          | Disable autoincrement
    
Loop:
    move.w %d0,(%a4)
    addi.w #1,%d0
    move.w #200,%d1
wait:
    dbra %d1,wait
    bra Loop
*/

/*
    bsr     ReadJoypad              | Read joypad values into D7
    
     btst    #2, %d7                 | Test whether for left button
     beq     1f                      | If it's pressed branch to 1
    
     btst    #3, %d7                 | Test whether for right
     bne     3f                      | If it's not pressed branch to 3
    
     addq.w  #1, %d6                 | Increase D6 by one (if right button
                                     | is pressed)
     bra     2f                      | Branch to 2

 1:  subq.w  #1, %d6                 | Decrease D6 by one (if left button
                                     | is pressed)
 2:  move.w  %d6, (%a4)              | Write D6 into horizontal scroll table

 3:  bsr     WaitVsync               | Wait for vertical retrace
     bra     Loop                    | Loop
*/
 |==============================================================================
 | LoadPatterns
 |==============================================================================
    .global LoadPatterns
 LoadPatterns:
     move.l  #0x00C00000, %a4        | Throughout all my code I'll use A4
     move.l  #0x00C00004, %a5        | for the VDP data port and A5 for the
     move.l  #0x40000000, (%a5)      | Point data port to start of VRAM
     move.w  #0x8F02, (%a5)          | Set autoincrement (register 15) to 2

     moveq   #31, %d0                | We'll load 4 patterns, each 8 longs
                                     | wide
     lea     Patterns, %a0           | Load address of Patterns into A0

 1:  move.l  (%a0)+, (%a4)           | Move long word from patterns into VDP
                                     | port and increment A0 by 4
     dbra    %d0, 1b                 | If D0 is not zero decrement and jump
                                     | back to 1

     rts                             | Return to caller
 |==============================================================================
 | FillPlaneA
 |==============================================================================
    .global FillPlaneA
 FillPlaneA:
     move.l  #0x00C00000, %a4        | Throughout all my code I'll use A4
     move.l  #0x00C00004, %a5        | for the VDP data port and A5 for the
     move.l  #0x40000003, (%a5)      | Point data port to 0xC000 in VRAM,
                                     | which is the start address of plane A
     move.w  #0x8F02, (%a5)          | Set autoincrement (register 15) to 2

     move.w  #0x2002, %d0            | We'll use palette #1 and pattern #2,
                                     | don't flip the pattern and set it to
                                     | low priority.
     moveq   #27, %d1                | The screen is 28 cells high

 1:  moveq   #63, %d2                | One line is 64 cells wide

 2:  move.w  %d0, (%a4)              | Move our pattern data into the plane
     dbra    %d2, 2b                 | Loop back to 2

     dbra    %d1, 1b                 | Loop back to 1

     move.l  #0x40000003, %d0
     moveq   #13, %d1                | We want to draw in line 13...
   mulu.w  #64, %d1                | ... and a line is 64 cells wide...
   addi.w  #20, %d1                | ... and we want to draw in column 20
   rol.l   #1, %d1                 | Equivalent to multiply by 2
   swap    %d1                     | Swap words in D1
   or.l    %d1, %d0                | Add it to D0

   move.l  %d0, (%a5)              | Point the VDP to line 13, column 20
                                   | in plane A
   move.w  #0x0003, (%a4)          | Display pattern #3 with palette #0

   rts                             | Return to caller

|==============================================================================
| FillPlaneB
|==============================================================================
    .global FillPlaneB
FillPlaneB:
     move.l  #0x00C00000, %a4        | Throughout all my code I'll use A4
     move.l  #0x00C00004, %a5        | for the VDP data port and A5 for the
   move.l  #0x60000003, (%a5)      | Point data port to 0xE000 in VRAM,
                                   | which is the start address of plane A
   move.w  #0x8F02, (%a5)          | Set autoincrement (register 15) to 2

   move.w  #0x0001, %d0            | We'll use palette #0 and pattern #1,
                                   | don't flip the pattern and set it to
                                   | low priority.
   moveq   #27, %d1                | The screen is 28 cells high

1: moveq   #63, %d2                | One line is 40 cells wide

2: move.w  %d0, (%a4)              | Move our pattern data into the plane
   dbra    %d2, 2b                 | Loop back to 2

   dbra    %d1, 1b                 | Loop back to 1

   rts                             | Return to caller
|==============================================================================
| Read joypad 1
|
| Returns the joypad values in the last byte of D7 with the following layout:
| SACBRLDU (Start A C B Right Left Down Up)
|==============================================================================
ReadJoypad:
   move.l  #0x00A10003, %a0        | Joypad 1 is at 0x00A10003

   move.b  #0x40, (%a0)            | Set TH to high
   nop                             | Wait for the bus to synchronize
   move.b  (%a0), %d7              | Read status into D0

   andi.b  #0x3F, %d7              | D7.b = 00CBRLDU

   move.b  #0x00, (%a0)            | Set TH to low
   nop                             | Wait for the bus to synchronize
   move.b  (%a0), %d0              | Read status into D0
                                   | D0.b = ?0SA00DU

   rol     #2, %d0                 | D0.b = SA00DU??
   andi.b  #0xC0, %d0              | D0.b = SA000000
   or.b    %d0, %d7                | D7.b = SACBRLDU

   rts                             | Return to caller


|==============================================================================
| WaitVsync
|==============================================================================
WaitVsync:
   move.l  (VarVsync), %d0 | Read value from VarVsync into D0

1: move.l  (VarVsync), %d1 | Read value from VarVsync into D1
   cmp.l   %d0, %d1        | Compare D0 and D1
   beq     1b              | If result is 0 the value has not been changed
                           | so jump back to 1

   rts                     | Return to caller



|==============================================================================
| Data
|==============================================================================
Palettes:
   .word   0x0000  | Color 0 is always transparent
   .word   0x00EE  | Yellow
   .word   0x0E00  | Blue
   .word   0x000E  | Red
   .word   0x000E  | Red
   .word   0x000E  | Red
   .word   0x000E  | Red
   .word   0x000E  | Red
   .word   0x000E  | Red
   .word   0x000E  | Red
   .word   0x000E  | Red
   .word   0x000E  | Red
   .word   0x000E  | Red
   .word   0x000E  | Red
   .word   0x000E  | Red
   .word   0x000E  | Red

   .word   0x0000  | Color 0 is always transparent
   .word   0x0000  | Black
   .word   0x0EEE  | White
   .word   0x000E  | Red
   .word   0x000E  | Red
   .word   0x000E  | Red
   .word   0x000E  | Red
   .word   0x000E  | Red
   .word   0x000E  | Red
   .word   0x000E  | Red
   .word   0x000E  | Red
   .word   0x000E  | Red
   .word   0x000E  | Red
   .word   0x000E  | Red
   .word   0x000E  | Red
   .word   0x000E  | Red

Patterns:
   .long   0xFFFFFFFF
   .long   0xFFFFFFFF
   .long   0xFFFFFFFF
   .long   0xFFFFFFFF
   .long   0xFFFFFFFF
   .long   0xFFFFFFFF
   .long   0xFFFFFFFF
   .long   0xFFFFFFFF

   .long   0x22111111
   .long   0x12211111
   .long   0x11221111
   .long   0x11122111
   .long   0x11112211
   .long   0x11111221
   .long   0x11111122
   .long   0x21111112

   .long   0x00000000
   .long   0x00000000
   .long   0x00000000
   .long   0x00011000
   .long   0x00011000
   .long   0x00000000
   .long   0x00000000
   .long   0x00000000

   .long   0x22222222
   .long   0x21111112
   .long   0x21222212
   .long   0x21200212
   .long   0x21200212
   .long   0x21222212
   .long   0x21111112
   .long   0x22222222


 |==============================================================================
 | LoadPalettes
 |==============================================================================
    .global LoadPalettes
 LoadPalettes:
     move.l  #0x00C00000, %a4        | Throughout all my code I'll use A4
     move.l  #0x00C00004, %a5        | for the VDP data port and A5 for the
     move.l  #0xC0000000, (%a5)      | Point data port to CRAM
     move.w  #0x8F02, (%a5)          | Set autoincrement (register 15) to 2

     moveq   #31, %d0                | We'll load 32 colors (2 palettes)
     lea     Palettes, %a0           | Load address of Palettes into A0

 1:  move.w  (%a0)+, (%a4)           | Move word from palette into VDP data
                                     | port and increment A0 by 2
     dbra    %d0, 1b                 | If D0 is not zero decrement and jump
                                     | back to 1

     rts                             | Return to caller



 |==============================================================================
 | Register values for the VDP
 |==============================================================================
 VDPRegs:.byte      0x04    | Reg.  0: Enable Hint, HV counter stop
    .byte   0x74    | Reg.  1: Enable display, enable Vint, enable DMA, V28 mode (PAL & NTSC)
    .byte   0x30    | Reg.  2: Plane A is at 0xC000
    .byte   0x40    | Reg.  3: Window is at 0x10000 (disable)
    .byte   0x07    | Reg.  4: Plane B is at 0xE000
    .byte   0x6A    | Reg.  5: Sprite attribute table is at 0xD400
    .byte   0x00    | Reg.  6: always zero
    .byte   0x00    | Reg.  7: Background color: palette 0, color 0
    .byte   0x00    | Reg.  8: always zero
    .byte   0x00    | Reg.  9: always zero
    .byte   0x00    | Reg. 10: Hint timing
    .byte   0x08    | Reg. 11: Enable Eint, full scroll
    .byte   0x81    | Reg. 12: Disable Shadow/Highlight, no interlace, 40 cell mode
    .byte   0x34    | Reg. 13: Hscroll is at 0xD000
    .byte   0x00    | Reg. 14: always zero
    .byte   0x00    | Reg. 15: no autoincrement
    .byte   0x01    | Reg. 16: Scroll 32V and 64H
    .byte   0x00    | Reg. 17: Set window X position/size to 0
    .byte   0x00    | Reg. 18: Set window Y position/size to 0
    .byte   0x00    | Reg. 19: DMA counter low
    .byte   0x00    | Reg. 20: DMA counter high
    .byte   0x00    | Reg. 21: DMA source address low
    .byte   0x00    | Reg. 22: DMA source address mid
    .byte   0x00    | Reg. 23: DMA source address high, DMA mode ?


    .data
VarVsync:
    .long 0

VarHsync:
    .long 0

