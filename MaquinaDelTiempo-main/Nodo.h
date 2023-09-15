#ifndef MAQUINADELTIEMPO_NODO_H
#define MAQUINADELTIEMPO_NODO_H

#include <string>

class Nodo {
public:

    int datos;
    static std::string cientifico;
    Nodo *PtrPasado;
    Nodo *PtrFuturo;

    //Constructor
    Nodo (int datos, const std::string cientifico);

    //Destructor
    ~Nodo();


};


#endif //MAQUINADELTIEMPO_NODO_H
