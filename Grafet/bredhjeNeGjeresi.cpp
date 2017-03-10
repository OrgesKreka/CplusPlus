//// bredhje ne gjeresi e grafit
#include <iostream>
#include "struktura Grafit.cpp"

using namespace std;


bool procesuar[ MAXK ];
bool vizituar[ MAXK ];
int prindi[ MAXK ];

struct rradhe
{
     int vl;
     
     rradhe *pas;       
};


void shtoNeRradhe( rradhe *& r, int vl )
{
     rradhe *element;
     
     rradhe *tmp;
     
     element = new rradhe;
     
     element->vl = vl;
     
     element->pas = 0;
     
     if( r == 0 )
         r = element;
         
     else
     {
         tmp = r;
         
         while( tmp->pas != 0 )
                tmp = tmp->pas;
         
         tmp->pas = element;    
     }
}


void inicializoBredhje( graf *g )
{
    for( int i = 0; i < g->nKulmesh; i++ )
    {
         procesuar[ i ] = vizituar[ i ] =false;
         
         prindi[ i ] = -1;     
    }     
}



void bredhjeNeGjeresi( graf *g, int kulmFillimi )
{
   rradhe *q = 0;
   
   int v;
   
   int y;
   
   brinje *p;
   
   shtoNeRradhe( q, kulmFillimi );
   vizituar[ kulmFillimi ] = true;
    
    cout << "\n\nBredhja ne thellesi nga kulmi " << kulmFillimi << endl;
    cout << kulmFillimi << " : " ;
    
   while( q != 0 )
   {
          rradhe *fillim = q;
          
          v = fillim->vl;
          
          p = g->brinjet[ v ];
          
          
          while( p != 0 )
          {
               y = p->w;
               
               if( vizituar[ y ] == false )
               {
                   shtoNeRradhe( q, y );
                   vizituar[ y ] = true;
                   
                   prindi[ y ] = v;    
                   
                   cout << y << " : ";
               }       
               
               p = p->pas;
          }       
          
          procesuar[ v ] = true;
          fillim = fillim->pas;
          q = fillim;
   }     
}
