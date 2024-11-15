#ifndef FICHA_H
#define FICHA_H

#include <iostream>
#include <string>
#include <memory>

#include "Casilla.h"

class Casilla;

class Ficha : public std::enable_shared_from_this<Ficha> {
private:
    std::string color;
    int posicion;
    bool enCasa;
    bool enMeta;
    std::shared_ptr<Casilla> casillaActual;

public:
    Ficha(const std::string& color)
        : color(color), posicion(0), enCasa(true), enMeta(false), casillaActual(nullptr) {}

    std::string getColor() const { return color; }
    int getPosicion() const { return posicion; }
    bool estaEnCasa() const { return enCasa; }
    bool estaEnMeta() const { return enMeta; }

    void mover(int pasos) {
        if (enCasa) {
            std::cout << "La ficha " << color << " está en casa y no puede moverse aún." << std::endl;
            return;
        }

        if (enMeta) {
            std::cout << "La ficha " << color << " ya está en la meta y no puede moverse." << std::endl;
            return;
        }

        posicion += pasos;
        std::cout << "La ficha " << color << " se mueve " << pasos << " pasos y ahora está en la posición " << posicion << "." << std::endl;
        
        if (casillaActual) {
            //casillaActual->removerFicha(shared_from_this());
        }
        
        if (casillaActual) {
            //casillaActual->agregarFicha(shared_from_this());
        }
    }

    void regresarACasa() {
        if (enCasa) {
            std::cout << "La ficha " << color << " ya está en casa." << std::endl;
            return;
        }
        
        posicion = 0;
        enCasa = true;
        enMeta = false;
        casillaActual.reset();
        std::cout << "La ficha " << color << " ha regresado a casa." << std::endl;
    }

    void entrarEnMeta() {
        if (enMeta) {
            std::cout << "La ficha " << color << " ya está en la meta." << std::endl;
            return;
        }

        enMeta = true;
        posicion = 100;
        std::cout << "La ficha " << color << " ha entrado en la meta." << std::endl;
    }

    void establecerCasillaActual(std::shared_ptr<Casilla> casilla) {
        casillaActual = casilla;
    }

    std::shared_ptr<Casilla> obtenerCasillaActual() const {
        return casillaActual;
    }
};

#endif // FICHA_H
