#include <iostream>
#include <fstream>
#include<math.h>
#include<list>
#include <stdlib.h>

using namespace std;

const int wym2=6;
const int wym1=6;

float funkcja_h(int start_x, int start_y, int cel_x, int cel_y)
{
float h = sqrt(pow((start_x-cel_x),2)+pow((start_y-cel_y),2));
return h;
}

float funkcja_g(int from_x, int from_y, int to_x, int to_y)
{
float krok_x = abs(from_x - to_x);
float krok_y = abs(from_y - to_y);
float g = krok_x+krok_y;
return g;
}




void mozliwe_do_odwiedzenia(int map[wym2][wym1], int otwarta[wym2][wym1], int parent[wym2][wym1], int &x, int &y, int zamknieta[wym2][wym1], int &finish, int cel_x, int cel_y)
{
	
if ((x+1 == cel_x)&&(y == cel_y))
{
	map[cel_x][cel_y] = 3;
	finish = 1;
	parent[x+1][y] = 0;
	otwarta[x+1][y] = 0;
}
if ((x==cel_x)&&(y-1==cel_y))
{
	map[cel_x][cel_y] = 3;
	finish = 1;
	parent[x][y-1] = 1;
	otwarta[x+1][y] = 1;
}
if ((x-1==cel_x)&&(y==cel_y))
{
	map[cel_x][cel_y] = 3;
	finish = 1;
	parent[x-1][y] = 2;
	otwarta[x+1][y] = 2;
}
if ((x==cel_x)&&(y+1==cel_y))
{
	map[cel_x][cel_y] = 3;
	finish = 1;
	parent[x][y+1] = 3;
	otwarta[x+1][y] = 3;
}
	
	
if ( (map[x+1][y] == 0) && (zamknieta[x+1][y] == 0) && ((x+1) <= wym2) )
	{
//		cout<<"dol istnieje\n";
		otwarta[x+1][y] = 0;
		parent[x+1][y] = 0;
	}	
	
if ( (map[x][y-1] == 0) && (zamknieta[x][y-1] == 0) && ((y-1) > 0) )
	{
//		cout<<"lewo istnieje\n";
		otwarta[x][y-1] = 1;
		parent[x][y-1] = 1;
	}
	
if ( (map[x-1][y] == 0) && (zamknieta[x-1][y] == 0) && ((x-1) > 0) )
	{
//		cout<<"gora istnieje\n";
		otwarta[x-1][y] = 2;
		parent[x-1][y] = 2;
	}	
	
if ( (map[x][y+1] == 0) && (zamknieta[x][y+1] == 0) && ((y+1) <= wym1) ) 
	{
//		cout<<"prawo istnieje\n";
		otwarta[x][y+1] = 3;
		parent[x][y+1] = 3;
	}


}	
	
	
void oblicz_koszta(int otwarta[wym2][wym1], float koszta[wym2][wym1], int &roboczy_x,int &roboczy_y,int cel_x,int cel_y)
{
	
	float h = funkcja_h(roboczy_x,roboczy_y,cel_x,cel_y);
	
	for(int i=1;i<wym2+1;i++)
 	{
  		for(int j=1;j<wym1+1;j++)
  		{
    		if (otwarta[i][j] != 5)
    		{
    			

    		float g = funkcja_g(roboczy_x,roboczy_y,i,j);
    		float f = h + g;
    		koszta[i][j] = f;
    			
    			
			}
   		}
 	}


	
}
	
	
	

void wyczysc_otwarta(int otwarta[wym2][wym1])
{
	for(int i=1;i<wym2+1;i++)
 	{
  		for(int j=1;j<wym1+1;j++)
  		{
    		otwarta[i][j] = 5;
   		}
 	}
}


void wybierz_po_kosztach(int map[wym2][wym1], float koszta[wym2][wym1], int otwarta[wym2][wym1], int parent[wym2][wym1], int zamknieta[wym2][wym1], float temp[4], int &roboczy_x, int &roboczy_y)
{

	int k = 0;
	float mini = 0;
	int maxi = 0;

	for (int i=1;i<wym2+1;i++)
	{
		for (int j=1;j<wym1+1;j++)
		{		
			if (otwarta[i][j] != 5 )
			{	
			temp[k] = koszta[i][j];
			k++;	
			}
		}
	}


   		
	mini = min(min(min(temp[0],temp[1]),temp[2]),temp[3]);

	

 	int licznik = 0;
	for (int i=1;i<wym2+1;i++)
	{
		for (int j=1;j<wym1+1;j++)
		{
				
		  if (koszta[i][j] == mini)
          {
			licznik++;	
		  }
		}
	}
	
	if (licznik == 1)
    {
    
       for (int i=1;i<wym2+1;i++)
       {
           for (int j=1;j<wym1+1;j++)
           {
           
            if (koszta[i][j] == mini)
               {
                 map[i][j] = 3;
                 zamknieta[i][j] = map[i][j];
				 roboczy_x = i;
				 roboczy_y = j;           
               }             
           }
       }
    
                
    }
    else
    {////////
        
        
        int temp2[4]={0,0,0,0};
        int k2=0;
        
        for (int i=1;i<wym2+1;i++)
       {
           for (int j=1;j<wym1+1;j++)
           {
           
            if (koszta[i][j] == mini)
               {
                temp2[k2] = parent[i][j];
                k2++;      
               }             
           }
       }
       
       

       maxi = max(max(max(temp2[0],temp2[1]),temp2[2]),temp2[3]);

       
       
       for (int i=1;i<wym2+1;i++)
       {
           for (int j=1;j<wym1+1;j++)
           {
           
            if (otwarta[i][j] == maxi)
               {
                map[i][j] = 3;
                zamknieta[i][j] = map[i][j];
                roboczy_x = i;
				roboczy_y = j; 
               }             
           }
       }
      
      
    }////////
 	

}


