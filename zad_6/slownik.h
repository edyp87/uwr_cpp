#ifndef slownik_h
#define slownik_h

#include <iostream>
#include <string>

class Para {
    public:
     const std::string klucz;

     Para(std::string _klucz, int _wartosc) : klucz(_klucz), wartosc(_wartosc) {}
     int Wartosc() { return wartosc; } //getter
     void Wartosc(int nowaWartosc) { wartosc = nowaWartosc; } //setter

    private:
     int wartosc;
};

class Wezel {
    public:
     Wezel(Para &p, Wezel *_poprzedni, Wezel *_nastepny);
     ~Wezel();
     static bool wstaw(Wezel *wz, Para &p);
     static bool usun(Wezel *wz, const std::string &kl);
     static int pobierz_wart(Wezel *wz, const std::string &kl);
     static void wyczysc(Wezel *wz);
     static void wypisz(Wezel *wz);

    private:
     Para *para;
     Wezel *poprzedni, *nastepny;
};

class Slownik {
    public:
     Slownik();
     ~Slownik();
     bool wstaw(const std::string &klucz, const int &wartosc);
     bool usun(const std::string &klucz);
     int szukaj(const std::string &key);
     inline int ile() { return rozmiar; }
     void wypisz();

     int operator[] (const std::string klucz) {
        return szukaj(klucz);
     }

    private:
     Wezel *korzen;
     int rozmiar;
};

#endif
