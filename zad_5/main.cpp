/* Marek Jenda
 * nazwa programu: kurs_cpp_zad5
 * nazwa modulu: main.cpp
 * 12-31-03 12:29:00:00
 */

#include "lista.h"

int main()
{
  int poz, op, op1;
  double var;

  while(1) {
    cout << "*****************************************************************" << endl;
    cout << "*                    Autor : Marek Jenda                        *" << endl;
    cout << "*      Program testujacy dzialanie listy, stosu i kolejki       *" << endl;
    cout << "*****************************************************************" << endl << endl;

    cout << "[1] : Lista"   << endl;
    cout << "[2] : Stos"    << endl;
    cout << "[3] : Kolejka" << endl;
    cout << "[0] : Zakoncz" << endl;
    cin >> op;

    if(op == 0) break;

    if(op == 1) {
      Lista &test = *new Lista();
      while(1) {
        cout<<"[1] : Dodaj element na pozycje (\"wartosc pozycja\")" << endl;
        cout<<"[2] : Usun element z pozycji (\"pozycja\")"           << endl;
        cout<<"[0] : Powrot"                                         << endl;
        cin >> op1;

        if(op1 == 0) { delete &test; break; }

        if(op1 == 1) {
            cin >> var >> poz;
            try {
                test.wstaw(var, poz);
                cout << "Rozmiar = " << test.rozmiar() << "\nZawartosc : ";
            }
            catch(const char *s) { cout << s << endl; }
            test.wypisz();
        }

        if(op1 == 2) {
            cin>>poz;
            if(!test.usun(poz))
                cout << "Nie mozna usunac elementu\n";
            cout << "Rozmiar = " << test.rozmiar() << "\nZawartosc : ";
            test.wypisz();
        }
      }
    }

    if(op == 2) {
      Stos &test = *new Stos();
      while(1) {
        cout << "[1] : Dodaj element na stos"     << endl;
        cout << "[2] : Usun element ze stosu"     << endl;
        cout << "[3] : Podaj element ze szczytu"  << endl;
        cout << "[0] : Powrot"                    << endl;
        cin >> op1;

        if(op1 == 0) { delete &test; break; }

        if(op1 == 1) {
            cin >> var;
            test.wstaw(var);
            cout << "Rozmiar = " << test.rozmiar() << "\nZawartosc : ";
            test.wypisz();
        }

        if(op1 == 2) {
            if(!test.usun())
            cout << "Nie mozna usunac elementu\n";
        cout << "Rozmiar = " << test.rozmiar() << "\nZawartosc : ";
        test.wypisz();
        }

        if(op1 == 3)
            cout << *test << endl;
        }
    }

    if(op == 3) {
      Kolejka &test = *new Kolejka();
      while(1) {
            cout << "[1] : Dodaj element do kolejki" << endl;
            cout << "[2] : Usun element z kolejki"   << endl;
            cout << "[3] : Podaj element ze szczytu" << endl;
            cout << "[0] : Powrot"                   << endl;
            cin>>op1;

            if(op1 == 0) { delete &test; break; }

            if(op1 == 1) {
                cin>>var;
                test.wstaw(var);
                cout<<"Rozmiar = " << test.rozmiar() << "\nZawartosc : ";
                test.wypisz();
            }

            if(op1 == 2) {
                if(!test.usun())
                cout<<"Nie mozna usunac elementu\n";
                cout<<"Rozmiar = " << test.rozmiar() << "\nZawartosc : ";
                test.wypisz();
            }

            if(op1 == 3)
                cout << *test << endl;
      }
    }
  }
  return 0;
}
