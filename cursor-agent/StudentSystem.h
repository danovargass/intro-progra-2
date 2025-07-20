#ifndef STUDENTSYSTEM_H
#define STUDENTSYSTEM_H

#include <vector>
#include <memory>
#include "Student.h"
#include "Grade.h"
#include "FileManager.h"
#include "MenuManager.h"
#include "Validator.h"

using namespace std;

class StudentSystem {
private:
    vector<Student> estudiantes;
    vector<Grade> notas;
    
    // Componentes del sistema
    unique_ptr<FileManager> fileManager;
    unique_ptr<MenuManager> menuManager;
    
    bool sistemaInicializado;

public:
    // Constructor y destructor
    StudentSystem();
    ~StudentSystem();

    // Inicialización del sistema
    bool inicializar();
    void finalizar();

    // Método principal de ejecución
    void ejecutar();

    // Operaciones principales del menú
    void registrarEstudiante();
    void ingresarCalificaciones();
    void modificarDatosEstudiante();
    void modificarNotas();
    void eliminarEstudiante();
    void generarReporte();

    // Operaciones de búsqueda
    Student* buscarEstudiante(const string& cedula);
    vector<Grade*> buscarNotasEstudiante(const string& cedula);
    bool existeEstudiante(const string& cedula);

    // Operaciones de datos
    bool agregarEstudiante(const Student& estudiante);
    bool agregarNota(const Grade& nota);
    bool actualizarEstudiante(const Student& estudiante);
    bool actualizarNota(const Grade& nota);
    bool eliminarDatosEstudiante(const string& cedula);

    // Validaciones del sistema
    bool validarCedulaUnica(const string& cedula);
    bool validarDatosEstudiante(const Student& estudiante);
    bool validarDatosNota(const Grade& nota);

    // Estadísticas y reportes
    int contarEstudiantes() const;
    int contarNotas() const;
    int contarNotasEstudiante(const string& cedula) const;
    double promedioGeneralEstudiante(const string& cedula) const;

    // Operaciones de archivo
    bool cargarDatos();
    bool guardarDatos();
    bool respaldarDatos();

    // Estado del sistema
    bool estaSistemaInicializado() const;
    string obtenerEstadoSistema() const;

private:
    // Métodos auxiliares privados
    void inicializarComponentes();
    bool verificarIntegridadDatos();
    void limpiarDatos();
    
    // Métodos de entrada de datos
    Student solicitarDatosEstudiante();
    Grade solicitarDatosNota(const string& cedula);
    
    // Métodos de modificación
    void procesarModificacionEstudiante(Student& estudiante);
    void procesarModificacionNota(Grade& nota);
    
    // Métodos de validación interna
    bool validarEstadoSistema();
    bool validarOperacion(const string& operacion);
    
    // Manejo de errores
    void manejarError(const string& error);
    void registrarOperacion(const string& operacion);
};

#endif // STUDENTSYSTEM_H 