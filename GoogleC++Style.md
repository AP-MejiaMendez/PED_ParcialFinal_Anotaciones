## Google c++ style y comentarios
| Regla                                     | Descripción                    |
| ----------------------------------------- | ------------------------------ |
| **Identación:** 2 espacios                | Nada de tabs.                  |
| **Límite de línea:** 80 caracteres        | Obligatorio.                   |
| **Llaves estilo K&R (Egipcio)**           | `{` en la misma línea.         |
| **Nombrado de variables:** snake_case     | `total_suma`, `numero_items`   |
| **Nombrado de funciones:** PascalCase     | `CalcularPromedio()`           |
| **Nombrado de clases/struct:** PascalCase | `struct NodoLista`             |
| **Const-correctness:** usar `const`       | `int Calcular(const int x)`    |
| **Paso por referencia:**                  | Objetos grandes por `const &`. |
| **Inicialización:** siempre inicializar   | `int total = 0;`               |
| **Evitar auto innecesario**               | Solo si el tipo es obvio.      |
| **Evitar variables no usadas**            | No declarar lo que no usarás.  |

### Reglas para estructuras y funciones
| Regla                          | Explicación                                           |
| ------------------------------ | ----------------------------------------------------- |
| **Responsabilidad única**      | Una función = una sola acción.                        |
| **Validación de parámetros**   | Validar al inicio (`if (ptr == nullptr)`).            |
| **Archivos separados**         | `.hpp` para declaraciones, `.cc` para implementación. |
| **Documentación con Doxygen**  | Cada función con `@brief`, `@param`, `@return`.       |
| **Constructores recomendados** | Inicialización con lista `{}` cuando aplica.          |

### Comentarios en el codigo
- Documentación: Cada archivo .hpp o .cc debe empezar con un bloque de cabecera que incluya
  Nombre del archivo
  Descripción breve de su propósito
  Autor(es)
  Fecha de creación / modificación

  @file examen.cc
  @brief Solución del examen parcial 2 de programación de estructuras dinámicas.

  Contiene las funciones que satisfacen las indicaciones dadas por la instructura que resuelven el ejercicio.

  @author Adriana
  @date 2025-10-25

  - Documentación de funciones:

  @brief Calcula el área de un cuadrado.
  @param lado Longitud del lado (mayor que 0).
  @return Área del cuadrado.

#

@file AdrianaMejia.cc
@brief Resolución del parcial Clave A

Se busca desarrollar un programa para gestionar información sobre cine y sus salas de proyección.

@author Adriana Mejia
@date 2025-09-20

#

@brief Calcula el área de un cuadrado.

Recibe la longitud de un lado y devuelve el área correspondiente.

@param lado Longitud de un lado del cuadrado (debe ser mayor que 0).
@return Área del cuadrado (lado \* lado).

@throw std::invalid_argument si lado <= 0.

@example
int a = calcularAreaCuadrado(5); // devuelve 25
/
int CalcularAreaCuadrado(int lado){
};
