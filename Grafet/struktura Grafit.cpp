#include <iostream>

using namespace std;

const int MAXK = 10;

/// struktura e brinjes. . . 
struct brinje
{
     int w;
     
     int pesha;
     
     brinje *pas;       
};


/// struktura e grafit
struct graf
{

     brinje *brinjet[ MAXK ];
     
     int nKulmesh;
     
     int nBrinje;
     
     bool orientuar;       
};


bool procesuar[ MAXK ];
bool vizituar[ MAXK ];
int prindi[ MAXK ];

struct rradhe
{
     int vl;
     
     rradhe *pas;       
};



void inicializoGraf( graf *& g, bool eshteIOrientuar )
{
    g->nKulmesh = 0;
    
    g->nBrinje = 0;
    
    g->orientuar = eshteIOrientuar;
    
    for( int i = 0; i < MAXK; i++ )
         g->brinjet[ i ] = 0;     
} 



void shtoBrinje( graf *& g, int v, int w, bool eshteIOrientuar )
{
     brinje *b = new brinje;
     
     b->pesha = 0;
     
     b->w = w;
     
     b->pas = g->brinjet[ v ];
     g->brinjet[ v ] = b;
     
     if( eshteIOrientuar == false )
         shtoBrinje( g, w, v, true );
         
     else
         g->nBrinje++;     
}



void afishoGraf( graf * g )
{
     for( int i = 0; i < MAXK; i++ )
     {
          cout << "\nBrinjet e kulmit " << i << " : ";
          
          
          for( brinje *tmp = g->brinjet[ i ]; tmp != 0; tmp = tmp->pas ) 
               cout << tmp->w << " --> ";
           
           cout << " NULL " << endl;    
     }     
}



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



/// gjetja e shtegut 
void gjejShteg( int kFillim, int kFund, int prindi[] )
{
     if( ( kFillim == kFund )  ||  ( kFund == -1 ) )
          cout << endl << kFillim << " : ";
      
      else
      {
          gjejShteg( kFillim, prindi[ kFund ], prindi );
                     cout << kFund << " : ";    
      }     
}
