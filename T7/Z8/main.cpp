/* 
    TP 16/17 (Tutorijal 7, Zadatak 8)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
using std::cout;

std::string IzvrniBezRazmaka(std::string s) {
	std::string pom;
	std::remove_copy(s.rbegin(),s.rend(),std::back_inserter(pom),' ');
	return pom;
}

int main ()
{
	std::string s1("Funkcija kao parametar prima dva znaka."),s2(IzvrniBezRazmaka(s1));
	cout<<s2;
	return 0;
}