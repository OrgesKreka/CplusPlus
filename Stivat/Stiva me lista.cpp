//// Implemetnimi i stives me lista te lidhura....
#include <iostream>

using namespace std;

typedef struct nyje
{
        int vlera;
        nyje *pas;        
} stive;

/// krijon nje stive bosh.
stive* krijoStiveBosh ()
{
 return 0;       
}


/// kontrollon nese stiva eshte boshe
bool eshteBoshe( stive *s )
{
     return s == 0;     
}

/// shton nje element ne stive.
void Push( stive *&s, int x )
{
     stive *eliri = new stive;
     
     eliri->vlera = x;
     eliri->pas = s;
     s = eliri;
     
     cout << "Elementi " << x << " u shtua ne stive..." << endl << endl;
}


/// heq nje element nga stiva...
void Pop( stive *&s )
{
     if( s == 0 )
         cout << "Stive boshe...\n\n";
     else
     {
         stive *tmp = s;
         s = s->pas;
         
         cout << "Elementi " << tmp->vlera << " u hoq.\n\n";
         delete( tmp );    
     }     
}

/// afishon elementet e stives.
void afisho( stive *s )
{
     if( s == 0 )
         cout << "Stive boshe..\n\n";
     else
     {
         while( s != 0 )
         {
                cout << s->vlera << " --> ";
                s = s->pas;       
         }    
     }     
}



// funskioni main
int main ()
{
 stive *s = krijoStiveBosh ();
 
 int element;
 
 int pergjigja;
 
 bool perserit = true;
 
 do
 {
   cout << "1. per te shtuar ne stive.\n";
   cout << "2. per te hequr nga stiva.\n";
   cout << "3. per te afishuar stiven.\n";
   cout << "4. per te dale.\n";
   
   cout << "\nPergjigja> ";
   cin >> pergjigja;
   
   switch( pergjigja )
   {
      case 1:
             cout << "Elementi qe do shtoni> ";
             cin >> element;
             Push( s, element );
               break;
      case 2:
             Pop( s );
                  break;
      case 3: 
                 afisho( s );      
                break;
        case 4:
               cout << "Mire u pafshim...." << endl;
               cout << "                                      ";
               perserit = false;     
               break;  
        
        default:
                cout << "Pergjigje e pavlefshme!\nProvo Perseri...";
   }   ///FUND switch
     
 } while( perserit );
 
  
 cout << endl << endl << endl << endl;
 
 system( "pause" );
 return 0; 
   
}



