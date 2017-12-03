#include <cstdlib>
#include <stdio.h>
#include <iostream>

#include "Algoritmos.h"
#include "ColadePrioridades/ColaPrioridades.h"
#include "ConjuntodeConjuntos/CnjCnjs.h"
#include "Diccionario/Diccionario.h"
#include "Grafo/ListaAdyacencia.h"
//#include "Grafo/MatrizAdyacencia.h"

//typedef MatrizAdyacencia grafo;
typedef ListaAdyacencia grafo;

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    bool continuar = true;
    while (continuar) {
        int desicion;
        cout << "Qué desea usar?" << endl;
        cout << " 1. Operadores Básicos." << endl;
        cout << " 2. Algoritmos." << endl;
        cout << " 0. Salir." << endl;
        cout << " Ingrese el número correspondiente: ";
        cin >> desicion;
        grafo g;
        switch (desicion) {
            case 1:
            {
                bool seguir = true;
                int op;
                while (seguir) {
                    cout << "   Qué desea hacer?" << endl;
                    cout << "       1. Crear." << endl;
                    cout << "       2. Destruir." << endl;
                    cout << "       3. Vaciar." << endl;
                    cout << "       4. Averiguar si esta vacio." << endl;
                    cout << "       5. Agregar un vertice." << endl;
                    cout << "       6. Eliminar un vertice." << endl;
                    cout << "       7. Modificar la etiqueta de un vertice." << endl;
                    cout << "       8. Agregar un arista." << endl;
                    cout << "       9. Eliminar una arista." << endl;
                    cout << "       10. Modificar un peso." << endl;
                    cout << "       11. Averiguar el peso de un arista." << endl;
                    cout << "       12. Averiguar si dos vertices son adyacentes." << endl;
                    cout << "       13. Averiguar cual es el primer vertice." << endl;
                    cout << "       14. Averiguar el siguiente vertice." << endl;
                    cout << "       15. Averiguar el primer vertice adyacente." << endl;
                    cout << "       16. Averiguar el siguiente vertice adyacente." << endl;
                    cout << "       17. Averiguar el numero de vertices del grafo." << endl;
                    cout << "       18. Listar." << endl;
                    cout << "       0. Salir." << endl;
                    cout << "   Ingrese el número correspondiente: ";
                    cin >> op;
                    switch (op) {
                        case 1:
                        {
                            g.Crear();
                        }
                            break;
                        case 2:
                        {
                            g.Destruir();
                        }
                            break;
                        case 3:
                        {
                            g.Vaciar();
                        }
                            break;
                        case 4:
                        {
                            g.Vacio() ? cout << "          Grafo Vacio.\n" : cout << "         Grafo no vacio.\n";
                        }
                            break;
                        case 5:
                        {
                            string h;
                            string etq;
                            cout << "           Ingrese la etiqueta del nuevo vertice: ";
                            cin >> etq;
                            g.AgregarVertice(etq);
                        }
                            break;
                        case 6:
                        {
                            string etq;
                            cout << "           Ingrese la etiqueta del vertice que desea eliminar: ";
                            cin >> etq;
                            g.EliminarVertice(g.ConvierteVertice(etq));
                        }
                            break;
                        case 7:
                        {
                            string ver;
                            cout << "           Ingrese la etiqueta del vertice que desea modificar: ";
                            cin >> ver;
                            string etq;
                            cout << "           Ingrese la nueva etiqueta del vertice: ";
                            cin >> etq;
                            g.ModificarEtiqueta(etq, g.ConvierteVertice(ver));
                        }
                            break;
                        case 8:
                        {
                            string ver;
                            cout << "           Ingrese el primer vertice: ";
                            cin >> ver;
                            string ver2;
                            cout << "           Ingrese el segundo vertice: ";
                            cin >> ver2;
                            int p;
                            cout << "           Ingrese el peso del arista: ";
                            cin >> p;
                            g.AgregarArista(g.ConvierteVertice(ver), g.ConvierteVertice(ver2), p);
                        }
                            break;
                        case 9:
                        {
                            string ver;
                            cout << "           Ingrese el primer vertice: ";
                            cin >> ver;
                            string ver2;
                            cout << "           Ingrese el segundo vertice: ";
                            cin >> ver2;
                            g.EliminarArista(g.ConvierteVertice(ver), g.ConvierteVertice(ver2));
                        }
                            break;
                        case 10:
                        {
                            string ver;
                            cout << "           Ingrese el primer vertice: ";
                            cin >> ver;
                            string ver2;
                            cout << "           Ingrese el segundo vertice: ";
                            cin >> ver2;
                            int p;
                            cout << "           Ingrese el nuevo peso del arista: ";
                            cin >> p;
                            g.ModificarPeso(g.ConvierteVertice(ver), g.ConvierteVertice(ver2), p);
                        }
                            break;
                        case 11:
                        {
                            string ver;
                            cout << "           Ingrese el primer vertice: ";
                            cin >> ver;
                            string ver2;
                            cout << "           Ingrese el segundo vertice: ";
                            cin >> ver2;
                            cout << "           El peso del arista es: " << g.Peso(g.ConvierteVertice(ver), g.ConvierteVertice(ver2));
                        }
                            break;
                        case 12:
                        {
                            string ver;
                            cout << "           Ingrese el primer vertice: ";
                            cin >> ver;
                            string ver2;
                            cout << "           Ingrese el segundo vertice: ";
                            cin >> ver2;
                            if (g.Adyacentes(g.ConvierteVertice(ver), g.ConvierteVertice(ver2))) {
                                cout << "           Vertices adyacentes." << endl;
                            } else {
                                cout << "           Vertices no adyacentes." << endl;
                            }
                        }
                            break;
                        case 13:
                        {
                            cout << "           El primer vertice es: " << g.Etiqueta(g.PrimerVertice()) << endl;
                        }
                            break;
                        case 14:
                        {
                            //siguiente vertice
                            string ver;
                            cout << "           Ingrese el vertice: ";
                            cin >> ver;
                            cout << "           El siguiente vertice de " << g.Etiqueta(g.ConvierteVertice(ver)) << " es " << g.Etiqueta(g.SiguienteVertice(g.ConvierteVertice(ver))) << endl;
                        }
                            break;
                        case 15:
                        {
                            //primer vertice adyacente
                            string ver;
                            cout << "           Ingrese el vertice: ";
                            cin >> ver;
                            cout << "           El primer vertice adyacente a " << g.Etiqueta(g.ConvierteVertice(ver)) << " es " << g.Etiqueta(g.PrimerVerticeAdyacente(g.ConvierteVertice(ver))) << endl;
                        }
                            break;
                        case 16:
                        {
                            //siguiente vertice adyacente
                            string ver;
                            cout << "           Ingrese el primer vertice: ";
                            cin >> ver;
                            string ver2;
                            cout << "           Ingrese el segundo vertice: ";
                            cin >> ver2;
                            cout << "          " << g.Etiqueta(g.ConvierteVertice(ver2)) << " es adyacente a " << g.Etiqueta(g.ConvierteVertice(ver)) << ",\n su siguiente vertive adyacente es " << g.Etiqueta(g.SiguienteVerticeAdyacente(g.ConvierteVertice(ver), g.ConvierteVertice(ver2))) << endl;
                        }
                            break;
                        case 17:
                        {
                            //num vertices
                            cout << "El grafo posee actualmente  " << g.NumVertices() << " vertices." << endl;
                        }
                            break;
                        case 18:
                        {
                            g.Listar();
                        }
                            break;
                        case 0:
                        {
                            seguir = false;
                        }
                            break;
                        default:
                        {
                            cout << "   INGRESE UN NUMERO VALIDO\n" << endl;
                        }
                            break;
                    }
                }
            }
                break;

            case 2:
            {

                bool seguir = true;
                int op;
                AlgoritmosGrafos alg;
                while (seguir) {
                    cout << "¿Qué desea hacer?" << endl;
                    cout << "       1. Dijkstra." << endl;
                    cout << "       2. Floyd." << endl;
                    cout << "       3. Comprobar si dos grafos son iguales." << endl;
                    cout << "       4. Copiar un grafo." << endl;
                    cout << "       5. Vendedor." << endl;
                    cout << "       6. Kruskal." << endl;
                    cout << "       7. Prim." << endl;
                    cout << "       0. Salir." << endl;
                    cout << "Seleccione una opción válida ";
                    cin >> op;
                    switch (op) {
                        case 1:
                        {
                            string v;
                            cout << "Seleccione un vértice en el grafo ";
                            cin >> v;
                            alg.Dijkstra(&g, g.ConvierteVertice(v));
                        }
                            break;

                        case 2:
                        {
                            alg.Floyd(&g);
                        }
                            break;

                        case 3:
                        {
                            grafo g2;
                            g2.Crear();
                            bool seg = true;
                            while (seg) {
                                cout << "Que desea hacer?" << endl;
                                cout << "  1. Agregar Vertice" << endl;
                                cout << "  2. Agregar Arista." << endl;
                                cout << "  3. Eliminar Vertice" << endl;
                                cout << "  4. Eliminar Arista" << endl;
                                cout << "  0. Salir." << endl;
                                cout << "Seleccione una opción válida ";
                                int op2;
                                cin >> op2;
                                switch (op2) {
                                    case 1:
                                    {
                                        string etq;
                                        cout << "           Ingrese la etiqueta del nuevo vertice: ";
                                        cin >> etq;
                                        g.AgregarVertice(etq);
                                    }
                                        break;
                                    case 2:
                                    {
                                        string ver;
                                        cout << "           Ingrese el primer vertice: ";
                                        cin >> ver;
                                        string ver2;
                                        cout << "           Ingrese el segundo vertice: ";
                                        cin >> ver2;
                                        int p;
                                        cout << "           Ingrese el peso del arista: ";
                                        cin >> p;
                                        g.AgregarArista(g.ConvierteVertice(ver), g.ConvierteVertice(ver2), p);
                                    }
                                        break;
                                    case 3:
                                    {
                                        string etq;
                                        cout << "           Ingrese la etiqueta del vertice que desea eliminar: ";
                                        cin >> etq;
                                        g.EliminarVertice(g.ConvierteVertice(etq));
                                    }
                                        break;
                                    case 4:
                                    {
                                        string ver;
                                        cout << "           Ingrese el primer vertice: ";
                                        cin >> ver;
                                        string ver2;
                                        cout << "           Ingrese el segundo vertice: ";
                                        cin >> ver2;
                                        g.EliminarArista(g.ConvierteVertice(ver), g.ConvierteVertice(ver2));
                                    }
                                        break;
                                    case 0:
                                    {
                                        seg = false;
                                    }
                                        break;
                                    default:
                                    {
                                        cout << "Seleccione una opción válida" << endl;
                                    }
                                        break;
                                }
                            }
                            bool iguales = alg.Iguales(&g, &g2);
                            if (iguales) {
                                cout << "Los dos grafos son iguales" << endl;
                            } else {
                                cout << "No son iguales" << endl;
                            }
                        }
                            break;

                        case 4:
                        {
                            grafo g2;
                            g2.Crear();
                            alg.Copiar(&g, &g2);
                            cout << "Copiado!" << endl;
                        }
                            break;

                        case 5:
                        {
                            alg.Vendedor(&g);
                        }
                            break;
                        case 6:
                        {
                            alg.Kruscal(&g);
                        }
                            break;
                        case 7:
                        {
                            alg.Prim(&g);
                        }
                            break;
                        case 0:
                        {
                            seguir = false;
                        }
                            break;
                        default:
                        {
                            cout << "   INGRESE UN NUMERO VALIDO\n" << endl;
                        }
                            break;
                    }
                }
            }
                break;

            case 0:
            {
                continuar = false;
            }
                break;
            default:
            {
                cout << "   INGRESE UN NUMERO VALIDO\n" << endl;
            }
                break;
        }
    }

    //        grafo g;
    //        g.Crear();
    //        g.AgregarVertice("a");
    //        g.AgregarVertice("b");
    //        g.AgregarVertice("c");
    //        g.AgregarVertice("d");
    //        g.AgregarArista(g.ConvierteVertice("a"), g.ConvierteVertice("b"), 7);
    //        g.AgregarArista(g.ConvierteVertice("a"), g.ConvierteVertice("c"), 9);    //            a
    //        g.AgregarArista(g.ConvierteVertice("a"), g.ConvierteVertice("d"), 8);    //      7 /   |   \ 9
    //        g.AgregarArista(g.ConvierteVertice("b"), g.ConvierteVertice("c"), 10);   //      b 10--|---- c
    //        g.AgregarArista(g.ConvierteVertice("b"), g.ConvierteVertice("d"), 4);    //      4 \   |8   / 15
    //        g.AgregarArista(g.ConvierteVertice("c"), g.ConvierteVertice("d"), 15);   //            d 
    //       
    //
    //
    //    AlgoritmosGrafos alg;
    //    alg.Prim(&g);
    //    //alg.Vendedor(&g);

    return 0;
}

