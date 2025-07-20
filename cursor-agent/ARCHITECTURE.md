# Object-Oriented Architecture - Student Management System

## Overview
The student management system has been refactored into a clean object-oriented design with clear separation of concerns and modular components.

## Architecture Components

### 1. **Main Controller**
- **`main.cpp`**: Entry point with error handling and system lifecycle management
- **`StudentSystem`**: Central controller coordinating all operations

### 2. **Data Models**
- **`Student`**: Encapsulates student data and operations
- **`Grade`**: Handles grades, calculations, and academic status

### 3. **Service Layer**
- **`FileManager`**: All file I/O operations (ESTUDIANTES.txt, NOTAS.txt)
- **`MenuManager`**: User interface and interaction handling
- **`Validator`**: Input validation and data constraints

## Class Responsibilities

### Student Class
```cpp
- Data: cedula, nombre, apellidos, direccion, edad, genero
- Operations: getters/setters, validation, file serialization
- Utilities: display, comparison, string conversion
```

### Grade Class
```cpp
- Data: cedula, materia, 5 grade components, promedio, estado
- Calculations: weighted average (1%+2%+3%+1%+3% = 10%)
- Status: Aprobó (70-100), Reposición (50-69), Reprobó (<50)
```

### FileManager Class
```cpp
- File Operations: load/save students and grades
- Data Persistence: ESTUDIANTES.txt ↔ Student objects
- Error Handling: file access, backup/restore
```

### MenuManager Class
```cpp
- User Interface: menus, prompts, formatting
- Input Handling: data entry with validation
- Output Display: reports, student info, error messages
```

### Validator Class
```cpp
- Input Validation: cedula (10 digits), edad (18-100), notas (0-100)
- Data Constraints: unique cedula, required fields
- Error Messages: standardized validation feedback
```

### StudentSystem Class
```cpp
- System Coordination: orchestrates all components
- Business Logic: student operations, grade management
- Data Management: in-memory data structures
- Operation Flow: menu → validation → processing → persistence
```

## Key Design Benefits

### 1. **Separation of Concerns**
- Each class has a single, well-defined responsibility
- UI logic separated from business logic and data persistence

### 2. **Modularity**
- Components can be developed and tested independently
- Easy to modify one area without affecting others

### 3. **Maintainability**
- Clear structure makes code easier to understand and modify
- Validation logic centralized in one place

### 4. **Extensibility**
- Easy to add new features (e.g., new grade types, additional reports)
- Interface-based design allows for component swapping

### 5. **Error Handling**
- Centralized error handling in main()
- Component-level error management and reporting

## File Structure
```
intro-progra-2/
├── main.cpp              # Entry point
├── StudentSystem.h/.cpp  # Main controller
├── Student.h/.cpp        # Student data model
├── Grade.h/.cpp          # Grade data model  
├── FileManager.h/.cpp    # File operations
├── MenuManager.h/.cpp    # User interface
├── Validator.h/.cpp      # Input validation
├── Makefile             # Build configuration
├── ESTUDIANTES.txt      # Student data file
└── NOTAS.txt           # Grades data file
```

## Next Steps

1. **Implement .cpp files**: Create implementations for all classes
2. **Add validation logic**: Complete all validation methods
3. **Implement file I/O**: Complete persistence operations
4. **Add error handling**: Implement try-catch blocks
5. **Create user flows**: Complete menu operations
6. **Add reporting**: Implement grade reports and statistics

## Compilation

Use the provided Makefile:
```bash
make           # Compile the project
make run       # Compile and run
make clean     # Clean compiled files
make help      # Show all available commands
```

This object-oriented design provides a solid foundation for implementing all the required functionality while maintaining clean, maintainable code. 