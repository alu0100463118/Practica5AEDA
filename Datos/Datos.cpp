#pragma once

#include <iostream>
#include<string.h>
#include<stdlib.h>
#include "Datos.h"

using namespace std;

Datos::Datos(){
    nPruebas = 0;
    minBusqueda = -1;
    medioBusqueda = 0;
    maxBusqueda = 0;
    minInsersion = -1;
    medioInsersion = 0;
    maxInsersion = 0;
    numeroPruebaBusqueda = 0;
    numeroPruebaInsersion = 0;
}

Datos::~Datos() {
    nPruebas = 0;
    minBusqueda = 0;
    medioBusqueda = 0;
    maxBusqueda = 0;
    minInsersion = 0;
    medioInsersion = 0;
    maxInsersion = 0;
    numeroPruebaBusqueda = 0;
    numeroPruebaInsersion = 0;
}

void Datos::insertarNumPruebas(int n) {
    nPruebas = n;

}

int Datos::obtenerNumPruebas() {
    return nPruebas;
}

        
void Datos::insertarMinBusqueda(int n) {
    if (minBusqueda == -1) {
        minBusqueda = n;
    }
    else {
        if (minBusqueda > n) {
            minBusqueda = n;
        }
    }
}

int Datos::obtenerMinBusqueda() {
    return minBusqueda;
}

        
void Datos::insertarMedioBusqueda(int n) {
    datBusqueda[numeroPruebaBusqueda] = n;
    numeroPruebaBusqueda++;
}

float Datos::obtenerMedioBusqueda() {
    float total = 0;
    for (int i = 0; i < nPruebas; i++) {
        total = total + datBusqueda[i];
    }
    medioBusqueda = total / nPruebas;
    return medioBusqueda;
}

        
void Datos::insertarMaxBusqueda(int n) {
    if (maxBusqueda < n) {
        maxBusqueda = n;
    }
}

int Datos::obtenerMaxBusqueda() {
    return maxBusqueda;
}

        
void Datos::insertarMinInsersion(int n) {
    if (minInsersion == -1) {
        minInsersion = n;
    }
    else {
        if (minInsersion > n) {
            minInsersion = n;
        }
    }
}

int Datos::obtenerMinInsersion() {
    return minInsersion;
}

        
void Datos::insertarMedioInsersion(int n) {
    datInsersion[numeroPruebaInsersion] = n;
    numeroPruebaInsersion++;
}

float Datos::obtenerMedioInsersion() {
    float total = 0;
    for (int i = 0; i < nPruebas; i++) {
        total = total + datInsersion[i];
    }
    medioInsersion = total / nPruebas;
    return medioInsersion;
}

        
void Datos::insertarMaxInsersion(int n) {
    if (maxInsersion < n) {
        maxInsersion = n;
    }
}

int Datos::obtenerMaxInsersion() {
    return maxInsersion;
}

void Datos::insertarBusqueda(int n) {
    insertarMinBusqueda(n);
    insertarMedioBusqueda(n);
    insertarMaxBusqueda(n);
}

void Datos::insertarInsersion(int n) {
    insertarMinInsersion(n);
    insertarMedioInsersion(n);
    insertarMaxInsersion(n);
}

void Datos::mostrarEstadisticas() {
    cout << "                Minimo           Media           Maximo" << endl;
    cout << "Busquedas:        " << obtenerMinBusqueda() << "               " << obtenerMedioBusqueda() << "           " << obtenerMaxBusqueda() << endl;
    cout << "Insercion:        " << obtenerMinInsersion() << "               " << obtenerMedioInsersion() << "           " << obtenerMaxInsersion() << endl << endl;
    
    
}