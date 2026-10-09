#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

#include "Matrix.h"
#include "Exceptions.h"

class Matrix;
class Vector;

std::ostream& operator<<(std::ostream&, const Vector&); //make friend??

class Vector
{
public:
    Vector(int);
    Vector(int, float *);
    ~Vector();
    Vector(const Vector &);
    Vector operator+(const Vector&) const;
    Vector operator-(const Vector&) const;
    Vector operator*(float) const;
    float operator*(const Vector&) const;
    const float &operator[](int index) const;
    float& operator[](int index);
    float magnitude() const;
    operator Matrix() const;
    Vector crossProduct(const Vector&) const;
    Vector unitVector() const;
    int getN() const;
    bool operator>(const Vector&) const;
    Vector operator~() const;

private:
    int n;      
    float *arr;
};

#endif /*VECTOR_H*/