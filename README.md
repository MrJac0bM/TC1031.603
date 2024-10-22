
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

## SICT0302: Toma de decisiones

En este proyecto, tomé decisiones clave al seleccionar los algoritmos y estructuras de datos más adecuadas para organizar y gestionar los equipos en función de su puntaje. A continuación, se explica por qué seleccioné **QuickSort** para el ordenamiento y el **árbol binario de búsqueda (BST)** para la organización y búsqueda de los equipos.

### Selección de algoritmo de ordenamiento

Para el problema de ordenar los equipos por puntaje, seleccioné el algoritmo **QuickSort**. La razón de esta elección se basa en su alta eficiencia tanto en promedio como en su mejor caso, en comparación con otros algoritmos de ordenamiento como **Bubble Sort** o **Insertion Sort**.

**QuickSort** es un algoritmo de ordenamiento basado en dividir y conquistar. Su funcionamiento consiste en seleccionar un elemento como pivote y luego particionar los elementos en subarreglos, uno con elementos menores al pivote y otro con elementos mayores. Este proceso se repite recursivamente hasta que los subarreglos estén ordenados.

#### Justificación de la elección del algoritmo:

- **Mejor caso (O(n log n))**: El mejor caso ocurre cuando el pivote seleccionado divide los elementos de manera balanceada, es decir, cuando el pivote está cerca del valor medio de la lista. En este caso, cada partición reduce significativamente el número de elementos a procesar, logrando una complejidad de **O(n log n)**, que es más eficiente que otros algoritmos como **MergeSort**, que necesita espacio adicional.

- **Caso promedio (O(n log n))**: En la mayoría de las situaciones, **QuickSort** logra un rendimiento promedio de **O(n log n)**, debido a que los pivotes suelen dividir los datos de manera razonablemente balanceada. Esto lo hace una excelente opción cuando no se tiene conocimiento previo de la disposición de los datos, ya que puede manejar eficientemente conjuntos de datos desordenados o semidesordenados.

- **Peor caso (O(n²))**: El peor caso se da cuando el pivote seleccionado es el menor o el mayor elemento de la lista repetidamente, lo que genera particiones extremadamente desbalanceadas. Este escenario ocurre, por ejemplo, si la lista ya está ordenada o inversamente ordenada. Sin embargo, este comportamiento se puede mitigar mediante la selección aleatoria del pivote o mediante algoritmos optimizados como **QuickSort dual-pivot**.

#### Por qué **QuickSort** es adecuado para este problema:

- **Eficiencia promedio**: El proyecto maneja listas de equipos que pueden variar en tamaño, y **QuickSort** ofrece una solución eficiente, con una complejidad promedio de **O(n log n)** que es suficiente para ordenar listas de varios tamaños sin incurrir en grandes penalizaciones de tiempo.

- **Espacio eficiente**: A diferencia de otros algoritmos como **MergeSort**, que requiere espacio adicional de **O(n)** para los subarreglos, **QuickSort** solo necesita **O(log n)** espacio adicional para las llamadas recursivas. Esto lo hace más adecuado cuando se busca optimizar tanto tiempo como espacio, lo cual es importante en proyectos que pueden manejar grandes volúmenes de datos.

- **Aplicación directa a puntajes**: Como el puntaje de los equipos es un valor numérico fácilmente comparable, **QuickSort** es ideal para ordenar estos datos y permitir luego la búsqueda eficiente.

---

### Selección de la estructura de datos

En cuanto a la estructura de datos, seleccioné un **árbol binario de búsqueda (BST)** para almacenar y organizar los equipos en función de su puntaje. Esta elección se basó en la necesidad de realizar operaciones rápidas de búsqueda, inserción y organización jerárquica de los equipos.

**BST** es una estructura de datos en la que cada nodo tiene como máximo dos hijos, uno a la izquierda y otro a la derecha. Los elementos menores que el nodo se colocan en el subárbol izquierdo, y los mayores se colocan en el subárbol derecho. Esta estructura permite realizar búsquedas, inserciones y eliminaciones de manera eficiente.

#### Justificación de la elección de la estructura de datos:

- **Mejor caso (O(log n))**: En el mejor de los casos, el **BST** está balanceado, es decir, cada nodo tiene aproximadamente el mismo número de nodos a la izquierda y a la derecha. En este escenario, la altura del árbol es logarítmica con respecto al número de nodos, lo que permite realizar búsquedas, inserciones y eliminaciones en **O(log n)**. Esto es altamente eficiente, especialmente cuando se necesita hacer varias operaciones sobre los datos, como es el caso de este proyecto.

- **Caso promedio (O(log n))**: En la mayoría de los casos, el **BST** tiende a estar razonablemente balanceado, lo que significa que las operaciones en el árbol aún se pueden realizar en **O(log n)**. Esto lo hace adecuado para manejar datos de puntaje que no estén ordenados previamente ni presenten patrones específicos de orden.

- **Peor caso (O(n))**: El peor caso ocurre cuando los elementos se insertan de manera que el árbol se convierte en una lista enlazada, es decir, cuando todos los nodos se encuentran en un solo camino (por ejemplo, al insertar datos ya ordenados). En este caso, las operaciones tienen una complejidad de **O(n)**, similar a la de una lista enlazada. Sin embargo, este problema puede ser mitigado utilizando técnicas como la **auto-balanceo** (aunque no se implementó en este proyecto), o reinsertando los elementos en otro orden.

#### Por qué el **BST** es adecuado para este problema:

- **Eficiencia en búsqueda y organización**: Como el proyecto necesita organizar los equipos en función de su puntaje y permitir búsquedas rápidas de jugadores en función de ese puntaje, el **BST** es una opción ideal. A diferencia de una lista o un array, donde las búsquedas podrían ser lineales, el **BST** permite encontrar un equipo con un puntaje dado en **O(log n)** en la mayoría de los casos, lo que reduce significativamente el tiempo de consulta.

- **Flexibilidad para inserciones dinámicas**: El **BST** permite insertar nuevos equipos sin necesidad de reorganizar los datos existentes, lo que lo hace adecuado para un sistema donde se espera que los datos cambien dinámicamente. Las operaciones de inserción también se realizan en **O(log n)** en el mejor y caso promedio, lo que permite una actualización eficiente de los equipos.

- **Comparación con otras estructuras**: Aunque una lista enlazada o un array podrían haber sido utilizados para organizar los equipos, estas estructuras no serían tan eficientes para las búsquedas y actualizaciones dinámicas. Una lista enlazada no permitiría realizar búsquedas rápidas, ya que requeriría recorrer la lista de manera secuencial, resultando en **O(n)** para las búsquedas. Por otro lado, aunque un array podría ofrecer acceso directo a elementos, requeriría reordenar los elementos manualmente después de cada inserción, lo que es menos eficiente que un **BST**.

### SICT0303: Implementa acciones científicas

#### Implementa mecanismos para consultar información de las estructuras correctos.
- **Argumento**: Implementé mecanismos eficientes de consulta, utilizando tanto búsqueda binaria en la lista ordenada como el recorrido in-order en el árbol binario. Esto me permitió consultar los equipos de manera rápida y precisa, dependiendo del puntaje o el orden jerárquico.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
- **Argumento**: En este avance, implementé la funcionalidad de cargar datos de equipos desde un archivo **CSV**. Esto permite gestionar los datos de manera dinámica y eficiente. Los equipos se cargan desde un archivo externo, mejorando la flexibilidad del programa.
