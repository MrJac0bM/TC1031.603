# Proyecto: Gestión de Equipos de Competencia

Este proyecto tiene como objetivo gestionar información sobre equipos y jugadores de competencias. Utiliza un **árbol binario de búsqueda (ABB)** para organizar los equipos de acuerdo con sus puntajes de manera eficiente. El sistema permite **visualizar, ordenar y buscar equipos** usando un menú interactivo. Los datos de los equipos se cargan desde un archivo CSV para facilitar la gestión dinámica de información.

---

## Descripción del Avance 1

En el primer avance, se implementó la clase `Equipo`, que define los atributos de cada equipo y jugador, como el nombre del equipo, nombre del jugador, edad, nacionalidad y puntaje. También se añadieron funciones para mostrar los equipos y ordenarlos por puntaje utilizando **QuickSort**. La funcionalidad de búsqueda binaria permitía encontrar jugadores en función de su puntaje. El menú inicial incluía opciones para ver los equipos, ordenarlos por puntaje o buscar un equipo específico.

### Implementaciones en el Código (Avance 1)

1. **Clase `Equipo`**: Define los atributos del equipo y jugador.
   - **Archivo**: `Equipo.h`.
   - **Métodos**: `get_nombre_jugador`, `get_nombre_equipo`, `get_edad_jugador`, `get_nacionalidad`, `get_puntaje`.
2. **Función `QuickSort`**: Ordena los equipos por puntaje.
   - **Archivo**: `Equipo.h`.
   - **Método**: `quick_sort`.
3. **Función de Búsqueda Binaria**: Busca un equipo por puntaje en un arreglo ordenado.
   - **Archivo**: `Equipo.h`.
   - **Método**: `busqueda_binaria`.

---

## Descripción del Avance 2

En el segundo avance, el proyecto evolucionó al **usar un árbol binario de búsqueda (ABB)** como estructura de datos principal. Esto permitió una **organización jerárquica** de los equipos según su puntaje, lo cual facilita tanto la búsqueda de puntajes específicos como el cálculo de estadísticas sobre el árbol (como el puntaje máximo, mínimo y promedio). Además, se implementó la carga de equipos desde un archivo CSV, haciendo que el sistema sea más flexible y dinámico.

### Implementaciones en el Código (Avance 2)

1. **Clase `Nodo`**: Define cada nodo del ABB, almacenando un equipo y punteros a nodos hijos.
   - **Archivo**: `Equipo.h`.
   - **Estructura**: `Nodo`.
2. **Clase `Arbol` (ABB)**: Gestiona la organización jerárquica de los equipos en el árbol, permite insertar, consultar y calcular estadísticas.
   - **Archivo**: `Equipo.h`.
   - **Métodos**:
      - `insertar_nodo`: Inserta un equipo en el ABB.
      - `imprimir_in_order`: Muestra los equipos en el orden del ABB.
      - `equipo_max_puntaje` y `equipo_min_puntaje`: Encuentran el equipo con puntaje máximo y mínimo.
      - `promedio_puntajes`: Calcula el puntaje promedio.
      - `contar_y_mostrar_por_rango`: Cuenta y muestra los equipos con puntajes dentro de un rango.
3. **Función `cargar_equipos_desde_csv`**: Carga datos de equipos desde un archivo CSV.
   - **Archivo**: `Equipo.h`.
   - **Método**: `cargar_equipos_desde_csv`.

---

## Cambios Sobre el Primer Avance

### 1. Carga de Equipos desde CSV

- **Razón del cambio**: Para mejorar la flexibilidad y permitir la carga dinámica de datos, se añadió la función `cargar_equipos_desde_csv`. Esto permite actualizar los equipos sin modificar el código fuente, facilitando el mantenimiento.
- **Ubicación en el código**: `cargar_equipos_desde_csv` se encuentra en `Equipo.h`. Lee el archivo CSV y añade cada equipo al ABB mediante el método `agregar_equipo` de la clase `Arbol`.

### 2. Árbol Binario de Búsqueda (ABB)

- **Razón del cambio**: Implementar el ABB mejora la organización jerárquica de los equipos, permitiendo una estructura que facilita la búsqueda de puntajes específicos y el cálculo de estadísticas en tiempo eficiente.
- **Ubicación en el código**: `Arbol` en `Equipo.h`, con métodos como `insertar_nodo`, `equipo_max_puntaje`, `equipo_min_puntaje` y `contar_y_mostrar_por_rango`.

