#pragma once

#include <iostream>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include "DNI.h"

using namespace std;

DNI::DNI(){
    //srand(time(NULL));
    long int num = rand()%999999999;
    //numDNI = to_string(num);
    //numDNI = num;
    char letras[26]= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'Y', 'V', 'W', 'X', 'Y', 'Z'}; //posibles letras
    
    int random= rand()%26;
    char letraSel = letras[random];
    numDNI = num;
    letra = letraSel;
    nombre = "";
    apellido = "";
}
DNI::DNI(long int dn, string nom, string ape){
    numDNI = dn;
    nombre = nom;
    apellido = ape;
}


DNI::~DNI() {
    numDNI = 0;
    //numDNI = 0;
    
}

//string DNI::numeroDNI() {
long int DNI::numeroDNI() {
   return numDNI;
}

DNI::operator unsigned long() const {
    unsigned long int output;
    int numero = numDNI;
    output = (unsigned long int)numero;
    return output;
}

bool DNI::operator==(DNI d) {
    
    long int numero1 = numDNI;
    long int numero2 = d.numDNI;
    
    int parteClave1 = stoi(letra);
    int parteClave2 = stoi(d.letraDNI());
    
    long int clave1 = numero1 + parteClave1;
    long int clave2 = numero2 + parteClave2;
    
    if (clave1 == clave2){
        return true;
    }
    else {
        return false;
    }
}

bool DNI::operator<(DNI d) {
    
  //  int clave1 = stoi(numDNI);
  //  int clave2 = stoi(d.numeroDNI());
    long int numero1 = numDNI;
    long int numero2 = d.numDNI;
    
    int parteClave1 = stoi(letra);
    int parteClave2 = stoi(d.letraDNI());
    
    long int clave1 = numero1 + parteClave1;
    long int clave2 = numero2 + parteClave2;
    
    if (clave1 < clave2){
        return true;
    }
    else {
        return false;
    }

}

bool DNI::operator>(DNI d) {
    
   // int clave1 = stoi(numDNI);
   // int clave2 = stoi(d.numeroDNI());
    long int numero1 = numDNI;
    long int numero2 = d.numDNI;
    
    int parteClave1 = stoi(letra);
    int parteClave2 = stoi(d.letraDNI());
    
    long int clave1 = numero1 + parteClave1;
    long int clave2 = numero2 + parteClave2;
    
    if (clave1 > clave2){
        return true;
    }
    else {
        return false;
    }
}

void DNI::operator = (DNI d) {
    letra = d.letraDNI();
    numDNI = d.numeroDNI();
    nombre = d.obtenerApellido();
    apellido = d.obtenerNombre();
}

void DNI::inicializarDNI() {
    numDNI = 0;
}

string DNI::obtenerNombre() {
    return nombre;
}

string DNI::obtenerApellido() {
    return apellido;
}

string DNI::letraDNI() {
    return letra;
}
