#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <typeinfo>
#include <limits>

class Napis {
    public:
     Napis(std::string x);    //kosntruktor
     Napis(const Napis &np);  //konstruktor kopiujacy
     Napis(int x);            //konstruktor konwertujacy int na napis
     Napis(bool x);           //konstruktor konwertujacy wartosc logiczna na napis
     Napis(char x);           //konstruktor konwertujacy znak na napis
     Napis(double x);         //konstruktor konwertujacy double na napis
     Napis(void *x);          //konstruktor konwertujacy wartosc logiczna na napis
     virtual ~Napis();

     Napis & operator =  (const Napis &np);  //operator tworzacy referencje
     Napis & operator += (const Napis &np);  //

     operator std::string() const; //zwraca pole war obiektu
     operator int() const;
     operator bool() const;
     operator char() const;
     operator double() const;
     operator void *();

     int length() const;
     void append(const Napis &a);
     void insert(const Napis &a, int pos);
     void erase(int spos, int epos);
     void replace(const Napis &a, int pos);
     Napis substr(int pos, int n);

     char operator[] (int i) const {
        return war[i];
     }

    private:
     std::string war;

     friend Napis operator + (Napis &a, Napis &b);
     friend bool operator < (const Napis &a, const Napis &b);
     friend bool operator <= (const Napis &a, const Napis &b);
     friend bool operator == (const Napis &a, const Napis &b);
     friend bool operator > (const Napis &a, const Napis &b);
     friend bool operator >= (const Napis &a, const Napis &b);
     friend bool operator != (const Napis &a, const Napis &b);
     friend std::ostream & operator << (std::ostream &wy, const Napis &np);
};
