#include "stack.h"

stos::stos( stos &ps)
{
    rozmiar = ps.rozmiar;
    liczElem = ps.liczElem;
    ws = new double[rozmiar];
    if(ws == NULL) throw "Brak pamieci!\n";
    for(int i = 0; i < rozmiar; i++)
        ws[i] = ps.ws[i];
}


stos::stos(int rozmiarn)
{
   rozmiar = rozmiarn;
   liczElem = 0;

   ws = new double[rozmiar];
   if(ws == NULL) throw "Brak pamieci!\n";
}


stos::~stos()
{
   liczElem = 0;
   delete[] ws;
}


void stos::wloz(double x)
{
   if(liczElem == rozmiar) {
       throw "Nie mozna wlozyc elementu. Stos jest zapelniony.\n";
       return;
     }

   ws[liczElem++] = x;
}


double stos::sciagnij()
{
   if(liczElem == 0) {
       throw "Nie mozna sciagnac elementu. Stos jest pusty.\n";
       return NAN;
    }

   return ws[--liczElem];
}


double stos::sprawdz()
{
   if(liczElem == 0) {
       throw "Nie mozna sprawdzic elementu. Stos jest pusty.\n";
       return NAN;
    }

   return ws[liczElem - 1];
}


int stos::zapelnienie()
{
   return liczElem;
}
