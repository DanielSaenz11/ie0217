/**
 * @file main.cpp
 * @brief Archivo que muestra el menú de interacción del usuario con la base de datos MongoDB.
 * 
 * @details En este archivo se encuentra la función main, la cual corresponde al punto de inicio de ejecución del
 * programa. Se manejan las entradas del usuario y las acciones que desea realizar sobre la base de datos. Asimismo,
 * contiene la información de la base de datos (nombre y colección) para conectarse a ella a través del localhost.
 * 
 * Software bajo la licencia de MIT.
 * En términos generales, se concede permiso para utilizar este Software sin ninguna restricción, pero se proporciona sin
 * ninguna garantía. 
 * El aviso de copyright anterior y este aviso de permiso deberán incluirse en todas
 * las copias o partes sustanciales del Software.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @date 25/10/2024
 */

#include "social_network.hpp"

/**
 * @enum OpcionesMenu
 * @brief Contiene las opciones del menú del programa.
 */
enum opcionesMenu {
    OPT_INSERTAR_PUBLICACION = 1,
    OPT_CONSULTAR_TODAS_PUBLICACIONES,
    OPT_CONSULTAR_POR_AUTOR,
    OPT_CONSULTAR_POR_FECHA,
    OPT_AGREGAR_COMENTARIO,
    OPT_ACTUALIZAR_CONTENIDO,
    OPT_ELIMINAR_PUBLICACION,
    OPT_MARCAR_DESTACADA,
    OPT_SALIR
};

/**
 * @brief Función principal que controla la interacción con el usuario.
 * 
 * Proporciona un menú interactivo para realizar operaciones CRUD sobre la base de datos social_network en MongoDB.
 * 
 * @return int Código de salida del programa.
 */
