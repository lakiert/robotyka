// v4

#include <iostream>
#include <fstream>
#include<math.h>
#include<list>
#include <stdlib.h>

using namespace std;

const int wym2=5;
const int wym1=5;
int start_x = 4;
int start_y = 1;
int cel_x = 2;
int cel_y = 5;

int map[wym2][wym1];
int otwarta[wym2][wym1];
int zamknieta[wym2][wym1];
int parent[wym2][wym1];
int priorytet[wym2][wym1];
int trasa[wym2][wym1];
float koszta[wym2][wym1];



float funkcja_h(int start_x, int start_y, int cel_x, int cel_y)
{
float h = sqrt( pow((start_x-cel_x),2) + pow((start_y-cel_y),2) );
return h;
}


float funkcja_g(int from_x, int from_y, int to_x, int to_y)
{
	float krok = 0;
	int x = to_x;
	int y = to_y;
	int pomoc = otwarta[x][y];
	
	while(pomoc != parent[from_x][from_y])
	{
		if(pomoc == 1)
		{
			x-=1;
			pomoc = parent[x][y];
			krok++;
		}
		else if(pomoc == 2)
		{
			y+=1;
			pomoc = parent[x][y];
			krok++;
		}
		else if(pomoc == 3)
		{
			x+=1;
			pomoc = parent[x][y];
			krok++;
		}
		else if(pomoc == 4)
		{
			y-=1;
			pomoc = parent[x][y];
			krok++;
		}
	}

return krok;

}




void mozliwe_do_odwiedzenia()
{
	
	for(int x=1;x<wym2+1;x++)
 	{
  		for(int y=1;y<wym1+1;y++)
  		{
    	
		if ( (map[x+1][y] == 0) && ((x+1) <= wym2) && (zamknieta[x+1][y] != 1) && (zamknieta[x][y] == 1) )
		{
		//	cout<<"dol istnieje\n";
			otwarta[x+1][y] = 1;
		}	
		
		if ( (map[x][y-1] == 0) && ((y-1) > 0) && (zamknieta[x][y-1] != 1) && (zamknieta[x][y] == 1) )
		{
		//	cout<<"lewo istnieje\n";
			otwarta[x][y-1] = 2;
		}
		
		if ( (map[x-1][y] == 0) && ((x-1) > 0) && (zamknieta[x-1][y] != 1) && (zamknieta[x][y] == 1) )
		{
		//	cout<<"gora istnieje\n";
			otwarta[x-1][y] = 3;
		}	
		
		if ( (map[x][y+1] == 0) && ((y+1) <= wym1) && (zamknieta[x][y+1] != 1) && (zamknieta[x][y] == 1) ) 
		{
		//	cout<<"prawo istnieje\n";
			otwarta[x][y+1] = 4;
		}
		
		
		
   		}
 	}
	
	

	
}




void oblicz_koszta(int prio)
{
	
	for(int i=1;i<wym2+1;i++)
 	{
  		for(int j=1;j<wym1+1;j++)
  		{
    		if ((otwarta[i][j]!=5)&&(otwarta[i][j]!=0)&&(map[i][j]!=5))
    		{	
			float h = funkcja_h((i-1),(j-1),(cel_x-1),(cel_y-1));
    		float g = funkcja_g(start_x,start_y,i,j);
    		float f = h + g;
    		koszta[i][j] = f;
			priorytet[i][j] = prio;	
			}
   		}
 	}
 	
	
}


int find_max(int tablica[wym2][wym1])
{

	int maximum = 0;
	for(int i=1; i<=wym2; i++)
	{
		for(int j=1; j<=wym1; j++)
		{
			if (tablica[i][j] > maximum)
			{
				maximum = tablica[i][j];
			}
		}
			
	}
	
	
	return maximum;
	
}





void wybierz_po_kosztach()
{

float mini = 999;
//oblicz mini
for(int i=1;i<wym2+1;i++)
 {
  for(int j=1;j<wym1+1;j++)
   {

	if ((koszta[i][j] != 0) && (koszta[i][j] < mini) &&   (zamknieta[i][j] != 1) )
	{
		mini = koszta[i][j];
	}

   }
 }
 
 //policz ile jest mini
 int ilosc_mini=0;
 for(int i=1;i<wym2+1;i++)
 {
  for(int j=1;j<wym1+1;j++)
   {

	if (koszta[i][j] == mini)
	{
		ilosc_mini++;
	}

   }
 }

 if (ilosc_mini == 1)
    {
    
		// kratka trafia do zamknietej
		for(int i=1;i<wym2+1;i++)
		 {
		  for(int j=1;j<wym1+1;j++)
		   {
		
			if ( (koszta[i][j] == mini) && (zamknieta[i][j] !=1) )
			{
				zamknieta[i][j] = 1;
                parent[i][j] = otwarta[i][j];
				otwarta[i][j] = 0;
				koszta[i][j] = 0;

			}
		
		   }
		 }
    
                
    }
    else
    {////////
        

    int maxi = find_max(priorytet);


	   for (int i=1;i<wym2+1;i++)
	   {
	       for (int j=1;j<wym1+1;j++)
	       {
	       
	        if ( (priorytet[i][j] == maxi) && (koszta[i][j] == mini) && (zamknieta[i][j] !=1))
	           {
	            zamknieta[i][j] = 1;
	            parent[i][j] = otwarta[i][j];
				otwarta[i][j] = 0;
				koszta[i][j] = 0; 
	           }             
	       }
	   }
      
      
	}////////
 
}


