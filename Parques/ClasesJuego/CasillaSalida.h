#ifndef CASILLASALIDA_H
#define CASILLASALIDA_H

#include <iostream>
#include <memory>  // Para usar shared_ptr

#include "Casilla.h"
#include "Ficha.h"

class CasillaSalida : public Casilla {
private:
    std::string color;  // Atributo color de la casilla

public:
    // Constructor que inicializa la posición y el color de la casilla
    CasillaSalida(int posicion, const std::string& color) : Casilla(posicion), color(color) {}

    // Getter para obtener el color de la casilla
    std::string getColor() const {
        return color;
    }

    // Implementación del método aplicarEfecto
    void aplicarEfecto(std::shared_ptr<Ficha> ficha) override {
        std::cout << "¡La ficha " << ficha->getColor() << " ha llegado a la salida (" << color << ")!" << std::endl;
    }
};

#endif