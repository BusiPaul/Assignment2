#include "Matrix.h"
#include <iostream>

Matrix::Matrix(int rows, int cols){

    if(rows <= 0 || cols <= 0){
        throw InvalidMatrixSize();
    }

    n = rows;
    m = cols;

    arr = new Vector*[n];


    for(int i = 0; i < n; i++){

        arr[i] = new Vector(m);
    }
}


Matrix::Matrix(int rows, int cols, Vector** vecArr){

    //initialise members
    n = rows;
    m = cols;

    arr = new Vector*[n];

    for(int i = 0; i < n; i++){
        arr[i] = new Vector(*vecArr[i]);
    }
}


Matrix::Matrix(const Matrix & other){

    n = other.n;
    m = other.m;

    arr = new Vector*[n];

    for(int i = 0; i < n; i++){

        arr[i] = new Vector(*other.arr[i]);
    }
}

Matrix::~Matrix(){

    //1D dynamic array of Vector POINTERS!!
    for(int i = 0; i < n; i++){

        delete arr[i];
    }
    delete[] arr;
    arr = NULL;
}


Vector& Matrix::operator[](int index) const{

    if(index < 0 || index >= n){
        throw InvalidMatrixMultiplication();
    }


    return *arr[index];
}

Matrix Matrix::operator*(const Matrix& other) const{

    //multiply two matrices:
    //call operator* on the VECTORS

    //int sum = 0;

    if(m != other.n){
        throw InvalidMatrixMultiplication();
    }


    Matrix newMatrix(n, other.m);

    for(int i = 0; i < n; i++){ //rows of current M

        for(int j = 0; j < other.m; j++){ //cols of other M

            float sum = 0.0f;

            for(int k = 0; k < m; k++){

                sum += arr[i][k] * other.arr[k][j];
            }

            newMatrix[i][j] = sum;

        }
    }

    return newMatrix;
}

Vector Matrix::operator*(const Vector& otherVec) const{

    if(m != otherVec.getN()){

        throw InvalidMatrixMultiplication();
    }

    Vector newVector(n);

    for(int i = 0; i < n; i++){

        newVector[i] = (*arr[i]) * otherVec;
    
    }

    return newVector;
}


Matrix Matrix::operator*(const float value) const{

    Matrix newMatrix(n, m);

    for(int i = 0; i < n; i++){
        
        *newMatrix.arr[i] = (*arr[i]) * value; //operator*(float) --> rhs == float

    }

    return newMatrix;
}

Matrix Matrix::operator+(const Matrix& other) const{

    if(n != other.n && m != other.m){
        throw InvalidMatrixAddition();
    }

    Matrix newMatrix(n,m);

    for(int i = 0; i < n; i++){

        *newMatrix.arr[i] = (*arr[i]) + (*other.arr[i]);
    }

    return newMatrix;
}

Matrix Matrix::operator~() const{

    //rows become cols
    //cols become rows

    Matrix newMatrix(m, n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            newMatrix.arr[j][i] = (*arr[i])[j];
        }
    }

    return newMatrix;

}

int Matrix::getM() const{

    return m;
}

int Matrix::getN() const{

    return n;
}


std::ostream& operator<<(std::ostream& os, const Matrix& matrix){

    for(int i = 0; i < matrix.getN(); i++){

        //call VECTOR's << op
        os << *matrix.arr[i] << "\n";
    }

    return os;
}
