#ifndef SHAPE_H
#define SHAPE_H

#include "TransformationMatrix.h"
#include "VertexArray.h"

class ComboShape;

class Shape{
    public:
        virtual ~Shape(){};
        virtual Shape& operator=(const Shape&){return *this;};
        virtual VertexArray getArray() const =0;
        virtual Shape* applyMatrix(const TransformationMatrix&) const =0;
        virtual Shape* clone() const = 0;
        virtual VertexArray formVertices() const = 0;
        virtual ComboShape* operator+=(const Shape&) =0;
        virtual ComboShape* operator+=(const ComboShape*) =0;
};

#include "ComboShape.h"

#endif /*SHAPE*/