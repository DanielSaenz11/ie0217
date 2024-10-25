/**
 * @file social_network.hpp
 * @brief Archivo que contiene la declaración de las funciones para interactuar con la base de datos MongoDB.
 * 
 * @details Este archivo contiene la declaración de las funciones para insertar y consultar sobre las publicaciones,
 * agregar comentarios, actualizar el contenido de una publicación, eliminar una publicación y marcar como destacada.
 * Además, contiene el prototipo de funciones para validar la entrada de los datos ingresados por el usuario.
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

#ifndef SOCIAL_NETWORK_HPP
#define SOCIAL_NETWORK_HPP

#include <iostream>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <string>

/**
 * @brief Inserta una nueva publicación en la base de datos.
 * 
 * Crea un documento BSON con los detalles de la publicación y lo inserta en la colección MongoDB.
 * 
 * @param collection La colección donde se insertará la publicación.
 * @param autor El autor de la publicación.
 * @param contenido El contenido de la publicación.
 * @param fecha La fecha de la publicación en formato YYYY-MM-DD.
 * @return void
 */
void insertarPublicacion(mongocxx::collection& collection, const std::string& autor, const std::string& contenido, const std::string& fecha);

/**
 * @brief Consulta todas las publicaciones en la base de datos.
 * 
 * Recupera todos los documentos de la colección y los muestra en la consola.
 * 
 * @param collection La colección de la cual se consultarán las publicaciones.
 * @return void
 */
void consultarPublicaciones(mongocxx::collection& collection);

/**
 * @brief Consulta las publicaciones de un autor específico.
 * 
 * Recupera y muestra todas las publicaciones de un autor dado.
 * 
 * @param collection La colección de la cual se consultarán las publicaciones.
 * @param autor El autor cuyas publicaciones se desean consultar.
 * @return void
 */
void consultarPublicacionesPorAutor(mongocxx::collection& collection, const std::string& autor);

/**
 * @brief Consulta todas las publicaciones en orden cronológico.
 * 
 * Recupera todas las publicaciones y las muestra en orden cronológico (más recientes primero).
 * 
 * @param collection La colección de la cual se consultarán las publicaciones.
 * @return void
 */
void consultarPublicacionesPorFecha(mongocxx::collection& collection);

/**
 * @brief Agrega un comentario a una publicación existente.
 * 
 * Busca la publicación especificada por autor y fecha, y añade un comentario.
 * 
 * @param collection La colección donde se encuentra la publicación.
 * @param autor El autor de la publicación.
 * @param fecha La fecha de la publicación en formato YYYY-MM-DD.
 * @param usuario El usuario que realiza el comentario.
 * @param comentario El contenido del comentario.
 * @param fechaComentario La fecha del comentario en formato YYYY-MM-DD.
 * @return void
 */
void agregarComentario(mongocxx::collection& collection, const std::string& autor, const std::string& fecha, const std::string& usuario, const std::string& comentario, const std::string& fechaComentario);

/**
 * @brief Actualiza el contenido de una publicación existente.
 * 
 * Busca la publicación especificada por autor y fecha, y actualiza su contenido.
 * 
 * @param collection La colección donde se encuentra la publicación.
 * @param autor El autor de la publicación.
 * @param fecha La fecha de la publicación en formato YYYY-MM-DD.
 * @param nuevoContenido El nuevo contenido para la publicación.
 * @return void
 */
void actualizarPublicacion(mongocxx::collection& collection, const std::string& autor, const std::string& fecha, const std::string& nuevoContenido);

/**
 * @brief Elimina una publicación de la base de datos.
 * 
 * Busca y elimina la publicación especificada por autor y fecha.
 * 
 * @param collection La colección de la cual se eliminará la publicación.
 * @param autor El autor de la publicación.
 * @param fecha La fecha de la publicación en formato YYYY-MM-DD.
 * @return void
 */
void eliminarPublicacion(mongocxx::collection& collection, const std::string& autor, const std::string& fecha);

/**
 * @brief Marca o desmarca una publicación como destacada.
 * 
 * Busca la publicación especificada por autor y fecha, y cambia su estado de destacada.
 * 
 * @param collection La colección donde se encuentra la publicación.
 * @param autor El autor de la publicación.
 * @param fecha La fecha de la publicación en formato YYYY-MM-DD.
 * @param destacada Indica si la publicación debe ser marcada o desmarcada como destacada.
 * @return void
 */
void marcarDestacada(mongocxx::collection& collection, const std::string& autor, const std::string& fecha, bool destacada);

/**
 * @brief Verifica si el formato de la fecha es válido.
 * 
 * Verifica si la fecha ingresada cumple con el formato YYYY-MM-DD utilizando expresiones regulares.
 * 
 * @param fecha La fecha a verificar.
 * @return true si el formato es correcto, false en caso contrario.
 */
bool verificarFormatoFecha(const std::string& fecha);

/**
 * @brief Verifica si una publicación existe en la base de datos.
 * 
 * Busca la publicación especificada por autor y fecha.
 * 
 * @param collection La colección donde se encuentra la publicación.
 * @param autor El autor de la publicación.
 * @param fecha La fecha de la publicación en formato YYYY-MM-DD.
 * @return true si la publicación existe, false en caso contrario.
 */
bool verificarPublicacionExiste(mongocxx::collection& collection, const std::string& autor, const std::string& fecha);

#endif // SOCIAL_NETWORK_HPP