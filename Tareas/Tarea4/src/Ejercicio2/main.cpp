/**
 * @file main.cpp
 * @brief Programa principal que interactúa con el usuario para gestionar proyectos y tareas.
 *
 * @details Este programa presenta un menú interactivo que permite al usuario realizar diversas operaciones, como agregar
 * proyectos y tareas, eliminar proyectos y tareas, y mostrar información detallada de los proyectos. También, se realiza
 * la validación de las entradas del usuario para las funciones.
 * 
 * Software bajo la licencia de MIT.
 * En términos generales, se concede permiso para utilizar este Software sin ninguna restricción, pero se proporciona sin
 * ninguna garantía. 
 * El aviso de copyright anterior y este aviso de permiso deberán incluirse en todas
 * las copias o partes sustanciales del Software.
 * 
 * @author Daniel Alberto Sáenz Obando
 * @date 04/10/2024
 */


#include "Funciones.hpp"
#include "Tarea.hpp"
#include <iostream>

using namespace std;

/**
 * @enum OpcionesMenu
 * @brief Contiene las opciones del menú del programa.
 */
enum OpcionesMenu {
    OPT_NUEVO_PROYECTO = 1,
    OPT_NUEVA_TAREA,
    OPT_ELIMINAR_TAREA,
    OPT_ORDENAR_TAREAS,
    OPT_RESUMEN_PROYECTO,
    OPT_ELIMINAR_PROYECTO,
    OPT_SALIR
};


/**
 * @brief Función principal del programa.
 *
 * Controla el flujo del programa, mostrando un menú y ejecutando las operaciones
 * seleccionadas por el usuario hasta que decide salir.
 *
 * @return Código de estado de la ejecución.
 */
