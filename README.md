# intro-progra-2
Estudiante: Daniel Vargas Somogyi \
Fecha de presentación: 

## Desarrollo de segundo proyecto de introducción a programación para la Universidad Estatal a Distancia de Costa Rica

**Menu Principal**
```
├── 1. Registrar Estudiante
│   ├── Verificar si estudiante existe
│   │   ├── Si NO existe:
│   │   │   ├── Solicitar Identificación (10 caracteres numéricos)
│   │   │   │   ├── Validaciones:
│   │   │   │   │   ├── Exactamente 10 caracteres
│   │   │   │   │   ├── Solo números (no letras ni caracteres especiales)
│   │   │   │   │   └── Mostrar: "Identificación válida!"
│   │   │   ├── Solicitar Datos Personales:
│   │   │   │   ├── Nombre del estudiante
│   │   │   │   ├── Primer apellido  
│   │   │   │   ├── Segundo apellido
│   │   │   │   ├── Lugar de residencia:
│   │   │   │   │   ├── Provincia
│   │   │   │   │   ├── Cantón
│   │   │   │   │   └── Distrito
│   │   │   │   ├── Edad (validación: 18-100 años)
│   │   │   │   └── Género:
│   │   │   │       ├── Masculino
│   │   │   │       ├── Femenino
│   │   │   │       ├── Otro
│   │   │   │       └── Mostrar: "Género seleccionado `selección`"
│   │   │   └── Guardar en "ESTUDIANTE.txt"
│   │   │       └── Mostrar: "Registro de estudiante exitoso! en `archivo`"
│   │   └── Si SÍ existe:
│   │       └── Mostrar: "El estudiante ya está registrado!"
├── 2. Ingresar Calificaciones
│   ├── Solicitar identificación del estudiante
│   ├── Buscar en "ESTUDIANTE.txt"
│   │   ├── Si NO existe:
│   │   │   ├── Mostrar: "Estudiante no registrado"
│   │   │   └── Preguntar: "¿Desea ingresar otra identidad?"
│   │   │       ├── Sí (S): → Volver a solicitar identificación
│   │   │       └── No (N): → Volver al Menú Principal
│   │   └── Si SÍ existe:
│   │       ├── Solicitar cantidad de materias (máximo 3)
│   │       │   ├── Si ≤ 0: → Volver al Menú Principal
│   │       │   └── Si 1, 2 o 3:
│   │       │       └── Para cada materia:
│   │       │           ├── Mostrar: "Materia `posición`"
│   │       │           ├── Ingresar nombre de materia
│   │       │           ├── Ingresar notas (base 10):
│   │       │           │   ├── Proyecto 1 (1%)
│   │       │           │   ├── Proyecto 2 (2%) 
│   │       │           │   ├── Ensayo (3%)
│   │       │           │   ├── Foro (1%)
│   │       │           │   └── Defensa (3%)
│   │       │           ├── Calcular Promedio (2 decimales):
│   │       │           │   ├── 70-100: "Aprobó"
│   │       │           │   ├── 50-69: "Reposición"
│   │       │           │   └── <50: "Reprobó"
│   │       │           └── Mostrar: "Promedio: `promedio`, estado: `estado`"
│   │       └── Guardar en "NOTAS.txt" relacionado por ID
│   │           └── Mostrar: "Registro(s) guardado exitosamente!"
├── 3. Modificar Datos Estudiante
│   ├── Solicitar identificación del estudiante
│   ├── Buscar en "ESTUDIANTE.txt"
│   │   ├── Si NO existe:
│   │   │   ├── Mostrar: "Estudiante no registrado"
│   │   │   └── Preguntar: "¿Desea ingresar otra identidad?"
│   │   │       ├── Sí (S): → Volver a solicitar identificación
│   │   │       └── No (N): → Volver al Menú Principal
│   │   └── Si SÍ existe:
│   │       ├── Modificar Edad:
│   │       │   ├── Si igual al registro: "Valor ingresado coincide con el registrado"
│   │       │   └── Si diferente: "Valor registrado correctamente!"
│   │       ├── Modificar Residencia:
│   │       │   ├── Provincia
│   │       │   ├── Cantón
│   │       │   └── Distrito
│   │       └── Mostrar: "Datos actualizados correctamente!"
├── 4. Modificar Registro de Notas por Estudiante
│   ├── Solicitar identificación del estudiante
│   ├── Buscar en "ESTUDIANTE.txt"
│   │   ├── Si NO existe:
│   │   │   ├── Mostrar: "Estudiante no registrado"
│   │   │   └── Preguntar: "¿Desea ingresar otra identidad?"
│   │   │       ├── Sí (S): → Volver a solicitar identificación
│   │   │       └── No (N): → Volver al Menú Principal
│   │   └── Si SÍ existe:
│   │       ├── Mostrar materias registradas:
│   │       │   ├── "1. [`materia1`]"
│   │       │   ├── "2. [`materia2`]"
│   │       │   └── "..."
│   │       ├── Seleccionar materia
│   │       ├── Mostrar: "Notas actuales: `notas en orden`"
│   │       ├── Ingresar nuevas notas:
│   │       │   ├── Proyecto 1 (1%)
│   │       │   ├── Proyecto 2 (2%)
│   │       │   ├── Ensayo (3%)
│   │       │   ├── Foro (1%)
│   │       │   └── Defensa (3%)
│   │       └── Preguntar: "¿Desea hacer otra modificación?"
│   │           ├── Sí (S): → Volver a mostrar materias registradas
│   │           └── No (N): → Volver al Menú Principal
├── 5. Eliminar Registro de Estudiante
│   ├── Solicitar número de identificación
│   ├── Si existe:
│   │   ├── Confirmar: "¿Está seguro de eliminar el registro? (S/N)"
│   │   │   ├── Sí (S): 
│   │   │   │   └── Eliminar de ESTUDIANTES.txt y NOTAS.txt
│   │   │   └── No (N): 
│   │   │       └── Preguntar: "¿Desea eliminar otro estudiante?"
│   │   │           ├── Sí (S): → Volver al inicio del ciclo
│   │   │           └── No (N): → Volver al Menú Principal
│   │   └── Si no existe: [flujo de manejo de error]
├── 6. Reporte de Estudiantes, Promedios y Estado
│   └── Mostrar: "REPORTE DE ESTUDIANTES - NOTAS FINALES"
│       └── Formato tabla:
│           ├── ID: `id estudiante`
│           ├── NOMBRE: `nombre` + `primer apellido` + `segundo apellido`
│           ├── MATERIA: `materias ingresadas`
│           ├── PROMEDIO: `promedio de cada materia`
│           └── ESTADO: `estado de la materia`
└── 7. Salir del Programa
    └── Confirmar: "¿Seguro que desea salir? Sí (S) o No (N)"
        ├── Sí (S): → Cerrar aplicación
        └── No (N): → Volver al Menú Principal
```

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
    - opción persitente antes de iniciar el proceso de cada ingreso u opción para volver (S/N) al `Menú principal`
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
- Registro de datos del estudiante.
- Ingresar notas.
- Modificar notas.
- Eliminar registro.
- Generar reportes
- Carga y almacenamiento de datos en archivos.