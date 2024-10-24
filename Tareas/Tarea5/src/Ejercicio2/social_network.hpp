
#ifndef SOCIAL_NETWORK_HPP
#define SOCIAL_NETWORK_HPP

#include <iostream>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <string>

void insertarPublicacion(mongocxx::collection& collection, const std::string& autor, const std::string& contenido, const std::string& fecha);

void consultarPublicaciones(mongocxx::collection& collection);

void consultarPublicacionesPorAutor(mongocxx::collection& collection, std::string& autor);

void consultarPublicacionesPorFecha(mongocxx::collection& collection);

void agregarComentario(mongocxx::collection& collection, const std::string& autor, const std::string& fecha, const std::string& usuario, const std::string& comentario, const std::string& fechaComentario);

void actualizarPublicacion(mongocxx::collection& collection, const std::string& autor, const std::string& fecha, const std::string& nuevoContenido);

void eliminarPublicacion(mongocxx::collection& collection, const std::string& autor, const std::string& fecha);

void marcarDestacada(mongocxx::collection& collection, const std::string& autor, const std::string& fecha, bool destacada);

bool verificarFormatoFecha(const std::string& fecha);

#endif // SOCIAL_NETWORK_HPP