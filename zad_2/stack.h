#ifndef stack_h
#define stack_h

#include <iostream>
#include <cmath>

using namespace std;

class stos {
    private:
       int liczElem;                  //liczba elementow na stosie
       double *ws;                    //wskaznik do elementu

    public:
        int rozmiar;                     //rozmiar stosu

        stos(int rozmiarn = 1);
        stos( stos &ps);
        ~stos();
        void wloz(double x);
        double sciagnij();
        double sprawdz();
        int zapelnienie();

};

#endif
