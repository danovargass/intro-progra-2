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
        return respuesta_si_no;
        break;
    case 'N':
        return respuesta_si_no;
        break;
    default:
        cout << "Opción no válida \n" << endl;
        return respuesta_si_no;
        break;
    }
}