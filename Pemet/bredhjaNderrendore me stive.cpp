/// Bredhja nderrendore e pemes ne menyre iterative duke perdorur stiven
#include <iostream>

using namespace std;

/// struktura e pemes
typedef struct kulm
{
        int vlera;
        
        kulm *majtas;
        kulm *djathtas;
}peme;


const int MADHESIA = 20;

typedef struct 
{
   int top;
   
   peme  *kulm[ MADHESIA ];        
} stive;


void inicializo( stive &s )
{
   s.top = -1;
   for( int i = 0; i < MADHESIA; i++ )
        s.kulm[ i ] = 0;
        
}


void push( stive &s, peme *pointer )
{   
    
    if( s.top < MADHESIA )
    {
        s.top++;
    
        s.kulm[ s.top ] = pointer;
    }
    else
        cout << " StackOverflow. . . ";
   
}

void pop( stive &s )
{
   s.top--;     
}

peme *top( stive &s )
{
    if( s.top >= 0 )
        return s.kulm[ s.top ];
    else
        return 0;     
}


bool eshteBosh( stive s )
{
     return s.top == -1;
}



void bredhjeNderrendore( peme *rrenja )
{
   if( rrenja == 0 )
   {
      cout << "Pema nuk ekziston . . . "; return;    
   } 
   
   peme *tmp = rrenja;
   stive s;
   inicializo( s );
   
   bool mbaroi = false;
   
   while( !mbaroi )
   {
       if( tmp != 0 )
       {
          push( s, tmp );
          tmp = tmp->majtas;    
       }   
       else
       {  
            if( !eshteBosh ( s ) )
            { 
              tmp = top( s );
              pop( s );

              cout << tmp->vlera << "  ";
              
              tmp = tmp->djathtas;
             }/// FUND if
             else
                 mbaroi = true;    
       } ///FUND else  
   }  /// FUND while
}///FUND funksioni. . . 

void shtoKulm( peme *& rrenja, int vlera )
{    
    peme *kulmiri = 0;
    
    if( rrenja == NULL )
    {
       kulmiri = new peme;
       kulmiri->vlera = vlera;
       kulmiri->majtas = kulmiri->djathtas = 0;
       
       rrenja = kulmiri;  
       
    } 
    
    else if( rrenja->vlera > vlera )     
        shtoKulm( rrenja->majtas, vlera  );
    else
        shtoKulm( rrenja->djathtas, vlera );
} 


void afishoPeme( peme *rrenja, int h  )
{  
     int i;
   if( rrenja != NULL )
   {
        afishoPeme( rrenja->djathtas, h+1 );
        
        for( i = 0; i < h; i++ )
             cout << "  ";
        
        cout << rrenja->vlera << endl;
        
        afishoPeme( rrenja->majtas, h+1 );     
   }  ///FUND if
}

int main ()
{
    peme *rrenja = NULL;
    
    shtoKulm( rrenja, 9 );
    shtoKulm( rrenja, 4 );
    shtoKulm( rrenja, 15 );
    shtoKulm( rrenja, 2 );
    shtoKulm( rrenja , 8 );
    shtoKulm( rrenja, 12 );
    shtoKulm( rrenja, 17 );
      
    afishoPeme( rrenja , 0);
    
    
    cout << "\nBredhja nderrendore e pemes : \n\n";
    bredhjeNderrendore( rrenja );
    
    cout << endl << endl << endl;
    system( "pause" );
    
    return 0;
         
}
