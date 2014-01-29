#include "NodoArbol.h"

NodoArbol::NodoArbol(int num)
{
    hijo_izq=NULL;
    hijo_der=NULL;
    this->num=num;
}

NodoArbol::~NodoArbol()
{
    //dtor
}
