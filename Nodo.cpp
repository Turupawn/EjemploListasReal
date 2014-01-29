#include "Nodo.h"

Nodo::Nodo()
{
    numero=-1;
    siguiente=NULL;
}
Nodo::Nodo(int n){
        setNumero(n);
        siguiente=NULL;
}

Nodo::~Nodo()
{
    //dtor
}
int Nodo::getNumero(){
    return numero;
}

void Nodo::setNumero(int n){
    this->numero=n;
}
