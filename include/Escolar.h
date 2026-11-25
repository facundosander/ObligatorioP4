#ifndef LIBRERIA_ESCOLAR_H
#define LIBRERIA_ESCOLAR_H
#include "Texto.h"

class Escolar : public Texto
{
    public:
        Escolar(unsigned long long isbn, const std::string& titulo,const std::string& editorial, float precioBase, const std::string& materia, const Fecha& fechaPublicado, int anioEscuela);
        std::string tipo() const override;
        float precioVenta() const override;
        std::string detalle() const override;
    private:
        int anioEscuela;
};


#endif
