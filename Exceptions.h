#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

class Exception{};
class VectorExceptions: public Exception{};
class MatrixExceptions: public Exception{};
class InvalidVectorSize : public VectorExceptions{};
class InvalidMatrixSize : public MatrixExceptions{};
class InvalidMatrixMultiplication : public MatrixExceptions{};
class InvalidIndex : public Exception{};
class InvalidMatrixAddition : public MatrixExceptions{};
class InvalidVectorAddition : public VectorExceptions{};
class InvalidDotProduct : public VectorExceptions{};
class InvalidCrossProduct : public VectorExceptions{};
class InvalidUnitVector : public VectorExceptions{};

#endif /*EXCEPTIONS_H*/