#include<iostream>
#include<cmath>
#include "LZespolona.hh"

using std::cout;
using std::cin;


/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona operator - (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona operator * (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = (Skl1.re * Skl2.re) - (Skl1.im * Skl2.im);
  Wynik.im = (Skl1.re * Skl2.im) + (Skl1.im + Skl2.re);
  return Wynik;
}

LZespolona sprzezenie (LZespolona Skl1)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re;
  Wynik.im = -Skl1.im;
  return Wynik;
}

LZespolona modul (LZespolona Skl1)
{
  LZespolona wynik;

  wynik.re = pow(pow(Skl1.re, 2) + pow(Skl1.im, 2), 0.5);
  wynik.im = 0
  return wynik;
}


LZespolona operator / (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  LZespolona modul = modul(Skl2);
  LZespolona sprzezenie = sprzezenie(Skl2);
  LZespolona licznik = Skl1 * sprzezenie

  Wynik.re = licznik.re/(modul.re * modul.re);
  Wynik.im = licznik.im/(modul.re * modul.re);
  return Wynik;
}

LZespolona utworz(double re, double im)
{
  LZespolona Z;
  Z.re = re;
  Z.im = im;
  return Z;
}

void wyswietl(LZespolona Z)
{
  cout<<"("<<Z.re<<std::showpos<<Z.im<<std::noshowpos<<"i)"<<std::endl;
}

std::istream & operator >> (std::istream & strm, LZespolona &Z1)
{
  char znak;
  strm>>znak;
  if(znak!='(')
    strm.setstate(std::ios::failbit);
  strm>>Z1.re;
  strm>>znak;
  strm>>Z1.im;
  if(znak=='-')
    Z1.im=(-Z1.im);
  strm>>znak;
  if(znak!='i')
    strm.setstate(std::ios::failbit);
    strm>>znak;
  if(znak!=')')
    strm.setstate(std::ios::failbit);
}