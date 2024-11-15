#ifndef CASILLA_H
#define CASILLA_H

#include <iostream>
#include <vector>
#include <memory>  // Para usar shared_ptr
#include <algorithm>  // Para usar std::find

#include "Ficha.h"

class Ficha;  // Declaración hacia adelante de Ficha

class Casilla : public std::enable_shared_from_this<Casilla> {
protected:
    int posicion;  // Atributo: posición de la casilla
    std::vector<std::shared_ptr<Ficha>> fichasEnCasilla;  // Atributo: lista de fichas en la casilla

public:
    // Constructor
    Casilla(int posicion) : posicion(posicion) {}

    // Getter para obtener la posición de la casilla
    int getPosicion() const {
        return posicion;
    }

    // Método para agregar una ficha a la casilla
    /*void agregarFicha(std::shared_ptr<Ficha> ficha) {
        fichasEnCasilla.push_back(ficha);
        if (auto ptr = shared_from_this()) {
            ficha->establecerCasillaActual(ptr);  // Establece la casilla actual de la ficha
        }
        std::cout << "Ficha agregada a la casilla " << posicion << "." << std::endl;
    }*/

    // Método para remover una ficha de la casilla
    void removerFicha(std::shared_ptr<Ficha> ficha) {
        auto it = std::find(fichasEnCasilla.begin(), fichasEnCasilla.end(), ficha);
        if (it != fichasEnCasilla.end()) {
            fichasEnCasilla.erase(it);
            std::cout << "Ficha removida de la casilla " << posicion << "." << std::endl;
        } else {
            std::cout << "La ficha no está en la casilla " << posicion << "." << std::endl;
        }
    }

    // Método abstracto para aplicar el efecto de la casilla sobre la ficha
    virtual void aplicarEfecto(std::shared_ptr<Ficha> ficha) = 0;

    virtual ~Casilla() = default;  // Asegura un destructor virtual en clases base
};

#endif  // CASILLA_H
