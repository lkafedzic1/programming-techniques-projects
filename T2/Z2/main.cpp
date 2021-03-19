#include <iostream>
#include <cmath>
#include <vector>

bool TestPerioda (std::vector<double> v, int p) {
	if(v.size()<=1 || p<1 || v.size()<=p) return false;
	for(int i=0; i+p<v.size();i++) {
		 if(std::fabs(v.at(i)-v.at(i+p))>0.005) return 0;
	}
	
return 1;
}

int OdrediOsnovniPeriod (std::vector<double> v) {
	if (v.size()==0) return 0;
	for(int i=1; i<v.size(); i++) {
		if (TestPerioda(v,i)) {
			return i;
		}
	}
	return 0;
}

int main ()
{
	std::vector<double> v;
	std::cout<<"Unesite slijed brojeva (0 za kraj): ";
	for(;;){
		double x;
		std::cin>>x;
		if(std::fabs(x)-0<0.005) break;
		else v.push_back(x);
	}
	
	int P(OdrediOsnovniPeriod(v));
	if (P==0) std::cout<<"Slijed nije periodican!";
	else if (P!=0) std::cout<<"Slijed je periodican sa osnovnim periodom "<<P<<".";
	
	return 0;
}