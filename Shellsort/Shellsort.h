#pragma once

#include <stdio.h>

using namespace std;

class Shellsort {
    
    private:
        float a;
    
    public:

        Shellsort(float f);
        ~Shellsort();
        void ordenar(Vector v, int n, int mostrar);
        void deltasort(int delta, Vector &v, int n, int mostrar);
};