#ifndef LISTACIRCULARDOBLE_H
#define LISTACIRCULARDOBLE_H

#include <iostream>
using namespace std;

template <typename T>
class NodoDoble {
public:
    T contenido;
    NodoDoble* siguiente;
    NodoDoble* anterior;

    NodoDoble(T contenido) : contenido(contenido), siguiente(nullptr), anterior(nullptr) {}
};

template <typename T>
class ListaCircularDoble {
private:
    NodoDoble<T>* cabeza = nullptr;

public:
    ListaCircularDoble() {}

    NodoDoble<T>* getCabeza() {
        return cabeza;
    }

    bool esVacia() const {
        return cabeza == nullptr;
    }

    void insertarNodo(T contenido) {
        NodoDoble<T>* nuevo = new NodoDoble<T>(contenido);
        if (esVacia()) {
            cabeza = nuevo;
            cabeza->siguiente = cabeza;
            cabeza->anterior = cabeza;
        } else {
            NodoDoble<T>* ultimo = cabeza->anterior;
            ultimo->siguiente = nuevo;
            nuevo->anterior = ultimo;
            nuevo->siguiente = cabeza;
            cabeza->anterior = nuevo;
        }
    }

    void imprimirLista() const {
        if (esVacia()) {
            cout << "La lista está vacía" << endl;
        } else {
            NodoDoble<T>* temp = cabeza;
            do {
                cout << temp->contenido << " <-> ";
                temp = temp->siguiente;
            } while (temp != cabeza);
            cout << "(Ciclo cerrado)" << endl;
        }
    }

    int eliminarNodo(T dato) {
        if (esVacia()) {
            cout << "Lista vacía, no es posible eliminar" << endl;
            return 0;
        }

        NodoDoble<T>* temp = cabeza;
        do {
            if (temp->contenido == dato) {
                if (temp->siguiente == cabeza && temp->anterior == cabeza) {
                    cabeza = nullptr;
                } else {
                    temp->anterior->siguiente = temp->siguiente;
                    temp->siguiente->anterior = temp->anterior;
                    if (temp == cabeza) {
                        cabeza = temp->siguiente;
                    }
                }
                delete temp;
                cout << "Nodo con dato " << dato << " eliminado" << endl;
                return 1;
            }
            temp = temp->siguiente;
        } while (temp != cabeza);

        cout << "El dato no se encontró en la lista" << endl;
        return 0;
    }

    int contarNodos() const {
        if (esVacia()) {
            cout << "La lista no contiene ningún elemento" << endl;
            return 0;
        }

        int contador = 0;
        NodoDoble<T>* temp = cabeza;
        do {
            contador++;
            temp = temp->siguiente;
        } while (temp != cabeza);

        cout << "La lista contiene " << contador << " nodos" << endl;
        return contador;
    }
};

#endif