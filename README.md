# intro-progra-2
Estudiante: Daniel Vargas Somogyi \
Fecha de presentación: 

## Desarrollo de segundo proyecto de introducción a programación para la Universidad Estatal a Distancia de Costa Rica

<Menu Principal>

1. Registrar Estudiante [no es vacío]
    - si no existe:
        - Identificación del estudiante
            - debe ser de 10 caracteres numéricos 
                - [validación que no haya más o menos de 10]
                - [no debe permitir letras]
                - [no debe permitir caracteres especiales]
                - mostrar => "Identificación válida!"
            - Nombre del estudiante
            - Primer apellido
            - Segundo apellido
            - Lugar de residencia
                - Provincia
                - Cantón
                - Distrito
            - Edad [validación rango entre 18 y 100]
            - Género
                - Masculino
                - Femenino
                - Otro
                - mostrar => "Género seleccionado <selección del usuario>"
            - Registro existoso
                - guardar en "ESTUDIANTE.txt"
                - mostrar => "Registro de estudiante existoso! en <archivo dónde se guardó>"
    - si existe:
        - mostrar => "El estudiante ya está registrado!"
2. Ingresar Calificaciones [no es vacío]
    - en distintas materias (máximo 3 materias a la vez)
    - solicitar identificación del estudiante
        - buscar en "ESTUDIANTE.txt"
            - si no existe
                - mostrar => "Estudiante no registrado"
                - preguntar => "Desea ingresar otra identidad?"
                    - Si (S): volver a <solicitar identificación del estudiante>
                    - No (N): volver a <Menu Principal>
            - si existe
                - mostrar => "Ingrese la cantidad de materias a registrar (Máximo 3): <valor ingresado>"
                    -  si <valor ingresado> <= 0
                        - volver a <Menu Principal>
                    - si <valor ingresado> == 1 o 2 o 3
                        - mostrar "Materia <posición de ingreso>"
                        - Ingresar nombre de la materia
                        - Ingresar notas en base 10 para
                            - Proyecto 1 = 1%
                            - Proyecto 2 = 2%
                            - Ensayo = 3%
                            - Foro = 1%
                            - Defensa = 3%
                        - Promedio [debe permitir dos decimales]
                            - utilizar escala de promedios de ingrsar notas
                            - entre 70 y 100 => “Aprobó”
                            - entre 50 y 69 => "Reposición"
                            - < 50 => "Reprobó"
                            - mostrar => "Promedio: <promedio>, estado de la materia <estado>"
                        - mostrar "Materia <posición de ingreso>" recursivamente hasta llegar al número ingresado por el usuario 
                        - guardar notas
                            - realizar el cálculo del promedio, con decimales
                            - adjuntar al registro de la materia específica ["Aprobó","Reposición","Reprobó"] 
                            - guardar en "NOTAS.txt"
                            - relacionar por id con "ESTUDIANTES.txt"
                            - "Registro(s) guardado existosamente! "
3. Modificar Datos Estudiante [no es vacío]
    - solo se permite la modificación de Edad y lugar de residencia
    - solicitar identificación del estudiante
        - buscar en "ESTUDIANTE.txt"
            - si no existe
                - mostrar => "Estudiante no registrado"
                - preguntar => "Desea ingresar otra identidad?"
                    - Si (S): volver a <solicitar identificación del estudiante>
                    - No (N): volver a <Menu Principal>
            - si existe
                - "Edad del estudiante"
                    - si es igual al registro mostrar => "Valor ingresado coincide con el registrado."
                    - si es nuevo mostrar => "Valor registrado correctamente!"
                - "Residencia del estudiante"
                    - Provincia
                    - Cantón
                    - Distrito
                - mostrar => "Datos actualizados correctamente!"
4. Modificar Registro de Notas por Estudiante
    - Solo para modificar notas registradas
    - solicitar identificación del estudiante
        - buscar en "ESTUDIANTE.txt"
            - si no existe
                - mostrar => "Estudiante no registrado"
                - preguntar => "Desea ingresar otra identidad?"
                    - Si (S): volver a <solicitar identificación del estudiante>
                    - No (N): volver a <Menu Principal>
            - si existe
                - mostrar => "Materias registradas: \n"
                    "1. [materiasRegistradas]\n"
                    "2. [etc]"
                - seleccionar materia
                    - mostrar => "Notas actuales: <notas en orden>"
                    - Ingresar notas en base 10 para
                        - Proyecto 1 = 1%
                        - Proyecto 2 = 2%
                        - Ensayo = 3%
                        - Foro = 1%
                        - Defensa = 3%
                    - mostrar => "Notas modificadas correctamente! ¿Desea hacer otra modificación Sí (S) o No (N)?"
                        - Si (S): volver a mostrar "Materias registradas"
                        - No (N): volver a <Menu Principal>
5. Eliminar Registro de Estudiante
    - solicitar el número de identificación
        - si existe
            - confirmar si esta seguro de eliminar el registro (S/N)
                - Si (S): eliminar todo el registro relacionado del archivo ESTUDIANTES.txt y NOTAS.txt
                - No (N): preguntar si desea eliminar otro estudiante
                    - Si (S): entrar de nuevo al ciclo
                    - No (N): salir al menu principal
6. Reporte de Estudiantes, promedios y estado
    - mostrar => "REPORTE DE ESTUDIANTES - NOTAS FINALES"
        - formato tabla
            - ID: mostrar => <id estudiante> |
            - NOMBRE: mostrar => <nombre> + <primer apellido> + <segundo apellido> |
            - MATERIA: mostrar => <materias ingresadas> |
            - PROMEDIO: mostrar => <promedio de cada materia> |
            - ESTADO: mostrar => <estado de la materia> |
7. Salir del programa
    - mostrar => "Seguro que desea salir? Si (S) o No (N)"
        - Si (S): cerrar aplicación
        - No (N): volver a mostrar <Menu Principal>

## Validaciones, requerimientos técnicos y funciones mínimas
### Validaciones
- [no es vacío]
- [no debe permitir letras]
- [no debe permitir caracteres especiales]
- [no deben repetirse caracteres]
- [no dentro del rango]
    - entre 18 y 100 para edades
    - entre 1 y 3 en notas
- [volver al menú principal]
    - opción persitente antes de iniciar el proceso de cada ingreso u opción para volver (S/N) al <Menú principal>
- menu
    - si la opción seleccionada no está entre 1 y 7 mostrar => "Opción inválida, vuelva a intentarlo."
    - no mostrar caracteres especiales en el menú
    - mientras la opción de salir no se ejecute el menú debe permanecer en pantalla

### Requerimientos Técnicos
- Caracteres como S y N deben convertirse en mayúscula si se ingresan en minúscula
- Notas deben permitir hasta 2 decimales
- Demostrar manejo de variables, condicionales, funciones con/sin parametrizar, try-catch-throw, arreglos, matrices.
    - Vector para ESTUDIANTES.txt
    - Matriz para NOTAS.txt
- Manejar errores como valor numérico invalido o vacío
- Los archivos de captura de datos deben persistir, quiere decir que si se cierra la aplicación y se reinicia, los valores deben existir y cargarse automáticamente
- Priorizar código reutilizable
- Mostrar mensajes de error cuando se ingresan opciones inválidas
- Él menú debe mantenerse en posición cuando esté presente.
- Agregar comentarios para funciones y otros necesarios/pertinentes

### Funciones Principales mínimas
• Registro de datos del estudiante.
• Ingresar notas.
• Modificar notas.
• Eliminar registro.
• Generar reportes
• Carga y almacenamiento de datos en archivos.