#ifndef VALIDACION_H
#define VALIDACION_H

#include <string>
using namespace std;

bool estudianteExiste(int cedula);
void noVacio(string& valor);
void noLetras(string& valor);
void noCaracteresEspeciales(string& valor);
void noRepetidos(string& valor);
int dentroDelRango(int& valor, int min, int max);
char volverAlMenu(char respuesta_si_no);
bool validarCedula(string cedula);
bool validarEdad(int edad);
bool validarNota(float nota);

#endif