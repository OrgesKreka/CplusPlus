//// veprime me pemet
//// rruga nga rrenja tek gjethja. . . 
#include <iostream>

using namespace std;


const int MADHESIA = 10;

typedef struct stive
{
    int top;
    int vlera[ MADHESIA ];
};



typedef struct kulm
{       
    int vlera; /// celesi i kulmit.
    
    struct kulm *majte, *djathte, *p;
    /// majte - biri i majte.
    /// djathte - biri i djathte
    /// p - prindi i kulmit
} peme;



void inicializo( stive &s )
{
   s.top = -1;
   
   for( int i = 0; i < MADHESIA; i++ )
        s.vlera[ i ] = 0;     
} ///FUND inicializo


void push( stive &s, int vlera )
{
     if( s.top < MADHESIA - 1 )
     {
         s.top++;
         s.vlera[ s.top ] = vlera;    
     }  
     else
         cout << "Stack Overflow. . . ";   
}// FUND push


void pop( stive &s )
{
     s.top--; 
}


int top( stive s )
{
     return s.vlera[ s.top ];    
}/// fund top


bool eshteBosh( stive s )
{
     return s.top == -1;     
} ///FUND eshteBosh





/// shton kulm ne peme
void shtoKulm( peme *& rrenja, int vlera )
{
     
     
     peme *kulmiri = new peme;
     kulmiri->vlera = vlera;
     
     kulmiri->majte = kulmiri->djathte = 0;
     
     peme *y = 0;
     peme *x = rrenja;
     
     
     while( x != 0 )
     {
           y = x;
           
           if(  vlera < x->vlera )
               x = x->majte;
           else
               x = x->djathte;        
     } ///FUND while
     
     kulmiri->p = y;
     
     if( y == 0 )
         rrenja = kulmiri;
         
     else if( kulmiri->vlera < y->vlera )
          y->majte = kulmiri;
     else
         y->djathte = kulmiri;
} ///FUND shtoKulm


void afishoPeme( peme *rrenja, int h )
{
     if( rrenja != 0 )
     {
         afishoPeme( rrenja->djathte, h+1 );
         
         for( int i = 0; i< h; i++ )
              cout << "  ";
              
          cout << rrenja->vlera << endl;
          
          afishoPeme( rrenja->majte, h+1 );     
     }///FUND if
} ///FUND afishoPeme


void rrugaRrenjeGjethe( peme *gjethe )
{
        stive s;
      inicializo( s );
      
     peme *tmp = gjethe;
     
     while( tmp != 0 ) 
     {
            push( s, tmp->vlera );
            
            tmp = tmp->p;       
     }  ///FUND while
     
     
     while( !eshteBosh( s ) )
     {
        int t = top( s );
        
        pop( s );
        
        cout << t << " --> ";       
     } ///FUND while
     
} //FUND rrugaRrenjeGjethe


void gjejGjethe( peme *rrenja )
{
   if( rrenja == 0 ) return;
   
   else if( rrenja->majte == 0 && rrenja->djathte == 0 )
          {    
               rrugaRrenjeGjethe( rrenja );  
                     cout << endl;       
                          /**
             peme *tmp = rrenja;
             
             while( tmp != 0 )
             {
                cout << tmp->vlera << " : ";
                
                tmp = tmp->p;       
             } ///FUND while 
             
             cout << endl;
             */
             
          } ///FUND else if
   
    if( rrenja->majte != 0 )
   {    
      gjejGjethe( rrenja->majte );      
   }
   if( rrenja->djathte != 0 )
       gjejGjethe( rrenja->djathte );
} ///FUND gjejGjethe




peme *gjejKulm( peme *t, int vlera )
{
   if( t == 0 ) return 0;
   
   if( t->vlera == vlera ) return t;
   
   else 
        if( t->vlera < vlera )
            return gjejKulm( t->djathte, vlera );
        else
            return gjejKulm( t->majte, vlera );
        
}
///---------------- 3 funksionet per heqjen e nje kulmi te pemes. . .

peme *minimum( peme *t )
{
   if( t == 0 ) return 0;
   
   else if( t->majte == 0  && t->djathte == 0 ) return t;
   
   else 
        return minimum( t->majte );
        
}
 
void zevendeso( peme *& T, peme *u, peme *v )
{
    if( u->p == 0 )
        T = v;
     else
         if( u == u->p->majte )
             u->p->majte = v;
          else
              u->p->djathte = v;
     
     if( v != 0 )
           v->p = u->p;     
} ///FUND zevendeso

void fshiKulm( peme *& t, peme *kulm )
{
     peme *y;
     
     if( kulm->majte == 0 )
         zevendeso( t, kulm, kulm->djathte );
     else
         if( kulm->djathte == 0 )
             zevendeso( t, kulm, kulm->majte );
         
         else
         {
             y = minimum( kulm->djathte );
             
             if( y->p != kulm )
             {
                zevendeso( t, y, y->djathte );
                y->djathte = kulm->djathte;
                y->djathte->p = y;    
             } ///FUND if
             
             zevendeso( t, kulm, y );
             y->majte = kulm->majte;
             y->majte->p = kulm;   
         }    ///FUND if 
}



int numri_gjetheve_majtas( peme *rr )
{
    if( rr == 0 ) return 0;
    
    else if( rr->majte == 0 && rr->djathte == 0 && rr->p->majte == rr )
         return 1;
     else
         return numri_gjetheve_majtas( rr->majte ) + numri_gjetheve_majtas( rr->djathte );    
}


int njeGjethe( peme *t )
{
 if( t == 0 ) return 0;
 
 if( ( t->majte == 0 && t->djathte == 0 ) && ( t->p->majte == 0 || t->p->djathte == 0 ) )
     return 1;
  else
      return njeGjethe( t->majte ) + njeGjethe( t->djathte);    
}
int main ()
{
    peme *rrenja = 0;
    
    /**
    shtoKulm( rrenja, 24 );    
    shtoKulm( rrenja, 16 );
    shtoKulm( rrenja, 43 );
    shtoKulm( rrenja, 21 );
    shtoKulm( rrenja, 18 );
    shtoKulm( rrenja, 24 );
    shtoKulm( rrenja, 55 );
    shtoKulm( rrenja, 45 );
    shtoKulm( rrenja, 67 );
*/
    
    
    shtoKulm( rrenja, 9 );
    shtoKulm( rrenja, 4 );
    shtoKulm( rrenja, 15 );
    shtoKulm( rrenja, 2 );
    shtoKulm( rrenja, 6 );
    shtoKulm( rrenja, 12 );
    shtoKulm( rrenja, 17 );
    
    
    afishoPeme( rrenja, 0 );
    
    cout << endl << endl;
    
   // gjejGjethe( rrenja );
    
    cout << "\n\nHeqja e kulmit me vlere 55...\n\n";
         peme *tmp = gjejKulm( rrenja, 55 );
         
         cout << "\n\nKulmi me vlere 55> " << tmp << endl;
         
         peme *i = gjejKulm( rrenja, 24 );
         
         cout << "\n\nRruget rrenje -> gjethe: \n";
         gjejGjethe( rrenja );
         
         
         
         cout << "\n\n > " << njeGjethe( rrenja );
         /**
         fshiKulm( rrenja, tmp );
         fshiKulm( rrenja, i );
         fshiKulm( rrenja, i );
    cout << "\n\nP E M A E R E . . . " << endl << endl;
         afishoPeme( rrenja, 0 );
    */
    ///cout << " Pema ka " << shuma_gjetheve_majtas( rrenja ) << " gjethe djathtas.\n\n";
    system( "pause" );
    
    return 0;
}
