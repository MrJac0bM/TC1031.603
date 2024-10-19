
# Proyecto: Gestión de Equipos de Competencia

Este proyecto tiene como objetivo gestionar información sobre equipos y jugadores de competencias. Permite visualizar, ordenar y buscar equipos de manera eficiente utilizando algoritmos de ordenamiento y estructuras de datos. Implementé un menú interactivo que ofrece al usuario opciones para visualizar equipos, ordenarlos por puntaje, buscar jugadores y cargar la información de equipos desde un archivo CSV.

## Descripción del avance 1
En el primer avance, implementé una clase `Equipo` que contiene los atributos del jugador, equipo, edad, nacionalidad y puntaje. Añadí funciones para mostrar los equipos y ordenarlos por puntaje utilizando **QuickSort**. También implementé una función de **búsqueda binaria** para buscar un equipo en función de su puntaje. El menú interactivo ofrece al usuario opciones para visualizar los equipos en el orden ingresado, ordenarlos o buscar un equipo por puntaje.

## Descripción del avance 2
En este segundo avance, mejoré la funcionalidad al implementar un **árbol binario de búsqueda (BST)** para organizar y visualizar los equipos según su puntaje de manera jerárquica. También añadí la funcionalidad de **cargar equipos desde un archivo CSV**, lo que permite que los datos sean gestionados de manera dinámica, en lugar de estar codificados directamente en el programa.

### Cambios sobre el primer avance
1. **Carga de equipos desde CSV**:
   - **Razón del cambio**: Para mejorar la flexibilidad del programa y permitir la carga de datos dinámicos, se añadió la funcionalidad de cargar equipos desde un archivo CSV, facilitando la actualización de la información sin necesidad de modificar el código fuente.
   
2. **Árbol binario de búsqueda (BST)**:
   - **Razón del cambio**: Implementar el BST permite una mejor organización de los equipos y una visualización jerárquica basada en el puntaje.

3. **Optimización del menú**:
   - **Razón del cambio**: El menú fue mejorado para incluir la opción de insertar equipos en el BST y visualizarlos en el orden del árbol, así como cargar los equipos desde un archivo CSV.

## Instrucciones para compilar el avance de proyecto

Para compilar el proyecto, asegúrate de estar en el directorio donde están tus archivos y utiliza el siguiente comando en la terminal:

```bash
g++ main.cpp -o main
```

## Instrucciones para ejecutar el avance de proyecto

Una vez compilado el proyecto, ejecuta el programa con el siguiente comando:

```bash
./main
```

Esto ejecutará tu proyecto usando el archivo compilado con el nombre **main**.

### Configuración del archivo CSV
El programa permite cargar los datos de los equipos desde un archivo CSV. Para que el programa funcione correctamente, debes asegurarte de que la ruta del archivo CSV esté correctamente especificada en el código. Si cambias la ubicación del archivo en tu sistema, solo necesitas actualizar la ruta en el código donde se asigna la variable `archivo_csv`.

## Descripción de las **entradas del sistema**
Las entradas del sistema son obtenidas desde un archivo CSV que contiene la información de los equipos, así como las interacciones que el usuario realiza a través del menú interactivo. El archivo CSV debe tener un formato adecuado que incluya la siguiente información por cada equipo: 
1. Nombre del jugador.
2. Nombre del equipo.
3. Edad del jugador.
4. Nacionalidad del jugador.
5. Puntaje del jugador.

El usuario también debe interactuar a través del menú para seleccionar las acciones deseadas como:
- Imprimir equipos.
- Ordenar equipos por puntaje.
- Buscar equipos por puntaje.

## Descripción de las salidas del avance de proyecto
Las salidas incluyen:
1. **Lista de equipos en el orden ingresado**.
2. **Equipos ordenados por puntaje utilizando QuickSort**.
3. **Equipos organizados en el orden jerárquico del árbol binario**.
4. **Resultado de la búsqueda**: Si el puntaje buscado se encuentra, se muestra el nombre del jugador correspondiente; de lo contrario, se informa que el puntaje no fue encontrado.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes

#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

- **QuickSort**:
  - **Mejor caso**: **O(n log n)**, cuando el pivote divide de manera uniforme los subarreglos en cada partición.
  - **Caso promedio**: **O(n log n)**, lo que sucede en la mayoría de los casos cuando los subarreglos no están extremadamente desbalanceados.
  - **Peor caso**: **O(n^2)**, ocurre cuando el pivote elegido es el menor o mayor elemento en cada partición, lo que genera particiones muy desbalanceadas (por ejemplo, cuando la lista ya está ordenada en orden ascendente o descendente).

- **BST**:
  - **Mejor caso**: **O(log n)**, cuando el árbol está balanceado.
  - **Caso promedio**: **O(log n)**, cuando las inserciones en el árbol producen un árbol moderadamente balanceado.
  - **Peor caso**: **O(n)**, cuando el árbol es muy desbalanceado (similar a una lista enlazada), lo que ocurre cuando los datos se insertan en orden creciente o decreciente.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
- **Argumento**: La estructura del **árbol binario de búsqueda (BST)** permite insertar y organizar los equipos en función de su puntaje con una complejidad promedio de **O(log n)** para operaciones de inserción y búsqueda en un árbol balanceado, aunque puede llegar a **O(n)** en casos extremos. En el caso de **QuickSort**, el rendimiento promedio y mejor es **O(n log n)**, pero puede alcanzar **O(n^2)** en el peor de los casos.

### SICT0302: Toma decisiones

#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
- **Argumento**: **QuickSort** fue seleccionado por su alta eficiencia para ordenar equipos por puntaje. Su complejidad promedio de **O(n log n)** lo hace adecuado para manejar listas grandes. Además, permite ordenar de manera eficiente la lista de equipos en diferentes situaciones, aunque se debe tener en cuenta que en su peor caso puede llegar a **O(n^2)** si los datos están muy desbalanceados.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
- **Argumento**: Decidí utilizar un **árbol binario de búsqueda (BST)** porque necesitaba organizar y visualizar los equipos de manera jerárquica. El BST permite realizar búsquedas y consultas eficientes, con una complejidad de **O(log n)** en su mejor y caso promedio, aunque en el peor de los casos (si está desbalanceado) puede llegar a **O(n)**.

### SICT0303: Implementa acciones científicas

#### Implementa mecanismos para consultar información de las estructuras correctos.
- **Argumento**: Implementé mecanismos eficientes de consulta, utilizando tanto búsqueda binaria en la lista ordenada como el recorrido in-order en el árbol binario. Esto me permitió consultar los equipos de manera rápida y precisa, dependiendo del puntaje o el orden jerárquico.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
- **Argumento**: En este avance, implementé la funcionalidad de cargar datos de equipos desde un archivo **CSV**. Esto permite gestionar los datos de manera dinámica y eficiente. Los equipos se cargan desde un archivo externo, mejorando la flexibilidad del programa.
