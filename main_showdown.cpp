#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

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
            if(CONT==0)tablero[pos_x[i]][pos_y[i]]='1';if(CONT==1)tablero[pos_x[i]][pos_y[i]]='2';if(CONT==2)tablero[pos_x[i]][pos_y[i]]='3';if(CONT==3)
tablero[pos_x[i]][pos_y[i]]='4';
        }
    }

    //Regreso si hay al menos una respuesta
    return respuesta;
}

int main()
{
    char tablero[10][10];
    for(int y=0;y<10;y++)
    {
        for(int x=0;x<10;x++)
            tablero[x][y]='#';
    }

    tablero[4][2]='@';
    tablero[4][3]='@';

    imprimir(tablero);

    cout<<puedoLLegar(2,2,//inicio
                      5,3,//final
                      6,//pasos
                      tablero)<<endl;
    tablero[2][2]='I';
    tablero[5][3]='D';

    imprimir(tablero);

    cout<<"Soluciones: "<<CONT<<endl;

}
