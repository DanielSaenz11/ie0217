/**
 * @file social_network.cpp
 * @brief Archivo que contiene la implementación de las funciones para interactuar con la base de datos MongoDB.
 * 
 * @details Este archivo contiene la definición de las funciones para insertar y consultar sobre las publicaciones,
 * agregar comentarios, actualizar el contenido de una publicación, eliminar una publicación y marcar como destacada.
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
#include <regex>

using namespace bsoncxx::builder::stream;
using bsoncxx::builder::stream::document;

void insertarPublicacion(mongocxx::collection& collection, const std::string& autor, const std::string& contenido, const std::string& fecha) {
    try {
        // Verificar que no haya un documento con el autor y fecha que se van a ingresar
        if (verificarPublicacionExiste(collection, autor, fecha)) {
            std::cout << "Ya existe una publicación para ese autor y fecha." << std::endl;
            return; // En caso de haberlo, se sale de la función
        }

        // Crear documento BSON para la nueva publicación
        document publicacion{};
        publicacion << "autor" << autor
                    << "contenido" << contenido
                    << "fecha" << fecha
                    << "comentarios" << open_array << close_array
                    << "destacada" << false;
        
        // Insertar documento en la colección
        collection.insert_one(publicacion.view());
        std::cout << "Publicación insertada correctamente en la base de datos." << std::endl;
    } catch(const std::exception& e) {
        // Manejo de errores en caso de fallo al insertar
        std::cerr << "Error al insertar la publicación: " << e.what() << std::endl;
    }
}

void consultarPublicaciones(mongocxx::collection& collection) {
    try {
        // Obtener todos los documentos de la colección posts
        auto cursor = collection.find({});

        // Imprimir cada documento con formato autor, contenido, fecha
        for (auto&& doc : cursor) {
            std::cout << "Autor: " << doc["autor"].get_utf8().value << "\n"
                      << "Contenido: " << doc["contenido"].get_utf8().value << "\n"
                      << "Fecha: " << doc["fecha"].get_utf8().value << "\n"
                      << "-----------------------" << std::endl;
        }
    } catch (const std::exception& e) {
        // Manejo de errores en caso de fallo al consultar
        std::cerr << "Error al consultar publicaciones: " << e.what() << std::endl;
    }
}

void consultarPublicacionesPorAutor(mongocxx::collection& collection, const std::string& autor) {
    try {
        // Crear filtro para buscar publicaciones por autor
        document filter{};
        filter << "autor" << autor;

        // Obtener los documentos que coincidan con el filtro
        auto cursor = collection.find(filter.view());

        // Imprimir cada documento con formato autor, contenido, fecha
        for (auto&& doc : cursor) {
            std::cout << "Autor: " << doc["autor"].get_utf8().value << "\n"
                      << "Contenido: " << doc["contenido"].get_utf8().value << "\n"
                      << "Fecha: " << doc["fecha"].get_utf8().value << "\n"
                      << "-----------------------" << std::endl;
        }
    } catch (const std::exception& e) {
        // Manejo de errores en caso de fallo al consultar
        std::cerr << "Error al consultar por autor: " << e.what() << std::endl;
    }
}

void consultarPublicacionesPorFecha(mongocxx::collection& collection) {
    try {
        // Crear el documento de opciones para ordenar por fecha de manera descendente
        document sortOptions{};
        sortOptions << "fecha" << -1;

        // Obtener los documentos ordenados por fecha
        auto cursor = collection.find({}, mongocxx::options::find{}.sort(sortOptions.view()));

        // Imprimir cada documento con formato específico
        for (auto&& doc : cursor) {
            std::cout << "Autor: " << doc["autor"].get_utf8().value << "\n"
                      << "Contenido: " << doc["contenido"].get_utf8().value << "\n"
                      << "Fecha: " << doc["fecha"].get_utf8().value << "\n"
                      << "-----------------------" << std::endl;
        }
    } catch (const std::exception& e) {
        // Manejo de errores en caso de fallo al consultar
        std::cerr << "Error al consultar publicaciones por fecha: " << e.what() << std::endl;
    }
}

void agregarComentario(mongocxx::collection& collection, const std::string& autor, const std::string& fecha, const std::string& usuario, const std::string& comentario, const std::string& fechaComentario) {
    try {
        // Verificar si existe una publicación para comentar con el autor y fecha indicados
        if (!verificarPublicacionExiste(collection, autor, fecha)) {
            std::cout << "La publicación no existe. No se puede agregar el comentario." << std::endl;
            return; // En caso de no haberlo, se sale de la función
        }

        // Crear filtro para encontrar la publicación
        document filtro{};
        filtro << "autor" << autor
               << "fecha" << fecha;
        
        // Crear documento BSON para el nuevo comentario
        document docComentario{};
        docComentario << "usuario" << usuario
                      << "comentario" << comentario
                      << "fecha_comentario" << fechaComentario;
        
        // Actualizar la información añadida del nuevo comentario en la publicación original
        document update{};
        update << "$push" << open_document << "comentarios" << docComentario << close_document;

        // Actualizar en la colección
        collection.update_one(filtro.view(), update.view());
        
        std::cout << "Comentario agregado correctamente." << std::endl;

    } catch(const std::exception& e) {
        // Manejo de errores en caso de fallo del comentario
        std::cerr << "Error al agregar comentario: " << e.what() << '\n';
    }
}

void actualizarPublicacion(mongocxx::collection& collection, const std::string& autor, const std::string& fecha, const std::string& nuevoContenido) {
    try {
        // Verificar si existe una publicación para actualizar su información según el autor y fecha
        if (!verificarPublicacionExiste(collection, autor, fecha)) {
            std::cout << "La publicación no existe. No se puede actualizar el contenido." << std::endl;
            return; // En caso de que no, se sale de la función
        }

        // Crear documento para encontrar la publicación
        document filtro{};
        filtro << "autor" << autor
               << "fecha" << fecha;
        
        // Crear documento para la actualización del nuevo contenido
        document update{};
        update << "$set" << open_document << "contenido" << nuevoContenido << close_document;

        // Realizar la actualización en la colección
        collection.update_one(filtro.view(), update.view());

        std::cout << "Publicación actualizada correctamente." << std::endl;

    } catch(const std::exception& e) {
        // Manejo de errores en caso de fallo al actualizar
        std::cerr << "Error al actualizar la publicación: " << e.what() << '\n';
    }
}

void eliminarPublicacion(mongocxx::collection& collection, const std::string& autor, const std::string& fecha) {
    try {
        // Verificar si existe una publicación para eliminar
        if (!verificarPublicacionExiste(collection, autor, fecha)) {
            std::cout << "La publicación no existe para ese autor y fecha." << std::endl;
            return; // En caso de que no, se sale de la función
        }

        // Crear filtro para encontrar la publicación
        document filtro{};
        filtro << "autor" << autor
               << "fecha" << fecha;

        // Eliminar el documento que hizo match con el filtro
        collection.delete_one(filtro.view());

        std::cout << "Publicación eliminada correctamente." << std::endl;

    } catch(const std::exception& e) {
        // Manejo de errores en caso de fallo al eliminar
        std::cerr << "Error al eliminar la publicación: " << e.what() << std::endl;
    }
}

void marcarDestacada(mongocxx::collection& collection, const std::string& autor, const std::string& fecha, bool destacada) {
    try {
        // Verificar si existe una publicación para marcar como destacada según el autor y fecha
        if (!verificarPublicacionExiste(collection, autor, fecha)) {
            std::cout << "La publicación no existe. No se puede marcar/desmarcar como destacada." << std::endl;
            return; // En caso de que no, se sale de la función
        }

        // Crear filtro para encontrar la publicación
        document filtro{};
        filtro << "autor" << autor
               << "fecha" << fecha;

        // Crear documento para la marcar/desmarcar como destacada
        document update{};
        update << "$set" << open_document << "destacada" << destacada << close_document;

        // Realizar la actualización en la colección
        collection.update_one(filtro.view(), update.view());

        std::cout << "Publicación marcada/desmarcada como destacada correctamente." << std::endl;

    } catch(const std::exception& e) {
        // Manejo de errores en caso de fallo al actualizar
        std::cerr << "Error al marcar/desmarcar la publicación como destacada: " << e.what() << std::endl;
    }
}

bool verificarFormatoFecha(const std::string& fecha) {
    std::regex formatoFecha("\\d{4}-\\d{2}-\\d{2}"); // Formato de regex para validar la fecha (YYYY-MM-DD)
    return std::regex_match(fecha, formatoFecha); // Retornar si hubo match
}

bool verificarPublicacionExiste(mongocxx::collection& collection, const std::string& autor, const std::string& fecha) {
    // Crear documento de filtro
    document filter{};
    filter << "autor" << autor << "fecha" << fecha; // Filtrar por autor y fecha

    // Buscar en la colección con base en el filtro
    auto result = collection.find_one(filter.view());

    // Retornar si hubo resultado o no
    return result ? true : false; // Uso de operador ternario para validar la salida
}