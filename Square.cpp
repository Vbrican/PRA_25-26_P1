#include "Square.h"
#include <cmath>

static const double EPS = 1e-9;

bool Square::check(Point2D* vertices) {
    if (vertices == nullptr) return false;

    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);

    return (std::fabs(d01 - d12) < EPS) &&
           (std::fabs(d12 - d23) < EPS) &&
           (std::fabs(d23 - d30) < EPS);
}

Square::Square() : Rectangle() {
    // Reemplazamos los vértices por defecto del rectángulo por los del cuadrado
    Point2D v[Rectangle::N_VERTICES] = {
        Point2D(-1,  1),
        Point2D( 1,  1),
        Point2D( 1, -1),
        Point2D(-1, -1)
    };
    Rectangle::set_vertices(v);
}

Square::Square(std::string color, Point2D* vertices)
    : Rectangle(color, vertices)  // primero crea como rectángulo válido
{
    if (!check(vertices)) {
        throw std::invalid_argument("Vertices no forman un cuadrado valido");
    }
    // ya están copiados por Rectangle, no hace falta más
}

void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Vertices no forman un cuadrado valido");
    }
    Rectangle::set_vertices(vertices); // reutiliza validación/ copia del padre
}

void Square::print() {
    std::cout << *this; // reutiliza operator<<
}

std::ostream& operator<<(std::ostream &out, const Square &square) {
    out << "[Square: color = " << square.color
        << "; v0 = (" << square.vs[0].x << "," << square.vs[0].y << ")"
        << "; v1 = (" << square.vs[1].x << "," << square.vs[1].y << ")"
        << "; v2 = (" << square.vs[2].x << "," << square.vs[2].y << ")"
        << "; v3 = (" << square.vs[3].x << "," << square.vs[3].y << ")]";
    return out;
}

