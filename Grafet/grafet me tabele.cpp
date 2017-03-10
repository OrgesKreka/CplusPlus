#include <iostream>

using namespace std;

const int MADHESIAK = 6;

bool G[ MADHESIAK ][ MADHESIAK ];

void inicializoGrafin ()
{
	for( int i = 0 ; i < MADHESIAK; i++ )
		for( int j = 0; j < MADHESIAK; j++ )
			G[ i ][ j ] = false;
} ///FUND inicializo

void shtoKulm( int i, int j )
{
	if( i < MADHESIAK && i >= 0 )
		if( j < MADHESIAK && j >= 0)
			G[ i ][ j ] = true;
	else
		cout << "Koordinata te pavlefshme. . . ";
}

void afishoGraf ()
{
	for( int i = 0; i < MADHESIAK; i++ )
	{
		for( int j = 0; j < MADHESIAK; j++ )
			cout << G[ i ][ j ] << "  ";

		cout << endl;
	}///FUND for
} ///FUND afishoGraf


int numri_i_brinjeve_te_grafit ()
{
    int n = 0;
    
    for( int i = 0 ; i < MADHESIAK; i++ )
         for( int j = 0; j < MADHESIAK; j++ )  
              if( G[ i ][ j ] )  n++;
    
    return n;
}

int rendiDales( int i )
{
    if( i < MADHESIAK && i >= 0 )
    {
        int rendi_dales = 0;
    
        for( int j = 0; j < MADHESIAK; j++ )
              if( G[ i ][ j ]) rendi_dales++;
    
              return rendi_dales;
    }    
}


int rendiHyres( int j )
{ 
    int rendi_hyres = 0;
    
    for( int i = 0; i < MADHESIAK; i++ )
         if( G[ i ][ j ]) rendi_hyres++;
         
    return rendi_hyres;
}

int main ()
{

	inicializoGrafin ();
	shtoKulm( 0, 2 );
	shtoKulm( 0, 4 );
	shtoKulm( 1, 0 );
	shtoKulm( 2, 1 );
	shtoKulm( 2, 5 );
	shtoKulm( 3, 0 );
	shtoKulm( 3, 4 );
	shtoKulm( 5, 2 );
	shtoKulm( 5, 4 );

 afishoGraf ();
 
 cout << "\n\nNumri i brinjeve> " << numri_i_brinjeve_te_grafit ();
 cout << "\n\nNumri i kulmeve hyrese te kulmit 5> " << rendiHyres( 12 );
 cout << "\n\nNumri i kulmeve dalese te kulmit 5> " << rendiDales( 12 );
 
 
 cout << endl << endl;
  system( "pause" );
	return 0;


}
