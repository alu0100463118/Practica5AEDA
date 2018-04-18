#pragma once

#include <stdio.h>
#include "../Vector/Vector.cpp"

using namespace std;

class Banco {
    
    private:
        Vector<DNI>** banco;
        int nElementos;
    
    public:
        Banco(int nPruebas, int tamVector);
        ~Banco();
        Vector<DNI>& operator[](int indice) { return *banco[indice]; }
        int numeroElementos();
        void mostrarBanco();

};
