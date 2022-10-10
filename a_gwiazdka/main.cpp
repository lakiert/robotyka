#include <iostream>
#include<math.h>
#include<list>
#include <stdlib.h>

using namespace std;

class Kratka{
public:
    int poz_x;
    int poz_y;
    int parent;
};

double funkcja_h(int pozx, int pozy, Kratka cel)
{
double h = sqrt(pow((pozx-cel.poz_x),2)+pow((pozy-cel.poz_y),2));
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

// tworze kratke cel i nadaje parametry pozycji
    Kratka cel;
    cel.poz_x = 5;
    cel.poz_y = 5;

// tworze punkt startowy i nadaje parametry pozycji
    Kratka start;
    start.poz_x = 0;
    start.poz_y = 0;

// heurystyka, x i y dla rozwazanej kratki
    double h = funkcja_h(2,3,cel);
    cout<<h;


    Kratka otwarta[100];
    Kratka zamknieta[100]={start};

    int jakies_g = funkcja_g(2,2,5,0);
    cout << "\n" << jakies_g;

    return 0;
}
