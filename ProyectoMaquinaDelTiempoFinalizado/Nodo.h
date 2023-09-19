#ifndef NODO_H
#define NODO_H

#include <string>

class Nodo {
public:
    int datosRandom;
    int datos;
    std::string cientifico;
    Nodo* PtrPasado;
    Nodo* PtrFuturo;

    Nodo(int datos, int cientifico, int datosRandom);
};

#endif // NODO_H
