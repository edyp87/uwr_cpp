/* Marek Jenda
 * nazwa programu: kurs_cpp_zad1
 * nazwa modulu: main.cpp
 * 12-02-10 12:29:00:00
 */

#include "zad1.hpp"

using namespace std;

int main()
{
    int odp;
    double x, y;
    cout << "*****************************************************************" << endl;
    cout << "*                    Autor : Marek Jenda                        *" << endl;
    cout << "* Program testujacy dzialanie obiektow klas Punkt2D i Odcinek2D *" << endl;
    cout << "*****************************************************************" << endl;

    while(1)
    {
        cout << endl;
        cout << "[1] : Wczytaj dwa punkty stanowiace konce odcinka." << endl;
        cout << "[0] : Zakoncz dzialanie programu." << endl << "odp : ";
        cin  >> odp;

        if(odp == 0) break;
        cout << "Podaj wspolrzedne pierwszego punktu (x, y): ";
        cin  >> x >> y;
        punkt2D punkt1(x, y);
        cout << "Podaj wpolrzedne drugiego punktu (x, y): ";
        cin  >> x >> y;
        punkt2D punkt2(x, y);
        odcinek2D odcinek1(punkt1, punkt2);
        while(1)
        {
            cout << endl;
            cout << "[1] : Przesun odcinek o podana wartosc wzgledem osi 0X." << endl;
            cout << "[2] : Przesun odcinek o podana wartosc wzgledem osi 0Y." << endl;
            cout << "[3] : Sprawdz czy podany punkt lezy na odcinku." << endl;
            cout << "[4] : Wczytaj parametry drugiego odcinka." << endl;
            cout << "[0] : Wroc do poprzedniego menu." << endl << "odp : ";
            cin  >> odp;

            if(odp == 0) break;
            switch(odp)
            {
                case 1 :
                    double odlx;
                    cout << "Podaj wartosc przesuniecia: ";
                    cin  >> odlx;
                    odcinek1.przesun0X(odlx);
                    cout << "Odcinek zostal przesuniety wzgledem osi 0X o: " << odlx << endl;
                    cout << "Nowe wspolrzedne "; odcinek1.wyswietl_wspol();
                    break;
                case 2 :
                    double odly;
                    cout << "Podaj wartosc przesuniecia: ";
                    cin  >> odly;
                    odcinek1.przesun0Y(odly);
                    cout << "Odcinek zostal przesuniety wzgledem osi 0Y o: " << odly << endl;
                    cout << "Nowe wspolrzedne "; odcinek1.wyswietl_wspol();
                    break;
                case 3 :
                    {
                        cout << "Podaj wspolrzedne punktu (x, y): ";
                        cin  >> x >> y;
                        punkt2D punkt3(x, y);
                        if(odcinek1.czy_na_odc(punkt3))
                            cout << "Podany punkt lezy na odcinku." << endl;
                        else
                            cout << "Podany punkt nie lezy na odcinku.";
                        break;
                    }
                case 4 :
                    {
                        cout << "Podaj wspolrzedne pierwszego punktu (x, y): ";
                        cin  >> x >> y;
                        punkt2D punkt4(x, y);
                        cout << "Podaj wpolrzedne drugiego punktu (x, y): ";
                        cin  >> x >> y;
                        punkt2D punkt5(x, y);
                        odcinek2D odcinek2(punkt4, punkt5);
                        while(1)
                        {
                            cout << endl;
                            cout << "[1] : Sprawdz czy odcinki sa rownlolegle." << endl;
                            cout << "[2] : Sprawdz czy odcinki sa prostopadle." << endl;
                            cout << "[3] : Sprawdz czy odcinki sie przecinaja." << endl;
                            cout << "[0] : Wroc do poprzedniego menu." << endl << "odp : ";
                            cin  >> odp;

                            if(odp == 0) break;
                            switch(odp)
                            {
                                case 1 :
                                    if(rownolegle(odcinek1, odcinek2))
                                        cout << "Odcinki sa rownolegle." << endl;
                                    else
                                        cout << "Odcinki nie sa rownolegle." << endl;
                                    break;
                                case 2 :
                                    if(prostopadle(odcinek1, odcinek2))
                                        cout << "Odcinki sa prostopadle." << endl;
                                    else
                                        cout << "Odcinki nie sa prostopadle." << endl;
                                    break;
                                case 3 :
                                    if(przeciecie(odcinek1, odcinek2))
                                        cout << "Odcinki sie przecinaja." << endl;
                                    else
                                        cout << "Odcinki sie nie przecinaja." << endl;
                            }
                        }
                        break;
                    }
            }
        }
    }
    return 0;
}
