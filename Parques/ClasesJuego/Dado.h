// Dado.h
#ifndef DADO_H
#define DADO_H

#include <cstdlib>
#include <ctime>

// Clase Dado
class Dado {
public:
    Dado() {
        // Inicializa la semilla para generar números aleatorios solo una vez
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
    }

    // Método para lanzar el dado y obtener un número entre 1 y 6
    int lanzar() const {
        return (std::rand() % 6) + 1;
    }
};

#endif // DADO_H
