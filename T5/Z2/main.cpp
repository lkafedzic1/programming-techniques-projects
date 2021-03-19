/* 
    TP 2017/2018 (Tutorijal 5, Zadatak 2)
	
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
#include <vector>
#include <string>
#include <utility>
using std::cin;
using std::cout;
using std::string;
using std::vector;

template <typename tip1,typename tip2,typename tip3>

tip3 RazmijeniBlokove(tip1 pocetak, tip2 kraj, tip3 odrediste) {
    int pom;
    while (pocetak!=kraj) {
        pom=*pocetak;
        *pocetak=*odrediste;
        *odrediste=pom;
        odrediste++;
        pocetak++;
    }
    return odrediste;
}

int main ()
{
	vector<int> a{0,1,2,3,4,5};
	vector<int> b{10,11,12,13,14,15};
	int *pokazivac;
	pokazivac=RazmijeniBlokove(&a[2], &a[4], &b[0]);
	for (int i=0; i<a.size(); i++) {
		cout<<a[i]<<" ";
	}
	cout<<std::endl;
	for (int i=0; i<b.size(); i++) {
		cout<<b[i]<<" ";
	}
	cout<<std::endl;
	string prvi("Unitarni ili prethilbertov redni prostor");
	string drugi("je realni vektorski prostor X");
	char *pok;
	pok=RazmijeniBlokove(&prvi[0], &prvi[8], &drugi[2]);
	for (int i=0; i<prvi.size();i++) 
		cout<<prvi[i];
	cout<<std::endl;
	for (int i=0; i<drugi.size();i++)
		cout<<drugi[i];
	cout<<std::endl;
	
	
	return 0;
}