#ifndef LIBRERIA_NOVELA_H
#define LIBRERIA_NOVELA_H
#include "Libro.h"

class Autor;

class Novela : public Libro
{
    public:
        Novela(unsigned long long isbn, const std::string& titulo, const std::string& editorial, float precioBase, const std::string& genero);
        void asociarAutor(const Autor& autor);
        std::string tipo() const override;
        float precioVenta() const override;
        std::string detalle() const override;
    private:
        std::string genero;
        const Autor* autor = nullptr;
};

#endif
