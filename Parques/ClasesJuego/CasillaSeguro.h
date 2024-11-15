#ifndef CASILLASEGURO_H
#define CASILLASEGURO_H

#include <iostream>
#include <memory>  // Para usar shared_ptr

#include "Casilla.h"
#include "Ficha.h"

class CasillaSeguro : public Casilla {
public:
    // Constructor que llama al constructor base de Casilla
    CasillaSeguro(int posicion) : Casilla(posicion) {}

    // Implementación del método aplicarEfecto (no tiene ningún efecto en la ficha)
    void aplicarEfecto(std::shared_ptr<Ficha> ficha) override {
        std::cout << "Casilla segura. La ficha " << ficha->getColor() << " no recibe efectos." << std::endl;
    }
};

#endif