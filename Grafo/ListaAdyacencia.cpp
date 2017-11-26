#include "ListaAdyacencia.h"

Grafo_ListaAdyacencia::Grafo_ListaAdyacencia()
{
    //ctor
    cabeza = new Vertice();
    numVertices = 0;
}

Grafo_ListaAdyacencia::~Grafo_ListaAdyacencia()
{
    //dtor
}

Grafo_ListaAdyacencia::Grafo_ListaAdyacencia(const Grafo_ListaAdyacencia& orig)
{

}

void Grafo_ListaAdyacencia::Crear()
{
    cabeza = new Vertice();
    numVertices = 0;
}

void Grafo_ListaAdyacencia::EliminarTodasAristas(adyacente ad){
    if(ad != 0){
        while(ad->sig != 0){
            EliminarTodasAristas(ad->sig);
            delete(ad);
        }
    }
}

void Grafo_ListaAdyacencia::EliminarTodosVertices(vertice v){
    if(v != 0){
        while(v->siguiente != 0){
            EliminarTodosVertices(v->siguiente);
            delete(v);
        }
    }
}

void Grafo_ListaAdyacencia::Destruir()
{
    vertice v = cabeza->siguiente;
    while(v!=0){
        EliminarTodasAristas(v->ady);
        v = v->siguiente;
    }
    v = cabeza;
    EliminarTodosVertices(v);

}

void Grafo_ListaAdyacencia::Vaciar()
{
    vertice v = cabeza->siguiente;
    while(v!=0){
        EliminarTodasAristas(v->ady);
        v = v->siguiente;
    }
    v = cabeza->siguiente;
    EliminarTodosVertices(v);
}

bool Grafo_ListaAdyacencia::Vacio()
{
    return numVertices == 0 ? true : false;
}

void Grafo_ListaAdyacencia::AgregarVertice(string e)
{
    vertice n = new Vertice(e);
    if(cabeza->siguiente == 0){
        cabeza->siguiente = n;
    }
    else{
        vertice t = cabeza->siguiente;
        while(t->siguiente != 0){
            t = t->siguiente;
        }
        t->siguiente = n;
    }
    numVertices++;
}

void Grafo_ListaAdyacencia::EliminarVertice(vertice v)
{
    if(v == cabeza->siguiente){
        cabeza->siguiente = v->siguiente;
        delete(v);
    }
    else{
        vertice vrtemp = cabeza->siguiente;
        while(vrtemp != 0 && vrtemp->siguiente->etiqueta != v->etiqueta){
            vrtemp = vrtemp->siguiente;
        }
        vrtemp->siguiente = v->siguiente;
        delete(v);
    }
    --numVertices;
}

void Grafo_ListaAdyacencia::ModificarEtiqueta(string e, vertice v)
{
    v->etiqueta = e;
}

string Grafo_ListaAdyacencia::Etiqueta(vertice v) {
    return v->etiqueta;
}

void Grafo_ListaAdyacencia::AgregarArista(vertice v1, vertice v2, int p) {
    adyacente adn = new Adyacente(v2->etiqueta, p);
    if (v1->ady->peso == -1) {
        v1->ady = adn;
    } else {
        adyacente ad_t = v1->ady;
        while (ad_t->sig != 0) {
            ad_t = ad_t->sig;
        }
        ad_t->sig = adn;
    }
    v1->n_verticesadyacentes++;
}

void Grafo_ListaAdyacencia::EliminarArista(vertice v1, vertice v2) {
    adyacente artemp = v1->ady;
    if (artemp->etqVertice == v2->etiqueta) {
        if (artemp->sig != 0) {
            v1->ady = artemp->sig;
            delete(artemp);
        } else {
            delete(artemp);
            v1->ady = 0;
        }
    } else {
        while (artemp != 0 && artemp->sig->etqVertice != v2->etiqueta) {
            artemp = artemp->sig;
        }
        if (artemp->sig->sig == 0) {
            delete(artemp->sig);
            artemp->sig = 0;
        } else {
            artemp->sig = artemp->sig->sig;
            /* FALTA EL DELETE */
//            delete(artemp);
        }
    }
    v1->n_verticesadyacentes--;
}

void Grafo_ListaAdyacencia::ModificarPeso(vertice v1, vertice v2, int p)
{
    adyacente artemp = v1->ady;
    while(artemp != 0 && artemp->etqVertice != v2->etiqueta){
        artemp = artemp->sig;
    }
    artemp->peso = p;
}

int Grafo_ListaAdyacencia::Peso(vertice v1, vertice v2)
{
    adyacente artemp = v1->ady;
    while(artemp != 0 && artemp->etqVertice != v2->etiqueta){
        artemp = artemp->sig;
    }
    return artemp->peso;
}

bool Grafo_ListaAdyacencia::Adyacentes(vertice v1, vertice v2)
{
    adyacente artemp = 0;
    if(v1->ady != 0){
    artemp = v1->ady;
    while(artemp != 0 && artemp->etqVertice != v2->etiqueta){
        artemp = artemp->sig;
    }
    }
    return artemp ? true : false;
}

vertice Grafo_ListaAdyacencia::PrimerVertice()
{
    return cabeza->siguiente;
}

vertice Grafo_ListaAdyacencia::SiguienteVertice(vertice v)
{
    return v->siguiente;
}

vertice Grafo_ListaAdyacencia::PrimerVerticeAdyacente(vertice v)
{
    vertice vrtemp = cabeza->siguiente;
    while(vrtemp != 0 && vrtemp->etiqueta != v->ady->etqVertice){
        vrtemp = vrtemp->siguiente;
    }
    return vrtemp;
}

vertice Grafo_ListaAdyacencia::SiguienteVerticeAdyacente(vertice v1, vertice v2)
{
    adyacente artemp = v1->ady;
    while(artemp != 0 && artemp->etqVertice != v2->etiqueta){
        artemp = artemp->sig;
    }
    artemp = artemp->sig;
    vertice vrtemp =0;
    if(artemp != 0){
    vrtemp = cabeza->siguiente;
    while(vrtemp != 0 && vrtemp->etiqueta != artemp->etqVertice){
        vrtemp = vrtemp->siguiente;
    }
    }
    return vrtemp;
}

int Grafo_ListaAdyacencia::NumVertices()
{
    return numVertices;
}

int Grafo_ListaAdyacencia::NumVerticesAdyacentes(vertice v)
{
    return v->n_verticesadyacentes;
}

void Grafo_ListaAdyacencia::Listar(){
    vertice vrtemp = cabeza->siguiente;
    while(vrtemp != 0){
        std::cout << vrtemp->etiqueta  << ": ";
        adyacente adytemp = vrtemp->ady;
        while(adytemp != 0){
            std::cout << adytemp->etqVertice << ":" << adytemp->peso << "-> ";
            adytemp = adytemp->sig;
        }
        cout << endl;
        vrtemp = vrtemp->siguiente;
    }
    cout << endl;
}

vertice Grafo_ListaAdyacencia::ConvierteVertice(string e){
    vertice tmp = cabeza->siguiente;
    while(tmp != 0 && tmp->etiqueta != e){
        tmp = tmp->siguiente;
    }
    return tmp;
}