#ifndef EQUIPO_H
#define EQUIPO_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

// Clase que representa un equipo con atributos de jugador, equipo y puntaje.
class Equipo {
private:
    std::string nombre_jugador;
    std::string nombre_equipo;
    int edad_jugador;
    std::string nacionalidad;
    int puntaje;

public:
    // Constructor que inicializa todos los atributos de un equipo.
    Equipo(const std::string& nombre_jugador, const std::string& nombre_equipo, int edad_jugador,
           const std::string& nacionalidad, int puntaje)
        : nombre_jugador(nombre_jugador), nombre_equipo(nombre_equipo),
          edad_jugador(edad_jugador), nacionalidad(nacionalidad), puntaje(puntaje) {}

    // Getters
    std::string get_nombre_jugador() const { return nombre_jugador; }
    std::string get_nombre_equipo() const { return nombre_equipo; }
    int get_edad_jugador() const { return edad_jugador; }
    std::string get_nacionalidad() const { return nacionalidad; }
    int get_puntaje() const { return puntaje; }
};

// Clase Nodo que representa cada nodo en el árbol binario, conteniendo un equipo y punteros a los nodos hijos.
class Nodo {
public:
    Equipo equipo;
    Nodo* izquierda;
    Nodo* derecha;

    // Constructor del Nodo que inicializa el equipo y los hijos como NULL.
    Nodo(const Equipo& eq) : equipo(eq), izquierda(NULL), derecha(NULL) {}
};

// Clase Arbol que representa un Árbol Binario de Búsqueda (ABB) de equipos.
class Arbol {
private:
    Nodo* raiz;

public:
    // Constructor que inicializa el árbol vacío con la raíz en NULL.
    Arbol() : raiz(NULL) {}

    // Inserta un equipo en el ABB de forma recursiva.
    // Devuelve el nodo raíz actualizado.
    Nodo* insertar_nodo(Nodo* nodo, const Equipo& equipo) {
        if (nodo == NULL) {
            return new Nodo(equipo);
        }

        // Inserta en el subárbol izquierdo si el puntaje es menor, derecho si es mayor.
        if (equipo.get_puntaje() < nodo->equipo.get_puntaje()) {
            nodo->izquierda = insertar_nodo(nodo->izquierda, equipo);
        } else if (equipo.get_puntaje() > nodo->equipo.get_puntaje()) {
            nodo->derecha = insertar_nodo(nodo->derecha, equipo);
        } else {
            std::cout << "Ya existe un equipo con el puntaje " << equipo.get_puntaje() << std::endl;
        }
        return nodo;
    }

    // Agrega un equipo al árbol llamando a la función insertar_nodo.
    void agregar_equipo(const Equipo& equipo) {
        raiz = insertar_nodo(raiz, equipo);
        std::cout << "Equipo insertado: " << equipo.get_nombre_equipo()
                  << ", Jugador: " << equipo.get_nombre_jugador()
                  << ", Puntaje: " << equipo.get_puntaje() << std::endl;
    }

    // Función recursiva para imprimir el árbol en orden (in-order).
    void imprimir_in_order(Nodo* nodo) const {
        if (nodo != NULL) {
            imprimir_in_order(nodo->izquierda);
            std::cout << "Equipo: " << nodo->equipo.get_nombre_equipo()
                      << ", Jugador: " << nodo->equipo.get_nombre_jugador()
                      << ", Puntaje: " << nodo->equipo.get_puntaje() << std::endl;
            imprimir_in_order(nodo->derecha);
        }
    }

    // Función pública para imprimir el árbol comenzando desde la raíz.
    void imprimir() const {
        imprimir_in_order(raiz);
    }

    // Guarda la estructura del árbol en un archivo de texto.
    void guardar_en_archivo() const {
        std::ofstream archivo("estructura_arbol.txt");
        if (archivo.is_open()) {
            guardar_in_order(raiz, archivo);
            archivo.close();
            std::cout << "El árbol ha sido guardado en 'estructura_arbol.txt'.\n";
        } else {
            std::cerr << "No se pudo abrir el archivo para guardar.\n";
        }
    }

