#ifndef LIBRERIA_TEXTO_H
#define LIBRERIA_TEXTO_H
#include "Libro.h"
#include "Fecha.h"

class Texto : public Libro
{
    public:
        Texto(unsigned long long isbn, const std::string& titulo,const std::string& editorial, float precioBase, const std::string& materia, const Fecha& fechaPublicado);
        std::string tipo() const override;
        float precioVenta() const override;
        std::string detalle() const override;
    private:
        std::string materia;
        Fecha fechaPublicado;
};

#endif
