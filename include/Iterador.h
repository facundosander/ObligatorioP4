#ifndef LIBRERIA_ITERADOR_H
#define LIBRERIA_ITERADOR_H

class Objeto;

class Iterador
{
    public:
        Iterador();
        ~Iterador();
        Iterador(const Iterador&) = delete;
        Iterador& operator=(const Iterador&) = delete;

        void agregar(const Objeto& dato);
        void vaciar();
        void reiniciar();
        bool hayActual() const;
        const Objeto& actual() const;
        void avanzar();
    private:
        struct Nodo
        {
            const Objeto* dato;
            Nodo* sig;
        };
        Nodo* ini = nullptr;
        Nodo* fin = nullptr;
        Nodo* cursor = nullptr;
};

#endif
