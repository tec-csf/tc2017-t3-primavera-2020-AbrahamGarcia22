#include <iostream>
#include <stack>
#include <list>
using namespace std;

class Arista;
int contador;
class Vertice{
    public:
    Vertice *siguiente;
    Arista *adyacente;
    string nombreNodo;
};

class Arista{
    public:
    Vertice *adyacente;
    Arista *siguiente;
    int peso;
};
class Grafo{
    
    public:
    Vertice *v0;
    int cont=0;
    Grafo(){
        v0=NULL;
    }
    bool vacio(){
        if(v0==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    int size(){
        int cont=0;
        Vertice *aux;
        aux==v0;
        while(aux!=NULL){
            cont++;
            aux=aux->siguiente;
        }
        return cont;
    }
    Vertice *getVertice(string nombre){
        Vertice *aux;
        aux=v0;
        while(aux!=NULL){
            if(aux->nombreNodo==nombre){
                return aux;
            }
            aux=aux->siguiente;
        }
        return NULL;
    }
    void insertarArista(Vertice *origen,Vertice *destino, int peso){
        Arista *nueva=new Arista;
        nueva->adyacente=NULL;
        nueva->siguiente=NULL;
        nueva->peso=peso;
        Arista *aux;
        Vertice *auxi;
        aux=origen->adyacente;
        if(aux==NULL){
            origen->adyacente=nueva;
            nueva->adyacente=destino;
            cout<<"caso"<<endl;
        }
        else{
            while(aux->siguiente!=NULL){
                aux=aux->siguiente;
                
                //nueva->adyacente=destino;
            }
            aux->siguiente=nueva;
            nueva->adyacente=destino;
            /*if(nueva->peso<aux->peso){
                origen->adyacente=nueva;
                nueva->siguiente=aux;
                

            }








            aux->siguiente=nueva;
            nueva->adyacente=destino;



            cout<<nueva->peso<<" nueva"<<endl;
            cout<<aux->adyacente->nombreNodo<<" auxNO"<<endl;
            cout<<aux->peso<<" aux"<<endl;
            if(nueva->peso<aux->peso){

                cout<<"flag"<<endl;
                Arista *a;
                a=aux;
                cout<<a->adyacente->nombreNodo<<" auxA"<<endl;
                aux->peso=nueva->peso;
                aux->adyacente=nueva->adyacente;
                nueva->peso=a->peso;
                nueva->adyacente=a->adyacente;
                cout<<nueva->adyacente->nombreNodo<<" ADY"<<endl;
                //cout<<aux->siguiente->adyacente->nombreNodo<<"pruba2"<<endl;
                
            }*/
        }

    }
    void insertarVertice(string nombre){
        Vertice *nuevo=new Vertice();
        nuevo->nombreNodo=nombre;
        nuevo->siguiente=NULL;
        nuevo->adyacente=NULL;
        if(vacio()){
            v0=nuevo;
            visitado.push_back(v0);
            contador++;
        }
        else{
            Vertice *aux;
            aux=v0;
            while(aux->siguiente!=NULL){
                aux=aux->siguiente;
            }
            aux->siguiente=nuevo;
        }
    }
    void lista(){
        Vertice *vAux;
        Arista *aAux;
        vAux=v0;
        while(vAux!=NULL){
            cout<<vAux->nombreNodo<<"->";
            aAux= vAux->adyacente;
            while(aAux!=NULL){
                cout<<aAux->adyacente->nombreNodo<<"->";
                aAux=aAux->siguiente;
            }
            vAux=vAux->siguiente;
            cout<<endl;

        }

 


    }
        list<Vertice*>visitado;
        
        list<Vertice*>::iterator i;
    void profundidad(Vertice *actual){
        list<Vertice*>orden;
        //cout<<"el tamano en "<<actual->nombreNodo<<contador<<endl;
        int flag=0;
        Arista *aux;
        aux=actual->adyacente;


        while(aux!=NULL){
                    if(actual==v0){
            cout<<"flag"<<endl;
            visitado.clear();
            visitado.push_back(v0);
        }
            for(i=visitado.begin();i!=visitado.end();i++){
                if(*i ==aux->adyacente){
                    flag=1;
                    if(aux->adyacente==v0&&visitado.size()==7){
                        //break;    g.insertarArista(g.getVertice("A"),g.getVertice("B"),500);

                        cout<<"hay ciclo: "<<actual->nombreNodo<<endl;
                    }
                    //cout<<"algf"<<endl;
                }
            }
            if(flag==0){
                visitado.push_back(aux->adyacente);
                contador++;
                cout<<aux->adyacente->nombreNodo<<",";
                profundidad(aux->adyacente);
            }
            contador--;
            aux=aux->siguiente;
            cout<<"actualizado"<<contador;
            cout<<endl;
        }
        
    }
};
int main(){
    Grafo g;
    g.insertarVertice("A");
    g.insertarVertice("B");
    g.insertarVertice("C");
    g.insertarVertice("D");
    g.insertarVertice("E");
    g.insertarVertice("F");
    g.insertarVertice("G");
    /*g.insertarVertice("1");
    g.insertarVertice("2");
    g.insertarVertice("3");
    g.insertarVertice("4");
    g.insertarVertice("5");*/
    g.insertarArista(g.getVertice("A"),g.getVertice("B"),500);
    g.insertarArista(g.getVertice("A"),g.getVertice("C"),50); 
    g.insertarArista(g.getVertice("A"),g.getVertice("D"),10);   
    g.insertarArista(g.getVertice("B"),g.getVertice("C"),50);
    g.insertarArista(g.getVertice("C"),g.getVertice("D"),50);
    g.insertarArista(g.getVertice("D"),g.getVertice("E"),5);
    g.insertarArista(g.getVertice("E"),g.getVertice("F"),10);
    g.insertarArista(g.getVertice("F"),g.getVertice("G"),40);
    g.insertarArista(g.getVertice("G"),g.getVertice("A"),40);
    g.insertarArista(g.getVertice("B"),g.getVertice("E"),50);
    g.insertarArista(g.getVertice("E"),g.getVertice("C"),50);
    g.insertarArista(g.getVertice("D"),g.getVertice("F"),50);
    g.insertarArista(g.getVertice("F"),g.getVertice("C"),50);
    g.insertarArista(g.getVertice("D"),g.getVertice("G"),50);
    g.insertarArista(g.getVertice("D"),g.getVertice("G"),50);
    g.insertarArista(g.getVertice("D"),g.getVertice("G"),50);


    
   /*g.insertarArista(g.getVertice("1"),g.getVertice("2"),50);
    g.insertarArista(g.getVertice("1"),g.getVertice("3"),50);
    g.insertarArista(g.getVertice("2"),g.getVertice("4"),50);
    g.insertarArista(g.getVertice("2"),g.getVertice("5"),50);
    //g.insertarArista(g.getVertice("4"),g.getVertice("5"),50);*/
    //cout<<g.getVertice("A")->adyacente->adyacente->adyacente->adyacente->nombreNodo<<endl;
    g.lista();
    g.profundidad(g.v0);
}

