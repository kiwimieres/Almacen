# Sistema de Gestión - Cocina Comunitaria Muñecas II 🍲

Proyecto académico introductorio de primer año desarrollado íntegramente en **C** bajo el paradigma de programación estructurada. El sistema fue diseñado para administrar el inventario, personal y control de asistencia de una cocina comunitaria, implementando persistencia de datos puramente a través de **archivos binarios** (`.dat`) sin utilizar bases de datos ni Programación Orientada a Objetos.

## 🛠️ Tecnologías y Conceptos Aplicados

* **Lenguaje:** C (Estándar estructurado).
* **Persistencia:** Manejo avanzado de archivos binarios (`fread`, `fwrite`, `fseek`)[cite: 4].
* **Estructuras de Datos:** Uso intensivo de `structs` para modelar Usuarios, Personas y Productos[cite: 4].
* **Algoritmia:** Implementación de ordenamiento (Bubble Sort) con manipulación directa de punteros en disco para sortear limitaciones de memoria RAM[cite: 4].
* **Validaciones:** Desarrollo de algoritmos lógicos iterativos para control estricto de seguridad en contraseñas y datos de entrada[cite: 4].

## ⚙️ Características Principales

### 1. Control de Acceso (Login)
* Módulo de registro con políticas estrictas de seguridad (longitud, caracteres alfanuméricos, mayúsculas, minúsculas y prevención de caracteres consecutivos)[cite: 4].
* Autenticación de usuarios validada directamente contra registros binarios[cite: 4].

### 2. Gestión de Personal
* Sistema CRUD (Alta, Baja lógica, Modificación y Lectura) para registrar asistentes mediante nombre y DNI[cite: 4].
* Módulo de toma de asistencia diaria[cite: 4].
* Listado interactivo ordenado alfabéticamente en tiempo real[cite: 4].

### 3. Gestión de Almacén e Inventario
* Administración completa de productos (código, nombre, stock y precio)[cite: 4].
* Borrado lógico y reactivación de productos discontinuados[cite: 4].
* Modificación directa de registros específicos en el archivo sin necesidad de cargar la base de datos completa en memoria[cite: 4].

### 4. Módulo Financiero
* Cálculo automático de gastos totales basado en el consumo de productos y su precio unitario[cite: 4].
* División del gasto per cápita cruzando los datos de consumo con la asistencia diaria registrada[cite: 4].

## 🚀 Compilación y Ejecución

1. Clonar el repositorio:
   ```bash
   git clone [https://github.com/kiwimieres/Almacen.git](https://github.com/kiwimieres/Almacen.git)
2. Abrir el proyecto en un IDE compatible con C/C++ (ej. Visual Studio, Dev-C++ o VS Code).
3. Asegurarse de que los archivos de datos (Personas.dat, Productos.dat, usuarios.dat) se encuentren en el directorio raíz junto al ejecutable.
4. Compilar el archivo principal que contiene la función main() (TFI_2.cpp) vinculando el encabezado libreria_2.h[cite: 3, 4].

## Desarrollado por la Comisión 1k3 (2024):
- Mieres Gerhardt, Sebastian Segundo
- Brizuela, Santiago
- Yurcovich de Armas, Ernesto

#### Proyecto Académico - Universidad Tecnológica Nacional (UTN)
