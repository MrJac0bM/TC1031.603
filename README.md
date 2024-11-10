# Proyecto: Gestión de Equipos de Competencia

Este proyecto tiene como objetivo gestionar información sobre equipos y jugadores de competencias. Se desarrolló una estructura de datos para organizar los equipos de acuerdo con sus puntajes de manera eficiente, utilizando un sistema de ordenamiento en el primer avance y un árbol binario de búsqueda (ABB) en el segundo avance. El sistema permite visualizar, ordenar y buscar equipos usando un menú interactivo, y los datos de los equipos se cargan desde un archivo CSV. Además, el sistema puede generar un archivo de texto para visualizar la estructura actual de los equipos en el ABB.

---

## Descripción del Avance 1

En el primer avance, se implementó una estructura de datos basada en un vector para almacenar los equipos y se desarrolló un sistema de ordenamiento para organizar estos equipos por puntaje utilizando el algoritmo QuickSort. Esto permitió ordenar los equipos de manera eficiente en el vector, optimizando el proceso de búsqueda de un equipo específico. Se incluyeron las funciones básicas para mostrar y ordenar los equipos, y el menú inicial permitía al usuario ver los equipos en orden de puntaje.

## Descripción del Avance 2
En el segundo avance, se implementó una estructura de datos basada en un árbol binario de búsqueda (ABB) para almacenar y organizar los equipos jerárquicamente de acuerdo con sus puntajes. Además, se añadió la funcionalidad de carga de datos desde un archivo CSV, lo que permite actualizar los equipos de manera dinámica sin modificar el código fuente. Esta estructura facilita la búsqueda de puntajes específicos y el cálculo de estadísticas de manera eficiente, maximizando el rendimiento del programa.

### Cambios sobre el primer avance

1. **Cambio 1: Implementación del Árbol Binario de Búsqueda (ABB):**
   - **Razón**: La estructura de ABB mejora la organización jerárquica de los equipos, permitiendo una búsqueda eficiente de puntajes específicos y el cálculo de estadísticas en tiempo óptimo.
   - **Ubicación**:Se implementó en la clase Arbol de Equipo.h, con métodos como `insertar_nodo`, `equipo_max_puntaje`, `equipo_min_puntaje` y `contar_y_mostrar_por_rango`. 
2. **Cambio 2: Carga de Equipos desde CSV**:
   - **Razón**: Se añadió la función `cargar_equipos_desde_csv` para mejorar la flexibilidad y permitir la carga dinámica de datos. Esto facilita actualizar los equipos sin necesidad de modificar el código fuente.

---

## Descripción del Avance 3

En el tercer avance, se añadió la capacidad de generar un archivo de texto (`estructura_arbol.txt`) que guarda la estructura del ABB en orden in-order. Esto permite visualizar la organización de los equipos directamente desde un archivo, proporcionando una manera fácil de consultar el estado actual de la estructura de datos fuera del programa.

### Cambios sobre el segundo avance

1. **Cambio 1: Generación de Archivo de Texto:**
   - **Razón**: La generación de un archivo de texto (estructura_arbol.txt) permite visualizar la estructura actual del ABB de manera externa, ofreciendo una representación directa y accesible de interpretar de los equipos y sus puntajes en el orden del árbol
   - **Ubicación**:Se implementó en la clase Arbol de Equipo.h, con métodos como `insertar_nodo`, `equipo_max_puntaje`, `equipo_min_puntaje` y `contar_y_mostrar_por_rango`. 
2. **Cambio 2: Carga de Equipos desde CSV**:
   - **Razón**: Se añadió la función `cargar_equipos_desde_csv` para mejorar la flexibilidad y permitir la carga dinámica de datos. Esto facilita actualizar los equipos sin necesidad de modificar el código fuente.
   - **Ubicación**: Método `guardar_en_archivo` en la clase Arbol, en `Equipo.h`

---

## Instrucciones para Compilar el Proyecto

Ejecuta el siguiente comando en la terminal:

```bash
g++ main.cpp -o gestion_equipos
```
**Instrucciones para Ejecutar el Proyecto**

Una vez compilado, ejecuta el programa con:

```bash
./gestion_equipos
```

Esto ejecutará el proyecto usando el archivo compilado `main`.

---

## Descripción de las Entradas y Salidas del Sistema

### Entradas

1. **Archivo CSV**: ontiene los datos iniciales de los equipos, ubicado en el mismo directorio que el ejecutable.
2. **Formato de archivo CSV:**: 
   - Nombre del jugador
   - Nombre del equipo
   - Edad del jugador
   - Nacionalidad del jugador
   - Puntaje del jugador
   
### Salidas

1. **Lista de equipos en el orden del ABB**: Muestra los equipos en el orden in-order del ABB.
2. **Estadísticas**:
   - Puntaje máximo y mínimo.
   - Puntaje promedio.
3. **Consulta de rangos**: Muestra equipos con puntajes dentro de un rango especificado.
4. **Archivo `estructura_arbol.txt`** : Guarda la estructura del árbol en orden in-order para consulta externa.

---

## Desarrollo de Competencias

### SICT0301: Evalúa los Componentes

