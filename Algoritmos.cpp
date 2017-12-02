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

void AlgoritmosGrafos::Kruscal(grafos g) {
    diccionarioAristasVisitadas dav;
    colaPrioridades cp;
    conjuntodConjs cc;
    dav.Crear();
    int cVrt = 0;
    pair<vertice, vertice> vrts;
    vertice v1 = g->PrimerVertice();
    vertice v2;
    vrts.first = v1;
    vrts.second = v2;
    while (v1 != 0) {
        cc.agregarConjunto(to_string(cVrt), v1);
        v2 = g->PrimerVerticeAdyacente(v1);

        while (v2 != 0) {
            vrts.first = v1;
            vrts.second = v2;
            if (!dav.Pertenece(make_pair(v2, v1))) {
                cp.agregar(vrts, g->Peso(v1, v2));
                dav.Agregar(make_pair(v1, v2));
            }
            v2 = g->SiguienteVerticeAdyacente(v1, v2);
        }
        ++cVrt;
        v1 = g->SiguienteVertice(v1);
    }
    int c = 0;
    int cArt = 0;
    string NC1 = "";
    string NC2 = "";
    while (cArt < g->NumVertices() - 1 && cp.numElem() != 0) {
        vrts = cp.sacar();
        NC1 = cc.conjuntoAlQuePertenece(vrts.first);
        NC2 = cc.conjuntoAlQuePertenece(vrts.second);

        if (NC1 != NC2) {
            cout << g->Etiqueta(vrts.first) << "-" << g->Etiqueta(vrts.second) << ", ";
            c += g->Peso(vrts.first, vrts.second);
            cc.unirConjuntos(NC1, NC2);
            cArt++;
        }
    }
    cout << "Su costo es de " << c << endl;
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