    // Función auxiliar recursiva para guardar el árbol en orden en el archivo.
    void guardar_in_order(Nodo* nodo, std::ofstream& archivo) const {
        if (nodo != NULL) {
            guardar_in_order(nodo->izquierda, archivo);
            archivo << "Equipo: " << nodo->equipo.get_nombre_equipo()
                    << ", Jugador: " << nodo->equipo.get_nombre_jugador()
                    << ", Puntaje: " << nodo->equipo.get_puntaje() << "\n";
            guardar_in_order(nodo->derecha, archivo);
        }
    }

    // Encuentra y devuelve el equipo con el puntaje más alto en el árbol.
    Equipo equipo_max_puntaje() const {
        Nodo* actual = raiz;
        while (actual != NULL && actual->derecha != NULL) {
            actual = actual->derecha;
        }

        if (actual != NULL) {
            return actual->equipo;
        } else {
            return Equipo("", "", 0, "", 0);  // Devuelve un equipo vacío si el árbol está vacío.
        }
    }

    // Encuentra y devuelve el equipo con el puntaje más bajo en el árbol.
    Equipo equipo_min_puntaje() const {
        Nodo* actual = raiz;
        while (actual != NULL && actual->izquierda != NULL) {
            actual = actual->izquierda;
        }

        if (actual != NULL) {
            return actual->equipo;
        } else {
            return Equipo("", "", 0, "", 0);  // Devuelve un equipo vacío si el árbol está vacío.
        }
    }

    // Calcula y devuelve el promedio de puntajes de todos los equipos en el ABB.
    double promedio_puntajes() const {
        int suma = 0;
        int contador = 0;
        calcular_promedio(raiz, suma, contador);

        if (contador != 0) {
            return static_cast<double>(suma) / contador;
        } else {
            return 0;
        }
    }

    // Función auxiliar recursiva para calcular el promedio de puntajes en el ABB.
    void calcular_promedio(Nodo* nodo, int& suma, int& contador) const {
        if (nodo != NULL) {
            suma += nodo->equipo.get_puntaje();
            contador++;
            calcular_promedio(nodo->izquierda, suma, contador);
            calcular_promedio(nodo->derecha, suma, contador);
        }
    }

    // Cuenta y muestra los equipos en un rango de puntaje específico.
    int contar_y_mostrar_por_rango(int min_puntaje, int max_puntaje) const {
        int count = contar_y_mostrar_rango(raiz, min_puntaje, max_puntaje);
        std::cout << "\nTotal de equipos en el rango de " << min_puntaje << " a " << max_puntaje << ": " << count << std::endl;
        return count;
    }

    // Función auxiliar para contar y mostrar nodos dentro de un rango de puntaje.
    int contar_y_mostrar_rango(Nodo* nodo, int min_puntaje, int max_puntaje) const {
        if (nodo == NULL) return 0;

        int count = 0;
        // Verifica si el equipo está en el rango y lo muestra si es así.
        if (nodo->equipo.get_puntaje() >= min_puntaje && nodo->equipo.get_puntaje() <= max_puntaje) {
            std::cout << "Equipo: " << nodo->equipo.get_nombre_equipo()
                      << ", Jugador: " << nodo->equipo.get_nombre_jugador()
                      << ", Puntaje: " << nodo->equipo.get_puntaje() << std::endl;
            count = 1;
        }
        

        // Cuenta recursivamente en los subárboles izquierdo y derecho.
        return count + contar_y_mostrar_rango(nodo->izquierda, min_puntaje, max_puntaje) +
               contar_y_mostrar_rango(nodo->derecha, min_puntaje, max_puntaje);
    }
};

// Función para cargar equipos desde un archivo CSV y agregarlos al ABB.
void cargar_equipos_desde_csv(const std::string& archivo_csv, Arbol& arbol) {
    std::ifstream archivo(archivo_csv.c_str());
    std::string linea;

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo: " << archivo_csv << std::endl;
        return;
    }

    // Lee cada línea del archivo, crea un equipo y lo agrega al ABB.
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string nombre_jugador, nombre_equipo, nacionalidad;
        int edad_jugador, puntaje;

        std::getline(ss, nombre_jugador, ',');
        std::getline(ss, nombre_equipo, ',');
        ss >> edad_jugador; ss.ignore();
        std::getline(ss, nacionalidad, ',');
        ss >> puntaje;

        arbol.agregar_equipo(Equipo(nombre_jugador, nombre_equipo, edad_jugador, nacionalidad, puntaje));
    }

    archivo.close();
}

#endif
