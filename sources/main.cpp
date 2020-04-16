#include "Matrices.cpp"
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
}