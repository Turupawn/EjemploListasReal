#include "Lista.h"

Lista::Lista()
{
    inicio=NULL;
}

Lista::~Lista()
{
    //dtor
}
void Lista::addNodo(Nodo *nodo){
    if (inicio==NULL)
    {
        inicio=nodo;
    }
    else
    {
        Nodo *tem=inicio;
        while(tem->siguiente!=NULL){
            tem=tem->siguiente;

        }
        tem->siguiente=nodo;
    }
}
void Lista::imprimir(){
        Nodo *tem=inicio;
            while(tem!=NULL){
                cout<<tem->numero<<endl  ;
                tem=tem->siguiente;
            }
}
void Lista::borrar(int n){
        Nodo *tem=inicio;
        Nodo *tem_borrar;
        int pos_tem=0;
        if(n==0){
            tem_borrar=inicio;
            inicio=inicio->siguiente;

        }else{
            while(tem!=NULL){
                if(pos_tem+1==n){
                    tem_borrar=tem->siguiente;
                    tem->siguiente=tem->siguiente->siguiente;
                }
                pos_tem++;
                tem=tem->siguiente;
            }

        }
        delete tem_borrar;

}


