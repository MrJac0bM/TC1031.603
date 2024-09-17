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
        std::cout << "-----------------------------------------------	" << std::endl;
    }
}

// Función para ordenar los equipos por puntaje de mayor a menor
void ordenar_equipos(std::vector<Equipo>& equipos) {
    int pos_max = 0;
    for (size_t i = 0; i < equipos.size(); ++i) {
        pos_max = i;
        for (size_t j = i + 1; j < equipos.size(); ++j) {
            if (equipos[j].get_puntaje() > equipos[pos_max].get_puntaje()) {
                pos_max = j;
            }
        }
        std::swap(equipos[i], equipos[pos_max]);
    }
}

// Función de búsqueda binaria para encontrar un equipo por su puntaje
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


