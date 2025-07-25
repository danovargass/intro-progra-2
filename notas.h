// archivo header para referenciar funciones
#ifndef NOTAS_H
#define NOTAS_H

#include <string>
#include <vector>
using namespace std;

struct Estudiante;

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
void generarReporte();
void cargarDatosEnMatriz();
void mostrarEncabezadoReporte();
void mostrarDatosEstudiantes();
vector<Estudiante> cargarEstudiantes();
Estudiante parsearLineaEstudiante(const string& linea);
Notas parsearLineaNota(const string& linea);
int contadorDeMaterias();

#endif