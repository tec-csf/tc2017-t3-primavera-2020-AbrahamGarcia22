#include <iostream>
#include <vector>
using namespace std;
class Grafo{
    public:
    vector<vector<int>*> *vectores;
    Grafo(int size){
        vectores=new vector<vector<int>*>;
        for(int i=0;i<size;i++){
            vectores->push_back(new vector<int>);
        }
    
    }
    void insertar(int pos, int nodo){
        vectores->at(pos)->push_back(nodo);
        //cout<<vectores->at(pos)->size()<<" size"<<endl;
    }
   void lista(){
       int size=vectores->size();
       //cout<<size<<" flag"<<endl;
       cout<<"lista de adyacencia: "<<endl<<endl;
        for(int i =0;i<size;i++){
            int size2=vectores->at(i)->size();
            for(int j=0;j<size2;j++){
                if(j==0){
                    cout<<"["<<vectores->at(i)->at(j)<<"]";
                }
                else{
                    cout<<"->"<<vectores->at(i)->at(j);
                }
            }
            cout<<endl;
        }
    }    
};

int main(){
   Grafo g(4);
   g.insertar(0,1);
   g.insertar(0,2);
   g.insertar(1,2);
   g.insertar(1,3);
   g.insertar(2,3);
   g.insertar(2,1);
   g.insertar(2,4);
   g.insertar(3,4);
   g.insertar(3,3);
   g.lista();
}