#include "Algoritmos.h"

AlgoritmosGrafos::AlgoritmosGrafos() {

}

AlgoritmosGrafos::AlgoritmosGrafos(const AlgoritmosGrafos& orig) {
}

AlgoritmosGrafos::~AlgoritmosGrafos() {
}

void AlgoritmosGrafos::Dijkstra(grafos g, vertice k) {
    int tam = g->NumVertices();
    int distancia[tam];
    vertice camino[tam];
    vertice vg[tam];
    diccionarios dvv;
    dvv.Crear();
    int cnt;
    vertice v;

    vg[0] = k;
    dvv.Agregar(k);
    cnt = 1;
    v = g->PrimerVertice();
    while (cnt < tam) {
        if (!dvv.Pertenece(v)) {
            vg[cnt] = v;
            ++cnt;
        }
        v = g->SiguienteVertice(v);
    }

    dvv.Vaciar();
    v = g->PrimerVertice();
    dvv.Agregar(k);
    distancia[0] = 0;
    camino[0] = k;
    cnt = 1;
    while (v != 0) {
        if (!dvv.Pertenece(v)) {
            if (g->Adyacentes(k, v)) {
                distancia[cnt] = g->Peso(k, v);
            } else {
                distancia[cnt] = 999999;
            }
            camino[cnt] = k;
            ++cnt;
        }
        v = g->SiguienteVertice(v);
    }

    dvv.Vaciar();
    dvv.Agregar(k);
    int menor;
    while (dvv.NumElem() < tam - 1) {
        menor = 3;
        cnt = 0;
        while (cnt < tam) {
            if ((distancia[menor] > distancia[cnt]) && (!dvv.Pertenece(vg[cnt]))) {
                menor = cnt;
            }
            cnt++;
        }
        cout << "menor: " << menor << endl;
        v = vg[menor];
        dvv.Agregar(v);
        vertice dy = g->PrimerVerticeAdyacente(v);

        int indice_ady;
        for (int i = 0; i < tam; ++i) {
            if (g->Etiqueta(vg[i]) == g->Etiqueta(dy)) {
                indice_ady = i;
            }
        }

        while (dy != 0) {
            if (g->Etiqueta(dy) != g->Etiqueta(k)) {
                if (distancia[indice_ady] > g->Peso(v, dy) + distancia[menor]) {
                    distancia[indice_ady] = g->Peso(v, dy) + distancia[menor];
                    camino[indice_ady] = dy;
                }
            }
            dy = g->SiguienteVerticeAdyacente(v, dy);
        }
    }

}

void AlgoritmosGrafos::Floyd(grafos g) {
    diccionarios dvv, dav;
    dvv.Crear();
    dav.Crear();
    int n = g->NumVertices();
    int matrizA[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matrizA[i][j] = 0;
            } else {
                matrizA[i][j] = -1;
            }
        }
    }
    vertice v = g->PrimerVertice();
    for (int i = 0; i < n; i++) {
        if (!dvv.Pertenece(v) && v != 0) {
            dvv.Agregar(v);
            vertice vA = g->PrimerVertice();
            int contador = 0;
            while (vA != 0) {

                if (g->Adyacentes(v, vA) && !dav.Pertenece(vA)) {
                    matrizA[i][contador] = g->Peso(v, vA);
                    matrizA[contador][i] = g->Peso(v, vA);
                    dav.Agregar(vA);
                }
                vA = g->SiguienteVertice(vA);
                contador++;
            }

        }
        dav.Vaciar();
        v = g->SiguienteVertice(v);
    }

    int matrizB[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matrizB[i][j] = 0;
            } else {
                matrizB[i][j] = j;
            }
        }
    }

    int vector1[n];
    int vector2[n];
    int bucle = 0;

    for (bucle = 0; bucle < n; bucle++) {
        for (int j = 0; j < n; j++) {
            vector1[j] = matrizA[bucle][j];
            vector2[j] = matrizA[j][bucle];
        }

        int suma = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (vector2[i] == -1 || vector1[j] == -1) {
                    suma = 9999;
                } else {
                    suma = vector2[i] + vector1[j];
                }
                if (suma < matrizA[i][j]) {
                    matrizA[i][j] = suma;
                    matrizB[i][j] = bucle;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrizA[i][j] << ",";
        }
        cout << " " << endl;
    }
}

