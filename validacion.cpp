#include <iostream>
#include <fstream>
#include "validacion.h"

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

bool estudianteExiste(int cedula){
    ifstream archivoEstudiantes("ESTUDIANTE.txt");
    if (archivoEstudiantes.is_open()) {
        string linea_del_archivo;
        while (getline(archivoEstudiantes, linea_del_archivo)) {
            if (linea_del_archivo.find(to_string(cedula)) != string::npos) {
                cout << "Estudiante existe! \n" << endl;
                archivoEstudiantes.close();
                return true;
            }
        }
        archivoEstudiantes.close();
        return false;
    }
    else{
        cout << "Estudiante no existe! \n" << endl;
        return false;
    }
}

int dentroDelRango(int& valor, int min, int max){
    try{
    if (valor >= min && valor <= max) {
        return valor;
    }
    else{
        cout << "Opción seleccionada no es válida \n" << endl;
        return 0;
    }
    } catch (const std::invalid_argument& e){
        cout << "Recuerde que solo puede usar números como respuestas \n" << endl;
        return 0;
    }
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

bool validarCedula(string cedula){
    try{
    if(cedula.length() != 10){
        cout << "La cédula debe tener 10 dígitos \n" << endl;
        return false;
    }
    for(char digito : cedula){
        if(!isdigit(digito)){
            cout << "La cédula solo debe contener números \n" << endl;
            return false;
        }
    }
    return true;
    } catch (const std::invalid_argument& e){
        cout << "Recuerde que solo puede usar números como respuestas \n" << endl;
        return false;
    }
}

bool validarEdad(int edad){
    try{
    if(edad < 18 && edad >= 100){
        cout << "La edad debe ser entre 18 y 99 años \n" << endl;
        return false;
    }
    return true;
    } catch (const std::invalid_argument& e){
        cout << "Recuerde que solo puede usar números como respuestas \n" << endl;
        return false;
    }
}

bool validarNota(float nota){
    try{
    if(nota < 0.0 && nota > 100.0){
        cout << "La nota debe ser entre 0 y 100 \n" << endl;
        return false;
    }
    return true;
    } catch (const std::invalid_argument& e){
        cout << "Recuerde que solo puede usar números con hasta 2 decimales como respuestas \n" << endl;
        return false;
    }
}

char validarGenero(char genero){
    try{
    if(genero != 'M' && genero != 'F'){
        cout << "El género debe ser M o F \n" << endl;
        return '\0';
    } else if (genero != 'm' && genero != 'f'){
        return toupper(genero);
    } else {
        return genero;
    }
    } catch (const std::invalid_argument& e){
        cout << "Recuerde que solo puede usar M o F como respuestas \n" << endl;
        return '\0';
    }
}