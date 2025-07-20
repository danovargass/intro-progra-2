#include <iostream>
using namespace std;

int main() {
    int opcion;

    do{
        cout << "Ingresar Estudiante" << endl;
        cout << "Ingresar Calificaciones en distintas materias"  << endl; 
        //(mínimo 3 materias).
        cout << "Modificar Datos Estudiante" << endl;  
        //Solo se permite la modificación de Edad y lugar de residencia.
        cout << "Modificar Registro de Notas por Estudiante" << endl; 
        //El programa debe permitir la modificación únicamente de las notas registradas, 
        // no se debe modificar el nombre del estudiante, ni tampoco el ID y Edad.
        cout << "Eliminar Registro de Estudiante" << endl; 
        //El programa debe solicitar el número de identificación, 
        // si lo encuentra, debe preguntar si esta seguro que desea eliminar el registro (S/N). 
        // Si es Si (S), se debe eliminar todo el registro tanto del archivo estudiantes.txt, 
        // así como del archivo notas.txt. En caso de ser N, 
        // debe preguntar si desea eliminar otro estudiante y vuelve el ciclo.
        cout << "Reporte de Estudiantes, promedios y estado" << endl;
        cout << "Salir del programa" << endl;
        cin >> opcion;

        switch(opcion){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    } while(opcion != 7);

    return 0; 
}