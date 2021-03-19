#include <iostream>

class NeobicnaKlasa{
	public:
		explicit NeobicnaKlasa (int &&x){std::cout << "Direktna inicijalizacija"<<std::endl;}
		NeobicnaKlasa (const int &x){std::cout << "Kopirajuca inicijalizacija";}
};
int main (){
	NeobicnaKlasa k1(5);
	NeobicnaKlasa k2= 5;
	return 0;
}