#include <iostream>
#include <vector>
#include "Equipo.h"

using namespace std;

void mostrar_equipos_original(const vector<Equipo>& equipos) {
    cout << "\nEquipos tal como se ingresaron:\n";
    for (size_t i = 0; i < equipos.size(); ++i) {
        const Equipo& equipo = equipos[i];
        cout << "Equipo: " << equipo.get_nombre_equipo()
             << ", Jugador: " << equipo.get_nombre_jugador()
             << ", Puntaje: " << equipo.get_puntaje() << endl;
    }
}

void mostrar_equipos_ordenados(vector<Equipo>& equipos) {
    quick_sort(equipos, 0, equipos.size() - 1);

    cout << "\nEquipos ordenados por puntaje (de mayor a menor):\n";
    for (int i = equipos.size() - 1; i >= 0; --i) {
        const Equipo& equipo = equipos[i];
        cout << "Equipo: " << equipo.get_nombre_equipo()
             << ", Jugador: " << equipo.get_nombre_jugador()
             << ", Puntaje: " << equipo.get_puntaje() << endl;
    }
}

int main() {
    vector<Equipo> equipos;

    std::string archivo_csv = "C:\\Users\\e_spe\\OneDrive\\Escritorio\\Proyecto fornite\\equipos_informacion.csv"; //Cambiar ruta del archivo 

    cargar_equipos_desde_csv(archivo_csv, equipos);

    Arbol arbol;

    int opcion;
    do {
        cout << "\nMenu:\n";
        cout << "1. Imprimir equipos (sin ordenar)\n";
        cout << "2. Imprimir equipos ordenados por puntaje\n";
        cout << "3. Insertar equipos en el árbol y mostrar\n";
        cout << "4. Buscar equipo por puntaje\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrar_equipos_original(equipos);
                break;
            case 2:
                mostrar_equipos_ordenados(equipos);
                break;
            case 3:
                quick_sort(equipos, 0, equipos.size() - 1);
                for (int i = equipos.size() - 1; i >= 0; --i) {
                    arbol.agregar_equipo(equipos[i]);  
                }
                
                break;
            case 4: {
                quick_sort(equipos, 0, equipos.size() - 1);
                int puntaje_buscado;
                cout << "Ingrese el puntaje a buscar: ";
                cin >> puntaje_buscado;
                string jugador_encontrado = busqueda_binaria(equipos, puntaje_buscado);
                cout << "Resultado: " << jugador_encontrado << endl;
                break;
            }
            case 5:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción no válida. Intente nuevamente.\n";
                break;
        }
    } while (opcion != 5);

    return 0;
}
