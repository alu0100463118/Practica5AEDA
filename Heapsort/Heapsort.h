#pragma once

#include <stdio.h>

using namespace std;

class Heapsort {
    
    private:
        
    public:

        Heapsort();
        ~Heapsort();
        void ordenar(Vector v, int n, int mostrar);
        void baja(int i, Vector &v, int n);
};