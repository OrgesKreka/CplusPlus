/// Implementimi i stives me vektor.......

#include <iostream>

using namespace std;

const int MADHESIA = 3;

typedef struct 
{
      int top;
      int vektor[ MADHESIA ];        
} stive;

/// krijon nje stive boshe
stive krijoStiveBoshe ()
{
      stive s;
      s.top = -1;
      
      return s;      
}

/// kontrollon nese stiva eshte bosh apo jo
bool eshteBoshe( stive s )
{
     return s.top == -1;     
}


/// shton nje element ne stive....
void Push( stive &s, int x )
{
     if( s.top < MADHESIA )
     {
         s.top++;
         s.vektor[ s.top ] = x;
         
         cout << "Elementi u shtua ne stive...\n\n";    
     }   
     else
     {
         cout << "Stive e mbushur....\n\n";  
     }  
}

/// heq nje element nga stiva...
void Pop( stive &s )
{
    if( s.top == -1 )
    {
        cout << "Stive Boshe....\n\n";  
    }    
    else
    {
        cout << "Elementi: " << s.vektor[ s.top ] << " u hoq...\n\n";
             s.top--;    
    }
}


int main ()
{
 stive s = krijoStiveBoshe ();
 
 stive tmp;
 
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
             stive tmp = s;
             
             while( tmp.top != -1 )
                    Pop( tmp ); 
                    
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
