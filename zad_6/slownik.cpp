#include "slownik.h"

Wezel::Wezel(Para &p, Wezel *_poprzedni, Wezel *_nastepny) {
    para = new Para(p.klucz, p.Wartosc());
    poprzedni = _poprzedni;
    nastepny  = _nastepny;
}

Wezel::~Wezel() {
    delete para;
}

bool Wezel::wstaw(Wezel *wz, Para &p) {
    Wezel *tmp;

    while(wz->nastepny != NULL && p.klucz > wz->nastepny->para->klucz)
        wz = wz->nastepny;

    if(wz->nastepny == NULL) {
        tmp = new Wezel(p, wz, NULL);
        wz->nastepny = tmp;
        return true;
    }

    if(p.klucz == wz->nastepny->para->klucz)
        return false;

    tmp = new Wezel(p, wz, wz->nastepny);
    wz->nastepny->poprzedni = tmp;
    wz->nastepny = tmp;
    return true;
}

bool Wezel::usun(Wezel *wz, const std::string &klucz) {
    while(wz->nastepny != NULL) {
        if(wz->nastepny->para->klucz != klucz) {
            wz = wz->nastepny;
            continue;
        }
        Wezel *tmp = wz->nastepny;
        wz->nastepny = tmp->nastepny;
        if(tmp->nastepny != NULL) tmp->nastepny->poprzedni = wz;
        delete tmp;
        return true;
    }
    return false;
}

int Wezel::pobierz_wart(Wezel *wz, const std::string &klucz) {
    while(wz->nastepny != NULL) {
        if(wz->nastepny->para->klucz != klucz) { wz = wz->nastepny; continue; }
        return wz->nastepny->para->Wartosc();
    }
    return 0;
}

void Wezel::wypisz(Wezel *wz) {
    wz = wz->nastepny;
    while(wz != NULL) {
        std::cout << wz->para->klucz << " " << wz->para->Wartosc() << "\n";
        wz = wz->nastepny;
    }
}

void Wezel::wyczysc(Wezel *wz) {
    if(wz != NULL) {
        wyczysc(wz->nastepny);
        delete wz;
    }
}

Slownik::Slownik() {
    Para tmp("", 0);
    korzen = new Wezel(tmp, NULL, NULL);
    rozmiar = 0;
}

Slownik::~Slownik() {
    Wezel::wyczysc(korzen);
}

bool Slownik::wstaw(const std::string &klucz, const int &wartosc) {
    Para tmp(klucz, wartosc);
    if(Wezel::wstaw(korzen, tmp)) {
        rozmiar++;
        return true;
    }
    return false;
}

bool Slownik::usun(const std::string &klucz) {
    if(Wezel::usun(korzen, klucz)) {
        rozmiar--;
        return true;
    }
    return false;
}

int Slownik::szukaj(const std::string &klucz) {
    return Wezel::pobierz_wart(korzen, klucz);
}

void Slownik::wypisz() {
    Wezel::wypisz(korzen);
}
