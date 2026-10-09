#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"
#include "Triangle.h"

class Rectangle: public ComboShape{
    public:
        Rectangle(const Vector& tl, const Vector& tr, const Vector& br, const Vector& bl);
        Rectangle(const Rectangle&);
        VertexArray formVertices() const;
        Rectangle* clone() const;
        
};

#endif /*SQUARE_H*/