#include "tabbit.h"
#include <iostream>
using namespace std;


int main()
{
   // TabBit x(5);
   // cout<<x<<endl;
   // cin>>x;
   // cout<<x<<endl;
    TabBit t(72); // tablica 72 bitow
    t[0] = 1; // ustawienie bitu 0-ego bitu na 1
    t[71] = true; // ustawienie bitu 71-go bitu na 1
    bool b = t[0]; // odczytanie bitu 0-ego
    t[40] = b; // ustawienie bitu 40-go
    t[36] = t[38] = t[71]; // przepisanie bitu 71-go do bitow 38-go i 36-go
    cout<<t<<endl; // wysietlenie zawartosci tablicy bitow na ekranie
     cout << t.test(15);
cout<<t<<endl;

    TabBit tmp = !t;
    tmp[70] = t[70];
    tmp^=t;

    cout<<tmp<<endl;

    //while(true) {
    TabBit t1(10);
    t1[0] = t1[5] = t1[9] = 1;

    TabBit t2(10);
    t2[3] = t2[7] = t2[9] = 1;

    cout<<"t1 = "<<t1<<endl<<"t2 = "<<t2<<endl;
    t1 &= t2;
    cout<<"t1 &= t2 = "<<t1<<endl;

    return 0;
}
