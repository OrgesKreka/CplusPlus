/// Krijimi i nje peme binare

#include <iostream>

using namespace std;

typedef struct kulm
{
        int vlera;
        
        kulm *djathtas;
        kulm *majtas;        
} peme;


/// krijon nje peme binare.
void shtoElement( peme *& rrenja, int vlera )
{
     peme *tmp  = 0;
     
     if( rrenja == 0 )
     {
         tmp = new peme;
         
         tmp->majtas = tmp->djathtas = 0;
         
         tmp->vlera = vlera;
         
         rrenja = tmp;
         
         return ;    
     } 
     
     
     if( vlera < rrenja->vlera )
     {
         shtoElement( rrenja->majtas, vlera );    
     }
     
     else if( vlera > rrenja->vlera )
     {
          shtoElement( rrenja->djathtas, vlera );     
     }    
} ///FUND shtoElement


void afishoPeme( peme *rrenja, int h  )
{
          int i;
          
          if( rrenja != 0 )
          {
              afishoPeme( rrenja->majtas, h+1 );
              
              for( i = 0; i < h; i++ ) cout << "  ";
              cout << rrenja->vlera << endl;
               
              afishoPeme( rrenja->djathtas, h+1 );    
          }
}


int main ()
{
 
peme *kulm = NULL;

int pergjigja;

do
{
  cout << "Jep vlere( -1 per te dale)> ";
  cin >> pergjigja;

  if( pergjigja != -1 )
      shtoElement( kulm, pergjigja );

}while( pergjigja != -1 );
     
     afishoPeme( kulm,0 );
     
     
     
     cout << endl << endl;
     
     system( "pause" );
     
     return 0;
}
