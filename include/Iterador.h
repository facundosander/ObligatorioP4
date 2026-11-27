#ifndef LIBRERIA_ITERADOR_H
#define LIBRERIA_ITERADOR_H

class Objeto;

class Iterador
{
    public:
        Iterador();
        ~Iterador();
        void insertar(const Objeto* dato);
        bool hayMasObjetos() const;
        const Objeto* proximoObjeto();
    private:
        struct Nodo
        {
            const Objeto* dato;
            Nodo* sig;
        };
        Nodo* ini;
        Nodo* fin;
        Nodo* cursor;
};

#endif
