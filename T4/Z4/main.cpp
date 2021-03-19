/* TP, 2017/2018, Tutorijal 4, Zadatak 4 */
#include <iostream>
#include <string>
#include <cstring>
using std::string;
using std::cout;
using std::cin;

template <typename Sarma>

void UnosBroja (string unesi, string greska, Sarma &broj) {
   cout<<unesi;
   while(!(std::cin>>broj) || std::cin.peek()!='\n') {
      cout<<greska<<std::endl<<unesi;
      std::cin.clear();
      std::cin.ignore(10000,'\n');
   }
}

double exponent (double a, double b) {
   double e(1);
   if(b<0) {
      for(int i=0; i<abs(b);i++)
      e*=a;
      e=1/e;
   }
   else if(b>0) {
      for (int i=0; i<abs(b);i++)
      e*=a;
   }
   return e;
}
   
int main ()
{
   double baza;
   UnosBroja("Unesite bazu: \n","Neispravan unos, pokusajte ponovo...",baza);
   int ex;
   UnosBroja("Unesite cjelobrojni eksponent: \n","Neispravan unos, pokusajte ponovo...",ex);
   cout<<baza<<" na "<<ex<<" iznosi "<<exponent(baza,ex);
	return 0;
}