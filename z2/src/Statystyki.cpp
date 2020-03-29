#include<iostream>
#include "Statystyki.hh"

double ObliczProcent(statystyki stats)
{
    double Procent;

    Procent = (stats.DobrychOdpo*100)/stats.IloscPytan;

    return Procent;
}