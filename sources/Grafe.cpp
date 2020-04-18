#include <iostream>
#include <cstdio>
#include <cstdlib>
#define N 5 //Numero 5 predefimido
using namespace std;
int coste=0;
    void mostrarSol(int path[]);

    //Verifica si el vertice puede ser añadido al ciclo
    bool verificar(int n, bool g[N][N], int path[], int pos) {
    if (g [path[pos-1]][n] == 0)
        return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == n)
            return false;
        coste+=(g[pos][n]);
    return true;
    }
    bool hamilton(bool g[N][N], int path[], int pos) {
    //Si todos los vertices pertenecen al ciclo, entonces es verdadero
    if (pos == N) {
        if (g[ path[pos-1] ][ path[0] ] != 0){
            return true;
        }
        else{
                return false;
        }
            
    }
    for (int n = 1; n < N; n++) {
        if (verificar(n, g, path, pos)) 
        {

            path[pos] = n;
            //Llamada recursiva del algoritmo para construir la solucion
            if (hamilton (g, path, pos+1) == true)
                return true;
            path[pos] = -1;
            //Vertice se elimina si no se puede añadir
        }
    }
    return false;
    }
    bool hamCycle(bool g[N][N]) {
        coste=0;
    int *path = new int[N];
    for (int i = 0; i < N; i++)
        path[i] = -1;
    path[0] = 0;
    if (hamilton(g, path, 1) == false) {
        cout<<"\nNo existe ciclo hamiltoniano"<<endl;
        return false;
    }
    mostrarSol(path);
    return true;
    }
    void mostrarSol(int p[]) {
    cout<<"Ciclo encontrado \n";
    cout<<" El ciclo es:  \n"<<endl;
    for (int i = 0; i < N; i++)
        cout<<p[i]<<"->";
        cout<< p[0]<<endl;
    cout<<"El coste es: "<<coste;
    }

int main() {
   bool g[N][N] = {
      {0, 1, 0, 8, 1},
      {0, 0, 3, 1, 0},
      {0, 3, 0, 2, 1},
      {1, 1, 4, 0, 1},
      {0, 1, 1, 0, 0},
   };
   hamCycle(g);
   cout<<endl;

      bool h[N][N] = {
      {0, 1, 0, 8, 1},
      {0, 0, 3, 0, 0},
      {0, 2, 0, 2, 1},
      {1, 0, 2, 0, 0},
      {0, 0, 1, 0, 0},
   };
   hamCycle(h);
   return 0;
}