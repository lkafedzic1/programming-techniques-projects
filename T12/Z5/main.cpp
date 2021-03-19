#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
int main (){
	std::vector<double> v;
	std::cout << "Koliko zelite elemenata: ";
	int n; std::cin >> n;
	v.resize(n);
	std::cout<<"Unesite elemente: ";
	for(int i=0;i<n;i++) std::cin >> v[i];
	std::cout<<"Transformirani elementi: ";
	std::transform(v.begin(),v.end(),v.begin(),std::bind(std::divides<double>(),1,std::placeholders::_1));
	for(int i=0;i<n;i++) std::cout<<v[i]<<" ";
	return 0;
}