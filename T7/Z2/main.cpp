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
	char**s=nullptr;
	std::string rec;
	try {
		cout<<"Unesite recenice:\n";
		s=new char*[n];
		try {
			for(int i=0; i<n;i++) s[i]=nullptr;
			for (int i=0; i<n; i++) {
				std::getline(std::cin,rec);
				s[i]=new char[rec.size()+1];
				std::strcpy(s[i],rec.c_str());
			}
			std::sort(s,s+n,[](char *x,char *y) {return std::strcmp(x,y)<=0;});
		}
		catch(std::bad_alloc x) {
			for (int i=0;i<n;i++) delete[] s[i];
			throw x;
		}
		cout<<"Sortirane recenice:\n";
		for(int i=0;i<n;i++) cout<<s[i]<<std::endl;
		for(int i=0;i<n;i++) delete[] s[i];
	}
	catch(std::bad_alloc x) {
		cout<<"Problemi s memorijom!";
	}
	delete [] s;
	return 0;
}