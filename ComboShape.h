#ifndef COMBO_SHAPE_H
#define COMBO_SHAPE_H

#include "Shape.h"

class ComboShape: public Shape{
    public:
        ComboShape();
        ComboShape(const ComboShape&);
        virtual ~ComboShape();
        virtual ComboShape& operator=(const ComboShape&);
        virtual VertexArray getArray() const;
        virtual ComboShape* applyMatrix(const TransformationMatrix&) const;
        virtual ComboShape* clone() const;
        virtual VertexArray formVertices() const;
        virtual ComboShape* operator+=(const Shape&);
        virtual ComboShape* operator+=(const ComboShape*);

    protected:
        Shape** subShapes; //1D dynamic arr of DYNAMIC SHAPE OBJECTS
        int numSubShapes; //number of SHAPES the COMBOSHAPE contains
};

#endif /*COMBO_SHAPE_H*/