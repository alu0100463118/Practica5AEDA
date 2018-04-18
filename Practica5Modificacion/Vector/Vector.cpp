#pragma once

#include <iostream>
#include "../DNI/DNI.h"
#include "Vector.h"

template<class Base_t>
Vector<Base_t>::Vector(int nElem) : nElementos(nElem) {
   pDNI = new DNI[nElementos];
}

template<class Base_t>
Vector<Base_t>::~Vector() {
   //delete[] pDNI;
}

template<class Base_t>
int Vector<Base_t>::numeroElementos() {
   return nElementos;
}

template<class Base_t>
void Vector<Base_t>::mostrarVector() {
   cout << endl;
   for (int i = 0; i < nElementos; i++) {
      cout << pDNI[i].numeroDNI() << "   ";
   }
   cout << endl;
}