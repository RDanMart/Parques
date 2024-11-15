#ifndef CASILLALLEGADA_H
#define CASILLALLEGADA_H

#include <iostream>
#include <string>
#include "Casilla.h"  // Asegúrate de incluir la clase Casilla base
#include "Ficha.h"

class CasillaLlegada : public Casilla {
private:
    std::string color;  // Color de la casilla de llegada

public:
    // Constructor
    CasillaLlegada(int posicion, const std::string& color)
        : Casilla(posicion), color(color) {}

    // Getter para obtener el color de la casilla
    std::string getColor() const {
        return color;
    }

    // Método que implementa el efecto de la casilla de llegada
    void aplicarEfecto(std::shared_ptr<Ficha> ficha) override {
        // Si la ficha llega a esta casilla, se considera que ha llegado a la meta
        std::cout << "La ficha " << ficha->getColor() << " ha llegado a la casilla de llegada de color " 
                  << color << "." << std::endl;
        
        // Aplicamos el efecto: la ficha ha llegado a la meta
        ficha->entrarEnMeta();
    }
};

#endif