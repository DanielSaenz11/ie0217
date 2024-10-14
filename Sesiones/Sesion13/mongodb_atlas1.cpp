/*
Este archivo corresponde al mostrado en la presentación de la sesión 13 para MongoDB Atlas
*/

// Inclusión de bibliotecas utilizadas en el programa
#include <iostream>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>

int main() {

    // Crear una instancia de la base de datos
    mongocxx::instance instance{};

    // Reemplazar '<your-atlas-connection-string>' con la cadena de conexión de MongoDB Atlas
    mongocxx::client client{mongocxx::uri{"<your-atlas-connection-string>"}};

    auto db = client["mydatabase"]; // Nombre de la base de datos a utilizar
    auto collection = db["users"];  // Nombre de la colección a utilizar

    // Operaciones CRUD aquí

    std::cout << "Conectado a MongoDB Atlas!" << std::endl; // String para indicar la correcta conexión con el servidor

    return 0;
}