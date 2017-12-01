#ifndef COLAPRIORIDADES_H
#define COLAPRIORIDADES_H
#define SIZE 20
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

template <class A>
class ColaPrioridades {
public:
    
    //EFE: Crea una Cola vacia 
    //REQ: Cola no inicializada
    //MOD: 
    ColaPrioridades();
    
    //EFE: Destruye la cola
    //REQ: Cola inicializada
    //MOD: Cola
    virtual ~ColaPrioridades();
    
    //EFE: Vacia la Cola
    //REQ: Cola Inicializada
    //MOD: Cola
    void vaciar();
    
    //EFE: verifica si la cola esta vacia
    //REQ:
    //MOD:
    bool vacia();
    
    //EFE: Agrega un elemento a la cola segun su prioridad
    //REQ: Cola Inicializada
    //MOD: Cola
    
    void agregar(A elemento, int prioridad);

    //EFE: Saca el primer elemento de la Cola 
    //REQ: Cola inicializada
    //MOD: Cola
    A sacar();
    
    //EFE: Devuelve el numero de elementos de la cola
    //REQ: Cola inicializada
    //MOD:
    int numElem();

private:

    template <typename B>
    struct Caja {
        B elemento;
        int prioridad;

        Caja(B elementoNuevo, int nuevaPrioridad) {
            elemento = elementoNuevo;
            prioridad = nuevaPrioridad;
        }

        Caja() {
        };
    };
    Caja<A> arreglo[SIZE];
    int ultimo;
    int contador;
};

template <typename A>
ColaPrioridades<A>::ColaPrioridades() {
    ultimo = 0;
    contador = 0;
}

template <typename A>
ColaPrioridades<A>::~ColaPrioridades() {

}

template <typename A>
void ColaPrioridades<A>::vaciar() {
    ultimo = 0;
    contador = 0;
}

template <typename A>
bool ColaPrioridades<A>::vacia() {
    return (ultimo == 0);
}

template <typename A>
void ColaPrioridades<A>::agregar(A elemento, int prioridad) {
    Caja<A>* nuevo = new Caja<A>(elemento, prioridad);
    Caja<A> padre;
    ultimo++;
    contador++;
    arreglo[ultimo] = *nuevo;
    int agregado = ultimo;
    while ((agregado > 0) && (arreglo[agregado].prioridad < arreglo[agregado / 2].prioridad)) {
        padre = arreglo[agregado / 2];
        arreglo[agregado / 2] = arreglo[agregado];
        arreglo[agregado] = padre;
        agregado = agregado / 2;
    }
}

template <typename A>
A ColaPrioridades<A>::sacar() {
    A auxiliar = arreglo[1].elemento;
    cout<<arreglo[1].elemento<<"\n";
    Caja<A> padre;
    bool terminado = false;
    int iterador = 1;
    int minimo = 0;
    if (contador > 1) {
        arreglo[1] = arreglo[ultimo];
        ultimo--;
        contador--;
        while (!terminado) {
            if (iterador * 2 <= ultimo) {
                minimo = iterador * 2;
                if ((iterador * 2 + 1 <= ultimo)&&(arreglo[iterador * 2 + 1].prioridad < arreglo[iterador * 2].prioridad)) {
                    minimo = iterador * 2 + 1;
                }
                if (arreglo[minimo].prioridad < arreglo[iterador].prioridad) {
                    padre = arreglo[iterador];
                    arreglo[iterador] = arreglo[minimo];
                    arreglo[minimo] = padre;
                    iterador = minimo;
                } else {
                    terminado = true;
                }
            } else {
                terminado = true;
            }
        }
    } else {
        ultimo--;
        contador--;
    }
    return auxiliar;
}

template <typename A>
int ColaPrioridades<A>::numElem() {
    return contador;
}
#endif /* COLAPRIORIDADES_H */