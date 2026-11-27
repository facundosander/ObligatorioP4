#include "DicLibros.h"

DicLibros::DicLibros()
{
    for (int i = 0; i < TAM; i++)
        hash[i] = nullptr;
}

DicLibros::~DicLibros()
{
    for (int i = 0; i < TAM; i++)
    {
        while (hash[i] != nullptr)
        {
            Nodo* borrar = hash[i];
            hash[i] = borrar->sig;
            delete borrar->libro;
            delete borrar;
        }
    }
}

Libro* DicLibros::buscar(ISBN isbn) const
{
    for (Nodo* nodo = hash[isbn % TAM]; nodo != nullptr; nodo = nodo->sig)
    {
        if (nodo->libro->obtenerISBN() == isbn)
            return nodo->libro;
    }
    return nullptr;
}

bool DicLibros::insertar(Libro* libro)
{
    if (libro == nullptr || buscar(libro->obtenerISBN()) != nullptr)
        return false;

    int posicion = libro->obtenerISBN() % TAM;
    Nodo* nuevo = new Nodo;
    nuevo->libro = libro;
    nuevo->sig = hash[posicion];
    hash[posicion] = nuevo;
    return true;
}

void DicLibros::listarPorPrefijo(const std::string& frase, Iterador& salida) const
{
    for (int i = 0; i < TAM; i++)
    {
        for (Nodo* nodo = hash[i]; nodo != nullptr; nodo = nodo->sig)
        {
            std::string titulo = nodo->libro->obtenerTitulo();
            if (titulo.substr(0, frase.size()) == frase)
                salida.insertar(nodo->libro);
        }
    }
}

float DicLibros::recaudacion(const std::string& editorial) const
{
    float total = 0;
    for (int i = 0; i < TAM; i++)
    {
        for (Nodo* nodo = hash[i]; nodo != nullptr; nodo = nodo->sig)
        {
            Libro* libro = nodo->libro;
            if (libro->obtenerEditorial() == editorial)
                total += libro->precioVenta() * libro->obtenerUnidadesVendidas();
        }
    }
    return total;
}

void DicLibros::ventasSobre(float umbral, int& novelas, int& textos, int& escolares) const
{
    novelas = 0;
    textos = 0;
    escolares = 0;
    for (int i = 0; i < TAM; i++)
    {
        for (Nodo* nodo = hash[i]; nodo != nullptr; nodo = nodo->sig)
        {
            Libro* libro = nodo->libro;
            if (libro->obtenerPrecioBase() > umbral)
            {
                int unidades = libro->obtenerUnidadesVendidas();
                std::string tipo = libro->tipo();
                if (tipo == "novela")
                    novelas += unidades;
                else if (tipo == "escolar")
                    escolares += unidades;
                else
                    textos += unidades;
            }
        }
    }
}

Libro* DicLibros::masVendido(const std::string& editorial) const
{
    Libro* mejor = nullptr;
    for (int i = 0; i < TAM; i++)
    {
        for (Nodo* nodo = hash[i]; nodo != nullptr; nodo = nodo->sig)
        {
            Libro* libro = nodo->libro;
            if (libro->obtenerEditorial() == editorial &&
                (mejor == nullptr || libro->obtenerUnidadesVendidas() > mejor->obtenerUnidadesVendidas()))
                mejor = libro;
        }
    }
    return mejor;
}
