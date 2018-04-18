#pragma once

#include <iostream>
#include "Burbuja.h"
#include "../Vector/Vector.cpp"
#include "../DNI/DNI.cpp"

Burbuja::Burbuja() {

}

Burbuja::~Burbuja() {
   
}


int Burbuja::ordenar(Vector v1, int n, int mostrar){
   int comparaciones = 0;
   Vector v = v1;
   int nCambios = 1;
   while (nCambios > 0) {
      nCambios = 0;
      for (int i = n - 2; i > -1; i--){
         comparaciones++;
         if (v[i + 1] < v[i]) {
            DNI aux;
            aux = v[i];
            v[i] = v[i + 1];
            v[i + 1] = aux;
            nCambios++;
            if (mostrar == 0) {
               v.mostrarVector();
               cout << "Se intercambiaron " << v[i + 1].numeroDNI() << " y " << v[i].numeroDNI()<< endl;
            }
         }
      }
   }
   return comparaciones;
}

