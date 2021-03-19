#include <iostream>
#include <string>
#include <type_traits>
#include <vector>
#include <stdexcept>
#include <forward_list>

template <typename tip>
auto KreirajIzvrnutiNiz (tip pocetak, tip kraj)->typename std::remove_reference<decltype (*pocetak)>::type*{
	int brojac=0;
	tip hehe=pocetak;
	while (hehe!=kraj){
		brojac++;
		hehe++;
	}
	typename std::remove_reference<decltype (*pocetak)>::type *p = new typename std::remove_reference<decltype (*pocetak)>::type [brojac];
	tip pom = pocetak;
	int i = brojac-1;
	
	while (pom!=kraj){
		p[i]=*pom;
		pom++;
		i--;
	}
	return p;
}
int main()
{
	int n;
	std::cout<<"Koliko zelite elemenata: ";
	std::cin>> n;
	double *pok;
	try{
	pok=new double [n];
	delete [] pok;
	double niz[100];
	std::cout<<"Unesite elemente: ";
	for (int i=0; i<n; i++){
		std::cin>>niz[i];
	}
	double *p = KreirajIzvrnutiNiz(niz, niz+n);
	std::cout<<"Kreirani niz: ";
	for (int i=0; i<n; i++){
		std::cout<<p[i]<<" ";
	}
	delete [] p;
	}
		catch (std::bad_alloc a){
			std::cout<<"Nedovoljno memorije!";
		}
	return 0;
}