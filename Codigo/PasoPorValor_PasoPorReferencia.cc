#include <iostream>

void PasoPorValor(int taza);
void PasoPorPuntero(int *taza);
void ValorPorReferencia(int &taza);

int main()
{
    //!>
    /*
    int num = 500;
    int *ptr = &num;
    // Dirección de memoria disponible en la cual se encuentra la variable a la que apunta, 0X no pertenece a la dirección
    std::cout << "Dir. memoria num: " << ptr << "\n";
    std::cout << "Dir. memoria pntr: " << &ptr << "\n";
    std::cout << "Valor de lavariable num: " << *ptr << "\n";

    std::cout << "\n-------\n\n";

    // Cambiando el valor de la variable a través del puntero
    *ptr = 800;
    std::cout << "Valor de la variable num cambiada a traves del puntero: " << *ptr << " -- " << &num << "\n";

    num = 1000;
    std::cout << "Valor de la variable num cambiada: " << *ptr << "\n";

    /* Para gestionar memoria, como por ejemplo asignar o quitar hacemos uso del puntero
     Si simplemente queremos manipular la variable sin gestion de memoria no es necesario el uso de puntero*/

    /* Null = 0 || nullPtr = void
    El 0 no representa correctamente el valor "vació" puesto que en algunos casos el 0 tiene importancia
    En cambio nullptr si representa correctamente el void

    int *ptrNull = nullptr;

    !> */

    // TODO ------------- EJERCICIO -------------

    int taza = 0;
    std::cout << "Contenido de la taza: " << taza << "\n"; // 0
    PasoPorValor(taza);                                    // 100
    std::cout << "Contenido de la taza: " << taza << "\n"; // 0
    PasoPorPuntero(&taza);                                 // 100
    std::cout << "Contenido de la taza: " << taza << "\n"; // 100
    ValorPorReferencia(taza);                              // 200
    std::cout << "Contenido de la taza: " << taza << "\n"; // 200
    PasoPorValor(taza); //300
    std::cout << "Contenido de la taza: " << taza << "\n"; // 200
    return 0;
}

void PasoPorValor(int taza)
{
    taza = taza + 100;
    std::cout << "Contenido taza: " << taza << "\n";
}

void PasoPorPuntero(int *taza)
{
    *taza = *taza + 100;
    std::cout << "Contenido taza: " << *taza << "\n";
}

void ValorPorReferencia(int &taza)
{
    taza = taza + 100;
    std::cout << "Contenido taza: " << taza << "\n";
}