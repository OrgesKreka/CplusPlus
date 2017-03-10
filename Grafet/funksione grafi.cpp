#include <iostream>
#include "struktura Grafit.cpp"
//#include "bredhjeNeGjeresi.cpp"


using namespace std;


int kulmiMeRendinHyresMax( graf *g )
{
    int kulmeDales[ MAXK ] = { 0 };
    
    for( int i = 0; i < MAXK; i++ )
        
        for( brinje *tmp = g->brinjet[ i ]; tmp != 0; tmp = tmp->pas )
             kulmeDales[ tmp->w ]++;
             
             
             
  int max = kulmeDales[ 0 ]; int p = 0;
  
  for( int i = 1; i < MAXK; i++ )
       if( kulmeDales[ i ] > max )
       {
           max = kulmeDales[ i ];
           
           p = i;      
       }    
       
       return p; 
}



/// fuksioni qe merr nje graf dhe i ndryshon drejtimin
void ndryshoDrejtim( graf*g )
{
     graf *g2 = new graf;
     
     inicializoGraf( g2, true );
     
     for( int i = 0; i < MAXK; i++ )
     {
          brinje *tmp = g->brinjet[ i ];
          
          
          while( tmp != 0 )
          {    
              
              brinje *b = new brinje;
              
              b->pesha = 0;
              
              b->w = i;
              
              b->pas = g2->brinjet[ tmp->w ];
              g2->brinjet[ tmp->w ] = b;
              
              g2->nBrinje++;  
              
              tmp = tmp->pas;  
          }   
     }     
     
     
     afishoGraf( g2 );
}


/// 1 0 6 
bool ekzistonRruge( graf *g, int shteg[], int n )
{
     for( int i = 0; i < n-1; i++ )
     {
          brinje *tmp = g->brinjet[ shteg[ i ] ];
          
          while( ( tmp != 0 ) &&  ( tmp->w != shteg[ i+1 ] ) )
                 tmp = tmp->pas;
          
          if( tmp == 0 ) return false;     
     }     
     
     return true;
}



int main ()
{
 graf *g = new graf;
 
 inicializoGraf( g, true );
 
 shtoBrinje( g, 0, 2, true );
 shtoBrinje( g, 0, 4, false );
 shtoBrinje( g, 0, 5, true );
 shtoBrinje( g, 1, 0, true );
 shtoBrinje( g, 2, 1, true );
 shtoBrinje( g, 2, 5, true );
 shtoBrinje( g, 3, 1, true );
 shtoBrinje( g, 3, 6, false );
 shtoBrinje( g, 4, 0, true );
 shtoBrinje( g, 4, 5, true );
 
 
 afishoGraf( g );
 
 bredhjeNeGjeresi( g, 1 );
 
  cout << "\n\nShtegu:";
  gjejShteg( 1, 4, prindi );
 
 
 ///cout << "\nKulmi me me shume fqinj> " << kulmiMeRendinHyresMax( g );
 
 
 ///cout << "\n\nGrafi pas ndryshimit te drejtimit: \n";
// ndryshoDrejtim( g );
 
 ///int shteg[] = { 1, 0, 5, 6, 7};
 ///cout << "\nShtegu i kerkuar " << ekzistonRruge( g, shteg, 5 );
    system( "pause" );
 return 0;    
}
