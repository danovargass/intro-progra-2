#ifndef NOTAS_H
#define NOTAS_H

#include <string>
using namespace std;

struct Notas{
    int cedula;
    string materia;
    float proyecto_uno;
    float proyecto_dos;
    float ensayo;
    float foro;
    float defensa;
    float promedio;
    string estado;
};

void ingresarCalificaciones();
float calcularPromedio(float proyecto_uno, float proyecto_dos, float ensayo, float foro, float defensa);
string estadoMateria(float promedio);
void guardarNotas(const Notas& notas);
void modificarNotas();
int bucleExisteEstudiante();

#endif