#ifndef __CONTROLLER_H
#define __CONTROLLER_H

#define CTRL1_CONTROL  (*(uint8_t*)0xA10009)
#define CTRL1_DATA     (*(uint8_t*)0xA10003)



#define CONTROLLER_SELECT_PRESSED(x)  ((x>>7) & 1)
#define CONTROLLER_A_PRESSED(x)       ((x>>6) & 1)
#define CONTROLLER_C_PRESSED(x)       ((x>>5) & 1)
#define CONTROLLER_B_PRESSED(x)       ((x>>4) & 1)
#define CONTROLLER_RIGHT_PRESSED(x)   ((x>>3) & 1)
#define CONTROLLER_LEFT_PRESSED(x)    ((x>>2) & 1)
#define CONTROLLER_DOWN_PRESSED(x)    ((x>>1) & 1)
#define CONTROLLER_UP_PRESSED(x)      ((x>>0) & 1)

#endif
