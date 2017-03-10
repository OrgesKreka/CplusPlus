///Veprimet me dy thyesa
#include<iostream>
using namespace std;

///funksini qe ben afishimin e rezultatit
void afisho(int a1,int a2, int b1, int b2, int c1, int c2, char v)
{cout<<endl<<endl;
cout<<a1<<" "<<" / "<<" "<<a2<<" "<<v<<" "<<b1<<" / "<<b2<<" = "<<" "<<c1<<" / "<<c2;
}


///funksioni menu
void menu(int& a1, int& a2, int& b1,int& b2, char& c)
{
  cout<<"Ky program kryen veprime me thyesat sic jane.\n";
  cout<<"Shfaqja e rezultatit do te jete perseri thyese.\n";
  cout<<"Nuk lejohen emeruesat = 0  ose veprime te ndryshme nga +,-,/,*.\n";   
     
do
{
 cout<<"\n\nJep thyesen e pare numeruesi/emeruesi:";
 cin>>a1;
 cin>>a2;
 cout<<"\nJep thyesen e dyte numeruesi/emeruesi:"; 
 cin>>b1;
 cin>>b2;   
} while(b2==0 || a2== 0);


cout<<"\n\nJep veprimin(+,-,/,*):";
cin>>c;
     
}

/// funksioni qe llogarit mbledhjen e thyesave
void mbledhja(int a1, int a2, int b1, int b2, int& c1, int& c2)
{
 if(a2%b2 == 0)
 {
     c2 = a2;
     c1 =  a1+a2/b2*b1;    
 }  
else if(b2%a2 == 0)
{
c2 = b2;
c1 = b1 + b2/a2*a1;
} 
else
{
    c2 = a2*b2;
    c1 = c2/a2*a1 + c2/b2*b1;
}   
}

///funksioni qe llogarit zbritjen e thyesave
void zbritja(int a1, int a2, int b1, int b2, int& c1, int& c2)
{
 if(a2%b2 == 0)
 {
     c2 = a2;
     c1 =  a1 - a2/b2*b1;    
 }  
else if(b2%a2 == 0)
{
c2 = b2;
c1 = b1 - b2/a2*a1;
} 
else
{
    c2 = a2*b2;
    c1 = c2/a2*a1 - c2/b2*b1;
}   
   
}

///funksioni qe llogarit shumezimin e thyesave
void shumezo(int a1,int a2, int b1,int b2, int& c1, int& c2)
{
   c1 = a1*b1;
   c2 = a2*b2;  
}


///funksioni qe llogarit pjesetimin e thyesave
void pjeseto(int a1,int a2, int b1, int b2, int& c1, int& c2)
{
     c1 = a1*b2;
     c2 = a2*b1;
     
}



///funksioni main
int main()
{
    
int num1;
int em1;

int num2;
int em2;

char veprimi;   


int num3,em3;

 menu(num1,em1,num2,em2,veprimi);

switch(veprimi)
{
    case '+': mbledhja(num1,em1,num2,em2,num3,em3);  break;
    case '-': zbritja(num1,em1,num2,em2,num3,em3);  break; 
    case '*': shumezo(num1,em1,num2,em2,num3,em3);  break; 
    case '/': pjeseto(num1,em1,num2,em2,num3,em3);  break; 
    default:
            cout<<"Ju lutem jepni nje veprim matematikor te vlefshem!/nProvoni perseri!";
            break;                 
} 

afisho(num1,em1,num2,em2,num3,em3,veprimi);
 
 
 cout<<endl<<endl;
 
 system("pause");  
 return 0; 
}
