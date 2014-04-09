#include "wyrazenie.h"

//***********klasa Stala***********

Stala::Stala(int x) {
    wartosc = x;
}

int Stala::oblicz() {
    return wartosc;
}

std::string Stala::opis() {
    std::ostringstream tmp;
    tmp << wartosc;
    return tmp.str();
}

//**********klasa Zmienna**********

Zmienna::Zmienna(std::string _nazwa, int _wartosc) {
    nazwa = _nazwa;
    if(!slownik.wstaw(_nazwa, _wartosc))
        throw nazwa + "Zmienna o takiej nazwie juz istnieje.\n";
}

Zmienna::Zmienna(std::string _nazwa) {
    nazwa = _nazwa;
    if(!slownik.wstaw(_nazwa, 0))
        throw nazwa + "Zmienna o takiej nazwie juz istnieje.\n";
}

Zmienna::~Zmienna() {
    slownik.usun(nazwa);
}

void Zmienna::operator = (int _wartosc) {
    slownik.usun(nazwa);
    slownik.wstaw(nazwa, _wartosc);
}

int Zmienna::oblicz() {
    return slownik[nazwa];
}

std::string Zmienna::opis() {
    std::ostringstream tmp;
    tmp << slownik[nazwa];
    return "(" + nazwa + "=" + tmp.str() + ")";
}

Slownik Zmienna::slownik;

//*******klasa Operator1arg********

Operator1arg::Operator1arg(Wyrazenie *_arg1) {
    arg1 = _arg1;
}

Operator1arg::~Operator1arg() {
    delete arg1;
}

//*******klasa PrzeciwnyZnak********

PrzeciwnyZnak::PrzeciwnyZnak(Wyrazenie *_arg1) : Operator1arg(_arg1) {}

PrzeciwnyZnak::~PrzeciwnyZnak() {}

int PrzeciwnyZnak::oblicz() {
    return -1 * arg1->oblicz();
}

std::string PrzeciwnyZnak::opis() {
    std::ostringstream tmp;
    tmp << "-(" << arg1->opis() << ")";
    return tmp.str();
}

//*******klasa WartBezwzgl********

WartBezwzgl::WartBezwzgl(Wyrazenie *_arg1) : Operator1arg(_arg1) {}

WartBezwzgl::~WartBezwzgl() {}

int WartBezwzgl::oblicz() {
    int tmp = arg1->oblicz();
    if(tmp < 0) return -1 * tmp;
    return tmp;
}

std::string WartBezwzgl::opis() {
    std::ostringstream tmp;
    tmp << "|" << arg1->opis() << "|";
    return tmp.str();
}

//*******klasa Operator2arg********

Operator2arg::Operator2arg(Wyrazenie *_arg1, Wyrazenie *_arg2) : Operator1arg(_arg1), arg2(_arg2) {}

Operator2arg::~Operator2arg() {
    delete arg2;
}

std::string Operator2arg::opisOperator2arg(std::string znak) {
    std::ostringstream tmp;
    tmp << "(" << arg1->opis() <<" " << znak << " " << arg2->opis() << ")";
    return tmp.str();
}

//*******operacje binarne********

Dodaj::Dodaj(Wyrazenie *_arg1, Wyrazenie *_arg2) : Operator2arg(_arg1, _arg2) {}

Dodaj::~Dodaj() {}

int Dodaj::oblicz() {
    return arg1->oblicz() + arg2->oblicz();
}

std::string Dodaj::opis() {
    return opisOperator2arg("+");
}


Odejmij::Odejmij(Wyrazenie *_arg1, Wyrazenie *_arg2) : Operator2arg(_arg1, _arg2) {}

Odejmij::~Odejmij() {}

int Odejmij::oblicz() {
    return arg1->oblicz() - arg2->oblicz();
}

std::string Odejmij::opis() {
    return opisOperator2arg("-");
}


Przemnoz::Przemnoz(Wyrazenie *_arg1, Wyrazenie *_arg2) : Operator2arg(_arg1, _arg2) {}

Przemnoz::~Przemnoz() {}

int Przemnoz::oblicz() {
    return arg1->oblicz() * arg2->oblicz();
}

std::string Przemnoz::opis() {
    return opisOperator2arg("*");
}


Podziel::Podziel(Wyrazenie *_arg1, Wyrazenie *_arg2) : Operator2arg(_arg1, _arg2) {}

Podziel::~Podziel() {}

