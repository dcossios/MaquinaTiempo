#include "Nodo.h"

Nodo::Nodo(int datos, int cientifico, int datosRandom) {
    this->datos = datos;
    this->cientifico = (cientifico == 1) ? "Einstein" : "Rosen";
    this->datosRandom = datosRandom;
    PtrPasado = nullptr;
    PtrFuturo = nullptr;
}
