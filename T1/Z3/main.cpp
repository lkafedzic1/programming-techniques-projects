//TP 2016/2017: Tutorijal 1, Zadatak 3
#include <iostream>
#include <cmath>
#include <iomanip>

int main ()
{
    using std::cout;
    using std::cin;
    int a, b;
    cout<<"Unesite pocetnu i krajnju vrijednost: \n";
    cin>>a>>b;
    
    cout<<"+---------+----------+----------+-----------+"<<std::endl;
    cout<<"| Brojevi | Kvadrati | Korijeni | Logaritmi |"<<std::endl;
    cout<<"+---------+----------+----------+-----------+"<<std::endl;
    for(int i=a;i<=b ;i++) {
        cout<<"| "<<std::left<<std::setw(8)<<i<< "|"<<std::right<<std::setw(9)<<i*i<<" |"<< std::right<<std::setw(9)<<std::fixed<<std::setprecision(3)<<std::sqrt(i)<<" |"<< std::right<<std::setw(10)<<std::fixed<<std::setprecision(5)<<std::log(i)<<" |"<<std::endl;
    }
    cout<<"+---------+----------+----------+-----------+"<<std::endl;
    
	return 0;
}