#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include "VertexArray.h"

class Screen;
std::ostream& operator<<(std::ostream&, const Screen&);

class Screen{
    public:
        Screen(int height, int width);
        ~Screen();
        friend std::ostream& operator<<(std::ostream&, const Screen&);
        void draw(const VertexArray&);
        void draw(int x, int y);
        void draw(const Vector& p0, const Vector& p1);
        void clearScreen();

        static float implicitLineEquation(const Vector& p0, const Vector& p1, const Vector& p);

    private:
        char** pixels;
        int height;
        int width;

};

#endif /*SCREEN_H*/