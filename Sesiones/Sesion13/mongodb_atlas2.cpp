/*
Programa sugerido en MongoDB Atlas para probar la conexión con el servidor
*/

// Inclusión de bibliotecas
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

int main() {
    try {
        // Crear una instancia
        mongocxx::instance inst{};

        // Configuración del URI para acceder a la base de datos
        const auto uri = mongocxx::uri{"<your-atlas-connection-string>"};

        // Establecer la versión de la API estable en el cliente
        mongocxx::options::client client_options;
        const auto api = mongocxx::options::server_api{mongocxx::options::server_api::version::k_version_1};
        client_options.server_api_opts(api);

        // Configurar la conexión y obtener un handle en la base de datos "admin"
        mongocxx::client conn{ uri, client_options };
        mongocxx::database db = conn["admin"];

        // Conectarse a la base de datos
        const auto ping_cmd = bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp("ping", 1));
        db.run_command(ping_cmd.view());
        std::cout << "Pinged your deployment. You successfully connected to MongoDB!" << std::endl;
    }
    catch (const std::exception& e) {
        // Manejar errores
        std::cout<< "Exception: " << e.what() << std::endl;
    }

    return 0;
}