#include <iostream>
#include <vector>
#include "Equipo.h"
using namespace std;

int main() {
    // Crear el vector de equipos
    std::vector<Equipo> equipos;
    
    // Agregar equipos al vector
    equipos.push_back(Equipo("MrSavage", "100 Thieves", 20, "Norway", 999));
    equipos.push_back(Equipo("Sphinx 7", "Elite", 20, "Lebanon", 318));
    equipos.push_back(Equipo("Kwanti", "EXD", 20, "United States of America", 312));
    equipos.push_back(Equipo("Bugha", "DIG", 21, "United States of America", 288));
    equipos.push_back(Equipo("Batman Bugha", "Null", 22, "United States of America", 387));
    equipos.push_back(Equipo("Boltz", "Null", 22, "United States of America", 313));
    equipos.push_back(Equipo("Jakpo", "Falcon", 18, "Poland", 330));
    equipos.push_back(Equipo("King", "Dragn", 18, "Brazil", 276));
    equipos.push_back(Equipo("Kami", "GG", 19, "Poland", 259));
    equipos.push_back(Equipo("Rise", "DT", 19, "Canada", 204));
    equipos.push_back(Equipo("Vadeal", "WAVE", 19, "Germany", 195));
    equipos.push_back(Equipo("Reet", "SG", 18, "United States of America", 294));
    equipos.push_back(Equipo("Krisp", "Null", 20, "Germany", 177));
    equipos.push_back(Equipo("Muz3x", "XSET", 21, "Australia", 174));
    equipos.push_back(Equipo("Parz", "Elite", 18, "United States of America", 276));
    equipos.push_back(Equipo("Th0masHD", "Heroic", 22, "Denmark", 481));
    equipos.push_back(Equipo("Khanada", "DIG", 19, "United States of America", 186));
    equipos.push_back(Equipo("Paper", "Elite", 21, "United States of America", 150));
    equipos.push_back(Equipo("Huty", "Null", 23, "United States of America", 135));
    equipos.push_back(Equipo("Resignz", "Null", 20, "Australia", 123));
    equipos.push_back(Equipo("G13ras", "G1", 18, "Poland", 123));
    equipos.push_back(Equipo("Visxals", "Null", 17, "United States of America", 105));
    equipos.push_back(Equipo("CZB", "Null", 22, "Denmark", 99));
    equipos.push_back(Equipo("Clone", "KPI", 20, "Spain", 96));
    equipos.push_back(Equipo("Clix", "XSET", 19, "United States of America", 276));
    equipos.push_back(Equipo("Vico1x", "Ovation", 18, "Germany", 285));
    equipos.push_back(Equipo("Peterbot", "EXD", 22, "United States of America", 543));
    equipos.push_back(Equipo("FKS", "R8", 22, "Saudi Arabia", 78));
    equipos.push_back(Equipo("Sky", "Atlantic", 22, "France", 153));
    equipos.push_back(Equipo("Shelom", "Null", 20, "Slovenia", 171));
    equipos.push_back(Equipo("Trulex", "Valiant", 21, "Serbia", 351));
    equipos.push_back(Equipo("Shadow", "2AM", 22, "Poland", 243));
    equipos.push_back(Equipo("Prism", "Orkida", 18, "Belgium", 132));
    equipos.push_back(Equipo("Seytto", "Null", 21, "Korea", 75));
    equipos.push_back(Equipo("JobKame44", "CR", 22, "Japan", 69));
    equipos.push_back(Equipo("Koyota", "ZETA", 21, "Japan", 117));
    equipos.push_back(Equipo("7man", "Null", 22, "Bahrain", 147));
    equipos.push_back(Equipo("JannisZ", "CGN", 19, "Germany", 321));
    equipos.push_back(Equipo("Cold", "ManCity", 18, "United States of America", 60));
    equipos.push_back(Equipo("Malibuca", "KC", 18, "Russia", 78));
    equipos.push_back(Equipo("Aspect", "Tribe", 19, "United States of America", 57));
    equipos.push_back(Equipo("T3nny", "Falcnon", 23, "Slovenia", 390));
    equipos.push_back(Equipo("Worthy", "PWR", 18, "Australia", 48));
    equipos.push_back(Equipo("P1ngfnz", "Aight", 21, "United States of America", 399));
    equipos.push_back(Equipo("Threats", "ManCity", 20, "United States of America", 48));
    equipos.push_back(Equipo("Seeyun", "Null", 18, "United States of America", 153));

    int opcion;
    do {
        // Mostrar el menú
        cout << "\nMenu:\n";
        cout << "1. Imprimir equipos\n";
        cout << "2. Ordenar equipos por puntaje (de mayor a menor)\n";
        cout << "3. Buscar equipo por puntaje\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                // Imprimir equipos
                cout << "\nLista de equipos:\n";
                mostrar_equipos(equipos);
                break;

            case 2:
                // Ordenar equipos por puntaje
                ordenar_equipos(equipos);
                cout << "\nEquipos ordenados por puntaje:\n";
                mostrar_equipos(equipos);
                break;

            case 3: {
                // Buscar equipo por puntaje
                int puntaje_a_buscar;
                cout << "Ingrese el puntaje a buscar: ";
                cin >> puntaje_a_buscar;
                busqueda_binaria_puntaje(equipos, puntaje_a_buscar);
                break;
            }

            case 4:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opción no válida. Intente nuevamente.\n";
                break;
        }
    } while (opcion != 4);

    return 0;
}



