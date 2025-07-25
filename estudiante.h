// archivo header para referenciar funciones
#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>
using namespace std;

struct Residencia{
    string provincia;
    string canton;
    string distrito;
};

struct Estudiante{
    int cedula;
    string nombre;
    string primer_apellido;
    string segundo_apellido;
    int edad;
    char genero;
    Residencia lugar_residencia;
};

void registrarEstudiante();
void guardarEstudiante(const Estudiante& estudiante);
void modificarEstudiante(int cedula);
void eliminarEstudiante(int cedula);

#endif