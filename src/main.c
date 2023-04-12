/*
 * Sega Genesis Base Project
 *
 * Copyright (c) 2023 Neil Klingensmith
 * neil@cs.luc.edu
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include <stdint.h>
#include "printfuncs.h"
#include "gfx.h"
#include "controller.h"

void LoadPalettes();
void LoadPatterns();
void FillPlaneA();
void FillPlaneB();

extern const uint32_t fontPallete[50][8];


void wait() {
    unsigned int k;
    for(k = 0; k < 10000; k++) {
        asm("nop");
        asm("nop");
        asm("nop");
    }
}

void main() {
    uint16_t k, x = 5, y = 5;
    uint8_t SACBRLDU; // Controller state

    LoadPalettes();
    loadTiles((uint16_t*)fontPallete, sizeof(fontPallete));
    (*(uint32_t*)0x00C00004) = 0x50000003;
    (*(uint16_t*)0x00C00004) = 0x8F00;
    //Point data port to 0xC000 in VRAM,
    //which is the start address of plane A
    *(uint32_t*)0x00C00004 = 0x40000003;

    rprintf("booting up\n\n");

    while(1){
//        printString(x,y, "Hello Dave");
        SACBRLDU = readController();
//        rprintf("SACBRLDU = 0x%x\n", (int)(SACBRLDU&0xff));
//        rprintf("Tile @ (5,5) is %d\n", (int)readTile(3,5));

        if(CONTROLLER_UP_PRESSED(SACBRLDU)) {
            y--;
        }
        if(CONTROLLER_DOWN_PRESSED(SACBRLDU)) {
            y++;
        }
        if(CONTROLLER_LEFT_PRESSED(SACBRLDU)) {
            x--;
        }
        if(CONTROLLER_RIGHT_PRESSED(SACBRLDU)) {
            x++;
        }

        printString(x, y, "NEIL");
        wait();
    }
}

