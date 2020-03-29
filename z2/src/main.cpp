#include <iostream>
#include "BazaTestu.hh"
#include "LZespolona.hh"
#include "Statystyki.hh"
#include "WyrazenieZesp.hh"

using namespace std;




int main(int argc, char **argv)
{
  LZespolona OdpoUzytkownika, Poprawna;

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  statystyki stats;
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << " Oblicz: ";
    cout << WyrZ_PytanieTestowe << endl;
    stats.IloscPytan++;

    Poprawna = Oblicz(WyrZ_PytanieTestowe);
    cout << Poprawna<< endl;
    cout <<" Twoja odpowiedz: ";

    for(int i=0; i<3; i++)
    {
      cin >> OdpoUzytkownika;
      if(!cin.good())
      {
        cout << endl << " Blad. Sprobuj ponownie" << endl;
        cin.clear();
        cin.ignore(1000,'\n');
        cout <<" Twoja odpowiedz: ";
      }
      else break;
    }

    if (OdpoUzytkownika == Oblicz(WyrZ_PytanieTestowe))
    {
      stats.DobrychOdpo++;
      cout << " Odpowiedz poprawna" << endl;
    }
    else
    {
      cerr<<" Blad. Prawidlowy wynik to:" << Oblicz(WyrZ_PytanieTestowe) << endl;
    }
  }

  cout << " Ilosc dobrych odpowiedzi: " << stats.DobrychOdpo << "/" << stats.IloscPytan << endl;
  cout << " Wynik procentowy testu:" << ObliczProcent(stats) << "%" << endl;

  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
}
