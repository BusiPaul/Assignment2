#include "TransformationMatrix.h"
#include <iostream>

using namespace std;

TransformationMatrix::TransformationMatrix() : SquareMatrix(3)
{

    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){

            if(i == j){
                (*arr[i])[j] = 1.0f;
            }else{
                (*arr[i])[j] = 0.0f;
            }
        }
    }

}

TransformationMatrix::TransformationMatrix(const TransformationMatrix& other) : SquareMatrix(other.getN()){

    //n = other.getN();
    //m = other.getM();

    for(int i  = 0; i < n; i++){

        *arr[i] = *other.arr[i];
    }
}

//STATIC FUNCTIONS (non members!!)
TransformationMatrix TransformationMatrix::translation(Vector& dir){

    //move shape around screen
    if(dir.getN() != 3){

        throw InvalidVectorSize();
    }

    //[dx, dy, 1]: dx = translation along x-axis, dy = along y-axis
    TransformationMatrix transformer;
    
    (*transformer.arr[0])[2] = dir[0];
    (*transformer.arr[1])[2] = dir[1];

    return transformer;
}

TransformationMatrix TransformationMatrix::scale(Vector& factors){
    
    if(factors.getN() != 3){

        throw InvalidVectorSize();
    }

    TransformationMatrix transformer;

    (*transformer.arr[0])[0] = factors[0];
    (*transformer.arr[1])[1] = factors[1];
    (*transformer.arr[2])[2] = factors[2];

    return transformer;
}

TransformationMatrix TransformationMatrix::rotate(float radiant){

 
    TransformationMatrix transformer;

    (*transformer.arr[0])[0] = cos(radiant);
    (*transformer.arr[0])[1] = -sin(radiant);
    (*transformer.arr[1])[0] = sin(radiant);
    (*transformer.arr[1])[1] = cos(radiant);
    (*transformer.arr[2])[2] = 1.0f;

    return transformer;
}

TransformationMatrix TransformationMatrix::shear(Vector& factors){

    if(factors.getN() != 3){
        throw InvalidVectorSize();
    }

    TransformationMatrix transformer;

    (*transformer.arr[0])[1] = factors[0];
    (*transformer.arr[1])[0] = factors[1];

    return transformer;
}

TransformationMatrix TransformationMatrix::reflect(){

    TransformationMatrix transformer;

    (*transformer.arr[0])[0] = -1.0f;
    (*transformer.arr[0])[0] = 1.0f;
    (*transformer.arr[0])[0] = 1.0f;

    return transformer;
}