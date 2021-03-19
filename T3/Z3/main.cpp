/* TP, 2017/2018, Tutorijal 3, Zadatak 3 */
#include <iostream>
#include <deque>

bool ParnostSumeCifara(int n) {
    int suma(0);
    while(n!=0) {
        suma+=n%10;
        n/=10;
    }
    if(suma%2==0) return true;
    return false;
}

std::deque<int> IzdvojiElemente (std::deque<int> v, bool p_n) {
    std::deque<int> nv;
    for(int x:v) if(ParnostSumeCifara(x)==p_n) nv.push_back(x);
    return nv;
}

int main ()
{
    std::cout<<"Koliko zelite unijeti elemenata: ";
    int n;
    while(std::cin>>n, n==0) {
        std::cout<<"Broj elemenata mora biti veci od 0!";
        return 0;
    }
    std::deque<int> a,b,c;
    std::cout<<"Unesite elemente: ";
    int x;
    for(int i=0; i<n;i++) {
        std::cin>>x;
        a.push_back(x);
    }
    b=IzdvojiElemente(a,true);
    c=IzdvojiElemente(a,false);
    for(int i=0; i<b.size();i++) {
        if(i==b.size()-1) std::cout<<b.at(i);
        else std::cout<<b.at(i)<<",";
    }   
    std::cout<<std::endl;
    for(int i=0; i<c.size();i++){
        if(i==c.size()-1) std::cout<<c.at(i);
        else std::cout<<c.at(i)<<",";
    }
        std::cout<<std::endl;
	return 0;
}