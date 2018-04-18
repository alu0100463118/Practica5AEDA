#pragma once

#include <iostream>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include "DNI.h"

using namespace std;

DNI::DNI(){
    //srand(time(NULL));
    int num = rand()%999;
    numDNI = to_string(num);
    //numDNI = num;
    char letras[26]= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'Y', 'V', 'W', 'X', 'Y', 'Z'}; //posibles letras
    
    int random= rand()%26;
    char letra = letras[random];
    numDNI = numDNI + letra;
    nombre = "";
    apellido = "";
}
DNI::DNI(string dn, string nom, string ape){
    numDNI = dn;
    nombre = nom;
    apellido = ape;
}


DNI::~DNI() {
    numDNI = "";
    //numDNI = 0;
    
}

//string DNI::numeroDNI() {
string DNI::numeroDNI() {
   return numDNI;
}

DNI::operator unsigned long() const {
    unsigned long int output;
    int numero = stoi(numDNI);
    output = (unsigned long int)numero;
    return output;
}

bool DNI::operator==(DNI d) {
    int clave1 = stoi(numDNI);
    int clave2 = stoi(d.numeroDNI());
    
    if (clave1 == clave2){
        return true;
    }
    else {
        return false;
    }
}

bool DNI::operator<(DNI d) {
    
    int clave1 = stoi(numDNI);
    int clave2 = stoi(d.numeroDNI());
    
    if (clave1 < clave2){
        return true;
    }
    else {
        return false;
    }

}

bool DNI::operator>(DNI d) {
    
    int clave1 = stoi(numDNI);
    int clave2 = stoi(d.numeroDNI());
    
    if (clave1 > clave2){
        return true;
    }
    else {
        return false;
    }
}

void DNI::operator = (DNI d) {
    numDNI = d.numeroDNI();
    nombre = d.obtenerApellido();
    apellido = d.obtenerNombre();
}

void DNI::inicializarDNI() {
    numDNI = "";
}

string DNI::obtenerNombre() {
    return nombre;
}

string DNI::obtenerApellido() {
    return apellido;
}
