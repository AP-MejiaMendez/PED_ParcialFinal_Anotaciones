/*
=====================================================================
        SISTEMA DE GESTIÓN DE ZOOLÓGICOS (CON MAP)
=====================================================================
Estructura:
  map<string, Zoologico>
        |
        |--- map<int, Visitante>
        |
        └--- map<int, Habitat>
                     |
                     └--- map<string, int> animales (ej: "Leones" → 3)
=====================================================================
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

// ---------------------------------------------------------
// ESTRUCTURAS
// ---------------------------------------------------------

struct Visitante {
    string nombre;
    int edad;
};

struct Habitat {
    string tipo;                      // Ej: "Selva", "Acuático"
    map<string, int> animales;        // Animal → cantidad
};

struct Zoologico {
    string nombre;
    string direccion;

    map<int, Visitante> visitantes;   // ID visitante → datos
    map<int, Habitat> habitats;       // ID habitat → datos
};

// ---------------------------------------------------------
// MAIN DE EJEMPLO COMPLETO CON TODAS LAS OPERACIONES
// ---------------------------------------------------------

int main() {

    map<string, Zoologico> zoologicos;   // clave: nombre del zoo

    // *****************************************************************
    // INSERTAR ZOOLÓGICO
    // *****************************************************************
    zoologicos["ZooCentral"] = {"ZooCentral", "Av. Siempreviva 123", {}, {}};
    zoologicos["EcoWild"] = {"EcoWild", "Ruta 8 km 55", {}, {}};

    // *****************************************************************
    // INSERTAR VISITANTES
    // *****************************************************************
    zoologicos["ZooCentral"].visitantes[1] = {"Juan Perez", 25};
    zoologicos["ZooCentral"].visitantes[2] = {"Ana Lopez", 30};

    zoologicos["EcoWild"].visitantes[10] = {"Carlos Diaz", 19};

    // *****************************************************************
    // INSERTAR HABITATS
    // *****************************************************************
    zoologicos["ZooCentral"].habitats[100] = {"Selva", {{"Tigres", 3}, {"Monos", 12}}};
    zoologicos["ZooCentral"].habitats[101] = {"Desierto", {{"Camellos", 4}}};

    zoologicos["EcoWild"].habitats[500] = {"Acuático", {{"Delfines", 5}, {"Tiburones", 2}}};

    // *****************************************************************
    // INSERTAR ANIMAL DENTRO DE UN HÁBITAT
    // *****************************************************************
    zoologicos["ZooCentral"].habitats[100].animales["Jaguar"] = 1;

    // *****************************************************************
    // BUSCAR ZOOLÓGICO
    // *****************************************************************
    string buscarZoo = "ZooCentral";
    if (zoologicos.count(buscarZoo)) {
        cout << "Encontrado zoológico: " << buscarZoo << endl;
    } else {
        cout << buscarZoo << " NO existe.\n";
    }

    // *****************************************************************
    // BUSCAR VISITANTE POR ID
    // *****************************************************************
    int buscarVisitante = 2;
    auto &visitMap = zoologicos["ZooCentral"].visitantes;
    auto itVisit = visitMap.find(buscarVisitante);

    if (itVisit != visitMap.end()) {
        cout << "Visitante encontrado: " << itVisit->second.nombre << endl;
    } else {
        cout << "No existe el visitante con ID " << buscarVisitante << endl;
    }

    // *****************************************************************
    // BUSCAR HABITAT
    // *****************************************************************
    int buscarHab = 100;
    auto itHab = zoologicos["ZooCentral"].habitats.find(buscarHab);

    if (itHab != zoologicos["ZooCentral"].habitats.end()) {
        cout << "Habitat encontrado: " << itHab->second.tipo << endl;
    }

    // *****************************************************************
    // ELIMINAR VISITANTE
    // *****************************************************************
    zoologicos["ZooCentral"].visitantes.erase(1);

    // *****************************************************************
    // ELIMINAR HABITAT
    // *****************************************************************
    zoologicos["EcoWild"].habitats.erase(500);

    // *****************************************************************
    // ELIMINAR ZOOLÓGICO COMPLETO
    // *****************************************************************
    zoologicos.erase("EcoWild");

    // *****************************************************************
    // MOSTRAR TODO
    // *****************************************************************
    cout << "\n========= MOSTRANDO TODOS LOS ZOOLÓGICOS =========\n";
    for (auto &Z : zoologicos) {
        cout << "\nZoológico: " << Z.second.nombre << endl;
        cout << "Dirección: " << Z.second.direccion << endl;

        cout << "\n--- Visitantes ---\n";
        for (auto &V : Z.second.visitantes) {
            cout << "ID " << V.first << ": "
                 << V.second.nombre << " (" << V.second.edad << " años)\n";
        }

        cout << "\n--- Hábitats ---\n";
        for (auto &H : Z.second.habitats) {
            cout << "ID " << H.first << " -> Tipo: " << H.second.tipo << endl;

            cout << "  Animales:\n";
            for (auto &A : H.second.animales) {
                cout << "    " << A.first << ": " << A.second << endl;
            }
        }
        cout << "-----------------------------------\n";
    }

    return 0;
}