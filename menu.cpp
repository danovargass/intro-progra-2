#include <iostream>
#include "menu.h"
#include "validacion.h"
#include <limits>

int menuPrincipal(int& opcion){
    cout << "\n";
    cout << "|========================================================|\n";
    cout << "|         SISTEMA DE GESTIÓN DE ESTUDIANTES              |\n";
    cout << "|========================================================|\n";
    cout << "| 1. Ingresar Estudiante                                 |\n";
    cout << "| 2. Ingresar Calificaciones en distintas materias       |\n";
    cout << "| 3. Modificar Datos Estudiante                          |\n";  
    cout << "| 4. Modificar Registro de Notas por Estudiante          |\n"; 
    cout << "| 5. Eliminar Registro de Estudiante                     |\n"; 
    cout << "| 6. Reporte de Estudiantes, promedios y estado          |\n";
    cout << "| 7. Salir del programa                                  |\n";
    cout << "| Utilice los número (1 al 7) para la opción deseada.    |\n";
    cout << "|========================================================|\n";
    cin >> opcion;
    int opcion_seleccionada = dentroDelRango(opcion, 1, 7);
    return opcion_seleccionada;
}

void limpiarPantalla(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void confirmarVolverAlMenu(){
    cout << "\n\nPresione Enter para volver al menú principal..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    limpiarPantalla();
}

char volverAlMenu(char respuesta_si_no){
    try{
        if (respuesta_si_no == 'S' || respuesta_si_no == 'N'){
            return respuesta_si_no;
        } else if (respuesta_si_no == 's' || respuesta_si_no == 'n'){
            return toupper(respuesta_si_no);
        } else {
            cout << "Opción no válida \n" << endl;
            return '\0';
        }
    } catch (const std::invalid_argument& e){
        cout << "Recuerde que solo puede usar S o N como respuestas \n" << endl;
        return '\0';
    }
}