#ifndef COLA_H
#define COLA_H

#include <list>
#include <stdexcept>

using namespace std;

template <typename T>
class Cola {
private:
    list<T> elementos;

public:
    Cola() {}

    void añadirFinal(const T& elemento) {
        elementos.push_back(elemento);
    }

    T extraerInicio() {
        if (estaVacia()) {
            throw out_of_range("La cola está vacía");
        }
        T elemento = elementos.front();
        elementos.pop_front();
        return elemento;
    }

    T retornarInicio() const {
        if (estaVacia()) {
            throw out_of_range("La cola está vacía");
        }
        return elementos.front();
    }

    bool estaVacia() const {
        return elementos.empty();
    }

    int tamano() const {
        return elementos.size();
    }
};
#endif