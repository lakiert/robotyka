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


int main()
{
    int mapa_rows = 5;
    int mapa_columns = 5;
    int mapa[mapa_rows][mapa_columns] = { {0,0,0,0,0}, {0,0,0,0,1}, {1,1,0,0,1}, {0,0,0,0,0}, {0,0,1,0,0} };

    int poczatek[2]={0,0};
    int koniec[2]={5,5};
    int otwarta[4][2]={};
    int pusta[mapa_rows*mapa_columns][2];
    pusta[0][0]=koniec[0];
    pusta[0][1]=koniec[1];

// heurystyka, x i y dla rozwazanej kratki
    double h = funkcja_h(2,3,7,8);
    cout<<h;

    int jakies_g = funkcja_g(2,2,5,0);
    cout << "\n" << jakies_g;


    for(int i =0; i<=mapa_rows-1; i++)
    {
        cout<<endl;
        for(int j=0; j<=mapa_columns-1; j++)
        {
            cout<<mapa[i][j];
            cout<<" ";
        }

    }

    return 0;
}
