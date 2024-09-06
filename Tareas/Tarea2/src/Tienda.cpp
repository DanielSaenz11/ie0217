/**
 * @file Tienda.cpp
 * @brief Archivo que contiene la implementación de los métodos de la clase Tienda.
 * 
 * @details En este source file se incluye la definición del destructor de la clase Tienda, así como
 * los métodos para agregar un producto, agregar un cliente, procesar la compra del cliente, buscar
 * un cliente y un producto dentro de los vectores designados para almacenarlos.
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

#include "Tienda.hpp"

using namespace std;

// Destructor de la clase Tienda
Tienda::~Tienda() {
    // Recorre el vector de productosDisponibles y libera cada producto almacenado
    for (Producto *producto : productosDisponibles) {
        delete producto;
    }

    // Recorre el vector de clientes y libera la memoria de cada cliente
    for (Cliente *cliente : clientes) {
        delete cliente;
    }
}

void Tienda::agregarProducto(Producto *producto) {
    productosDisponibles.push_back(producto); // Agrega al final del vector el nuevo producto
}

void Tienda::agregarCliente(Cliente *cliente) {
    clientes.push_back(cliente); // Agrega al final del vector el nuevo cliente
}

void Tienda::procesarCompra(const string &nombreCliente) const {
    // Llamado de la funcion buscarCliente() con el nombre del cliente para procesar la compra
    Cliente* cliente = buscarCliente(nombreCliente);

    // Si el puntero es distinto de nullptr
    if (cliente) {

        // Cálculo del precio total a pagar
        double total = cliente->calcularTotal();

        // Aplicar el descuento al precio total (si aplica)
        double totalConDescuento = cliente->aplicarDescuento(total);

        // Imprimir información
        cout << "Cliente: " << nombreCliente << endl;
        cout << "Total sin descuento: $" << total << endl;
        cout << "Total con descuento: $" << totalConDescuento << endl;
        cout << "Productos en el carrito:" << endl;

        // Mostrar la información de cada producto en el vector carrito
        for (const Producto* producto : cliente->getCarrito()) {
            cout << "Producto: " << producto->getNombre() << ", Precio: $" << producto->getPrecio() << endl;
        }
    }
}

Cliente* Tienda::buscarCliente(const std::string &nombreCliente) const {
    
    // Inicializar cliente como un nullptr
    Cliente* cliente = nullptr;

    // Recorrer el vector de clientes y determinar si hay coincidencia entre el nombre y un cliente registrado
    for (Cliente* c : clientes) {
        if (c->getNombre() == nombreCliente) {
            cliente = c; // Se asigna cliente como el cliente cuyo nombre coincide con el buscado
            break;
        }
    }

    // Si no hubo coincidencia, se muestra un mensaje que lo indica
    if (cliente == nullptr) {
        cout << "Cliente no encontrado." << endl;
    }

    // Retorno del puntero de tipo Cliente
    return cliente;
}

Producto* Tienda::buscarProducto(const std::string &nombreProducto) const {
    
    // Inicializar producto como nullptr
    Producto* producto = nullptr;

    // Recorrido del vector productosDisponibles para ver si hay coincidencia
    for (Producto* p : productosDisponibles) {
        if (p->getNombre() == nombreProducto) {
            producto = p; // Se asigna producto como el producto cuyo nombre coincide
            break;
        }
    }

    // Si no hubo coincidencia, se muestra un mensaje que lo indica
    if (producto == nullptr) {
        cout << "Producto no encontrado." << endl;
    }

    // Retorno del puntero de tipo Producto
    return producto;
}