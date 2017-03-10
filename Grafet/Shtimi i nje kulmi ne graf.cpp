#include <iostream>

using namespace std;

 const int MADHESIAK = 5;

bool G[ MADHESIAK ][ MADHESIAK ];

bool G1[ MADHESIAK + 1][ MADHESIAK + 1 ];

int shtesa = 0;

bool inicializo( int n )
{
     if( n == MADHESIAK )
     {
         for( int i = 0; i < n; i++ )
               for( int j = 0; j < n; j++ )
                G[ i ][ j ] = false; 
     }
     else
     {
            for( int i = 0; i < n; i++ )
               for( int j = 0; j < n; j++ )
                    G1[ i ][ j ] = false;    
     }
         
} ///FUND inicializo

void shtoBrinje( int n , int i, int j )
{   
    if( n == MADHESIAK )
        G[ i ][ j ] = true;
    else
        G1[ i ][ j ] = true;
}


void afisho( int n )
{
     if( n == MADHESIAK )
     {
         for( int i = 0; i < n; i++ )
          {
                  for( int j = 0; j < n; j++ )
                       cout << G[ i ][ j ] << "  ";
                  
                  cout << endl;     
          }   
     }
     else
     {
          for( int i = 0; i < n; i++ )
          {
               for( int j = 0; j < n; j++ )
                    cout << G1[ i ][ j ] << " ";
                
                 cout << endl;  
          } 
         
     }  
}


void shtoKulm ()
{
   
   for( int i = 0; i < MADHESIAK; i++ )
        for( int j = 0; j < MADHESIAK; j++ )
             G1[ i ][ j ] = G[ i ][ j ]; 
             
               delete( G ); 
               
               
               cout << "Kulmi i ri u shtua ne matrice . . . " << endl;   
}


int main ()
{

inicializo( MADHESIAK );
shtoBrinje( MADHESIAK, 1, 1 );
afisho(  MADHESIAK );


shtoKulm ();
shtoBrinje(  MADHESIAK + 1, 5 ,5  );
afisho( MADHESIAK + 1 );




system( "pause" );    
        return 0;

}
