#ifndef MAQUINADELTIEMPO_MAQUINADELTIEMPO_H
#define MAQUINADELTIEMPO_MAQUINADELTIEMPO_H

#include "Nodo.h"


class MaquinaDelTiempo {
public:
    Nodo* lista;

    //Constructor
    MaquinaDelTiempo();

    //Destructor
    ~MaquinaDelTiempo();

    //Función para crear envento A
    Nodo* crearEventoA();
    //Función para crear envento B
    Nodo* crearEventoB(Nodo* eventoA);
    //Función para crear envento C
    Nodo* crearEventoC(Nodo* eventoB);

    //Imprimir lista
    void imprimirLista();

    //Función para generar un número aleatorio
    int generarNumeroAleatorio();

    //Función para generar un científico aleatorio
    std::string generarCientificoAleatorio();

    //funcion para agegar eventos a la lista
    void agregarEvento(Nodo* nuevoEvento);


};


#endif //MAQUINADELTIEMPO_MAQUINADELTIEMPO_H
