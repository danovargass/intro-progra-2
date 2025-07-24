#include <iostream>
#include <fstream>
#include "validacion.h"

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