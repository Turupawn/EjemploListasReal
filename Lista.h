#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"

class Lista
{
    public:
        Nodo *inicio;

        Lista();
        void addNodo(Nodo * nodo);
        void imprimir();
        void borrar(int pos);
        virtual ~Lista();
    protected:
    private:
};

#endif // LISTA_H
