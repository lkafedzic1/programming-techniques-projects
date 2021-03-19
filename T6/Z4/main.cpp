/* 
    TP 16/17 (Tutorijal 6, Zadatak 4)
	
	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja 
	i sugestije saljite na mail: khodzic2@etf.unsa.ba
	
	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak
	
*/
#include <iostream>
#include <stdexcept>
#include <new>
using std::cout;
using std::cin;

int** KreirajTrougao(int n) {
	if (n<=0) throw std::domain_error("Broj redova mora biti pozitivan");
	int **a(nullptr);
	try {
		a=new int* [n];
		for (int i=0; i<n; i++) {
			a[i]=new int [2*i+1];
			a[i][i]=1;
			int pocetak(0), broj(i+1), kraj(2*i);
			while (pocetak<i) {
				a[i][pocetak]=broj;
				a[i][kraj]=broj;
				pocetak++;
				kraj--;
				broj--;
			}
		}
	}
	catch (std::bad_alloc izuzetak) {
		for (int i=0; i<n; i++) {
			delete[] a[i];
		}
		delete[] a;
		throw std::bad_alloc();
	}
	return a;
}


int main ()
{
	try {
		cout<<"Koliko zelite redova: ";
		int n;
		cin>>n;
		int **pok(KreirajTrougao(n));
		for (int i=0; i<n; i++) {
			for (int j=0; j<2*i+1;j++) {
				cout<<pok[i][j]<<" ";
			}
			cout<<std::endl;
		}
		for(int i=0; i<n;i++)
			delete[] pok[i];
		delete[] pok;
	}
	catch (std::bad_alloc izuzetak) {
		cout<<"Izuzetak: Nedovoljno memorije!";
	}
	catch (std::domain_error izuzetak) {
		std::cout<<"Izuzetak: "<<izuzetak.what();
	}
	
	return 0;
}