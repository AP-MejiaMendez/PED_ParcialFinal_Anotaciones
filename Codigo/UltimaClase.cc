/*
    Definir una estructura
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct Animal
{
    string nombre_cientifico;
    string nombre_comun;
    bool genero = 0;
    // 0 = false = masc
};

struct Animal SolicitarDatos();
void Imprimir(const unordered_map<string, Animal> &animap);
bool Buscar(const unordered_map<string, Animal> &animap, string clave);
void Eliminar(unordered_map<string, Animal> &animap, string criterio);

int main()
{
    unordered_map<string, Animal> animap;
    string criterio;
    struct Animal animal;
    char continuar;
    int op;
    cout << "\n----------\nBienvenido a nuestro programa de meter animales\n----------\n";

    do
    {
        animal = SolicitarDatos();
        animap.insert({animal.nombre_cientifico, animal});
        cout << "\nDesea agregar otro animal?: \n (1) Si \n (2) No \n\n Mi opcion: ";
        cin >> op;
        cin.ignore();

    } while (op != 2);

    Imprimir(animap);

    cout << "\n\nIngrese el nombre cientifico a eliminar: ";
    cin >> criterio;
    Eliminar(animap, criterio);

    Imprimir(animap);

    return 0;
}

bool Buscar(const unordered_map<string, Animal> &animap, string criterio)
{
    auto encontrado = animap.find(criterio);
    if (encontrado != animap.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Eliminar(unordered_map<string, Animal> &animap, string criterio)
{
    if (Buscar(animap, criterio))
    {
        auto encontrado = animap.find(criterio);
        animap.erase(encontrado);
        cout << "\nEliminado correctamente\n";
    }
    else
    {
        cout << "No existe el elemento a eliminar";
    }
}

void Imprimir(const unordered_map<string, Animal> &animap)
{
    auto hash = animap.hash_function();

    for (const auto &a : animap)
    {
        cout << "\n-------" << "\nHash: " << hash(a.first) << "\n-------"
             << "\nNombre cientifico: " << a.first
             << "\nNombre comun: " << a.second.nombre_comun
             << "\nGenero: " << ((a.second.genero) ? "Femenino" : "Masculino");
    }
}

struct Animal SolicitarDatos()
{
    Animal animal;
    int genero;

    cout << "\nIngrese el nombre cientifico del animal: ";
    getline(cin, animal.nombre_cientifico);

    cout << "Ingrese el nombre comun del animal: ";
    getline(cin, animal.nombre_comun);

    cout << "\nIngrese el genero del animal \n (1)Femenimo | (2)Masculino: \n\n Mi opcion: ";
    cin >> genero;
    (genero == '1') ? animal.genero = 1 : animal.genero = 0;

    return animal;
}