#pragma once

#include <iostream>
#include "Insercion.h"
#include "../Vector/Vector.cpp"
#include "../DNI/DNI.cpp"

Insercion::Insercion() {

}

Insercion::~Insercion() {
   
}


int Insercion::ordenar(Vector v, int n, int mostrar){
   
   int comparaciones = 0;
   for (int i = 1; i < n; i++) {
      int j = i - 1;
      
      // Buscamos la posicion en la que vamos a insertar el nuevo valor
      while ((v[i] < v[j]) && (j > 0) ) {
         j--;  
         comparaciones++;
      } 
      
      // Si llego a 0, comprobamos si lo queremos insertar en la primera posicion
      if (j == 0) {
         if (v[i] < v[j]) {
            j--;
         }
      }
      j++;
      
      DNI aux;
      aux = v[i];
      
      // Desplazamos todos los valores
      for (int a = i; a > j; a--) {
         v[a] = v[a - 1];
      }
      
      v[j] = aux;
      if (mostrar == 0) {
         v.mostrarVector();
         cout << "Se puso " << v[j].numeroDNI() << " en la posicion " << j << endl;
      }
         
      }
   return comparaciones;
}

