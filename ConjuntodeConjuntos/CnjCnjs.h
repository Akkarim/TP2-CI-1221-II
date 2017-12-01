#ifndef CNJCNJS_H
#define CNJCNJS_H

#include <string>
using namespace std;

template < typename V>
class CnjCnjs{
public: 
    
    CnjCnjs();
    
    CnjCnjs(V elemento, string id);
    
    CnjCnjs(const CnjCnjs<V>& orig);
    
    virtual ~CnjCnjs();
    
    //EFE: Inicializa el Conjunto de conjuntos.
    //REQ:
    //MOD:
    void crear();
    
    //EFE: Destruye el Conjunto de conjuntos, lo deja inutilizable.
    //REQ:
    //MOD:
    void destruir();
    
    //EFE: Vacía el conjunto de conjuntos y se puede volver  usar.
    //REQ: El Conjunto de conjuntos inicializado.
    //MOD: El Conjunto de conjuntos.
    void vaciar();
    
    //EFE: Retorna true si el conjunto esta vacío, false si tiene al menos un elemento.
    //REQ: El Conjunto inicializado.
    //MOD:
    bool vacio();
    
    //EFE: Retorna el identificador del conjunto donde se encuentra el elemento.
    //REQ: El Conjunto inicializado y no vacio, y no elementos repetidos.
    //MOD:
    string cnjAlQuePertenece(V elemento);
    
    //EFE: Retorna true si el conjunto esta vacío, false si tiene al menos un elemento.
    //REQ: El Conjunto inicializado y no elementos repetidos.
    //MOD:
    void agregarConjunto(V elemento, string id);
    
    //EFE: Une dos conjuntos.
    //REQ: Ambos conjuntos inicializados y no vacios.
    //MOD: El primer conjunto.
    void unirConjuntos(string cnjUno, string cnjDos);
    
private:
    
    V* primerElemento = 0;
    V* sigElemento = 0;
    CnjCnjs* sigConjunto = 0;
    string identificador;
    static V* elementoNulo;
};

V* CnjCnjs<V>::elementoNulo = 0;

template < typename V >
CnjCnjs<V>::CnjCnjs(){
}

template < typename V >
CnjCnjs<V>::CnjCnjs(V* elemento, string id){
    identificador = id;
    primerElemento = elemento;
}

template < typename V >
CnjCnjs<V>::CnjCnjs(const CnjCnjs<V>& orig){   
}

template < typename V >
CnjCnjs<V>::~CnjCnjs(){
    
}

template < typename V >
void CnjCnjs<V>::crear(){
    primerElemento = elementoNulo;
    identificador = "Contenedor";
}

template < typename V >
void CnjCnjs<V>::destruir(){
    
}

template < typename V >
void CnjCnjs<V>::vaciar(){
    
}

template < typename V >
bool CnjCnjs<V>::vacio(){
    bool empty = false;
    if (primerElemento == elementoNulo)
        empty = true;
    return empty;
}

template < typename V >
string CnjCnjs<V>::cnjAlQuePertenece(V* elemento){
    string id = "";
    bool encontrado = false;
    if(primerElemento == elemento)
        id = identificador;
    else {
        V* iterElem = sigElemento;
        while(sigConjunto != 0 && !encontrado){
            while(sigElemento != 0 && !encontrado){
                if(iterElem)
            }
        }
    }
    return id;
}

template < typename V >
void CnjCnjs<V>::agregarConjunto(V elemento, string id){
    CnjCnjs<V>* newConj = new CnjCnjs(elemento, id);
    if(primerElemento == elementoNulo)
        primerElemento = newConj;
    else
        sigElemento = newConj;
}

template < typename V >
void CnjCnjs<V>::unirConjuntos(string cnjUno, string cnjDos){
    
}
#endif /* CNJCNJS_H */
