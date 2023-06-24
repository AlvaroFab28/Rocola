# Rockola USFX

Este es un programa básico desarrollado en C++ con Programación Orientada a Objetos (POO), contenedores STL y el patrón singleton. La aplicación simula una rocola y permite la manipulación de playlists y canciones (no reproduce canciones reales).

## Menú Principal
El menú principal de la rocola ofrece diversas operaciones para interactuar con las playlists. Solo necesitas seleccionar una opción ingresando el número correspondiente. Aquí está el menú principal:

            ROCKOLA USFX
                                            
 Operación a realizar en la Rockola:        
                                            
     1.-  Cargar una Playlist               
     2.-  Eliminar una Playlist             
     3.-  Mostrar Todas las Playlist        
     4.-  Trabajar en una Playlist          
     5.-  Guardar                           
                                            
  <- 6.-  Cerrar Programa                   


opcion (1-6):


### Submenú PlayList 
El programa incluye varios submenús en los que puedes interactuar para realizar diferentes operaciones en las playlists. A continuación se muestra el menú de opciones de la playlist por defecto:

PLAYLIST POR DEFECTO
DESCRIPCION: Playlist por defecto para realizar pruebas
Seleccione la operacion a realizar:

      1.-  Agregar Cancion
      2.-  Eliminar Cancion
      3.-  Ver la PlayList
      4.-  Buscar cancion
      5.-  Importar una PlayList
      6.-  Clonar una PlayList
      7.-  Cancion mas Corta
      8.-  Cancion mas Larga
      9.-  Top 10 canciones
      10.- Top N canciones
      11.- Ver Artistas Archivo Json

   <- 12.- Volver

Opcion (1-12):

## Requisitos
Compilador de C++
Biblioteca externa para la manipulación de archivos JSON (incluir en el proyecto)
Visual Studio (IDE utilizado para el desarrollo)

## Instrucciones de Uso
1. Clona o descarga este repositorio en tu máquina local.
2. Abre el proyecto en Visual Studio u otro entorno de desarrollo C++ compatible.
3. Configura el proyecto para incluir la biblioteca externa "SON for Modern C++ (nlohmann/json)" según las instrucciones proporcionadas por el proveedor.
4. Compila y ejecuta el programa.
5. Sigue las indicaciones en pantalla para interactuar con la rocola y las playlists.

## Notas Adicionales
El programa utiliza fuentes de datos estáticas y archivos CSV para cargar playlists y agregar canciones.
Asegúrate de descargar la biblioteca externa para la manipulación de archivos JSON y agregarla al proyecto antes de compilar.
Este proyecto fue desarrollado en Visual Studio 2022.

## Capturas de Pantalla
quí se presentan algunas capturas de pantalla del programa en ejecución:

Interfaz principal:

![Captura de pantalla 2023-06-24 113254](https://github.com/AlvaroFab28/Rocola/assets/74251083/7d1c61d0-c0c0-442a-b8f2-00e2f00ab4ac)

Carga de Playlist desde una fuente Estatica:

![Captura de pantalla 2023-06-24 113325](https://github.com/AlvaroFab28/Rocola/assets/74251083/1fa760c7-7a1b-4523-a9a7-203bec14acd9)

Operaciones en la Playlist por Defecto:

![Captura de pantalla 2023-06-24 113409](https://github.com/AlvaroFab28/Rocola/assets/74251083/22c810ab-456d-45f9-8a1d-1e078c317f88)

Carga de canciones de Fuente Estatica a la Playlist:

![Captura de pantalla 2023-06-24 113451](https://github.com/AlvaroFab28/Rocola/assets/74251083/fa71c0cd-e4c5-4b40-8fd5-e079b55edba2)

## Contribución
Las contribuciones son bienvenidas. Si deseas contribuir a este proyecto, por favor, sigue estos pasos:

1. Realiza un fork del proyecto.
2. Crea una rama con la nueva funcionalidad: git checkout -b nueva-funcionalidad.
3. Realiza los cambios necesarios y guarda los archivos.
4. Realiza un commit de tus cambios: git commit -m 'Agregar nueva funcionalidad'.
5. Sube tus cambios al repositorio: git push origin nueva-funcionalidad.
6. Realiza una pull request en el repositorio original.

## Autor
Villena Mamani Alvaro Fabian - Desarrollador principal

## Colaborador
Molina Yampa Luis Antonio (Asesor/Colaborador)

## Licencia
Este proyecto está licenciado bajo Licencia MIT.

## Contacto
Para cualquier consulta o duda relacionada con este proyecto, puedes ponerte en contacto conmigo a través del siguiente correo:
Correo electrónico: alvarofabianvillenam@gmail.com
