#pragma once

#include <iostream>
#include "Banco.h"
#include "../Vector/Vector.cpp"
#include "../DNI/DNI.cpp"

Banco::Banco(int nPruebas, int tamVector) {
   //pVector = new Vector[nElementos];
   nElementos = nPruebas;
   banco = new Vector<DNI>*[tamVector];
   
   for (int i = 0; i < nPruebas; i++) {
      banco[i] = new Vector<DNI>(tamVector);
   }
 /*  for (int i = 0; i < nClaves; i++) {
      for (int j = 0; j < nCeldas; j++) {
         tabla[i][j].inicializarDNI();
      }
   }*/
}

Banco::~Banco() {
   //delete[] pVector;
}

int Banco::numeroElementos() {
   return nElementos;
}

void Banco::mostrarBanco() {
   for (int i = 0; i < nElementos; i++) {
      banco[i]->mostrarVector();
      cout << endl;
   }
}