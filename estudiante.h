#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>
using namespace std;

struct Estudiante{
    string nombre;
    string apellido;
    int edad;
    string lugar_residencia;
    string cedula;
};

void registrarEstudiante();
void guardarEstudiante(const Estudiante& estudiante);
void modificarEstudiante();
void eliminarEstudiante();

#endif