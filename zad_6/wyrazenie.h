#ifndef wyrazenie_h
#define wyrazenie_h

#include <sstream>
#include "slownik.h"

class Wyrazenie {
    public:
        virtual int oblicz() = 0;
        virtual std::string opis() = 0;
};

//***********klasa Stala***********

class Stala : public Wyrazenie {
    public:
     Stala(int x);

     int oblicz();
     std::string opis();

    private:
     int wartosc;
};

//***********klasa Zmienna*********

class Zmienna : public Wyrazenie {
    public:
     Zmienna(std::string _nazwa, int _wartosc);
     Zmienna(std::string _nazwa);
     ~Zmienna();
     void operator = (int _wartosc);

     int oblicz();
     std::string opis();

    private:
     static Slownik slownik;
     std::string nazwa;
};

//*******klasa Operator1arg********

class Operator1arg : public Wyrazenie {
    public:
     Operator1arg(Wyrazenie *_arg1);
     ~Operator1arg();

    protected:
     Wyrazenie *arg1;
};

//*******klasa PrzeciwnyZnak********

class PrzeciwnyZnak : public Operator1arg {
    public:
     PrzeciwnyZnak(Wyrazenie *_arg1);
     ~PrzeciwnyZnak();

     int oblicz();
     std::string opis();
};

//*******klasa WartBezwzgl********

class WartBezwzgl : public Operator1arg {
    public:
     WartBezwzgl(Wyrazenie *_arg1);
     ~WartBezwzgl();

     int oblicz();
     std::string opis();
};

//*******klasa Operator2arg********

class Operator2arg : public Operator1arg {
    public:
     Operator2arg(Wyrazenie *_arg1, Wyrazenie *_arg2);
     ~Operator2arg();

    protected:
     Wyrazenie *arg2;
     std::string  opisOperator2arg(std::string znak);
};

//*******operacje binarne********

class Dodaj : public Operator2arg {
    public:
     Dodaj(Wyrazenie *_arg1, Wyrazenie *_arg2);
     ~Dodaj();

     int oblicz();
     std::string opis();
};

class Odejmij : public Operator2arg {
    public:
     Odejmij(Wyrazenie *_arg1, Wyrazenie *_arg2);
     ~Odejmij();

     int oblicz();
     std::string opis();
};

class Przemnoz : public Operator2arg {
    public:
     Przemnoz(Wyrazenie *_arg1, Wyrazenie *_arg2);
     ~Przemnoz();

     int oblicz();
     std::string opis();
};

class Podziel : public Operator2arg {
    public:
     Podziel(Wyrazenie *_arg1, Wyrazenie *_arg2);
     ~Podziel();

     int oblicz();
     std::string opis();
};

class Modulo : public Operator2arg {
    public:
     Modulo(Wyrazenie *_arg1, Wyrazenie *_arg2);
     ~Modulo();

     int oblicz();
     std::string opis();
};

class Minimum : public Operator2arg {
    public:
     Minimum(Wyrazenie *_arg1, Wyrazenie *_arg2);
     ~Minimum();

     int oblicz();
     std::string opis();
};

class Maksimum : public Operator2arg {
    public:
     Maksimum(Wyrazenie *_arg1, Wyrazenie *_arg2);
     ~Maksimum();

     int oblicz();
     std::string opis();
};

class Rowne : public Operator2arg {
    public:
     Rowne(Wyrazenie *_arg1, Wyrazenie *_arg2);
     ~Rowne();

     int oblicz();
     std::string opis();
};

class Mniejsze : public Operator2arg {
    public:
     Mniejsze(Wyrazenie *_arg1, Wyrazenie *_arg2);
     ~Mniejsze();

     int oblicz();
     std::string opis();
};

class Mniejszerowne : public Operator2arg {
    public:
     Mniejszerowne(Wyrazenie *_arg1, Wyrazenie *_arg2);
     ~Mniejszerowne();

     int oblicz();
     std::string opis();
};

class Wieksze : public Operator2arg {
    public:
     Wieksze(Wyrazenie *_arg1, Wyrazenie *_arg2);
     ~Wieksze();

     int oblicz();
     std::string opis();
};

class Wiekszerowne : public Operator2arg {
    public:
     Wiekszerowne(Wyrazenie *_arg1, Wyrazenie *_arg2);
     ~Wiekszerowne();

     int oblicz();
     std::string opis();
};

class Rozne : public Operator2arg {
    public:
     Rozne(Wyrazenie *_arg1, Wyrazenie *_arg2);
     ~Rozne();

     int oblicz();
     std::string opis();
};



#endif
