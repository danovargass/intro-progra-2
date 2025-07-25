// archivo header para referenciar funciones
#ifndef CONTROLADORENTRADAS_H
#define CONTROLADORENTRADAS_H

#include <iostream>
#include <string>
#include <limits>
#include <sstream>
using namespace std;

int intValido(string consultaAlUsuario);
string stringValido(string consultaAlUsuario);
char charValido(string consultaAlUsuario);
float floatValido(string consultaAlUsuario);

#endif