bool AlgoritmosGrafos::Iguales(grafos g1, grafos g2) {
    bool iguales = true;
    diccionarios dvv;
    int cnt = 0;
    vertice v2;
    vertice primero[g1->NumVertices() + 1];
    vertice segundo[g2->NumVertices() + 1];
    vertice v1;
    if (g1->NumVertices() == g2->NumVertices()) {
        dvv.Crear();
        v1 = g1->PrimerVertice();
        while (v1 != 0 && iguales) {
            if (!dvv.Pertenece(v1)) {
                dvv.Agregar(v1);
                v2 = g2->PrimerVertice();
                while (v2 != 0 && g1->Etiqueta(v1) != g2->Etiqueta(v2)) {
                    v2 = g2->SiguienteVertice(v2);
                }
                if (v2 == 0) {
                    iguales = false;
                } else {
                    primero[cnt] = v1;
                    segundo[cnt] = v2;
                    ++cnt;
                }
            }
            v1 = g1->SiguienteVertice(v1);
        }
    }

    dvv.Vaciar();
    diccionarios dav;
    cnt = 0;
    while (cnt < g1->NumVertices() && iguales) {
        v1 = primero[cnt];
        v2 = segundo[cnt];
        if (g1->NumVerticesAdyacentes(v1) != g2->NumVerticesAdyacentes(v2)) {
            iguales = false;
        } else {
            vertice ad1 = g1->PrimerVerticeAdyacente(v1);
            dav.Crear();
            while (ad1 != 0 && iguales) {
                if (!dav.Pertenece(ad1)) {
                    dav.Agregar(ad1);
                    vertice ad2 = g2->PrimerVerticeAdyacente(v2);
                    while (ad2 != 0 && g1->Etiqueta(ad1) != g2->Etiqueta(ad2)) {
                        ad2 = g2->SiguienteVerticeAdyacente(v2, ad2);
                    }
                    if (g1->Etiqueta(ad1) == g2->Etiqueta(ad2)) {
                        if (g1->Peso(v1, ad1) == g2->Peso(v2, ad2)) {
                            ad1 = g1->SiguienteVerticeAdyacente(v1, ad1);
                        } else {
                            iguales = false;
                        }
                    } else {
                        iguales = false;
                    }
                }
            }
        }
        cnt++;
    }
    dvv.Destruir();
    dav.Destruir();
    return iguales;
}

void AlgoritmosGrafos::Copiar(grafos o, grafos c) {
    c->Crear();
    diccionarios dvv;
    dvv.Crear();
    diccionarios dav;
    dav.Crear();
    vertice v;
    v = o->PrimerVertice();
    while (v != 0) {
        c->AgregarVertice(o->Etiqueta(v));
        v = o->SiguienteVertice(v);
    }

    v = o->PrimerVertice();
    vertice vc = c->PrimerVertice();
    while (v != 0) {
        if (!dvv.Pertenece(v)) {
            dvv.Agregar(v);
            vertice vA = o->PrimerVerticeAdyacente(v);
            while (vA != 0) {
                if (!dav.Pertenece(vA)) {
                    vertice vAC = c->PrimerVertice();
                    bool encontrado = false;
                    while (!encontrado) {
                        if (c->Etiqueta(vAC) == o->Etiqueta(vA)) {
                            encontrado = true;
                        } else {
                            vAC = c->SiguienteVertice(vAC);
                        }
                    }
                    if (encontrado) {
                        dav.Agregar(vA);
                        c->AgregarArista(vc, vAC, o->Peso(v, vA));
                        vA = o->SiguienteVerticeAdyacente(v, vA);
                    }
                }
            }
        }
        dav.Vaciar();
        v = o->SiguienteVertice(v);
        vc = c->SiguienteVertice(vc);
    }
}

