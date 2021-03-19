#include<iostream>
#include<cmath>
#include<complex>

int main ()
{
	std::cout<<"Unesite broj elemenata: "<<std::endl;
	int n;
	std::cin>>n;
	double r,c;
	std::complex<double>sum;
	for(int i=1; i<=n; i++) {
		std::cout<<"R"<<i<<" = ";
		std::cin>>r;
		std::cout<<"X"<<i<<" = ";
		std::cin>>c;
		std::cout<<std::endl;
		std::complex<double> Z_(r,c);
		sum+=1./Z_;
	}
	std::complex<double> p_veza(1./sum);
	std::cout<<std::endl<<"Paralelna veza ovih elemenata ima R = "<<p_veza.real()<<" i X = "<<p_veza.imag()<<".";
	
	return 0;
}