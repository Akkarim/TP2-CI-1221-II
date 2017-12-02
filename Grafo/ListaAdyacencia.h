#ifndef LISTAADYACENCIA_H
#define LISTAADYACENCIA_H

#include <iostream>
#include <string>
using namespace std;

struct Adyacente {
    string etqVertice;
    Adyacente *sig;
    int peso;

    Adyacente() {
        etqVertice = "";
        peso = 0;
        sig = 0;
    }

    Adyacente(string e, int p) {
        etqVertice = e;
        peso = p;
        sig = 0;
    }
};

struct Vertice {
    string etiqueta;
    Vertice *siguiente;

    Adyacente *ady;
    int n_verticesadyacentes;

    Vertice() {
        etiqueta = "";
        siguiente = 0;
        ady = new Adyacente("", -1);
    }

    Vertice(string e) {
        etiqueta = e;
        siguiente = 0;
        ady = new Adyacente("", -1);
    }
};

typedef Vertice* vertice;
typedef Adyacente* adyacente;

class ListaAdyacencia {
public:
    ListaAdyacencia();
    ListaAdyacencia(const ListaAdyacencia& orig);
    virtual ~ListaAdyacencia();

    //EFE: Crea un grafo vacio.
    //REQ: Grafo sin inicializar.
    //MOD: ---
    void Crear();

    //EFE: Destruye el grafo.
    //REQ: Grafo inicializado.
    //MOD: ---
    void Destruir();

    //EFE: Vacía el grafo.
    //REQ: Grafo inicializado.
    //MOD: ---
    void Vaciar();

    //EFE: Devuelve verdadero si el grafo está vacío, falso en caso contrario.
    //REQ: Grafo inicializado.
    //MOD: ---
    bool Vacio();

    //EFE: Agrega un nuevo vértice al grafo.
    //REQ: Grafo inicializado.
    //MOD: G
    void AgregarVertice(string);

    //EFE: Elimina un vertice de el grafo.
    //REQ: Vertice válido y aislado.
    //MOD: G
    void EliminarVertice(vertice);

    //EFE: Modifica la etiqueca del vertice.
    //REQ: Vertice válido.
    //MOD: Vrt
    void ModificarEtiqueta(string, vertice);

    //EFE: Devuelve la etiqueta del vertice.
    //REQ: értice válido.
    //MOD: ---
    string Etiqueta(vertice);

    //EFE: Agrega una arista que conecta a los vértices.
    //REQ: Vertices válidos.
    //MOD: ---
    void AgregarArista(vertice, vertice, int);

    //EFE: Elimina la arista que conecta a los vértices.
    //REQ: Vértices válidos.
    //MOD: ---
    void EliminarArista(vertice, vertice);

    //EFE: Modififica el peso de la arista que conecta a los vertices.
    //REQ: Vértices válidos.
    //MOD: Peso del arista.
    void ModificarPeso(vertice, vertice, int);

    //EFE: Devuelve el peso del arista que conecta a los vertices.
    //REQ: Vértices válidos.
    //MOD: ---
    int Peso(vertice, vertice);

    //EFE: Devuelve verdadero si los vertices son adyacentes, falso en caso contrario.
    //REQ: Vértices válidos.
    //MOD: ---
    bool Adyacentes(vertice, vertice);

    //EFE: Devuelve el primer vértice del grafo, nulo si no existe.
    //REQ: Grafo inicializado.
    //MOD: ---
    vertice PrimerVertice();

    //EFE: Devuelve el siguiente vértice al que es pasado por parámetro, nulo si no existe.
    //REQ: Vértice válido.
    //MOD: ---
    vertice SiguienteVertice(vertice);

    //EFE: Devuelve el primer vértice adyacente al que es pasado por parámetro, nulo si no existe.
    //REQ: Vértice válido.
    //MOD: ---
    vertice PrimerVerticeAdyacente(vertice);

    //EFE: Devuelve el vértice adyacente a el primero, que está después del segundo, nulo si no existe.
    //REQ: Vértices válidos.
    //MOD: ---
    vertice SiguienteVerticeAdyacente(vertice, vertice);

    //EFE: Devuelve el némero de vertices del grafo.  
    //REQ: Grafo inicializado.
    //MOD: ---
    int NumVertices();

    //EFE: Devuelve el número de vertices adyacentes al vértice.
    //REQ: Vértice válido.
    //MOD: ---
    int NumVerticesAdyacentes(vertice);

    //EFE: Lista todas las etiquetas del grafo.
    //REQ: Grafo inicializado.
    //MOD: ---
    void Listar();

    vertice ConvierteVertice(string);

private:
    int numVertices;
    vertice cabeza;

    //EFE: Elimina todas las aristas de un vertice. Implementado para Destruir y Vaciar.
    //REQ: Grafo inicializado.
    //MOD: Elimina los adyacentes a un vertice.
    void EliminarTodasAristas(adyacente);

    //EFE: Elimina todas los vertices. Implementado para Destruir y Vaciar.
    //REQ: Grafo inicializado.
    //MOD: Deja sin vertices al grafo.
    void EliminarTodosVertices(vertice);
};

#endif /* LISTAADYACENCIA_H */
