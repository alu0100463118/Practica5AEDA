#pragma once

#include <stdio.h>

using namespace std;

class DNI {
    
    private:
        string numDNI;
        string nombre;
        string apellido;
        
        
    
    public:
        DNI();
        DNI(string nd, string nom, string ape);
        ~DNI();
        //string numeroDNI();
        string numeroDNI();
        bool operator == (DNI d);
        bool operator < (DNI d);
        bool operator > (DNI d);
        void operator = (DNI d);
        operator unsigned long() const;
        void inicializarDNI();
        string obtenerNombre();
        string obtenerApellido();
};
