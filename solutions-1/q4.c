#include <stdio.h>
#include <string.h>

int cntlower(char str[]) {
    int counter = 0;

    for (int i = 0;  i < strlen(str); i++) {
        if(str[i] >= 'a' && str[i] <= 'z')
            counter++;
    }

    return counter;
}

int main(void) {

    char str[] = "Computer Laboratory";

    int counter = cntlower(str);

    printf("%d", counter);

    return 0;
}
