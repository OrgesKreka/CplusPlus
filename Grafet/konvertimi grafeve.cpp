#include <iostream>
#include "Grafi me lista te lidhura.cpp"

using namespace std;

bool G[ MAXK ][ MAXK ];

void inicializo( bool G[][ MAXK ], int MAXK )
{
     for( int i = 0; i < MAXK; i++ )
          for( int j = 0; j < MAXK; j++ )   
               G[ i ][ j ] = false;     
}


/// konverton grafin me lista te lidhura
/// ne graf me matrice fqinjesie.
void konverto( graf *g )
{
     bool G1[ MAXK ][ MAXK ];
     inicializo( G1, MAXK );
     
     for( int i = 0; i < MAXK; i++ )
          {
              brinje *tmp = g->brinjet[ i ];
              
              while( tmp != 0 )
              {
                     G1[ i ][ tmp->w ] = true;
                     
                     tmp = tmp->pas;       
              }   ///FUND while  
          } ///FUND for
          
          
     for( int i = 0; i < MAXK; i++ )
          for( int j = 0; j < MAXK; j++ )
               G[ i ][ j ] = G1[ i ][ j ];
} ///FUND konverto


/// konverton grafin me matrice fqinjesie
/// ne graf me lista te lidhura. . . 
graf *konverto2 ()
{
     graf *g = new graf;
     inicializoGraf( g, false );
     
     for( int i = 0; i < MAXK; i++ )
          for( int j = 0; j < MAXK; j++ )
               if( G[ i ][ j ] )
               {
                   brinje *tmp = new brinje;
                   tmp->w = j;
                   tmp->pesha = 0;
                   
                   tmp->pas = g->brinjet[ i ];
                   g->brinjet[ i ] = tmp;    
               } ///FUND if
               
     return g;
}


void shtoBrinje( int i, int j )
{
     G[ i ][ j ] = true;     
}

void afisho ()
{
     for( int i = 0; i < MAXK; i++ )
     {
          for( int j = 0; j < MAXK; j++ )
               cout << G[ i ][ j ] << "  ";
           
           cout << endl;
      }         
}


/// funksioni qe merr si parameter grafin
/// dhe kthen numrin e brinjeve.
int numriBrinjeve( const graf *g  )
{
    int n = 0;
    
    for( int i = 0; i < MAXK; i++ )
    {
         brinje *tmp = g->brinjet[ i ];
         
         while( tmp != 0 )
         {
                n++;
                tmp = tmp->pas;       
         }    ///FUND while  
    }///FUND for
    
    return n;    
} ///FUND numriBrinjeve.


/// gjen rendin hyres te nje kulmi. . . 
/// 
int rendiHyres( graf *g, int kulm )
{
    int n = 0;
    
    for( int i = 0; i < MAXK; i++ )
    {
        brinje *tmp = g->brinjet[ i ];
        
        while( tmp != 0 )
        {
               if( tmp->w == kulm )
                   { n++; break; }  
               
               tmp = tmp->pas;     
        } ///FUND while
    }     ///FUND for
    
    return n;
    
}


/// heq nje brinje nga grafi me lista
//
bool hiqBrinje( graf *& g, int i , int j )
{
   brinje *tmp = g->brinjet[ i ];
   
   
   if( i < MAXK &&  i >= 0 )
   {
       
       bool ugjet = false;
       
       while( tmp->pas != 0 && !ugjet  )
       {      
              ugjet = tmp->pas->w  == j;
                    tmp = tmp->pas;
       }
       
          
        if( tmp->w == j && !ugjet ) /// nese kulmi qe do te hiqet eshte i pari ne liste.
        {
            g->brinjet[ i ] = tmp->pas;
            delete ( tmp );   
                   return true;
        }    
       else if( ugjet ) /// nese kulmi i dyte gjendet
       {
           brinje *fshi = tmp;
           tmp->pas = fshi->pas;
           
           delete ( fshi );    
           
           return true;
       }   /// FUND if
       else /// kulmi i dyte nuk gjendet. . .
       {
           cout << "\nKulmi " << j << " nuk gjendet ne graf. \n\n";
                return false;
       }
   }///FUND if
   else /// kulmi i pare nuk gjendet ne graf
   {
       cout << "\nKulmi " << i << " nuk gjendet ne graf . . . " << endl;
       return false;
   }
}



int main ()
{
    graf *g;
    
    //inicializoGraf( g, false );
    
   
   /** 
    *  shtoBrinje( g, 2, 4, false );
    *  shtoBrinje( g, 2, 7, false );
    *   shtoBrinje( g, 3, 8, false );
    *  shtoBrinje( g, 4, 1, false );
    **/
    

    shtoBrinje( 2, 4 );
    shtoBrinje( 2, 7 );
    shtoBrinje( 3, 8 );
    shtoBrinje( 4, 1 );
    shtoBrinje( 1, 1 );
    shtoBrinje( 0, 0 );
    shtoBrinje( 0, 1 );
    shtoBrinje( 0, 2 );
    shtoBrinje( 0, 3 );
    shtoBrinje( 0, 4 );
    shtoBrinje( 0, 5 );
    
    /**
    cout << "\nGrafi me matrice fqinjesie. . . " << endl << endl;
         afisho ();
       */  
         
    cout << "\nGrafi me lista te lidhura. . . \n\n";
         g = konverto2 ();
         afishoGraf( g );
   
   /** 
    cout << "\nGrafi i ri ka " << numriBrinjeve( g ) << " brinje. . .";
    
    cout << "\nKulmi 0 ka " << rendiHyres( g, 0 ) << " kulme hyrese. \n";
    */
    
    cout << "\nGrafi pas heqjes se brinjes 0 , 2 \n\n";
         if ( hiqBrinje( g, 0 , 2 ) )
            afishoGraf( g );
    
    cout << "\nGrafi me matrice . . .\n";
         konverto( g );
         afisho ();
    
    
    system( "pause" );
return 0;    
}
