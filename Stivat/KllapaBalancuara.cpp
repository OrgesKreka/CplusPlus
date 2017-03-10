/// Kllapa te balancuara. kontrollon nese nje string qe permban kllapa eshte i balancuar apo jo

#include <iostream>
#include <string>

using namespace std;

const int MADHESIA = 20;

typedef struct 
{
   int  top;
   char vektor[ MADHESIA ];          
} stive;


/// krijon nje stive boshe
stive krijoStiveBosh ()
{
      stive s;
      s.top = -1;
      
      return s;      
}


/// shton nje element ne stive.
void Push( stive &s, char vl )
{
    s.top++;
    s.vektor[ s.top ] = vl;     
}

///heq nje element nga stiva.

void Pop( stive&s )
{
 s.top--;     
}


/// kontrollon nese kllapat jane te balancuara
bool kllapaTeBalancuara( string kllapa )
{    
     char  c1 = ')';
     char  c2 = '(';
     
     stive tmp = krijoStiveBosh ();
     
     if(  kllapa.at( 0 ) == c1 ) return false;
     if( kllapa.length () == 1  || kllapa.length () == 0 ) return false;
     
     for( int i = 0; i < kllapa.length (); i++ )
     {
          if( kllapa.at( i ) == c2 )
              Push( tmp, kllapa[ i ] ); 
          else
              Pop( tmp );    
     }     
     
     return tmp.top == -1;
}


int main ()
{
 
 string kllapa = "(((((()))))()";
 
 if( kllapaTeBalancuara( kllapa ) ) cout << "Kllapat jane te balancuara..\n";
 
 else
     cout << "\nKllapat nuk jane te balancuara...\n";


cout << endl << endl << endl;
system( "pause" );
return 0;     
}
