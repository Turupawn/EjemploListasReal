#include "ArbolBinario.h"

ArbolBinario::ArbolBinario()
{
    NodoArbol*cinco=new NodoArbol(5);
    NodoArbol*seis=new NodoArbol(6);
    NodoArbol*siete=new NodoArbol(7);
    NodoArbol*ocho=new NodoArbol(8);
    NodoArbol*nueve=new NodoArbol(9);

    cinco->hijo_izq=seis;
    cinco->hijo_der=nueve;
    seis->hijo_izq=siete;
    seis->hijo_der=ocho;

    padre=cinco;
}

ArbolBinario::~ArbolBinario()
{
    //dtor
}

void ArbolBinario::imprimir()
{
    imprimir(padre);
}

void ArbolBinario::imprimir(NodoArbol*nodo)
{
    cout<<nodo->num<<endl;
    if(nodo->hijo_izq!=NULL)
        imprimir(nodo->hijo_izq);
    if(nodo->hijo_der!=NULL)
        imprimir(nodo->hijo_der);
}

bool ArbolBinario::existe(int num)
{
    return false;
}

bool ArbolBinario::existe(NodoArbol*nodo,int num)
{
    return false;
}

int ArbolBinario::getMenor(NodoArbol*nodo)
{
    if(nodo==NULL)
        return 99999;
    int menor=nodo->num;
    int menor_izq=getMenor(nodo->hijo_izq);
    if(menor_izq<menor)
        menor=menor_izq;
    int menor_der=getMenor(nodo->hijo_der);
    if(menor_der<menor)
        menor=menor_der;

    return menor;
}
