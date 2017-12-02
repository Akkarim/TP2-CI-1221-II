#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <iostream>
#include <string>

//#include "Grafo/MatrizAdyacencia.h"
#include "Grafo/ListaAdyacencia.h"
#include "Diccionario/Diccionario.h"
#include "ColadePrioridades/ColaPrioridades.h"
#include "ConjuntodeConjuntos/CnjCnjs.h"

//typedef MatrizAdyacencia grafos;
typedef ListaAdyacencia* grafos;
typedef Diccionario<vertice> diccionarios;
typedef ColaPrioridades<pair<vertice, vertice>> colaPrioridades;
typedef Diccionario<pair <vertice, vertice>> diccionarioAristasVisitadas; // Diccionario de Aristas visitadas
typedef CnjCnjs<vertice> conjuntodConjs;

using namespace std;

class AlgoritmosGrafos {
public:
    AlgoritmosGrafos();
    AlgoritmosGrafos(const AlgoritmosGrafos& orig);
    virtual ~AlgoritmosGrafos();

    //EFE: Busca el camino más corto entre un vértice y todos los demás
    //REQ: G inicializado con más de 2 vértices
    //MOD: ---
    void Dijkstra(grafos, vertice);

    //EFE: Nos da el camino más corto entre todo par de vértices
    //REQ: G inicializado con más de 2 vértices
    //MOD: ---    
    void Floyd(grafos);

    //EFE: Busca el árbol de mínimo costo de un grafo G, se basa en los vértices
    //REQ: G inicializado con más de 2 vértices
    //MOD: ---
    void Prim(grafos); // falta

    //EFE: Busca el árbol de mínimo costo de un grafo G, se basa en las aristas
    //REQ: G inicializado con más de 2 vértices
    //MOD: ---
    void Kruscal(grafos); // falta

    //EFE: Copia G en un nuevo grafo
    //REQ: G inicializado con más de 2 vértices
    //MOD: G2
    void Copiar(grafos, grafos);

    //EFE: Retorna true un G1 es igual a G2
    //REQ: G1 y G2 inicializado con más de 2 vértices
    //MOD: ---
    bool Iguales(grafos, grafos);

    //EFE: 
    //REQ: G inicializado con más de 2 vértices
    //MOD: ---
    void Vendedor(grafos); // falta

};

#endif /* ALGORITMOS_H */
