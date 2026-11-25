#include "Libro.h"

#include <iomanip>
#include <sstream>

Libro::Libro(unsigned long long isbn, const std::string& titulo, const std::string& editorial, float precioBase)
: isbn(isbn), titulo(titulo), editorial(editorial), precioBase(precioBase)
{
}

unsigned long long Libro::obtenerISBN() const
{
    return isbn;
}

std::string Libro::obtenerTitulo() const
{
    return titulo;
}

std::string Libro::obtenerEditorial() const
{
    return editorial;
}

float Libro::obtenerPrecioBase() const
{
    return precioBase;
} 

int Libro::obtenerUnidadesVendidas() const
{
    return unidadesVendidas;
}

void Libro::registrarVenta()
{
    unidadesVendidas ++;
}

std::string Libro::detalle() const
{
    return "ISBN: " + std::to_string(isbn) + "\n"
         + "Titulo: " + titulo + "\n"
         + "Editorial: " + editorial + "\n"
         + "Precio base: " + std::to_string(precioBase) + "\n"
         + "Unidades vendidas: " + std::to_string(unidadesVendidas) + "\n"
         + "Tipo: " + tipo();
}