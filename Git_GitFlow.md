## Comandos para git y uso de gitflow

### Comandos básicos
| No. | Comando                      | Descripción                                                         |
| --- | ---------------------------- | ------------------------------------------------------------------- |
| 1   | **git init**                 | Inicializa un repositorio Git vacío.                                |
| 2   | **git clone <url>**          | Clona un repositorio remoto a tu máquina.                           |
| 3   | **git add .**                | Agrega todos los archivos modificados al staging.                   |
| 4   | **git add <archivo>**        | Agrega un archivo en específico.                                    |
| 5   | **git status**               | Muestra el estado del repositorio.                                  |
| 6   | **git commit -m "mensaje"**  | Crea un commit con mensaje.                                         |
| 7   | **git commit -am "mensaje"** | Agrega y hace commit en un solo paso (solo archivos ya rastreados). |
| 8   | **git log**                  | Muestra historial de commits.                                       |
| 9   | **git show <hash>**          | Muestra detalles de un commit.                                      |
| 10  | **git diff**                 | Muestra cambios sin añadir a staging.                               |
| 11  | **git diff --staged**        | Muestra cambios ya añadidos a staging.                              |

### Comandos para repositorios remotos
| No. | Comando                            | Descripción                           |
| --- | ---------------------------------- | ------------------------------------- |
| 1   | **git remote add origin <url>**    | Conecta repositorio local con remoto. |
| 2   | **git remote -v**                  | Lista las URLs del repo remoto.       |
| 3   | **git push -u origin master/main** | Sube el primer push.                  |
| 4   | **git push**                       | Sube cambios al repositorio remoto.   |
| 5   | **git pull**                       | Descarga cambios y los fusiona.       |
| 6   | **git fetch**                      | Descarga cambios sin fusionar.        |
| 7   | **git push <remoto> <rama>**       | Enviar cambios a repositorio remoto   |

#### Comandos para Configurar el Usuario y las Credenciales
| No. | Comando                                    | Descripción                                                        |
| :-: | :----------------------------------------- | :----------------------------------------------------------------- |
|  1  | **git config --global user.name ""**       | Configura el nombre de usuario global para Git.                    |
|  2  | **git config --global user.email ""**      | Configura el correo electrónico global para Git.                   |
|  3  | **git config user.name ""**                | Configura el nombre de usuario local para un proyecto específico.  |
|  4  | **git config user.email ""**               | Configura el correo electrónico local para un proyecto específico. |
|  5  | **git config --global --unset user.name**  | Elimina la configuración global del nombre de usuario.             |
|  6  | **git config --global --unset user.email** | Elimina la configuración global del correo electrónico.            |
|  7  | **git config --unset user.name**           | Elimina la configuración local del nombre de usuario.              |
|  8  | **git config --unset user.email**          | Elimina la configuración local del correo electrónico.             |
|  9  | **git config --list**                      | Muestra todas las configuraciones de Git.                          |
| 10  | **git config user.name**                   | Muestra el nombre de usuario configurado en Git.                   |
| 11  | **git config user.email**                  | Muestra el correo electrónico configurado en Git.                  |

### Comandos para ramas
| No. | Comando                             | Descripción                    |
| --- | ----------------------------------- | ------------------------------ |
| 1   | **git branch**                      | Lista ramas locales.           |
| 2   | **git branch -a**                   | Lista ramas locales y remotas. |
| 3   | **git branch <nombre>**             | Crea una nueva rama.           |
| 4   | **git checkout <rama>**             | Cambia a otra rama.            |
| 5   | **git checkout -b <rama>**          | Crea y cambia a la nueva rama. |
| 6   | **git merge <rama>**                | Fusiona una rama a la actual.  |
| 7   | **git branch -d <rama>**            | Elimina una rama local.        |
| 8   | **git push origin --delete <rama>** | Elimina una rama remota.       |

### Comandos de recuperación
| No. | Comando                     | Descripción                                        |
| --- | --------------------------- | -------------------------------------------------- |
| 1   | **git restore <archivo>**   | Restaura archivo modificado.                       |
| 2   | **git reset <archivo>**     | Quita archivo del staging.                         |
| 3   | **git reset --soft HEAD~1** | Revierte el último commit **manteniendo cambios**. |
| 4   | **git reset --hard HEAD~1** | Elimina commit y **borra cambios**.                |
| 5   | **git revert <hash>**       | Crea un commit que deshace otro commit.            |

### Git flow
| No. | Comando                             | Descripción                                               |
| --- | ----------------------------------- | --------------------------------------------------------- |
| 1   | **git flow init**                   | Inicializa Git Flow en el proyecto.                       |
| 2   | **git flow feature start nombre**   | Crea rama de feature.                                     |
| 3   | **git flow feature publish nombre** | Publica rama feature al remoto.                           |
| 4   | **git flow feature finish nombre**  | Fusiona feature → develop y elimina rama.                 |
| 5   | **git flow release start vX.X.X**   | Inicia un release.                                        |
| 6   | **git flow release finish vX.X.X**  | Finaliza el release (merge a main, tag, merge a develop). |
| 7   | **git flow hotfix start nombre**    | Inicia hotfix desde main.                                 |
| 8   | **git flow hotfix finish nombre**   | Finaliza hotfix.                                          |

### Usando Git flow
1. git flow init
2. git flow feature start matriz-excel
3. git add .
4. git commit -m "Añadida funcionalidad de cuadrícula"
5. git flow feature publish matriz-excel
6. git flow feature finish matriz-excel
7. git push origin develop

8. git flow release start v1.0.0
9. git flow release finish v1.0.0
10. git push origin main
11. git push origin develop

### Tags
- Crear un tag:
  git tag nombre-etiqueta

- Ver los tags:
  git tag

- Crear un tag con mensaje:
  git tag -a nombre_del_tag -m "Mensaje del tag"

- Ver detalles de un tag:
  git show nombre_del_tag
