#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include "Point.h"
#include "Vector.h"

class Triangle: public Shape{
    public:
        Triangle(const Vector& p0, const Vector& p1, const Vector& p2);
        Triangle(const Triangle&);
        VertexArray formVertices() const;
        VertexArray getArray() const;
        Triangle* clone() const;
        virtual Triangle* applyMatrix(const TransformationMatrix&) const;
        virtual ComboShape* operator+=(const Shape&);
        virtual ComboShape* operator+=(const ComboShape*);

    protected:
        Point p0;
        Point p1;
        Point p2;
};

#endif /*TRIANGLE_H*/