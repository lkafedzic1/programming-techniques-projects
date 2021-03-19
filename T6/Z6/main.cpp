/* 
    TP 16/17 (Tutorijal 6, Zadatak 6)
	
	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja 
	i sugestije saljite na mail: khodzic2@etf.unsa.ba
	
	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak
	
*/
#include <iostream>
#include <new>
#include <vector>
#include <deque>
#include <type_traits>

template <typename Tip_Matrice>
	auto KreirajDinamickuKopiju2D (Tip_Matrice matrica)->typename std::remove_reference<decltype(matrica[0][0])>::type** {
typedef typename std::remove_reference<decltype(matrica[0][0])>::type Nesto;
	Nesto **nova_matr(new Nesto*[matrica.size()]);
int max(0);
for(int i(0);i<matrica.size();i++) {
	if(matrica[i].size()>max) max=matrica[i].size();
	}
	try{
		nova_matr[0]=new Nesto[matrica.size()*max];
		for(int i(1); i<matrica.size(); i++) nova_matr[i]=nova_matr[i-1]+matrica[i].size();

	} catch(std::bad_alloc) {
		delete[] nova_matr;
		throw;
	}
for(int i=0; i<matrica.size(); i++) {
	for(int j=0; j<matrica[i].size(); j++) {
		nova_matr[i][j]=matrica[i][j];
	}
}
return nova_matr;
}

int main ()
{
try {
std::cout<<"Unesite broj redova kvadratne matrice: ";
int n;
std::cin>>n;
std::vector<std::deque<int>>M(n, std::deque<int>(n));
std::cout<<"Unesite elemente matrice: ";
for(int i(0); i<n; i++)
	for(int j(0); j<n; j++) 
		std::cin>>M[i][j];
auto x(KreirajDinamickuKopiju2D(M));
for(int i=0; i<n; i++) {
	for(int j=0; j<n; j++) {
		std::cout<<x[i][j]<<" ";
	}
	std::cout<<std::endl;
}
delete [] x[0];
delete[] x;


} catch(std::bad_alloc) {
std::cout<<"Nedovoljno memorije";
}
return 0;
}