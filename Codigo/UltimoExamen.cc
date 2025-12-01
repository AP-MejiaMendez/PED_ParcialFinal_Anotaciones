/**
 * @file adriana_mejia.cc
 * @brief Solución del examen parcial 2 de programación de estructuras dinámicas.
 *
 * Programa que gestione la información sobre zoológicos y sus zonas de exhibición
 *
 * @author Adriana Mejia
 * @date 2025-09-20
 */
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

// Declaración de estructuras de datos
struct Zona
{
    string nombre_zona;
    int cantidad_especies_zona;
};

struct Zoologico
{
    string nombre_zoologico;
    float costo_entrada_zoologico;
    bool guia_zoologico;
    vector<struct Zona> zona_zoologico;
};

// Declaración de funciones
struct Zoologico SolicitarInformacion();
void ImprimirInformacion(const list<Zoologico> zoologicos);
void Ordenar(list<Zoologico> &zoologicos);
void BuscarRegistroDeZoologico(const list<Zoologico> zoologicos, bool guia);

int main()
{
    list<Zoologico> zoologicos;
    int opcion_usuario, opcion_guia;
    bool buscar_por;

    cout << "\n---Bienvenido al programa de zoologicos---\n";
    do
    {
        cout << "\nEscoja una opcion:"
             << "\n (1) Ingresar un zoologico"
             << "\n (2) Imprimir los zoologicos"
             << "\n (3) Ordenar"
             << "\n (4) Buscar"
             << "\n (5) Salir"
             << "\n\nMi respuesta: ";
        cin >> opcion_usuario;
        switch (opcion_usuario)
        {
        case 1:
            zoologicos.push_front(SolicitarInformacion());
            break;
        case 2:
            ImprimirInformacion(zoologicos);
            break;
        case 3:
            Ordenar(zoologicos);
            cout << "\n--Se ha ordenado la lista!\n";
            break;
        case 4:
            cout << "--Buscar por--\n(1) Tienen guia \n(2) No tienen guia\nMi respuesta: ";
            cin >> opcion_guia;

            if (opcion_guia != 1)
            {
                buscar_por = false;
            }
            else
            {
                buscar_por = true;
            }

            BuscarRegistroDeZoologico(zoologicos, buscar_por);
            break;
        case 5:
            cout << "\nHasta la proximaaa\n";
            break;
        default:
            cout << "\nEsa opcion no esta disponible, veulva a intentar\n\n";
            break;
        }
    } while (opcion_usuario != 5);
    return 0;
}

// Funcion que solicita la información al usuario
// Parametros: Sin parametros
// Devuelve una estructura
struct Zoologico SolicitarInformacion()
{
    struct Zoologico zoologico_informacion;
    struct Zona zonas_informacion;

    string nombre;
    float costo_entrada;
    bool guia = false;
    int opcion;
    int opcion_usuario;

    string nombre_de_zona;
    int cantidad_especies;

    cout << "(1) Ingrese el nombre del zoologico: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "(2) Ingrese el costo de entrada: ";
    cin >> costo_entrada;
    cout << "(3) Cuenta con un guia?: (1)Si (2)No\nMi respuesta: ";
    cin >> opcion;

    if (opcion != 1)
    {
        guia = false;
    }
    else
    {
        guia = true;
    }

    cout << "(4) Ingrese las zonas de exibicion: ";
    do
    {
        cout << "\n   (1)Nombre:";
        cin.ignore();
        getline(cin, nombre_de_zona);
        cout << "   (2)Cantidad de especies: ";
        cin >> cantidad_especies;

        zonas_informacion.nombre_zona = {nombre_de_zona};
        zonas_informacion.cantidad_especies_zona = {cantidad_especies};

        cout << "Desee agregar otra zona?:\n(1)Si \n(2)No\nMi respuesta: ";
        cin >> opcion_usuario;

        zoologico_informacion.zona_zoologico.push_back(zonas_informacion);
    } while (opcion_usuario != 2);

    zoologico_informacion.nombre_zoologico = {nombre};
    zoologico_informacion.costo_entrada_zoologico = {costo_entrada};
    zoologico_informacion.guia_zoologico = {guia};

    return zoologico_informacion;
}
// Funcion que imprime la información de los zoologicos al usuario
// Parametros: const list<Zoologico>& zoologicos
// Imprime la información de la lista
void ImprimirInformacion(const list<Zoologico> zoologicos)
{
    int longitud_zoologicos = zoologicos.size();
    string guia = "No";
    if (longitud_zoologicos == 0)
    {
        cout << "\nNo hay nada que imprimir, ningun zoologico ingresado\n";
    }
    else
    {
        cout << "\n---Imprimiendo la informacion ingresada---\n";
        for (const auto &z : zoologicos)
        {
            (z.guia_zoologico) ? guia = "Si" : guia = "No";

            cout << "\n Nombre: " << z.nombre_zoologico
                 << "\n | Costo de entrada " << z.costo_entrada_zoologico
                 << "\n | Cuenta con guia: " << guia;

            cout << "\n----Zonas del zoologico----\n";

            for (auto v : z.zona_zoologico)
            {
                cout << "\nNombre de la zona: " << v.nombre_zona
                     << "\n | Cantidad de especies: " << v.cantidad_especies_zona;
            }
        }
        cout << "\n--------------------------------\n\n";
    }
}
// Funcion que ordenar la información de los zoologicos
// Parametros: list<Zoologico> &zoologicos
// Ordena la información de la lista
void Ordenar(list<Zoologico> &zoologicos)
{
    zoologicos.sort([](const Zoologico &a, const Zoologico &b)
                    { return a.costo_entrada_zoologico < b.costo_entrada_zoologico; });
}
// Funcion que busca los zoologicos en base si tienen o no guia
// Parametros: const list<Zoologico> zoologicos, bool guia
// Busca la información de la lista
void BuscarRegistroDeZoologico(const list<Zoologico> zoologicos, bool guia)
{
    /*bool criterio = [](Zoologico a, Zoologico b) {
        return a.guia_zoologico;
    };
    auto it = find_if(zoologicos.front(), zoologicos.back(), criterio);
    //cout << &it;
    /*if ()
    {

        cout << "Si se encontraron zoologicos con guias.";
    }
    else
    {
        cout << "No se encontró ninguna coincidencia." << std::endl;
    }
   */
}