#ifndef LIBRERIA_DICLIBROS_H
#define LIBRERIA_DICLIBROS_H

#include "Iterador.h"
#include "Libro.h"
#include "Tipos.h"

const int TAM = 500;

class DicLibros
{
public:
    DicLibros();
    ~DicLibros();
    Libro* buscar(ISBN isbn) const;
    bool insertar(Libro* libro);
    void listarPorPrefijo(const std::string& frase, Iterador& salida) const;
    float recaudacion(const std::string& editorial) const;
    void ventasSobre(float umbral, int& novelas, int& textos, int& escolares) const;
    Libro* masVendido(const std::string& editorial) const;

private:
    struct Nodo
    {
        Libro* libro;
        Nodo* sig;
    };
    Nodo* hash[TAM];
};

#endif
