/* 
    TP 16/17 (Tutorijal 6, Zadatak 5)
	
	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja 
	i sugestije saljite na mail: khodzic2@etf.unsa.ba
	
	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak
	
*/
#include <iostream>
#include <deque>
#include <vector>
#include <stdexcept>
#include <new>
using std::cin;
using std::cout;
using std::vector;
using std::deque;

template <typename Kontejner1>

auto KreirajDinamickuKopiju2D(Kontejner1 v1) -> typename std::remove_reference<decltype(v1[0][0])>::type** {
	typename std::remove_reference<decltype(v1[0][0])>::type** a(nullptr);
	try {
		a=new typename std:: remove_reference<decltype(v1[0][0])>::type* [v1.size()];
		for(int i=0; i<v1.size(); i++) {
			a[i]=new typename std::remove_reference<decltype(v1[0][0])>::type [v1[i].size()];
		}
		for (int i=0; i<v1.size();i++) {
			for(int j=0; j<v1[i].size();j++) {
				a[i][j]=v1[i][j];
			}
		}
	}
	catch(std::bad_alloc izuzetak) {
		delete[] a;
		throw std::bad_alloc();
	}
	return a;
}


int main ()
{
	try {
		cout<<"Unesite broj redova kvadratne matrice: ";
		int n;
		cin>>n;
		vector<deque<int>> v(n,deque<int> (n));
		cout<<"Unesite elemente matrice: ";
		for (int i=0;i<n; i++) {
			for(int j=0; j<n; j++) {
				cin>>v[i][j];
			}
		}
		int** pok(nullptr);
		pok=KreirajDinamickuKopiju2D(v);
		for (int i=0; i<n;i++) {
			for (int j=0; j<n;j++) {
				cout<<pok[i][j]<<" ";
			}
			cout<<std::endl;
		}
		for (int i=0; i<n; i++) {
			delete[] pok[i];
		}
		delete[] pok;
	}
	catch (std::bad_alloc izuzetak) {
		std::cout<<"Nedovoljno memorije";
	}
	
	return 0;
}