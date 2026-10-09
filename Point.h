#ifndef POINT_H
#define POINT_H

#include "Shape.h"
#include "ComboShape.h"

class Point: public Shape{
    public:
        Point(const Vector&);
        Point(const Point&);
        Point& operator=(const Point&);
        VertexArray getArray() const;
        virtual Point* applyMatrix(const TransformationMatrix&) const;
        Point* clone() const;
        VertexArray formVertices() const;
        ComboShape* operator+=(const Shape&);
        ComboShape* operator+=(const ComboShape*);
        const Vector& getVector() const;

    private:
        Vector point;
};

#endif /*POINT_H*/