int main() {

    map<string, Proyecto> proyectos; // Mapa de objetos de la clase Proyecto (contienen tareas)
    int opcion; // Opción escogida en el menú

    do {
        // Imprimir menú en la consola
        cout << "\n*- Programa de Gestión de Proyectos de Construcción -*" << endl;
        cout << "1. Agregar un nuevo proyecto." << endl;
        cout << "2. Agregar una tarea a un proyecto existente." << endl;
        cout << "3. Eliminar una tarea de un proyecto." << endl;
        cout << "4. Ordenar tareas por costo, tiempo o prioridad." << endl;
        cout << "5. Mostrar el resumen de un proyecto." << endl;
        cout << "6. Eliminar un proyecto." << endl;
        cout << "7. Salir del programa." << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion; // Opción escogida

        try {
            // Opción 1: Agregar proyecto a mapa de proyectos
            if (opcion == OPT_NUEVO_PROYECTO) {
                string nombreProyecto; // String que almacena el nombre del proyecto ingresado

                // Input del nombre del proyecto
                cout << "Ingrese el nombre del proyecto: ";
                cin.ignore();
                getline(cin, nombreProyecto);

                // Agregar proyecto a mapa de proyectos a partir de su nombre
                agregar_proyecto(proyectos, nombreProyecto);
            }
            // Opción 2: Agregar nueva tarea a un proyecto
            else if (opcion == OPT_NUEVA_TAREA) {
                string nombreProyecto; // String que almacena el nombre del proyecto ingresado
                
                // Input del nombre del proyecto
                cout << "Ingrese el nombre del proyecto: ";
                cin.ignore();
                getline(cin, nombreProyecto);

                // Buscar proyecto en mapa de proyectos
                auto iterator = proyectos.find(nombreProyecto);
                if (iterator == proyectos.end()) {
                    throw runtime_error("El proyecto no fue encontrado."); // Mensaje de error si no fue encontrado
                }

                // Datos de la nueva tarea
                string nombreTarea;
                double costo;
                double tiempo_estimado;
                int prioridad;
                int tipoRecurso;

                // Input de los datos de la tarea
                cout << "Ingrese el nombre de la tarea: ";
                getline(cin, nombreTarea);
                cout << "Ingrese el costo de la tarea: ";
                cin >> costo;
                cout << "Ingrese el tiempo estimado de la tarea: ";
                cin >> tiempo_estimado;
                cout << "Ingrese la prioridad de la tarea (1-alta, 2-media, 3-baja): ";
                cin >> prioridad;

                cout << "Ingrese el tipo de recurso (1-materiales de construcción, 2-costo de contratación de personal): ";
                cin >> tipoRecurso;

                if (tipoRecurso == 1) {
                    int recursos; // Recurso de tipo int

                    // Input de cantidad de materiales de construcción
                    cout << "Ingrese la cantidad de materiales de construcción (int): ";
                    cin >> recursos;

                    // Construcción de objeto Tarea<int>
                    auto tarea = make_shared<Tarea<int>>(nombreTarea, costo, tiempo_estimado, prioridad, recursos);
                    
                    // Agregar tarea a proyecto ingresado
                    iterator->second.agregar_tarea(tarea);
                } else if (tipoRecurso == 2) {
                    double recursos; // Recurso de tipo double

                    // Input del costo de contratación de personal
                    cout << "Ingrese el costo de contratación de personal (double): ";
                    cin >> recursos;

                    // Construcción de objeto Tarea<double>
                    auto tarea = make_shared<Tarea<double>>(nombreTarea, costo, tiempo_estimado, prioridad, recursos);
                    
                    // Agregar tarea a proyecto ingresado
                    iterator->second.agregar_tarea(tarea);
                } else {
                    cout << "Tipo de recurso inválido." << endl;
                    continue; // Continuar ejecución de do-while
                }

                cout << "Tarea agregada exitosamente.\n";
            }
            // Opción 3: Eliminar una tarea
            else if (opcion == OPT_ELIMINAR_TAREA) {
                string nombreProyecto, nombreTarea; // String que almacena el nombre del proyecto y de la tarea

                // Input del nombre del proyecto
                cout << "Ingrese el nombre del proyecto: ";
                cin.ignore();
                getline(cin, nombreProyecto);

                // Buscar proyecto con nombre ingresado
                auto iterator = proyectos.find(nombreProyecto);
                if (iterator == proyectos.end()) {
                    throw runtime_error("El proyecto no fue encontrado."); // Error si no se encontró el proyecto
                }

                // Input del nombre de la tarea a eliminar
                cout << "Ingrese el nombre de la tarea a eliminar: ";
                getline(cin, nombreTarea);

                // Ejecutar el método de eliminar_tarea() en el proyecto
                iterator->second.eliminar_tarea(nombreTarea);

                cout << "Tarea " << nombreTarea << " eliminada exitosamente de " << nombreProyecto << endl;
            }
            // Opción 4: Ordenar tareas por criterio
            else if (opcion == OPT_ORDENAR_TAREAS) {
                string nombreProyecto; // String que almacena el nombre del proyecto ingresado

                // Input del nombre del proyecto
                cout << "Ingrese el nombre del proyecto: ";
                cin.ignore();
                getline(cin, nombreProyecto);

                // Llamado de función para mostrar las tareas a partir de un criterio
                mostrar_tareas_por_criterio(proyectos, nombreProyecto);
            }
            // Opción 5: Mostrar el resumen de un proyecto
            else if (opcion == OPT_RESUMEN_PROYECTO) {
                string nombreProyecto; // String que almacena el nombre del proyecto ingresado

                // Input del nombre del proyecto
                cout << "Ingrese el nombre del proyecto: ";
                cin.ignore();
                getline(cin, nombreProyecto);

                // Buscar proyecto con nombre ingresado
                auto it = proyectos.find(nombreProyecto);
                if (it == proyectos.end()) {
                    throw runtime_error("El proyecto no fue encontrado.");
                }

                // Ejecutar función miembro de mostrar un resumen
                it->second.mostrar_resumen_proyecto();
            }
            // Opción 6: Eliminar un proyecto
            else if (opcion == OPT_ELIMINAR_PROYECTO) {
                string nombreProyecto; // String que almacena el nombre del proyecto ingresado

                // Input del nombre del proyecto
                cout << "Ingrese el nombre del proyecto a eliminar: ";
                cin.ignore();
                getline(cin, nombreProyecto);

                // Llamado de función para eliminar un proyecto
                eliminar_proyecto(proyectos, nombreProyecto);
                cout << "Proyecto " << nombreProyecto << " eliminado exitosamente.\n";
            }
            // Opción 7: Salir del programa
            else if (opcion == OPT_SALIR) {
                cout << "Saliendo del programa..." << endl;
            }
            
        } catch (const exception& e) {
            // Mostrar mensaje de excepción atrapada
            cout << "Error: " << e.what() << endl;
        } catch (...) {
            cout << "Error imprevisto. Intente nuevamente." << endl;
        }

    } while (opcion != OPT_SALIR); // Condición de repetición de do-while loop

    return 0;
}