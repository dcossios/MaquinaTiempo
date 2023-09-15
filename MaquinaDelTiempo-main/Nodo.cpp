
#include "Nodo.h"

// Constructor
Nodo::Nodo(int datos, std::string cientifico) {

    this->datos = datos;
    this->cientifico = cientifico;
    this->PtrPasado = nullptr;
    this->PtrFuturo = nullptr;
}
// Destructor
Nodo::~Nodo() {


}
