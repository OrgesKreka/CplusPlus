#include <iostream>

using namespace std;



int main ()
{   
    int n = 5;
    
    int vektor[ n ];
    
    int vlera;
    
    int i = 0;
    
    do
    {
        cout <<  "Shto nje vlere ne vektor ( -9 ) per te dale: ";
        
        cin >> vlera;
        
        if( i == n  ) 
        {
           int tmp[ n ];
           
           for( int i = 0; i < n; i++ )
                tmp[ i ] = vektor[ i ];
           
             vektor[ 2*n ];
             
             int p = 0;
             
             while( p!= n )
             {
                    vektor[ p ] = tmp[ p ];
                    
                    p++;       
             }
           
            n = 2*n;  
            
            delete tmp;
        }
        
        vektor[ i ] = vlera;
         
         i++;
    } while( vlera != -9 );
    
    
     int l = 0;
     
     while( vektor [ l ] != -9 )
     {
         cout << vektor[ l ] << " - ";          
         
         l++;
     }
    system( "pause" );
    
    return 0;
}
