#include <stdio.h>
#include <string.h>

const char* strfind(const char* s, const char* f) {
    while (*f != '\0') {
        if (*s == *f) {
            return f;
        }
        f++;
    }

    return NULL;
}

int main(void) {
    char haystack[] = "Computer Laboratory";
    char needle = 'L';

    const char *b = strfind(&needle, haystack);

    if (b == NULL) {
        printf("NULL");
    } else {
        printf("%c", *b);
    }
}
