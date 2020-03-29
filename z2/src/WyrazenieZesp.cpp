#include<iostream>
#include "WyrazenieZesp.hh"

using std::cout;

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */



std::ostream & operator << (std::ostream & Strm, const WyrazenieZesp & WyrZ)
{
    Strm<<WyrZ.Arg1;
    switch(WyrZ.Op)
    {
    case 0 : Strm<<"+" ; break;
    case 1 : Strm<<"-" ; break;
    case 2 : Strm<<"*" ; break;
    case 3 : Strm<<"/" ; break;
    } 
    Strm<<WyrZ.Arg2;
}

LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
  LZespolona Wynik;
    switch (WyrZ.Op)
    {
        case 0: 
        Wynik = WyrZ.Arg1 + WyrZ.Arg2;
        break;

        case 1:
        Wynik = WyrZ.Arg1 - WyrZ.Arg2;
        break;

        case 2:
        Wynik = WyrZ.Arg1 * WyrZ.Arg2;
        break;

        case 3:
        Wynik = WyrZ.Arg1 / WyrZ.Arg2;
        break;
    }
  return Wynik;
}


std::istream & operator >> (std::istream & Strm, WyrazenieZesp & wyraz) 
{
  char znak;
  Strm >> wyraz.Arg1 >> znak >> wyraz.Arg2;
  switch(znak)
  {
    case '+':wyraz.Op = Op_Dodaj; break;
    case '-':wyraz.Op = Op_Odejmij; break;
    case '*':wyraz.Op = Op_Mnoz; break;
    case '/':wyraz.Op = Op_Dziel; break;
  }
}

/*std::istream & operator >> (std::istream & strm, Operator & Op) 
{
  char znak;
  strm >> znak;
    switch (znak) {
    case '+':wyraz.Op = Op_Dodaj; break;
    case '-':wyraz.Op = Op_Odejmij; break;
    case '*':wyraz.Op = Op_Mnoz; break;
    case '/':wyraz.Op = Op_Dziel; break;
  }
}*/