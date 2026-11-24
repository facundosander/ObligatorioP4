#ifndef LIBRERIA_LIBRO_H
#define LIBRERIA_LIBRO_H

#include <string>

class Libro
{
public:
    virtual ~Libro() = default;

    unsigned long long obtenerISBN() const;
    std::string obtenerTitulo() const;
    std::string obtenerEditorial() const;
    float obtenerPrecioBase() const;
    int obtenerUnidadesVendidas() const;
    void registrarVenta();

    virtual std::string tipo() const = 0;
    virtual float precioVenta() const = 0;

    virtual std::string detalle() const;

protected:
    Libro(unsigned long long isbn, const std::string& titulo,
          const std::string& editorial, float precioBase);

private:
    unsigned long long isbn;
    std::string titulo;
    std::string editorial;
    float precioBase;
    int unidadesVendidas = 0;
};

#endif
