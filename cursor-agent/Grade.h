#ifndef GRADE_H
#define GRADE_H

#include <string>
#include <iostream>

using namespace std;

class Grade {
private:
    string cedula;         // Relación con estudiante
    string materia;        // Materia cursada
    double proyecto1;      // Peso: 1%
    double proyecto2;      // Peso: 2%
    double ensayo;         // Peso: 3%
    double foro;           // Peso: 1%
    double defensa;        // Peso: 3%
    double promedio;       // Calculado automáticamente
    string estado;         // Aprobó, Reposición, Reprobó

    // Constantes para los pesos
    static const double PESO_PROYECTO1;
    static const double PESO_PROYECTO2;
    static const double PESO_ENSAYO;
    static const double PESO_FORO;
    static const double PESO_DEFENSA;

public:
    // Constructores
    Grade();
    Grade(string cedula, string materia);
    Grade(string cedula, string materia, double p1, double p2, 
          double ensayo, double foro, double defensa);

    // Getters
    string getCedula() const;
    string getMateria() const;
    double getProyecto1() const;
    double getProyecto2() const;
    double getEnsayo() const;
    double getForo() const;
    double getDefensa() const;
    double getPromedio() const;
    string getEstado() const;

    // Setters
    void setCedula(const string& cedula);
    void setMateria(const string& materia);
    void setProyecto1(double nota);
    void setProyecto2(double nota);
    void setEnsayo(double nota);
    void setForo(double nota);
    void setDefensa(double nota);
    void setTodasLasNotas(double p1, double p2, double ensayo, double foro, double defensa);

    // Métodos de cálculo
    void calcularPromedio();
    void determinarEstado();
    void actualizarCalificacion();  // Calcula promedio y estado

    // Métodos de utilidad
    void mostrarNotas() const;
    void mostrarResumen() const;
    string toString() const;               // Para guardar en archivo
    void fromString(const string& data);   // Para cargar desde archivo
    
    // Métodos estáticos para validación
    static bool esNotaValida(double nota);
    static string obtenerEstadoPorPromedio(double promedio);

    // Operadores
    bool operator==(const Grade& other) const;
    friend ostream& operator<<(ostream& os, const Grade& grade);
};

#endif // GRADE_H 