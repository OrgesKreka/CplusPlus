///     Implementimi i rradhes me lista te lidhura....
#include <iostream>

using namespace std;

/// struktura e nyjes 
typedef struct nyje
{
        int vlera;
        
        nyje *pas;        
} rradhe;

/// shenjuesat e rradhes
typedef struct
{
   rradhe *kreu;
   rradhe *fundi;        
} shRradhe;


/// krijimi i nje rradhe bosh...
void krijoRradheBosh( shRradhe &r )
{
     r.kreu = 0;
     r.fundi = 0;     
}


//// kontrollimi nese eshte rradhe boshe apo jo
bool rradheBoshe( shRradhe r )
{
     return r.kreu == 0 && r.fundi == 0;     
}

/// shton nje element ne rradhe. enquee
void shtoNeRradhe( shRradhe &r, int x )
{
     rradhe *eliri = new nyje;
     
     eliri->vlera = x;
     eliri->pas = 0;
     
     if( rradheBoshe( r ) ) /// shtimi ne fillim te rradhes
     {
         r.kreu = eliri;
         r.fundi = eliri;    
     }
     else /// shtimi ne fund te rradhes
     {
         r.fundi->pas = eliri;
         r.fundi = eliri;
     }
     
     cout << "Elementi " << x << " u shtua ne rradhe...\n\n";
}


/// heq nje element nga rradha. dequee
void hiqNgaRradha( shRradhe &r, int &x )
{
     rradhe *tmp;
     
     if( !rradheBoshe( r ))
     {
         x = r.kreu->vlera;
         
         tmp = r.kreu;
         
         if( r.kreu == r.fundi ) /// rradha ka nje element
             { r.kreu = 0; r.fundi = 0; } 
         else
             r.kreu = r.kreu->pas;
         
         
         cout << "Elementi " << tmp->vlera << " u hoq nga rradha.\n\n";
         delete( tmp );    
     }     
     else
         cout << "Rradhe boshe...\n\n";
}


/// afishon elementet e nje rradhe
void afisho( shRradhe r )
{
     if( rradheBoshe( r ) )
                  cout << "\nRradhe boshe....\n";
     else
     {
         while( r.kreu != 0 )
         {
                cout << r.kreu->vlera << " -- ";
                r.kreu = r.kreu->pas; 
         }  
         cout << endl << endl; 
     }
            
}

int main ()
{
    shRradhe r;
    
    krijoRradheBosh( r );
    
    
    int pergjigja;
    int element;
    bool perserit = true;
    
    do
    {
        cout << "1. per te shtuar ne rradhe.\n";
        cout << "2.per te hequr nga rradha.\n";
        cout << "3.per te afishuar rradhen.\n";
        cout << "4. per te dale.\n";
        
        cout << "\nPergjigja> ";
        cin >> pergjigja;
        
        switch( pergjigja )
        {
                case 1:
                       cout << "\nElementi qe do shtoni> ";
                       cin  >> element;
                       shtoNeRradhe( r, element );
                               break;
               case 2:
                      hiqNgaRradha( r, element );
                                    break;
               case 3:
                    shRradhe tmp = r;
                     
                     afisho( tmp );
                     break;
              case 4:
                     cout << "~~~~~~~~~~~~~Mire u pafshim~~~~~~~~~~~";
                     
                     perserit = false;
                      break;
              default:
                      cout << "Zgjedhje e gabuar....\nProvo perseri..\n\n";
                       break;       
        }   //// FUND switch
    } while( perserit ); /// fund do - while
    
    
    cout << endl << endl << endl;
    
    system( "pause" );
    return 0;
   
}
