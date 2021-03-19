/* TP, 2017/2018, Tutorijal 3, Zadatak 8 */
#include <iostream>
#include <string>
#include<stdexcept>

std::string IzdvojiRijec (std::string a, int n)
{
     int prvi(a.length()), brojac(0),poc(-1),kraj(-1);
     bool razmak(true);
     
     if(n<1)
     {
        throw std::range_error("IZUZETAK: Pogresan redni broj rijeci!");
     }
     
     for(int i=0;i<prvi;i++)
     {
         if(a[i]!=' ' && razmak == true)
         { 
             brojac++;
             razmak = false;
             if (brojac == n)
             {
                poc=i;
             }
         }
         if (a[i]==' ' && razmak == false) 
         {
            razmak = true;
            if (poc != -1) 
            { 
                kraj=i; break; 
                
            }
         }
     }
    
    if(brojac<n)
    {
        return std::string();
    }
    
    std::string novi=a.substr(poc,kraj-poc);
    return novi;
 }

int main()
{
     std::string rijec,a;
     int n;
     std::cout<<"Unesite redni broj rijeci: ";
     std::cin>>n;
     std::cin.ignore(10000,'\n');
     std::cout << "Unesite recenicu: " ;
     getline(std::cin,rijec);
     
     if(n<=0)
     {
        std::cout << "IZUZETAK: Pogresan redni broj rijeci!" << std::endl;
        return 0;
     }
     a=IzdvojiRijec(rijec,n);
     if(a.empty())
     {
        std::cout << "IZUZETAK: Pogresan redni broj rijeci!" << std::endl;
        return 0;
     }
    std::cout<<"Rijec na poziciji "<<n<<" je "<<a<<std::endl;
     return 0;
}