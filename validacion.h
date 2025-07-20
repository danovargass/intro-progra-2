#ifndef VALIDACION_H
#define VALIDACION_H

#include <string>
using namespace std;

void noVacio(string& valor);
void noLetras(string& valor);
void noCaracteresEspeciales(string& valor);
void noRepetidos(string& valor);
void fueraDeRango(int& valor, int min, int max);

#endif