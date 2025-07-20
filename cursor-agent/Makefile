# Makefile para Sistema de Gestión de Estudiantes
# Universidad Estatal a Distancia de Costa Rica
# Proyecto 2 - Introducción a la Programación

# Configuración del compilador
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -O2
TARGET = student_system
SRCDIR = .
OBJDIR = obj

# Archivos fuente y objetos
SOURCES = main.cpp Student.cpp Grade.cpp FileManager.cpp MenuManager.cpp Validator.cpp StudentSystem.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = Student.h Grade.h FileManager.h MenuManager.h Validator.h StudentSystem.h

# Regla principal
all: $(TARGET)

# Crear el ejecutable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilar archivos objeto
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Reglas de limpieza
clean:
	rm -f *.o $(TARGET) *.txt *.bak

clean-data:
	rm -f ESTUDIANTES.txt NOTAS.txt *.bak

# Reglas de utilidad
run: $(TARGET)
	./$(TARGET)

debug: CXXFLAGS += -DDEBUG -g3
debug: $(TARGET)

release: CXXFLAGS += -O3 -DNDEBUG
release: clean $(TARGET)

# Reglas de ayuda
help:
	@echo "Comandos disponibles:"
	@echo "  make          - Compilar el proyecto"
	@echo "  make run      - Compilar y ejecutar"
	@echo "  make debug    - Compilar en modo debug"
	@echo "  make release  - Compilar optimizado"
	@echo "  make clean    - Limpiar archivos compilados"
	@echo "  make clean-data - Limpiar archivos de datos"
	@echo "  make help     - Mostrar esta ayuda"

# Verificar que existen los archivos fuente
check:
	@echo "Verificando archivos del proyecto..."
	@for file in $(SOURCES) $(HEADERS); do \
		if [ ! -f $$file ]; then \
			echo "⚠️  Archivo faltante: $$file"; \
		else \
			echo "✓ $$file"; \
		fi \
	done

# Crear archivos .cpp placeholder si no existen
create-cpp:
	@for src in $(filter %.cpp, $(SOURCES)); do \
		if [ ! -f $$src ] && [ $$src != "main.cpp" ]; then \
			echo "Creando $$src..."; \
			echo '#include "'$${src%.cpp}'.h"' > $$src; \
			echo '' >> $$src; \
			echo '// Implementaciones a completar' >> $$src; \
		fi \
	done

.PHONY: all clean clean-data run debug release help check create-cpp 