int main() {
    // Inicializar la instancia de MongoDB y establecer la conexión
    mongocxx::instance inst{};                          // Instancia
    mongocxx::client client{mongocxx::uri{}};           // Cliente
    mongocxx::database db = client["social_network"];   // Base de datos
    mongocxx::collection collection = db["posts"];      // Colección

    int opcion = 0; // Opción ingresada por el usuario en el menú
    do {
        // Mostrar el menú de opciones
        std::cout << "\n--- Menú de Opciones ---" << std::endl;
        std::cout << "1. Insertar Publicación" << std::endl;
        std::cout << "2. Consultar Todas las Publicaciones" << std::endl;
        std::cout << "3. Consultar Publicaciones por Autor" << std::endl;
        std::cout << "4. Consultar Publicaciones por Fecha" << std::endl;
        std::cout << "5. Agregar Comentario a una Publicación" << std::endl;
        std::cout << "6. Actualizar Contenido de una Publicación" << std::endl;
        std::cout << "7. Eliminar Publicación" << std::endl;
        std::cout << "8. Marcar/Desmarcar Publicación como Destacada" << std::endl;
        std::cout << "9. Salir" << std::endl;
        std::cout << "Seleccione una opción: ";

        // Validar la entrada del usuario para el menú
        while (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida. Ingrese un valor numérico entre las opciones.";
        }

        // Ejecutar la acción correspondiente a la opción seleccionada
        switch (opcion) {
            case OPT_INSERTAR_PUBLICACION: {
                // Solicitar datos para insertar una nueva publicación
                std::string autor, contenido, fecha;

                std::cout << "Ingrese el autor: ";
                std::cin.ignore();
                std::getline(std::cin, autor);

                std::cout << "Ingrese el contenido: ";
                std::getline(std::cin, contenido);

                std::cout << "Ingrese la fecha (YYYY-MM-DD): ";
                std::getline(std::cin, fecha);

                // Validar el formato de la fecha
                if (verificarFormatoFecha(fecha)) {
                    // Insertar publicación a la base de datos con la información dada
                    insertarPublicacion(collection, autor, contenido, fecha);
                } else {
                    std::cout << "Formato de fecha inválido. Use el formato YYYY-MM-DD." << std::endl;
                }
                break;
            }
            case OPT_CONSULTAR_TODAS_PUBLICACIONES:
                // Consultar y mostrar todas las publicaciones
                consultarPublicaciones(collection);
                break;
            case OPT_CONSULTAR_POR_AUTOR: {
                // Solicitar el autor y consultar sus publicaciones
                std::string autor;

                std::cout << "Ingrese el autor: ";
                std::cin.ignore();
                std::getline(std::cin, autor);

                consultarPublicacionesPorAutor(collection, autor);
                break;
            }
            case OPT_CONSULTAR_POR_FECHA:
                // Consultar y mostrar las publicaciones por fecha
                consultarPublicacionesPorFecha(collection);
                break;
            case OPT_AGREGAR_COMENTARIO: {
                // Solicitar datos para agregar un comentario a una publicación existente
                std::string autor, fecha, usuario, comentario, fechaComentario;

                std::cout << "Ingrese el autor de la publicación: ";
                std::cin.ignore();
                std::getline(std::cin, autor);

                std::cout << "Ingrese la fecha de la publicación (YYYY-MM-DD): ";
                std::getline(std::cin, fecha);

                // Validar el formato de la fecha
                if (!verificarFormatoFecha(fecha)) {
                    std::cout << "Formato de fecha inválido. Use el formato YYYY-MM-DD." << std::endl;
                    break;
                }

                std::cout << "Ingrese el usuario que comenta: ";
                std::getline(std::cin, usuario);

                std::cout << "Ingrese el comentario: ";
                std::getline(std::cin, comentario);

                std::cout << "Ingrese la fecha del comentario (YYYY-MM-DD): ";
                std::getline(std::cin, fechaComentario);

                // Validar el formato de la fecha del comentario
                if (verificarFormatoFecha(fechaComentario)) {
                    // Agregar comentario a la base de datos con la información dada
                    agregarComentario(collection, autor, fecha, usuario, comentario, fechaComentario);
                } else {
                    std::cout << "Formato de fecha inválido. Use el formato YYYY-MM-DD." << std::endl;
                }
                break;
            }
            case OPT_ACTUALIZAR_CONTENIDO: {
                // Solicitar datos para actualizar el contenido de una publicación
                std::string autor, fecha, nuevoContenido;

                std::cout << "Ingrese el autor de la publicación: ";
                std::cin.ignore();
                std::getline(std::cin, autor);

                std::cout << "Ingrese la fecha de la publicación (YYYY-MM-DD): ";
                std::getline(std::cin, fecha);

                // Validar el formato de la fecha
                if (!verificarFormatoFecha(fecha)) {
                    std::cout << "Formato de fecha inválido. Use el formato YYYY-MM-DD." << std::endl;
                    break;
                }

                // Ingresar el nuevo contenido de la publicación
                std::cout << "Ingrese el nuevo contenido: ";
                std::getline(std::cin, nuevoContenido);

                // Ingresar el nuevo contenido a la base de datos
                actualizarPublicacion(collection, autor, fecha, nuevoContenido);
                break;
            }
            case OPT_ELIMINAR_PUBLICACION: {
                // Solicitar datos para eliminar una publicación
                std::string autor, fecha;

                std::cout << "Ingrese el autor de la publicación: ";
                std::cin.ignore();
                std::getline(std::cin, autor);

                std::cout << "Ingrese la fecha de la publicación (YYYY-MM-DD): ";
                std::getline(std::cin, fecha);

                // Validar el formato de la fecha
                if (verificarFormatoFecha(fecha)) {
                    // Eliminar publicación de la base de datos
                    eliminarPublicacion(collection, autor, fecha);
                } else {
                    std::cout << "Formato de fecha inválido. Use el formato YYYY-MM-DD." << std::endl;
                }
                break;
            }
            case OPT_MARCAR_DESTACADA: {
                // Solicitar datos para marcar/desmarcar una publicación como destacada
                std::string autor, fecha;
                bool destacada;

                std::cout << "Ingrese el autor de la publicación: ";
                std::cin.ignore();
                std::getline(std::cin, autor);

                std::cout << "Ingrese la fecha de la publicación (YYYY-MM-DD): ";
                std::getline(std::cin, fecha);

                // Validar el formato de la fecha
                if (!verificarFormatoFecha(fecha)) {
                    std::cout << "Formato de fecha inválido. Use el formato YYYY-MM-DD." << std::endl;
                    break;
                }

                // Mensaje para marcar/desmarcar
                std::cout << "¿Desea marcar la publicación como destacada? (1 para sí, 0 para no): ";
                std::cin >> destacada;

                // Actualizar el estado de destacada en la base de datos
                marcarDestacada(collection, autor, fecha, destacada);
                break;
            }
            case OPT_SALIR:
                // Salir del programa
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                // Mensaje de opción inválida
                std::cout << "Opción inválida. Seleccione una opción válida." << std::endl;
        }
    } while (opcion != OPT_SALIR); // Condición de repetición del loop del menú

    return 0;
}
