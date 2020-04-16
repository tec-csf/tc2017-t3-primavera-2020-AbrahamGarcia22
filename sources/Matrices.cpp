#include <iostream>
#include <climits>
using namespace std;
class Matrices{
    public:
    /* Recibe una lista de dimensiones, siendo que para que una multiplicacion de 
    matrices sea posible, la dimension de "j" de la primer matriz, deberá ser la
    dimension "i" de la siguiente.*/

    void multiplicacionMatriz(int* p, int size){
        int valor;
        int valores[size][size];

        //Se llena con ceros la matriz
        for(int i=0;i<size;++i){
            valores[i][i]=0;
        }
        //Llenamos por diagonales, obteniendo los valores de las diagonales previas.
        for(int diagonal=1; diagonal<size;++diagonal){
            int i=0;
            int j=diagonal;
            while(i<size && j<size){
                int min=INT16_MAX;
                for(int k=i;k<j;++k){
                    valor=valores[i][k]+valores[k+1][j]+p[i]*p[k+1]*p[j+1];
                    if(valor<min){
                        min=valor;
                    }
                }
                valores[i][j]=min;
                i++;
                j++;
                
            }

        }
        /*for(int i=0; i<size; i++){        //Descomentar para imprimir la matriz
            for(int j=0; j<size; j++){
                cout <<"["<< valores[i][j] <<"]" ;
            }
            cout << endl;
        }*/
        cout<<"El resultado es: "<<valores[0][size-1]<<endl;
        //El resultado es la esquina superior derecha    
    }

};