#include <iostream>
#include <map>
#include <string>
using namespace std;

// Ejemplo simple con maps de strings y enteros

int main() {

    // Mapa externo que contiene mapas internos
    map<string, map<int,string>> zoologicos;

    // Otro map externo para recibir datos
    map<int,string> datosExtra;

    // =============================
    //   CARGA INICIAL DE DATOS
    // =============================
    zoologicos["ZooCentral"][10] = "Leon";
    zoologicos["ZooCentral"][20] = "Tigre";
    zoologicos["ZooCentral"][50] = "Jirafa";

    zoologicos["ZooNorte"][5] = "Mono";
    zoologicos["ZooNorte"][7] = "Oso";

    // =============================
    //   CASO 1: Pasar un solo dato
    // =============================
    {
        cout << "CASO 1: Pasar un solo dato" << endl;
        auto &mapInterno = zoologicos["ZooCentral"];
        auto it = mapInterno.find(50);

        if (it != mapInterno.end()) {
            datosExtra[it->first] = it->second;  // copiar
            cout << "Copiado: " << it->first << " -> " << it->second << endl;
        }
    }

    // =============================
    //   CASO 2: Copiar TODO un map interno
    // =============================
    {
        cout << "\nCASO 2: Copiar TODO el map interno" << endl;
        map<int,string> copiaCompleta = zoologicos["ZooNorte"];

        for (auto &p : copiaCompleta)
            cout << p.first << " -> " << p.second << endl;
    }

    // =============================
    //   CASO 3: Copiar solo algunos elementos
    // =============================
    {
        cout << "\nCASO 3: Copiar solo algunos elementos" << endl;
        auto &mapInterno = zoologicos["ZooCentral"];

        for (auto &p : mapInterno) {
            if (p.first > 15) { // condición cualquiera
                datosExtra[p.first] = p.second;
                cout << "Copiado condicional: " << p.first << " -> " << p.second << endl;
            }
        }
    }

    // =============================
    //   CASO 4: Mover (copiar + eliminar)
    // =============================
    {
        cout << "\nCASO 4: Mover un elemento (copiar y eliminar)" << endl;
        auto &mapInterno = zoologicos["ZooCentral"];
        auto it = mapInterno.find(20);

        if (it != mapInterno.end()) {
            datosExtra[it->first] = it->second;  // copiar
            cout << "Movido: " << it->first << " -> " << it->second << endl;

            mapInterno.erase(it);               // eliminar del original
        }
    }

    // =============================
    //   CASO 5: Mover entre dos maps internos
    // =============================
    {
        cout << "\nCASO 5: Mover entre dos maps internos" << endl;

        auto &z1 = zoologicos["ZooCentral"];
        auto &z2 = zoologicos["ZooNorte"];

        auto it = z1.find(10);

        if (it != z1.end()) {
            z2[it->first] = it->second; // copiar al otro map interno
            cout << "Movido interno: " << it->first << " -> " << it->second << endl;

            z1.erase(it);               // borrar del primero
        }
    }

    // =============================
    //   MOSTRAR RESULTADOS
    // =============================
    cout << "\n=== Estado final de datosExtra ===\n";
    for (auto &p : datosExtra)
        cout << p.first << " -> " << p.second << endl;

    cout << "\n=== Estado final de zoologicos ===\n";
    for (auto &zoo : zoologicos) {
        cout << "\nZoologico: " << zoo.first << endl;
        for (auto &p : zoo.second)
            cout << "  " << p.first << " -> " << p.second << endl;
    }

    return 0;
}