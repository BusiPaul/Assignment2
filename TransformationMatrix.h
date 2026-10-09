#ifndef TRANSFORMATION_MATRIX_H
#define TRANSFORMATION_MATRIX_H

#include "SquareMatrix.h"

class TransformationMatrix: public SquareMatrix{
    public:
        TransformationMatrix(const TransformationMatrix&);
        static TransformationMatrix translation(Vector& dir);
        static TransformationMatrix scale(Vector& factors);
        static TransformationMatrix rotate(float radiant);
        static TransformationMatrix shear(Vector& factors);
        static TransformationMatrix reflect();

    protected:
        TransformationMatrix();
        
};

#endif /*TRANSFORMATION_MATRIX_H*/