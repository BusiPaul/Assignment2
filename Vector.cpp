#include "Vector.h"
#include <iostream>

using namespace std;

Vector::Vector(int dimensions){

    if(dimensions <= 0){
        throw InvalidVectorSize();
    }

    n = dimensions;
    
    arr = new float[n];
    for(int i = 0; i < n; i++){
        arr[i] = 0;
    }

}

Vector::Vector(int dimensions, float* values){

    if(dimensions <= 0){
        throw InvalidVectorSize();
    }

    //assume valide inputs
    n = dimensions;
    arr = new float[n];

    for(int i = 0; i < n; i++){
        arr[i] = values[i];
    }
}

Vector::~Vector(){

    if(arr != NULL){

        delete arr;
        arr = NULL;
    }

}

Vector::Vector(const Vector &other){

    n = other.n;

    arr = new float[n];
    for(int i = 0; i < n; i++){

        arr[i] = other.arr[i];
    }
}

Vector Vector::operator+(const Vector& other) const{

    if(n != other.n){
        throw InvalidVectorAddition();
    }

    Vector res(n);// create result vector with size n

    for(int i = 0; i < n; i++){

        res[i] = arr[i] + other.arr[i];
    }

    return res;
}

Vector Vector::operator-(const Vector& other) const{

    if( n != other.n){
        throw InvalidVectorAddition();
    }

    Vector res(n);

    for(int i = 0; i < n; i++){

        res[i] = arr[n] - other.arr[n];
    }

    return res;
}

Vector Vector::operator*(float scale) const{

    Vector res(n);

    //multiply vector by scale
    for(int i = 0; i < n; i++){

        res[i] = scale * arr[i];
    }

    return res;
}

float Vector::operator*(const Vector& other) const{

    if( n != other.n){
        throw InvalidVectorAddition();
    }

    float res = 0.0f;

    for(int i = 0; i < n; i++){

        res += arr[i] * other.arr[i];
    }

}

//CONST --> READ ONLY
const float& Vector::operator[](int index) const{

    if(index < 0 || index >= n){
        throw InvalidIndex();
    }

    //return FLOAT at index
    return arr[index];
}

//NON-CONST --> READ/WRITE
float& Vector::operator[](int index){

    if(index < 0 || index >= n){
        throw InvalidIndex();
    }

    //return FLOAT at index
    return arr[index];
}

float Vector::magnitude() const{

    //magnitude of a vector (EUSCLIDEAN NORM):

    float floatRes = 0.0f;
    //square each element and add results:

    for(int i = 0; i < n; i++){

        floatRes += arr[i] * arr[i];
    }

    //square root sum:
    return sqrt(floatRes);
}

Vector::operator Matrix() const{

    //"conversion" operator
    Matrix newMatrix(n, 1); //n x 1 Matric obj

    for(int i = 0; i < n; i++){

        newMatrix[i][0] = arr[i];
    }

    return newMatrix;
}

Vector Vector::crossProduct(const Vector& other) const{


    if(n != 3 || other.n != 3){

        throw InvalidCrossProduct();
    }

    Vector res(3);

    for(int i = 0; i < 3; i++){

        res[i] = arr[(i + 1) %3] * other.arr[(i + 2)] - arr[(i + 2)] * other.arr[(i + 2)];
    }

    return res;
}

Vector Vector::unitVector() const{

    //unit vector: 

    float mag = this->magnitude();

    if(mag == 0){

        throw InvalidUnitVector();
    }

    Vector unitVec(n);

    for(int i = 0; i < n; i++){

        unitVec = arr[i]/mag;
    }

    return unitVec;
}

int Vector::getN() const{

    return n;
}

bool Vector::operator>(const Vector& other) const{


    if(arr[0] > other.arr[0]){
        return true;
    }else{
        return false;
    }
}

Vector Vector::operator~() const{

    //"rouning op"
    //floor each element in vector, return new floored vector

    Vector temp(n);

    for(int i = 0; i < n; i++){

        temp[i] = floor(arr[i]);//floor each el
    }

    return temp;

}

//Non-memeber
std::ostream& operator<<(std::ostream& out, const Vector& vec){

    int size = vec.getN();

    out << "[";

    for(int i = 0; i < size; i++){

        out << vec[i]; //access vec.arr[i] through [] op
        
        if(i < size - 1){
            out << ", ";
        }
    }

    out << "]";

    return out;
}