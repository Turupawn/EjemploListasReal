#ifndef NODO_H
#define NODO_H
#include <iostream>
using namespace std;


class Nodo
{
    public:
        Nodo *siguiente;
        int numero;

        Nodo();
        Nodo(int n);
        int getNumero();
        void setNumero(int n);
        virtual ~Nodo();
    protected:
    private:
};

#endif // NODO_H
