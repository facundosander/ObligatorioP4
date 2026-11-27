#ifndef LIBRERIA_DICAUTORES_H
#define LIBRERIA_DICAUTORES_H

#include "Autor.h"
#include "Iterador.h"

class DicAutores
{
public:
    DicAutores();
    ~DicAutores();
    Autor* buscar(int ci) const;
    bool insertar(Autor* autor);
    void listar(Iterador& salida) const;

private:
    struct Nodo
    {
        Autor* autor;
        Nodo* izq;
        Nodo* der;
    };
    Nodo* abb;
    bool insertarEnArbol(Nodo*& nodo, Autor* autor);
    void listarEnOrden(Nodo* nodo, Iterador& salida) const;
    void liberar(Nodo* nodo);
};

#endif
