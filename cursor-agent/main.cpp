/*
 * Sistema de Gestión de Estudiantes
 * Autor: [Nombre del Estudiante]
 * Fecha: Enero 2025
 * Descripción: Sistema para registrar estudiantes, calificaciones y generar reportes
 * Universidad Estatal a Distancia de Costa Rica
 * Introducción a la Programación - Proyecto 2
 * 
 * Arquitectura:
 * - Student: Manejo de datos de estudiantes
 * - Grade: Manejo de calificaciones y cálculos
 * - FileManager: Operaciones de archivos
 * - MenuManager: Interface de usuario
 * - Validator: Validaciones de entrada
 * - StudentSystem: Controlador principal del sistema
 */

#include <iostream>
#include <exception>
#include "StudentSystem.h"

using namespace std;

int main() {
    try {
        // Crear instancia del sistema
        StudentSystem sistema;
        
        // Inicializar el sistema
        if (!sistema.inicializar()) {
            cerr << "Error: No se pudo inicializar el sistema." << endl;
            cerr << "Estado del sistema: " << sistema.obtenerEstadoSistema() << endl;
            return 1;
        }
        
        // Ejecutar el sistema principal
        sistema.ejecutar();
        
        // Finalizar y limpiar recursos
        sistema.finalizar();
        
        cout << "\n¡Gracias por usar el Sistema de Gestión de Estudiantes!" << endl;
        cout << "Universidad Estatal a Distancia de Costa Rica" << endl;
        
    } catch (const exception& e) {
        cerr << "\nError crítico del sistema: " << e.what() << endl;
        cerr << "El programa se cerrará de forma segura." << endl;
        return 1;
        
    } catch (...) {
        cerr << "\nError desconocido en el sistema." << endl;
        cerr << "El programa se cerrará de forma segura." << endl;
        return 1;
    }
    
    return 0;
}
