/* TP, 2017/2018, Tutorijal 4, Zadatak 2 */
#include <iostream>
#include <string>

void IzvrniString (std::string &s) {
    char pom;
    for(int i=0; i<((int)s.length()/2);i++) {
        pom=s.at(i);
        s.at(i)=s.at(s.size()-1-i);
        s.at(s.size()-1-i)=pom;
        
    }
}


int main ()
{
   std::string recenica;
   std::cout<<"Unesi string: ";
   std::getline(std::cin,recenica);
   IzvrniString(recenica);
   std::cout<<"Izvrnuti string je: "<<recenica;
	return 0;
}