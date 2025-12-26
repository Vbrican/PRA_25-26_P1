#include "Rectangle.h"
#include <cmath>

static const double EPS = 1e-9;

bool Rectangle::check(Point2D* vertices) {
    if (vertices == nullptr) return false;

    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);

    return (std::fabs(d01 - d23) < EPS) && (std::fabs(d12 - d30) < EPS);
}

Rectangle::Rectangle() : Shape(), vs(new Point2D[N_VERTICES]) {
    vs[0] = Point2D(-1,  0.5);
    vs[1] = Point2D( 1,  0.5);
    vs[2] = Point2D( 1, -0.5);
    vs[3] = Point2D(-1, -0.5);
}

Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color), vs(nullptr) {
    if (!check(vertices)) {
        throw std::invalid_argument("Vertices no forman un rectangulo valido");
    }
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; ++i) vs[i] = vertices[i];
}

Rectangle::Rectangle(const Rectangle &r) : Shape(r.color), vs(new Point2D[N_VERTICES]) {
    for (int i = 0; i < N_VERTICES; ++i) vs[i] = r.vs[i];
}

Rectangle::~Rectangle() {
    delete[] vs;
    vs = nullptr;
}

Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("Indice de vertice fuera de rango");
    }
    return vs[ind];
}

Point2D Rectangle::operator[](int ind) const {
    return get_vertex(ind);
}

void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Vertices no forman un rectangulo valido");
    }
    for (int i = 0; i < N_VERTICES; ++i) vs[i] = vertices[i];
}

Rectangle& Rectangle::operator=(const Rectangle &r) {
    if (this == &r) return *this;

    // Copiamos color (protected en Shape)
    color = r.color;

    // Copia profunda de vértices
    if (vs == nullptr) vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; ++i) vs[i] = r.vs[i];

    return *this;
}

double Rectangle::area() const {
    double a = Point2D::distance(vs[0], vs[1]);
    double b = Point2D::distance(vs[1], vs[2]);
    return a * b;
}

double Rectangle::perimeter() const {
    double a = Point2D::distance(vs[0], vs[1]);
    double b = Point2D::distance(vs[1], vs[2]);
    return 2 * (a + b);
}

void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

void Rectangle::print() {
    std::cout << *this; // Reutilizamos operator<< (sin duplicar código)
}

std::ostream& operator<<(std::ostream &out, const Rectangle &r) {
    out << "[Rectangle: color = " << r.color
        << "; v0 = (" << r.vs[0].x << "," << r.vs[0].y << ")"
        << "; v1 = (" << r.vs[1].x << "," << r.vs[1].y << ")"
        << "; v2 = (" << r.vs[2].x << "," << r.vs[2].y << ")"
        << "; v3 = (" << r.vs[3].x << "," << r.vs[3].y << ")]";
    return out;
}

