#include <iostream>
#include "BazaTestu.hh"
#include "LZespolona.hh"
#include "Statystyki.hh"
#include "WyrazenieZesp.hh"

using std::cout;
using std::cin;
using std::endl;


int main(int argc, char **argv)
{
  LZespolona OdpoUzytkownika;

  if (argc < 2) {
    std::cout << std::endl;
    std::cout << " Brak opcji okreslajacej rodzaj testu." << std::endl;
    std::cout << " Dopuszczalne nazwy to:  latwy, trudny." << std::endl;
    std::cout << std::endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    std::cerr << " Inicjalizacja testu nie powiodla sie." << std::endl;
    return 1;
  }


  
  std::cout << std::endl;
  std::cout << " Start testu arytmetyki zespolonej: " << argv[1] << std::endl;
  std::cout << std::endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  statystyki stats;
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    std::cout << " Oblicz: ";
    std::cout << WyrZ_PytanieTestowe << endl;
    stats.IloscPytan++;

    std::cout <<" Twoja odpowiedz: ";

    for(int i=0; i<3; i++)
    {
      std::cin >> OdpoUzytkownika;
      if(!cin.good())
      {
        std::cout << std::endl << " Blad. Sprobuj ponownie" << std::endl;
        cin.clear();
        cin.ignore(1000,'\n');
        std::cout <<" Twoja odpowiedz: ";
      }
      else break;
    }

    if (OdpoUzytkownika == Oblicz(WyrZ_PytanieTestowe))
    {
      stats.DobrychOdpo++;
      std::cout << " Odpowiedz poprawna" << std::endl;
    }
    else
    {
      std::cerr<<" Blad. Prawidlowy wynik to:" << Oblicz(WyrZ_PytanieTestowe) << std::endl;
    }
  }

  std::cout << " Ilosc dobrych odpowiedzi: " << stats.DobrychOdpo << "/" << stats.IloscPytan << std::endl;
  std::cout << " Wynik procentowy testu:" << ObliczProcent(stats) << "%" << std::endl;

  std::cout << std::endl;
  std::cout << " Koniec testu" << std::endl;
  std::cout << std::endl;
}
