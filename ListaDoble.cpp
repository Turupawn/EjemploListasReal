#include "ListaDoble.h"

ListaDoble::ListaDoble()
{
    inicio=NULL;
}

ListaDoble::~ListaDoble()
{
    //dtor
}

void ListaDoble::addNodo(NodoDoble*nodo)
{
    if(inicio==NULL)
    {
        inicio=nodo;
    }
    else
    {
        NodoDoble*temp=inicio;
        while(temp->siguiente!=NULL)
        {
            temp=temp->siguiente;
        }
        temp->siguiente=nodo;
        nodo->anterior=temp;
    }
}

void ListaDoble::imprimir()
{
    NodoDoble*temp=inicio;
    while(temp!=NULL)
    {
        cout<<temp->getNumero()<<endl;
        temp=temp->siguiente;
    }
}

void ListaDoble::imprimir(int pos)
{
    NodoDoble*temp=inicio;

//    int i=0;
//    while(i<pos)
//    {
//        temp=temp->siguiente;
//        i++;
//    }

    for(int i=0;i<pos;i++)
    {
        temp=temp->siguiente;
    }

    cout<<temp->getNumero()<<endl;
}

void ListaDoble::borrar(int pos)
{
    NodoDoble*temp=inicio;

    int i=0;
    while(i<pos)
    {
        temp=temp->siguiente;
        i++;
    }

    if(temp->siguiente!=NULL)
        temp->siguiente->anterior=temp->anterior;
    if(temp->anterior!=NULL)
    {
        temp->anterior->siguiente=temp->siguiente;
    }else
    {
        inicio=temp->siguiente;
    }
}

void ListaDoble::addNodo(int pos,NodoDoble*n)
{
    if(pos<0)
    {
        cout<<"Posicion invalida."<<endl;
        return;
    }
    if(pos==0)//Validar si es el inicio
    {
        n->siguiente=inicio;
        inicio->anterior=n;
        inicio=n;
    }
    else//Si no es el inicio
    {
        //Buscamos el anterior (temp)
        NodoDoble*temp=inicio;
        for(int i=0;i<pos-1;i++)
        {
            temp=temp->siguiente;
            if(temp==NULL)//Si esta despues del final
            {
                cout<<"Posicion invalida."<<endl;
                return;
            }
        }

        if(temp->siguiente!=NULL)//Si no es la ultima posicion
        {
            n->siguiente=temp->siguiente;
            temp->siguiente->anterior=n;

            temp->siguiente=n;
            n->anterior=temp;
        }
        else//Si es la ultima posicion
        {
            temp->siguiente=n;
            n->anterior=temp;
        }
    }
}
