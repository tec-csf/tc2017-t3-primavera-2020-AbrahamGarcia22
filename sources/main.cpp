#include "Matrices.cpp"
#include "Grafe.cpp"
int main(){
    Matrices m;
    int size;
    cout<<"Ingresa el numero de matrices";
    cin>>size;
    int dimensiones[size+1];
    for(int i=0;i<size+1;++i){
        cout<<"Ingresa las dimensiones"<<endl;
        cin>>dimensiones[i];
    }
    m.multiplicacionMatriz(dimensiones,size);
    cout<<'-'*90<<endl;
    Grafe g;

    bool mat[N][N] = {
      {0, 1, 0, 3, 1},
      {0, 0, 1, 3, 0},
      {0, 3, 0, 4, 5},
      {1, 1, 1, 0, 4},
      {0, 1, 2, 0, 0},
   };
   g.hamCycle(mat);
   return 0;
}