### 3. Optimización del Menú

- **Razón del cambio**: Se mejoró el menú para incluir opciones avanzadas de búsqueda y visualización en el ABB, incluyendo la posibilidad de calcular estadísticas directamente desde el árbol y cargar equipos desde un archivo CSV.

---

## Instrucciones para Compilar el Proyecto

Asegúrate de estar en el directorio donde están tus archivos y utiliza el siguiente comando en la terminal:

```bash
g++ main.cpp -o main
```
**Instrucciones para Ejecutar el Proyecto**

Una vez compilado, ejecuta el programa con:

```bash
Copiar código:
./main
```

Esto ejecutará el proyecto usando el archivo compilado `main`.

---

## Configuración del Archivo CSV

El archivo CSV debe ubicarse en el mismo directorio que el ejecutable y debe contener los siguientes campos en cada línea:

- **Nombre del jugador**
- **Nombre del equipo**
- **Edad del jugador**
- **Nacionalidad del jugador**
- **Puntaje del jugador**


---

## Descripción de las Entradas y Salidas del Sistema

### Entradas

1. **Archivo CSV**: Contiene los datos iniciales de los equipos.
   - **Ubicación**: Configurable en `main.cpp`.
2. **Menú Interactivo**: Permite al usuario seleccionar acciones como:
   - Imprimir equipos en el orden del ABB.
   - Calcular puntaje promedio.
   - Contar y mostrar equipos en un rango de puntajes.

### Salidas

1. **Lista de equipos en el orden del ABB**: Muestra los equipos en el orden in-order del ABB.
2. **Estadísticas**:
   - Puntaje máximo y mínimo.
   - Puntaje promedio.
3. **Consulta de rangos**: Muestra equipos con puntajes dentro de un rango especificado.

---

## Desarrollo de Competencias

### SICT0301: Evalúa los Componentes

El proyecto realiza un análisis de complejidad de los algoritmos y estructuras de datos utilizados:

- **QuickSort**  
  - **Mejor caso**: O(n log n)
  - **Promedio**: O(n log n)
  - **Peor caso**: O(n²), cuando la lista está en orden ascendente o descendente.

- **ABB**  
  - **Mejor caso**: O(log n), cuando el árbol está balanceado.
  - **Caso promedio**: O(log n).
  - **Peor caso**: O(n), cuando el árbol es muy desbalanceado (similar a una lista enlazada).

> **Justificación**: El ABB se elige por su capacidad de manejar búsquedas y actualizaciones dinámicas, lo cual sería menos eficiente en una lista o un array, donde las búsquedas podrían ser lineales. Además, al organizar los equipos por puntaje en un árbol, se garantiza una mejor eficiencia en la consulta de puntajes y en la búsqueda de equipos específicos.

### SICT0302: Toma de Decisiones

En este proyecto, se seleccionaron **QuickSort** para el ordenamiento y el **ABB** para la organización y consulta de equipos, considerando varios factores:

1. **QuickSort**: Es un algoritmo de ordenamiento rápido y eficiente con una complejidad promedio de O(n log n). La elección se basa en su eficiencia tanto en el mejor como en el caso promedio, siendo más rápido que otros algoritmos como `MergeSort`, que necesita espacio adicional. QuickSort es apropiado en este proyecto porque no requiere memoria adicional y se adapta bien a conjuntos de datos de tamaño moderado.
2. **ABB**: Elegí el ABB porque permite búsquedas y consultas rápidas, especialmente al trabajar con datos dinámicos. Comparado con estructuras como listas enlazadas o arrays, el ABB permite insertar, buscar y organizar datos con una eficiencia superior, al tiempo que facilita la consulta de rangos y estadísticas en tiempo logarítmico en la mayoría de los casos.

### SICT0303: Implementa Acciones Científicas

Este proyecto implementa mecanismos de consulta en el ABB y permite la carga de datos desde archivos externos:

1. **Consulta en el ABB**: Las funciones `equipo_max_puntaje`, `equipo_min_puntaje`, `promedio_puntajes` y `contar_y_mostrar_por_rango` permiten consultar el árbol y obtener información detallada sobre los equipos y sus puntajes.
2. **Carga de datos desde archivo**: La función `cargar_equipos_desde_csv` permite cargar equipos dinámicamente desde un archivo CSV, mejorando la flexibilidad del programa y facilitando la gestión de datos externos.
