#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include "NodoArbol.h"
#include <iostream>

using namespace std;

class ArbolBinario
{
    public:
        NodoArbol*padre;
        ArbolBinario();
        virtual ~ArbolBinario();
        void imprimir();
        bool existe(int num);
        bool existe(NodoArbol*nodo,int num);
        void imprimir(NodoArbol*nodo);
        int getMenor(NodoArbol*nodo);
    protected:
    private:
};

#endif // ARBOLBINARIO_H