void AlgoritmosGrafos::Vendedor(const grafos& g) {
    int n = g->NumVertices();
    vertice* ruta = new vertice[n];
    dvv.Crear();
    numSolFacts = 0;
    solOptima = 9999;
    dvv.Agregar(g->PrimerVertice());
    vertice* rutaAct = VendedorRec(g, g->PrimerVertice(), 0, ruta);
    delete[] ruta;
    if (rutaAct != 0) {
        cout << g->Etiqueta(g->PrimerVertice()) << "->";
        for (int i = 0; i < n - 1; i++) {
            cout << g->Etiqueta(rutaAct[i]) << "->";
        }
        cout << g->Etiqueta(g->PrimerVertice()) << endl;
        cout << "Peso Total: " << solOptima << endl;
        cout << "Numero de soluciones factibles: " << numSolFacts << endl;
    } else {
        cout << "No hay soluciones" << endl;
    }
    dvv.Destruir();
}

vertice* AlgoritmosGrafos::VendedorRec(const grafos& g, vertice vrt, int peso, vertice* ruta) {
    vertice* solucion = 0;
    if (dvv.NumElem() == g->NumVertices()) {
        if (!g->Adyacentes(vrt, g->PrimerVertice())) {
            return 0;
        }
        peso += g->Peso(vrt, g->PrimerVertice());
        numSolFacts++;
        if (peso < solOptima) {
            const int n = g->NumVertices();
            solucion = new vertice[n];
            solOptima = peso;
            for (int i = 0; i < n - 1; i++) {
                solucion[i] = ruta[i];
            }
            solucion[n - 1] = g->PrimerVertice();
        }
        return solucion;
    }
    vertice ady = g->PrimerVerticeAdyacente(vrt);
    while (ady != 0) {
        if (!dvv.Pertenece(ady)) {
            dvv.Agregar(ady);
            peso += g->Peso(vrt, ady);
            ruta[dvv.NumElem() - 2] = ady;
            vertice* solP = VendedorRec(g, ady, peso, ruta);
            if (solP != 0) {
                if (solucion != 0) {
                    delete[] solucion;
                }
                solucion = solP;
            }
            dvv.Eliminar(ady);
            peso -= g->Peso(vrt, ady);
        }
        ady = g->SiguienteVerticeAdyacente(vrt, ady);
    }
    return solucion;
}

void AlgoritmosGrafos::Prim(const grafos& g) {
    dvv.Crear();
    dvv.Vaciar();
    int n = g->NumVertices();
    string ruta[n]; //para guardar el árbol 
    int keys[n];

    for (int i = 0; i < n; i++) {
        keys[i] = 99999;
    }
    for (int i = 0; i < n; i++) {
        vertice piv = Pivote(g);
        dvv.Agregar(piv);
        ruta[i] = g->Etiqueta(piv);
        vertice vA = g->PrimerVerticeAdyacente(piv);
        while (vA != NULL) {
            if ((g->Peso(piv, vA) < keys[i])) {
                ruta[i] = g->Etiqueta(piv);
                keys[i] = g->Peso(piv, vA);
            }
            vA = g->SiguienteVerticeAdyacente(piv, vA);
        }
    }

    cout << "ARISTA    PESO" << endl;
    for (int i = 0; i < n-1; i++) {
        cout << ruta[i] <<  "-" << ruta[i+1] << "        " << keys[i] << endl;
    }
}

vertice AlgoritmosGrafos::Pivote(const grafos& g) {
    vertice pivote = g->PrimerVertice();
    vertice v = g->PrimerVertice();
    while (v != NULL) {
        if (dvv.Pertenece(pivote)) {
            pivote = g->SiguienteVertice(pivote);
        } else {
            if (pivote->etiqueta.compare(v->etiqueta) > 0 && !dvv.Pertenece(v)) {
                pivote = v;
                dvv.Agregar(v);
            }
            v = g->SiguienteVertice(v);
        }
    }
    return pivote;
}




