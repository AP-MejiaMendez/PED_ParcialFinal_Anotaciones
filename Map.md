/*
===========================================================
        MAP DE ESTUDIANTES (ID → Datos del estudiante)
===========================================================

Estructura del estudiante:
    - nombre
    - apellido
    - materias: map<string, int>   (materia → nota)
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

// ---------------------------------------------------------
// Estructura del estudiante
// ---------------------------------------------------------
struct Estudiante {
    string nombre;
    string apellido;
    map<string, int> materias; // materia → nota
};

// ---------------------------------------------------------
// Ejemplo de uso
// ---------------------------------------------------------
int main() {

    // map: clave = ID del estudiante, valor = Estudiante
    map<int, Estudiante> alumnos;

    // -----------------------------------------------------
    // Insertar estudiantes
    // -----------------------------------------------------
    alumnos[100] = {"Juan", "Perez", { {"Matematica", 8}, {"Prog", 10} }};
    alumnos[200] = {"Ana", "Gomez", { {"Prog", 9}, {"Ingles", 7} }};
    alumnos[300] = {"Luis", "Martinez", {} }; // sin materias aún

    // Agregar materia a un alumno existente
    alumnos[300].materias["Historia"] = 6;
    alumnos[300].materias["Prog"] = 9;

    // -----------------------------------------------------
    // Recorrer todos los estudiantes
    // -----------------------------------------------------
    cout << "LISTA DE ESTUDIANTES:\n";
    for (auto &e : alumnos) {
        cout << "ID: " << e.first << endl;
        cout << "  Nombre: " << e.second.nombre << endl;
        cout << "  Apellido: " << e.second.apellido << endl;

        cout << "  Materias:" << endl;
        for (auto &m : e.second.materias) {
            cout << "    " << m.first << " = " << m.second << endl;
        }
        cout << endl;
    }

    // -----------------------------------------------------
    // Buscar un estudiante por su ID
    // -----------------------------------------------------
    int idBuscado = 200;
    auto it = alumnos.find(idBuscado);

    if (it != alumnos.end()) {
        cout << "Encontrado -> " << it->second.nombre 
             << " " << it->second.apellido << endl;
    } else {
        cout << "No existe el estudiante con ID " << idBuscado << endl;
    }

    // -----------------------------------------------------
    // Borrar un estudiante
    // -----------------------------------------------------
    alumnos.erase(100);

    return 0;
}

