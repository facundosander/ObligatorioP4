#include "Iterador.h"

Iterador::Iterador() = default;

Iterador::~Iterador()
{
    vaciar();
}

void Iterador::agregar(const Objeto& dato)
{
    Nodo* nuevo = new Nodo{&dato, nullptr};

    if (fin == nullptr)
    {
        ini = nuevo;
    }
    else
    {
        fin->sig = nuevo;
    }

    fin = nuevo;
}

void Iterador::vaciar()
{
    while (ini != nullptr)
    {
        Nodo* nodo = ini;
        ini = ini->sig;
        delete nodo;
    }

    fin = nullptr;
    cursor = nullptr;
}

void Iterador::reiniciar()
{
    cursor = ini;
}

bool Iterador::hayActual() const
{
    return cursor != nullptr;
}

const Objeto& Iterador::actual() const
{
    return *cursor->dato;
}

void Iterador::avanzar()
{
    cursor = cursor->sig;
}
