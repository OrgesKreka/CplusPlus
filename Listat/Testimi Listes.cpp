#include <iostream>
#include <string>
#include "Liste.h"

using namespace std;

void afishoMenu ()
{
     cout << "Zgjidh nje nga veprimet:\n"
          << "1 per te shtuar ne fillim te listes\n"
          << "2 per te shtuar ne fund te listes\n"
          <<"3 per te hequr ne fillim te listes\n"
          <<"4 per te hequr ne fund te listes\n"
          <<"5 per te perfunduar.\n";     
} //FUND afishoMenu


/// funksioni qe teston fuksionet e krijuara te listes
template< typename Tipi >
void perdorFunksionet( Liste< Tipi > &liste, const string &tipiTeDhenes )
{
     cout << "Testimi i nje liste me te dhena " << tipiTeDhenes << endl;
    
    afishoMenu(); 
       
       int zgjedhja;
       Tipi vlera;
       
       do
       {
               cout << " ? ";
               cin >> zgjedhja;
               
               switch( zgjedhja )
               {
                       case 1: ///shtimi ne fillim
                              cout << "Jep nje vlere " << tipiTeDhenes << " : ";
                              cin >> vlera;
                              
                              liste.shtoNeFillim( vlera );
                              liste.afisho ();
                                           break;
                       case 2: ///shtimi ne fund
                               cout << "Jep nje vlere " << tipiTeDhenes << " : ";
                               cin >> vlera;
                               
                               liste.shtoNeFund( vlera );
                               liste.afisho ();
                                            break;
                       case 3: ///hiq vleren e pare
                               if( liste.hiqNgaFillimi ( vlera ) )
                                   cout << "Koka e listes u hoq...\n";
                               
                               liste.afisho ();
                               break;
                       case 4: ///hiq vleren e fundit
                               if( liste.hiqNgaFundi( vlera ) )
                                   cout << "Bishti i listes u hoq...\n";
                                   
                                   liste.afisho ();
                                   break;
                       default:
                               if( zgjedhja <0 || zgjedhja > 5 )
                                   cout << "\nVlere e palejuar....\n\n";
                                else
                                    cout << "\n-----Mire u Pafshim-----\n\n";    
                                    break;
               } ///FUND switch
       } while( zgjedhja < 5 );
} ///FUND perdorFunksionet


int main ()
{
    Liste< int > listeEPlote;
    perdorFunksionet( listeEPlote, "integer");
    
    /// testimi i nje liste me vlera me presje
    Liste< double > listeMePresje;
    perdorFunksionet( listeMePresje, "double");
    
    system( "pause" );
    return 0;    
} ///FUND main
