#include <stdio.h>
#include "q3.h"

Matrix::Matrix(
    const float a,
    const float b,
    const float c,
    const float d
    ) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
}

void Matrix::pprint() {
    printf("\n|%f %f|\n", this->a, this->b);
    printf("|%f %f|\n\n", this->c, this->d);
}

Matrix Matrix::operator+(const Matrix & right) {
    return Matrix(
        this->a + right.a,
        this->b + right.b,
        this->c + right.c,
        this->d + right.d
    );
}

Matrix Matrix::operator-(const Matrix & right) {
    return Matrix(
        this->a - right.a,
        this->b - right.b,
        this->c - right.c,
        this->d - right.d
    );
}

Matrix Matrix::operator*(const float x) {
    return Matrix(
    this->a * x,
    this->b * x,
    this->c * x,
    this->d * x
    );
}

Vector Matrix::operator*(const Vector & right) {
    return Vector(
        this->a * right.x + this->b * right.y,
        this->c * right.x + this->d * right.y
    );
}

Matrix Matrix::operator*(const Matrix & right) {
    return Matrix(
        this->a * right.a + this->b * right.c,
        this->a * right.b + this->b * right.d,
        this->c * right.a + this->d * right.c,
        this->c * right.b + this->d * right.d
    );
}

Matrix Matrix::operator/(const Matrix & right) {
    float inverseDeterminant
        = 1.0 / (right.a * right.d - right.b * right.c);

    return Matrix(
        this->a *  right.d + this->b * -right.c,
        this->a * -right.b + this->b *  right.a,
        this->c *  right.d + this->d * -right.c,
        this->c * -right.b + this->d *  right.a
    ) * inverseDeterminant;
}
