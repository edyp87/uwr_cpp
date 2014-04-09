/* Marek Jenda
 * nazwa programu: kurs_cpp_zad1
 * nazwa modulu: zad1.cpp
 * 12-02-10 12:29:00:00
 */

#include "zad1.hpp"

//----- definicje klasy Punkt2D ------------

punkt2D::punkt2D(const double pktX, const double pktY)
{
    x = pktX;
    y = pktY;
}

double punkt2D::pobierzX()
{
    return x;
}

double punkt2D::pobierzY()
{
    return y;
}

void punkt2D::wyswietlXY()
{
    cout << "Wspolrzedne (x, y): (" << x << ", " << y << ").\n";
}

//----- definicje klasy Odcinek2D ----------

odcinek2D::odcinek2D(punkt2D pkt1, punkt2D pkt2)
{
    x1 = pkt1.pobierzX();
    y1 = pkt1.pobierzY();
    x2 = pkt2.pobierzX();
    y2 = pkt2.pobierzY();
}

void odcinek2D::przesun0X(const double dys)
{
    x1 += dys;
    x2 += dys;
    return;
}

void odcinek2D::przesun0Y(const double dys)
{
    y1 += dys;
    y2 += dys;
    return;
}

void odcinek2D::wyswietl_wspol()
{
    cout << "(x1, y1) <--> (x2, y2): (";
    cout << x1 << ", " << y1 << ") <--> (";
    cout << x2 << ", " << y2 << ").\n";
    return;
}

 bool odcinek2D::czy_na_odc(punkt2D pkt)
 {
     return((pkt.pobierzX() - x1) * (y2 - y1) == (pkt.pobierzY() - y1) * (x2 - x1));
 }

//-------- funkcje globalne ----------------

bool przeciecie(odcinek2D odc1, odcinek2D odc2)
{
    double t1, t2;

    t1 = (((odc2.x2 - odc2.x1) * (odc1.y1 - odc2.y1) - (odc2.y2 - odc2.y1) * (odc1.x1 = odc2.x1)) /
          ((odc2.y2 - odc2.y1) * (odc1.x2 - odc1.x1) - (odc2.x2 - odc2.x1) * (odc1.y2 - odc1.y1)));
    t2 = (((odc1.x2 - odc1.x1) * (odc1.y1 - odc2.y1) - (odc1.y2 - odc1.y1) * (odc1.x1 = odc2.x1)) /
          ((odc2.y2 - odc2.y1) * (odc1.x2 - odc1.x1) - (odc2.x2 - odc2.x1) * (odc1.y2 - odc1.y1)));
    return (t1 >= 0 && t1 <= 1) && (t2 >= 0 && t2 <=1);
}

bool rownolegle(odcinek2D odc1, odcinek2D odc2)
{
    return ((odc1.y2 - odc1.y1) / (odc1.x2 - odc1.x1)
    == (odc2.y2 - odc2.y1) / (odc2.x2 - odc2.x1));
}

bool prostopadle(odcinek2D odc1, odcinek2D odc2)
{
    return ((odc1.y2 - odc1.y1) / (odc1.x2 - odc1.x1)
         == (odc2.x1 - odc2.x2) / (odc2.y2 - odc2.y1));
}

