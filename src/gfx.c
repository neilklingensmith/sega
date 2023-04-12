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


#include "gfx.h"




/*
 * setAutoIncrementRegister
 *
 * Sets the VDP's autoincrement register
 *
 */
void setAutoIncrementRegister(unsigned char ai) {
    uint16_t *controlReg = (uint16_t*)0x00C00004; // Address of the VDP control register
    *controlReg = 0x8F00 | (uint16_t)ai;
}

/*
 * loadTiles
 *
 * Loads a set of tiles into the VDP memory.
 *
 */
void loadTiles(uint16_t *buf, uint32_t len) {
    int k = 0;
//    setAutoIncrementRegister(2);
    *((uint32_t*)0xc00004) = 0x40000000; // Writing to VRAM address 0

    while(k < len){
        *((uint16_t*)0xc00000) = *buf; // Write tile data to VRAM
        buf++;
        k++;
    }
}

void drawTile(unsigned short x, unsigned short y, unsigned short tileno) {
    unsigned short linewidth = 64;
    unsigned int offset = 2*(x + linewidth * y); // Each tile takes two bytes in VDP mem

    // Write 
    *(uint32_t*)0x00C00004 = 0x40000003 | ((offset&0x3fff) << 16) | ((offset&0xc000) >> 14);
    (*(uint16_t*)0x00C00000) = tileno & 0xff;
}

unsigned short readTile(unsigned short x, unsigned short y) {

    uint16_t val;
    unsigned short linewidth = 64;
    unsigned int offset = 2*(x + linewidth * y); // Each tile takes two bytes in VDP mem
    *(uint32_t*)0x00C00004 = 0x00000003 | (offset << 16);
    val = (*(uint16_t*)0x00C00000);
    return (val);
}
