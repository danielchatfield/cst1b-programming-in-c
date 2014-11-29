class Vector {
    float x;
    float y;

    friend class Matrix;

public:
    Vector(const float x, const float y);
    void pprint();
};

class Matrix {
    float a;
    float b;
    float c;
    float d;

public:

    Matrix(
        const float a,
        const float b,
        const float c,
        const float d
    );

    void pprint();

    Matrix operator+(const Matrix & right);
    Matrix operator-(const Matrix & right);
    Matrix operator*(const float x);
    Vector operator*(const Vector & right);
    Matrix operator*(const Matrix & right);
    Matrix operator/(const Matrix & right);
};
