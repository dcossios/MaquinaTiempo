#include "MaquinaDelTiempo.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <sstream>

MaquinaDelTiempo::MaquinaDelTiempo() {
    primerEvento = nullptr;
    ultimoEvento = nullptr;
    cantidadEventosTipoA = 0;
    cantidadEventosTipoB = 0;
    ultimoEventoTipoA = nullptr;
    ultimoEventoTipoB = nullptr;
    nodoSingularidad = nullptr;
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

MaquinaDelTiempo::~MaquinaDelTiempo() {
    // Libera la memoria de los nodos si es necesario
    Nodo* actual = primerEvento;
    while (actual != nullptr) {
        Nodo* siguiente = actual->PtrFuturo;
        delete actual;
        actual = siguiente;
    }
}

bool MaquinaDelTiempo::esPrimo(int numero) {
    if (numero <= 1) {
        return false; // Los números menores o iguales a 1 no son primos
    }
    if (numero <= 3) {
        return true; // 2 y 3 son primos
    }
    if (numero % 2 == 0 || numero % 3 == 0) {
        return false; // Los múltiplos de 2 y 3 no son primos
    }

    // Comprobamos divisibilidad desde 5 hasta la raíz cuadrada del número
    for (int i = 5; i * i <= numero; i += 6) {
        if (numero % i == 0 || numero % (i + 2) == 0) {
            return false; // Si es divisible por i o i+2, no es primo
        }
    }

    return true; // Si no se encontraron divisores, es primo
}

int MaquinaDelTiempo::organizarEventos(int randomDatos) {
    Nodo* actual = primerEvento;
    bool eventoATipoA = false;
    int tipoEvento = 0;

    if (esPrimo(randomDatos)) {
        if (cantidadEventosTipoA <= cantidadEventosTipoB) {
            tipoEvento = 1;

        } else {
            tipoEvento = 2;

        }
    } else {
        tipoEvento = 3;
    }

    return tipoEvento;
}


void MaquinaDelTiempo::crearEventos() {
    for (int i = 0; i < 22; i++) {
        int randomDatos = std::rand() % 100 + 1;
        while (randomDatos == 0) {
            randomDatos = std::rand() % 100 + 1;
        }

        int randomCientifico = std::rand() % 2 + 1;
        int eventoTipo = organizarEventos(randomDatos);

        if (ultimoEventoTipoA != nullptr) {
            if (randomDatos % 2 == 0) {
                eventoTipo = 2;
            }
        }

        Nodo *nuevoEvento = new Nodo(eventoTipo, randomCientifico, randomDatos);

        if (primerEvento == nullptr) {
            primerEvento = nuevoEvento;
            ultimoEvento = nuevoEvento;
        } else {
            nuevoEvento->PtrPasado = ultimoEvento;
            ultimoEvento->PtrFuturo = nuevoEvento;
            ultimoEvento = nuevoEvento;
        }

        // Verificar si es un evento tipo A o B y aplicar las restricciones según sea necesario.
        if (eventoTipo == 1 || eventoTipo == 2) { // Evento A o B
            if (randomCientifico == 1) { // Einstein
                nuevoEvento->cientifico = "Einstein";
            }
            if (eventoTipo == 1) { // Evento A
                cantidadEventosTipoA++;
                ultimoEventoTipoA = nuevoEvento;
            } else { // Evento B
                cantidadEventosTipoB++;
                ultimoEventoTipoB = nuevoEvento;
            }
        }

        // Verificar si se ha producido una singularidad y almacenar el nodo correspondiente.
        if (nuevoEvento->PtrPasado != nullptr && nuevoEvento->datos % nuevoEvento->PtrPasado->datos == 0) {
            nodoSingularidad = nuevoEvento;
        }
    }
}

void MaquinaDelTiempo::imprimirEventosEnFormato() {
    std::cout << "\n";
    Nodo* actual = primerEvento;
    int contador = 1;
    while (actual != nullptr) {
        std::cout << "[";
        std::cout << actual->datosRandom << "|";
        std::cout << actual->cientifico[0] << "|";
        if (actual->datos == 1) {
            std::cout << "A";
        }
        else if(actual->datos == 2) {
            std::cout << "B";
        }else {
            std::cout << "C";

        }
        std::cout << "] -> ";
        actual = actual->PtrFuturo;
        contador++;
    }
}

void MaquinaDelTiempo::imprimirEventosNuevo() {
    std::stringstream formato;
    std::map<int, std::string> tiposEventos;
    tiposEventos[1] = "A";
    tiposEventos[2] = "B";
    tiposEventos[3] = "C";

    Nodo* actual = primerEvento; // El evento actual

    while (actual != nullptr) {
        std::string tipoEvento;
        if (actual->datos == 1 || actual->datos == 2) {
            tipoEvento = tiposEventos[actual->datos]; // Usar el valor directamente como tipo "A" o "B"
        } else {
            tipoEvento = tiposEventos[3]; // Tipo "C" para otros valores
        }

        formato << "Se ha producido un evento de Tipo (" << tipoEvento << "): (Dato): ";

        if (actual->PtrPasado != nullptr) {
            formato << actual->datosRandom; // Mostrar el número aleatorio en lugar de datos
        } else {
            formato << "N/A"; // O cualquier otro mensaje que desees para indicar que no hay valor
        }

        std::cout << formato.str() << std::endl;
        formato.str("");

        /* Avanzamos al siguiente evento */
        actual = actual->PtrFuturo;
    }
}

void MaquinaDelTiempo::mostrarEventos() {
    std::cout << "\n";
    std::cout << "-------------------------------------------------";
    std::cout << "\n";
    Nodo* actual = primerEvento;
    int contador = 1;
    while (actual != nullptr) {
        std::cout << "\n";
        std::cout << "Evento " << contador << ": ";
        std::cout << "Datos=" << actual->datos << ", ";
        std::cout << "Científico=" << actual->cientifico << ", ";
        if (actual->PtrPasado != nullptr) {
            std::cout << "PtrPasado->Datos=" << actual->PtrPasado->datos << ", ";
        }
        if (actual->PtrFuturo != nullptr) {
            std::cout << "PtrFuturo->Datos=" << actual->PtrFuturo->datos;
        }
        std::cout << std::endl;
        actual = actual->PtrFuturo;
        contador++;
    }
}

void MaquinaDelTiempo::mostrarEventosTipoA() {
    std::cout << "Eventos Tipo A (" << cantidadEventosTipoA << "):" << std::endl;

}

void MaquinaDelTiempo::mostrarEventosTipoB() {
    std::cout << "Eventos Tipo B (" << cantidadEventosTipoB << "):" << std::endl;

}

void MaquinaDelTiempo::mostrarSingularidad() {
    std::cout << "\n";
    if (nodoSingularidad != nullptr) {
        std::cout << "Singularidad encontrada en el evento con Datos=" << nodoSingularidad->datos << std::endl;
    } else {
        std::cout << "No se ha encontrado ninguna singularidad." << std::endl;
    }
}

int MaquinaDelTiempo::obtenerTotalEventos() {
    std::cout << "\n";
    int contador = 0;
    Nodo* actual = primerEvento;
    while (actual != nullptr) {
        contador++;
        actual = actual->PtrFuturo;
    }
    return contador;
}
