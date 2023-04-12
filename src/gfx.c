

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
