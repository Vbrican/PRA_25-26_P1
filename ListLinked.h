#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

private:
    Node<T>* first;
    int n;

public:
    ListLinked() {
        first = nullptr;
        n = 0;
    }

    ~ListLinked() {
        while (first != nullptr) {
            Node<T>* aux = first->next;
            delete first;
            first = aux;
        }
        n = 0;
    }

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición inválida!");
        }

        if (pos == 0) {
            first = new Node<T>(e, first);
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; ++i) {
                prev = prev->next;
            }
            prev->next = new Node<T>(e, prev->next);
        }
        n++;
    }

    void append(T e) override {
        insert(n, e);
    }

    void prepend(T e) override {
        insert(0, e);
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida!");
        }

        Node<T>* to_delete;
        T value;

        if (pos == 0) {
            to_delete = first;
            first = first->next;
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; ++i) {
                prev = prev->next;
            }
            to_delete = prev->next;
            prev->next = to_delete->next;
        }

        value = to_delete->data;
        delete to_delete;
        n--;
        return value;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida!");
        }

        Node<T>* cur = first;
        for (int i = 0; i < pos; ++i) {
            cur = cur->next;
        }
        return cur->data;
    }

    int search(T e) override {
        Node<T>* cur = first;
        int i = 0;
        while (cur != nullptr) {
            if (cur->data == e) return i;
            cur = cur->next;
            i++;
        }
        return -1;
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }

    T operator[](int pos) {
        return get(pos);
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream &out, const ListLinked<U> &list);
};

template <typename U>
std::ostream& operator<<(std::ostream &out, const ListLinked<U> &list) {
    if (list.n == 0) {
        out << "[]";
        return out;
    }

    out << "[\n";
    Node<U>* cur = list.first;
    while (cur != nullptr) {
        out << "  " << cur->data << "\n";
        cur = cur->next;
    }
    out << "]";
    return out;
}

#endif

