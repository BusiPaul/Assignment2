#ifndef SQR_MAT_H
#define SQR_MAT_H

#include "Matrix.h"
#include "Vector.h"

class SquareMatrix : public Matrix
{
public:
    SquareMatrix(int);
    SquareMatrix(int, Vector **);
    SquareMatrix(const SquareMatrix&);
};

#endif /*SQR_MAT_H*/