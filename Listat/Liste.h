#ifndef LISTE_H
#define LISTE_H  


#include <iostream>
#include "Nyje.h" 

using namespace std;


template< typename Tipi >
class Liste
{
   public:
          Liste (); /// Konstruktori
          ~Liste(); /// Destruktori
          
          void shtoNeFillim( const Tipi& );
          void shtoNeFund( const Tipi& );
          bool hiqNgaFillimi( Tipi& );
          bool hiqNgaFundi( Tipi& );
          bool eshteBoshe() const;
          void afisho() const;
          
   private:
           Nyje< Tipi > *koka;
           Nyje< Tipi > *bishti;
           
           Nyje< Tipi > *krijoNyje( const Tipi& );        
}; /// FUND prototipi i klases

///====================Implementimi i Klases Liste=============

/// Kontruktori
template< typename Tipi >
Liste< Tipi >::Liste () : koka( 0 ), bishti( 0 )
{
           
} ///FUND konstruktori


/// Destruktori
template< typename Tipi >
Liste< Tipi >::~Liste()
{
    if( !eshteBoshe () )
    {
        cout << "Duke fshire nyjet...\n";
        
        Nyje< Tipi > *eliri = koka;
        Nyje< Tipi > *tmp;
        
        while( eliri != 0 )
        {
              tmp = eliri;
              cout << tmp->vlera << '\n';
              eliri = eliri->pas;
              
              delete tmp;      
        } ///FUND while
    } ///FUND if
    
    
    cout << "Lista u shkaterrua...\n\n";
}  ///FUND destruktori


/// shtimi i nyjes ne fillim te listes
template< typename Tipi >
void Liste< Tipi >:: shtoNeFillim( const Tipi &vlera )
{
     Nyje< Tipi > *eliri = krijoNyje( vlera );
     
     if( eshteBoshe () )
     {
         koka = bishti = eliri;    
     } ///FUND if
     else
     {
         eliri->pas = koka;
         koka = eliri;    
     }    ///FUND else 
} //FUND shtoNeFillim


// shto nyje ne fund te listes
template< typename Tipi >
void Liste< Tipi >::shtoNeFund( const Tipi &vlera )
{
     Nyje< Tipi > *eliri = krijoNyje( vlera );
     
     if( eshteBoshe () )     
         koka = bishti = eliri;
     else
     {
         bishti->pas = eliri;
         bishti= eliri;    
     } //FUND else
} ///FUND shtoNeFund


/// fshin nje nyje ne fillim te listes
template< typename Tipi >
bool Liste< Tipi >::hiqNgaFillimi( Tipi &vlera )
{
     if( eshteBoshe () )
         return false;
     else
     {
         Nyje< Tipi > *tmp = koka;
         
         if( koka == bishti )
             koka = bishti = 0;
         else
             koka = koka->pas;
             
             
             vlera = tmp->vlera;
             delete tmp;
             return true; 
     }      ///FUND else
} ///FUND hiqNgaFillimi


/// heq nje nyje nga fundi i listes
template< typename Tipi >
bool Liste< Tipi >:: hiqNgaFundi( Tipi &vlera )
{
     if( eshteBoshe() )
         return false;
     
     else
     {
         Nyje< Tipi > *tmp = koka;
         
         if( koka == bishti )
             koka = bishti = 0;
             
         else
         {
             Nyje< Tipi > *eliri = koka;
             
             while( eliri->pas != bishti )
                    eliri = eliri->pas;
             
             tmp = eliri->pas;   
             bishti = eliri;
             eliri->pas = 0;    
         }    ///FUND else
         
         vlera = tmp->vlera;
         delete tmp;
         return true;
     }      ///FUND else
} //FUND hiqNgaFundi

template< typename Tipi >
bool Liste< Tipi >::eshteBoshe () const
{
     return koka == 0;     
} ///FUND eshteBosh


/// krijon nje objekt te tipit nyje
template< typename Tipi >
Nyje< Tipi > *Liste< Tipi >::krijoNyje(const Tipi &vlera )
{
      return new Nyje< Tipi >( vlera );     
} ///FUND krijoNyje


/// afishon listen
template< typename Tipi >
void Liste< Tipi >::afisho() const
{
     if( eshteBoshe () )     
     {
         cout << "Lista eshte boshe...\n\n";
         return;    
     } ///FUND if
     
     Nyje< Tipi > *tmp = koka;
     
     cout << "\nElementet e listes:\n";
     
     while( tmp != NULL )
     {
            cout << tmp->vlera <<" --> ";
            
            tmp = tmp->pas;       
     } ///FUND while
     
     cout << " NULL\n\n";
} ///FUND afisho


#endif ///FUND deklarimi klases
