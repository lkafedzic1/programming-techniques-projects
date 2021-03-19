#include <iostream>
#include <deque>
#include <string>
#include <stdexcept>
template <typename tip>
auto SumaBloka(tip p1, tip p2) ->decltype(*p1+*p1){
	if(p1==p2) throw std::range_error("Blok je prazan");
	auto suma(*p1);
	p1++;
	while(p1!=p2){
		suma+=*p1;
		p1++;
	}
	return suma;
}
int main (){
	std::deque<std::string> d (0);
	std::string suma = SumaBloka (d.begin(), d.end());
	std::cout << "'" << suma << "'";
	return 0;
}