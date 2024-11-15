#ifndef LISTAENLAZADASIMPLE_H
#define LISTAENLAZADASIMPLE_H

#include <iostream>
using namespace std;

template <typename T>
class NodoSimple {
public:
    T contenido;
    NodoSimple* siguiente;

    NodoSimple(T contenido) : contenido(contenido), siguiente(nullptr) {}
};

template <typename T>
class ListaEnlazadaSimple {
private:
    NodoSimple<T>* cabeza = nullptr;

public:
    ListaEnlazadaSimple() {}

    NodoSimple<T>* getCabeza() const {
        return cabeza;
    }

    bool esVacia() const {
        return cabeza == nullptr;
    }

    void insertarNodo(T contenido) {
        NodoSimple<T>* nuevo = new NodoSimple<T>(contenido);
        if (esVacia()) {
            cabeza = nuevo;
        } else {
            NodoSimple<T>* temp = cabeza;
            while (temp->siguiente != nullptr) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevo;
        }
    }

    void imprimirLista() const {
        NodoSimple<T>* temp = cabeza;
        while (temp != nullptr) {
            cout << temp->contenido << " -> ";
            temp = temp->siguiente;
        }
        cout << "null" << endl;
    }

    int eliminarNodo(T dato) {
        if (esVacia()) {
            cout << "Lista vacía, no es posible eliminar" << endl;
            return 0;
        } else if (cabeza->contenido == dato) {
            NodoSimple<T>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            cout << "Se ha eliminado el nodo con el dato ingresado en la cabeza" << endl;
            return 1;
        } else {
            NodoSimple<T>* temp = cabeza;
            while (temp->siguiente != nullptr) {
                if (temp->siguiente->contenido == dato) {
                    NodoSimple<T>* nodoEliminar = temp->siguiente;
                    temp->siguiente = temp->siguiente->siguiente;
                    delete nodoEliminar;
                    cout << "Se ha eliminado el nodo con el contenido ingresado" << endl;
                    return 1;
                }
                temp = temp->siguiente;
            }
            cout << "El dato no se encontró en la lista" << endl;
            return 0;
        }
    }

    int buscarNodo(T dato) const {
        if (esVacia()) {
            cout << "Lista vacía" << endl;
            return 0;
        } else if (cabeza->contenido == dato) {
            cout << "El nodo está en la lista y es el primero" << endl;
            return 1;
        } else {
            NodoSimple<T>* temp = cabeza;
            while (temp->siguiente != nullptr) {
                if (temp->siguiente->contenido == dato) {
                    cout << "Se ha encontrado el nodo en la lista" << endl;
                    return 1;
                }
                temp = temp->siguiente;
            }
            return 0;
        }
    }

    int contarNodos() const {
        int contador = 0;
        if (esVacia()) {
            cout << "La lista no contiene ningún elemento" << endl;
            return contador;
        }

        NodoSimple<T>* temp = cabeza;
        while (temp != nullptr) {
            contador++;
            temp = temp->siguiente;
        }

        cout << "La lista contiene " << contador << " nodos 'reales'" << endl;
        return contador;
    }
};

#endif