/* Marek Jenda
 * nazwa programu: kurs_cpp_zad5
 * nazwa modulu: lsita.h
 * 12-31-03 12:29:00:00
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include "tabbit1.h"

using namespace std;

class Wezel {
    double wart;
    Wezel *l, *p;

    Wezel(double _wart, Wezel *_l, Wezel *_p);

   public:
    void * operator new (size_t size);
    void operator delete (void *ptr);

    friend class Lista;
    friend class Stos;
    friend class Kolejka;
    friend class Pamiec;
};

class Lista {
    Wezel *pocz, *kon;
    int rozm;

   public:
    Lista();
    ~Lista();
    void wstaw(double wartosc, int pozycja);
    bool usun(int pozycja);
    inline int rozmiar() { return rozm; }
    void wypisz();

    Wezel & operator [](int i) {
        if(i < 0 || i >= rozm)
            throw "Element nie istnieje";

        Wezel *akt = pocz;
        for(int j = 0; j < i; j++)
                akt = akt->p;
        return *akt;
    }
};

class Stos : private Lista {
    Wezel *pocz;
    int rozm;

   public:
    Stos();
    ~Stos();
    void wstaw(double wartosc);
    bool usun();
    inline int rozmiar() { return rozm; }
    void wypisz();

    double operator *();
};

class Kolejka : private Lista {
    Wezel *pocz, *kon;
    int rozm;

   public:
    Kolejka();
    ~Kolejka();
    void wstaw(double wartosc);
    bool usun();
    inline int rozmiar() { return rozm; }
    void wypisz();

    double operator *();
};

class Pamiec {
    static const int rozmEl = sizeof(Wezel);
    static const int MAX_ROZMIAR = 64;
    static char obszar[MAX_ROZMIAR];
    static TabBit t;

    static void zamien(int i, bool wart);
    static bool sprawdzCzyWolne(int i);

   public:
    static void * alokuj();
    static void zwolnij(void *ptr);
    static void usunCalaListe(Wezel *ptr);
    static void resetuj();
};