int Podziel::oblicz() {
    return arg1->oblicz() / arg2->oblicz();
}

std::string Podziel::opis() {
    return opisOperator2arg("/");
}


Modulo::Modulo(Wyrazenie *_arg1, Wyrazenie *_arg2) : Operator2arg(_arg1, _arg2) {}

Modulo::~Modulo() {}

int Modulo::oblicz() {
    return arg1->oblicz() + arg2->oblicz();
}

std::string Modulo::opis() {
    return opisOperator2arg("+");
}


Minimum::Minimum(Wyrazenie *_arg1, Wyrazenie *_arg2) : Operator2arg(_arg1, _arg2) {}

Minimum::~Minimum() {}

int Minimum::oblicz() {
   int tmp1 = arg1->oblicz(), tmp2 = arg2->oblicz();
   return (tmp1 <= tmp2 ? tmp1 : tmp2);
}


std::string Minimum::opis() {
   std::ostringstream tmp;
   tmp << "MIN(" << arg1->opis() << ", " << arg2->opis() << ")";
   return tmp.str();
}

Maksimum::Maksimum(Wyrazenie *_arg1, Wyrazenie *_arg2) : Operator2arg(_arg1, _arg2) {}

Maksimum::~Maksimum() {}

int Maksimum::oblicz() {
   int tmp1 = arg1->oblicz(), tmp2 = arg2->oblicz();
   return (tmp1 >= tmp2 ? tmp1 : tmp2);
}


std::string Maksimum::opis() {
   std::ostringstream tmp;
   tmp << "MAX(" << arg1->opis() << ", " << arg2->opis() << ")";
   return tmp.str();
}

Rowne::Rowne(Wyrazenie *_arg1, Wyrazenie *_arg2) : Operator2arg(_arg1, _arg2) {}

Rowne::~Rowne() {}

int Rowne::oblicz() {
   int tmp1 = arg1->oblicz(), tmp2 = arg2->oblicz();
   return (tmp1 == tmp2 ? 1 : 0);
}


std::string Rowne::opis() {
   return opisOperator2arg("==");
}

Mniejsze::Mniejsze(Wyrazenie *_arg1, Wyrazenie *_arg2) : Operator2arg(_arg1, _arg2) {}

Mniejsze::~Mniejsze() {}

int Mniejsze::oblicz() {
   int tmp1 = arg1->oblicz(), tmp2 = arg2->oblicz();
   return (tmp1 < tmp2 ? 1 : 0);
}


std::string Mniejsze::opis() {
   return opisOperator2arg("<");
}

Mniejszerowne::Mniejszerowne(Wyrazenie *_arg1, Wyrazenie *_arg2) : Operator2arg(_arg1, _arg2) {}

Mniejszerowne::~Mniejszerowne() {}

int Mniejszerowne::oblicz() {
   int tmp1 = arg1->oblicz(), tmp2 = arg2->oblicz();
   return (tmp1 <= tmp2 ? 1 : 0);
}


std::string Mniejszerowne::opis() {
   return opisOperator2arg("<=");
}

Wieksze::Wieksze(Wyrazenie *_arg1, Wyrazenie *_arg2) : Operator2arg(_arg1, _arg2) {}

Wieksze::~Wieksze() {}

int Wieksze::oblicz() {
   int tmp1 = arg1->oblicz(), tmp2 = arg2->oblicz();
   return (tmp1 > tmp2 ? 1 : 0);
}

std::string Wieksze::opis() {
   return opisOperator2arg(">");
}

Wiekszerowne::Wiekszerowne(Wyrazenie *_arg1, Wyrazenie *_arg2) : Operator2arg(_arg1, _arg2) {}

Wiekszerowne::~Wiekszerowne() {}

int Wiekszerowne::oblicz() {
   int tmp1 = arg1->oblicz(), tmp2 = arg2->oblicz();
   return (tmp1 >= tmp2 ? 1 : 0);
}

std::string Wiekszerowne::opis() {
   return opisOperator2arg("=>");
}

Rozne::Rozne(Wyrazenie *_arg1, Wyrazenie *_arg2) : Operator2arg(_arg1, _arg2) {}

Rozne::~Rozne() {}

int Rozne::oblicz() {
   int tmp1 = arg1->oblicz(), tmp2 = arg2->oblicz();
   return (tmp1 != tmp2 ? 1 : 0);
}

std::string Rozne::opis() {
   return opisOperator2arg("!=");
}

