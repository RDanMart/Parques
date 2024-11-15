#include <iostream>
#include <memory>
#include "Juego.h"
#include "Tablero.h"
#include "Jugador.h"
#include "Ficha.h"

int main() {
    // Crear un tablero
    auto tablero = std::make_shared<Tablero>();
    
    // Crear el juego con el tablero
    Juego juego(tablero);

    // Crear jugadores y sus fichas
    auto jugador1 = std::make_shared<Jugador>("Rojo");
    auto jugador2 = std::make_shared<Jugador>("Verde");
    auto jugador3 = std::make_shared<Jugador>("Azul");

    // Agregar fichas a cada jugador
    jugador1->agregarFicha(std::make_shared<Ficha>("Rojo"));
    jugador1->agregarFicha(std::make_shared<Ficha>("Rojo"));
    
    jugador2->agregarFicha(std::make_shared<Ficha>("Verde"));
    jugador2->agregarFicha(std::make_shared<Ficha>("Verde"));

    jugador3->agregarFicha(std::make_shared<Ficha>("Azul"));
    jugador3->agregarFicha(std::make_shared<Ficha>("Azul"));

    // Agregar jugadores al juego
    juego.agregarJugador(jugador1);
    juego.agregarJugador(jugador2);
    juego.agregarJugador(jugador3);

    // Iniciar el juego
    try {
        juego.iniciarJuego();
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
        return 1;  // Terminar el programa si hay un error
    }

    // Simular algunos turnos
    for (int i = 0; i < 5; ++i) {
        std::cout << "\nTurno " << i + 1 << ":" << std::endl;
        juego.jugarTurno();
    }

    return 0;
}
