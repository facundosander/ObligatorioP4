#include "Iterador.h"

Iterador::Iterador()
{
    ini = nullptr;
    fin = nullptr;
    cursor = nullptr;
}

Iterador::~Iterador()
{
    while (ini != nullptr)
    {
        Nodo* nodo = ini;
        ini = ini->sig;
        delete nodo;
    }
}

void Iterador::insertar(const Objeto* dato)
{
    Nodo* nuevo = new Nodo;
    nuevo->dato = dato;
    nuevo->sig = nullptr;

    if (fin == nullptr)
    {
        ini = nuevo;
        cursor = nuevo;
    }
    else
    {
        fin->sig = nuevo;
    }

    fin = nuevo;
}

bool Iterador::hayMasObjetos() const
{
    return cursor != nullptr;
}

const Objeto* Iterador::proximoObjeto()
{
    const Objeto* dato = cursor->dato;
    cursor = cursor->sig;
    return dato;
}
