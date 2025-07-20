#ifndef NOTAS_H
#define NOTAS_H

#include <string>
using namespace std;

struct Notas{
    string materia;
    double nota1;
    double nota2;
    double nota3;
};

void registrarNotas();
void guardarNotas(const Notas& notas);
void modificarNotas();

#endif