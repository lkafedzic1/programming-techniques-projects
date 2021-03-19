//TP 2016/2017: Tutorijal 1, Zadatak 1
#include <iostream>
int main ()
{
    std::cout<<"Unesite duzinu, sirinu i dubinu bazena u metrima: ";
    int a,b,c,d;
    std::cin>>a>>b>>c;
    std::cout<<"Unesite sirinu plocice u centimetrima: "<<std::endl;
    std::cin>>d;
    int br(0);
    int P;
    P=(a*b+2*(a*c+b*c))*10000;
    if((P%(d*d))==0) {
        br=P/(d*d);
        std::cout<<"Za poplocavanje bazena dimenzija "<<a<<"x"<<b<<"x"<<c<<"m sa plocicama dimenzija "<<d<<"x"<<d<<"cm "<<std::endl<<"potrebno je "<<br<<" plocica."<<std::endl;
    }
    else 
        std::cout<<"Poplocavanje bazena dimenzija "<<a<<"x"<<b<<"x"<<c<<"m sa plocicama dimenzija "<<d<<"x"<<d<<"cm"<<std::endl<<"nije izvodljivo bez lomljenja plocica!"<<std::endl;
        
    return 0;
}