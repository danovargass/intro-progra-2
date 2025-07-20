#include "estudiante.h"
#include <iostream>
#include <fstream>

using namespace std;
Estudiante estudiante;

void registrarEstudiante(){
    cout << "Ingrese el nombre del estudiante: ";
    cin >> estudiante.nombre;
    cout << "Ingrese el apellido del estudiante: ";
    cin >> estudiante.apellido;
    cout << "Ingrese la edad del estudiante: ";
    cin >> estudiante.edad;
    cout << "Ingrese el lugar de residencia del estudiante: ";
    cin >> estudiante.lugar_residencia;
    cout << "Ingrese la cedula del estudiante: ";
    cin >> estudiante.cedula;

    guardarEstudiante(estudiante);
}

void guardarEstudiante(const Estudiante& estudiante){
    ofstream archivoEstudiantes("estudiantes.txt", ios::app);
    if (archivoEstudiantes.is_open()) {
        archivoEstudiantes << estudiante.nombre << ","
                          << estudiante.apellido << ","
                          << estudiante.edad << ","
                          << estudiante.lugar_residencia << ","
                          << estudiante.cedula << endl;
        archivoEstudiantes.close();
        cout << "Estudiante guardado exitosamente!" << endl;
    } else {
        cout << "Error al abrir el archivo!" << endl;
    }
}