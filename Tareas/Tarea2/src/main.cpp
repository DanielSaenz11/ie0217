/**
 * @file main.cpp
 * @brief Archivo que corresponde al punto de entrada de ejecución del programa.
 * 
 * @details En este source file, se encuentra la función main(), la cual corresponde al punto de entrada de ejecución
 * del programa. Además, se muestra el menú del programa, valida las opciones ingresadas por el usuario e integra
 * el funcionamiento de las clases creadas para que la tienda funcione.
 * 
 * Software bajo la licencia de MIT.
 * En términos generales, se concede permiso para utilizar este Software sin ninguna restricción, pero se proporciona sin
 * ninguna garantía. 
 * El aviso de copyright anterior y este aviso de permiso deberán incluirse en todas
 * las copias o partes sustanciales del Software.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @date 06/09/2024
 */

#include <limits> // Para std::numeric_limits
#include "Tienda.hpp" // Declaración de la clase Tienda
#include "ProductoDigital.hpp" // Declaración de la clase ProductoDigital
#include "ProductoFisico.hpp" // Declaración de la clase ProductoFisico
#include "ClientePremium.hpp" // Declaración de la clase ClientePremium
#include "ClienteRegular.hpp" // Declaración de la clase ClienteRegular

using namespace std;

/**
 * @enum OpcionesMenu
 * @brief Contiene las opciones del menú del programa.
 */
enum OpcionesMenu {
    OPT_AGREGAR_PRODUCTO = 1,
    OPT_REGISTRAR_CLIENTE,
    OPT_PRODUCTO_CARRITO,
    OPT_PROCESAR_COMPRA,
    OPT_SALIR
};

/**
 * @enum TipoProducto
 * @brief Contiene las opciones para el tipo de producto
 * 
 * 1 - Digital
 * 
 * 2 - Fisico
 */
enum TipoProducto {
    DIGITAL = 1,
    FISICO
};

/**
 * @enum TipoCliente
 * @brief Contiene las opciones para el tipo de cliente
 * 
 * 1 - Regular
 * 
 * 2 - Premium
 */
enum TipoCliente {
    REGULAR = 1,
    PREMIUM
};

/**
 * @brief Punto de entrada principal del programa.
 * 
 * Esta función inicializa el programa y gestiona el menú del programa. Además, se encarga
 * del llamado de las funciones miembro de las clases.
 * 
 * @return Código de estado del programa.
 */
int main() {
    // Declaración de instancia de clase Tienda
    Tienda tienda;

    // Opcion escogida por el usuario para el menú
    int opcion;

    // Ciclo do-while para mostrar el menú hasta que se ingrese la opción de salida
    do {
        // Imprimir el menú
        cout << "Sistema de Gestión de Tienda en Línea" << endl;
        cout << "1. Agregar producto" << endl;
        cout << "2. Registrar cliente" << endl;
        cout << "3. Agregar producto al carrito" << endl;
        cout << "4. Procesar compra" << endl;
        cout << "5. Salir" << endl;

        // Input de la opción escogida
        cin >> opcion;

        // Switch-case para validar la opción ingresada
        switch (opcion) {
            case OPT_AGREGAR_PRODUCTO:
            {
                // Declaracion de variables requeridas para agregar un producto
                string nombreProducto, id;
                double precio, peso;
                int tipoProducto;

                /* Ingreso de datos para registrar el producto */

                cout << "Seleccione el tipo de producto (1: Digital, 2: Físico): ";
                cin >> tipoProducto;

                cout << "Nombre del producto: ";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(cin, nombreProducto); // Leer línea

                cout << "Precio: ";
                cin >> precio;

                // Caso en que el producto es digital
                if (tipoProducto == DIGITAL) {
                    // Ingreso del ID del producto digital
                    cout << "ID: ";
                    cin >> id;

                    // Agregar nuevo producto digital a la tienda
                    tienda.agregarProducto(new ProductoDigital(nombreProducto, precio, id));
                }
                // Caso en que el producto es fisico
                else if (tipoProducto == FISICO)
                {
                    // Ingreso de peso del producto fisico
                    cout << "Peso (kg): ";
                    cin >> peso;

                    // Agregar nuevo producto fisico a la tienda
                    tienda.agregarProducto(new ProductoFisico(nombreProducto, precio, peso));
                }

                break;
            }
            case OPT_REGISTRAR_CLIENTE:
            {
                // Declaración de variables requeridas para agregar cliente
                string nombreCliente;
                double descuento;
                int tipoCliente;

                /* Ingreso de datos para registrar cliente */

                cout << "Seleccione el tipo de cliente (1: Regular, 2: Premium): ";
                cin >> tipoCliente;

                cout << "Nombre del cliente: ";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(cin, nombreCliente); // Leer línea

                // Caso en que el tipo de cliente es regular
                if (tipoCliente == REGULAR) {
                    tienda.agregarCliente(new ClienteRegular(nombreCliente)); // No se requiere descuento
                }
                // Caso en que el tipo de cliente es premium
                else if (tipoCliente == PREMIUM) {
                    // Ingreso del descuento del cliente premium
                    cout << "Porcentaje de descuento para cliente premium: ";
                    cin >> descuento;
                    descuento /= 100.0; // Convertir porcentaje a proporción

                    tienda.agregarCliente(new ClientePremium(nombreCliente, descuento)); // Agregar cliente a vector
                }

                break;
            }
            case OPT_PRODUCTO_CARRITO:
            {
                // Declaración de variables requeridas para agregar un producto al carrito de un cliente
                string nombreCliente, nombreProducto;

                // Ingreso de los datos del cliente
                cout << "Nombre del cliente: ";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar buffer de entrada
                getline(cin, nombreCliente); // Leer línea

                // Se busca el cliente en el vector de clientes guardados
                Cliente* cliente = tienda.buscarCliente(nombreCliente);

                if (cliente == nullptr) break; // Si no existe, se sale

                // Ingreso de los datos del producto
                cout << "Nombre del producto a agregar al carrito: ";
                getline(cin, nombreProducto); // Leer línea

                // Se busca el producto en el vector productosDisponibles
                Producto* producto = tienda.buscarProducto(nombreProducto);

                if (producto == nullptr) break; // Si no existe, se sale

                // Se agrega el producto al carrito del cliente
                cliente->agregarProducto(producto);

                // Imprimir mensaje de la acción
                cout << "Producto " << nombreProducto << " agregado al carrito de " << nombreCliente << endl;

                break;
            }
            case OPT_PROCESAR_COMPRA:
            {
                // Declaración de variable de nombreCliente
                string nombreCliente;

                // Ingreso del nombre del cliente
                cout << "Nombre del cliente: ";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar buffer de entrada
                getline(cin, nombreCliente); // Leer línea

                // Se procesa la compra del cliente
                tienda.procesarCompra(nombreCliente);

                break;
            }
            case OPT_SALIR:
            {   
                // Salir del programa
                cout << "Saliendo del programa..." << endl;
                break;
            }
            default:
            {
                cout << "Opción inválida. Intente de nuevo con una opción de las que se muestra en el menú." << endl;
                break;
            }
        }
        
    } while(opcion != OPT_SALIR);

    return 0;
}