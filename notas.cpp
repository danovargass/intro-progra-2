#include "notas.h"
#include <iostream>
#include "validacion.h"
#include "estudiante.h" 
#include <fstream>
#include <string>
#include <map>          
#include <vector>       
#include <iomanip>      
#include <sstream>      
#include "controladorEntradas.h"
using namespace std;

map<string, vector<Notas>> matrizNotasEstudiantes;
Notas notas;

void ingresarCalificaciones(){
    // funcion para ingresar calificaciones del estudiante
    if(bucleExisteEstudiante() != 0){
        int materiasIngresadas = contadorDeMaterias();
        for(int i = 0; i < materiasIngresadas; i++){
            notas.materia = stringValido("Materia " + to_string(i + 1) + ": \n");
            notas.proyecto_uno = floatValido("Ingrese la nota del proyecto 1: ");
            notas.proyecto_dos = floatValido("Ingrese la nota del proyecto 2: ");
            notas.ensayo = floatValido("Ingrese la nota del ensayo: ");
            notas.foro = floatValido("Ingrese la nota del foro: ");
            notas.defensa = floatValido("Ingrese la nota de la defensa: ");
            notas.promedio = calcularPromedio(notas.proyecto_uno, notas.proyecto_dos, notas.ensayo, notas.foro, notas.defensa);
            notas.estado = estadoMateria(notas.promedio);
            guardarNotas(notas);
        }
    } else {
        cout << "El estudiante no existe \n" << endl;
        return;
    }
}

float calcularPromedio(float proyecto_uno, float proyecto_dos, float ensayo, float foro, float defensa){
    // funcion con promedio predeterminado por requerimientos del profesor
    float p_uno = proyecto_uno * 1 / 100;
    float p_dos = proyecto_dos * 2 / 100;
    float ens = ensayo * 3 / 100;
    float fo = foro * 1 / 100;
    float def = defensa * 3 / 100;
    notas.promedio = (p_uno + p_dos + ens + fo + def);
    return notas.promedio;
}

string estadoMateria(float promedio){
    // funcion para determinar el estado de la materia comparando con el promedio para definirlo
    if(promedio >= 7){
        notas.estado = "Aprobado";
    } else if (promedio >= 5 && promedio < 7){
        notas.estado = "Reposición";
    } else {
        notas.estado = "Reprobado";
    }
    return notas.estado;
}

void guardarNotas(const Notas& notas){
    // funccion para cargar las entradas del usuario en NOTAS.txt
    ofstream archivoNotas("NOTAS.txt", ios::app);
    if(archivoNotas.is_open()){
        archivoNotas 
            << notas.cedula << "," 
            << notas.materia << "," 
            << notas.proyecto_uno << "," 
            << notas.proyecto_dos << "," 
            << notas.ensayo << ","
            << notas.foro << "," 
            << notas.defensa << "," 
            << notas.promedio << ","
            << notas.estado << endl;
        archivoNotas.close();
    }
}

