#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
#include <vector>

using namespace std;

class Validator {
public:
    // Validación de cédula
    static bool validarCedula(const string& cedula);
    static bool esCedulaUnica(const string& cedula, const vector<class Student>& estudiantes);
    static bool esSoloNumeros(const string& str);
    
    // Validación de datos personales
    static bool validarEdad(int edad);
    static bool validarNombre(const string& nombre);
    static bool validarGenero(const string& genero);
    
    // Validación de notas
    static bool validarNota(double nota);
    static bool validarPromedio(double promedio);
    
    // Validación de respuestas S/N
    static bool validarRespuestaSN(const string& respuesta);
    static char normalizarRespuestaSN(const string& respuesta);
    
    // Validación de campos vacíos
    static bool esCampoVacio(const string& campo);
    static bool esNumeroValido(const string& str);
    static bool esNumeroDecimalValido(const string& str);
    
    // Validación de menú
    static bool validarOpcionMenu(int opcion, int minimo, int maximo);
    
    // Métodos de limpieza y normalización
    static string limpiarTexto(const string& texto);
    static string convertirAMayusculas(const string& texto);
    static string convertirAMinusculas(const string& texto);
    
    // Constantes para validación
    static const int CEDULA_LONGITUD = 10;
    static const int EDAD_MINIMA = 18;
    static const int EDAD_MAXIMA = 100;
    static const double NOTA_MINIMA;
    static const double NOTA_MAXIMA;
    static const double PROMEDIO_APROBADO;
    static const double PROMEDIO_REPOSICION;
    
    // Mensajes de error
    static string obtenerMensajeErrorCedula();
    static string obtenerMensajeErrorEdad();
    static string obtenerMensajeErrorNota();
    static string obtenerMensajeErrorCampoVacio();
    static string obtenerMensajeErrorOpcionInvalida();

private:
    // Constructor privado para evitar instanciación
    Validator() {}
};

#endif // VALIDATOR_H 