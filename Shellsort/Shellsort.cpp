#pragma once

#include <iostream>
#include "Shellsort.h"
#include "../Vector/Vector.cpp"
#include "../DNI/DNI.cpp"

Shellsort::Shellsort(float f) {
   a = f;
}

Shellsort::~Shellsort() {
   
}


void Shellsort::ordenar(Vector v, int n, int mostrar){
   
   int delta = n;
   while (delta > 1) {
      delta = delta * a;
      //delta = delta / 2;
      cout << endl << delta << endl;
      deltasort(delta,v, n, mostrar);
   }
   if (mostrar == 0) {
      v.mostrarVector();
   }
}

void Shellsort::deltasort(int delta, Vector &v, int n, int mostrar) {
   for (int i = delta; i < n; i++) {
      DNI aux;
      aux = v[i];
      int j = i;
      while ((j >= delta) && (aux < v[j - delta])) {
         v[j] = v[j - delta];
         j = j - delta;
      }
      v[j] = aux;
      if (mostrar == 0) {
         v.mostrarVector();
      }
   }
   
}

