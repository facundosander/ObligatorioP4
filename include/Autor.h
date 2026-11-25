#ifndef LIBRERIA_AUTOR_H
#define LIBRERIA_AUTOR_H
#include "Objeto.h"
#include <string>

class Autor : public Objeto
{
    public:
        Autor(int cedula, const std::string& nombre,const std::string& apellido);
        int obtenerCedula() const;
        std::string obtenerNombre() const;
        std::string obtenerApellido() const;
    private:
        int cedula;
        std::string nombre;
        std::string apellido;
};

#endif
