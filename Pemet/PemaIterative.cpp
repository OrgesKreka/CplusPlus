//// Krijimi i pemes ne menyre iterative.
#include <iostream>
using namespace std;

typedef struct kulm
{
        int vlera;
        
        kulm *majtas;
        kulm *djathtas;      
        kulm *paraardhes;  
}peme;


/// shton elemente ne peme ne menyre iterative
void shtoKulmNePeme( peme *& rrenja, peme *kulmiri )
{
     peme *y = 0; /// elementi paraardhes i kulmit te ri
     
     peme *tmp = rrenja; /// tmp
     
     while( tmp != 0 )
     {
            y = tmp;
            
            if( kulmiri->vlera < tmp->vlera )
                tmp = tmp->majtas;
            
            else 
                 tmp = tmp->djathtas;       
     } ///FUND while
     
     kulmiri->paraardhes = y; /// e lidhim kulmin e ri me paraardhesin
     
     if( y == 0 )
         rrenja = kulmiri; /// rrenja ka qene null, pema ka rrenje elementin e ri
     
     else
         if( kulmiri->vlera < y->vlera )
             y->majtas = kulmiri;
         else
             y->djathtas = kulmiri;
}


void krijoPemeIterative( peme *& rrenja, int vlera  )
{
     peme *kulmiri = new peme;
     kulmiri->vlera = vlera;
     kulmiri->majtas = kulmiri->djathtas = 0;
     
     peme *tmp = rrenja;
     peme *y = 0;
     
     while( tmp != 0 )
     {
            y = tmp;
            
            if( vlera < tmp->vlera )
                tmp = tmp->majtas;
            else
                tmp = tmp->djathtas;       
     }  
     
     kulmiri->paraardhes = y;
     
     if( y == 0 )
     {
         rrenja = kulmiri;    
     }
     else
         if( vlera < y->vlera )
             y->majtas = kulmiri;
         else
              y->djathtas = kulmiri;
     
        
}

/// shton elemente ne peme ne menyre rekursive
void shtoElementRekursivisht( peme *& rrenja, int vlera )
{
     peme *kulmiri = 0;
     
     if( rrenja == 0 )
     {
         kulmiri = new peme;
         kulmiri->vlera = vlera;
         
         kulmiri->majtas = kulmiri->djathtas = 0;
         
         rrenja = kulmiri;    
     } 
     
     else if( vlera > rrenja->vlera )
          shtoElementRekursivisht( rrenja->djathtas, vlera );
      else
          shtoElementRekursivisht( rrenja->majtas, vlera );    
}


/// afishon pemen
void afishoPeme( peme *rrenja, int h )
{   
    int i;
     if( rrenja != 0 )
     {
         ///afishoPeme( rrenja->majtas, h+1 );
         afishoPeme( rrenja->djathtas, h+1 );
         for( i = 0; i < h; i++ ) cout << "  ";
         cout << rrenja->vlera << endl;
         
         afishoPeme( rrenja->majtas, h+1 );
         ///afishoPeme( rrenja->djathtas, h+1 );    
     }     
}



/// kerkon nese nje kulm gjendet ne peme apo jo
peme *kerko( peme *rrenja, int celes )
{
     peme *tmp = rrenja;
     
     while( tmp != 0 && celes != tmp->vlera )
            if( celes > tmp->vlera )
                     tmp = tmp->djathtas;
            else
                tmp = tmp->majtas;
                
    return tmp;
}


int numriKulmeve( peme *p )
{
    int n = 0;
 if( p!= 0 )
 {
      n++;
       numriKulmeve( p->majtas ); 
       numriKulmeve( p->djathtas );
 }    
 return n;
}



int njeGjethe( peme *t )
{
 if( t == 0 )
     return 0;
 if(  t->majtas == 0 && t->djathtas == 0 ) 
   {cout << t->paraardhes->vlera << " : ";   return 1; }
 else
     return njeGjethe( t->majtas ) + njeGjethe( t->djathtas );
 }

int main ()
{
    peme *rrenja = NULL;
    
    peme *kulmiri;
    
    int pergjigja;
    
    
    /**
    do
    {
      cout << "Jep element( -1 per te dale) > ";
      
      cin >> pergjigja;
      
      if( pergjigja != -1 )
      {  
          
          kulmiri = new peme;
          kulmiri->vlera = pergjigja;
          kulmiri->majtas = kulmiri->djathtas = 0;
          
         /// krijoPemeIterative( rrenja, pergjigja );
          ///shtoKulmNePeme( rrenja, kulmiri );
            shtoElementRekursivisht( rrenja, pergjigja );  
      }    
    }    while( pergjigja != -1 );
    */
    
    shtoElementRekursivisht( rrenja, 9 );
    shtoElementRekursivisht( rrenja, 4 );
    shtoElementRekursivisht( rrenja, 15 );
    shtoElementRekursivisht( rrenja, 2 );
    shtoElementRekursivisht( rrenja, 6 );
    shtoElementRekursivisht( rrenja, 12 );
    shtoElementRekursivisht( rrenja, 17 );
    
    afishoPeme( rrenja, 0 );
    
    
    int el;
    cout << "\n\nElementi> ";
    cin >> el;
    
    peme *gjendet = kerko( rrenja, el );
    
    if( !gjendet  )
        cout << "\n\nElementi nuk gjendet ne peme. . . \n";
    else cout << " Elementi gjendet ne peme. . . " << gjendet;
    
    
    int n = numriKulmeve( rrenja );
        cout << "\nPema ka " << n << " kulme ";
    
    
    cout << endl << endl << ">  ";
    cout << njeGjethe( rrenja );
    cout << endl << endl;
    system( "pause" );
    
    return 0;
}