Cada función en el ABB presenta una complejidad específica, que se analiza a continuación:

- **Función `insertar_nodo`**: Inserta un equipo en el ABB de acuerdo con su puntaje. Su complejidad promedio es O(log n) en un árbol balanceado, lo que permite una inserción rápida. Sin embargo, en el peor de los casos, si el árbol está desbalanceado, la complejidad podría ser O(n).

- **Función `imprimir_in_order`**: Recorre el árbol en orden para mostrar los equipos organizados. Su complejidad es O(n) porque debe visitar cada nodo una vez

- **Función `equipo_max_puntaje` y `equipo_min_puntaje`**: Buscan el equipo con el puntaje más alto o más bajo recorriendo el extremo derecho o izquierdo del árbol. Su complejidad es O(log n) en un árbol balanceado y O(n) en un árbol desbalanceado.

- **Función `promedio_puntajes`**: Calcula el puntaje promedio recorriendo todos los nodos del ABB. Su complejidad es O(n) ya que se debe visitar cada nodo para sumar sus puntajes.

- **Función `contar_y_mostrar_por_rango`**: Muestra los equipos dentro de un rango de puntajes. Su complejidad es O(n) en el caso de visitar todos los nodos en un rango amplio, aunque en la práctica se puede optimizar si el rango es pequeño.

- **Función `cargar_equipos_desde_csv`**: Carga los equipos en el ABB desde un archivo CSV. La complejidad depende de la cantidad de equipos, siendo O(n log n) en promedio, donde n es el número de líneas en el archivo, debido a que cada línea implica una inserción en el ABB.

**Complejidad general del programa**
La complejidad total del programa depende de los datos ingresados y del tipo de operación. En el caso de la carga de datos y creación del ABB, la complejidad es aproximadamente O(n log n), y para consultas de búsqueda o estadísticas, la complejidad promedio es de O(log n) por cada consulta. Estas eficiencias hacen que el programa sea escalable y mantenga un rendimiento óptimo incluso con grandes volúmenes de datos.

### SICT0302: Toma de Decisiones

**Elección de la estructura de datos: Árbol Binario de Búsqueda (ABB)**

Para organizar y gestionar de manera eficiente los equipos en función de sus puntajes, se optó por implementar un Árbol Binario de Búsqueda (ABB). Esta estructura permite almacenar datos de manera jerárquica y, a diferencia de listas o arrays, facilita la búsqueda rápida y la obtención de estadísticas clave como el puntaje máximo, mínimo y promedio.

**Ventajas del ABB frente a otras estructuras de datos:**

1. **Búsqueda rápida y eficiente**:  La estructura del ABB permite que las operaciones de búsqueda tengan una complejidad de O(log n) en promedio, siempre que el árbol esté balanceado. Esto mejora considerablemente el rendimiento frente a listas enlazadas o arrays, donde una búsqueda secuencial tendría una complejidad de O(n). En este proyecto, los usuarios necesitan consultar puntajes específicos y rangos de puntajes, por lo que el ABB se ajusta bien a estos requisitos de búsqueda rápida.
2. **Inserción y actualización eficientes**: Dado que el proyecto incluye la carga de datos desde un archivo CSV, es esencial una estructura que maneje eficientemente la inserción de elementos nuevos. En el ABB, cada equipo se inserta en su posición correcta según su puntaje, con una complejidad promedio de O(log n) en árboles balanceados. Esta eficiencia es esencial para cargar grandes cantidades de datos, como ocurre con el archivo CSV, sin afectar el rendimiento del programa.
3. **Inserción y actualización eficientes**: La jerarquía del ABB facilita cálculos como puntaje máximo, mínimo y promedio. Operaciones como encontrar el puntaje más alto o el más bajo requieren solo recorrer el extremo derecho o izquierdo del árbol, respectivamente, con una complejidad de O(log n) en promedio. Esta organización también optimiza la consulta de rangos específicos, ya que el árbol puede recortarse efectivamente para omitir ramas completas, lo cual no sería posible en una lista o un array.

**Justificación basada en la complejidad**:
- **Inserción y búsqueda**: Como se detalló en la sección **Evalúa los componentes**, las operaciones de inserción y búsqueda en el ABB tienen una complejidad de O(log n) en promedio, lo que garantiza un rendimiento constante a medida que aumenta el número de equipos
- **Flexibilidad en la consulta de datos**: La capacidad del ABB para segmentar su recorrido permite manejar grandes volúmenes de datos manteniendo la eficiencia, sin necesidad de recorrer la totalidad de la estructura.

### SICT0303: Implementa Acciones Científicas

Este proyecto implementa mecanismos de consulta en el ABB y permite la carga de datos desde archivos externos:

1. **Consulta en el ABB**: Las funciones `equipo_max_puntaje`, `equipo_min_puntaje`, `promedio_puntajes` y `contar_y_mostrar_por_rango` permiten consultar el árbol y obtener información detallada sobre los equipos y sus puntajes.
2. **Carga de datos desde archivo**: La función `cargar_equipos_desde_csv` permite cargar equipos dinámicamente desde un archivo CSV, mejorando la flexibilidad del programa y facilitando la gestión de datos externos.
