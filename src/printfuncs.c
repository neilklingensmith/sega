

#include "printfuncs.h"

unsigned int char2font(char c) {
    if((c >= 'a') && (c <= 'z')){
        return c - 'a' + 1;
    } else if((c >= 'A') && (c <= 'Z')){
        return c - 'A' + 1;
    } else if((c >= '0') && (c <= '9')){
        return c - '0' + 26 + 1;
    } else if( c == ' ') {
        return 0;
    }
}


void printString(uint16_t x, uint16_t y, char *str) {

    while(*str != '\0') {
        drawTile(x++, y, char2font(*str));
        str++;
        if(x > SCREEN_TILE_WIDTH) {
            x = 0;
            y++;
        }
    }
}



int stdio_putc(int c) {
    static unsigned short x = 0, y = 0;

    if(c == '\n') {
        y++;
        x = 0;
    } else {
        drawTile(x++, y, char2font(c));
        if(x > SCREEN_TILE_WIDTH) {
            x = 0;
            y++;
        }
    }
}
