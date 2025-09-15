//
// Created by penny on 14/09/25.
//

#ifndef TVECTOR2D_H
#define TVECTOR2D_H

template <typename T>
struct TVector2D {
    T x;
    T y;

    // Constructors
    TVector2D() : x(0), y(0) {}
    TVector2D(T xVal, T yVal) : x(xVal), y(yVal) {}
};

#endif //TVECTOR2D_H
