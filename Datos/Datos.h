#pragma once

#include <stdio.h>

using namespace std;

class Datos {
    
    private:
        int nPruebas;
        int minBusqueda;
        float medioBusqueda;
        int maxBusqueda;
        int minInsersion;
        float medioInsersion;
        int maxInsersion;
        int datInsersion[1000];
        int datBusqueda[1000];
        int numeroPruebaInsersion;
        int numeroPruebaBusqueda;
    
    public:
        Datos();
        ~Datos();
        
        void insertarNumPruebas(int n);
        int obtenerNumPruebas();
        
        void insertarMinBusqueda(int n);
        int obtenerMinBusqueda();
        
        void insertarMedioBusqueda(int n);
        float obtenerMedioBusqueda();
        
        void insertarMaxBusqueda(int n);
        int obtenerMaxBusqueda();
        
        void insertarMinInsersion(int n);
        int obtenerMinInsersion();
        
        void insertarMedioInsersion(int n);
        float obtenerMedioInsersion();
        
        void insertarMaxInsersion(int n);
        int obtenerMaxInsersion();
        
        void insertarBusqueda(int n);
        void insertarInsersion(int n);
        
        void mostrarEstadisticas();
};
