/// Anasjellta e nje liste pa krijuar liste te re....
#include <iostream>

using namespace std; 

/// deklarimi i struktures
typedef struct nyje
{
       int vlera;
       nyje *pas;       
} liste;


liste *krijoListe ()
{
      liste *eliri;
      liste *koka;
      liste *tmp;
      
      for( int i = 1; i <= 10; i++ )
      {
           if( i == 1 )
           {
               koka = new liste;
               koka->vlera = i;
               koka->pas = 0;
               
               eliri = new liste;
               eliri->pas = 0;
               
               tmp = koka;
                     
           } 
           else
           { 
               eliri = new liste;
           
               eliri->vlera = i;
               eliri->pas = 0;
           
               tmp->pas = eliri;
           
               tmp = eliri;
           }
      } ///FUND for
            
            
            return koka;
}



/// afishon listen
void afishoListen( liste *l )
{
     if( l == 0 ) cout << "Liste boshe...\n\n";
     
     else
     {
         liste *tmp = l;
         
         while( tmp != 0 )
         {
                cout << tmp->vlera << " --> ";
                
                tmp = tmp->pas;        
         }   ///FUND while 
         
         cout << " NULL ";
     }    ///FUND else  
} ///FUND afishoListen



void anasjelltaListes( liste *& l )
{
     liste *paraardhes = 0;
     liste *aktual = l;
     liste *pasardhes = 0;
     
     while( aktual != 0 )
     {
            pasardhes = aktual->pas;
            aktual->pas = paraardhes;
            paraardhes = aktual;
            aktual = pasardhes;       
     }
          
       l = paraardhes; 
}



int main ()
{
    
    liste *koka = 0;
    
    koka = krijoListe ();
    
    cout << " Lista> \n\n"; 
    afishoListen( koka );
    
    cout << endl << endl;
    cout << "Lista e anasjellte> \n\n";
    anasjelltaListes( koka );
    
    afishoListen( koka );
    
        cout << endl << endl << endl;
        
        system( "pause" );
        return 0;
}
