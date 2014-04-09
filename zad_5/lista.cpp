/* Marek Jenda
 * nazwa programu: kurs_cpp_zad5
 * nazwa modulu: lista.cpp
 * 12-31-03 12:29:00:00
 */

#include "lista.h"
#include <iostream>

using namespace std;
Wezel::Wezel(double _wart, Wezel *_l, Wezel *_p) : wart(_wart), l(_l), p(_p) {}

void * Wezel::operator new (size_t size) {
    return Pamiec::alokuj();
}

void Wezel:: operator delete (void *ptr) {
    Pamiec::zwolnij(ptr);
}

Lista::Lista() : pocz(NULL), kon(NULL), rozm(0) {}

Lista::~Lista() {
    Pamiec::usunCalaListe(pocz);
}

void Lista::wstaw(double wartosc, int pozycja) {
    if(pozycja < 0 || pozycja > rozm)
        throw "Niepoprawna pozycja.";

    Wezel *tmp;
    if(rozm == 0) {
        tmp = new Wezel(wartosc, NULL, NULL);
        pocz = kon = tmp;
    }

    else if(pozycja == 0) {
        tmp = new Wezel(wartosc, NULL, pocz);
        pocz->l = tmp;
        pocz = tmp;
    }

    else if(pozycja == rozm) {
        tmp = new Wezel(wartosc, kon, NULL);
        kon->p = tmp;
        kon = tmp;
    }

    else {
        Wezel &akt = this->operator [](pozycja);
        tmp = new Wezel(wartosc, akt.l, &akt);
        akt.l = tmp;
        tmp->l->p = tmp;
    }

    rozm++;
}

bool Lista::usun(int pozycja) {
    if(pozycja < 0 || pozycja >= rozm)
        return false;

    Wezel *tmp;
    if(rozm == 1) {
        tmp = pocz;
        pocz = kon = NULL;
    }

    else if(pozycja == 0) {
        tmp = pocz;
        pocz = tmp->p;
        pocz->l = NULL;
    }

    else if(pozycja == rozm - 1) {
        tmp = kon;
        kon = tmp->l;
        kon->p = NULL;
    }

    else {
        tmp = &(this->operator [](pozycja));
        tmp->l->p = tmp->p;
        tmp->p->l = tmp->l;
    }

    delete tmp;
    rozm--;
    return true;
}

void Lista::wypisz(){
    Wezel *akt = pocz;
    while(akt != NULL) {
        cout << akt->wart << " ";
        akt = akt->p;
    }
    cout<<endl;
}

Stos::Stos() : pocz(NULL), rozm(0) {}

Stos::~Stos() {
    Pamiec::usunCalaListe(pocz);
}

void Stos::wstaw(double wartosc) {
    Wezel *tmp = new Wezel(wartosc, NULL, pocz);
    pocz = tmp;
    rozm++;
}

bool Stos::usun() {
    if(rozm == 0)
        return false;

    Wezel *tmp = pocz;
    pocz = tmp->p;
    delete tmp;
    rozm--;
    return true;
}

double Stos::operator *() {
    return (pocz != NULL ? pocz->wart : NAN);
}

void Stos::wypisz(){
    Wezel *akt = pocz;
    while(akt != NULL) {
        cout << akt->wart << " ";
        akt = akt->p;
    }
    cout << endl;
}

Kolejka::Kolejka() : pocz(NULL), kon(NULL), rozm(0) {}

Kolejka::~Kolejka() {
    Pamiec::usunCalaListe(pocz);
}

void Kolejka::wstaw(double wartosc) {
    Wezel *tmp;
    if(rozm == 0) {
        tmp = new Wezel(wartosc, NULL, NULL);
        pocz = kon = tmp;
    }

    else {
        tmp = new Wezel(wartosc, kon, NULL);
        kon->p = tmp;
        kon = tmp;
    }

    rozm++;
}

bool Kolejka::usun() {
    if(rozm == 0)
        return false;

    Wezel *tmp;
    if(rozm == 1) {
        tmp = pocz;
        pocz = kon = NULL;
    }

    else {
        tmp = pocz;
        pocz = tmp->p;
        pocz->l = NULL;
    }

    delete tmp;
    rozm--;
    return true;
}

double Kolejka::operator *() {
    return (pocz != NULL ? pocz->wart : NAN);
}

void Kolejka::wypisz(){
    Wezel *akt = pocz;
    while(akt != NULL) {
        cout << akt->wart << " ";
        akt = akt->p;
    }
    cout<<endl;
}

TabBit Pamiec::t(MAX_ROZMIAR);
char Pamiec::obszar[MAX_ROZMIAR];

void Pamiec::zamien(int i, bool wart) {
    cout << "Stan pamieci:\nPrzed: " << t << endl;
    for(int k = i; k < i + rozmEl; k++)
        t[k] = wart;
    cout << "   Po: " << t << endl;
}

bool Pamiec::sprawdzCzyWolne(int i) {
    for(int k = i; k < i + rozmEl; k++)
        if(t[k]) return false;
    return true;
}

void * Pamiec::alokuj() {
    for(int i = 0; i <= MAX_ROZMIAR - rozmEl; i++)
        if(!t[i] && sprawdzCzyWolne(i)) {
            zamien(i, 1);
            return (void *) &obszar[i];
        }
    return NULL;
}

void Pamiec::zwolnij(void *ptr) {
    zamien((char *)ptr - &obszar[0], 0);
}

void Pamiec::usunCalaListe(Wezel *ptr) {
    if(ptr != NULL) {
        usunCalaListe(ptr->p);
        delete ptr;
    }
}

void Pamiec::resetuj() {
    for(int i = 0; i < MAX_ROZMIAR; i++)
        t[i] = 0;
}
