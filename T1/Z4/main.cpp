//TP 2016/2017: Tutorijal 1, Zadatak 4
#include <iostream>

int main ()
{
    using std::cout;
    using std::cin;
    double n;
    
    for(;;){
    cout<<"Unesite prirodan broj ili 0 za kraj: ";
    cin>>n;
    while(((n-int(n))>0.00005) || n<0 || !cin) {
        cout<<"Niste unijeli prirodan broj!"<<std::endl;
        cin.clear();
        cin.ignore(10000,'\n');
        cout<<"Unesite prirodan broj ili 0 za kraj: ";
        cin>>n;
    }
    if (int(n)==0)  {
        cout<<"Dovidjenja!";
        return 0;
    }
    else {
        int suma(0), br(0);
        for(int i=1;i<static_cast<int>(n);i++) {
            if((static_cast<int>(n)%i)==0) {
                br++;
                suma+=i;
            }
        }
        int N=static_cast<int>(n);
        if(suma < N)
            cout<<"Broj "<<N<<" je manjkav!"<<std::endl;
        else if(suma > N)
            cout<<"Broj "<<N<<" je obilan!"<<std::endl;
        else if(suma==N)
            cout<<"Broj "<<N<<" je savrsen!"<<std::endl;
    }
    }
	return 0;
}