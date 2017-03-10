#include <iostream>

using namespace std;

class Nyje
{
      public:
             
             char vlera;
             Nyje *pas;
             
              Nyje( const char vlera )
             {
                    this->vlera = vlera;
                    this->pas = 0;
             } //FUND konstruktori
             
             Nyje *krijoNyje( const char vlera )
             {
                  return new Nyje( vlera );     
             } //FUND krijoNyje         
}; ///FUND Nyje


class Liste : public Nyje
{
      private :
              Nyje *koka;
              Nyje *bishti;
      public:
             Liste() : Nyje( 0 )
             {
                    koka = 0;
                    bishti = 0;       
             }   ///FUND konstruktori
             
             
             bool eshteBoshe ()
             {
                  return koka == 0;     
             } ///FUND eshteBoshe
             
             void shtoNeFillim( const char vlera )
             {
                  Nyje *eliri = krijoNyje( vlera );
                  
                  if( this->koka == 0 )
                      koka = bishti = eliri;
                   
                  else
                  {
                      eliri->pas = koka;
                      koka = eliri;    
                  }     ///FUND else
             } ///FUND shtoNeFillim
             
             
             void shtoNeFund( const char vlera )
             {
                  Nyje *eliri = krijoNyje( vlera );
                  
                  if( koka == 0 )
                      koka = bishti = eliri;
                   else
                   {
                       eliri->pas = 0;
                       bishti->pas = eliri;
                       bishti = eliri;    
                   }     
             } ///FUND shtoNeFund
             
             bool hiqNgaFillimi( char& vlera )
             {
                  if( this->eshteBoshe () )
                      return false;
                   else
                   {
                       Nyje *tmp = koka;
                       
                       if( koka == bishti ) 
                           koka = bishti = 0;
                        
                        else   
                               koka = koka->pas;
                               
                        vlera = tmp->vlera;
                        
                        delete tmp;
                        return true;
                   }  ///FUND else    
             } ///FUND hiqNgaFillimi
             
             
             
             bool hiqNgaFundi( char& vlera )
             {     
                   
                   Nyje *tmp = koka;
                   
                   if( this->eshteBoshe () )
                       return false;
                   
                   else
                   {
                       Nyje *eliri = koka;
                       
                       while( eliri->pas != bishti )
                              eliri = eliri->pas;
                       
                       tmp = eliri->pas;   
                       bishti = eliri;
                       eliri->pas = 0;       
                   }/// FUND else
                   
                   vlera = tmp->vlera;
                   delete tmp;
                   return true;  
             } ///FUND hiqNgaFundi
             
             
             void afishoListe ()
             {
                  if( this->koka == 0 ){ cout << "Liste boshe ...";}
                  
                  else
                  {
                      Nyje *tmp = koka; 
                      
                      while( tmp != 0 )
                      {
                             cout << tmp->vlera << " -->  ";
                             
                             tmp = tmp->pas;       
                      }     ///FUND while
                      
                      cout << " NULL \n\n";
                  } ///FUND else
             } ///FUND afishoListe
};///FUND Liste

int main()
{
    Liste obj;
    
    int perzgjedhja;
    
    char vlera;
    
    do
    {  
         
         cout << "1. per te shtuar ne fillim.\n";
         cout << "2. per te shtuar ne fund.\n";
         cout << "3. per te hequr ne fillim.\n";
         cout << "4. per te hequr ne fund.\n";
         cout << "5. per te dale..\n";
         cout << "Zgjedhja Juaj> ";
         
         cin >> perzgjedhja;
         
         switch( perzgjedhja )
         {
                 case 1:
                        cout << "\nJep vleren qe do te shtosh ne fillim> ";
                        cin >> vlera;
                        obj.shtoNeFillim( vlera );
                        
                        cout << "\n---------Lista e re----------\n";
                        obj.afishoListe ();
                                        break;
                 case 2:
                      cout << "\nJep vleren qe do te shtosh ne fund te listes> ";
                      cin >> vlera;
                      obj.shtoNeFund( vlera ); 
       
                      cout << "\n---------Lista e re----------\n";
                      obj.afishoListe ();
                                        break;  
                 case 3:
                        if( obj.hiqNgaFillimi( vlera ) )
                        {
                            cout << "\nKoka e listes u hoq...\n";
                            
                            cout << "\n\n----------Lista e re---------\n";
                            obj.afishoListe ();
                        }
                        else
                            cout << "\nE R R O R -Dicka shkoi keq...\n\n";
                                 break;
                 case 4:
                        if( obj.hiqNgaFundi( vlera ) )
                        {
                             cout << "\nBishti i listes u hoq....\n";
                             
                             cout << "\n\n-------Lista re ------------\n";
                             obj.afishoListe ();    
                             
                        }  
                        else
                        {
                            cout << "E R R O R - Dicka shkoi gabim..." << endl;    
                        }  
                                 break;
               case 5:
                      cout << "\t\tMire u pafshim....";
                           break;
               default:
                       cout << "\nVlere e palejuar!\nProvo perseri>\n";
         }     ///FUND switch
         
    } while( perzgjedhja != 5 );
    
    
    system( "pause" );
    return 0;
}
