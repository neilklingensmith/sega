
#include <stdint.h>

uint32_t strlen(char *s) {
    uint32_t len = 0;

    while(s[len]) {
        len++;
    }
    return len;
}

int tolower(int c) {
    if(c >= 'A' && c <= 'Z') return c -32;
    else return c;
}