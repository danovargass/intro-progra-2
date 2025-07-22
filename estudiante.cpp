#include "estudiante.h"
#include "validacion.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
Estudiante estudiante;

void registrarEstudiante(){
    cout << "Ingrese el número de cédula del estudiante: ";
    cin >> estudiante.cedula;
    cin.ignore(); // Limpiar el buffer de entrada para evitar problemas con palabras con espacios
    
    // si el estudiante no existe, se registra
    if(estudianteExiste(estudiante.cedula) == false){
        cout << "Ingrese el nombre del estudiante: ";
        getline(cin, estudiante.nombre);
        cout << "Ingrese el primer apellido del estudiante: ";
        getline(cin, estudiante.primer_apellido);
        cout << "Ingrese el segundo apellido del estudiante: ";
        getline(cin, estudiante.segundo_apellido);
        cout << "Ingrese la edad del estudiante: ";
        cin >> estudiante.edad;
        cin.ignore(); // limpiar el buffer de entrada del enter que se ejecuta
        cout << "Ingrese el género del estudiante M = Masculino, F = Femenino, O = Otro: ";
        cin >> estudiante.genero;
        cin.ignore(); // limpiar el buffer de entrada del enter que se ejecuta
        cout << "Ingrese la provincia de residencia del estudiante: ";
        getline(cin, estudiante.lugar_residencia.provincia);
        cout << "Ingrese el cantón de residencia del estudiante: ";
        getline(cin, estudiante.lugar_residencia.canton);
        cout << "Ingrese el distrito de residencia del estudiante: ";
        getline(cin, estudiante.lugar_residencia.distrito);
        guardarEstudiante(estudiante);
    } else {
        cout << "El estudiante ya está registrado! \n" << endl;
    }
}

void modificarEstudiante(int cedula){
    ifstream archivoEstudiantes("ESTUDIANTE.txt");
    ofstream archivoEstudiantesTemp("ESTUDIANTE_TEMP.txt");
    bool estudiante_encontrado = false;
    
    if (archivoEstudiantes.is_open() && archivoEstudiantesTemp.is_open()) {
        string registroEstudiante;
        while (getline(archivoEstudiantes, registroEstudiante)) {
            if (registroEstudiante.find(to_string(cedula)) != string::npos) {
                // variable equivalente a retornar true a si existe el usuario
                estudiante_encontrado = true;        
                // hacer un parseo de las lineas del archivo para obtener los valores que no se van a cambiar
                string datosEstudianteActual[9];
                int indiceCampoActual = 0;
                string valorCampoTemporal = "";   
                for (char caracterActual : registroEstudiante) {
                    if (caracterActual == ',') {
                        datosEstudianteActual[indiceCampoActual++] = valorCampoTemporal;
                        valorCampoTemporal = "";
                    } else {
                        valorCampoTemporal += caracterActual;
                    }
                }
                datosEstudianteActual[indiceCampoActual] = valorCampoTemporal; // ultimo campo 
                // pedir al usuario los datos que se van a cambiar
                cout << "Ingrese la nueva edad del estudiante: ";
                cin >> estudiante.edad;
                cin.ignore(); // limpiar el buffer de entrada del enter que se ejecuta
                cout << "Ingrese la nueva provincia de residencia del estudiante: ";
                getline(cin, estudiante.lugar_residencia.provincia);
                cout << "Ingrese el nuevo canton de residencia del estudiante: ";
                getline(cin, estudiante.lugar_residencia.canton);
                cout << "Ingrese el nuevo distrito de residencia del estudiante: ";
                getline(cin, estudiante.lugar_residencia.distrito);    
                // escribir lineas con valores actualizados y no actualizados en el archivoEstudiantesTemp
                archivoEstudiantesTemp 
                    << datosEstudianteActual[0] << ","  // cedula (sin cambio)
                    << datosEstudianteActual[1] << ","  // nombre (sin cambio)
                    << datosEstudianteActual[2] << ","  // primer_apellido (sin cambio)
                    << datosEstudianteActual[3] << ","  // segundo_apellido (sin cambio)
                    << estudiante.edad << ","  // edad (ACTUALIZADO)
                    << datosEstudianteActual[5] << ","  // genero (sin cambio)
                    << estudiante.lugar_residencia.provincia << ","  // provincia (ACTUALIZADO)
                    << estudiante.lugar_residencia.canton << ","     // canton (ACTUALIZADO)
                    << estudiante.lugar_residencia.distrito << endl; // distrito (ACTUALIZADO)
            } else {
                // copiar lineas con valores no actualizados en el archivoEstudiantesTemp
                archivoEstudiantesTemp << registroEstudiante << endl;
            }
        }
        
        archivoEstudiantes.close();
        archivoEstudiantesTemp.close();
        
        if (estudiante_encontrado) {
            // reemplazar el archivo original con el archivo temporal
            remove("ESTUDIANTE.txt");
            rename("ESTUDIANTE_TEMP.txt", "ESTUDIANTE.txt");
            cout << "Datos actualizados correctamente! \n" << endl;
        } else {
            // eliminar el archivo temporal si el estudiante no se encontró
            remove("ESTUDIANTE_TEMP.txt");
            cout << "Estudiante no fue encontrado! \n" << endl;
        }
    } else {
        cout << "Error al abrir el archivo! \n" << endl;
    }
}

void guardarEstudiante(const Estudiante& estudiante){
    // instancia que abre y escribe en el archivo ESTUDIANTE.txt
    ofstream archivoEstudiantes("ESTUDIANTE.txt", ios::app);
    if (archivoEstudiantes.is_open()) {
        archivoEstudiantes 
            << estudiante.cedula << ","
            << estudiante.nombre << ","
            << estudiante.primer_apellido << ","
            << estudiante.segundo_apellido << ","
            << estudiante.edad << ","
            << estudiante.genero << ","
            << estudiante.lugar_residencia.provincia << ","
            << estudiante.lugar_residencia.canton << ","
            << estudiante.lugar_residencia.distrito << endl;
        archivoEstudiantes.close();
        cout << "Estudiante guardado exitosamente! \n" << endl;
    } else {
        cout << "Error al abrir el archivo! \n" << endl;
    }
}

void eliminarEstudiante(int cedula){
    ifstream archivoEstudiantes("ESTUDIANTE.txt");
    ofstream archivoEstudiantesTemp("ESTUDIANTE_TEMP.txt"); // archivo temporal para guardar los estudiantes que no se van a eliminar
    
    if (archivoEstudiantes.is_open() && archivoEstudiantesTemp.is_open()) {
        string linea;
        while (getline(archivoEstudiantes, linea)) {
            if (linea.find(to_string(cedula)) == string::npos) {
                archivoEstudiantesTemp << linea << endl;
            }
        }
        archivoEstudiantes.close();
        archivoEstudiantesTemp.close();
        remove("ESTUDIANTE.txt");
        rename("ESTUDIANTE_TEMP.txt", "ESTUDIANTE.txt");
        cout << "Estudiante eliminado exitosamente! \n" << endl;
    } else {
        cout << "Error al abrir el archivo! \n" << endl;
    }
}