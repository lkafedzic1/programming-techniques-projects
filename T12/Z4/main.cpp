#include <iostream>
#include <complex>
typedef std::complex<int> Kompleksni;
std::ostream &operator <<(std::ostream &tok, Kompleksni c){
	if(c.real()!=0)tok<<c.real();
	if(c.imag()==1&&c.real()!=0)tok<<"+"<<"i";
	else if(c.imag()==1&&c.real()==0)tok<<"i";
	else if(c.imag()==-1)tok<<"-"<<"i";
	else if(c.imag()!=0){
		if(c.imag()>0&&c.real()!=0)tok<<"+"<<c.imag()<<"i";
		else tok<<c.imag()<<"i";
	}
	if(c.real()==0&&c.imag()==0) tok<<0;
	return tok;
}

int main ()
{
	std::cout << Kompleksni(0);
	return 0;
}