#include "Fachada.h"
#include "Novela.h"
#include "Escolar.h"

void Fachada::registrarAutor(int ci, const std::string& nombre, const std::string& apellido, tipoError& error)
{
    error = "";
    if (autores.buscar(ci) != nullptr)
    {
        error = "Ya existe un autor con esa cedula.";
        return;
    }
    autores.insertar(new Autor(ci, nombre, apellido));
}

void Fachada::validarAltaLibro(ISBN isbn, float base, tipoError& error) const
{
    error = "";
    if (libros.buscar(isbn) != nullptr)
        error = "Ya existe un libro con ese ISBN.";
    else if (base < 0)
        error = "El precio base debe ser cero o mayor.";
}

void Fachada::registrarNovela(ISBN isbn, const std::string& titulo, const std::string& editorial, float base,
                         const std::string& genero, tipoError& error)
{
    validarAltaLibro(isbn, base, error);
    if (error != "")
        return;

    libros.insertar(new Novela(isbn, titulo, editorial, base, genero));
}

void Fachada::registrarTexto(ISBN isbn, const std::string& titulo, const std::string& editorial, float base,
                        const std::string& materia, int dia, int mes, int anio, tipoError& error)
{
    validarAltaLibro(isbn, base, error);
    if (error != "")
        return;

    if (!Fecha::esValida(dia, mes, anio))
    {
        error = "Fecha de publicacion invalida.";
        return;
    }
    Fecha fecha(dia, mes, anio);
    libros.insertar(new Texto(isbn, titulo, editorial, base, materia, fecha));
}

void Fachada::registrarEscolar(ISBN isbn, const std::string& titulo, const std::string& editorial, float base,
                          const std::string& materia, int dia, int mes, int anio, int grado, tipoError& error)
{
    validarAltaLibro(isbn, base, error);
    if (error != "")
        return;

    if (!Fecha::esValida(dia, mes, anio))
    {
        error = "Fecha de publicacion invalida.";
        return;
    }
    if (grado < 1)
    {
        error = "El anio escolar debe ser positivo.";
        return;
    }
    Fecha fecha(dia, mes, anio);
    libros.insertar(new Escolar(isbn, titulo, editorial, base, materia, fecha, grado));
}

void Fachada::asociarAutor(ISBN isbn, int ci, tipoError& error)
{
    error = "";
    Libro* libro = libros.buscar(isbn);
    if (libro == nullptr)
    {
        error = "No existe un libro con ese ISBN.";
        return;
    }

    if (libro->tipo() != "novela")
    {
        error = "El libro indicado no es una novela.";
        return;
    }

    Autor* autor = autores.buscar(ci);
    if (autor == nullptr)
        error = "No existe un autor con esa cedula.";
    else
    {
        Novela* novela = (Novela*) libro;
        novela->asociarAutor(*autor);
    }
}

void Fachada::listarPorPrefijo(const std::string& frase, std::string& salida, tipoError& error) const
{
    error = "";
    salida = "";
    Iterador iter;
    libros.listarPorPrefijo(frase, iter);
    if (!iter.hayMasObjetos())
        error = "Ningun titulo comienza con esa frase.";
    while (iter.hayMasObjetos())
    {
        const Libro* libro = (const Libro*) iter.proximoObjeto();
        salida += std::to_string(libro->obtenerISBN()) + " | " + libro->obtenerTitulo()
                + " | " + libro->tipo() + "\n";
    }
}

void Fachada::consultarDetalle(ISBN isbn, std::string& salida, tipoError& error) const
{
    error = "";
    Libro* libro = libros.buscar(isbn);
    if (libro == nullptr)
        error = "No existe un libro con ese ISBN.";
    else
        salida = libro->detalle();
}

void Fachada::listarAutores(std::string& salida, tipoError& error) const
{
    error = "";
    salida = "";
    Iterador iter;
    autores.listar(iter);
    if (!iter.hayMasObjetos())
        error = "No hay autores registrados.";
    while (iter.hayMasObjetos())
    {
        const Autor* autor = (const Autor*) iter.proximoObjeto();
        salida += std::to_string(autor->obtenerCedula()) + " | " + autor->obtenerNombre()
                + " | " + autor->obtenerApellido() + "\n";
    }
}

void Fachada::vender(ISBN isbn, float& importe, tipoError& error)
{
    error = "";
    Libro* libro = libros.buscar(isbn);
    if (libro == nullptr)
        error = "No existe un libro con ese ISBN.";
    else
    {
        libro->registrarVenta();
        importe = libro->precioVenta();
    }
}

float Fachada::recaudacion(const std::string& editorial) const
{
    return libros.recaudacion(editorial);
}

void Fachada::ventasSobre(float umbral, int& novelas, int& textos, int& escolares) const
{
    libros.ventasSobre(umbral, novelas, textos, escolares);
}

void Fachada::masVendido(const std::string& editorial, std::string& detalle, tipoError& error) const
{
    error = "";
    Libro* libro = libros.masVendido(editorial);
    if (libro == nullptr)
        error = "No hay libros de esa editorial.";
    else
        detalle = libro->detalle();
}
