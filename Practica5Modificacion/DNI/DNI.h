#pragma once

#include <stdio.h>

using namespace std;

class DNI {
    
    private:
        long int numDNI;
        string letra;
        string nombre;
        string apellido;
        
        
    
    public:
        DNI();
        DNI(long int nd, string nom, string ape);
        ~DNI();
        //string numeroDNI();
        long int numeroDNI();
        string letraDNI();
        bool operator == (DNI d);
        bool operator < (DNI d);
        bool operator > (DNI d);
        void operator = (DNI d);
        operator unsigned long() const;
        void inicializarDNI();
        string obtenerNombre();
        string obtenerApellido();
};
