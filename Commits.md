## Buen uso de los commits AR ER IR

### 1)Especifica el tipo de commit:

| Tipo          | Significado                         | Ejemplo                                    |
| ------------- | ----------------------------------- | ------------------------------------------ |
| **feat:**     | Nueva funcionalidad                 | feat: Añadir lista doble enlazada          |
| **fix:**      | Corrección de errores               | fix: Corregir desbordamiento de índice     |
| **docs:**     | Documentación                       | docs: Agregar comentarios Doxygen          |
| **style:**    | Cambios sin lógica                  | style: Formatear código según Google Style |
| **refactor:** | Reescritura sin cambios funcionales | refactor: Simplificar recorrido de lista   |
| **test:**     | Pruebas                             | test: Añadir casos frontera                |
| **chore:**    | Tareas menores                      | chore: Actualizar .gitignore               |

Ejemplo: git commit -m "fix: Corregir error de cálculo en la función de descuento"

### 2) Quita signos de puntuación innecesarios.

### 3) Usa mayúsculas al inicio del título y por cada párrafo del cuerpo del mensaje.

### 4) Usa el cuerpo del mensaje para explicar los cambios: Además del titulo, un commit tiene un cuerpo del mensaje, en el cuál, puedes explicar a los colaboradores del repositorio tus cambios.

- git commit -m "fix: Corregir error en la validación del formulario de registro"
  -m "Se corrigió un error que impedía que los usuarios con una contraseña válida pudieran registrarse correctamente.
  El problema se debía a una falta de validación en el campo de contraseña que permitía caracteres especiales no permitidos."

### 5) Sigue la convención del mensaje de commit definida por tu equipo.

### 6) Usar emojis en los mensajes de commit puede ser una forma efectiva de hacer que el historial de commits sea más visual y fácil de entender.

https://gitmoji.dev/