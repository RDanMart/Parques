#ifndef JUEGO_H
#define JUEGO_H

#include "Tablero.h"
#include "Cola.h"
#include "Jugador.h"
#include "Dado.h"
#include <iostream>
#include <memory>
#include <stdexcept>  // Para manejar excepciones

using namespace std;

// Clase Juego
class Juego {
private:
    shared_ptr<Tablero> tablero;         // Relación de 1 a 1 con Tablero
    Cola<shared_ptr<Jugador>> jugadores; // Relación de 1 a 2-4 con Jugador, usando Cola
    shared_ptr<Jugador> jugadorActual;   // Jugador cuyo turno es el actual
    Dado dado;                                // Relación con Dado

public:
    // Constructor
    Juego(shared_ptr<Tablero> tablero) : tablero(tablero), jugadorActual(nullptr) {}

    // Método para iniciar el juego
    void iniciarJuego() {
        // Asegurarnos de que haya entre 2 y 4 jugadores
        if (jugadores.tamano() < 2 || jugadores.tamano() > 4) {
            throw invalid_argument("Debe haber entre 2 y 4 jugadores.");
        }
        
        // Asignar el primer jugador
        jugadorActual = jugadores.retornarInicio();
        cout << "¡El juego ha comenzado! El jugador " << jugadorActual->getColor() << " empieza." << endl;
    }

    // Método para agregar un jugador al juego
    void agregarJugador(shared_ptr<Jugador> jugador) {
        if (jugadores.tamano() < 4) {
            jugadores.añadirFinal(jugador);
            cout << "Jugador " << jugador->getColor() << " ha sido agregado al juego." << endl;
        } else {
            cout << "No se pueden agregar más de 4 jugadores." << endl;
        }
    }

    // Método para cambiar al siguiente jugador
    void cambiarTurno() {
        if (jugadorActual != nullptr) {
            // Mueve el jugador actual al final de la cola y toma el siguiente
            jugadores.añadirFinal(jugadores.extraerInicio());
            jugadorActual = jugadores.retornarInicio();
            cout << "Es el turno del jugador " << jugadorActual->getColor() << "." << endl;
        }
    }

    // Método para verificar si hay un ganador
    bool verificarGanador() {
        for (int i = 0; i < jugadores.tamano(); ++i) {
            auto jugador = jugadores.retornarInicio();
            jugadores.añadirFinal(jugadores.extraerInicio()); // Mantiene el orden de la cola

            bool todasEnMeta = true;
            for (const auto& ficha : jugador->getFichas()) {
                if (!ficha->estaEnMeta()) {
                    todasEnMeta = false;
                    break;
                }
            }
            if (todasEnMeta) {
                cout << "¡El jugador " << jugador->getColor() << " ha ganado!" << endl;
                return true;
            }
        }
        return false;  // No hay ganador aún
    }

    // Método para lanzar el dado y mover la ficha
    void jugarTurno() {
        if (jugadorActual == nullptr) {
            cout << "El juego no ha comenzado. No hay jugador actual." << endl;
            return;
        }

        cout << "Turno del jugador " << jugadorActual->getColor() << ":" << endl;
        int pasos = dado.lanzar();  // Lanza el dado
        cout << "El dado ha sacado un " << pasos << "." << endl;

        // Pedir al jugador que mueva una de sus fichas
        if (!jugadorActual->getFichas().empty()) {
            jugadorActual->moverFicha(jugadorActual->getFichas()[0], pasos);
        }

        // Verificar si hay un ganador
        if (verificarGanador()) {
            cout << "El juego ha terminado." << endl;
        } else {
            // Cambiar de turno
            cambiarTurno();
        }
    }
};

#endif // JUEGO_H
