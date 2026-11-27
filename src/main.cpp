#include "Fachada.h"
#include <iostream>

using namespace std;

bool numeroValido()
{
    bool valido = !cin.fail();
    if (!valido)
    {
        if (cin.eof())
            return false;
        cin.clear(); 
    }

    string resto;
    if (!cin.eof())
        getline(cin, resto);
    for (unsigned i = 0; i < resto.size(); i++)
        if (resto[i] != ' ' && resto[i] != '\t' && resto[i] != '\r')
            valido = false;

    if (!valido)
        cout << "Ingresa un numero valido. Para decimales usa punto.\n";
    return valido;
}

int leerEntero(const char* pregunta)
{
    int valor = 0;
    do
    {
        cout << pregunta;
        cin >> valor;
    } while (!numeroValido() && cin);
    return valor;
}

float leerPrecio(const char* pregunta)
{
    float valor = 0;
    do
    {
        cout << pregunta;
        cin >> valor;
    } while (!numeroValido() && cin);
    return valor;
}

ISBN leerISBN()
{
    ISBN isbn = 0;
    while (cin)
    {
        cout << "ISBN: ";
        cin >> ws;
        if (cin.peek() == '-')
        {
            string linea;
            getline(cin, linea);
            cout << "El ISBN debe ser un numero sin signo.\n";
        }
        else
        {
            cin >> isbn;
            if (numeroValido())
                return isbn;
        }
    }
    return 0;
}

string leerTexto(const char* pregunta)
{
    string texto;
    cout << pregunta;
    getline(cin, texto);
    return texto;
}

void altaLibro(Fachada& fachada)
{
    int tipo = leerEntero("Tipo (1 novela, 2 texto comun, 3 escolar): ");
    if (!cin)
        return;
    if (tipo < 1 || tipo > 3)
    {
        cout << "Tipo de libro incorrecto.\n";
        return;
    }

    ISBN isbn = leerISBN();
    string titulo = leerTexto("Titulo: ");
    string editorial = leerTexto("Editorial: ");
    float base = leerPrecio("Precio base: ");
    if (!cin)
        return;
    if (base < 0)
    {
        cout << "El precio base debe ser cero o mayor.\n";
        return;
    }

    tipoError error;
    if (tipo == 1)
    {
        string genero = leerTexto("Genero (para el descuento ingresa infantil): ");
        if (!cin)
            return;
        fachada.registrarNovela(isbn, titulo, editorial, base, genero, error);
    }
    else
    {
        string materia = leerTexto("Materia: ");
        int dia = leerEntero("Dia de publicacion: ");
        int mes = leerEntero("Mes: ");
        int anio = leerEntero("Anio: ");
        if (!cin)
            return;
        if (tipo == 2)
            fachada.registrarTexto(isbn, titulo, editorial, base, materia, dia, mes, anio, error);
        else
        {
            int grado = leerEntero("Anio escolar: ");
            if (!cin)
                return;
            fachada.registrarEscolar(isbn, titulo, editorial, base, materia, dia, mes, anio, grado, error);
        }
    }

    if (error == "")
        cout << "Libro registrado.\n";
    else
        cout << error << '\n';
}

void mostrarMenu()
{
    cout << "\nLIBRERIA\n1. Registrar autor\n2. Registrar libro\n"
         << "3. Asociar autor a novela\n4. Listar libros por comienzo del titulo\n"
         << "5. Consultar detalle de libro\n6. Listar autores por cedula\n"
         << "7. Vender un libro\n8. Consultar recaudacion por editorial\n"
         << "9. Consultar unidades vendidas por precio base\n"
         << "10. Consultar el mas vendido de una editorial\n0. Salir\n";
}

int main()
{
    Fachada fachada;
    cout << fixed;
    cout.precision(2);

    while (cin)
    {
        mostrarMenu();
        int opcion = leerEntero("Opcion: ");
        if (!cin || opcion == 0)
            break;

        tipoError error;
        ISBN isbn;
        int ci;
        string editorial, detalle;
        switch (opcion)
        {
            case 1:
            {
                ci = leerEntero("Cedula: ");
                string nombre = leerTexto("Nombre: ");
                string apellido = leerTexto("Apellido: ");
                if (!cin)
                    break;
                fachada.registrarAutor(ci, nombre, apellido, error);
                if (error == "")
                    cout << "Autor registrado.\n";
                break;
            }
            case 2:
                altaLibro(fachada);
                break;
            case 3:
                isbn = leerISBN();
                ci = leerEntero("Cedula del autor: ");
                if (!cin)
                    break;
                fachada.asociarAutor(isbn, ci, error);
                if (error == "")
                    cout << "Autor asociado.\n";
                break;
            case 4:
            {
                string frase = leerTexto("Comienzo del titulo: ");
                if (!cin)
                    break;
                string listado;
                fachada.listarPorPrefijo(frase, listado, error);
                if (error == "")
                    cout << listado;
                break;
            }
            case 5:
                isbn = leerISBN();
                if (!cin)
                    break;
                fachada.consultarDetalle(isbn, detalle, error);
                if (error == "")
                    cout << detalle << '\n';
                break;
            case 6:
            {
                string listado;
                fachada.listarAutores(listado, error);
                if (error == "")
                    cout << listado;
                break;
            }
            case 7:
            {
                float importe;
                isbn = leerISBN();
                if (!cin)
                    break;
                fachada.vender(isbn, importe, error);
                if (error == "")
                    cout << "Importe de la venta: " << importe << '\n';
                break;
            }
            case 8:
                editorial = leerTexto("Editorial: ");
                if (!cin)
                    break;
                cout << "Total recaudado: " << fachada.recaudacion(editorial) << '\n';
                break;
            case 9:
            {
                float umbral = leerPrecio("Precio base a superar: ");
                int novelas, textos, escolares;
                if (!cin)
                    break;
                fachada.ventasSobre(umbral, novelas, textos, escolares);
                cout << "Novelas: " << novelas << " | Textos comunes: " << textos
                     << " | Escolares: " << escolares << '\n';
                break;
            }
            case 10:
                editorial = leerTexto("Editorial: ");
                if (!cin)
                    break;
                fachada.masVendido(editorial, detalle, error);
                if (error == "")
                    cout << detalle << '\n';
                break;
            default:
                cout << "Opcion incorrecta.\n";
        }
        if (error != "")
            cout << error << '\n';
    }
    return 0;
}
