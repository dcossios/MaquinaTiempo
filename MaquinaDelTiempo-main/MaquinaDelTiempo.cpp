#include <iostream>
#include "MaquinaDelTiempo.h"
#include "main.cpp"
MaquinaDelTiempo::MaquinaDelTiempo() {
    this->lista = nullptr;
}

MaquinaDelTiempo::~MaquinaDelTiempo() {
    while (this->lista != nullptr) {
        Nodo *nodo = this->lista;
        this->lista = this->lista->PtrPasado;
        delete nodo;
    }
}
    Nodo *MaquinaDelTiempo::crearEventoA() {
        int numeroAleatorio;
        do {
            numeroAleatorio = generarNumeroAleatorio();
        } while (!esPrimo(numeroAleatorio));
        return new Nodo(generarNumeroAleatorio(), generarCientificoAleatorio());

    }
    Nodo *MaquinaDelTiempo :: crearEventoB(Nodo *eventoA) {
        if (eventoA->datos % 2 == 0) {
            return nullptr;
        } else {
        }
        return new Nodo(generarNumeroAleatorio(), generarCientificoAleatorio());
    }

    Nodo *MaquinaDelTiempo :: crearEventoC(Nodo *eventoB){
        if (eventoB->datos % 2 == 0) {
            return nullptr;
        } else {
            int coprimo = generarNumeroAleatorio();
            while (coprimo % 2 == 0){
                coprimo = generarNumeroAleatorio();
            }
            if (coprimo % eventoB->datos == 0){
                return new Nodo(coprimo, generarCientificoAleatorio());
            } else {
                return nullptr;
            }
        }
    }

    void MaquinaDelTiempo ::imprimirLista(){

        Nodo *nodo = this->lista;
        while (nodo != nullptr) {
            std::cout << nodo->datos << " " << nodo->cientifico <<std::endl;
            nodo = nodo->PtrPasado;
        }
    }

    int MaquinaDelTiempo :: generarNumeroAleatorio(){
        return rand() % 100 + 1;
    }

    std:: string MaquinaDelTiempo :: generarCientificoAleatorio(){
    int random = rand() % 2 + 1;

    if(random == 1){
        return "Einstein";
    } else {
        return "Rosen";
    }
}

void MaquinaDelTiempo::agregarEvento(Nodo* nuevoEvento) {
    if (lista == nullptr) {
        lista = nuevoEvento;
    } else {
        // Encuentra el último evento en la lista
        Nodo* ultimoEvento = lista;
        while (ultimoEvento->PtrPasado != nullptr) {
            ultimoEvento = ultimoEvento->PtrPasado;
        }

        // Conecta el nuevo evento al último evento como pasado
        ultimoEvento->PtrPasado = nuevoEvento;
        nuevoEvento->PtrFuturo = ultimoEvento;
    }
}




