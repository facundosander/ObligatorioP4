#include "Escolar.h"

Escolar::Escolar(unsigned long long isbn, const std::string& titulo,const std::string& editorial, float precioBase, const std::string& materia, const Fecha& fechaPublicado, int anioEscuela)
:   Texto(isbn, titulo, editorial, precioBase, materia, fechaPublicado), anioEscuela(anioEscuela)
{
}

std::string Escolar::tipo() const
{
    return "escolar";
}

float Escolar::precioVenta() const
{
    float total = Texto::precioVenta();
    if (anioEscuela >= 1 && anioEscuela <= 3)
    {
        total = total * 0.90;
    }
    return total;
}

std::string Escolar::detalle() const
{
    std::string texto = Texto::detalle();
    texto = texto + "\naño escolar: " + std::to_string(anioEscuela);
    return texto;
}