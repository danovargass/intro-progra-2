#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include <string>
#include <vector>
#include "Student.h"
#include "Grade.h"

using namespace std;

class MenuManager {
public:
    // Constructor
    MenuManager();

    // Menús principales
    void mostrarMenuPrincipal();
    void mostrarEncabezado();
    void mostrarPiePrograma();

    // Menús de entrada de datos
    int solicitarOpcionMenu();
    string solicitarCedula();
    string solicitarNombre();
    string solicitarApellido();
    string solicitarProvincia();
    string solicitarCanton();
    string solicitarDistrito();
    int solicitarEdad();
    string solicitarGenero();
    string solicitarMateria();
    double solicitarNota(const string& tipoNota);

    // Menús de confirmación
    bool confirmarSalida();
    bool confirmarEliminacion(const string& cedula);
    bool volverMenuPrincipal();
    bool deseaContinuar(const string& mensaje = "¿Desea continuar?");

    // Menús de selección
    int seleccionarEstudiante(const vector<Student>& estudiantes);
    int seleccionarMateria(const vector<Grade>& notas, const string& cedula);
    string seleccionarGenero();

    // Mostrar información
    void mostrarEstudiante(const Student& estudiante);
    void mostrarNota(const Grade& nota);
    void mostrarListaEstudiantes(const vector<Student>& estudiantes);
    void mostrarListaNotas(const vector<Grade>& notas);
    void mostrarReporte(const vector<Student>& estudiantes, const vector<Grade>& notas);

    // Mensajes del sistema
    void mostrarMensaje(const string& mensaje);
    void mostrarError(const string& error);
    void mostrarExito(const string& mensaje);
    void mostrarAdvertencia(const string& advertencia);

    // Utilidades de pantalla
    void limpiarPantalla();
    void pausar();
    void mostrarLinea(char caracter = '=', int longitud = 50);
    void mostrarSeparador();

    // Entrada de datos con validación
    string leerTexto(const string& prompt, bool permitirVacio = false);
    int leerEntero(const string& prompt, int minimo = 0, int maximo = 999999);
    double leerDecimal(const string& prompt, double minimo = 0.0, double maximo = 100.0);
    char leerRespuestaSN(const string& prompt);

    // Formateo de datos
    string formatearCedula(const string& cedula);
    string formatearNota(double nota);
    string formatearPromedio(double promedio);
    string formatearEstado(const string& estado);

private:
    // Constantes para formato
    static const int ANCHO_PANTALLA = 80;
    static const int ANCHO_MENU = 50;
    static const char CHAR_BORDE = '=';
    static const char CHAR_SEPARADOR = '-';

    // Métodos auxiliares privados
    string centrarTexto(const string& texto, int ancho);
    string rellenarTexto(const string& texto, int ancho, char relleno = ' ');
    void mostrarMarcoSuperior();
    void mostrarMarcoInferior();
    bool esEntradaValida(const string& entrada);
};

#endif // MENUMANAGER_H 