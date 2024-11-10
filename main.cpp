#include <iostream>
#include "Equipo.h"

using namespace std;

int main() {
    Arbol arbol;
    string archivo_csv = "equipos_informacion.csv";

    // Cargar los equipos directamente al ABB desde el archivo CSV
    cargar_equipos_desde_csv(archivo_csv, arbol);

    int opcion;
    do {
        cout << "\nMenu:\n";
        cout << "1. Mostrar equipos en el árbol (in-order)\n";
        cout << "2. Consultar equipo con puntaje más alto\n";
        cout << "3. Consultar equipo con puntaje más bajo\n";
        cout << "4. Calcular promedio de puntajes\n";
        cout << "5. Contar y mostrar equipos en un rango de puntaje\n";
        cout << "6. Guardar el árbol en un archivo\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (cin.fail()) {
            cout << "Entrada no válida. Intente nuevamente." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (opcion) {
            case 1:
                arbol.imprimir();
                break;
            case 2: {
                Equipo max_equipo = arbol.equipo_max_puntaje();
                cout << "Equipo con puntaje más alto: " << max_equipo.get_nombre_equipo()
                     << ", Puntaje: " << max_equipo.get_puntaje() << endl;
                break;
            }
            case 3: {
                Equipo min_equipo = arbol.equipo_min_puntaje();
                cout << "Equipo con puntaje más bajo: " << min_equipo.get_nombre_equipo()
                     << ", Puntaje: " << min_equipo.get_puntaje() << endl;
                break;
            }
            case 4: {
                double promedio = arbol.promedio_puntajes();
                cout << "Promedio de puntajes: " << promedio << endl;
                break;
            }
            case 5: {
                int min_puntaje, max_puntaje;
                cout << "Ingrese el puntaje mínimo: ";
                cin >> min_puntaje;
                cout << "Ingrese el puntaje máximo: ";
                cin >> max_puntaje;
                arbol.contar_y_mostrar_por_rango(min_puntaje, max_puntaje);
                break;
            }
            case 6:
                arbol.guardar_en_archivo();
                break;
            case 7:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción no válida. Intente nuevamente.\n";
                break;
        }
    } while (opcion != 7);

    return 0;
}
