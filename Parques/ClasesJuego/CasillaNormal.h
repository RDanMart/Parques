#ifndef CASILLANORMAL_H
#define CASILLANORMAL_H

#include <iostream>
#include <memory>  // Para usar shared_ptr

#include "Casilla.h"
#include "Ficha.h"

class CasillaNormal : public Casilla {
public:
    // Constructor que llama al constructor base de Casilla
    CasillaNormal(int posicion) : Casilla(posicion) {}

    // Implementación del método aplicarEfecto (efecto general, por ejemplo, solo un mensaje)
    void aplicarEfecto(std::shared_ptr<Ficha> ficha) override {
        std::cout << "La ficha " << ficha->getColor() << " ha caído en una casilla normal." << std::endl;
    }
};

#endif