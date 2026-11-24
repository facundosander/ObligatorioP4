#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <string>


class Fecha
{
public:
    Fecha(int d, int m, int a);
    static bool esValida(int d, int m, int a);
    bool anteriorA(const Fecha& otra) const;
    std::string comoTexto() const;

private:
    int dia;
    int mes;
    int anio;
};


#endif // FECHA_H_INCLUDED
