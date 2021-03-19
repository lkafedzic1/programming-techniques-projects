//TP 2016/2017: Tutorijal 1, Zadatak 2
#include <iostream>
#include <cmath>

int main ()
{
    using std::cout;
    using std::cin;
    double a,b,c;
    cout<<"Unesite tri broja: ";
    cin>>a>>b>>c;
    if (a>0 && b>0 && c>0 && a<(b+c) && b<(a+c) && c<(a+b)) {
        double O=a+b+c;
        double s=O/2;
        double P=std::sqrt(double(s*(s-a)*(s-b)*(s-c)));
        double alfarad=std::acos((b*b+c*c-a*a)/2*b*c);
        double betarad=std::acos((a*a+c*c-b*b)/2*a*c);
        double gamarad=std::acos((a*a+b*b-c*c)/2*a*b);
        const double PI=4*std::atan(1);
        double alfa=alfarad*(180/PI);
        double beta=betarad*(180/PI);
        double gama=gamarad*(180/PI);
        
        double min=alfa;
        if (beta<min) 
            min=beta;
        else if (gama<min) 
            min=gama;
        
        
        double minStepeni=int(min);
        double minMinuta=int((min-minStepeni)*60);
        double minSekundi=int((((min-minStepeni)*60)-minMinuta)*60);
        
        cout<<"Obim trougla sa duzinama stranica "<<a<<", "<<b<<" i "<<c<<" iznosi "<<O<<"."<<std::endl;
        cout<<"Njegova povrsina iznosi "<<P<<"."<<std::endl;
        cout<<"Njegov najmanji ugao ima "<<minStepeni<<" stepeni, "<<minMinuta<<" minuta i "<<minSekundi<<" sekundi."<<std::endl;
    }
    
    else
        cout<<"Ne postoji trougao cije su duzine stranica "<<a<<", "<<b<<" i "<<c<<"!";
    
	return 0;
}