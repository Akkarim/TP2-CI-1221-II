#ifndef MATRIZADYACENCIA_H
#define MATRIZADYACENCIA_H
using namespace std;
#include <string.h>
#include <iostream>

struct VerticeM {
    string etiqueta;
    int nAdyacentes;
    
    VerticeM(){
        etiqueta = "";
        nAdyacentes = 0;
    }


    VerticeM(string e) {
        etiqueta = e;
        nAdyacentes = 0;
    }

};

typedef VerticeM vertice;
class MatrizAdyacencia {
public:
    //EFE: Inicializa la matriz
    //REQ: Matriz no inicializada
    //MOD: Matriz
    void Crear();
    
    //EFE: Destruye la matriz
    //REQ: Matriz inicializada
    //MOD: Matriz
    void Destruir();
    
    //EFE: Vacia la matriz 
    //REQ: Matriz Inicializada
    //MOD: ---
    void Vaciar();
    
    //EFE: Retorna un booleano al preguntar si la matriz esta vacia
    //REQ: Matriz inicializada
    //MOD: ---
    bool Vacio();
    
    //EFE: Agrega un vertice y lo retorna
    //REQ: Matriz inicializada
    //MOD: vector vertices
    vertice AgregarVertice(string etiqueta);
    
    //EFE: Elimina un vertice aislado
    //REQ: Matriz inicializada
    //MOD: vector vertices
    void EliminarVertice(vertice v);
    
      //EFE: Crea la arista entre 2 vertices y les pone peso
      //REQ: Existe Ver1 y Ver2
      //MOD: MatrizAdyacencia, MatrizCostes
    void AgregarArista(vertice ver1, vertice ver2, int peso);
    
      //EFE: Elimina la Arista entre Ver1 y Ver2
      //REQ: Ver1 y Ver2 existe, Arista entre ellos tambien existe
      //MOD: MatrizAdyacencias, MatrizCostes.
    void EliminarArista(vertice ver1, vertice ver2);
    
      //EFE: Modifica la Etiqueta de un vertice
      //REQ: verticeExiste
      //MOD: etiqueta de Ver
    void ModificarEtiqueta(string,vertice);
    
      //EFE: Retorna la etiqueta del ver
      //REQ: ver existente
      //MOD: ---
    string Etiqueta(vertice ver);
    
      //EFE: Modifica el peso de la arista entre Ver1 y Ver2
      //REQ: Existe Arista entre Ver1 y Ver2
      //MOD: MatrizCostes
   void ModificarPeso(vertice ver1, vertice ver2, int peso);
   
      //EFE: retorna el peso de la arista entre 2 vertices
      //REQ: Existe Arista entre Ver1 y Ver2
      //MOD: ---
    int Peso(vertice ver1, vertice ver2);
    
      //EFE: Retorna true si existe adyacencia entre 2 vertices 
      //REQ: Existe Ver1 y Ver 2
      //MOD: ---
    bool Adyacentes(vertice ver1, vertice ver2);
    
      //EFE: Retorna el primer 
      //REQ: Matriz inicializada y no vacia
      //MOD: ---
    vertice PrimerVertice();
    
      //EFE: retorna el Siguiente Vertice
      //REQ: Matriz inicializada
      //MOD: ---
    vertice SiguienteVertice(vertice vrt);
    
      //EFE: retorna el total de vertices
      //REQ: Matriz Inicializada
      //MOD: ---
    int NumVertices();
    
      //EFE: retorna el total de vertices adyacentes de un nodo
      //REQ: Existe Ver
      //MOD: ---
    int NumVerticesAdyacentes(vertice ver);
    
    //EFE: devuelve el primer vertice adyacente a vrt.
    //REQ: Grafo inicializado y no vacío, vrt pertenezca al grafo.
    //MOD: ---
    vertice PrimerVerticeAdyacente(vertice vrt);
    
    //EFE: devuelve el otro vertice adyacente a vrt1 diferente a vrt2.
    //REQ: Grafo inicializado y no vacío, vrt pertenezca al grafo.
    //MOD: ---
    vertice SiguienteVerticeAdyacente(vertice vrt1,vertice vrt2);
    
    vertice ConvierteVertice(string e);    
    void Listar();
    
private:
    int matrizCostes[30][30];
    VerticeM arrayVert[30];
    int numVertice;

};
#endif /* MATRIZADYACENCIA_H */
