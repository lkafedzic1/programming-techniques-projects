/* 
    TP 16/17 (Tutorijal 7, Zadatak 6)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <list>
#include <type_traits>
using std::cout;
using std::cin;

template <typename Tip>

auto SortirajListu(std::list<Tip> lista) -> std::list<Tip> {
	for(auto it1(lista.begin()); it1!=lista.end(); it1++) {
		for (auto it2(it1);it2!=lista.end();it2++){
			if(*it2<*it1) {
				auto pom=*it1;
				*it1=*it2;
				*it2=pom;
			}
		}
	}
	return lista;
}

int main ()
{
	cout<<"Koliko ima elemenata: ";
	int n;
	cin>>n;
	std::list<int> lista(n);
	cout<<"Unesite elemente: ";
	for(auto it(lista.begin()); it!=lista.end();it++)
		cin>>*it;
	lista=SortirajListu(lista);
	cout<<"Sortirana lista: ";
	for (int x: lista) cout<<x<<" ";
	
	return 0;
}