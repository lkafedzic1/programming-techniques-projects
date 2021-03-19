/* TP, 2017/2018, Tutorijal 4, Zadatak 1 */
#include <iostream>
#include <cmath>

int Cifre (long long int n,int &c_min,int &c_max) {
    if(n<0) n*=-1;
    int br(1),c(n%10);
    c_min=c;
    c_max=c;
    n/=10;
    while(n!=0) {
        c=n%10;
        n/=10;
        if(c<c_min) c_min=c;
        if(c>c_max) c_max=c;
        br++;
    }
return br;
}

int main () {
   long long n;
   std::cout<<"Unesite broj: ";
   std::cin>>n;
   int min(10), max(0);
   int c=Cifre(n,min,max);
   std::cout<<"Broj "<<n<<" ima "<<c<<" cifara, najveca je "<<max<<" a najmanja "<<min<<".";
	return 0;
}