#include<iostream>
#include "WyrazenieZesp.hh"

using std::cout;

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
std::ostream & operator << (std::ostream & strm, WyrazenieZesp  WyrZ)
{
    cout << WyrazenieZesp.Arg1 << WyrazenieZesp.Op << WyrazenieZesp.Arg2;
}

LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
    switch (WyrazenieZesp.Op)
    {
        case 0: 
        LZespolona L1 = WyrZ.Arg1 + WyrZ.Arg2;
        break;

        case 1:
        LZespolona L1 = WyrZ.Arg1 - WyrZ.Arg2;
        break;

        case 2:
        LZespolona L1 = WyrZ.Arg1 * WyrZ.Arg2;
        break;

        case 3:
        LZespolona L1 = WyrZ.Arg1 / WyrZ.Arg2;
        break;
    }

}


std::istream & operator >> (std::istream & strm, WyrazenieZesp & wyraz) 
{
  strm >> wyraz.Arg1 >> wyraz.Op >> wyraz.Arg2;
}

std::istream & operator >> (std::istream & strm, Operator & Op) 
{
  char znak;
  strm >> znak;
    switch (znak) {
    case '+':wyraz.Op = Op_Dodaj;
    case '-':wyraz.Op = Op_Odejmij;
    case '*':wyraz.Op = Op_Mnoz;
    case '/':wyraz.Op = Op_Dziel;
  }
}