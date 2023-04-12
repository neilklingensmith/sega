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


#ifndef __CONTROLLER_H
#define __CONTROLLER_H

#define CTRL1_CONTROL  (*(uint8_t*)0xA10009)
#define CTRL1_DATA     (*(uint8_t*)0xA10003)



#define CONTROLLER_SELECT_PRESSED(x)  ((~x>>7) & 1)
#define CONTROLLER_A_PRESSED(x)       ((~x>>6) & 1)
#define CONTROLLER_C_PRESSED(x)       ((~x>>5) & 1)
#define CONTROLLER_B_PRESSED(x)       ((~x>>4) & 1)
#define CONTROLLER_RIGHT_PRESSED(x)   ((~x>>3) & 1)
#define CONTROLLER_LEFT_PRESSED(x)    ((~x>>2) & 1)
#define CONTROLLER_DOWN_PRESSED(x)    ((~x>>1) & 1)
#define CONTROLLER_UP_PRESSED(x)      ((~x>>0) & 1)

#endif
