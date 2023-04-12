#include <stdint.h>
#include "printfuncs.h"
#include "gfx.h"


void LoadPalettes();
void LoadPatterns();
void FillPlaneA();
void FillPlaneB();

extern const uint32_t fontPallete[50][8];


void wait() {
    unsigned int k;
    for(k = 0; k < 50000; k++) {
        asm("nop");
        asm("nop");
        asm("nop");
    }
}

void main() {
    uint16_t k, x = 0, y = 0;
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
        rprintf("SACBRLDU = 0x%x\n", (int)(SACBRLDU&0xff));
//        rprintf("Tile @ (5,5) is %d\n", (int)readTile(3,5));

        if(SACBRLDU & 1<<0) {
            y--;
        }
        if(SACBRLDU & 1<<1) {
            y++;
        }
        if(SACBRLDU & 1<<2) {
            x--;
        }
        if(SACBRLDU & 1<<3) {
            x++;
        }

        wait();
    }
}

