/* TP, 2017/2018, Tutorijal 3, Zadatak 6 */
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

int NajvecaSirina(std::vector<std::vector<int>> m) {
    if (m.size()==0) return 0;
    int max(m[0][0]);
    for(int i=0;i<m.size();i++) {
        for(int j=0;j<m[i].size();j++) {
            int br=0;
            if(m[i][j]<0) br++;
            while(m[i][j]!=0) {
                m[i][j]/=10;
                br++;
            }
            if (br>max) max=br;
        }
    }
    return max;
}

std::vector<std::vector<int>> KroneckerovProizvod (std::vector<int> a, std::vector<int> b) {
    std::vector<std::vector<int>> c;
    for(int i=0;i<a.size();i++) {
        for(int j=0;j<b.size();j++) {
            c[i][j]=a.at(i)*b.at(j);
        }
    }
    return c;
}

int main ()
{
    std::vector<int> a,b;
    int n1,n2;
    std::cout<<"Unesite broj elemenata prvog vektora: ";
    std::cin>>n1;
    std::cout<<"Unesite elemente prvog vektora: ";
    int x,y;
    for(int i=0;i<n1;i++) {
        std::cin>>x;
        a.push_back(x);
    }
    std::cout<<"Unesite broj elemenata drugog vektora: ";
    std::cin>>n2;
    std::cout<<"Unesite elemente drugog vektora: ";
    for(int i=0; i<n2;i++) {
        std::cin>>y;
        b.push_back(y);
    }
    std::vector<std::vector<int>> c(KroneckerovProizvod(a,b));
    int w(NajvecaSirina(c)+1);
    for(int i=0;i<c.size();i++) {
        for(int j=0;j<c[i].size();j++) {
            std::cout<<std::setw(w)<<c[i][j];
        }
        std::cout<<std::endl;
    }
    
    
	return 0;
}