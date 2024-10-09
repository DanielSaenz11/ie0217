#include <iostream>
#include <sqlite3.h>


static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        std::cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << std::endl;
    }
    return 0;
}

int main() {
    sqlite3* db;       // Handle para la conexión con la base de datos
    char* errMsg = 0;  // Mensaje de error
    int rc;            // Return code

    // Abre o crea la base de datos
    rc = sqlite3_open("inventario.db", &db);

    if (rc) {
        // No se pudo abrir/crear
        std::cerr << "No se pudo abrir la base de datos: " << sqlite3_errmsg(db) << std::endl;
        return (0);
    } else {
        // Se abrió/creó satisfactoriamente
        std::cout << "Base de datos abierta con éxito" << std::endl;
    }

    // --------------------------- Crea la tabla Productos ---------------------------
    const char* sql = "CREATE TABLE IF NOT EXISTS Productos ( "
                      "IDProducto INTEGER PRIMARY KEY AUTOINCREMENT," // Identificador del producto: Clave primaria
                      "NombreProducto TEXT NOT NULL, "                // Nombre del producto
                      "Cantidad INT NOT NULL, "                       // Cantidad del producto
                      "Precio REAL NOT NULL); ";                      // Precio del producto

    rc = sqlite3_exec(db, sql, callback, 0, &errMsg); // Ejecutar la creación de la tabla

    if (rc != SQLITE_OK) {
        // Código de retorno de error
        std::cerr << "Error al crear la tabla: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        // Tabla creada satisfactoriamente
        std::cout << "Tabla creada con éxito" << std::endl;
    }

    // --------------------------- Inserta datos en la tabla Productos ---------------------------
    const char* sqlInsert = "INSERT INTO Productos (NombreProducto, Cantidad, Precio) "
                            "VALUES ('Laptop', 10, 1000.50), " // Laptop
                            "('Teclado', 50, 20.99), "         // Teclado
                            "('Mouse', 30, 15.50); ";          // Mouse


    rc = sqlite3_exec(db, sqlInsert, callback, 0, &errMsg); // Ejecutar la inserción de los datos

    if (rc != SQLITE_OK) {
        // Código de retorno de error
        std::cerr << "Error al insertar datos: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    // --------------------------- Selecciona todos los productos de la tabla ---------------------------
    const char* sqlSelect = "SELECT * FROM Productos;";

    rc = sqlite3_exec(db, sqlSelect, callback, 0, &errMsg); // Ejecutar la selección de todos los datos
    
    if (rc != SQLITE_OK) {
        // Código de retorno de error
        std::cerr << "Error al consultar datos: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    // --------------------------- Actualizar la cantidad de Mouse a 25 ---------------------------
    const char* sqlUpdate = "UPDATE Productos SET Cantidad = 25 WHERE NombreProducto = 'Mouse';"; 

    rc = sqlite3_exec(db, sqlUpdate, callback, 0, &errMsg); // Ejecutar la actualización de la cantidad de Mouse a 25
    
    if (rc != SQLITE_OK) {
        // Código de retorno de error
        std::cerr << "Error actualizar datos: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    // --------------------------- Eliminar el producto Teclado ---------------------------
    const char* sqlDelete = "DELETE FROM Productos WHERE NombreProducto = 'Teclado';";

    rc = sqlite3_exec(db, sqlDelete, callback, 0, &errMsg); // Ejecutar la eliminación de Teclado
    
    if (rc != SQLITE_OK) {
        // Código de retorno de error
        std::cerr << "Error al eliminar datos: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    // --------------------------- Selecciona todos los productos después de las modificaciones ---------------------------
    std::cout << "\nBase de datos después de las modificaciones" << std::endl;

    rc = sqlite3_exec(db, sqlSelect, callback, 0, &errMsg); // Ejecutar la selección de todos los datos
    
    if (rc != SQLITE_OK) {
        // Código de retorno de error
        std::cerr << "Error al consultar datos: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    // Cierra la base de datos
    sqlite3_close(db);

    return 0;
}