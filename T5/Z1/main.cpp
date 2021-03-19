/* 
    TP 2017/2018 (Tutorijal 5, Zadatak 1)
	
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
using std::cin;
using std::cout;



int main () {
	char recenica[1000];
	cout<<"Unesite recenicu: ";
	cin.getline(recenica,sizeof recenica,'\n');
    cout<<"Recenica bez prve rijeci glasi: ";
    char *p(recenica);
    if (*p==' ') {
        while(*p==' ') p++;
    }
    while (*p!=' ' && *p!='\0') p++;
    
    if (*p!='\0') {
        while(*p==' ') p++;
    }
    while (*p!='\0') {
    	cout<<*p;
    	p++;
    }
    cout<<std::endl;
    
	return 0;
} 