#pragma once

#include <iostream>
#include "Quicksort.h"
#include "../Vector/Vector.cpp"
#include "../DNI/DNI.cpp"

Quicksort::Quicksort() {

}

Quicksort::~Quicksort() {
   
}


void Quicksort::ordenar(Vector v, int n, int mostrar){
   
   for (int i = 1; i < n; i++) {
      int j = i - 1;
      while ((v[i] < v[j]) && (j > 0) ) {
         j--;  
      } 
      if (j == 0) {
         if (v[i] < v[j]) {
            j--;
         }
      }
//      if (v[i] < v[j]) {
//      }
 //     else {
         j++;
 //     }
      DNI aux;
      aux = v[i];
      for (int a = i; a > j; a--) {
         v[a] = v[a - 1];
      }
      v[j] = aux;
      if (mostrar == 0) {
         v.mostrarVector();
         cout << "Se puso " << v[j].numeroDNI() << " en la posicion " << j << endl;
      }
   }
}

