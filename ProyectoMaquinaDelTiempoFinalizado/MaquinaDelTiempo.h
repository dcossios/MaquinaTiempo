#ifndef MAQUINA_DEL_TIEMPO_H
#define MAQUINA_DEL_TIEMPO_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Nodo.h"

class MaquinaDelTiempo {
public:
    MaquinaDelTiempo();
    ~MaquinaDelTiempo();
    Nodo* primerEvento;
    void crearEventos();
    void mostrarEventos();
    void mostrarEventosTipoA();
    void mostrarEventosTipoB();
    void mostrarSingularidad();
    int obtenerTotalEventos();
    void imprimirEventosEnFormato();
    void imprimirEventosNuevo();
    int organizarEventos(int rand);
    bool esPrimo(int);
private:

    Nodo* ultimoEvento;
    int cantidadEventosTipoA;
    int cantidadEventosTipoB;
    Nodo* ultimoEventoTipoA;
    Nodo* ultimoEventoTipoB;
    Nodo* nodoSingularidad;


};

#endif // MAQUINA_DEL_TIEMPO_H