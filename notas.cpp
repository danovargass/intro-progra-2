#include "notas.h"
#include <iostream>
#include "validacion.h"
#include <fstream>
#include <string>
using namespace std;

Notas notas;

void ingresarCalificaciones(){
    if(bucleExisteEstudiante() != 0){
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
    } else {
        cout << "El estudiante no existe" << endl;
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
        cout << "Ingrese el número de cédula del estudiante al que se le va a ingresar las calificaciones:";
        cin >> notas.cedula;
        cin.ignore(); // limpiar el buffer de entrada del enter que se ejecuta
        
        if(estudianteExiste(notas.cedula) == false){       
            cout << "El/La estudiante no está registrado. \n"
            "¿Desea ingresar otra identidad Sí (S) o No (N)? ";
            cin >> respuesta_si_no;
        } else {
            return notas.cedula;
        }
    } while (respuesta_si_no == 'S');  
    return 0;
}