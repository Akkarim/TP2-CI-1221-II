#ifndef CNJCNJS_H
#define CNJCNJS_H

#include <string>
using namespace std;

template < typename V>
class CnjCnjs{
public: 
    
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
    //REQ: El Conjunto inicializado y no vacio.
    //MOD:
    string cnjAlQuePertenece(V elemento);
    
    //EFE: Retorna true si el conjunto esta vacío, false si tiene al menos un elemento.
    //REQ: El Conjunto inicializado.
    //MOD:
    void agregarConjunto(V elemento, string id);
    
    void unirConjuntos(string cnjUno, string cnjDos);
private:
    
    V* primerElemento;
    CnjCnjs* sigConjunto;
    string identificador;
};

template < typename V >
CnjCnjs::crear(){

}

template < typename V >
CnjCnjs::destruir(){
    
}

template < typename V >
CnjCnjs::vaciar(){
    
}

template < typename V >
CnjCnjs::vacio(){
    
}
#endif /* CNJCNJS_H */
