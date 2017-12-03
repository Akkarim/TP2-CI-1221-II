#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <iostream>
#include <string>
#include <vector>

//#include "Grafo/MatrizAdyacencia.h"
#include "Grafo/ListaAdyacencia.h"
#include "Diccionario/Diccionario.h"

//typedef MatrizAdyacencia grafos;
typedef Grafo_ListaAdyacencia* grafos;
typedef Diccionario<vertice> diccionarios;
typedef Diccionario<vertice> Dvv;

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
    void Prim(const grafos& g);

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

    //EFE: Devuelve el número de soluciones factibles y la solución óptima
    //REQ: G inicializado con más de 2 vértices
    //MOD: ---
    void Vendedor(const grafos& g);

    
private:
    vertice* VendedorRec(const grafos& g, vertice vrt, int peso, vertice* v);
    int solOptima;
    vertice* mejorRuta;
    int numSolFacts;
    Dvv dvv;
    
    vertice Pivote(const grafos& g);
};

#endif /* ALGORITMOS_H */
