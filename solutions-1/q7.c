#include <stdio.h>

#define SWAP(x,y) { x > y ? \
    (x = x - y, y = y + x, x = y - x): \
    (y = y - x, x = x + y, y = x - y);}

int main(void) {

    int x = 2;
    int y = 4;

    SWAP(x,y);
    printf("X:%d,Y:%d\n",x,y);
}
