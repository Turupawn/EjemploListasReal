#include <iostream>
#include "Lista.h"
#include "ListaDoble.h"
#include "NodoArbol.h"
#include "ArbolBinario.h"

#include <stdlib.h>
using namespace std;

//void misterioAhmed( int fin,int otra_varable)
//{
//    if (fin>0){
//        cout<<otra_varable-fin+1<<endl;
//        misterioAhmed( fin-1,otra_varable);
//    }
//}
//
//void misterio( int fin)
//{
//    if (fin>0){
//
//        misterio( fin-1);
//        cout<<fin<<endl;
//    }
//}
//
//
//void misterio(int inicio, int fin)
//{
//    if (inicio<=fin){
//        cout<<inicio<<endl;
//        inicio++;
//        misterio(inicio , fin);
//    }
//}

bool funcion(char tablero[10][10],int x_inicio,int y_inicio, int x_final,int y_final, int pasos)
{
    if(pasos<0)
        return false;

    if(x_inicio<0 && x_inicio>=10)
        return false;
    if(y_inicio<0 && y_inicio>=10)
        return false;
    if(x_final <0 && x_final>=10)
        return false;
    if(y_final <0 && y_final>=10)
        return false;

    if(tablero[x_inicio][y_inicio]=='@')
    {
        return false;
    }

    if(x_inicio == x_final
       && y_inicio == y_final)
    {
        tablero[x_inicio][y_inicio]='X';
        return true;
    }


    tablero[x_inicio][y_inicio]='A';

    cout<<"----------"<<endl;
    for(int y=0;y<10;y++)
    {
        for(int x=0;x<10;x++)
            cout<<tablero[x][y];
        cout<<endl;
    }
    cout<<"----------"<<endl;

    tablero[x_inicio][y_inicio]='-';

    bool resultado=false;

    if(funcion(tablero,x_inicio+1,y_inicio,x_final,y_final,pasos-1)
        || funcion(tablero,x_inicio-1,y_inicio,x_final,y_final,pasos-1)
        || funcion(tablero,x_inicio,y_inicio+1,x_final,y_final,pasos-1)
        || funcion(tablero,x_inicio,y_inicio-1,x_final,y_final,pasos-1))
        resultado=true;

    return resultado;
}

int main()
{
    char tablero[10][10];
    for(int y=0;y<10;y++)
    {
        for(int x=0;x<10;x++)
            tablero[x][y]='#';
    }

    tablero[6][6]='@';
    tablero[7][6]='@';
    tablero[6][7]='@';

    cout<<funcion(tablero,5,5,7,7,10)<<endl;

    for(int y=0;y<10;y++)
    {
        for(int x=0;x<10;x++)
            cout<<tablero[x][y];
        cout<<endl;
    }

//    ArbolBinario arbol;
//    arbol.imprimir();

//    misterio(4,100);
//    misterio(10);
//    misterioAhmed(10,10);

//    for(int i=0;i<100;i++)
//        cout<<rand()%360+1<<endl;

//   ListaDoble lista;
//   lista.addNodo(new NodoDoble(1));
//   lista.addNodo(new NodoDoble(2));
//   lista.addNodo(new NodoDoble(3));
//
//   lista.addNodo(7,new NodoDoble(0));
//
//   lista.imprimir();
}
