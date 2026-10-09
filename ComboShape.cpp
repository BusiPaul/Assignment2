#include "ComboShape.h"
#include <iostream>

using namespace std;

ComboShape::ComboShape(){

    numSubShapes = 0;
    subShapes = NULL;

}


ComboShape::ComboShape(const ComboShape& other){

    numSubShapes = other.numSubShapes;

    subShapes = new Shape*[numSubShapes];

    for(int i = 0; i < numSubShapes; i++){

        subShapes[i] = other.subShapes[i]->clone(); //use clone() to do deep copy. CANNOT initialise with a Shape constructor (abstract class)
    }
}

ComboShape::~ComboShape(){


    if(subShapes != NULL){

        for(int i = 0; i < numSubShapes; i++){

            delete subShapes[i];
        }

        delete[] subShapes;
        subShapes = NULL;
    }
}

ComboShape& ComboShape::operator=(const ComboShape& other){

    if(this == &other){
        return *this;
    }


    //free existing memeory:
    for(int i = 0; i < numSubShapes; i++){
        delete subShapes[i];
    }
    delete[] subShapes;
    subShapes = NULL;

    //DEEP COPY:
    numSubShapes = other.numSubShapes;

    if(numSubShapes > 0 && other.subShapes != NULL){
        subShapes = new Shape*[numSubShapes];

        for(int i = 0; i < numSubShapes; i++){

            if(other.subShapes[i] != NULL){
                subShapes[i] = other.subShapes[i]->clone();
            }else{
                subShapes[i] = NULL;
            }
            
        }
    }

    return *this;
}

VertexArray ComboShape::getArray() const{

    //loop through subShapes
    //create combined VertexArray
    //--> return ed using fromVertices function

    if(subShapes == NULL || numSubShapes == 0){
        return VertexArray();
    }

    VertexArray result;

    for(int i = 0; i < numSubShapes; i++){

        VertexArray currentVertex = subShapes[i]->formVertices();
        result += currentVertex;
    }

    return result;
}

ComboShape* ComboShape::applyMatrix(const TransformationMatrix& matrix) const{

    //apply passed in matrix to each Shape* in subShapes
    ComboShape* comboMatrix = new ComboShape();

    for(int i = 0; i < numSubShapes; i++){

        if(subShapes[i] != NULL){
            Shape* result = subShapes[i]->applyMatrix(matrix);
            *comboMatrix += *result;
        }

    }

    return comboMatrix;
}

ComboShape* ComboShape::clone() const{

    //return copy of current object;
    return new ComboShape(*this);
}

VertexArray ComboShape::formVertices() const{

    //return same result as getArray
    return this->getArray();
}

ComboShape* ComboShape::operator+=(const Shape& newShape){


    Shape** temp = new Shape*[numSubShapes + 1];//temporary arr
    for(int i = 0; i < numSubShapes; i++){
        temp[i] = subShapes[i]->clone();
    }

    temp[numSubShapes] = newShape.clone();

    //delete and reassign
    delete[] subShapes;
    subShapes = temp;
    numSubShapes++;

    return this;
}

ComboShape* ComboShape::operator+=(const ComboShape* newShape){

    if(newShape == NULL){
        return this;
    }

    Shape** temp = new Shape*[numSubShapes + 1];

    for(int i = 0; i < numSubShapes; i++){
        temp[i] = subShapes[i]->clone();
    }

    temp[numSubShapes] = newShape->clone();

    delete[] subShapes;
    subShapes = temp;
    numSubShapes++;

    return this; //returns ppointer, so "this" not "*this"


}