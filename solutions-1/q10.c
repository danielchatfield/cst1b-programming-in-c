#include <stdio.h>

typedef struct s {
    int i;
    int *j;
} s;

void print(s arr[], s* p, int x) {
    printf("{{%d,%d},{%d,%d},{%d,%d}} p:%d rv:%d\n", arr[0].i,*(arr[0].j),arr[1].i,*(arr[1].j),arr[2].i,*(arr[2].j),p->i,x);
}

int main(void) {

    int x = 4, y = 5, z = 6;

    s arr[] = {{1,&x},{2, &y},{3, &z}};
    s *p = arr;

    int rv = 0;
    print(arr,p,rv);

    rv = ++p->i;
    print(arr,p,rv);

    rv = p++->i;
    print(arr,p,rv);

    rv = *p->j;
    print(arr,p,rv);

    rv = *p->j++;
    print(arr,p,rv);

    rv = (*p->j)++;
    print(arr,p,rv);

    rv = *p++->j;
    print(arr,p,rv);

    return 0;
}
