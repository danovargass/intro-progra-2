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
    if (valor >= min && valor <= max) {
        return valor;
    }
    else{
        cout << "Opción seleccionada no es válida \n" << endl;
        return 0;
    }
}

char volverAlMenu(char respuesta_si_no){
    switch (respuesta_si_no){
    case 'S':
        cout << "Volviendo al menu principal! \n" << endl;
        return toupper(respuesta_si_no);
        break;
    case 'N':
        return toupper(respuesta_si_no);
        break;
    default:
        cout << "Opción no válida \n" << endl;
        return respuesta_si_no;
        break;
    }
}

bool validarCedula(string cedula){
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
}

bool validarEdad(int edad){
    if(edad < 18 && edad >= 100){
        cout << "La edad debe ser entre 18 y 99 años \n" << endl;
        return false;
    }
    return true;
}

bool validarNota(float nota){
    if(nota < 0.0 && nota > 100.0){
        cout << "La nota debe ser entre 0 y 100 \n" << endl;
        return false;
    }
    return true;
}

char validarGenero(char genero){
    if(genero != 'M' && genero != 'F'){
        cout << "El género debe ser M o F \n" << endl;
        return '\0';
    } else if (genero != 'm' && genero != 'f'){
        return toupper(genero);
    } else {
        return genero;
    }
}