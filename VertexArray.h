#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include <iostream>

#include "Vector.h"
#include "Exceptions.h"

class VertexArray;
std::ostream& operator<<(std::ostream&, const VertexArray&);

class VertexArray{
    public:
        VertexArray();
        VertexArray(const VertexArray&);
        ~VertexArray();

        VertexArray& operator=(const VertexArray&);
        VertexArray& operator+=(const Vector&);
        VertexArray& operator+=(const VertexArray&);
        Vector& operator[](int);
        const Vector& operator[](int) const;
        operator int() const;

        friend std::ostream& operator<<(std::ostream&, const VertexArray&);

    private:
        Vector** array; //1D dyn arr of Vector objs
        int size;
};

#endif /*VERTEX_ARRAY_H*/