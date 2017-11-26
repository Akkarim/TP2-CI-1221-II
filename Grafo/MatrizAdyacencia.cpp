#include "MatrizAdyacencia.h"


void MatrizAdyacencia::Crear() {
    numVertice = 0;
    for (int i = 0; i < 30; i++) { //inicializar todos los pesos en -1
        for (int j = 0; j < 30; j++) {
            matrizCostes[i][j] = -1;
        }
    }
}

void MatrizAdyacencia::Destruir() {

}

void MatrizAdyacencia::Vaciar() {
    numVertice = 0;
}

bool MatrizAdyacencia::Vacio() {
    if (numVertice == 0) {
        return true;
    } else
        return false;
}

vertice MatrizAdyacencia::AgregarVertice(string etiqueta) {
    VerticeM temp(etiqueta);
    arrayVert[numVertice] = temp;
    numVertice++;
    return temp;
}

void MatrizAdyacencia::EliminarVertice(vertice v) {
    bool eliminado = false;
    int contador = 0;
    while (contador < numVertice && !eliminado) {
        if (v.etiqueta == arrayVert[contador].etiqueta) {
            int contador2 = contador;
            while (contador2 < numVertice - 1) {
                VerticeM aux = arrayVert[contador2];
                arrayVert[contador2] = arrayVert[contador2 + 1];
                arrayVert[contador2 + 1] = aux;
                contador2++;
                eliminado = true;
            }
        }
        contador++;
    }

    numVertice--;
}

void MatrizAdyacencia::AgregarArista(vertice ver1, vertice ver2, int peso) {
    int i = 0;
    bool iguales = false;
    while (!iguales) {
        if (arrayVert[i].etiqueta == ver1.etiqueta) {
            iguales = true;
        } else {
            i++;
        }
    }
    iguales = false;
    int j = 0;
    while (!iguales) {
        if (arrayVert[j].etiqueta == ver2.etiqueta) {
            iguales = true;
        } else {
            j++;
        }
    }
    matrizCostes[i][j] = peso;
    matrizCostes[j][i] = peso;

    arrayVert[i].nAdyacentes++;
    arrayVert[j].nAdyacentes++;
}

void MatrizAdyacencia::EliminarArista(vertice ver1, vertice ver2) {
    int i = 0;
    bool iguales = false;
    while (!iguales) {
        if (arrayVert[i].etiqueta == ver1.etiqueta) {
            iguales = true;
        } else {
            i++;
        }
    }
    iguales = false;
    int j = 0;
    while (!iguales) {
        if (arrayVert[j].etiqueta == ver2.etiqueta) {
            iguales = true;
        } else {
            j++;
        }
    }
    matrizCostes[i][j] = -1;
    matrizCostes[j][i] = -1;

    arrayVert[i].nAdyacentes--;
    arrayVert[j].nAdyacentes--;

}

void MatrizAdyacencia::ModificarEtiqueta(string nuevaEtiqueta, vertice ver) {
    int contador = 0;
    bool done = false;
    while (!done) {
        if (arrayVert[contador].etiqueta == ver.etiqueta) {
            arrayVert[contador].etiqueta = nuevaEtiqueta;
            done = true;
        }
        contador++;
    }
}

string MatrizAdyacencia::Etiqueta(vertice ver) {
    return ver.etiqueta;
}

void MatrizAdyacencia::ModificarPeso(vertice ver1, vertice ver2, int peso) {
    int i = 0;
    bool iguales = false;
    while (!iguales) {
        if (arrayVert[i].etiqueta == ver1.etiqueta) {
            iguales = true;
        } else {
            i++;
        }
    }
    iguales = false;
    int j = 0;
    while (!iguales) {
        if (arrayVert[j].etiqueta == ver2.etiqueta) {
            iguales = true;
        } else {
            j++;
        }
    }
    matrizCostes[i][j] = peso;
    matrizCostes[j][i] = peso;
}

int MatrizAdyacencia::Peso(vertice ver1, vertice ver2) {
    int i = 0;
    bool iguales = false;
    while (!iguales) {
        if (arrayVert[i].etiqueta == ver1.etiqueta) {
            iguales = true;
        } else {
            i++;
        }
    }
    iguales = false;
    int j = 0;
    while (!iguales) {
        if (arrayVert[j].etiqueta == ver2.etiqueta) {
            iguales = true;
        } else {
            j++;
        }
    }
    return matrizCostes[i][j];
}

bool MatrizAdyacencia::Adyacentes(vertice ver1, vertice ver2) {
    int i = 0;
    bool iguales = false;
    while (!iguales) {
        if (arrayVert[i].etiqueta == ver1.etiqueta) {
            iguales = true;
        } else {
            i++;
        }
    }
    iguales = false;
    int j = 0;
    while (!iguales) {
        if (arrayVert[j].etiqueta == ver2.etiqueta) {
            iguales = true;
        } else {
            j++;
        }
    }
    if (matrizCostes[i][j] == -1) {
        return false;
    } else {
        return true;
    }
}

vertice MatrizAdyacencia::PrimerVertice() {
    return arrayVert[0];
}

vertice MatrizAdyacencia::SiguienteVertice(vertice vrt) {
    int contador = 0;
    while (contador < numVertice - 1) {
        if (arrayVert[contador].etiqueta == vrt.etiqueta) {
            return arrayVert[contador + 1];
        }
        contador++;
    }
}

vertice MatrizAdyacencia::PrimerVerticeAdyacente(vertice vrt) {
    int i = 0;
    bool encontrado = false;
    while (!encontrado) { //para encontrar a vrt en la matriz.
        if (vrt.etiqueta == arrayVert[i].etiqueta) {
            encontrado = true;
        } else {
            i++;
        }
    }

    int contador = 0;
    while (contador < numVertice) {
        if (matrizCostes[i][contador] != -1) {
            return arrayVert[contador];
        }
        contador++;
    }
}

vertice MatrizAdyacencia::SiguienteVerticeAdyacente(vertice vrt1, vertice vrt2) {
    int i = 0;
    bool encontrado = false;
    while (!encontrado) { //para encontrar a vrt1 en la matriz.
        if (vrt1.etiqueta == arrayVert[i].etiqueta) {
            encontrado = true;
        } else {
            i++;
        }
    }

    int contador = 0;
    while (contador < numVertice) {
        if (matrizCostes[i][contador] != -1 && arrayVert[contador].etiqueta != vrt2.etiqueta) {
            return arrayVert[contador];
        }
        contador++;
    }
}

int MatrizAdyacencia::NumVertices() {
    return numVertice;
}

int MatrizAdyacencia::NumVerticesAdyacentes(vertice ver) {
    int contador = 0;
    while (contador < numVertice) {
        if (arrayVert[contador].etiqueta == ver.etiqueta) {
            return arrayVert[contador].nAdyacentes;
        }
        contador++;
    }
}

vertice MatrizAdyacencia::ConvierteVertice(string e) {
    int contador = 0;
    while (contador < numVertice) {
        if (arrayVert[contador].etiqueta == e) {
            return arrayVert[contador];
        }
        contador++;
    }
}

void MatrizAdyacencia::Listar() {
    int contador = 0;
    while (contador < numVertice) {
        cout << arrayVert[contador].etiqueta << endl;
        contador++;
    }
}