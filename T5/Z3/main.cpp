/* 
    TP 2017/2018 (Tutorijal 5, Zadatak 3)
	
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
#include <algorithm>
#include <cmath>
using std::cin;
using std::cout;

using std::for_each;
using std::max_element;
using std::min_element;
using std::count;
using std::count_if;

void Unos(int &x) {
	cin>>x;
}
bool Je_li_kvadrat(int n) {
	double x;
	x=sqrt(n);
	if (int(x)!=x) return false;
	return true;
}
void ispis(int x) {
	if((x>=100 && x<=999) || (x>=-999 && x<=-100));
	else cout<<x<<" ";
}
bool red (int a,int b) {
	return abs(a)<abs(b);
}
int main () {
	int n;
	cout<<"Unesite broj elemenata (max. 1000): ";
	cin>>n;
	int niz[1000];
	int *p(&niz[0]),*s(&niz[n]);
	cout<<"Unesite elemente: ";
	for_each(p,s,[] (int &x) {return Unos(x);});
	
	cout<<"Najveci element niza je "<<*max_element(p,p+n)<<std::endl;
	cout<<"Najmanji element niza se pojavljuje "<<count(p,p+n,*min_element(p,p+n))<<" puta u nizu"<<std::endl;
	cout<<"U nizu ima "<<count_if(p,p+n,Je_li_kvadrat)<<" brojeva koji su potpuni kvadrati"<<std::endl;
    cout<<"Prvi element sa najmanjim brojem cifara je "<<*min_element(p,s,red)<<std::endl;
    cout<<"Elementi koji nisu trocifreni su: ";
    for_each(p,p+n,[] (int x) {return ispis(x);});
	return 0;
}