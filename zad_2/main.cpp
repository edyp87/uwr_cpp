/* Marek Jenda
 * nazwa programu: kurs_cpp_zad1
 * nazwa modulu: main.cpp
 * 12-02-10 12:29:00:00
 */

#include "stack.h"

using namespace std;

int main()
{
    int odp, tmp;
    double x;
    cout << "*****************************************************************" << endl;
    cout << "*                    Autor : Marek Jenda                        *" << endl;
    cout << "*              Program testujacy dzialanie stosu                *" << endl;
    cout << "*****************************************************************" << endl;

    while(1) {
        cout << endl;
        cout << "[1] : Stworz nowy stos." << endl;
        cout << "[0] : Zakoncz dzialanie programu." << endl << "odp : ";
        cin  >> odp;
        if(odp == 0) break;

        cout << endl;
        cout << "Podaj rozmiar stosu." << endl << "odp : ";
        cin  >> tmp;
        stos &stack = *new stos(tmp);

        while(1) {
            cout << endl;
            cout << "[1] : Poloz nowy element na stosie." << endl;
            cout << "[2] : Sciagnij element ze stosu." << endl;
            cout << "[3] : Spradz element na stosie." << endl;
            cout << "[4] : Podaj liczbe elementow na stosie." << endl;
            cout << "[0] : Zniszcz stos i powroc do poprzedniego menu." << endl << "odp : ";
            cin  >> odp;

            if(odp == 0) {
                delete &stack;
                break;
            }
            switch(odp)
            {
                case 1 :
                    cout << "Podaj element: ";
                    cin  >> x;
                    try {
                        stack.wloz(x);
                        cout << "Element umieszczony na stosie: " << x << endl;
                    }
                    catch(char *w) {
                        cerr << w;
                    }
                    break;
                case 2 :
                    try {
                        cout << "Element sciagniety ze stosu to: " << stack.sciagnij() << endl;
                    }
                    catch(char *w) {
                        cerr << w;
                    }
                    break;
                case 3 :
                    {
                        try {
                            cout << "Element na szczycie stosu to: " << stack.sprawdz() << endl;
                        }
                        catch(const char *w) {
                            cerr << w;
                        }
                    break;
                    }
                case 4 :
                    {
                        cout << "Elementow na stosie: " << stack.zapelnienie() << endl;
                    }
            }
        }
    }
    return 0;
}
