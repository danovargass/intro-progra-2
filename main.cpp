#include <iostream>
#include "menu.h"
#include "estudiante.h"
#include "notas.h"
using namespace std;

int main() {
    int opcion;
    Estudiante estudiante;
    char respuesta_si_no;
    int opcion_seleccionada;

    do{
        opcion_seleccionada = menuPrincipal(opcion);
        switch(opcion_seleccionada){         
            case 1:
                registrarEstudiante();
                confirmarVolverAlMenu();
                break;
            case 2:
                ingresarCalificaciones();
                confirmarVolverAlMenu();
                break;
            case 3:  
                int cedula_del_estudiante;
                cout << "Ingrese la cédula del estudiante a modificar: \n";
                cin >> cedula_del_estudiante;
                modificarEstudiante(cedula_del_estudiante);               
                confirmarVolverAlMenu();
                break;
            case 4:
                modificarNotas();
                confirmarVolverAlMenu();
                break;
            case 5:
                int cedula_del_estudiante_a_eliminar;
                cout << "Ingrese la cédula del estudiante a eliminar: \n";
                cin >> cedula_del_estudiante_a_eliminar;
                eliminarEstudiante(cedula_del_estudiante_a_eliminar);
                confirmarVolverAlMenu();
                break;
            case 6:
                generarReporte();
                confirmarVolverAlMenu(); 
                break;
            case 7:
                cout << "¿Seguro que desea salir? Volver al menú principal Sí (S) o No (N) \n" << endl;
                cin >> respuesta_si_no;
                respuesta_si_no = volverAlMenu(respuesta_si_no);
                break;
            default:
                cout << "Opción no válida \n" << endl;
                confirmarVolverAlMenu();
                break;
        }
    } while (respuesta_si_no != 'N');

    limpiarPantalla();
    cout << "Cerrando programa... \n" << endl;
    return 0; 
}