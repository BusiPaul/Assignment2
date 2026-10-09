#include <iostream>

#include "Exceptions.h"
#include "Matrix.h"
#include "Triangle.h"
#include "Point.h"
#include "Screen.h"
#include "Shape.h"
#include "Rectangle.h"
#include "SquareMatrix.h"
#include "TransformationMatrix.h"
#include "Vector.h"
#include "VertexArray.h"

using namespace std;

int main(){
    Vector p0(3);
    p0[0] = 0;
    p0[1] = 0;
    Vector p1(3);
    p1[0] = 5;
    p1[1] = 5;
    Vector p2(3);
    p2[0] = 10;
    p2[1] = 0;

    Triangle t(p0, p1, p2);
    cout << "t's getArray" << endl;
    cout << t.getArray() << endl;

    Screen screen(20, 20);
    screen.draw(t.getArray());
    cout << "Initial Position" << endl;
    cout << screen << endl;

    Vector d1(3);
    d1[0] = 5;
    d1[1] = 0;
    Triangle* t1p = t.applyMatrix(TransformationMatrix::translation(d1));
    cout << "t1p's getArray" << endl;
    cout << t1p->getArray() << endl;

    screen.clearScreen();
    screen.draw((*t1p).getArray());
    cout << "Initial Movement" << endl;
    cout << screen << endl;

    Vector d2(3);
    d1[0] = 0;
    d2[1] = 5;
    Triangle* t2p = t1p->applyMatrix(TransformationMatrix::translation(d2));
    cout << "t2p's getArray" << endl;
    cout << t2p->getArray() << endl;

    screen.clearScreen();
    screen.draw((*t2p).getArray());
    cout << "Second Movement" << endl;
    cout << screen << endl;
    
    Vector tl(3);
    tl[0] = 5;
    tl[1] = 5;
    Vector tr(3);
    tr[0] = 15;
    tr[1] = 5;
    Vector bl(3);
    bl[0] = 5;
    bl[1] = 0;
    Vector br(3);
    br[0] = 15;
    br[1] = 0; 

    ComboShape* cs1 = new ComboShape();
    (*cs1) += *t2p;
    (*cs1) += Rectangle(tl, tr, br, bl);
    cout << "cs1's getArray" << endl;
    cout << cs1->getArray() << endl;

    cout << "Adding sqaure" << endl;
    screen.clearScreen();
    screen.draw((*cs1).getArray());
    cout << screen << endl;

    cout << "Moving House" << endl;
    Vector d3(3);
    d3[0] = 0;
    d3[1] = 5;
    ComboShape* cs2 = cs1->applyMatrix(TransformationMatrix::translation(d3));
    cout << "cs2's getArray" << endl;
    cout << cs2->getArray() << endl;
    screen.clearScreen();
    screen.draw((*cs2).getArray());
    cout << screen << endl;

    delete t1p;
    delete t2p;
    delete cs1;
    delete cs2;

    return 0;
}

//Output is in output.txt