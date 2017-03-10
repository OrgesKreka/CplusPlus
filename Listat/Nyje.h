#ifndef NYJE_H
#define NYJE_H

#include <iostream>

using namespace std;


template< typename Tipi > class Liste;

template< typename Tipi >
class Nyje
{
      friend class Liste< Tipi >;

public:
       Nyje( const Tipi& ); ///Kontruktori 
       Tipi merrVlere () const; /// kthen vleren e nyjes
       
private:
        Tipi vlera;
        Nyje< Tipi > *pas; /// pointeri i nyjes pasardhese 
}; ///FUND prototipi klases


//===================Implementimi i Klases Nyje===============

/// kontruktori
template< typename Tipi >
Nyje< Tipi >::Nyje( const Tipi &v)
{
      this->vlera = v;
      this->pas = 0;      
} ///FUND konstruktori


/// kthen vleren e nyjes
template< typename Tipi >
Tipi Nyje< Tipi >::merrVlere() const
{
     vlera;     
} ///FUND merrVlere

#endif ///FUND Nyje.h
