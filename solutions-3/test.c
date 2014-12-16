#include <stdio.h>

int main(void) {
    // Address | Byte offset
    // ....... | 00 01 02 03
    // ________|_____________
    // 0x04 .. | 10 00 00 00
    // 0x08 .. | 61 72 62 33
    // 0x0c .. | 33 00 00 00
    // 0x10 .. | 78 0c 00 00
    // 0x14 .. | 08 00 00 00
    // 0x18 .. | 01 00 4c 03
    // 0x1c .. | 18 00 00 00

    int **i=(int **)0x04;
    //short **pps=(short **)0x1c;
    //struct i2c {int i; char *c;}*p=(struct i2c*)0x10;

    printf("Value is %d", **i);
    //printf("Address is %p\n", (void *)p);
    //printf("Address is %p\n", (void *)pp);
    //printf("Address is %p\n", (void *)i);
    //cout << p->c[2] << "\n";
    //cout << &(*pps)[1] << "\n";
    //cout << ++p->i << "\n";

    return 0;
}
