#include <iostream>
#include "Lista.h"
#include "ListaDoble.h"
#include "NodoArbol.h"
#include "ArbolBinario.h"

#include <stdlib.h>
#include <vector>
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

int CONT=0;
vector<int>pos_x;
vector<int>pos_y;

void imprimir(char tablero[10][10])
{
    cout<<"--------------------"<<endl;
    for(int y=0;y<10;y++)
    {
        for(int x=0;x<10;x++)
            cout<<tablero[x][y];
        cout<<endl;
    }
    cout<<"--------------------"<<endl;
}

bool puedoLLegar(int inicio_x, int inicio_y,
                 int final_x, int final_y,
                 int pasos, char tablero[10][10])
{
    //Caso base: obstaculos
    if(tablero[inicio_x][inicio_y]=='@')
        return false;

    //Caso base:fuera de rango o sin pasos
    if(inicio_x>=10
       || inicio_x<0
       || inicio_y>=10
       || inicio_y<0
       || pasos<0)
       return false;

    //Caso base: llegué
    if(inicio_x==final_x
       && inicio_y == final_y)
    {
        CONT++;

        imprimir(tablero);
        pos_x.clear();
        pos_y.clear();

        return true;
    }

    //Marco por dondo pasé
    //tablero[inicio_x][inicio_y]='-';

    //LLamadas recursivas
    bool respuesta = false;

    if(puedoLLegar(inicio_x+1,inicio_y,final_x,final_y,pasos-1,tablero))
        respuesta=true;

    if(puedoLLegar(inicio_x-1,inicio_y,final_x,final_y,pasos-1,tablero))
        respuesta=true;

    if(puedoLLegar(inicio_x,inicio_y+1,final_x,final_y,pasos-1,tablero))
        respuesta=true;

    if(puedoLLegar(inicio_x,inicio_y-1,final_x,final_y,pasos-1,tablero))
        respuesta=true;

    if(respuesta)
    {
        pos_x.push_back(inicio_x);
        pos_y.push_back(inicio_y);

        for(int i=0;i<pos_x.size();i++)
        {
            if(CONT==0)
                tablero[pos_x[i]][pos_y[i]]='1';
            if(CONT==1)
                tablero[pos_x[i]][pos_y[i]]='2';
            if(CONT==2)
                tablero[pos_x[i]][pos_y[i]]='3';
            if(CONT==3)
                tablero[pos_x[i]][pos_y[i]]='4';
        }
    }

    //Regreso si hay al menos una respuesta
    return respuesta;
}

bool encontre_llave=false;

bool tieneSolucion(int inicio_x, int inicio_y,
                   int pasos,
                   char tablero[5][5])
{
    //Caso base:fuera de rango
    if(inicio_x>=5
       || inicio_x<0
       || inicio_y>=5
       || inicio_y<0
       || pasos<0)
       return false;

//    cout<<"A";
    //Caso base: obstaculos
    if(tablero[inicio_x][inicio_y]=='#')
        return false;

    if(tablero[inicio_x][inicio_y]=='L')
        encontre_llave=true;

    if(tablero[inicio_x][inicio_y]=='S' && encontre_llave)
        return true;

    //Marco por dondo pasé
    //tablero[inicio_x][inicio_y]='-';

    //LLamadas recursivas
    bool respuesta = false;

    if(tieneSolucion(inicio_x+1,inicio_y,pasos-1,tablero))
        respuesta=true;

    if(tieneSolucion(inicio_x-1,inicio_y,pasos-1,tablero))
        respuesta=true;

    if(tieneSolucion(inicio_x,inicio_y+1,pasos-1,tablero))
        respuesta=true;

    if(tieneSolucion(inicio_x,inicio_y-1,pasos-1,tablero))
        respuesta=true;

    //Regreso si hay al menos una respuesta
    return respuesta;
}

int main()
{
////    ArbolBinario arbol;
////    arbol.imprimir();
////    cout<<arbol.getMenor(arbol.padre)<<endl;
//
//////////////////////////////////////////////////////////////
//
//char tablero[5][5]={{'#','#','#','#','#'},
//                    {'#',' ','#',' ','L'},
//                    {'#',' ','#',' ','#'},
//                    {'#',' ',' ',' ',' '},
//                    {'#','#','#','#','S'}};
//
//
////    imprimir(tablero);
//
//    cout<<tieneSolucion(1,1,//inicio
//                        10,
//                      tablero)<<endl;
//
//
////    imprimir(tablero);
//
//    cout<<"Soluciones: "<<CONT<<endl;
//
//////////////////////////////////////////////////////////////





//    ArbolBinario arbol;
//    arbol.imprimir();
//
//    for(int i=0;i<100;i++)
//        cout<<rand()%360+1<<endl;

   ListaDoble lista;
   lista.addNodo(new NodoDoble(1));
   lista.addNodo(new NodoDoble(2));
   lista.addNodo(new NodoDoble(5));
   lista.addNodo(new NodoDoble(3));

   lista.addNodo(7,new NodoDoble(0));

   lista.imprimir();
}
