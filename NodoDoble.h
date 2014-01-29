#ifndef NODODOBLE_H
#define NODODOBLE_H

#include <iostream>

class NodoDoble
{
    public:
        NodoDoble*anterior;
        NodoDoble*siguiente;
        int numero;

        NodoDoble();
        NodoDoble(int numero);
        int getNumero();
        void setNumero(int n);
        virtual ~NodoDoble();
    protected:
    private:
};

#endif // NODODOBLE_H
