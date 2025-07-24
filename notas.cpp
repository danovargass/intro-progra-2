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
using namespace std;

map<string, vector<Notas>> matrizNotasEstudiantes;
Notas notas;

void ingresarCalificaciones(){
    if(bucleExisteEstudiante() != 0){
        int materiasIngresadas = contadorDeMaterias();
        for(int i = 0; i < materiasIngresadas; i++){
            cout << "Materia " << i + 1 << ": \n";
            cout << "Ingrese el nombre de la materia: ";
            cin >> notas.materia;
            cout << "Ingrese la nota del proyecto 1: ";
            cin >> notas.proyecto_uno;
            cout << "Ingrese la nota del proyecto 2: ";
            cin >> notas.proyecto_dos;
            cout << "Ingrese la nota del ensayo: ";
            cin >> notas.ensayo;
            cout << "Ingrese la nota del foro: ";
            cin >> notas.foro;
            cout << "Ingrese la nota de la defensa: ";
            cin >> notas.defensa;
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
    float p_uno = proyecto_uno * 1 / 100;
    float p_dos = proyecto_dos * 2 / 100;
    float ens = ensayo * 3 / 100;
    float fo = foro * 1 / 100;
    float def = defensa * 3 / 100;
    notas.promedio = (p_uno + p_dos + ens + fo + def);
    return notas.promedio;
}

string estadoMateria(float promedio){
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
    if(bucleExisteEstudiante() != 0){
        ifstream archivoNotas("NOTAS.txt");
        ofstream archivoNotasTemp("NOTAS_TEMP.txt");
        bool materia_encontrada = false;

        if (archivoNotas.is_open() && archivoNotasTemp.is_open()){
            cout << "Cuál de las materias registradas desea modificar: " + notas.materia;
            cin >> notas.materia;
            cin.ignore(); // limpiar el buffer de entrada del enter que se ejecuta

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

                    cout << "Ingrese la nueva nota del proyecto 1: ";
                    cin >> notas.proyecto_uno;
                    cout << "Ingrese la nueva nota del proyecto 2: ";
                    cin >> notas.proyecto_dos;
                    cout << "Ingrese la nueva nota del ensayo: ";
                    cin >> notas.ensayo;
                    cout << "Ingrese la nueva nota del foro: ";
                    cin >> notas.foro;
                    cout << "Ingrese la nueva nota de la defensa: ";
                    cin >> notas.defensa;
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
    char respuesta_si_no;
    do {
        cout << "Ingrese el número de cédula del estudiante al que se le va a ingresar las calificaciones: \n";
        cin >> notas.cedula;
        cin.ignore(); // limpiar el buffer de entrada del enter que se ejecuta
        
        if(estudianteExiste(notas.cedula) == false){       
            cout << "El/La estudiante no está registrado. \n"
            "¿Desea ingresar otra identidad Sí (S) o No (N)? \n";
            cin >> respuesta_si_no;
        } else {
            return notas.cedula;
        }
    } while (respuesta_si_no == 'S');  
    return 0;
}

void generarReporte() {
    // Load data into matrix structure
    cargarDatosEnMatriz();
    
    // Display formatted report
    mostrarEncabezadoReporte();
    mostrarDatosEstudiantes();
}

void cargarDatosEnMatriz() {
    // Clear existing matrix
    matrizNotasEstudiantes.clear();
    
    // Load grades from NOTAS.txt into matrix
    ifstream archivoNotas("NOTAS.txt");
    string linea;
    
    while(getline(archivoNotas, linea)) {
        Notas nota = parsearLineaNota(linea);
        matrizNotasEstudiantes[to_string(nota.cedula)].push_back(nota);
    }
    archivoNotas.close();
}

void mostrarEncabezadoReporte() {
    cout << "\n";
    cout << "========================================================\n";
    cout << "         REPORTE DE ESTUDIANTES - NOTAS FINALES       \n";
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
    
    for(const auto& estudiante : estudiantes) {
        string cedulaStr = to_string(estudiante.cedula);
        string nombreCompleto = estudiante.nombre + " " + 
                               estudiante.primer_apellido + " " + 
                               estudiante.segundo_apellido;
        
        if(matrizNotasEstudiantes.find(cedulaStr) != matrizNotasEstudiantes.end()) {
            // Student has grades
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
            // Student has no grades
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
    int materiasIngresadas;
    cout << "Cuántas materias desea agregarle notas (1 a 3): ";
    cin >> materiasIngresadas;
    if(materiasIngresadas < 1 || materiasIngresadas > 3){
        cout << "El número de materias debe ser entre 1 y 3 \n" << endl;
        return 0;
    }
    return materiasIngresadas;
}