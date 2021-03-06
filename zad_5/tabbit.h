#include <iostream>
#define TABBIT_MAX_SIZE 3000000
#include <cstring>
using namespace std;

class TabBit
{
   typedef unsigned long long slowo; // komorka w tablicy
   static const int rozmiarSlowa = sizeof(slowo) * 8; // rozmiar slowa w bitach

   friend istream & operator >> (istream &we, TabBit &tb);
   friend ostream & operator << (ostream &wy, const TabBit &tb);
   friend TabBit & operator &= (TabBit &a, const TabBit &b);
   friend TabBit & operator |= (TabBit &a, const TabBit &b);
   friend TabBit & operator ^= (TabBit &a, const TabBit &b);
   friend TabBit & operator ! (const TabBit &a);

   class Ref
   {
      slowo &s;
      int nr;

      static slowo val(int x) {
	  return ((slowo)1) << x;
       }

     public:
      Ref(slowo &sl, int n) : s(sl), nr(n) {}

      operator bool() const {
	  return (bool)(s & val(nr));
       }

      bool const operator = (const bool b) {
	  if(b) {
	    s |= val(nr);
	    return true;
	   }
	  s &= ~val(nr);
	  return false;
       }

     const bool operator = (const Ref &b) {
	  this->operator =((bool) b);
      }
    };

   class Zakres : exception {}; // klasa wyjatku

  protected:
   int dl; // liczba bitów
   slowo *tab; // tablica bitów

   Ref wezRefa(int i) const;

  public:
   explicit TabBit (int rozm);
   TabBit (const TabBit &tb);
   ~TabBit ();

   TabBit & operator = (const TabBit &tb);

   const bool operator[] (int i) const {
     return (const bool) wezRefa(i);
    }

   Ref operator[] (int i) {
     return wezRefa(i);
    }

   inline int rozmiar() const {
     return dl;
    }
};
