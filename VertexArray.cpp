#include "VertexArray.h"
#include <iostream>

using namespace std;

VertexArray::VertexArray(){

    size = 0; 
    array = NULL;
}

VertexArray::VertexArray(const VertexArray& other){

    size = other.size;

    if(other.array != NULL && size > 0){

        array = new Vector*[size];

        for(int i = 0; i < size; i++){
            array[i] = new Vector(*other.array[i]);
        }
    }else{
        
        array = NULL;
    }
    

}

VertexArray::~VertexArray(){

    if(array != NULL){

        for(int i = 0; i < size; i++){
            delete array[i];
        }

        delete[] array;
        array = NULL;
    }
}

VertexArray& VertexArray::operator=(const VertexArray& other){

    if(this == &other){
        return *this;
    }

    //free existing memeory:
    for(int i = 0; i < size; i++){
        delete array[i];
    }
    delete[] array;
    array = NULL;  
    
    size = other.size;

    if(size > 0 && other.array != NULL){

        //new array
        array = new Vector*[size];

        for(int i = 0; i < size; i++){
            
        }
    }
}


VertexArray& VertexArray::operator+=(const Vector&){}
VertexArray& VertexArray::operator+=(const VertexArray&){}
Vector& VertexArray::operator[](int){}
const Vector& VertexArray::operator[](int) const{}
VertexArray::operator int() const{}
