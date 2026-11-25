#include "Autor.h"

Autor::Autor(int cedula, const std::string& nombre,const std::string& apellido)
:   cedula(cedula), nombre(nombre), apellido(apellido)
{
}

int Autor::obtenerCedula() const{
    return cedula;
}

std::string Autor::obtenerNombre() const{
    return nombre;
}

std::string Autor::obtenerApellido() const{
    return apellido;
}