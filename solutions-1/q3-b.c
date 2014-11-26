#include <stdio.h>
#include <string.h>

int main(void) {

    char str[] = "Computer Laboratory";


    for (int j = strlen(str); j > 1; j--) {
        for (int i = 0; i < j-1; i++) {
            if (strcmp(&str[i], &str[i+1]) > 0) {
                int rv = str[i];
                str[i] = str[i+1];
                str[i+1] = rv;
            }
        }
    }

    // Test it

    for (int i = 0; i < strlen(str); i++) {
        printf("%c", str[i]);
    }

    return 0;
}
