#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include <fstream>
#include "Student.h"
#include "Grade.h"

using namespace std;

class FileManager {
private:
    static const string ARCHIVO_ESTUDIANTES;
    static const string ARCHIVO_NOTAS;
    static const char SEPARADOR = '|';

public:
    // Constructor
    FileManager();

    // Operaciones con archivos de estudiantes
    bool cargarEstudiantes(vector<Student>& estudiantes);
    bool guardarEstudiantes(const vector<Student>& estudiantes);
    bool agregarEstudiante(const Student& estudiante);
    bool eliminarEstudiante(const string& cedula);
    bool modificarEstudiante(const Student& estudiante);

    // Operaciones con archivos de notas
    bool cargarNotas(vector<Grade>& notas);
    bool guardarNotas(const vector<Grade>& notas);
    bool agregarNota(const Grade& nota);
    bool eliminarNotasEstudiante(const string& cedula);
    bool modificarNota(const Grade& nota);

    // Operaciones generales
    bool respaldarArchivos();
    bool restaurarArchivos();
    bool existeArchivo(const string& nombreArchivo);
    bool crearArchivosVacios();

    // Métodos de utilidad
    string construirLineaEstudiante(const Student& estudiante);
    string construirLineaNota(const Grade& nota);
    Student parsearLineaEstudiante(const string& linea);
    Grade parsearLineaNota(const string& linea);

    // Métodos para validación de archivos
    bool validarIntegridadArchivos();
    bool repararArchivos();

    // Estadísticas de archivos
    int contarEstudiantes();
    int contarNotas();
    int contarNotasEstudiante(const string& cedula);

    // Manejo de errores
    string obtenerUltimoError() const;
    void limpiarError();

private:
    string ultimoError;
    
    // Métodos auxiliares privados
    bool escribirLinea(ofstream& archivo, const string& linea);
    bool leerArchivo(const string& nombreArchivo, vector<string>& lineas);
    bool escribirArchivo(const string& nombreArchivo, const vector<string>& lineas);
    vector<string> dividirLinea(const string& linea, char separador);
    void establecerError(const string& mensaje);
};

#endif // FILEMANAGER_H 