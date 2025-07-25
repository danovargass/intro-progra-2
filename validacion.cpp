#include <iostream>
#include <fstream>
#include "validacion.h"

bool estudianteExiste(int cedula){
    // funcion valida si el archivo, de estar abierto, contiene la cedula indicada
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
    // funcion manipulable para validar un valor ingresado por un usuario dentro de un rango predefinido
    try {
        if (valor >= min && valor <= max) {
            return valor;
        }
        else{
            return 0;
        }
    } catch (const std::invalid_argument& e){
        cout << "Opción inválida. Opciones válidas: " << min << " a " << max << " \n" << endl;
        return 0;
    }
}

bool validarCedula(string cedula){
    // funcion que valida el número de cédula tiene 10 dígitos exactamente y únicamente números
    try {
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
            cout << "Opción inválida. La cédula debe tener 10 dígitos \n" << endl;
            return false;
        }
}

bool validarEdad(int edad){
    // validación específica para rango de edad predefinido
    try {
        if(edad < 18 && edad >= 100){
            cout << "La edad debe ser entre 18 y 99 años \n" << endl;
            return false;
        }
        return true;
    } catch (const std::invalid_argument& e){
        cout << "Opción inválida. La edad debe ser entre 18 y 99 años \n" << endl;
        return false;
    }
}

bool validarNota(float nota){
    // validación de notas dentro del rango esperado
    try {
        if(nota < 0.0 && nota > 100.0){
            cout << "La nota debe ser entre 0 y 100 \n" << endl;
            return false;
        }
        return true;
    } catch (const std::invalid_argument& e){
        cout << "Opción inválida. La nota debe ser entre 0 y 100 \n" << endl;
        return false;
    }
}

char validarGenero(char genero){
    // validación de género predefinido con control de mayúsculas y minúsculas
    try {
        if(genero != 'M' && genero != 'F' && genero != 'm' && genero != 'f'){
            cout << "El género debe ser M o F \n" << endl;
            return '\0';
        } else {
            return toupper(genero);
        }
    } catch (const std::invalid_argument& e){
        cout << "Opción inválida. El género debe ser M o F \n" << endl;
        return '\0';
    }
}