/* TP, 2017/2018, Tutorijal 4, Zadatak 3 */
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cin;
using std::cout;

void IzdvojiKrajnjeRijeci (vector<string> v,string &s2, string &s1) {
   if (v.size()==0) {
      s1.resize(0);
      s2.resize(0);
      return;
   }
   
   vector<string> pom(v);
     
   for (int i=0; i<v.size();i++) {
      for(int j=0; j<v[i].length();j++) {
         if(v[i][j]>='A' && v[i][j]<='Z')
            v[i][j]+=('a'-'A');
      }
   }
      
   string s1p,s2p;
   s1=pom[0];
   s2=pom[0];
   s1p=v[0];
   
   for(int i=0;i<v.size();i++) {
      if(s1p<v[i]) {
         s1=pom[i];
         s1p=v[i];
      }
      if(s2>v[i]) {
         s2=pom[i];
         s2p=v[i];
      }
   }
}

vector<string> ZadrziDuplikate (vector<string> &v) {
   vector<string> ostatak;
   for(int i=0;i<v.size();i++) {
     bool ImaVec(false), ubaci(false);
     for(int j=i+1;j<v.size();j++) {
        if (v[i]==v[j]) {
           ubaci=true;
           for(int k=0; k<ostatak.size(); k++) {
              if(v[i]==ostatak[k]) {
                 ImaVec=true;
                 break;
              }
           }
        }
     }
     if(ImaVec==false && ubaci==true) {
        ostatak.push_back(v[i]);
     }
   }
     v=ostatak;
}

int main ()
{
   int n;
   cout<<"Koliko zelite unijeti rijeci: ";
   cin>>n;
   cin.ignore(10000,'\n');
   cout<<"Unesite rijeci: ";
   vector<string> v(n);
   for(int i=0; i<n;i++)   
      getline(cin,v[i]);
   string s1,s2;
   IzdvojiKrajnjeRijeci(v,s1,s2);
   ZadrziDuplikate(v);
   cout<<"Prva rijec po abecednom poretku je: "<<s1<<std::endl;
   cout<<"Posljednja rijec po abecednom poretku je: "<<s2<<std::endl;
   cout<<"Rijeci koje se ponavljaju su: ";
   for(int i(0); i<v.size(); i++)   
      cout<<v[i]<<" ";
   
	return 0;
}