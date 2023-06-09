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

#include <stdint.h>

const uint32_t fontPallete[50][8] = {
                                    {0x00000000,
                                     0x00000000,
                                     0x00000000,
                                     0x00000000,
                                     0x00000000,
                                     0x00000000,
                                     0x00000000,
                                     0x00000000},

                                    {0x01111100,
                                     0x11000110,
                                     0x10111010,
                                     0x10000010,
                                     0x10111010,
                                     0x10101010,
                                     0x11101110,
                                     0x00000000},

                                    {0x11111100,
                                     0x10000110,
                                     0x10111010,
                                     0x10000110,
                                     0x10111010,
                                     0x10000110,
                                     0x11111100,
                                     0x00000000},

                                    {0x01111110,
                                     0x11000010,
                                     0x10111110,
                                     0x10100000,
                                     0x10111110,
                                     0x11000010,
                                     0x01111110,
                                     0x00000000},

                                    {0x11111100,
                                     0x10000110,
                                     0x10111010,
                                     0x10101010,
                                     0x10111010,
                                     0x10000110,
                                     0x11111100,
                                     0x00000000},

                                    {0x11111110,
                                     0x10000010,
                                     0x10111110,
                                     0x10001000,
                                     0x10111110,
                                     0x10000010,
                                     0x11111110,
                                     0x00000000},

                                    {0x11111110,
                                     0x10000010,
                                     0x10111110,
                                     0x10001000,
                                     0x10111000,
                                     0x10100000,
                                     0x11100000,
                                     0x00000000},

                                    {0x01111110,
                                     0x11000010,
                                     0x10111110,
                                     0x10100010,
                                     0x10111010,
                                     0x11000010,
                                     0x01111110,
                                     0x00000000},

                                    {0x11101110,
                                     0x10101010,
                                     0x10111010,
                                     0x10000010,
                                     0x10111010,
                                     0x10101010,
                                     0x11101110,
                                     0x00000000},

                                    {0x11111110,
                                     0x10000010,
                                     0x11101110,
                                     0x00101000,
                                     0x11101110,
                                     0x10000010,
                                     0x11111110,
                                     0x00000000},

                                    {0x00001110,
                                     0x00001010,
                                     0x00001010,
                                     0x11101010,
                                     0x10111010,
                                     0x11000110,
                                     0x01111100,
                                     0x00000000},

                                    {0x11101110,
                                     0x10111010,
                                     0x10110110,
                                     0x10001100,
                                     0x10110110,
                                     0x10111010,
                                     0x11101110,
                                     0x00000000},

                                    {0x11100000,
                                     0x10100000,
                                     0x10100000,
                                     0x10100000,
                                     0x10111110,
                                     0x10000010,
                                     0x11111110,
                                     0x00000000},

                                    {0x11101110,
                                     0x10111010,
                                     0x10010010,
                                     0x10101010,
                                     0x10111010,
                                     0x10101010,
                                     0x11101110,
                                     0x00000000},

                                    {0x11101110,
                                     0x10111010,
                                     0x10011010,
                                     0x10101010,
                                     0x10110010,
                                     0x10111010,
                                     0x11101110,
                                     0x00000000},

                                    {0x01111100,
                                     0x11000110,
                                     0x10111010,
                                     0x10101010,
                                     0x10111010,
                                     0x11000110,
                                     0x01111100,
                                     0x00000000},

                                    {0x11111100,
                                     0x10000110,
                                     0x10111010,
                                     0x10000110,
                                     0x10111100,
                                     0x10100000,
                                     0x11100000,
                                     0x00000000},

                                    {0x01111100,
                                     0x11000110,
                                     0x10111010,
                                     0x10101010,
                                     0x10110110,
                                     0x11001010,
                                     0x01111110,
                                     0x00000000},

                                    {0x11111100,
                                     0x10000110,
                                     0x10111010,
                                     0x10000110,
                                     0x10110110,
                                     0x10111010,
                                     0x11101110,
                                     0x00000000},

                                    {0x01111110,
                                     0x11000010,
                                     0x10111110,
                                     0x11000110,
                                     0x11111010,
                                     0x10000110,
                                     0x11111100,
                                     0x00000000},

                                    {0x11111110,
                                     0x10000010,
                                     0x11101110,
                                     0x00101000,
                                     0x00101000,
                                     0x00101000,
                                     0x00111000,
                                     0x00000000},

                                    {0x11101110,
                                     0x10101010,
                                     0x10101010,
                                     0x10101010,
                                     0x10111010,
                                     0x11000110,
                                     0x01111100,
                                     0x00000000},

                                    {0x11101110,
                                     0x10101010,
                                     0x10111010,
                                     0x11010110,
                                     0x01010100,
                                     0x01101100,
                                     0x00111000,
                                     0x00000000},

                                    {0x11101110,
                                     0x10101010,
                                     0x10111010,
                                     0x10101010,
                                     0x10010010,
                                     0x10111010,
                                     0x11101110,
                                     0x00000000},

                                    {0x11101110,
                                     0x10111010,
                                     0x11010110,
                                     0x01101100,
                                     0x11010110,
                                     0x10111010,
                                     0x11101110,
                                     0x00000000},

                                    {0x11101110,
                                     0x10111010,
                                     0x11010110,
                                     0x01101100,
                                     0x00101000,
                                     0x00101000,
                                     0x00111000,
                                     0x00000000},

                                    {0x11111110,
                                     0x10000010,
                                     0x11110110,
                                     0x01101100,
                                     0x11011110,
                                     0x10000010,
                                     0x11111110,
                                     0x00000000},

                                    {0x01111100,
                                     0x11000110,
                                     0x10110010,
                                     0x10101010,
                                     0x10011010,
                                     0x11000110,
                                     0x01111100,
                                     0x00000000},

                                    {0x01111000,
                                     0x01001000,
                                     0x01101000,
                                     0x00101000,
                                     0x01101100,
                                     0x01000100,
                                     0x01111100,
                                     0x00000000},

                                    {0x11111100,
                                     0x10000110,
                                     0x11111010,
                                     0x11000110,
                                     0x10111110,
                                     0x10000010,
                                     0x11111110,
                                     0x00000000},

                                    {0x11111100,
                                     0x10000110,
                                     0x11111010,
                                     0x00100110,
                                     0x11111010,
                                     0x10000110,
                                     0x11111100,
                                     0x00000000},

                                    {0x11101110,
                                     0x10101010,
                                     0x10111010,
                                     0x10000010,
                                     0x11111010,
                                     0x00001010,
                                     0x00001110,
                                     0x00000000},

                                    {0x11111110,
                                     0x10000010,
                                     0x10111110,
                                     0x10000110,
                                     0x11111010,
                                     0x10000110,
                                     0x11111100,
                                     0x00000000},

                                    {0x01111100,
                                     0x11000100,
                                     0x10111100,
                                     0x10000110,
                                     0x10111010,
                                     0x11000110,
                                     0x01111100,
                                     0x00000000},

                                    {0x11111110,
                                     0x10000010,
                                     0x11111010,
                                     0x00110110,
                                     0x01101100,
                                     0x01011000,
                                     0x01110000,
                                     0x00000000},

                                    {0x01111100,
                                     0x11000110,
                                     0x10111010,
                                     0x11000110,
                                     0x10111010,
                                     0x11000110,
                                     0x01111100,
                                     0x00000000},

                                    {0x01111100,
                                     0x11000110,
                                     0x10111010,
                                     0x11000010,
                                     0x01111010,
                                     0x01000110,
                                     0x01111100,
                                     0x00000000},

                                    {0x00000000,
                                     0x00000000,
                                     0x00000000,
                                     0x00000000,
                                     0x00000000,
                                     0x11000000,
                                     0x11000000,
                                     0x00000000},

                                    {0x00000000,
                                     0x00000000,
                                     0x00000000,
                                     0x00000000,
                                     0x11100000,
                                     0x10100000,
                                     0x10100000,
                                     0x11100000},

                                    {0x01111100,
                                     0x11000110,
                                     0x10111010,
                                     0x11100110,
                                     0x00111100,
                                     0x00101000,
                                     0x00111000,
                                     0x00000000},

                                    {0x11100000,
                                     0x10100000,
                                     0x10100000,
                                     0x10100000,
                                     0x11100000,
                                     0x10100000,
                                     0x11100000,
                                     0x00000000},

                                    {0x01110000,
                                     0x11010000,
                                     0x10110000,
                                     0x10100000,
                                     0x10110000,
                                     0x11010000,
                                     0x01110000,
                                     0x00000000},

                                    {0x11100000,
                                     0x10110000,
                                     0x11010000,
                                     0x01010000,
                                     0x11010000,
                                     0x10110000,
                                     0x11100000,
                                     0x00000000},

                                    {0x11111000,
                                     0x10101000,
                                     0x10101000,
                                     0x11111000,
                                     0x00000000,
                                     0x00000000,
                                     0x00000000,
                                     0x00000000},

                                    {0x11100000,
                                     0x10100000,
                                     0x10100000,
                                     0x11100000,
                                     0x00000000,
                                     0x00000000,
                                     0x00000000,
                                     0x00000000},

                                    {0x00000000,
                                     0x11100000,
                                     0x10100000,
                                     0x11100000,
                                     0x10100000,
                                     0x11100000,
                                     0x00000000,
                                     0x00000000},

                                    {0x01111100,
                                     0x11010110,
                                     0x10000010,
                                     0x11010110,
                                     0x10000010,
                                     0x11010110,
                                     0x01111100,
                                     0x00000000},

                                    {0x00111000,
                                     0x00101000,
                                     0x11101110,
                                     0x10000010,
                                     0x11101110,
                                     0x00101000,
                                     0x00111000,
                                     0x00000000},

                                    {0x00000000,
                                     0x00000000,
                                     0x11111110,
                                     0x10000010,
                                     0x11111110,
                                     0x00000000,
                                     0x00000000,
                                     0x00000000},

                                    {0x00011100,
                                     0x00110100,
                                     0x01101100,
                                     0x11011000,
                                     0x10110000,
                                     0x11100000,
                                     0x00000000,
                                     0x00000000}};


