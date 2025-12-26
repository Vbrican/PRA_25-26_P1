#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>

class Point2D {
public:
    double x;  // Coordenada x
    double y;  // Coordenada y

    // Constructor (por defecto x=0, y=0)
    Point2D(double x = 0.0, double y = 0.0);

    // Distancia euclidiana entre dos puntos
    static double distance(const Point2D &a, const Point2D &b);

    // Operadores globales (declarados aquí como friend)
    friend bool operator==(const Point2D &a, const Point2D &b);
    friend bool operator!=(const Point2D &a, const Point2D &b);
    friend std::ostream& operator<<(std::ostream &out, const Point2D &p);
};

#endif

