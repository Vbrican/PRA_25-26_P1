#include "Drawing.h"

#include <iostream>
#include "Circle.h"
#include "Square.h"

// Interfaz y una implementación concreta
#include "List.h"
#include "ListLinked.h"   // o ListArray.h si usas array

Drawing::Drawing() {
    shapes = new ListLinked<Shape*>();
    // shapes = new ListArray<Shape*>(); // alternativa
}

Drawing::~Drawing() {
    // Liberamos las figuras (si Drawing “posee” las shapes)
    for (int i = 0; i < shapes->size(); ++i) {
        Shape* s = shapes->get(i);
        delete s;
    }
    delete shapes;
}

void Drawing::add_front(Shape* shape) {
    shapes->insert(0, shape);
}

void Drawing::add_back(Shape* shape) {
    shapes->insert(shapes->size(), shape);
}

void Drawing::print_all() {
    for (int i = 0; i < shapes->size(); ++i) {
        shapes->get(i)->print();
        std::cout << std::endl;
    }
}

double Drawing::get_area_all_circles() {
    double total = 0.0;
    for (int i = 0; i < shapes->size(); ++i) {
        Shape* s = shapes->get(i);
        if (dynamic_cast<Circle*>(s) != nullptr) {
            total += s->area();
        }
    }
    return total;
}

void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); ++i) {
        Shape* s = shapes->get(i);
        if (dynamic_cast<Square*>(s) != nullptr) {
            s->translate(incX, incY);
        }
    }
}

