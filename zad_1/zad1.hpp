/* Marek Jenda
 * nazwa programu: kurs_cpp_zad1
 * nazwa modulu: zad1.hpp
 * 12-02-10 12:29:00:00
 */

#ifndef zad1_hpp
#define zad1_hpp

#include <iostream>
#include <cmath>
using namespace std;

class punkt2D                                          //klasa punktu
{
    private:
        double x, y;                                   //wspolrzedne punktu
    public:
        punkt2D(const double pktX, const double pktY); //konstruktor
        double pobierzX();                             //zwraca punkt x
        double pobierzY();                             //zwraca punkt y
        void wyswietlXY();                             //drukuje wspolrzedna
};

class odcinek2D                                        //klasa odcinka
{
    private:
        double x1, x2, y1, y2;                         //krance odcinka
    public:
        odcinek2D(punkt2D pkt1, punkt2D pkt2);         //konstruktor
        void przesun0X(const double dys);              //przesuwa odcinek o 0X
        void przesun0Y(const double dys);              //przesuwa odcinek o 0Y
        void wyswietl_wspol();                         //wyswietla krance odcinka
        bool czy_na_odc(punkt2D pkt);                  //czy pkt lezy na odcinku?
        friend bool przeciecie(odcinek2D odc1, odcinek2D odc2);
        friend bool rownolegle(odcinek2D odc1, odcinek2D odc2);
        friend bool prostopadle(odcinek2D odc1, odcinek2D odc2);
};

bool przeciecie(odcinek2D odc1, odcinek2D odc2);       //czy odcinki sie przecinaja
bool rownolegle(odcinek2D odc1, odcinek2D odc2);       //czy sa rownolegle
bool prostopadle(odcinek2D odc1, odcinek2D odc2);      //czy prostopadle

#endif //zad1_hpp
