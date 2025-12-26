#ifndef DRAWING_H
#define DRAWING_H

#include "Shape.h"

// Forward declaration (porque List<T> es abstracta y solo guardamos un puntero)
template <typename T>
class List;

class Drawing {
private:
    List<Shape*>* shapes;

public:
    Drawing();
    ~Drawing();

    void add_front(Shape* shape);
    void add_back(Shape* shape);

    void print_all();

    double get_area_all_circles();

    void move_squares(double incX, double incY);
};

#endif

