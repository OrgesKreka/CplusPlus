/// FUNKSIONET ME PEMET
#include <iostream>

using namespace std;

typedef struct kulm
{
    int vlera;
    
    kulm *majtas;
    kulm *djathtas;        
} peme;


void krijoPeme( peme *& rrenja, int vlera )
{
     peme *kulmiri = 0;
     
     if( rrenja == 0 )
     {
         kulmiri = new peme;
         
         kulmiri->vlera = vlera;
         
         kulmiri->majtas = kulmiri->djathtas = 0;
         
         rrenja = kulmiri;    
     } 
     
     if( vlera > rrenja->vlera )
         krijoPeme( rrenja->djathtas, vlera );
     
     else if( vlera < rrenja->vlera )
         krijoPeme( rrenja->majtas, vlera );
}


// afishonPemen
void afishoPeme( peme *rrenja, int h )
{
     int i;
     if( rrenja != 0 )
     {
         afishoPeme( rrenja->djathtas, h+1 );
         for( i = 0; i < h; i++ )
              cout << "  ";
         
         cout << rrenja->vlera << endl;
         
         afishoPeme( rrenja->majtas, h+1 );
             
     } ///FUND if
} ///FUND afishoPeme


///------------------------------------------------------
/// Llogarit lartesine e pemes...
/// @param rrenja, rrenja e pemes.
/// @return l, numri i gjatesise.
///-------------------------------------------------------
int lartesia( peme *rrenja )
{
    int lartesiaMajtas, lartesiaDjathtas;
     lartesiaMajtas = lartesiaDjathtas = 0;
    
    if( rrenja->majtas != 0 )
        lartesiaMajtas = 1 + lartesia( rrenja->majtas );    
    else if( rrenja->djathtas != 0 )
         lartesiaDjathtas =  lartesia( rrenja->djathtas ) + 1;
         
    if( lartesiaMajtas > lartesiaDjathtas )
             return lartesiaMajtas;
    else 
         return lartesiaDjathtas;
}

///-------------------------------------------------------------
/// Numeron numrin e gjetheve ne nje peme te kerkimit binar.
// @param rrenja, rrenja e pemes.
/// @return numri i gjetheve.
///--------------------------------------------------------------
int numriGjetheve( peme *rrenja )
{
    if( rrenja == 0 )   return 0;
    
    else if( rrenja->majtas == 0 && rrenja->djathtas == 0 ) return 1;
    
    else return numriGjetheve( rrenja->majtas ) + numriGjetheve( rrenja->djathtas );    
}

///--------------------------------------------------------------
/// Numeron kulmet ne nje peme te kerkimit binar.
/// @param rrenja, rrenja e pemes qe do procedohet.
/// @return numri i kulmeve.
///--------------------------------------------------------------
int numriKulmeve( peme *rrenja )
{
    if( rrenja == 0 )  return 0;
    
    else 
         return numriKulmeve( rrenja->majtas) + 1 + numriKulmeve( rrenja->djathtas);   
}

///--------------------------------------------------------------
/// Krijon versionin pasqyre te pemes.
/// @param rrenja e pemes.
///--------------------------------------------------------------
void pasqyre( peme *& rrenja )
{
     if( rrenja == 0 ) return;
     
     else
     {
          peme *tmp;
          
          pasqyre( rrenja->majtas );
          pasqyre( rrenja->djathtas );
          
          tmp = rrenja->majtas;
          
          rrenja->majtas = rrenja->djathtas;
          
          rrenja->djathtas = tmp;    
     }     
}

///------------------------------------------------------------------
/// Numeron nyjet jo gjethe te nje peme.
/// @param rrenja
// @return numri i kulmeve jo gjethe.
///------------------------------------------------------------------
int kulmeJoGjethe( peme *rrenja )
{
    if( rrenja == 0 ) return 0;
    
    if( rrenja->majtas == 0 && rrenja->djathtas == 0 ) return 0;
    
    else 
         return  1 + kulmeJoGjethe( rrenja->majtas ) + kulmeJoGjethe( rrenja->djathtas);
        
}


///-------------------------------------------------------------
/// numri i kulmeve qe kane vetem nje gjethe.
///@return numri
///-------------------------------------------------------------
int njeGjethe( peme *t )
{
    if( t == 0 ) return 0;
    
    if( ( t->majtas->majtas == 0 && t->djathtas == 0 ) || ( t->majtas == 0 && t->djathtas->djathtas == 0 ) )
        return 1;
    
    else
        return njeGjethe( t->majtas ) + njeGjethe( t->djathtas );    
}

int main ()
{
 peme *rrenja = 0;
/** 
     krijoPeme( rrenja, 9 );
     krijoPeme( rrenja, 4 );
     krijoPeme( rrenja, 15 );
     krijoPeme( rrenja, 2 );
     krijoPeme( rrenja, 6 );
     krijoPeme( rrenja, 12 );
     krijoPeme( rrenja, 17 );
     //krijoPeme( rrenja, 3 );
 */
 
 int pergjigja;

do
{
  cout << "Jep vlere( -1 per te dale)> ";
  cin >> pergjigja;

  if( pergjigja != -1 )
      krijoPeme( rrenja, pergjigja );

}while( pergjigja != -1 );
 
 afishoPeme( rrenja, 0 );
 
 
 cout << "\n\n Lartesia e pemes eshte > " <<  lartesia( rrenja );
 cout << "\n\n Pema me siper ka " << numriGjetheve( rrenja ) << " gjethe.";
 cout << "\n\nPema me siper ka " << numriKulmeve( rrenja ) << " kulme ";
 cout << "\n\nPema me siper ka " << kulmeJoGjethe( rrenja ) << " kulme jo gjethe";
 
 pasqyre( rrenja );
 cout << "\n\nVersioni pasqyre i pemes se mesiperme> \n";
 afishoPeme( rrenja, 0 );
 
 cout << endl << endl;
 cout << "Pema mesiper ka " << njeGjethe( rrenja ) << " kulme me nje gjethe.";
 
 cout << endl << endl;
 system( "pause" );
 
 return 0;
     
}
