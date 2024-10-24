#include "social_network.hpp"

// using namespace bsoncxx::builder::stream;
// using bsoncxx::builder::stream::document;

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

int main() {
    mongocxx::instance inst{};
    mongocxx::client client{mongocxx::uri{}};
    mongocxx::database db = client["social_network"];
    mongocxx::collection collection = db["posts"];

    int opcion = 0;
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
        std::cout << "8. Marcar Publicación como Destacada" << std::endl;
        std::cout << "9. Salir" << std::endl;
        std::cout << "Seleccione una opción: ";

        while (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida. Ingrese un valor numérico entre las opciones.";
        }

        switch (opcion) {
            case OPT_INSERTAR_PUBLICACION: {
                std::string autor, contenido, fecha;

                std::cout << "Ingrese el autor: ";
                std::cin.ignore();
                std::getline(std::cin, autor);

                std::cout << "Ingrese el contenido: ";
                std::getline(std::cin, contenido);

                std::cout << "Ingrese la fecha (YYYY-MM-DD): ";
                std::getline(std::cin, fecha);

                if (verificarFormatoFecha(fecha)) {
                    insertarPublicacion(collection, autor, contenido, fecha);
                } else {
                    std::cout << "Formato de fecha inválido. Use el formato YYYY-MM-DD." << std::endl;
                }
                break;
            }
            case OPT_CONSULTAR_TODAS_PUBLICACIONES:
                consultarPublicaciones(collection);
                break;
            case OPT_CONSULTAR_POR_AUTOR: {
                std::string autor;

                std::cout << "Ingrese el autor: ";
                std::cin.ignore();
                std::getline(std::cin, autor);

                consultarPublicacionesPorAutor(collection, autor);
                break;
            }
            case OPT_CONSULTAR_POR_FECHA:
                consultarPublicacionesPorFecha(collection);
                break;
            case OPT_AGREGAR_COMENTARIO: {
                std::string autor, fecha, usuario, comentario, fechaComentario;

                std::cout << "Ingrese el autor de la publicación: ";
                std::cin.ignore();
                std::getline(std::cin, autor);

                std::cout << "Ingrese la fecha de la publicación (YYYY-MM-DD): ";
                std::getline(std::cin, fecha);

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

                if (verificarFormatoFecha(fechaComentario)) {
                    agregarComentario(collection, autor, fecha, usuario, comentario, fechaComentario);
                } else {
                    std::cout << "Formato de fecha inválido. Use el formato YYYY-MM-DD." << std::endl;
                }
                break;
            }
            case OPT_ACTUALIZAR_CONTENIDO: {
                std::string autor, fecha, nuevoContenido;

                std::cout << "Ingrese el autor de la publicación: ";
                std::cin.ignore();
                std::getline(std::cin, autor);

                std::cout << "Ingrese la fecha de la publicación (YYYY-MM-DD): ";
                std::getline(std::cin, fecha);

                if (!verificarFormatoFecha(fecha)) {
                    std::cout << "Formato de fecha inválido. Use el formato YYYY-MM-DD." << std::endl;
                    break;
                }

                std::cout << "Ingrese el nuevo contenido: ";
                std::getline(std::cin, nuevoContenido);

                actualizarPublicacion(collection, autor, fecha, nuevoContenido);
                break;
            }
            case OPT_ELIMINAR_PUBLICACION: {
                std::string autor, fecha;

                std::cout << "Ingrese el autor de la publicación: ";
                std::cin.ignore();
                std::getline(std::cin, autor);

                std::cout << "Ingrese la fecha de la publicación (YYYY-MM-DD): ";
                std::getline(std::cin, fecha);

                if (verificarFormatoFecha(fecha)) {
                    eliminarPublicacion(collection, autor, fecha);
                } else {
                    std::cout << "Formato de fecha inválido. Use el formato YYYY-MM-DD." << std::endl;
                }
                break;
            }
            case OPT_MARCAR_DESTACADA: {
                std::string autor, fecha;
                bool destacada;

                std::cout << "Ingrese el autor de la publicación: ";
                std::cin.ignore();
                std::getline(std::cin, autor);

                std::cout << "Ingrese la fecha de la publicación (YYYY-MM-DD): ";
                std::getline(std::cin, fecha);

                if (!verificarFormatoFecha(fecha)) {
                    std::cout << "Formato de fecha inválido. Use el formato YYYY-MM-DD." << std::endl;
                    break;
                }

                std::cout << "¿Desea marcar la publicación como destacada? (1 para sí, 0 para no): ";
                std::cin >> destacada;

                marcarDestacada(collection, autor, fecha, destacada);
                break;
            }
            case OPT_SALIR:
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "Opción inválida. Seleccione una opción válida." << std::endl;
        }
    } while (opcion != OPT_SALIR);

    return 0;
}