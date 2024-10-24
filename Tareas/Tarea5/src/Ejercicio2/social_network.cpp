#include "social_network.hpp"
#include <regex>

using namespace bsoncxx::builder::stream;
using bsoncxx::builder::stream::document;

void insertarPublicacion(mongocxx::collection& collection, const std::string& autor, const std::string& contenido, const std::string& fecha) {
    try {
        document publicacion{};
        publicacion << "autor" << autor
                    << "contenido" << contenido
                    << "fecha" << fecha
                    << "comentarios" << open_array << close_array
                    << "destacada" << false;
        collection.insert_one(publicacion.view());
        std::cout << "Publicación insertada correctamente en la base de datos." << std::endl;
    } catch(const std::exception& e) {
        std::cerr << "Error al insertar la publicación: " << e.what() << std::endl;
    }
}

void consultarPublicaciones(mongocxx::collection& collection) {
    try {
        auto cursor = collection.find({});

        for (auto&& doc : cursor) {
            std::cout << bsoncxx::to_json(doc) << std::endl;
        }
    } catch(const std::exception& e) {
        std::cerr << "Error al consultar publicaciones: " << e.what() << std::endl;
    }
}

void consultarPublicacionesPorAutor(mongocxx::collection& collection, const std::string& autor) {
    try {
        document filtro{};
        filtro << "autor" << autor;

        auto cursor = collection.find(filtro.view());

        for (auto&& doc : cursor) {
            std::cout << bsoncxx::to_json(doc) << std::endl;
        }
    } catch(const std::exception& e) {
        std::cerr << "Error al consultar por autor: " << e.what() << '\n';
    }   
}

void consultarPublicacionesPorFecha(mongocxx::collection& collection) {
    try {
        document sortOptions{};
        sortOptions << "fecha" << -1;
        
        auto cursor = collection.find({}, mongocxx::options::find{}.sort(sortOptions.view()));
        
        for (auto&& doc : cursor) {
            std::cout << bsoncxx::to_json(doc) << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error al consultar publicaciones por fecha: " << e.what() << std::endl;
    }
}

void agregarComentario(mongocxx::collection& collection, const std::string& autor, const std::string& fecha, const std::string& usuario, const std::string& comentario, const std::string& fechaComentario) {
    try {
        document filtro{};
        filtro << "autor" << autor
               << "fecha" << fecha;
            
        document docComentario{};
        docComentario << "usuario" << usuario
                      << "comentario" << comentario
                      << "fecha_comentario" << fechaComentario;
        
        document update{};
        update << "$push" << open_document << "comentarios" << docComentario << close_document;

        collection.update_one(filtro.view(), update.view());
        
        std::cout << "Comentario agregado correctamente." << std::endl;

    } catch(const std::exception& e) {
        std::cerr << "Error al agregar comentario: " << e.what() << '\n';
    }
}

void actualizarPublicacion(mongocxx::collection& collection, const std::string& autor, const std::string& fecha, const std::string& nuevoContenido) {
    try {
        document filtro{};
        filtro << "autor" << autor
               << "fecha" << fecha;
        
        document update{};
        update << "$set" << open_document << "contenido" << nuevoContenido << close_document;

        collection.update_one(filtro.view(), update.view());

        std::cout << "Publicación actualizada correctamente." << std::endl;

    } catch(const std::exception& e) {
        std::cerr << "Error al actualizar la publicación: " << e.what() << '\n';
    }
}

void eliminarPublicacion(mongocxx::collection& collection, const std::string& autor, const std::string& fecha) {
    try {
        document filtro{};
        filtro << "autor" << autor
               << "fecha" << fecha;

        collection.delete_one(filtro.view());

        std::cout << "Publicación eliminada correctamente." << std::endl;

    } catch(const std::exception& e) {
        std::cerr << "Error al eliminar la publicación: " << e.what() << std::endl;
    }
}

void marcarDestacada(mongocxx::collection& collection, const std::string& autor, const std::string& fecha, bool destacada) {
    try {
        document filtro{};
        filtro << "autor" << autor
               << "fecha" << fecha;

        document update{};
        update << "$set" << open_document << "destacada" << destacada << close_document;

        collection.update_one(filtro.view(), update.view());

        std::cout << "Publicación marcada/desmarcada como destacada correctamente." << std::endl;

    } catch(const std::exception& e) {
        std::cerr << "Error al marcar/desmarcar la publicación como destacada: " << e.what() << std::endl;
    }
}

bool verificarFormatoFecha(const std::string& fecha) {
    std::regex formatoFecha("\\d{4}-\\d{2}-\\d{2}");
    return std::regex_match(fecha, formatoFecha);
}