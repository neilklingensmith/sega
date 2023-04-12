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


#ifndef __RPRINTF_H__
#define __RPRINTF_H__


//#include <ctype.h>
//#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

int isdig(int c); // hand-implemented alternative to isdigit(), which uses a bunch of c library functions I don't want to include.

typedef char* charptr;
typedef int (*func_ptr)(int c);

///////////////////////////////////////////////////////////////////////////////
////  Common Prototype functions
/////////////////////////////////////////////////////////////////////////////////
void esp_sprintf(char *buf, char *ctrl, ...);
void esp_vprintf( const func_ptr f_ptr, charptr ctrl, va_list argp);
void esp_printf( const func_ptr f_ptr, charptr ctrl, ...);
void rprintf( charptr ctrl, ...);
#endif
