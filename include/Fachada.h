#ifndef LIBRERIA_FACHADA_H
#define LIBRERIA_FACHADA_H

#include "DicAutores.h"
#include "DicLibros.h"

class Fachada
{
public:
    void registrarAutor(int ci, const std::string& nombre, const std::string& apellido, tipoError& error);
    void registrarNovela(ISBN isbn, const std::string& titulo, const std::string& editorial, float base,
                         const std::string& genero, tipoError& error);
    void registrarTexto(ISBN isbn, const std::string& titulo, const std::string& editorial, float base,
                        const std::string& materia, int dia, int mes, int anio, tipoError& error);
    void registrarEscolar(ISBN isbn, const std::string& titulo, const std::string& editorial, float base,
                          const std::string& materia, int dia, int mes, int anio, int grado, tipoError& error);
    void asociarAutor(ISBN isbn, int ci, tipoError& error);
    void listarPorPrefijo(const std::string& frase, std::string& salida, tipoError& error) const;
    void consultarDetalle(ISBN isbn, std::string& salida, tipoError& error) const;
    void listarAutores(std::string& salida, tipoError& error) const;
    void vender(ISBN isbn, float& importe, tipoError& error);
    float recaudacion(const std::string& editorial) const;
    void ventasSobre(float umbral, int& novelas, int& textos, int& escolares) const;
    void masVendido(const std::string& editorial, std::string& detalle, tipoError& error) const;

private:
    DicAutores autores;
    DicLibros libros;
    void validarAltaLibro(ISBN isbn, float base, tipoError& error) const;
};

#endif
