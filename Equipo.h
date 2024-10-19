#ifndef EQUIPO_H
#define EQUIPO_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

// Definición de la clase Equipo
class Equipo {
private:
    std::string nombre_jugador;
    std::string nombre_equipo;
    int edad_jugador;
    std::string nacionalidad;
    int puntaje;

public:
    // Constructor
    Equipo(std::string nombre_jugador, std::string nombre_equipo, int edad_jugador, 
           std::string nacionalidad, int puntaje)
        : nombre_jugador(nombre_jugador), nombre_equipo(nombre_equipo), 
          edad_jugador(edad_jugador), nacionalidad(nacionalidad), puntaje(puntaje) {}

    // Getters
    std::string get_nombre_jugador() const { return nombre_jugador; }
    std::string get_nombre_equipo() const { return nombre_equipo; }
    int get_edad_jugador() const { return edad_jugador; }
    std::string get_nacionalidad() const { return nacionalidad; }
    int get_puntaje() const { return puntaje; }
};

// Definición de la clase Nodo para el árbol binario
class Nodo {
public:
    Equipo equipo;
    Nodo* izquierda;
    Nodo* derecha;

    // Constructor del Nodo
    Nodo(const Equipo& eq) : equipo(eq), izquierda(NULL), derecha(NULL) {}
};

// Definición de la clase Arbol
class Arbol {
private:
    Nodo* raiz;
public:

	//Constructor 	
	Arbol() : raiz(NULL) {}
    // Función recursiva para insertar nodos
    Nodo* insertar_nodo(Nodo* nodo, const Equipo& equipo) {
        if (nodo == NULL) {
            return new Nodo(equipo);
        }
        if (equipo.get_puntaje() < nodo->equipo.get_puntaje()) {
            nodo->izquierda = insertar_nodo(nodo->izquierda, equipo);
        } else {
            nodo->derecha = insertar_nodo(nodo->derecha, equipo);
        }
        return nodo;
    }

    // Función recursiva para imprimir el árbol en orden
    void imprimir_in_order(Nodo* nodo) const {
        if (nodo != NULL) {
            imprimir_in_order(nodo->izquierda);
            std::cout << "Equipo: " << nodo->equipo.get_nombre_equipo()
                      << ", Jugador: " << nodo->equipo.get_nombre_jugador()
                      << ", Puntaje: " << nodo->equipo.get_puntaje() << std::endl;
            imprimir_in_order(nodo->derecha);
        }
    }
    
    // Agregar un equipo al árbol
    void agregar_equipo(const Equipo& equipo) {
        insertar_nodo(raiz, equipo);
    }

    // Imprimir el árbol en orden
    void imprimir() const {
        imprimir_in_order(raiz);
    }
};

// Función de partición para Quick Sort
int partition(std::vector<Equipo>& equipos, int low, int high) {
    int pivot = equipos[high].get_puntaje();  
    int i = low - 1;  

    for (int j = low; j < high; ++j) {
        if (equipos[j].get_puntaje() < pivot) {
            ++i;
            std::swap(equipos[i], equipos[j]);
        }
    }
    std::swap(equipos[i + 1], equipos[high]);
    return i + 1;
}

// Implementación de Quick Sort
void quick_sort(std::vector<Equipo>& equipos, int low, int high) {
    if (low < high) {
        int pi = partition(equipos, low, high);  // Índice de partición

        // Ordenar las sublistas
        quick_sort(equipos, low, pi - 1);
        quick_sort(equipos, pi + 1, high);
    }
}

// Función para realizar búsqueda binaria
std::string busqueda_binaria(const std::vector<Equipo>& equipos, int puntaje_buscado) {
    int inicio = 0;
    int fin = equipos.size() - 1;

    while (inicio <= fin) {
        int mitad = inicio + (fin - inicio) / 2;
        if (equipos[mitad].get_puntaje() == puntaje_buscado) {
            return equipos[mitad].get_nombre_jugador(); 
        } else if (equipos[mitad].get_puntaje() < puntaje_buscado) {
            inicio = mitad + 1;
        } else {
            fin = mitad - 1;
        }
    }
    return "Puntaje no encontrado"; 
}

void cargar_equipos_desde_csv(const std::string& archivo_csv, std::vector<Equipo>& equipos) {
    std::ifstream archivo(archivo_csv.c_str());
    std::string linea;

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo: " << archivo_csv << std::endl;
        return;
    }

    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string nombre_jugador, nombre_equipo, nacionalidad;
        int edad_jugador, puntaje;

        std::getline(ss, nombre_jugador, ',');
        std::getline(ss, nombre_equipo, ',');
        ss >> edad_jugador; ss.ignore(); 
        std::getline(ss, nacionalidad, ',');
        ss >> puntaje;

        equipos.push_back(Equipo(nombre_jugador, nombre_equipo, edad_jugador, nacionalidad, puntaje));
    }

    archivo.close();
}

#endif
