#include "tabbit.h"

TabBit::TabBit (int rozm)
{
  dl = rozm;
  int liczbaKomorek = rozm / rozmiarSlowa + 1;
  tab = new slowo[liczbaKomorek];
  if(tab == NULL) throw "Nie otrzymano pamieci na stercie\n";
  
  for(int i = 0; i < liczbaKomorek; i++) tab[i] = 0;
}


TabBit::TabBit (const TabBit &tb)
{
  dl = tb.dl;
  int liczbaKomorek = tb.dl / rozmiarSlowa + 1;
  tab = new slowo[liczbaKomorek];
  if(tab == NULL) throw "Nie otrzymano pamieci na stercie\n";
  
  for(int i = 0; i < liczbaKomorek; i++) tab[i] = tb.tab[i];
}
  
  
TabBit::~TabBit ()
{
  delete[] tab;
}


TabBit & TabBit::operator = (const TabBit &tb) 
{
  if(&tb == this) return *this;
  this->~TabBit();
  TabBit &tmp = *new TabBit(tb);
  return tmp;
}


TabBit::Ref TabBit::wezRefa(int i) const 
{
  if(i >= dl || i < 0) throw "Zazadano bitu, ktorego nie ma\n";
  return Ref(tab[i / rozmiarSlowa], i % rozmiarSlowa);
}   


istream & operator >> (istream &we, TabBit &tb)
{
  char c;
  
  for(int i = 0; i < tb.rozmiar(); i++) {
    cin>>c;
    if(c != '0' && c != '1')
      throw "Podany ciag jest niewlasciwy";
    if(c == '0') tb[i] = 0;
    else tb[i] = 1;
   }
  return we; 
}


ostream & operator << (ostream &wy, const TabBit &tb) 
{
  for(int i = 0; i < tb.rozmiar(); i++) cout << tb[i];
  return wy;
}

TabBit & operator &= (TabBit &a, const TabBit &b)
{
  int r = min(a.rozmiar() / TabBit::rozmiarSlowa + 1, b.rozmiar() / TabBit::rozmiarSlowa + 1);
  while(r--)
    a.tab[r] &= b.tab[r];
  return a;
}
 
 
TabBit & operator |= (TabBit &a, const TabBit &b)
{
  int r = min(a.rozmiar() / TabBit::rozmiarSlowa + 1, b.rozmiar() / TabBit::rozmiarSlowa + 1);
  while(r--)
    a.tab[r] |= b.tab[r];
  return a;
}
   

TabBit & operator ^= (TabBit &a, const TabBit &b) 
{
  int r = min(a.rozmiar() / TabBit::rozmiarSlowa + 1, b.rozmiar() / TabBit::rozmiarSlowa + 1);
  while(r--)
    a.tab[r] ^= b.tab[r];
  return a;
}  
  
  
TabBit & operator ! (const TabBit &a) 
{
  //int r = a.rozmiar();
  TabBit &b = *new TabBit(a.rozmiar());
  int r = a.rozmiar() / TabBit::rozmiarSlowa + 1;
  while(r--)
    b.tab[r] = ~a.tab[r];
  return b;
}  

