#ifndef LIBRERIA_LISTABLE_H
#define LIBRERIA_LISTABLE_H

#include <string>

class Listable
{
public:
    virtual ~Listable() = default;
    virtual std::string lineaListado() const = 0;
};

#endif
