# Proyecto de Gestión de Equipos de eSports

Este proyecto gestiona una lista de equipos de eSports, permitiendo ordenar los equipos por puntaje, buscar equipos por puntaje específico, y mostrar la información de los equipos de manera organizada.

## Comportamiento del Programa

1. **Agregar Equipos**:
   Se añaden equipos al sistema con la información del jugador, nombre del equipo, edad, región y puntaje.

2. **Ordenar Equipos**:
   El programa ordena los equipos por puntaje de mayor a menor utilizando el algoritmo de Quick Sort.

3. **Buscar Equipos**:
   Permite buscar un equipo por su puntaje utilizando la búsqueda binaria.

4. **Mostrar Equipos**:
   Muestra la lista de equipos con su información después de ordenar.

### Ejemplo de Uso

> **Paso 1**: Crear una lista de equipos con la siguiente información:
> 
> - MrSavage, 100 Thieves, 20 años, Norway, 999 puntos
> - Bugha, DIG, 21 años, United States of America, 288 puntos
> - Jakpo, Falcon, 18 años, Poland, 330 puntos
> 
> **Paso 2**: Ordenar los equipos por puntaje.
> 
> **Paso 3**: Mostrar la lista de equipos ordenada.
> 
> **Paso 4**: Buscar un equipo con un puntaje específico.

## Estructura del Proyecto

### Archivos Principales

- `Equipo.h`: Define la clase `Equipo` con atributos y métodos para gestionar los equipos.
- `main.cpp`: Contiene el código principal para ejecutar el programa.

### Descripción de la Clase `Equipo`

La clase `Equipo` incluye:
- **Atributos**: nombre del jugador, nombre del equipo, edad, región y puntaje.
- **Métodos**:
  - Constructor por defecto y con parámetros.
  - Getters para acceder a los atributos.

### Funciones Principales

- **`mostrar_equipos`**: Muestra la información de todos los equipos.
- **`ordenar_equipos`**: Ordena los equipos por puntaje utilizando Quick Sort.
- **`busqueda_binaria_puntaje`**: Busca un equipo por su puntaje usando búsqueda binaria.

## Algoritmos Utilizados

### Algoritmo de Ordenamiento

Se utiliza el algoritmo de Quick Sort para ordenar los equipos por puntaje de mayor a menor. Quick Sort es eficiente incluso con listas grandes y tiene un rendimiento óptimo en la mayoría de los casos.

### Búsqueda Binaria

La búsqueda binaria se usa para encontrar un equipo con un puntaje específico en la lista ordenada. Es eficiente con listas grandes debido a su complejidad O(log n).

## Casos de Prueba

Los casos de prueba verifican las siguientes funcionalidades:
- **Ordenamiento**: Comprueba que los equipos se ordenen correctamente por puntaje.
- **Búsqueda**: Verifica que se pueda encontrar un equipo por su puntaje.
- **Visualización**: Asegura que la información de los equipos se muestre correctamente después del ordenamiento.

### Ejemplos de Casos de Prueba

1. **Ordenamiento**: 
   - Entrada: Lista de equipos desordenada.
   - Salida esperada: Lista ordenada por puntaje.

2. **Búsqueda**:
   - Entrada: Puntaje específico.
   - Salida esperada: Información del equipo con el puntaje buscado o mensaje de equipo no encontrado.

## Análisis de Complejidad

### Ordenamiento

- **Quick Sort**:
  - **Mejor caso**: O(n log n), cuando el pivote divide bien los datos.
  - **Caso promedio**: O(n log n), es el comportamiento esperado para listas aleatorias.
  - **Peor caso**: O(n^2), cuando el pivote es el menor o mayor en una lista ya ordenada o casi ordenada.

### Búsqueda

- **Búsqueda Binaria**: O(log n) debido a la división repetida de la lista.

## Implementación

### Consultas

El programa permite consultar la información de los equipos y realizar búsquedas por puntaje desde el menú principal.

### Lectura y Escritura de Archivos

Actualmente, el proyecto no incluye lectura o escritura de archivos, pero se puede ampliar para guardar y cargar la información de los equipos en un archivo CSV si es necesario.
