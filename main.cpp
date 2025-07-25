#include <iostream>
#include "menu.h"
#include "estudiante.h"
#include "notas.h"
#include "controladorEntradas.h"
using namespace std;

int main() {
    int opcion;
    Estudiante estudiante;
    char respuesta_si_no;
    int opcion_seleccionada;
    // switch general para controlar las decisiones del usuario
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
                {
                    int cedula_del_estudiante = intValido("Ingrese la cédula del estudiante a modificar: \n");
                    modificarEstudiante(cedula_del_estudiante);               
                    confirmarVolverAlMenu();
                }
                break;
            case 4:
                modificarNotas();
                confirmarVolverAlMenu();
                break;
            case 5:
                {
                    int cedula_del_estudiante_a_eliminar = intValido("Ingrese la cédula del estudiante a eliminar: \n");
                    eliminarEstudiante(cedula_del_estudiante_a_eliminar);
                    confirmarVolverAlMenu();
                }
                break;
            case 6:
                generarReporte();
                confirmarVolverAlMenu(); 
                break;
            case 7:
                {
                    char respuesta_si_no_usuario = charValido("¿Seguro que desea salir? Volver al menú principal Sí (S) o No (N) \n");
                    respuesta_si_no = volverAlMenu(respuesta_si_no_usuario);   
                }
                break;
            default:
                confirmarVolverAlMenu();
                break;
        }
    } while (respuesta_si_no != 'N');
    // limpiar pantalla y cerrar programa
    limpiarPantalla();
    cout << "Cerrando programa. Adiós! \n" << endl;
    return 0; 
}