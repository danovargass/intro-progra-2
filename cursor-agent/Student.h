#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

using namespace std;

class Student {
private:
    string cedula;          // 10 dígitos
    string nombre;          // Nombre completo
    string apellido1;       // Primer apellido
    string apellido2;       // Segundo apellido
    string provincia;       // Lugar de residencia
    string canton;
    string distrito;
    int edad;              // Entre 18 y 100
    string genero;         // Femenino, Masculino, u otro

public:
    // Constructores
    Student();
    Student(string cedula, string nombre, string apellido1, string apellido2,
            string provincia, string canton, string distrito, int edad, string genero);

    // Getters
    string getCedula() const;
    string getNombre() const;
    string getApellido1() const;
    string getApellido2() const;
    string getNombreCompleto() const;
    string getProvincia() const;
    string getCanton() const;
    string getDistrito() const;
    string getDireccionCompleta() const;
    int getEdad() const;
    string getGenero() const;

    // Setters
    void setCedula(const string& cedula);
    void setNombre(const string& nombre);
    void setApellido1(const string& apellido1);
    void setApellido2(const string& apellido2);
    void setProvincia(const string& provincia);
    void setCanton(const string& canton);
    void setDistrito(const string& distrito);
    void setEdad(int edad);
    void setGenero(const string& genero);

    // Métodos de utilidad
    void mostrarInformacion() const;
    string toString() const;               // Para guardar en archivo
    void fromString(const string& data);   // Para cargar desde archivo
    
    // Operadores
    bool operator==(const Student& other) const;
    friend ostream& operator<<(ostream& os, const Student& student);
};

#endif // STUDENT_H 