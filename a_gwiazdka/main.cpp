#include <iostream>
#include<math.h>
#include<list>
#include <stdlib.h>

using namespace std;

double funkcja_h(int pozx, int pozy, int celx, int cely)
{
double h = sqrt(pow((pozx-celx),2)+pow((pozy-cely),2));
return h;
}

int funkcja_g(int from_x, int from_y, int to_x, int to_y)
{
int krok_x = abs(from_x - to_x);
int krok_y = abs(from_y - to_y);
int g = krok_x+krok_y;
return g;
}


void map_print(int mapa[][5], int rows, int columns)
{
    for(int i =0; i<=rows-1; i++)
    {
        cout<<endl;
        for(int j=0; j<=columns-1; j++)
        {
            cout<<mapa[i][j];
            cout<<" ";
        }

    }

}

   // int mapa_rows = 5;
   // int mapa_columns = 5;

   // int mapa[mapa_rows][mapa_columns] = { {0,0,0,0,0}, {0,0,0,0,1}, {1,1,0,0,1}, {0,0,0,0,0}, {0,0,1,0,0} };

int main()
{

    int mapa_rows = 5;
    int mapa_columns = 5;
    int mapa[5][5] = { {0,0,0,0,0}, {0,0,0,0,1}, {1,1,0,0,1}, {0,0,0,0,0}, {0,0,1,0,0} };

    ////////////////////////////////////////////////////////////////////////////////////

    int poczatek[2]={0,0};
    int koniec[2]={5,5};
    int otwarta[4][3]={};
    int zamknieta[mapa_rows*mapa_columns][2];
    int trasa[mapa_rows*mapa_columns][3];


    ////////////////////////////////////////////////////////////////////////////////////

// heurystyka, x i y dla rozwazanej kratki
    double h = funkcja_h(2,3,7,8);
    cout<<h;

    int jakies_g = funkcja_g(2,2,5,0);
    cout << "\n" << jakies_g;


    ////////////////////////////////////////////////////////////////////////////////////

    map_print(mapa, mapa_rows, mapa_columns);

    ////////////////////////////////////////////////////////////////////////////////////

    mapa[poczatek[0]][poczatek[1]]=3;
    mapa[koniec[0]-1][koniec[1]-1]=3;
    cout<<endl;

    ////////////////////////////////////////////////////////////////////////////////////

    map_print(mapa, mapa_rows, mapa_columns);

    ////////////////////////////////////////////////////////////////////////////////////


    zamknieta[0][0]=poczatek[0];
    zamknieta[0][1]=poczatek[1];
    trasa[0][0]=poczatek[0];
    trasa[0][1]=poczatek[1];







    return 0;
}
