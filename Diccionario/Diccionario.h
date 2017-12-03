#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <iostream>
#include <string>
#include <memory>
#include <sstream>

using namespace std;

template <typename T>
class Diccionario {
public:
    Diccionario();
    Diccionario(const Diccionario& orig);
    virtual ~Diccionario();
    
    //REQ: 
    //EFE: inicializa el diccionario.
    //MOD: 
    void Crear();
    
    //REQ: D inicializado.
    //EFE: Destruye el diccionario haciendolo inutilizable.
    //MOD: D.
    void Destruir();
    
    //REQ: D inicializado y no vacio
    //EFE: Elimina todos los elementos que hay en D
    //MOD: D.
    void Vaciar();
    
    //REQ: D inicializado.
    //EFE: Devuelve true si D está vacio, false si no.
    //MOD: 
    bool Vacio();
    
    //REQ: D inicializado.
    //EFE: agreaga el elemento e al diccionario
    //MOD: D
    void Agregar(T e);
    
    //REQ: D inicializado y que el elemento e exista en el diccionario.
    //EFE: Elimina el elemento e del diccionario
    //MOD: D
    void Eliminar(T e);
    
    //REQ: D inicializado.
    //EFE: Devuelve true si el elemento e está en el diccionario, false en caso contrario.
    //MOD:
    bool Pertenece(T e);
    
    //REQ: D inicializado.
    //EFE: Devuelve el numero de elementos que hay en el diccionaro.
    //MOD: 
    int NumElem();
    
    string Listar();
    
    
    int ultimoLleno = 0;
private:  
    template <typename V >
    struct Nodo {
        V elemento;
        Nodo *sgt;
        Nodo(){};
        Nodo(V e) {
            elemento = e;
            sgt = NULL;
        }
    };
    Nodo<T> *primero;

};

template<typename T>
Diccionario<T>::Diccionario(){
    primero = NULL;
    ultimoLleno = 0;
}

template < typename T >
Diccionario<T>::Diccionario(const Diccionario& orig){
}

template < typename T >
Diccionario<T>::~Diccionario(){
}

template < typename T >
void Diccionario< T>::Crear(){
    primero = NULL;
    ultimoLleno = 0;
}

template < typename T >
void Diccionario<T>::Destruir(){
    Nodo<T> *temp = primero;
    Nodo<T> *aux = NULL;
    while (temp != NULL) {
        aux = temp->sgt;
        delete temp;
        temp = aux;
    }
    delete aux;
    delete temp;
}

template < typename T >
void Diccionario< T>::Vaciar(){
    primero = NULL;
    ultimoLleno = 0;
}

template <typename T>
bool Diccionario<T>::Vacio(){
     if (primero != NULL) {
        return false;
    }
    return true;
}

template <typename T>
void Diccionario<T>::Agregar(T e){
     bool existe = false;
 
    if (ultimoLleno != 0) {
        Nodo<T> *aux = primero;
        while (aux != NULL && !existe) {
            if (aux->elemento == e) {
                existe = true;
            }
            aux = aux->sgt;
        }
    }

    if (!existe) {
        Nodo<T> *temp = new Nodo<T>(e);
        temp->sgt = primero;
        primero = temp;
        ultimoLleno++;
    }
}

template <typename T>
void Diccionario<T>::Eliminar(T e){
    //Nodo<T> *temp = primero;
    Nodo<T> *aux;
    Nodo<T> *anterior = NULL;
    aux = primero;
    while(aux != NULL && aux->elemento != e){
        anterior = aux;
        aux = aux->sgt;
    }    
    if(anterior == NULL){ //si es el primer elemento
        primero = primero->sgt;
        delete aux;
    } else{
        anterior->sgt = aux->sgt;
        delete aux;
    }
    
//    while(temp->elemento != e && temp != NULL){
//        temp = temp->sgt;
//    }
//    if(temp->elemento == e){
//        temp->sgt = temp->sgt->sgt;
//    }
    ultimoLleno--;
}

template <typename T>
bool Diccionario<T>::Pertenece(T e){
    Nodo<T> *temp = primero;
    while (temp != NULL) {
        if (temp->elemento == e) {
            return true;
        }
        temp = temp->sgt;
    }
    return false;
}

template <typename T>
int Diccionario<T>::NumElem(){
     return ultimoLleno;
}

template <typename T>
string Diccionario<T>::Listar(){
    stringstream fs; 
    Nodo<T> *temp = primero;
    while (temp != NULL ) {
        fs << temp->elemento << ",";
        temp = temp->sgt;
    }
    return fs.str();
}

#endif /* DICCIONARIOARIO_H */