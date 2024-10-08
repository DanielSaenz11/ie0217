/*
Este programa es utilizado para interactuar con SQLite

1) Se crea una base de datos llamada test.db (si no existe).
2) Se crea una tabla con el nombre COMPANY para almacenar los empleados de una empresa
3) Se insertan la información de los empleados en la tabla (poseen una llave primaria única -> ID)
4) Selecciona todo el contenido de la tabla y lo muestra en la terminal

Después de cada operación, se verifica con un if, si ocurrieron errores en la operación.
*/

#include <iostream>
#include <sqlite3.h>

using namespace std;

// Función callback para imprimir los resultados de las consultas
static int callback(void *data, int argc, char **argv, char **azColName) {
    // Interpretacion de las consultas
    for (int i = 0; i < argc; i++) {
        cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
    }

    return 0;
}

int main() {

    sqlite3 *db; // Puntero a la base de datos

    char *errMsg = 0; // Mensaje de error
    int rc; // Return code de las consultas
    const char* data = "Callback function called";

    // Abre la base de datos (la crea si no existe)
    rc = sqlite3_open("test.db", &db);

    // Verificar estado de apertura de base de datos
    if (rc) {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return (0);
    } else {
        cout << "Opened database successfully" << endl;
    }

    // Crea una tabla con las columnas ID, AGE, ADDRESS, SALARY
    const char *sql = "CREATE TABLE COMPANY("
                      "ID INT PRIMARY KEY NOT NULL, "
                      "NAME TEXT NOT NULL, "
                      "AGE INT NOT NULL, "
                      "ADDRESS CHAR(50), "
                      "SALARY REAL );";

    // Ejecutar la accion sql en la base de datos db
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);

    // Verificar estado de accion de crear tabla COMPANY
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl; // Imprimir mensaje de error
        sqlite3_free(errMsg); // Liberación con el mensaje de error
    } else {
        cout << "Table created successfully" << endl;
    }

    // Inserta datos en la tabla siguiendo el formato creado para ella
    sql = "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) "
          "VALUES (1, 'Paul', 32, 'California', 20000.00); "
          "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) "
          "VALUES (2, 'Allen', 25, 'Texas', 15000.00); "
          "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) "
          "VALUES (3, 'Teddy', 23, 'Norway', 20000.00); "
          "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) "
          "VALUES (4, 'Mark', 25, 'Rich-Mond', 65000.00); ";

    // Ejecuta los comandos
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);

    // Verificar estado de la accion de insertar elementos a la tabla COMPANY
    if (rc != SQLITE_OK) {
        cerr << "SQL Error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        cout << "Records created successfully" << endl;
    }

    // Seleccionar datos de la tabla COMPANY
    sql = "SELECT * FROM COMPANY";
    rc = sqlite3_exec(db, sql, callback, (void*)data, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL Error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        cout << "Operation done successfully" << endl;
    }

    // Cierra la base de datos
    sqlite3_close(db);

    return 0;
}