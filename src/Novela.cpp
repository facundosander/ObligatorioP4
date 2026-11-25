#include "Novela.h"

Novela::Novela(unsigned long long isbn, const std::string& titulo, const std::string& editorial, float precioBase, const std::string& genero)
: Libro(isbn, titulo, editorial, precioBase), genero(genero)
{
}

void Novela::asociarAutor(const Autor& autor)
{
    this->autor = &autor;
}

std::string Novela::tipo() const
{
    return "novela";
}

float Novela::precioVenta() const
{
    float total = obtenerPrecioBase();
    if (genero == "infantil")
    {
        total = total * 0.80;
    }
    return total;
}

std::string Novela::detalle() const
{
    std::string texto = Libro::detalle();
    texto = texto + "\nGenero: " + genero;
    return texto;
}
