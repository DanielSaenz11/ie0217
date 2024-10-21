#include "social_network.hpp"

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
        std::cout << "Publicación insertada correctamente en la base de datos" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error al insertar la publicación: " << e.what() << std::endl;
    }
}

void consultarPublicaciones(mongocxx::collection& collection) {
    try {
        auto cursor = collection.find({});

        for (auto&& doc : cursor) {
            std::cout << bsoncxx::to_json(doc) << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error al consultar publicaciones: " << e.what() << std::endl;
    }
}

void consultarPublicacionesPorAutor(mongocxx::collection& collection, const std::string& autor) {
    try
    {
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