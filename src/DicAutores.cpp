#include "DicAutores.h"

DicAutores::DicAutores() : abb(nullptr)
{
}

DicAutores::~DicAutores()
{
    liberar(abb);
}

void DicAutores::liberar(Nodo* nodo)
{
    if (nodo != nullptr)
    {
        liberar(nodo->izq);
        liberar(nodo->der);
        delete nodo->autor;
        delete nodo;
    }
}

Autor* DicAutores::buscar(int ci) const
{
    Nodo* actual = abb;
    while (actual != nullptr)
    {
        int clave = actual->autor->obtenerCedula();
        if (ci == clave)
            return actual->autor;
        if (ci < clave)
            actual = actual->izq;
        else
            actual = actual->der;
    }
    return nullptr;
}

bool DicAutores::insertar(Autor* autor)
{
    if (autor == nullptr)
        return false;

    return insertarEnArbol(abb, autor);
}

bool DicAutores::insertarEnArbol(Nodo*& nodo, Autor* autor)
{
    if (nodo == nullptr)
    {
        nodo = new Nodo;
        nodo->autor = autor;
        nodo->izq = nullptr;
        nodo->der = nullptr;
        return true;
    }

    int ci = autor->obtenerCedula();
    int clave = nodo->autor->obtenerCedula();
    if (ci == clave)
        return false;
    if (ci < clave)
        return insertarEnArbol(nodo->izq, autor);
    return insertarEnArbol(nodo->der, autor);
}

void DicAutores::listar(Iterador& salida) const
{
    listarEnOrden(abb, salida);
}

void DicAutores::listarEnOrden(Nodo* nodo, Iterador& salida) const
{
    if (nodo != nullptr)
    {
        listarEnOrden(nodo->izq, salida);
        salida.insertar(nodo->autor);
        listarEnOrden(nodo->der, salida);
    }
}
