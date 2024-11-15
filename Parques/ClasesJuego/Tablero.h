#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include <memory>

#include "Casilla.h"
#include "CasillaLlegada.h"
#include "CasillaNormal.h"
#include "CasillaSalida.h"
#include "CasillaSeguro.h"
#include "ListaCircularDoble.h"
using namespace std;


class Tablero {
public:
	ListaCircularDoble<Casilla*> listacasillas; //Lista circular para las casillas
	

public:
    // Constructor
    Tablero() {}

    // Método para inicializar el tablero con casillas (esto es solo un ejemplo de inicialización)
    void inicializarTablero() {
    	//Zona del color rojo
        listacasillas.insertarNodo(new CasillaSalida(0, "rojo"));
        listacasillas.insertarNodo(new CasillaNormal(1));
        listacasillas.insertarNodo(new CasillaNormal(2));
        listacasillas.insertarNodo(new CasillaNormal(3));
        listacasillas.insertarNodo(new CasillaNormal(4));
        listacasillas.insertarNodo(new CasillaNormal(5));
        listacasillas.insertarNodo(new CasillaNormal(6));
        listacasillas.insertarNodo(new CasillaSeguro(7));
        listacasillas.insertarNodo(new CasillaNormal(8));
        listacasillas.insertarNodo(new CasillaNormal(9));
        listacasillas.insertarNodo(new CasillaNormal(10));
        listacasillas.insertarNodo(new CasillaNormal(11));
        listacasillas.insertarNodo(new CasillaLlegada(12, "azul")); //Casilla que marca la llegada de la ficha azul
        listacasillas.insertarNodo(new CasillaNormal(13));
        listacasillas.insertarNodo(new CasillaNormal(14));
        listacasillas.insertarNodo(new CasillaNormal(15));
        listacasillas.insertarNodo(new CasillaNormal(16));
        //Zona del color azul
        listacasillas.insertarNodo(new CasillaSalida(17,"azul"));
        listacasillas.insertarNodo(new CasillaNormal(18));
        listacasillas.insertarNodo(new CasillaNormal(19));
        listacasillas.insertarNodo(new CasillaNormal(20));
        listacasillas.insertarNodo(new CasillaNormal(21));
        listacasillas.insertarNodo(new CasillaNormal(22));
        listacasillas.insertarNodo(new CasillaNormal(23));
        listacasillas.insertarNodo(new CasillaSeguro(24));
        listacasillas.insertarNodo(new CasillaNormal(25));
        listacasillas.insertarNodo(new CasillaNormal(26));
        listacasillas.insertarNodo(new CasillaNormal(27));
        listacasillas.insertarNodo(new CasillaNormal(28));
        listacasillas.insertarNodo(new CasillaLlegada(29,"verde")); //Casilla que marca la llegada de la ficha verde
        listacasillas.insertarNodo(new CasillaNormal(30));
        listacasillas.insertarNodo(new CasillaNormal(31));
        listacasillas.insertarNodo(new CasillaNormal(32));
        listacasillas.insertarNodo(new CasillaNormal(33));
        //Zona del color verde
		listacasillas.insertarNodo(new CasillaSalida(34,"verde"));
		listacasillas.insertarNodo(new CasillaNormal(35));
        listacasillas.insertarNodo(new CasillaNormal(36));
        listacasillas.insertarNodo(new CasillaNormal(37));
        listacasillas.insertarNodo(new CasillaNormal(38));
        listacasillas.insertarNodo(new CasillaNormal(39));
        listacasillas.insertarNodo(new CasillaNormal(40));
        listacasillas.insertarNodo(new CasillaSeguro(41));
        listacasillas.insertarNodo(new CasillaNormal(42));
        listacasillas.insertarNodo(new CasillaNormal(43));
        listacasillas.insertarNodo(new CasillaNormal(44));
        listacasillas.insertarNodo(new CasillaNormal(45));
        listacasillas.insertarNodo(new CasillaLlegada(46,"amarillo")); //Casilla que marca la llegada de la ficha amarilla
        listacasillas.insertarNodo(new CasillaNormal(47));
        listacasillas.insertarNodo(new CasillaNormal(48));
        listacasillas.insertarNodo(new CasillaNormal(49));
        listacasillas.insertarNodo(new CasillaNormal(50));
		//Zona del color amarillo
		listacasillas.insertarNodo(new CasillaSalida(51,"amarillo"));
		listacasillas.insertarNodo(new CasillaNormal(52));
        listacasillas.insertarNodo(new CasillaNormal(53));
        listacasillas.insertarNodo(new CasillaNormal(54));
        listacasillas.insertarNodo(new CasillaNormal(55));
        listacasillas.insertarNodo(new CasillaNormal(56));
        listacasillas.insertarNodo(new CasillaNormal(57));
        listacasillas.insertarNodo(new CasillaSeguro(58));
        listacasillas.insertarNodo(new CasillaNormal(59));
        listacasillas.insertarNodo(new CasillaNormal(60));
        listacasillas.insertarNodo(new CasillaNormal(61));
        listacasillas.insertarNodo(new CasillaNormal(62));
        listacasillas.insertarNodo(new CasillaLlegada(63,"rojo")); //Casilla que marca la llegada de la ficha roja
        listacasillas.insertarNodo(new CasillaNormal(64));
        listacasillas.insertarNodo(new CasillaNormal(65));
        listacasillas.insertarNodo(new CasillaNormal(66));
        listacasillas.insertarNodo(new CasillaNormal(67));    
  }
        
   // Método para obtener una casilla por su posición
    shared_ptr<Casilla> obtenerCasilla(int posicion) {
        if (listacasillas.esVacia()) {
            cout << "El tablero está vacío." << endl;
            return nullptr;
        }

        NodoDoble<Casilla*>* temp = listacasillas.getCabeza();  // Apuntador al primer nodo de la lista
        int contador = 0;

        // Recorrer la lista circular buscando la casilla en la posición deseada
        do {
            if (contador == posicion) {
                return shared_ptr<Casilla>(temp->contenido); // Devuelve la casilla encontrada
            }
            temp = temp->siguiente;  // Mover al siguiente nodo
            contador++;
        } while (temp != listacasillas.getCabeza());  // Continúa hasta recorrer toda la lista circular

        cout << "Posición fuera de rango en el tablero." << endl;
        return nullptr;
    }
};

#endif
