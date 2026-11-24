#include "Fecha.h"
#include <stdio.h>


static bool esBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

static int diasDelMes(int mes, int anio) {
    int dias[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (mes < 1 || mes > 12) {
        return 0;
    }
    if (mes == 2 && esBisiesto(anio)) {
        return 29;
    }
    return dias[mes];
}

Fecha::Fecha(int d, int m, int a)
    : dia(d), mes(m), anio(a)
{
}

std::string Fecha::comoTexto() const
{
    return std::to_string(dia) + "/" +
           std::to_string(mes) + "/" +
           std::to_string(anio);
}

bool Fecha::esValida(int d, int m, int a)
{
    if (a < 1 || m < 1 || m > 12) {
        return false;
    }

    return d >= 1 && d <= diasDelMes(m, a);
}

bool Fecha::anteriorA(const Fecha& otra) const
{
    if (anio != otra.anio) {
        return anio < otra.anio;
    }

    if (mes != otra.mes) {
        return mes < otra.mes;
    }

    return dia < otra.dia;
}