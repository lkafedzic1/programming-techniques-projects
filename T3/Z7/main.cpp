/* TP, 2017/2018, Tutorijal 3, Zadatak 7 */
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <stdexcept>

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

std::vector<std::vector<int>> PascalovTrougao (int n) {
    std::vector<std::vector<int>> m;
    if (n==0) return m;
    if (n<0) throw std::domain_error("Broj redova ne smije biti negativan");
    
    m.resize(n);
    for(int i=0;i<n;i++) {
        m[i].resize(i+1);
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<i+1;j++){
            if ((j==0) || (i==j)) m[i][j]=1;
            else m[i][j]=m[i-1][j]+m[i-1][j-1];
        }
    }
    return m;
}

int main ()
{
    std::cout<<"Unesite broj redova: ";
    int n;
    std::cin>>n;
    try {
    std::vector<std::vector<int>> m(PascalovTrougao(n));
    int w(NajvecaSirina(m)+1);
    for(std::vector<int> k: m) {
        std::cout<<std::endl;
        for(int h:k) {
            std::cout<<std::setw(w)<<h;
        }
    }
    std::cout<<std::endl;
    }
    catch(std::domain_error izuzetak) {
        std::cout<<izuzetak.what()<<std::endl;
    }
	return 0;
}