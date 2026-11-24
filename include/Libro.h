#ifndef LIBRERIA_LIBRO_H
#define LIBRERIA_LIBRO_H

#include "Listable.h"

#include <string>

class Libro : public Listable
{
public:
    ~Libro() override = default;

    unsigned long long obtenerISBN() const;
    std::string obtenerTitulo() const;
    std::string obtenerEditorial() const;
    float obtenerPrecioBase() const;
    int obtenerUnidadesVendidas() const;
    void registrarVenta();

    // Cada subtipo indica su nombre y calcula su precio de venta.
    virtual std::string tipo() const = 0;
    virtual float precioVenta() const = 0;

    std::string lineaListado() const override;
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
