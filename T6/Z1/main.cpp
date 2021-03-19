/* 
    TP 16/17 (Tutorijal 6, Zadatak 1)
	
	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja 
	i sugestije saljite na mail: khodzic2@etf.unsa.ba
	
	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak
	
*/
/* 
    TP 16/17 (Tutorijal 6, Zadatak 1)
	
	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja 
	i sugestije saljite na mail: khodzic2@etf.unsa.ba
	
	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak
	
*/
#include <iostream>
#include <cmath>
#include <deque>
#include <vector>
#include <stdexcept>
#include <limits>
using std::cin;
using std::cout;
template <typename Tip>

Tip *GenerirajStepeneDvojke (int n) {
	if (n<=0) throw std::domain_error("Broj elemenata mora biti pozitivan");
	Tip *pok=nullptr;
	try {
		pok = new Tip[n];
	}
	catch (std::bad_alloc x) {
		delete[] pok;
		throw std::runtime_error("Alokacija nije uspjela");
	}
	pok[0]=1;
	for (int i=1; i<n; i++) {
		if(pok[i-1]>std::numeric_limits<Tip>::max()/2) {
			delete[] pok;
			throw std::overflow_error("Prekoracen dozvoljeni opseg");
		}
		pok[i]=pok[i-1]*2;
	}
	return pok;
}


int main ()
{	
	int* niz=nullptr;
	int n;
	cout<<"Koliko zelite elemenata: ";
	cin>>n;
	try {
		niz=GenerirajStepeneDvojke<int>(n);
		for (int i=0; i<n; i++) {
			cout<<niz[i]<<" ";
	}
	}
	catch(std::runtime_error x ) {
		cout<<"Izuzetak: "<<x.what();
	}
	catch(std::domain_error x) { 
		cout<<"Izuzetak: "<<x.what();
	}
	delete[] niz;
	return 0;
}