bool czy_otwarta_pusta()
{

	bool licznik = true;
	
	for(int i=1;i<wym2+1;i++)
	{
		  for(int j=1;j<wym1+1;j++)
		   {
		    if ( (otwarta[i][j] != 0) && (otwarta[i][j] != 5) )
		    {
		    	licznik = false;
		    	return licznik;
			}
		
		   }
 	}
 
 return licznik;
}



int sprawdz_finish(int &finish)
{
	
	
	if (parent[cel_x][cel_y] != 0)
	{
		finish = 1;
		zamknieta[cel_x][cel_y] = 8;
	}

	return finish;
}




void wyznacz_trase()
{

	int x = cel_x;
	int y = cel_y;
	trasa[cel_x][cel_y] = 3;
	trasa[start_x][start_y] = 3;
	int pomoc = parent[x][y];
	
	while(pomoc != parent[start_x][start_y])
	{
		if(pomoc == 1)
		{
			x-=1;
			pomoc = parent[x][y];
			trasa[x][y] = 3;
		}
		else if(pomoc == 2)
		{
			y+=1;
			pomoc = parent[x][y];
			trasa[x][y] = 3;
		}
		else if(pomoc == 3)
		{
			x+=1;
			pomoc = parent[x][y];
			trasa[x][y] = 3;
		}
		else if(pomoc == 4)
		{
			y-=1;
			pomoc = parent[x][y];
			trasa[x][y] = 3;
		}
	}

}





void a_star()
{
	
	int x = start_x;
	int y = start_y;
	int finish = 0;
	int prio = 0;	


while(finish == 0)
{				
	prio++;

	mozliwe_do_odwiedzenia();

	
	if ((czy_otwarta_pusta() == true) && (finish == 0))
	{
		finish=2;
	}

	oblicz_koszta(prio);
	wybierz_po_kosztach();
	finish = sprawdz_finish(finish);
	

}


if(finish == 1)
{
	wyznacz_trase();	
}
else
{
	cout<<"\nERROR - NO WAY! \n";
	cout<<"NIE ZNALEZIONO TRASY! \n";
}


	cout<<"\nTRASA:\n";
	for(int i=1;i<wym2+1;i++)
	 {
	  for(int j=1;j<wym1+1;j++)
	   {
	    cout<<trasa[i][j]<<" ";
	   }cout<<endl;
	 }


}



int main()
{

///////////////////////////////////////////////////////////////////////

cout<<"Wczytywanie danych z pliku\n";

string nazwap="grid.txt";

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
 
//na koniec czyścimy pamięć po naszej tablicy
for(int i=0;i<wym2+1;i++)
{delete[] G[i];}//czyscimy wiersze
delete[] G;//zwalniamy tablice wskaznikow do wierszy


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////



//wypisanie mapy
cout<<"\nMAPA:\n";
for(int i=1;i<wym2+1;i++)
 {
  for(int j=1;j<wym1+1;j++)
   {
    cout<<map[i][j]<<" ";
   }cout<<endl;
 }
 
 //wypelnienie otwartej
for(int i=1;i<wym2+1;i++)
 {
  for(int j=1;j<wym1+1;j++)
   {
    otwarta[i][j] = map[i][j];
    priorytet[i][j] = 0;
   }
 }
 
  //wypelnienie trasy
for(int i=1;i<wym2+1;i++)
 {
  for(int j=1;j<wym1+1;j++)
   {
   	if ( ((i==start_x)&&(j==start_y)) || ((i==cel_x)&&(j==cel_y)) )
   	{
   		trasa[i][j] = 3;
	}
	else
	{
		trasa[i][j] = map[i][j];
	}
   }
 }

//wypelnienie parent i zamknieta
for(int i=1;i<wym2+1;i++)
 {
  for(int j=1;j<wym1+1;j++)
   {
   	if((i==start_x)&&(j==start_y))
   	{
   	parent[i][j] = 7;
	zamknieta[i][j] = 1;	
	}
	else
	{
	parent[i][j] = map[i][j];
	zamknieta[i][j] = map[i][j];
	}
    
   }
 }


a_star();



cout<<"\n\nNacisnij ENTER aby zakonczyc";
getchar();


    return 0;
}
