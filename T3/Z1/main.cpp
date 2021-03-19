/* TP, 2017/2018, Tutorijal 3, Zadatak 1 */
#include <iostream>
#include <vector>

bool ParnostSumeCifara(int n) {
    int suma(0);
    while(n!=0) {
        suma+=n%10;
        n/=10;
    }
    if(suma%2==0) return true;
    return false;
}

std::vector<int> IzdvojiElemente (std::vector<int> v, bool p_n) {
    std::vector<int> nv;
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
    std::vector<int> a,b,c;
    std::cout<<"Unesite elemente: ";
    int x;
    for(int i=0; i<n;i++) {
        std::cin>>x;
        a.push_back(x);
    }
    b=IzdvojiElemente(a,true);
    c=IzdvojiElemente(a,false);
    for(int vr:b) std::cout<<vr<<" ";
    std::cout<<std::endl;
    for(int vr:c) std::cout<<vr<<" ";
    std::cout<<std::endl;
    
	return 0;
}