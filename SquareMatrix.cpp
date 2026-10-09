#include "SquareMatrix.h"
#include <iostream>

using namespace std;

SquareMatrix::SquareMatrix(int size):Matrix(size, size){


    arr = new Vector*[size];//create

    for(int i = 0; i < size; i++){
        arr[i] = new Vector(size);//create
    }
}


SquareMatrix::SquareMatrix(int size, Vector ** myArr): Matrix(size, size, myArr)
{
}

SquareMatrix::SquareMatrix(const SquareMatrix& other) : Matrix(other.getN(), other.getM())
{
    n = other.getN();
    m = other.getM();

    arr = new Vector*[n];

    for(int i = 0; i < n; i++){

        arr[i] = new Vector(*other.arr[i]);
    }

}
