#include <iostream>
#include "validacion.h"
#include "estudiante.h"
#include "notas.h"
using namespace std;

int main() {
    int opcion;
    Estudiante estudiante;
    char respuesta_si_no;

    do{
        cout << " SISTEMA DE GESTIÓN DE ESTUDIANTES \n" << endl;
        cout << " 1. Ingresar Estudiante " << endl;
        cout << " 2. Ingresar Calificaciones en distintas materias "  << endl; 
        cout << " 3. Modificar Datos Estudiante " << endl;  
        cout << " 4. Modificar Registro de Notas por Estudiante " << endl; 
        cout << " 5. Eliminar Registro de Estudiante " << endl; 
        cout << " 6. Reporte de Estudiantes, promedios y estado " << endl;
        cout << " 7. Salir del programa \n" << endl;
        cin >> opcion;
        int opcion_seleccionada = dentroDelRango(opcion, 1, 7);

        switch(opcion_seleccionada){
            case 1:
                registrarEstudiante();
                break;
            case 2:
                ingresarCalificaciones();
                break;
            case 3:  
                int cedula_del_estudiante;
                cout << "Ingrese la cédula del estudiante a modificar: \n";
                cin >> cedula_del_estudiante;
                modificarEstudiante(cedula_del_estudiante);               
                break;
            case 4:
                modificarNotas();
                break;
            case 5:
                int cedula_del_estudiante_a_eliminar;
                cout << "Ingrese la cédula del estudiante a eliminar: \n";
                cin >> cedula_del_estudiante_a_eliminar;
                eliminarEstudiante(cedula_del_estudiante_a_eliminar);
                break;
            case 6:
                break;
            case 7:
                cout << "¿Seguro que desea salir? Volver al menú principal Sí (S) o No (N) \n" << endl;
                cin >> respuesta_si_no;
                respuesta_si_no = volverAlMenu(respuesta_si_no);
                break;
            default:
                cout << "Opción no válida \n" << endl;
                break;
        }
    } while (respuesta_si_no != 'N');

    cout << "Cerrando programa... \n" << endl;
    return 0; 
}