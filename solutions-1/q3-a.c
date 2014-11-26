#include <stdio.h>

int main(void) {

    int items[] = {4, 6, 5, 1, 8, 2, 8, 6};

    int n = sizeof(items)/sizeof(items[0]);

    for (int j = n; j > 1; j--) {
        for (int i = 0; i < j-1; i++) {
            if (items[i] > items[i+1]) {
                int rv = items[i];
                items[i] = items[i+1];
                items[i+1] = rv;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if(i != 0) {
            printf(",");
        }
        printf("%d", items[i]);
    }

    return 0;
}
