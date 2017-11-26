Segunda Tarea Programada


Objetivos:

�	Definir, especificar, implementar y usar el  modelo Grafo No Dirigido, con pesos en las aristas, sin lazos y sin aristas paralelas.

�	Definir, especificar, implementar y usar el  modelo Cola de Prioridad.

�	Definir, especificar, implementar y usar el  modelo Conjunto de Conjuntos Disjuntos.

�	Definir, especificar, implementar y usar el  modelo Diccionario.

�	Implementar un algoritmo de recorrido de grafos.

�	Implementar  algoritmos para encontrar caminos m�nimos y �rbol de m�nimo costo.

�	Aplicar el m�todo de B�squeda Exhaustiva Pura para resolver dos problemas de optimizaci�n en grafos.



Especificaciones de la Tarea.


�	Definir formalmente el modelo Grafo No Dirigido, con pesos en las aristas, sin lazos y sin aristas paralelas.

�	Especificar de manera l�gica, formal y completa los operadores b�sicos del Grafo No Dirigido con pesos en las aristas, sin lazos y sin aristas paralelas: Crear, Destruir, Vaciar,  Vac�o, AgregarV�rtice (devuelve el v�rtice creado), EliminarV�rtice, ModificarEtiqueta, Etiqueta, AgregarArista, EliminarArista, ModificarPeso, Peso, Adyacentes (devuelve verdadero si v1 y v2 son adyacentes), PrimerV�rtice, SiguienteV�rtice, PrimerV�rticeAdyacente, SiguienteV�rticeAdyacente, NumV�rtices, NumV�rticesAdyacentes. La especificaci�n de cada operador  debe incluir: nombre, par�metros con sus tipos y  las cl�usulas Efecto (claro, completo y conciso), Requiere y Modifica.

�	La etiqueta es de tipo hilera.

�	Implementar el modelo Grafo No Dirigido con pesos en las aristas, sin lazos y sin aristas paralelas utilizando la estructura de datos Matriz de Adyacencia.
�	Implementar el modelo Grafo No Dirigido con pesos en las aristas, sin lazos y sin aristas paralelas utilizando la estructura de datos Lista de Adyacencia (LSE-LSE).
�	Definir formalmente el modelo Cola de Prioridad.
�	Especificar de manera l�gica, formal y completa los operadores b�sicos de la Cola de Prioridad: Crear, Destruir, Vaciar,  Vac�a, Agregar, Eliminar y NumElem.  La especificaci�n de cada operador  debe incluir: nombre, par�metros con sus tipos y  las cl�usulas Efecto (claro, completo y conciso), Requiere y Modifica.
�	Implementar el  modelo Cola de Prioridad mediante la estructura de datos �rbol Parcialmente Ordenado,  implementado por Vector Heap.
�	Definir formalmente el modelo  Conjunto de Conjuntos
�	Especificar de manera l�gica, formal y completa los operadores b�sicos del Conjunto de Conjuntos Disjuntos: Crear, Destruir, Vaciar,  Vac�o, ConjuntoAlQuePertenece (devuelve la identificaci�n del conjunto al que pertenece un elemento), AgregarConjunto (Agrega al Conjunto de Conjuntos un nuevo conjunto con un elemento.  El elemento y la a identificaci�n del nuevo conjunto ser�n par�metros de este operador) ,  UnirConjuntos.   La especificaci�n de cada operador  debe incluir: nombre, par�metros con sus tipos y  las cl�usulas Efecto (claro, completo y conciso), Requiere y Modifica.
�	Implementar el  modelo Conjunto de Conjuntos mediante la estructura de datos Lista de Listas (LSE-LSE).
�	Definir formalmente el modelo Diccionario.
�	Especificar de manera l�gica, formal y completa los operadores b�sicos del Diccionario: Crear, Destruir, Vaciar,  Vac�o, Agregar, Eliminar, Pertenece, NumElem. La especificaci�n de cada operador  debe incluir: nombre, par�metros con sus tipos y  las cl�usulas Efecto (claro, completo y conciso), Requiere y Modifica.
�	Implementar el  modelo Diccionario mediante la estructura de datos Lista No Ordenada por LSE.
�	Implementar el algoritmo de Dijkstra, versi�n original.  Para implementar este algoritmo debe usar el Modelo Diccionario,  para llevar registro de los v�rtices que han sido escogidos como pivote.  Adem�s debe usar  arreglo de una dimensi�n como estructura de datos auxiliar.
�	Implementar el algoritmo de Floyd.  Para  implementar este algoritmo debe usar arreglo de dos dimensiones como estructura de dato auxiliar.
�	Implementar el algoritmo de Prim.  Para implementar este algoritmo debe usar el Modelo Diccionario,  para llevar registro de los v�rtices que han sido escogidos como pivote.  Adem�s debe usar  arreglo de una dimensi�n como estructura de datos auxiliar.
�	Implementar el algoritmo de Kruskal.  Para implementar este algoritmo debe usar el Modelo Cola de Prioridad y  el Modelo  Conjunto de Conjuntos.
�	Implementar un algoritmo para copiar un grafo.
�	Implementar un algoritmo para averiguar si dos grafos son iguales.  Para simplificar, puede suponer que no hay etiquetas repetidas.
�	Implementar el algoritmo para resolver el problema del Vendedor (problema de optimizaci�n) usando B�squeda Exhaustiva Pura, para un grafo no necesariamente completo. El algoritmo deber� desplegar el n�mero de soluciones factibles del problema y la soluci�n �ptima.  Para implementar este algoritmo debe usar el Modelo Diccionario.  Adem�s debe usar  arreglo de una dimensi�n como estructura de datos auxiliar.

�	Hacer un programa de prueba que permita:

�	Trabajar con el grafo mediante el uso de sus operadores b�sicos
�	Aplicar Dijkstra
�	Aplicar Floyd
�	Aplicar Prim
�	Aplicar Kruskal
�	Copiar un grafo
�	Averiguar si dos grafos son iguales
�	Resolver el Problema del Vendedor mediante B�squeda Exhaustiva Pura.

�	Calcular y analizar los tiempos reales de ejecuci�n de:

-Los algoritmos implementados,  para determinar las diferencias  que se pueden dar al usar cada una de las implementaciones del grafo.

-Los algoritmos Prim y Kruskal, para compararlos y determinar sus diferencias en t�rminos de tiempo.

-El algoritmo usado para resolver el problema del Vendedor, para grafos completos o incompletos de diferentes tama�os.
