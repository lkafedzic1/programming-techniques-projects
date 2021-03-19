//TP 2017/2018: Tutorijal 8, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <iomanip>
using namespace std;
struct Vrijeme {
    int sati, minute, sekunde;
};
void TestirajVrijeme (Vrijeme v) {
    if(v.sati<0 || v.sati>23 || v.minute<0 || v.minute>59 || v.sekunde<0 || v.sekunde > 59)
        throw domain_error("Neispravno vrijeme");
}

void IspisiVrijeme(Vrijeme v){
    try{
        TestirajVrijeme(v);
    }
    catch(std::domain_error izuzetak)
    {
        throw izuzetak;
    }
    std::cout<<std::setfill('0')<<std::setw(2)<<v.sati<<":"<<std::setw(2)<<v.minute<<":"<<std::setw(2)<<v.sekunde;
}

Vrijeme SaberiVrijeme (Vrijeme v1, Vrijeme v2) {
    Vrijeme v3;
    try{
        TestirajVrijeme(v1); 
        TestirajVrijeme(v2);
    }
    catch(domain_error e){
        throw e;
    }
    v3.sekunde=v1.sekunde+v2.sekunde;
    v3.minute=v1.minute+v2.minute;
    v3.sati=v1.sati+v2.sati;

    if(v3.sekunde>=60) {
            v3.sekunde%=60;
            v3.minute++;
        
    }
    v3.minute+=v1.minute+v2.minute;
        if(v3.minute>=60) {

                v3.minute%=60;
                v3.minute++;
            
         }
    v3.sati+=v1.sati+v2.sati;
    if(v3.sati>24) {
            v3.sati%=24;
        
    }
    
    return v3;
}


int main ()
{
   std::cout<<"Unesite prvo vrijeme (h m s): ";
    Vrijeme a;
    std::cin>>a.sati>>a.minute>>a.sekunde;
    try{
        TestirajVrijeme(a);
    }
    catch(std::domain_error izuzetak)
    {
        std::cout<<izuzetak.what();
        return 0;
    }
    std::cout<<"Unesite drugo vrijeme (h m s): ";
    Vrijeme b;
    std::cin>>b.sati>>b.minute>>b.sekunde;
    try{
        TestirajVrijeme(b);
    }
    catch(std::domain_error izuzetak)
    {
        std::cout<<izuzetak.what();
        return 0;
    }
    std::cout<<"Prvo vrijeme: ";
    IspisiVrijeme(a);
    std::cout<<std::endl<<"Drugo vrijeme: ";
    IspisiVrijeme(b);
    auto f(SaberiVrijeme(a,b));
    std::cout<<std::endl<<"Zbir vremena: ";
    IspisiVrijeme(f);
	return 0;
}
