///*******************************************************
/// Program: Orari i Grupit
/// @autor:
///*******************************************************

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

 const int DITET = 5;
 const int ORA = 13;

string java[DITET] = {"Hene", "Marte", "Merkure", "Enjte", "Premte"};
int koha[ORA] = {8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};


 string M[DITET][ORA] = {
  {"Bosh","Bosh", "Bosh", "Java-seminar/ salla 314C", "Java-seminar / salla 314C", "Sisteme Multimediale- Leksion /salla D6", "Sisteme Multimediale- Leksion /salla D6"},
  {"Probabilitet-Leksion/ salla 301B","Probabilitet-Leksion/ salla 301B","C++ -Leksion/ salla 301B", "C++ -Leksion/ salla 401B"},
  {"Sisteme Multimediale-Seminar/ salla 301A","Sisteme Multimediale-Seminar/ salla 301A","Arkitekture Kompjuteri-Leksion/ salla D2","Sisteme Multimediale-Seminar/ salla 301A", "Arkitekture Kompjuteri-Leksion/ salla D2"},
  {"Bosh", "Anglisht-seminar/ salla 302A", "Anglisht-seminar/ salla 302A", "Arkitekture Kompjuteri-Seminar/ Salla 401C "},
  {"C++ -Seminar/Salla 314C", "C++ -Seminar/Salla 314C", "Java-Leksion/ salla D4", "Java-Leksion/ salla D4"}
};

/*
for(int i=0; i<DITET; i++)
{
for(int j=0; j<ORA; j++)

  if(M[i][j].compare("") == 0)
                         M[i][j] = "Bosh";
  
}

*/
///---------------------------------------------------------
/// Funksioni qe do marre te dhena nga perdoruesi dhe do te 
/// kerkoje ne orarin ekzistues ne baze te ores / lendes.
///---------------------------------------------------------

void kerkoNeOrar()
{
   int dita;
   do
   {
     cout << "\tCfare dite keni mesim ? ";
     cout << "\n\t1-Henen \n\t2-Marten\n\t3-Merkuren\n\t4-Enjten\n\t5-Premten\n";
     cout << "\nJep numrin e dites: ";
     cin >> dita;    
   }     
    while(dita < 1 || dita > 5);
    
    dita = dita - 1;
    
    int ora; int min;
    
    cout << "\n\n\tCfare ore deshironi te kontrolloni ? \n";
    cout << "Jep oren ne formatin hh:mm-  ";
    
    cin >> ora;
    
    if(ora <8 || ora>=20) 
    {
           cout << "Nuk ka mesim ne kete orar!\n";
            return;
    }
     
     cin.ignore();
    
    cin >> min;
    if(min < 0 || min > 59)
    {
       cout << "\nCa planeti jeton ?! \n";
            return;       
    }
    
    
  for(int i =0; i< ORA; i++)
  {
     if(koha[i] == ora)
     { 
       if(M[dita][i].compare("") !=0)
       cout << "\nNe kete ore ju keni " << M[dita][i];
       
       if(M[dita][ i + 1].compare("") !=0)
                   cout << "\nOres tjeter do te keni " << M[dita][i+1] <<endl;
       else
                   cout << "\nOres tjeter nuk keni mesim.\n";            
  
       
       cout << "\n\n****************Mire u pafshim!***********";
            return;            
                
     }        
  }  
    
     
}
///------------------------------------------------------------
/// Funksioni qe afishon Orarin.
///------------------------------------------------------------
void afishoOrarin()
{
     
for(int i=0; i<DITET; i++)
{
for(int j=0; j<ORA; j++)

  if(M[i][j].compare("") == 0)
                         M[i][j] = "Bosh";
  
}
     
     cout << right;
cout << "     " << "Hene"<< setw(15)<< "Marte"<<setw(15);
   cout  << "Merkure"  << setw(15) << "Enjte" << setw(15) <<"Premte" << endl;
   cout << endl << "___________________________________________________________________________";
   cout << endl;
     
for(int i=0; i<ORA; i++)
{  
        cout << koha[i] << " :   " ;
   for(int j=0; j<DITET; j++)
   { cout << right;
   cout <<setw(5)<<M[j][i];      
    }
    cout << endl << endl;
}        
}

