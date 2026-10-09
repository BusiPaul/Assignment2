#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cmath>
#include <iomanip>

#include "Vector.h"
#include "Exceptions.h"

class Vector;
class Matrix;
std::ostream& operator<<(std::ostream&, const Matrix&);

class Matrix
{
public:
    Matrix(int, int);
    Matrix(int, int, Vector**);
    Matrix(const Matrix &);
    virtual ~Matrix();
    Vector& operator[](int index) const;
    Matrix operator*(const Matrix&) const;
    Vector operator*(const Vector&) const;
    Matrix operator*(const float) const;
    Matrix operator+(const Matrix&) const;
    Matrix operator~() const;
    int getM() const;
    int getN() const;

    friend std::ostream& operator<<(std::ostream&, const Matrix&);

protected:
    int n;
    int m;
    Vector **arr;
};

#endif /*MATRIX_H*/