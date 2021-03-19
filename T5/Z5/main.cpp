#include <iostream>
#include <cmath>
#include <iomanip>

double TrapeznoPravilo(double fun(double), double a, double b, int n){
	double prvi((b-a)/n);
	double petlja(0);
	for(int i=1;i<n;i++) petlja+=fun(a+((b-a)/n)*i);
	return prvi*(fun(a)*0.5+fun(b)*0.5+petlja);
}

int main (){
	int n;
	std::cout << "Unesite broj podintervala: ";
	std::cin >> n;
	std::cout << "Za taj broj podintervala priblizne vrijednosti integrala iznose: " << std::endl;
	std::cout << "- Za funkciju sin x na intervalu (0,pi): " <<std::fixed<<std::setprecision(5)<<TrapeznoPravilo(std::sin,0,4*atan(1),n)<< std::endl;
	std::cout << "- Za funkciju x^3 na intervalu (0,10): " <<std::fixed<<std::setprecision(2)<< TrapeznoPravilo([](double x){return x*x*x;},0,10,n)<<std::endl;
	std::cout << "- Za funkciju 1/x na intervalu (1,2): " <<std::fixed<<std::setprecision(5)<< TrapeznoPravilo([](double x){return 1/x;},1,2,n)<<std::endl;
	return 0;
}