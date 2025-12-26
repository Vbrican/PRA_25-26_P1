#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <stdexcept>
#include "Point2D.h"

class Shape {
protected:
    std::string color;  // "red", "green", "blue"

    // Helper para validar color (uso interno)
    static bool is_valid_color(const std::string &c);

public:
    Shape();                      // por defecto: red
    Shape(std::string color);     // valida, si no -> invalid_argument
    virtual ~Shape() = default;   // MUY recomendable en clases base polimórficas

    std::string get_color() const;
    void set_color(std::string c);

    // Métodos polimórficos puros (interfaz)
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void translate(double incX, double incY) = 0;
    virtual void print() = 0;
};

#endif

