#ifndef NODOARBOL_H
#define NODOARBOL_H

#include <iostream>

class NodoArbol
{
    public:
        NodoArbol*hijo_izq;
        NodoArbol*hijo_der;
        int num;
        NodoArbol(int num);
        virtual ~NodoArbol();
    protected:
    private:
};

#endif // NODOARBOL_H
