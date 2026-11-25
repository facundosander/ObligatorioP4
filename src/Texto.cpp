#include "Texto.h"

Texto::Texto(unsigned long long isbn, const std::string& titulo,const std::string& editorial, float precioBase, const std::string& materia, const Fecha& fechaPublicado)
:   Libro(isbn, titulo, editorial, precioBase), materia(materia), fechaPublicado(fechaPublicado)
{
}

std::string Texto::tipo() const
{
    return "texto";
}

float Texto::precioVenta() const
{
    float total = obtenerPrecioBase();
    const Fecha fecha(1,1,2026);
    if (fechaPublicado.anteriorA(fecha))
    {
        total = total * 0.75;
    }
    return total;
}

std::string Texto::detalle() const
{
    std::string texto = Libro::detalle();
    texto = texto + "\nmateria: " + materia;
    texto = texto + "\nFecha publicado: " + fechaPublicado.comoTexto();
    return texto;
}