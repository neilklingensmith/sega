
#include <stdint.h>


#define CTRL1_CONTROL  (*(uint8_t*)0xA10009)
#define CTRL1_DATA     (*(uint8_t*)0xA10003)

uint8_t readController() {

    uint8_t CBRLDU = 0, SA = 0;
    CTRL1_CONTROL = 0x40; // Set TH pin to be a write
    CTRL1_DATA = 0x40;    // Set TH pin to 1
    asm("nop");
    asm("nop"); // delay
    CBRLDU = CTRL1_DATA & 0x3f;
    CTRL1_DATA = 0;    // Set TH pin to 0
    asm("nop");
    asm("nop"); // delay
    SA = CTRL1_DATA << 2;

    return SA | CBRLDU;
}
