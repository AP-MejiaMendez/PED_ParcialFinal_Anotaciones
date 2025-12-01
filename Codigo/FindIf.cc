#include <iostream>
#include <list>
#include <string>
#include <algorithm>

// definicion de la estructura Luchador
struct Luchador
{

    std::string nombre;
    float peso;
};

// declaracion de funciones
// funcion de agregar
Luchador SolicitarDatosLuchador()
{
    Luchador luchador;
    std::cout << "==========================" << std::endl;
    std::cout << "Ingrese el nombre del luchador: ";
    std::cin >> luchador.nombre;

    std::cout << "Ingrese el peso del luchador(en libras): ";
    std::cin >> luchador.peso;

    return luchador;
}

// imprimir datos
void imprimrDatos(std::list<struct Luchador> Luchadores, int n)
{
    for (auto c : Luchadores)
    {
        std::cout << "*Nombre: " << c.nombre << std::endl
                  << " peso: " << c.peso << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;
}

void buscarLuchadorNombre(std::list<struct Luchador> Luchadores, std::string nombre_buscar)
{
    auto pre = [nombre_buscar](const Luchador &luchador)
    {
        return luchador.nombre == nombre_buscar;
    };

    auto it = std::find_if(Luchadores.begin(), Luchadores.end(), pre);

    if (it != Luchadores.end())
    {
        std::cout << "Luchador encontrado: " << it->nombre << ", Peso: " << it->peso << std::endl;
    }
    else
    {
        std::cout << "Luchador no encontrado" << std::endl;
    }
}

int main()
{
    // declaracion de variables
    std::list<Luchador> Luchadores;
    int n, numero_luchadores;
    std::string nombre_buscado;

    std::cout << "Cuantos luchadores desea ingres? ";
    std::cin >> numero_luchadores;
    do
    {
        Luchadores.push_back(SolicitarDatosLuchador());
        numero_luchadores--;
    } while (numero_luchadores > 0);

    // imprimir datos de luchadores
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Datos de los luchadores ingresados: " << std::endl;
    imprimrDatos(Luchadores, n);

    // imprimir datos de luchadores ordenados
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Datos de los luchadores ingresados ORDENADOS: " << std::endl;
    //usar sort de list
    Luchadores.sort([](const Luchador &a, const Luchador &b)
                    { return a.peso < b.peso; });   
    imprimrDatos(Luchadores, n);

    // busqueda por nombre
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "ingrese el nombre del luchador a buscar: " << std::endl;
    std::cin >> nombre_buscado;
    buscarLuchadorNombre(Luchadores, nombre_buscado);

    return 0;
}