///---------------------------------------------------------------
///Funksioni qe do ktheje pozicionin e dites nese eshte e vlefshme
///---------------------------------------------------------------
int pDites(string d)
{
    int p;
    
if(d.compare("Hene") == 0 || d.compare("hene") == 0 ){p = 0; return p;} 
if(d.compare("Marte") == 0 || d.compare("marte") == 0 ){p = 1; return p;}  
if(d.compare("Merkure") == 0 || d.compare("merkure") == 0 ){p = 2; return p;}   
if(d.compare("Enjte") == 0 || d.compare("enjte") == 0 ){p = 3; return p;}  
if(d.compare("Premte") == 0 || d.compare("premte") == 0 ){p = 4; return p;}   
else{ p = -1; return p; }
      
}
////-----------------------------------------------------------
/// Funksioni qe kthen pozicionin e ores, dhe kontrollon nese eshte e vlefshme
///------------------------------------------------------------------

int pOres(int o)
{
    if(o<8 || o>=20)
           return -1;
    else
    {
      for(int i=0;i<ORA; i++)
              if(koha[i] == o)
                         return i;    
    }
    
}


///------------------------------------------------------------
///Funksini qe do shtoje te dhenat e perdoruesit ne orar.
///-----------------------------------------------------------
void shtoOrarin()
{
for(int i=0; i<DITET; i++)
{
for(int j=0; j<ORA; j++)

M[i][j] = ""; 
} 

string dita, permbajtja; int pozicioni, nSallave, ora; 

int max = DITET * ORA;
cout << "\n\tJep numrin e sallave: ";
cin >>nSallave;

if(nSallave <0 || nSallave > max)
{
  cout << "\nNuk i perballojme dot kaq salla!\n";
  return;            
}  
     
for(int i=0; i<nSallave; i++)
{
cout << "\nJep diten(hene - premte): ";
cin >> dita;        
   if(pDites(dita) !=-1)
   {
              cout << "\nJep oren: ";
              cin >> ora; 
                  if(pOres(ora) != -1)
                                {
                                  cout << "\n\nJep lenden:";
                                  cin >> permbajtja;
                                  M[pDites(dita)][pOres(ora)] = permbajtja;      
                                }
                                else{cout << "Ore e pavlefshme!"; return;}        
   } 
   else
   {cout << "\nMeso te shkruash ditet."; return;}    
    
}
    char a;
    cout << "\nTa afishoj orarin p/j : ";
    cin >> a;
    
    switch(a)
    {
      case 'p': afishoOrarin();  break;
      case 'j': exit(0);
       default: cout << "\n\t\tBye - Bye"; exit(0);         
    }
    
     
}





int main()
{
    

string afishimi[ORA] = {};

    
int pergjigja;

do
{
cout << "Shtyp 1 per te kerkuar ne orar.";
cout << "\nShtyp 2 per te shtuar orarin.";
cout << "\nShtyp 3 per te dale....";
cout << "\nShtyp 4 per te afishuar orarin.";
cout << "\nPergjigja:  ";    
    
cin >> pergjigja;   
}    
while(pergjigja < 1 || pergjigja > 4);   

    
  switch(pergjigja)
   {
      case 1: kerkoNeOrar(); 
           break;                
      case 2: shtoOrarin();              
           break;
      case 3: cout << "\n\t\t********MIRE U PAFSHIM************";
           exit(0);
      case 4: afishoOrarin();
           break;
   }  
  
  /// afishoOrarin();
    
   system("pause");
 return 0;   
}


/*
8:10 - 9
9:10 - 10
10:10 - 11
11:10 - 12
12:10 - 13
13:10 - 14
14:10 - 15
15:10 - 16
16:10 - 17
17:10 - 18
18:10 - 19
19:10 - 20

*/