void modificarNotas(){
    // funcion para modificar notas de una materia usando la misma estructura logica que modificarEstudiante
    if(bucleExisteEstudiante() != 0){
        ifstream archivoNotas("NOTAS.txt");
        ofstream archivoNotasTemp("NOTAS_TEMP.txt");
        bool materia_encontrada = false;

        if (archivoNotas.is_open() && archivoNotasTemp.is_open()){
            notas.materia = stringValido("Cuál de las materias registradas desea modificar: " + notas.materia);

            string registroNotas;
            while (getline(archivoNotas, registroNotas)){
                if (registroNotas.find(notas.materia) != string::npos){
                    materia_encontrada = true;

                    string datosNotasActual[9];
                    int indiceCampoActual = 0;
                    string valorCampoTemporal = "";
                    for (char caracterActual : registroNotas){
                        if (caracterActual == ','){
                            datosNotasActual[indiceCampoActual++] = valorCampoTemporal;
                            valorCampoTemporal = "";
                        } else {
                            valorCampoTemporal += caracterActual;
                        }
                    }
                    datosNotasActual[indiceCampoActual] = valorCampoTemporal;
                    notas.proyecto_uno = floatValido("Ingrese la nueva nota del proyecto 1: ");
                    notas.proyecto_dos = floatValido("Ingrese la nueva nota del proyecto 2: ");
                    notas.ensayo = floatValido("Ingrese la nueva nota del ensayo: ");
                    notas.foro = floatValido("Ingrese la nueva nota del foro: ");
                    notas.defensa = floatValido("Ingrese la nueva nota de la defensa: ");
                    notas.promedio = calcularPromedio(notas.proyecto_uno, notas.proyecto_dos, notas.ensayo, notas.foro, notas.defensa);
                    notas.estado = estadoMateria(notas.promedio);
                    archivoNotasTemp
                        << datosNotasActual[0] << ","
                        << datosNotasActual[1] << ","
                        << notas.proyecto_uno << ","
                        << notas.proyecto_dos << ","
                        << notas.ensayo << ","
                        << notas.foro << ","
                        << notas.defensa << "," 
                        << notas.promedio << ","
                        << notas.estado << endl;
                } else {
                    archivoNotasTemp << registroNotas  << endl;
                }
            }
        }
        archivoNotas.close();
        archivoNotasTemp.close();

        if (materia_encontrada){
            remove("NOTAS.txt");
            rename("NOTAS_TEMP.txt", "NOTAS.txt");
            cout << "Datos actualizados correctamente! \n" << endl;
        } else {
            remove("NOTAS_TEMP.txt");
            cout << "Materia no fue encontrada! \n" << endl;
        }
    } else {
        cout << "El estudiante no existe" << endl;
        return;
    }
}

int bucleExisteEstudiante(){
    // funcion que continua preguntando al usuario si desea ingresar un estudiante nuevo si el estudiante esta registrado ya
    char respuesta_si_no;
    do {
        notas.cedula = intValido("Ingrese el número de cédula del estudiante al que se le va a ingresar las calificaciones: \n");
        
        if(estudianteExiste(notas.cedula) == false){       
            cout << "El/La estudiante no está registrado. \n"
            "¿Desea ingresar otra identidad Sí (S) o No (N)? \n";
            respuesta_si_no = charValido("¿Desea ingresar otra identidad Sí (S) o No (N)? \n");
        } else {
            return notas.cedula;
        }
    } while (respuesta_si_no == 'S');  
    return 0;
}

void generarReporte() {
    // objeto para controlar los datos de la matriz junto con el menu a mostrar y los datos del estudiante
    // la intención es hacer un solo llamado en main.cpp para facilitar lectura
    cargarDatosEnMatriz();
    mostrarEncabezadoReporte();
    mostrarDatosEstudiantes();
}

void cargarDatosEnMatriz() {
    // funcion para cargar la información necesaria en la matriz. 
    matrizNotasEstudiantes.clear(); // limpiar para evitar duplicación de datos
    ifstream archivoNotas("NOTAS.txt");
    string linea;
    
    while(getline(archivoNotas, linea)) {
        Notas nota = parsearLineaNota(linea);
        matrizNotasEstudiantes[to_string(nota.cedula)].push_back(nota);
    }
    archivoNotas.close();
}

void mostrarEncabezadoReporte() {
    // objeto enfocado en mostrar el encabezado del reporte
    // utiliza setw para normalizar cómo se renderiza la información, esto por la variabilidad que puede existir en los largos de los datos
    cout << "\n";
    cout << "========================================================\n";
    cout << "         REPORTE DE ESTUDIANTES - NOTAS FINALES         \n";
    cout << "========================================================\n";
    cout << setw(12) << "ID" 
         << setw(25) << "NOMBRE" 
         << setw(15) << "MATERIA" 
         << setw(10) << "PROMEDIO" 
         << setw(12) << "ESTADO" << endl;
    cout << "--------------------------------------------------------\n";
}

