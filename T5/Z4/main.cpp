/* 
    TP 2017/2018 (Tutorijal 5, Zadatak 4)
	
	Autotestove pisala Nina Slamnik. Prijave gresaka, sugestije i pitanja
	mozete slati na mail nslamnik1@etf.unsa.ba.
	
	NAPOMENA: Tutorijal 5 sadrzi veliki broj ZABRANA, tipa zabrana
			  da se koristi indeksiranje niz[i] ili simulacija indeksiranja
			  npr. *(niz + i); dalje, da su zabranjene for petlje i slicno.
			  
			  To ce tutori rucno pregledati u toku tutorijala te ako
			  student bude PREKRSIO BAREM JEDNU ZABRANU, smatrace se da
			  za taj zadatak NIJE PROSAO NITI JEDAN AUTOTEST!
*/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <deque>
using std::cout;
using std::cin;
using std::deque;

void Unos(int &x) {
	cin>>x;
}
void Ispis(int x) {
	cout<<x<<" ";
}
int br (int n, int brc) {
	if(n==0) return brc;
	brc++;
	n/=10;
return br(n, brc);
}

int main () {
	cout<<"Unesite broj elemenata: ";
	int n;
	cin>>n;
	deque<int> niz(n);
	cout<<"Unesite elemente: ";
	for_each(niz.begin(), niz.end(), Unos);
	auto p=std::max_element(std::begin(niz), std::end(niz));
	cout << "Najveci element deka je "<<*p << std::endl;
	p=std::min_element(std::begin(niz), std::end(niz));
	cout << "Najmanji element deka se pojavljuje "<<std::count(std::begin(niz), std::end(niz), *p)<<" puta u deku"<<std::endl;
	cout << "U deku ima "<< std::count_if(std::begin(niz), std::end(niz), [] (int x){ if(x<0) return false; if(std::sqrt(x)==int(std::sqrt(x))) return true; return false;})<<" brojeva koji su potpuni kvadrati"<<std::endl;
	p=std::min_element(std::begin(niz), std::end(niz), [](int x, int y){ return br(x,0)<br(y,0);});
	cout << "Prvi element sa najmanjim brojem cifara je "<<*p<<std::endl;
	cout << "Elementi koji nisu trocifreni su: ";
	p=std::remove_if(std::begin(niz), std::end(niz), [] (int x){ int broj=br(x, 0); return broj==3;});
	for_each(niz.begin(), p, Ispis);
	return 0;
} 