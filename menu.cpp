#include <iostream>
#include "menu.h"
#include "validacion.h"
#include <limits>

int menuPrincipal(int& opcion){
    // menú estático con validación de entradas definidas en main.cpp
    bool validando_entrada = false;

    while (!validando_entrada){
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

        if(cin.fail()){
            cout << "Recuerde que solo puede usar números dentro del rango como respuestas \n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            validando_entrada = true;
        }
    }
    
    int opcion_seleccionada = dentroDelRango(opcion, 1, 7);
    return opcion_seleccionada;
}

void limpiarPantalla(){
    // limpia la pantalla del menú para manejar únicamente un menú principal por interacción completada
    #ifdef _WIN32
        system("cls"); // contemplando que sea ejecutado en Windows
    #else
        system("clear");
    #endif
}

void confirmarVolverAlMenu(){
    // funcion pide confirmar si volver al menu principal luego de un error. solicita 2 veces enter dada las limitaciones de cin.ignore
    cout << "Presione Enter 2 veces para confirmar volver al menú principal \n" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    limpiarPantalla();
}

char volverAlMenu(char respuesta_si_no){
    // funcion que valida la respuesta del usuario para determinar si desea volver al menú principal con control de mayúsculas y minúsculas
    try{
        if (respuesta_si_no == 'S' || respuesta_si_no == 'N'){
            return respuesta_si_no;
        } else if (respuesta_si_no == 's' || respuesta_si_no == 'n'){
            return toupper(respuesta_si_no);
        } else {
            return '\0';
        }
    } catch (const std::invalid_argument& e){
        cout << "Opción inválida. Opciones válidas: S o N \n" << endl;
        return '\0';
    }
}