#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>
#include <iostream>
#include <vector>

class Equipo {
private:
    std::string nombre_jugador;
    std::string nombre_equipo;
    int edad;
    std::string region;
    int puntaje;

public:
    // Constructor por defecto
    Equipo() {}

    // Constructor con parámetros
    Equipo(const std::string& nom_j, const std::string& nom_e, int ed, const std::string& reg, int punt)
        : nombre_jugador(nom_j), nombre_equipo(nom_e), edad(ed), region(reg), puntaje(punt) {}

    // Getters
    std::string get_nombre_jugador() const { return nombre_jugador; }
    std::string get_nombre_equipo() const { return nombre_equipo; }
    int get_edad() const { return edad; }
    std::string get_region() const { return region; }
    int get_puntaje() const { return puntaje; }
};

// Función para mostrar los equipos
void mostrar_equipos(const std::vector<Equipo>& equipos) {
    for (size_t i = 0; i < equipos.size(); ++i) {
        std::cout << "Equipo: " << equipos[i].get_nombre_equipo() << std::endl;
        std::cout << "Participante: " << equipos[i].get_nombre_jugador() << std::endl;
        std::cout << "Edad: " << equipos[i].get_edad() << std::endl;
        std::cout << "Región: " << equipos[i].get_region() << std::endl;
        std::cout << "Puntaje: " << equipos[i].get_puntaje() << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;
    }
}

// Función auxiliar para realizar el intercambio
void intercambiar(Equipo& a, Equipo& b) {
    Equipo temp = a;
    a = b;
    b = temp;
}

// Función para dividir el array y encontrar el pivote
int particion(std::vector<Equipo>& equipos, int bajo, int alto) {
    int pivote = equipos[alto].get_puntaje(); // Seleccionamos el último elemento como pivote
    int i = bajo - 1; // Índice del elemento más pequeño

    for (int j = bajo; j < alto; ++j) {
        // Si el puntaje del equipo actual es mayor que el del pivote (orden descendente)
        if (equipos[j].get_puntaje() > pivote) {
            i++; // Incrementamos el índice
            intercambiar(equipos[i], equipos[j]); // Intercambiamos los elementos
        }
    }
    intercambiar(equipos[i + 1], equipos[alto]); // Colocamos el pivote en su lugar correcto
    return i + 1;
}

// Función recursiva de Quick Sort
void quick_sort(std::vector<Equipo>& equipos, int bajo, int alto) {
    if (bajo < alto) {
        // Obtenemos el índice del pivote
        int indice_pivote = particion(equipos, bajo, alto);

        // Ordenamos los elementos antes y después del pivote
        quick_sort(equipos, bajo, indice_pivote - 1);
        quick_sort(equipos, indice_pivote + 1, alto);
    }
}

// Función principal para ordenar los equipos
void ordenar_equipos(std::vector<Equipo>& equipos) {
    quick_sort(equipos, 0, equipos.size() - 1);
}

// Función de búsqueda binaria 
void busqueda_binaria_puntaje(const std::vector<Equipo>& equipos, int puntaje_buscado) {
    int low = 0;
    int high = equipos.size() - 1;
    int mid;

    while (low <= high) {
        mid = (high + low) / 2;

        if (equipos[mid].get_puntaje() == puntaje_buscado) {
            std::cout << "Jugador encontrado: " << equipos[mid].get_nombre_jugador() << std::endl;
            return;
        }

        if (equipos[mid].get_puntaje() > puntaje_buscado) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    std::cout << "Equipo no encontrado." << std::endl;
}

#endif // EQUIPO_H