void mostrarDatosEstudiantes() {
    vector<Estudiante> estudiantes = cargarEstudiantes();
    
    for(const auto& estudiante : estudiantes) { // uso de auto para no repetir tipo de dato
        string cedulaStr = to_string(estudiante.cedula);
        string nombreCompleto = estudiante.nombre + " " + 
                               estudiante.primer_apellido + " " + 
                               estudiante.segundo_apellido;
        
        if(matrizNotasEstudiantes.find(cedulaStr) != matrizNotasEstudiantes.end()) {
            // manejo de datos en matriz si el estudiante tiene notas
            auto& notasEstudiante = matrizNotasEstudiantes[cedulaStr];
            
            for(size_t i = 0; i < notasEstudiante.size(); i++) {
                cout << setw(12) << cedulaStr
                     << setw(25) << (i == 0 ? nombreCompleto : "")
                     << setw(15) << notasEstudiante[i].materia
                     << setw(10) << fixed << setprecision(2) 
                     << notasEstudiante[i].promedio
                     << setw(12) << notasEstudiante[i].estado << endl;
            }
        } else {
            // manejo de datos en matriz si el estudiante no tiene notas
            cout << setw(12) << cedulaStr
                 << setw(25) << nombreCompleto
                 << setw(15) << "Sin materias"
                 << setw(10) << "N/A"
                 << setw(12) << "N/A" << endl;
        }
        cout << "--------------------------------------------------------\n";
    }
}

vector<Estudiante> cargarEstudiantes() {
    // vector que carga la información de los estudiantes
    vector<Estudiante> estudiantes;
    ifstream archivo("ESTUDIANTE.txt");
    string linea;
    
    while(getline(archivo, linea)) {
        estudiantes.push_back(parsearLineaEstudiante(linea));
    }
    archivo.close();
    return estudiantes;
}

Estudiante parsearLineaEstudiante(const string& linea) {
    // funcion que actua como controlador de la información transformada y convertirla al tipo necesario
    Estudiante estudiante;
    stringstream ss(linea);
    string campo;
    
    getline(ss, campo, ','); estudiante.cedula = stoi(campo);
    getline(ss, estudiante.nombre, ',');
    getline(ss, estudiante.primer_apellido, ',');
    getline(ss, estudiante.segundo_apellido, ',');
    getline(ss, campo, ','); estudiante.edad = stoi(campo);
    getline(ss, campo, ','); estudiante.genero = campo[0];
    getline(ss, estudiante.lugar_residencia.provincia, ',');
    getline(ss, estudiante.lugar_residencia.canton, ',');
    getline(ss, estudiante.lugar_residencia.distrito);
    
    return estudiante;
}

Notas parsearLineaNota(const string& linea) {
    // funcion que actua como controlador de la información transformada y convertirla al tipo necesario
    Notas nota;
    stringstream ss(linea);
    string campo;
    
    getline(ss, campo, ','); nota.cedula = stoi(campo);
    getline(ss, nota.materia, ',');
    getline(ss, campo, ','); nota.proyecto_uno = stof(campo);
    getline(ss, campo, ','); nota.proyecto_dos = stof(campo);
    getline(ss, campo, ','); nota.ensayo = stof(campo);
    getline(ss, campo, ','); nota.foro = stof(campo);
    getline(ss, campo, ','); nota.defensa = stof(campo);
    getline(ss, campo, ','); nota.promedio = stof(campo);
    getline(ss, nota.estado);
    
    return nota;
}

int contadorDeMaterias(){
    // función para controlar cuántas materias va a ingresar el usuario
    int materiasIngresadas;
    materiasIngresadas = intValido("Cuántas materias desea agregarle notas (1 a 3): ");
    if(materiasIngresadas < 1 || materiasIngresadas > 3){
        cout << "El número de materias debe ser entre 1 y 3 \n" << endl;
        return 0;
    }
    return materiasIngresadas;
}