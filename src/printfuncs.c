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
    else return 26;
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

static void scroll_screen() {
    int x,y;

    for(y = 0; y < SCREEN_TILE_HEIGHT-1; y++) {
        for(x = 0; x < SCREEN_TILE_WIDTH; x++) {
            uint16_t data = readTile(x,y+1);
            drawTile(x, y, data);
        }
    }
}

int stdio_putc(int c) {
    static unsigned short x = 0, y = 0;

    if(c == '\n') {
        y++;
        x = 0;
    } else {
        drawTile(x++, y, char2font((char)c));
        if(x > SCREEN_TILE_WIDTH) {
            x = 0;
            y++;
        }
    }
    if(y > SCREEN_TILE_HEIGHT-2) {
        y--;
        scroll_screen();
    }

}
