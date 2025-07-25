#include <iostream>
#include <string>
#include <limits>
#include "controladorEntradas.h"
using namespace std;

/*
    COMENTARIO GENERAL:
    validación identica para los 4 tipos de datos utilizados en el programa.
    while para valida la entrada del usuario hasta que se ingrese un valor válido.
    cin.fail() verifica la validez de la entrada.
    cin.clear() limpia el buffer de entrada.
    cin.ignore() ignora cualquier input adicional en caso de error en el resto de la entrada.
    numeric_limits<streamsize>::max() junto con'\n' para ignorar el resto de la línea de entrada. 
    lo anterior obliga a su vez 2 enters para finalizar la interacción del usuario.
*/

int intValido(string consultaAlUsuario) {
    int valor_ingresado;
    bool validando_entrada = false;
    
    while (!validando_entrada) {
        cout << consultaAlUsuario;
        cin >> valor_ingresado;
        
        if (cin.fail()) {
            cout << "Recuerde que solo puede usar números como respuestas \n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            validando_entrada = true;
        }
    }
    return valor_ingresado;
}

string stringValido(string consultaAlUsuario){
    string valor_ingresado;
    bool validando_entrada = false;
    
    while (!validando_entrada) {
        cout << consultaAlUsuario;
        cin >> valor_ingresado;
        
        if (cin.fail()) {
            cout << "Recuerde que solo puede usar caracteres como respuestas \n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            validando_entrada = true;
        }
    }
    return valor_ingresado;
}

char charValido(string consultaAlUsuario){
    char valor_ingresado;
    bool validando_entrada = false;
    
    while (!validando_entrada) {
        cout << consultaAlUsuario;
        cin >> valor_ingresado;
        
        if (cin.fail()) {
            cout << "Recuerde que solo puede usar caracteres como respuestas \n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            validando_entrada = true;
        }
    }
    return valor_ingresado;
}

float floatValido(string consultaAlUsuario){
    float valor_ingresado;
    bool validando_entrada = false;
    
    while (!validando_entrada) {
        cout << consultaAlUsuario;
        cin >> valor_ingresado;
        
        if (cin.fail()) {
            cout << "Recuerde que solo puede usar números con o sin decimales como respuestas \n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            validando_entrada = true;
        }
    }   
    return valor_ingresado;
}