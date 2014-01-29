#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "NodoDoble.h"
using namespace std;

class ListaDoble
{
    public:
        NodoDoble*inicio;

        ListaDoble();
        void addNodo(NodoDoble*nodo);
        void addNodo(int pos,NodoDoble*nodo);
        void imprimir();
        void imprimir(int pos);
        void borrar(int pos);
        virtual ~ListaDoble();
    protected:
    private:
};

#endif // LISTADOBLE_H
