#pragma once

#include <iostream>
#include "Heapsort.h"
#include "../Vector/Vector.cpp"
#include "../DNI/DNI.cpp"

Heapsort::Heapsort() {

}

Heapsort::~Heapsort() {
   
}


void Heapsort::ordenar(Vector v, int n, int mostrar){
   for (int i = n/2 - 1; i >= 0; i--) {
      baja(i, v, n);
      for (int j = n - 1; j >= 0; j--){
         DNI aux;
         aux = v[1];
         v[1] = v[j];
         v[j] = aux;
         baja(1,v,j-1) ;
         if (mostrar == 0) {
            v.mostrarVector();
         }
       //  cout << "Se puso " << v[j].numeroDNI() << " en la posicion " << j << endl;
      }
   } 
}


void Heapsort::baja( int i, Vector &v, int n ) {
   //cout << "aqui 1 ";
   DNI aux;
   aux = v[i];
   while (2 * i <= n - 1 ) {
      n=n-1;
      int h1 = 2 * i;
      int h2 = h1 + 1;
      int h;
      if (h1 == n) {
         h = h1;
      }
      
      else if (v[h1] > v[h2]) {
         h = h1;
      }
      else {
         h = h2;
      }
      if (v[h] <= aux) {
         break ;
      }
      else {
         v[i] = v[h];
         v[h] = aux ;
         i = h ;
      }
   }
}

