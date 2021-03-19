#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <memory>
typedef std::shared_ptr<std::string> Pametni;
int main (){
	int n;
	std::cout << "Koliko zelite recenica: ";
	std::cin >> n;
	std::cin.ignore(10000, '\n');

	std::cout << "Unesite recenice: "<<std::endl;
	try{
		std::unique_ptr<Pametni[]> recenice(new Pametni[n]);
		for(int i=0;i<n;i++){
			recenice[i]=std::make_shared<std::string> ();
			std::getline(std::cin,*recenice[i]);
		}
		std::sort(recenice.get(),recenice.get()+n,[](Pametni x, Pametni y){return *x<*y;});
		std::cout << "Sortirane recenice: " << std::endl;
		for(int i=0;i<n;i++){
			std::cout << *(recenice[i])<< std::endl;
		}
	}
	catch(...){
		std::cout << "Problemi s memorijom!" << std::endl;
	}
	return 0;
}