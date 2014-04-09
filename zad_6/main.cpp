#include <iostream>
#include "slownik.h"
#include "wyrazenie.h"

void test(int *, int *);

int main()
{
    int tmp;
    Zmienna x("x", -3);

    while(true) {
        Wyrazenie *t = new Dodaj(
          new Stala(3),
          new Stala(5)
        );

        std::cout << t->opis() << " = " << t->oblicz() << "\n";
        delete t;

        t = new Dodaj(
             new Stala(2),
             new Przemnoz(
              &x,
              new Stala(7)
              )
            );

        std::cout << t->opis() << " = " << t->oblicz() << "\n";
        delete t;

        t = new Podziel(
             new Odejmij(
              new Przemnoz(
               new Stala(3),
               new Stala(11)
              ),
             new Stala(1)
             ),
             new Dodaj(
              new Stala(7),
              new Stala(5)
             )
            );

        std::cout << t->opis() << " = " << t->oblicz() << "\n";
        delete t;

        t = new Podziel(
             new Przemnoz(
              new Dodaj(
               &x,
               new Stala(1)
              ),
              &x
             ),
             new Stala(2)
            );
        std::cout << t->opis() << " = " << t->oblicz() << "\n";
        delete t;

        t = new Mniejsze(
             new Dodaj(
              new Przemnoz(
               new Stala(2),
               &x
              ),
              new Stala(1)
             ),
             new Stala(0)
            );
        std::cout << t->opis() << " = " << t->oblicz() << "\n";
        delete t;

        std::cout << "\nWczytaj x\n";
        std::cin  >> tmp;
        x = tmp;
    }


    return 0;
}

void test(int *i, int *j) {
    int *tmp;
    tmp = i;
    i = j;
    j = tmp;
}
