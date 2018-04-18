#pragma once

#include <stdio.h>

using namespace std;

template <class Base_t>
class Vector {
    
    private:
        Base_t *pDNI;
        int nElementos;
    
    public:
        Vector(int nElem);
        ~Vector();
        Base_t& operator[](int indice) { return pDNI[indice]; }
        int numeroElementos();
        void mostrarVector();

};
