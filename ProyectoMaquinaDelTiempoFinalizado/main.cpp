#include <iostream>
#include "MaquinaDelTiempo.cpp"
#include "Nodo.cpp"

int main() {
    MaquinaDelTiempo maquina;

    maquina.crearEventos();
    maquina.imprimirEventosEnFormato();
    maquina.imprimirEventosNuevo();
    maquina.mostrarEventos();
    maquina.mostrarEventosTipoA();
    maquina.mostrarEventosTipoB();
    maquina.mostrarSingularidad();

    int totalEventos = maquina.obtenerTotalEventos();
    std::cout << "Total de eventos: " << totalEventos << std::endl;

    return 0;
}