#include<iostream>
#include<cmath>
#include<complex>

int main ()
{
	std::cout<<"Unesite broj elemenata: "<<std::endl;
	int n;
	std::cin>>n;
	std::complex<double> Z_,sum;
	for(int i=1; i<=n; i++) {
		std::cout<<"Z_"<<i<<" = ";
		std::cin>>Z_;
		sum+=1./Z_;
	}
	std::complex<double> p_veza(1./sum);
	std::cout<<std::endl<<"Paralelna veza ovih elemenata ima impedansu Z_ = "<<p_veza<<".";
	
	return 0;
}