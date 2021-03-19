#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using std::cout;
using std::cin;

int main ()
{ 
	int n;
	cout<<"Koliko zelite recenica: ";
	cin>>n;
	cin.ignore(1000,'\n');
	std::string *s=nullptr;
	std::string rec;
	try {
		cout<<"Unesite recenice:\n";
		s=new std::string[n];
		for (int i=0; i<n; i++) {
			std::getline(std::cin,rec);
			s[i]=rec;
		}
		std::sort(s,s+n,[](std::string x, std::string y){return x<=y;});
		cout<<"Sortirane recenice:\n";
		for(int i=0;i<n;i++) cout<<s[i]<<std::endl;
	}
	catch(std::bad_alloc x) {
		cout<<"Problemi s memorijom!";
	}
	delete [] s;
	return 0;
}