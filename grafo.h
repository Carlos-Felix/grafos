//grafo.h
#pragma once

#ifndef __GRAFO_H__
#define __GRAFO_H__

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct arista
{
    int dato;
    arista* sig;

};

struct vertice{
    int dato;
    arista* fr;
    vertice* sig;
};

class Grafo{
private:
    vertice* first;
public:
    Grafo();
    ~Grafo();
    void insertarVertice(int x);
    void insertarArista(int x,int y);
    vertice* buscarVertice(int);
    arista* buscarArista(vertice*,int);
    void imprimirGrafo();
    void eliminarVertice(int);
    //void eliminarVertice(vertice*);
    void eliminarTodoVertice();
    void eliminarArista(vertice*,int);
    void eliminarArista(int, int);
    void eliminarTodaArista(vertice*);
    void eliminarTodaArista(int);
};
#endif