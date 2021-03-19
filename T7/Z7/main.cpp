/* 
    TP 16/17 (Tutorijal 7, Zadatak 7)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <set>
#include <string>
using std::cout;
using std::cin;

template <typename Tip>

auto Unija (std::set<Tip> skup1, std::set<Tip> skup2) -> std::set<Tip> {
	std::set<Tip> unija;
	for (Tip x: skup1) unija.insert(x);
	for (Tip x: skup2) unija.insert(x);
	return unija;
}

template <typename Tip2>
auto Presjek(std::set<Tip2> skup1, std::set<Tip2>skup2) -> std::set<Tip2> {
	std::set<Tip2> presjek;
	for (Tip2 x: skup1)
		for(Tip2 y: skup2) 
			if(x==y) presjek.insert(x);
	return presjek;
}

int main ()
{
	std::set<std::string> skup1{"TP","IM2","Ljubav","etf","student","Tuga","profesori"},skup2{"OE","Tuga","etf","IM1"},unija(Unija(skup1,skup2)),presjek(Presjek(skup1,skup2));
	cout<<"Unija: ";
	for(std::string x:unija) cout<<x<<" ";
	cout<<std::endl;
	cout<<"Presjek: ";
	for(std::string x:presjek) cout<<x<<" ";
	cout<<std::endl;
	return 0;
}