bool czy_otwarta_pusta(int otwarta[wym2][wym1])
{

bool licznik = true;

for(int i=1;i<wym2+1;i++)
 {
  for(int j=1;j<wym1+1;j++)
   {
    if (otwarta[i][j] != 5)
    {
    	licznik = false;
    	return licznik;
	}

   }
 }
 
 return licznik;
}



int main()
{

///////////////////////////////////////////////////////////////////////

cout<<"Wczytywanie danych z pliku\n";

string nazwap="grid.txt";

float temp[4] = {999,999,999,999};
int map[wym2][wym1];

int start_x = 3;
int start_y = 2;
int cel_x = 2;
int cel_y = 6;
int start = map[start_x][start_y];
int cel = map[cel_x][cel_y];

int roboczy_x = start_x;
int *wsk_x = &roboczy_x;

int roboczy_y = start_y;
int *wsk_y = &roboczy_y;

int finish = 0;
int *wsk_finish = &finish;


int parent[wym2][wym1];
int otwarta[wym2][wym1];
int zamknieta[wym2][wym1];
float koszta[wym2][wym1];




//teraz deklarujemy dynamicznie tablice do, której wczytamy nasz plik,
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
 
 //wypelnianie listy otwartej,zamknietej, parent oraz koszta
for(int i=1;i<wym2+1;i++)
 {
  for(int j=1;j<wym1+1;j++)
   {
       	otwarta[i][j] = 5;
    	parent[i][j] = 5;
    	koszta[i][j] = 0;
    	zamknieta[i][j] = 0;
   }
 }
 zamknieta[start_x][start_y] = 3;
 parent[start_x][start_y] = 8;


//na koniec czyścimy pamięć po naszej tablicy
for(int i=0;i<wym2+1;i++)
{delete[] G[i];}//czyscimy wiersze
delete[] G;//zwalniamy tablice wskaznikow do wierszy

///////////////////////////////////////////////////////////////////////



////////////////////////ryneczek//////////////////////////////////////



cout<<"\nMAPA: \n";
for(int i=1;i<wym2+1;i++)
 {
  for(int j=1;j<wym1+1;j++)
   {
    cout<<" "<<map[i][j];
   }cout<<"\n";
 }




cout<<endl<<endl;
cout<<"start: ["<<start_x<<", "<<start_y<<"]"<<endl;
cout<<"cel: ["<<cel_x<<", "<<cel_y<<"]"<<endl;

map[start_x][start_y]=3;
map[cel_x][cel_y]=3;

cout<<"\nMAPA ZE STARTEM I CELEM JAKO LICZBA 3: ";
cout<<"\n";
for(int i=1;i<wym2+1;i++)
 {
  for(int j=1;j<wym1+1;j++)
   {
    cout<<" "<<map[i][j];
   }cout<<"\n";
 }

	
	
while(finish == 0)
{

mozliwe_do_odwiedzenia(map, otwarta, parent, roboczy_x, roboczy_y,zamknieta,finish,cel_x,cel_y);

if ((czy_otwarta_pusta(otwarta) == true) && (finish == 0))
{
finish = 2;	
} 

oblicz_koszta(otwarta,koszta,roboczy_x,roboczy_y,cel_x,cel_y);
wybierz_po_kosztach(map,koszta,otwarta,parent,zamknieta,temp,roboczy_x,roboczy_y);
wyczysc_otwarta(otwarta);

}




cout<<endl<<endl<<"TRASA: \n";
for(int i=1;i<wym2+1;i++)
 {
  for(int j=1;j<wym1+1;j++)
   {
    cout<<" "<<map[i][j];
   }cout<<"\n";
 }
 
if(finish == 2)
{
	cout<<"\nERROR - NO WAY! \n";
	cout<<"NIE ZNALEZIONO TRASY! \n\n";
}


cout<<"\n\nNacisnij ENTER aby zakonczyc";
getchar();




    return 0;
}
