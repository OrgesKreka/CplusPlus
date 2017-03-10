///************************************************************
/// Autor:Orges Kreka
/// Programi:Guri, Letra dhe Gershera
/// Programi luan lojen guri, letra dhe gershera
///************************************************************
#include<iostream>
using namespace std;
enum objectType{ 
  GURI,
  LETRA,
  GERSHERA};
  
 void afishoRregullat(){
 cout<<"Miresevini ne lojen Guri, Letra dhe Gershera."<<endl;
 cout<<"Kjo loje eshte per dy lojtare.Per cdo loje"<<endl;
 cout<<"cdo lojtar zgjedh nje nga objektet Gur, Leter ose Gershere"<<endl;
 cout<<"Rregullat per te fituar lojen jane:"<<endl;
 cout<<"1.Nese te dy lojtaret zgjedhin te njejtin objekt eshte barazim."<<endl;
 cout<<"2.Guri thyen gersheret keshtu qe lojtari qe ka gersheren fiton."<<endl;
 cout<<"3.Letra e mbulon gurin keshtu qe lojtari qe zgjedh letren fiton."<<endl;
 cout<<"4.Gersheret e presin letren keshtu qe lojtari qe ka gersheren fiton."<<endl;
cout<<"Shtypni G ose g per te zgjedhur gurin, L ose l per letren dhe S ose s per gersheren." <<endl;    
      
      }

bool zgjedhjeVlefshme(char zgjedhja){
     switch(zgjedhja){
       case 'G':
       case 'g':
       case 'L':
       case 'l':
       case 'S':
       case 's':
       return true;
       default: 
                return false;                                        
                      }
     }       
 
 
objectType retrievePlay(char zgjedhja){
 objectType objekt;
 switch(zgjedhja){
     case 'G':
     case 'g':                  
       objekt=GURI;
       break;
     case 'L':
     case 'l':
          objekt=LETRA;
       break;
     case 'S':
     case 's':
          objekt=GERSHERA;
        break;                        
         }          
       return objekt;       
           }      


  void convertEnum( objectType object){
    switch(object){
   case GURI:
        cout<<"GURI";
        break;
   case LETRA:
        cout<<"LETRA";
        break;
   case GERSHERA:
     cout<<"GERSHERA";
     break;                                           
                   }   
       
       }           
 

 objectType winningObject(objectType play1, objectType play2){
 if((play1==GURI && play2 == GERSHERA) || (play2 == GURI && play1==GERSHERA))
 return GURI;
 else if((play1==GURI && play2==LETRA)||(play2==GURI && play1 == LETRA))
 return LETRA;
 else return GERSHERA;           
            } 
            
            
 void gameResult(objectType play1, objectType play2, int& winner){
   objectType winnerObject;
   
   if(play1==play2){
     winner = 0;
     cout<<"Te dy lojtaret zgjodhen ";
     convertEnum(play1);
     cout<<"barazim"<<endl;               
                    }   
      
    else{
     winnerObject = winningObject(play1, play2);
     
     cout<<"Lojatri 1 zgjodhi ";
     convertEnum(play1);
     cout<<" Lojtari 2 zgjodhi ";
     convertEnum(play2);
     
  if(play1==winnerObject)
  winner=1;
  else if(play2==winnerObject)       
    winner=2;
             
 cout<<"Lojtari "<<winner<<"Fiton."<<endl; 
         }  
      }          
  

 
 

void displayResults(int gCount, int wCount1, int wCount2){
  cout<<"Numri total i lojave:"<<gCount<<endl;
  cout<<"Lojet e fituara nga lojtari 1"<<wCount1<<endl;
  cout<<"Lojet e fituara nga lojtari 2"<<wCount2<<endl;
     
     }                
int main(){
   int numriLojave;
   int fitoreE1;
   int fitoreE2;
   int fituesi;
   
   char pergjigja;
   
   char zgjedhja1;
   char zgjedhja2;
   
   objectType luaj1;
   objectType luaj2;
   
   numriLojave=0;
   fitoreE1=0;
   fitoreE2=0;
   
   afishoRregullat();
   
   cout<<"Shtyp Y/y per te luajtur lojen: ";
   cin>>pergjigja;
   cout<<endl;
   
   while(pergjigja=='Y'|| pergjigja=='y'){
   cout<<"Lojtari 1 bej zgjedhjen: ";
   cin>>zgjedhja1;
   cout<<endl;
   cout<<"Lojtari 2 bej zgjedhjen: ";
   cin>>zgjedhja2;                       
   cout<<endl;
   
     
   if(zgjedhjeVlefshme(zgjedhja1) && zgjedhjeVlefshme(zgjedhja2)){
   luaj1 = retrievePlay(zgjedhja1);                                                            
   luaj2 = retrievePlay(zgjedhja2);
   
   numriLojave++;
   gameResult(luaj1, luaj2, fituesi);
   if(fituesi == 1)
   fitoreE1++;
   else if(fituesi == 2)fitoreE2++;
}
  cout<<"Jep Y/y per te luajtur lojen: ";
  cin>>pergjigja;
  cout<<endl;
}

    displayResults(numriLojave, fitoreE1, fitoreE2); 
  
   system("pause");
   return 0;
  
   
    }
