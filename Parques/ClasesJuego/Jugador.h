// Jugador.h
#ifndef JUGADOR_H
#define JUGADOR_H

#include "Ficha.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>

// Clase Jugador
class Jugador {
private:
	std::string color;  // Color del jugador
	std::vector<std::shared_ptr<Ficha>> fichas;  // Lista de fichas del jugador
	int puntaje;  // Puntaje del jugador
	
public:
	// Constructor
	Jugador(const std::string& color)
		: color(color), puntaje(0) {}
	
	// Getter para obtener el color del jugador
	std::string getColor() const {
		return color;
	}
	
	// Getter para obtener el puntaje del jugador
	int getPuntaje() const {
		return puntaje;
	}

	// Getter para obtener las fichas del jugador
	std::vector<std::shared_ptr<Ficha>> getFichas() {
		return fichas;
	}
	
	// Método para agregar una ficha al jugador
	void agregarFicha(std::shared_ptr<Ficha> ficha) {
		if (fichas.size() < 4) {  // El jugador puede tener hasta 4 fichas
			fichas.push_back(ficha);
			std::cout << "Ficha " << ficha->getColor() << " agregada al jugador " << color << "." << std::endl;
		} else {
			std::cout << "El jugador " << color << " ya tiene 4 fichas." << std::endl;
		}
	}
	
	// Método para mover una ficha de un jugador
	void moverFicha(std::shared_ptr<Ficha> ficha, int pasos) {
		if (ficha->estaEnCasa()) {
			std::cout << "La ficha " << ficha->getColor() << " est� en casa y no puede moverse a�n." << std::endl;
		} else if (ficha->estaEnMeta()) {
			std::cout << "La ficha " << ficha->getColor() << " ya est� en la meta." << std::endl;
		} else {
			ficha->mover(pasos);  // Llamamos al m�todo de mover de la clase Ficha
			puntaje += pasos;  // Incrementamos el puntaje del jugador
		}
	}
	
	// Método para verificar si todas las fichas est�n en casa
	bool todasFichasEnCasa() const {
		for (const auto& ficha : fichas) {
			if (!ficha->estaEnCasa()) {
				return false;  // Si alguna ficha no est� en casa, retorna false
			}
		}
		return true;  // Si todas las fichas est�n en casa, retorna true
	}
	
	// Método para mostrar las fichas del jugador
	void mostrarFichas() const {
		std::cout << "Fichas del jugador " << color << ":" << std::endl;
		for (const auto& ficha : fichas) {
			std::cout << "  - " << ficha->getColor() << " (Posici�n: " << ficha->getPosicion() << ")" << std::endl;
		}
	}
};

#endif // JUGADOR_H
