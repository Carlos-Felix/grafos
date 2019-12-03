#include "grafo.h"
#include <cstddef>

Grafo::Grafo(){
    first = NULL;
}
Grafo::~Grafo(){
    eliminarTodoVertice();
}

void Grafo::insertarVertice(int x){
    vertice* q = new vertice;
    q->dato = x;
    q->fr = NULL;
    q->sig = NULL;
    if(first == NULL){
        first = q;
        return;
    }
    bool fnd = false;
    vertice* p = first;
    while(p->sig != NULL){
        if(p->dato == x){
            fnd = true;
            break;
        }
        p = p->sig;
    }
    if(!fnd)
        if(p->dato == x)
            fnd = true;
            
    if(!fnd) p->sig = q;
}

vertice* Grafo::buscarVertice(int x){
    vertice* v;
    if(first != NULL){
        v = first;
        while(v->dato != x){
            v = v->sig;
            if(v == NULL) break;
        }
        return v;
        
    }else return NULL;
}

arista* buscarArista(vertice* v,int y){
    if(v->fr != NULL){
        arista* a = v->fr;
        while(a->dato != y){
            a = a->sig;
            if(a == NULL) break;
        }
        return a;

    }else return NULL;
}

void Grafo::insertarArista(int x, int y){
    vertice* n = buscarVertice(x);
    if(n == NULL) return;
    arista* q = new arista;
    q->dato = y;
    q->sig = NULL;
    if(n->fr == NULL){
        n->fr = q;
        return;
    }
    bool fnd = false;
    arista* p = n->fr;
    
    while(p->sig != NULL){
        if(p->dato == y){
            fnd = true;
            break;
        }
        p = p->sig;
    }

    if(!fnd)
        if(p->dato == y)
            fnd = true;
    
    if(!fnd) p->sig = q; 
}

void Grafo::imprimirGrafo(){
    if(first == NULL) return;
    vertice *p = first;
    arista *a;
    while(p != NULL){
        cout << p->dato << " ";
        a = p->fr;
        while(a != NULL){
            cout << a->dato << " ";
            a = a->sig;
        }
        p = p->sig;
        cout << endl;
    }
    cout << endl;
}
/*
void Grafo::eliminarTodoVertice(){
    vertice* vAnterior = NULL,*e;
    vertice* v = first;
    while(v != NULL){
        e = v;
        v = v->sig;
        delete e;
    }
    first = NULL;    
}
*/

void Grafo::eliminarVertice(int x){
    vertice* vAnterior = NULL,*e;
    vertice* v = first;
    while(v->dato != x){
        vAnterior = v;
        v = v->sig;
        if(v == NULL) break;
    }
    eliminarTodaArista(v);
    

    if(vAnterior == NULL){
        if(v != NULL){
            //PRIMER ELEMENTO
            e = v;
            first = v->sig;
            delete e;
        }else{
            //VACIO
        }
    }else{
        if(v != NULL){
            //ELELM MEDIO
            e = v;
            vAnterior->sig = v->sig;
            delete e;
        }else{
            //NO SE HA ENCONTRADO
        }
    }
    
}
void Grafo::eliminarTodoVertice(){
    vertice* v = first,*e;
    while(v != NULL){
        e = v;
        eliminarTodaArista(v);
        v = v->sig;
        delete e;
    }
    first = NULL;
}

void Grafo::eliminarArista(vertice* v,int y){
    arista* aAnterior = NULL;
    arista* a = v->fr,*del;
    if(a != NULL){
        while(a->dato != y){
            aAnterior = a;
            a = a->sig;
            if(a == NULL) break;
        }
    }
    if(aAnterior == NULL){
        if(a != NULL){
            //PRIMER ELEMENTO
            del = a;
            v->fr = a->sig;
            delete del;
        }else{
            //VACIO
        }
    }else{
        if(a != NULL){
            //ELELM MEDIO
            del = a;
            aAnterior->sig = a->sig;
            delete del;
        }else{
            //NO SE HA ENCONTRADO

        }
    }
}



void Grafo::eliminarArista(int x, int y){
    vertice* v = buscarVertice(x);
    if(v != NULL){
        eliminarArista(v,y);
    }
}

void Grafo::eliminarTodaArista(int x){
    vertice* v = buscarVertice(x);
    eliminarTodaArista(v);
}

void Grafo::eliminarTodaArista(vertice* v){
    arista* a = v->fr,*e;
    while(a != NULL){
        e = a;
        a = a->sig;
        delete e;
    }
    v->fr = NULL;
}