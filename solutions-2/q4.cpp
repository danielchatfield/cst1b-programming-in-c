#include <stdio.h>
#include "q3.cpp"

Vector::Vector(const float x, const float y) {
    this->x = x;
    this->y = y;
}

void Vector::pprint(void) {
    printf("\n");
    printf("|%f|\n", this->x);
    printf("|%f|\n", this->y);
    printf("\n");
}

int main() {
    Matrix m(1,2,3,4);
    Matrix n(2,2,-1,0);
    m.pprint();
    n.pprint();

    Matrix o = m + n;

    o.pprint();

    Matrix p = m - n;

    p.pprint();

    Vector x = Vector(1,2);

    Vector y = m * x;

    y.pprint();
}
