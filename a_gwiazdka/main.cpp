#include <iostream>
#include <fstream>
#include<math.h>
#include<list>
#include <stdlib.h>

using namespace std;

const int wym2=3;
const int wym1=3;

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


//void mozliwe_do_odwiedzenia(int** map, int x, int y, int** otwarta)
//{
//	
//	if (map[y+1][x] == 0)
//	{
//		cout<<"dol intnieje";
//	}
//	
//
//}

void mozliwe_do_odwiedzenia(int map[wym2][wym1], int otwarta[wym2][wym1], int x, int y)
{
	
if ( (map[x+1][y] == 0) && ((x+1) <= wym2) )
	{
		cout<<"dol istnieje\n";
		otwarta[x+1][y] = map[x+1][y];
	}	
	
if ( (map[x][y-1] == 0) && ((y-1) > 0) )
	{
		cout<<"lewo istnieje\n";
		otwarta[x][y-1] = map[x][y-1];
	}
	
if ( (map[x-1][y] == 0) && ((x-1) > 0) )
	{
		cout<<"gora istnieje\n";
		otwarta[x-1][y] = map[x-1][y];
	}	
	
if ( (map[x][y+1] == 0) && ((y+1) <= wym1) ) 
	{
		cout<<"prawo istnieje\n";
		otwarta[x][y+1] = map[x][y+1];
	}
}	
	

void wyczysc_otwarta(int otwarta[wym2][wym1])
{
	for(int i=1;i<wym2+1;i++)
 	{
  		for(int j=1;j<wym1+1;j++)
  		{
    		otwarta[i][j] = 1;
   		}
 	}
}








int main()
{

///////////////////////////////////////////////////////////////////////

cout<<"Wczytywanie danych z pliku\n";

string nazwap="grid.txt";


int map[wym2][wym1];
int& start = map[1][1];
int& cel = map[3][3];
int parent[wym2][wym1];
double f[wym2][wym1];
int g[wym2][wym1];
double h[wym2][wym1];

int otwarta[wym2][wym1];
int zamknieta[wym2][wym1];
zamknieta[0][0] = start;
double koszta[wym2][wym1];
int trasa[wym2][wym1];

 //wypelnianie listy otwartej
 for(int i=1;i<wym2+1;i++)
 {
  for(int j=1;j<wym1+1;j++)
   {
    otwarta[i][j] = 1;
   }
 }


//teraz deklarujemy dynamicznie tablice do, której wczytamyu nasz plik,
int rows = wym2+1;
double **G;
G = new double*[rows];
while(rows--) G[rows] = new double[wym1+1];

cout<<"\n\nNacisnij ENTER aby wczytac tablice o nazwie "<< nazwap;
getchar();

std::ifstream plik(nazwap.c_str());
  
for ( unsigned int i=1;i<wym2+1;i++)    
  {
    for ( unsigned int j=1;j<wym1+1;j++) 
    {
         plik >> G[i][j];
    }
  }  
plik.close();


//wypelnianie mapy
for(int i=1;i<wym2+1;i++)
 {
  for(int j=1;j<wym1+1;j++)
   {
    map[i][j] = G[i][j];
   }
 }
 



cout<<"\nWypisujemy na ekran\n\n";
for(int i=1;i<wym2+1;i++)
 {
  for(int j=1;j<wym1+1;j++)
   {
    cout<<" "<<map[i][j];
   }cout<<"\n";
 }
   
//na koniec czyścimy pamięć po naszej tablicy
for(int i=0;i<wym2+1;i++)
{delete[] G[i];}//czyscimy wiersze
delete[] G;//zwalniamy tablice wskaznikow do wierszy

///////////////////////////////////////////////////////////////////////

cout<<endl<<endl;

for(int i=1;i<wym2+1;i++)
 {
  for(int j=1;j<wym1+1;j++)
   {
    cout<<" "<<map[i][j];
   }cout<<"\n";
 }

mozliwe_do_odwiedzenia(map, otwarta, 1, 1);

cout<<endl<<endl;
for(int i=1;i<wym2+1;i++)
 {
  for(int j=1;j<wym1+1;j++)
   {
    cout<<" "<<otwarta[i][j];
   }cout<<"\n";
 }
 
 
 wyczysc_otwarta(otwarta);
 
 cout<<endl<<endl;
for(int i=1;i<wym2+1;i++)
 {
  for(int j=1;j<wym1+1;j++)
   {
    cout<<" "<<otwarta[i][j];
   }cout<<"\n";
 }
 






cout<<"\n\nNacisnij ENTER aby zakonczyc";
getchar();




    return 0;
}
