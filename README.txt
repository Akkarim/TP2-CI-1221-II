Segunda Tarea Programada


Objetivos:

·	Definir, especificar, implementar y usar el  modelo Grafo No Dirigido, con pesos en las aristas, sin lazos y sin aristas paralelas.

·	Definir, especificar, implementar y usar el  modelo Cola de Prioridad.

·	Definir, especificar, implementar y usar el  modelo Conjunto de Conjuntos Disjuntos.

·	Definir, especificar, implementar y usar el  modelo Diccionario.

·	Implementar un algoritmo de recorrido de grafos.

·	Implementar  algoritmos para encontrar caminos mínimos y árbol de mínimo costo.

·	Aplicar el método de Búsqueda Exhaustiva Pura para resolver dos problemas de optimización en grafos.



Especificaciones de la Tarea.


·	Definir formalmente el modelo Grafo No Dirigido, con pesos en las aristas, sin lazos y sin aristas paralelas.

·	Especificar de manera lógica, formal y completa los operadores básicos del Grafo No Dirigido con pesos en las aristas, sin lazos y sin aristas paralelas: Crear, Destruir, Vaciar,  Vacío, AgregarVértice (devuelve el vértice creado), EliminarVértice, ModificarEtiqueta, Etiqueta, AgregarArista, EliminarArista, ModificarPeso, Peso, Adyacentes (devuelve verdadero si v1 y v2 son adyacentes), PrimerVértice, SiguienteVértice, PrimerVérticeAdyacente, SiguienteVérticeAdyacente, NumVértices, NumVérticesAdyacentes. La especificación de cada operador  debe incluir: nombre, parámetros con sus tipos y  las cláusulas Efecto (claro, completo y conciso), Requiere y Modifica.

·	La etiqueta es de tipo hilera.

·	Implementar el modelo Grafo No Dirigido con pesos en las aristas, sin lazos y sin aristas paralelas utilizando la estructura de datos Matriz de Adyacencia.
·	Implementar el modelo Grafo No Dirigido con pesos en las aristas, sin lazos y sin aristas paralelas utilizando la estructura de datos Lista de Adyacencia (LSE-LSE).
·	Definir formalmente el modelo Cola de Prioridad.
·	Especificar de manera lógica, formal y completa los operadores básicos de la Cola de Prioridad: Crear, Destruir, Vaciar,  Vacía, Agregar, Eliminar y NumElem.  La especificación de cada operador  debe incluir: nombre, parámetros con sus tipos y  las cláusulas Efecto (claro, completo y conciso), Requiere y Modifica.
·	Implementar el  modelo Cola de Prioridad mediante la estructura de datos Árbol Parcialmente Ordenado,  implementado por Vector Heap.
·	Definir formalmente el modelo  Conjunto de Conjuntos
·	Especificar de manera lógica, formal y completa los operadores básicos del Conjunto de Conjuntos Disjuntos: Crear, Destruir, Vaciar,  Vacío, ConjuntoAlQuePertenece (devuelve la identificación del conjunto al que pertenece un elemento), AgregarConjunto (Agrega al Conjunto de Conjuntos un nuevo conjunto con un elemento.  El elemento y la a identificación del nuevo conjunto serán parámetros de este operador) ,  UnirConjuntos.   La especificación de cada operador  debe incluir: nombre, parámetros con sus tipos y  las cláusulas Efecto (claro, completo y conciso), Requiere y Modifica.
·	Implementar el  modelo Conjunto de Conjuntos mediante la estructura de datos Lista de Listas (LSE-LSE).
·	Definir formalmente el modelo Diccionario.
·	Especificar de manera lógica, formal y completa los operadores básicos del Diccionario: Crear, Destruir, Vaciar,  Vacío, Agregar, Eliminar, Pertenece, NumElem. La especificación de cada operador  debe incluir: nombre, parámetros con sus tipos y  las cláusulas Efecto (claro, completo y conciso), Requiere y Modifica.
·	Implementar el  modelo Diccionario mediante la estructura de datos Lista No Ordenada por LSE.
·	Implementar el algoritmo de Dijkstra, versión original.  Para implementar este algoritmo debe usar el Modelo Diccionario,  para llevar registro de los vértices que han sido escogidos como pivote.  Además debe usar  arreglo de una dimensión como estructura de datos auxiliar.
·	Implementar el algoritmo de Floyd.  Para  implementar este algoritmo debe usar arreglo de dos dimensiones como estructura de dato auxiliar.
·	Implementar el algoritmo de Prim.  Para implementar este algoritmo debe usar el Modelo Diccionario,  para llevar registro de los vértices que han sido escogidos como pivote.  Además debe usar  arreglo de una dimensión como estructura de datos auxiliar.
·	Implementar el algoritmo de Kruskal.  Para implementar este algoritmo debe usar el Modelo Cola de Prioridad y  el Modelo  Conjunto de Conjuntos.
·	Implementar un algoritmo para copiar un grafo.
·	Implementar un algoritmo para averiguar si dos grafos son iguales.  Para simplificar, puede suponer que no hay etiquetas repetidas.
·	Implementar el algoritmo para resolver el problema del Vendedor (problema de optimización) usando Búsqueda Exhaustiva Pura, para un grafo no necesariamente completo. El algoritmo deberá desplegar el número de soluciones factibles del problema y la solución óptima.  Para implementar este algoritmo debe usar el Modelo Diccionario.  Además debe usar  arreglo de una dimensión como estructura de datos auxiliar.

·	Hacer un programa de prueba que permita:

·	Trabajar con el grafo mediante el uso de sus operadores básicos
·	Aplicar Dijkstra
·	Aplicar Floyd
·	Aplicar Prim
·	Aplicar Kruskal
·	Copiar un grafo
·	Averiguar si dos grafos son iguales
·	Resolver el Problema del Vendedor mediante Búsqueda Exhaustiva Pura.

·	Calcular y analizar los tiempos reales de ejecución de:

-Los algoritmos implementados,  para determinar las diferencias  que se pueden dar al usar cada una de las implementaciones del grafo.

-Los algoritmos Prim y Kruskal, para compararlos y determinar sus diferencias en términos de tiempo.

-El algoritmo usado para resolver el problema del Vendedor, para grafos completos o incompletos de diferentes tamaños.
