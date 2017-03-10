/// GRAFI ME LISTA TE LIDHURA. . . 
#include <iostream>

using namespace std;

/*** Percaktimi i struktures se Grafit ***********/
int const MAXK = 10; /// maksimumi i brinjeve te grafit

typedef struct brinje
{
        int w; /// variabli qe ruan kulmin fundor te brinjes. . . 
        int pesha; /// pesha e brinjes nese ka.
        brinje *pas; /// shenjuesi tek brinja pasardhese.        
};

typedef struct graf
{
        brinje *brinjet[ MAXK ]; /// tabela me listat e fqinjesive.
        
        int nKulmesh; /// numri i kulmeve te grafit.
        
        int nBrinje; /// numri i brinjeve te grafit.
        
        bool orientuar; /// nese grafi eshte i orientuar apo jo.        
};


void inicializoGraf( graf *& g, bool eshteIOrientuar )
{
     g->nKulmesh = 0;
     
     g->nBrinje = 0;
     
     
     g->orientuar = eshteIOrientuar;
     
     
     
     for( int i = 0; i < MAXK; i++ )
          g->brinjet[ i ] = NULL;

} /// FUND inicializoGraf

void shtoBrinje( graf *& g, int v, int w, bool eshteIOrientuar )
{
     brinje *b = new brinje;
     
     
     b->pesha = 0;
     b->w = w;
     
     /// shtimi ne fillim te listes
     b->pas = g->brinjet[ v ];
     g->brinjet[ v ] = b;
     
     g->orientuar = eshteIOrientuar;
     
     g->nBrinje++;     
}


void afishoGraf( graf *g )
{
     for( int i = 0; i < MAXK; i++ )
     {
          brinje *tmp = g->brinjet[ i ];
          
          cout << i << " : ";
          while( tmp != 0 )
          {
                 cout << tmp->w << " --> ";
                 
                 tmp = tmp->pas;       
          }     
          
          cout << " NULL " << endl;
     }     
     
}

