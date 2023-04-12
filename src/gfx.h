

#include <stdint.h>

#ifndef __GFX_H_
#define __GFX_H_

#define SCREEN_TILE_WIDTH 39



void setAutoIncrementRegister(unsigned char ai);
void loadTiles(uint16_t *buf, uint32_t len);




#endif

