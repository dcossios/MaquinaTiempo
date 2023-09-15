
#include <iostream>
#include "Nodo.h"
#include "MaquinaDelTiempo.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>

using namespace std;

bool esPrimo(int numero){
    int contador = 0;
    for(int i = 1; i <= numero; i++){
        if(numero % i == 0){
            contador++;
        }
    }
    if(contador == 2){
        return true;
    }else{
        return false;
    }
}
 void imprimirListaEventosFinal(Nodo* nodoInicial, int numAleatorio) {
    Nodo* nodoActual = nodoInicial;

    while (nodoActual != nullptr) {
        if (nodoActual->cientifico=="Einstein") {
            std::cout << numAleatorio << "|" << "E" << std::endl;
        } else {
            std::cout << numAleatorio << "|" << "R" << std::endl;
        }
        std::cout << "-----------" << std::endl;

        nodoActual = nodoActual->PtrPasado;
        nodoActual++;
    }
}

void imprimirEventos(Nodo* nodoActual, int numAleatorio) {
    if (nodoActual->eventoA) {
        std::cout << "Se ha producido un evento de tipo: A" << std::endl;
        if (nodoActual->cientifico=="Einstein") {
            std::cout << numAleatorio << "|" << "E" << "A" << std::endl;
        } else {
            std::cout << numAleatorio << "|" << "R" << "A" << std::endl;
        }
    }
    else if (nodoActual-> eventoB) {
        std::cout << "Se ha producido un evento de tipo: B" << std::endl;
        if (nodoActual->cientifico == "Einstein") {
            std::cout << numAleatorio << "|" << "E" << "B" << std::endl;
        } else {
            std::cout << numAleatorio << "|" << "R" << "B" << std::endl;
        }
    }
    else {
        std::cout << "Se ha producido un evento de tipo: C" << std::endl;
        if (nodoActual->cientifico=="Einstein") {
            std::cout << numAleatorio<< "|" << "E" << "C" << std::endl;
        } else {
            std::cout << numAleatorio << "|" << "R" << "C" << std::endl;
        }
    }
}

int main() {
    MaquinaDelTiempo maquinaTiempo;
    std::string cientifico = maquinaTiempo.generarCientificoAleatorio();
    Nodo* eventoA = maquinaTiempo.crearEventoA();
    maquinaTiempo.agregarEvento(eventoA);

    Nodo* eventoB = maquinaTiempo.crearEventoB(eventoA);
    if (eventoB != nullptr) {
        maquinaTiempo.agregarEvento(eventoB);
    }

    Nodo* eventoC = maquinaTiempo.crearEventoC(eventoB);
    if (eventoC != nullptr) {
        maquinaTiempo.agregarEvento(eventoC);
    }


    return 0;
}
