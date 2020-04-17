#include <iostream>
#include <stack>
#include <list>
using namespace std;

class Arista;

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
        aux=origen->adyacente;
        if(aux==NULL){
            origen->adyacente=nueva;
            nueva->adyacente=destino;
        }
        else{
            while(aux->siguiente!=NULL){
                aux=aux->siguiente;
                //nueva->adyacente=destino;
            }
            aux->siguiente=nueva;
            nueva->adyacente=destino;
        }
    }
    void insertarVertice(string nombre){
        Vertice *nuevo=new Vertice();
        nuevo->nombreNodo=nombre;
        nuevo->siguiente=NULL;
        nuevo->adyacente=NULL;
        if(vacio()){
            v0=nuevo;
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
    void hamiltoniano(){
    Vertice *vAux;
    Arista *aAux;
    vAux=v0;
    int nodos=7;
    hamiltonianoAux(getVertice("A"));
    
        
    }
    void hamiltonianoAux(Vertice* actual){
        Vertice *verticeaux;
        Arista *aristaaux;
       verticeaux=actual;
        while(verticeaux!=NULL){
            aristaaux=verticeaux->adyacente;
            while(aristaaux!=NULL){
                verticeaux=aristaaux->adyacente;
                if(verticeaux!=NULL){
                    cout<<"flag"<<endl;
                    hamiltonianoAux(verticeaux);
                }
                else{
                    return;
                }
                aristaaux=aristaaux->siguiente;
            } 
        }
         
    }
    void profundiad(Vertice *actual){
        stack<Vertice*> pila;
        list<Vertice*>lista;
        int flag=0;
        int flag2=0;
        list<Vertice*>::iterator i;
        pila.push(actual);
        while(!pila.empty()){
            actual=pila.top();
            pila.pop();
            for(i=lista.begin();i!=lista.end();i++){
                if (*i ==actual){
                    flag=1;
                }
            }
            if(flag==0){
                cout<<actual->nombreNodo<<", ";
                lista.push_back(actual);
                Arista *aux;
                aux=actual->adyacente;
                while(aux!=NULL){
                    for(i=lista.begin();i!=lista.end();i++){
                        if (*i ==aux->adyacente){
                        flag2=1;
                        }   
                    }
                    if(flag2==0){
                        pila.push(aux->adyacente);
                    }
                    aux=aux->siguiente;
                }

            }
        }




    }
            list<Vertice*>visitado;
        list<Vertice*>::iterator i;
    void profundidad(Vertice *actual){git 
        int flag=0;
        Arista *aux;
        aux=actual->adyacente;
        visitado.push_back(actual);
        while(aux!=NULL){
            for(i=visitado.begin();i!=visitado.end();i++){
                if(*i ==aux->adyacente){
                    flag=1;
                    //cout<<"algf"<<endl;
                }
            }
            if(flag==0){
                visitado.push_back(aux->adyacente);
                cout<<aux->adyacente->nombreNodo<<",";
                
                profundidad(aux->adyacente);
            }
            else{
                if(visitado.size()!=5){
                    aux=aux->siguiente;
                }
                else{
                    return;
                }
                
            }
        }
        cout<<endl;
    }
};
int main(){
    Grafo g;
    /*g.insertarVertice("A");
    g.insertarVertice("B");
    g.insertarVertice("C");
    g.insertarVertice("D");
    g.insertarVertice("E");
    g.insertarVertice("F");*/
    g.insertarVertice("1");
    g.insertarVertice("2");
    g.insertarVertice("3");
    g.insertarVertice("4");
    g.insertarVertice("5");
    /*g.insertarArista(g.getVertice("A"),g.getVertice("B"),500);
    g.insertarArista(g.getVertice("B"),g.getVertice("C"),50);
    g.insertarArista(g.getVertice("C"),g.getVertice("D"),50);
    g.insertarArista(g.getVertice("D"),g.getVertice("B"),5);
    g.insertarArista(g.getVertice("E"),g.getVertice("F"),10);
    g.insertarArista(g.getVertice("F"),g.getVertice("A"),40);
    g.insertarArista(g.getVertice("G"),g.getVertice("E"),10);
    g.insertarArista(g.getVertice("A"),g.getVertice("F"),500);*/
    g.insertarArista(g.getVertice("1"),g.getVertice("2"),50);
    g.insertarArista(g.getVertice("1"),g.getVertice("3"),50);
    g.insertarArista(g.getVertice("2"),g.getVertice("4"),50);
    g.insertarArista(g.getVertice("2"),g.getVertice("5"),50);
    g.insertarArista(g.getVertice("1"),g.getVertice("5"),50);
    cout<<g.size()<<endl;
    //cout<<g.getVertice("A")->adyacente->adyacente->adyacente->adyacente->nombreNodo<<endl;
    g.lista();
    g.profundidad(g.v0);
}

