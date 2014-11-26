#include <stdio.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsequenced"
int main(void) {
    int i = 1;
    int x =  i++ + ++i;
    printf("%d, %i\n", x, i); // 4,3
    i = 1;
    x = ++i + ++i;
    printf("%d, %i\n", x, i); // 5,3

}
#pragma clang diagnostic pop
