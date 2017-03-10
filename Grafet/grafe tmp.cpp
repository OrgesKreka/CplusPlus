#include <iostream>

using namespace std;

const int MAXK = 10;

typedef struct brinje
{
    int w;
    int pesha;
    brinje *pas;        
};

typedef struct graf
{
   brinje *brinjet[ MAXK ];
   
   int nKulmesh;
   int nBrinjesh;
   bool orientuar;             
};


void inicializoGraf( graf *&g, bool eshteIOrientuar )
{
     for( int i = 0 ; i < MAXK; i++ )
          g->brinjet[ i ] = NULL;     
     
     g->nKulmesh = 0;
     g->nBrinjesh = 0;
     g->orientuar = eshteIOrientuar;
}

void shtoBrinje( graf *&g, int v, int w, bool eshteIOrientuar )
{
   brinje *tmp = new brinje;
   tmp->w = w;
   tmp->pesha = 0;
   
   tmp->pas = g->brinjet[ v ];
   g->brinjet[ v ] = tmp;   
   
   
   if( eshteIOrientuar == false )
       shtoBrinje( g, w, v, true );
    
    g->nBrinjesh++;  
}

void afisho( graf *g )
{
     for( int i = 0; i < MAXK; i++ )
     {
          brinje *tmp = g->brinjet[ i ];
          
          
          cout << i << " : ";
          
          while( tmp != NULL )
          {
                 cout<< tmp->w << " --> ";       
                 
                 tmp = tmp->pas;
          }     
          cout << " NULL \n";
          
     }      
}

 
void maxkulmeDales( graf *g )
{
     int kulmeDales[ MAXK ] = { 0 };
     
     for( int i = 0 ; i < MAXK; i++ )
     {
          brinje *tmp = g->brinjet[ i ];
          
          while( tmp != 0 )
          {
                 kulmeDales[ i ]++;
                 
                 tmp = tmp->pas;       
          }     
     }   
     
     int max = kulmeDales[ 0 ]; int p = -1;
     
     for( int i = 0; i < MAXK; i++ )
     {
          cout << kulmeDales[ i ] << "  ";
          if( kulmeDales[ i ] > max )
          {
              max = kulmeDales[ i ];
              p = i;    
          } 
     }
          
     cout << "\nMaksimumi  = " << p;
}


void maxkulmeHyres( graf *g )
{
     int kulmeHyres[ MAXK] = { 0 };
     
     for( int i = 0; i < MAXK; i++ )
     {
          brinje *tmp = g->brinjet[ i ];
          
          while( tmp != NULL )
          {
             kulmeHyres[ tmp->w ]++;
             
             tmp = tmp->pas;       
          }     
     }
     
     
     
     int max = kulmeHyres[ 0 ]; int p = -1;
     
     for( int i = 0; i < MAXK; i++ )
     {
          cout << kulmeHyres[ i ] << "  ";
          if( kulmeHyres[ i ] > max )
          {
              max = kulmeHyres[ i ];
              p = i;    
          } 
     }
          
     cout << "\nMaksimumi  = " << p;     
}


void rruge( int kFillim, int kFund, int prindi[] )
{
     if( kFillim == kFund || kFund == -1 )
         cout << kFillim << " - ";
     else
     {
         rruge( kFillim, prindi[ kFund ], prindi )
                cout << kFund << " - ";    
     }
             
}


int main ()
{
    graf *g = new graf;
    inicializoGraf( g, true );
    
    shtoBrinje( g, 1, 2, true );  
    shtoBrinje( g, 1, 4, true );
    shtoBrinje( g, 2, 2, true );
    shtoBrinje( g, 3, 2, true );
    shtoBrinje( g, 4, 2, true ); 
    
    afisho( g );
    
    ///maxkulmeDales( g );
    maxkulmeHyres( g );
    system( "pause" );
    return 0; 
}


void gjej_shteg( int kFillim, int kFund, int prindi[] )
{
     if( kFillim == kFund || kFund == -1 )
         cout << kFillim << " - ";
     else
     {
         gjej_shteg( kFillim, prindi[ kFund ], prindi );
                     cout << kFund << " - ";    
     }     
}




void mergeSort(  int A[], int fillim, int fund )
{
     int mes;
     
     if( fillim < fund )
     {
         mes = ( fillim + fund ) / 2;
         
         mergeSort( A, fillim, mes );
         mergeSort( A, mes+1, fund );
         
         
         merge( A, fillim, mes, fund );    
     }     
}

void merge( int A[], int fillim, int mes, int fund )
{
     int B[ fund + 1 ];
     for( int i = filliml i < fund; i++ )
          B[ i ] = A[ i ];
     
     int k = fillim;
     int l = mes+1;
     int m = 0;
     
     while( k <= mes && l <= fund )
     {
            if( B[ k ] <= B[ l ] )
            {
                A[ m ] = B[ k ];
                k++;    
            }   
            else
            {
                A[ m ] = B[ l ];
                l++;    
            }    
            m++;
     }     
     
     
     while( k <= mes )
     {
            A[ m ] = B[ k ];
            m++;
            k++;       
     }
     
     
     while( l <= fund )
     {
            A[ m ] = B[ l ];
            m++;
            l++;       
     }
}


void quickSort( int A[], int fillim, int fund )
{
     int p;
     
     if( fillim < fund )
     {
         p = particiono( A, fillim, fund );
         
         quickSort( A, fillim+1, p );
         quickSort( A, p+1, fund );    
     }     
}

int particioni( int A[], int fillim, int fund )
{
    int p = fillim;
    int pozpivot = fund;
    
   for( int i = fillim; i <= fund; i++ )
   {
        if( A[ i ] < A[ p ] )
        {
            swap( A[ i ], A[ pozpivot ] );
            pozpivot++;        
        }     
   }    
   
   swap( A[ p ], A[ pozpivot ]);
   return pozpivot;
    
}


int kerkimBinar( int A[], int fillim, int fund, int k  )
{
    if( fillim > fund ) return -1;
    
    int mes = ( fillim + fund ) / 2;
    
    if( A[ mes ] == k ) return mes;
    
    else
    {
        if( A[ mes ] < k )
            kerkimBinar( A, mes+1, fund, k );
        else
            kerkimBinar( A, fillim, mes-1, k );    
    }    
}

