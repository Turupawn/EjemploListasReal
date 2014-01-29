#include "NodoDoble.h"

NodoDoble::NodoDoble()
{
    anterior=NULL;
    siguiente=NULL;
    setNumero(-1);
}

NodoDoble::NodoDoble(int n)
{
    anterior=NULL;
    siguiente=NULL;
    setNumero(n);
}

NodoDoble::~NodoDoble()
{
    //dtor
}

int NodoDoble::getNumero()
{
    return numero;
}

void NodoDoble::setNumero(int n)
{
    numero=n;
}
