#ifndef CNJCNJS_H
#define CNJCNJS_H
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

template <class T>
class CnjCnjs {
public:
    
    //EFE:Constructuye el conjunto de conjunto disjutnos
    //REQ:---
    //MOD:
    CnjCnjs();
    //EFE: Destruye el conjunto de conjuntos.
    //REQ: conjunto de conjuntos inicialiado
    //MOD: conjunto de conjuntos
    virtual ~CnjCnjs();
    //EFE:vacia el conjunto de conjuntos 
    //REQ: conjunto de conjuntos inicializado
    //MOD:
    void vaciar();
    //EFE: retorna un true si el conjunto de conjuntos esta vacio y un false si no.
    //REQ: conjunto de conjuntos inicializado
    //MOD:
    bool vacio();
    //EFE: retorna el identificador del conjunto que pertenece elemento
    //REQ: conjunto de conjuntos inicializado.
    //MOD:---
    string conjuntoAlQuePertenece(T elemento);
    //EFE: agrega un conjunto con un elemento al conjunto de conjuntos.
    //REQ: conjunto de conjuntos inicializado. elemento no pertenezca a otro conjunto.
    //MOD: conjunto de conjuntos..
    void agregarConjunto(string Identificador, T elemento);
    //EFE: une los elementos del conjunto 1 con los del conjunto 2.
    //REQ: conjunto de conjuntos inicializado. ambos conjuntos existan.
    //MOD: conjunto de conjuntos.
    void unirConjuntos(string idConj1, string idConj2);
    
private:
    
    template <typename C>
    struct Conjunto {
        C elemento;
        Conjunto *sigElem;
        Conjunto(C e) {
            elemento = e;
            sigElem = nullptr;
        };

        Conjunto() {
        };
    };

    template <typename C>
    struct ConjuntosList {
        string identificador;
        ConjuntosList* sig;
        Conjunto<C>* ConjPtr;

        ConjuntosList(string id, C e) {
            identificador = id;
            ConjPtr = new Conjunto<C>(e);
            sig = nullptr;
        }

        ConjuntosList() {
            identificador = "";
            ConjPtr = new Conjunto<C>;
            sig = nullptr;
        };
    };
    ConjuntosList<T>* primero;
};

template <typename T>
CnjCnjs<T>::CnjCnjs() {
    primero = new ConjuntosList<T>;
}

template <typename T>
CnjCnjs<T>::~CnjCnjs() {

}

template <typename T>
void CnjCnjs<T>::vaciar() {

}

template <typename T>
bool CnjCnjs<T>::vacio() {
    return primero==nullptr;
}

template <typename T>
void CnjCnjs<T>::agregarConjunto(string Identificador, T elemento) {
    ConjuntosList<T>* nConj = new ConjuntosList<T>(Identificador, elemento);
    nConj->sig = primero;
    primero = nConj;
}

template <typename T>
string CnjCnjs<T>::conjuntoAlQuePertenece(T elem) {
    bool encontrado = false;
    Conjunto<T>* auxElem = primero->ConjPtr;
    ConjuntosList<T>*  auxConj = primero;
    string buscado = "";
    while ((auxConj != nullptr)&&(!encontrado)) {
        auxElem= auxConj->ConjPtr;
        while ((auxElem != nullptr)&&(!encontrado)) {
            if (auxElem->elemento == elem) {
                encontrado = true;
                buscado= auxConj->identificador;
            } else
                auxElem = auxElem->sigElem;
        }
        auxConj= auxConj->sig;
    }
        return buscado;  
}

template <typename T>
void CnjCnjs<T>::unirConjuntos(string idConj1, string idConj2){
        bool encontrados=false;
        Conjunto<T>*  Conj1=nullptr;
        Conjunto<T>*  Conj2=nullptr;
        Conjunto<T>*  conjAux;
        ConjuntosList<T>*  Conjuntos=primero;
        ConjuntosList<T>*  ConjuntosPrev=nullptr;
        ConjuntosList<T>*  Conjunto2=primero;
        if (primero->identificador==idConj2){
            Conj2=primero->ConjPtr;
        }
        while ((Conjuntos!=nullptr)&&(!encontrados)){
            if (Conjuntos->identificador==idConj1){
                Conj1=Conjuntos->ConjPtr;
            }
            if (Conjuntos->sig->identificador==idConj2){
                Conj2=Conjuntos->sig->ConjPtr;
                ConjuntosPrev=Conjuntos;
            }
            if ((Conj1!=nullptr)&&(Conj2!=nullptr)){
                encontrados=true;
            }else if (!encontrados)
                Conjuntos=Conjuntos->sig;
        }    
        while ( Conj1->sigElem!=nullptr){
            Conj1= Conj1->sigElem;
        }        
        Conj1->sigElem=Conj2;
        
        if  (ConjuntosPrev!=nullptr){
            Conjunto2=ConjuntosPrev->sig;
            ConjuntosPrev->sig=Conjunto2->sig;
        } else {
            primero= primero->sig;
        }
        delete (Conjunto2);
}

#endif /* CNJCNJS_H */
