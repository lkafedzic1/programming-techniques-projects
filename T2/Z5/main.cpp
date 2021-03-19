#include<iostream>
#include<cmath>
#include<complex>

int main ()
{
	std::cout<<"Unesi broj elemenata: ";
	int n;
	std::cin>>n;
	double z,fi;
	std::complex<double>sum;
	const double PI(4*atan(1));
	for(int i=1; i<=n; i++) {
		std::cout<<std::endl<<"Z"<<i<<" = ";
		std::cin>>z;
		std::cout<<"fi"<<i<<" = ";
		std::cin>>fi;
		double fi_rad=fi*PI/180;
		std::complex<double> Z_(std::polar(z,fi_rad));
		sum+=1./Z_;
	}
	std::complex<double> p_veza(1./sum);
	std::cout<<std::endl<<"Paralelna veza ovih elemenata ima Z = "<<std::abs(p_veza)<<" i fi = "<<std::arg(p_veza)*180/PI<<".";
	
	return 0;
}

