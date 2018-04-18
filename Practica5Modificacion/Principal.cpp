#include <iostream>
#include <typeinfo>

#include "DNI/DNI.cpp"
#include "Banco/Banco.cpp"
#include "Vector/Vector.cpp"
/*#include "Datos/Datos.cpp"

#include "Burbuja/Burbuja.cpp"
#include "Heapsort/Heapsort.cpp"
#include "Shellsort/Shellsort.cpp"
#include "Quicksort/Quicksort.cpp"*/
//#include <vector>

//#include "Insercion/Insercion.cpp"

using namespace std;

/***************************    Insercion    ***************************/

template<class t> int Insercion(Vector<t> v, int n, int mostrar) {
    int comparaciones = 0;
    for (int i = 1; i < n; i++) {
        int j = i - 1;
      
      // Buscamos la posicion en la que vamos a insertar el nuevo valor
        while ((v[i] < v[j]) && (j > 0)) {
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

/***************************    Burbuja    ***************************/

template<class t> int Burbuja(Vector<t> v, int n, int mostrar) {
    int comparaciones = 0;
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

/***************************    HeapSort    ***************************/
template<class t> void baja(int i, Vector<t> v, int n, int &comparaciones, int mostrar) {
    int h1;
    int h2;
    int h;
    DNI aux;
    aux = v[i];
    while ( 2*i < n ) {
        h1 = 2*i;
        h2 = h1 + 1 ;
        if (h1 == n-1) {
            h = h1;
        }
        else if (v[h1] > v[h2]) {
            comparaciones++;
            h = h1;
        }
        else {
            h = h2;
        }
        if (v[h] <= aux){
            comparaciones++;
            break ;
        }
        else {
            comparaciones++;
            v[i] = v[h];
            v[h] = aux ;
            if (mostrar == 0) {
                v.mostrarVector();
                cout << "Se intercambiaron " << v[i].numeroDNI() << " y " << v[h].numeroDNI() << endl;
            }
            i = h ;
        }
    }
}

template<class t> int HeapSort(Vector<t> v, int n, int mostrar) {
    int comparaciones = 0;
    for (int i = n/2; i > 0; i--) {
        baja(i, v, n, comparaciones, mostrar);
    }
    for (int i = n-1; i > 0; i--) {
        DNI aux;
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        baja(0,v,i-1, comparaciones, mostrar);
    }
    return comparaciones;
} 

/***************************    QuickSort    ***************************/

template<class t> void QuickSort(Vector<t> v, int ini, int fin, int mostrar, int &comparaciones) {
    int i = ini;
    int f = fin;
    DNI p;
    p = v[(i+f)/2] ;
    while (i <= f) {
        while (v[i] < p) {
            comparaciones++;
            i++;
        }
        while (v[f] > p) {
            comparaciones++;
            f-- ;
        }
        if (i <= f) {
            DNI aux;
            aux = v[i];
            v[i] = v[f];
            v[f] = aux;
            if (mostrar == 0) {
                v.mostrarVector();
                cout << "Se intercambiaron " << v[i].numeroDNI() << " y " << v[f].numeroDNI() << endl;
            }
            i++; 
            f--;
            
        }
    }
    if (ini < f) {
        QuickSort(v, ini, f, mostrar, comparaciones);
    }
    if (i < fin) {
        QuickSort(v, i, fin, mostrar, comparaciones);
    }
}


/***************************    ShellSort    ***************************/

template<class t> void deltasort(int delta, Vector<t> v, int n, int mostrar, int &comparaciones) {
   
    for (int i = delta; i < n; i++) {
       
        DNI aux;
        aux = v[i];
        int j = i;
        while ((j >= delta) && (aux < v[j - delta])) {
            comparaciones++;
            v[j] = v[j - delta];
            if (mostrar == 0) {
                v.mostrarVector();
                cout << "Se rodo " << v[j].numeroDNI() << " desde " << j << " hasta " << j - delta << endl;
            }
            j = j - delta;
        }
        v[j] = aux;
        
    }
}

template<class t> int ShellSort(Vector<t> v, int n, int mostrar, float alfa) {
    float a = alfa;
    int comparaciones = 0;
    int delta = n;
    while ((delta * a) > 1) {
        delta = delta * a;
        //delta = delta / 2;
        deltasort(delta, v, n, mostrar, comparaciones);
    }
    if (mostrar == 0) {
        v.mostrarVector();
    }
    return comparaciones;
}



/***************************    Main    ***************************/



int main() {

    srand(time(NULL));
    //DNI d("123456", "pepe", "lopez");
    //DNI e("123456", "", "");
    
    int modo = -1;
    int algoritmo = -1;
    int tamVector = -1;

    while ((modo != 0) && (modo != 1)) {
        cout << endl << "Introduzca el modo de funcionamiento (0:demostracion, 1:estadistico)" << endl;
        cin >> modo;
    }
    
    switch (modo) {
        
        //Modo demostracion
        case 0: {

            cout << endl << "Introduzca el tamaño del vector:" << endl;
            cin >> tamVector;
            
            while ((algoritmo != 0) && (algoritmo != 1) && (algoritmo != 2) && (algoritmo != 3) && (algoritmo != 4)) {
                cout << endl << "Introduzca el algoritmo de ordenacion (0:Insercion, 1:Burbuja, 2:HeapSort, 3:QuickSort, 4:ShellSort)" << endl;
                cin >> algoritmo;
            }
            
            switch (algoritmo) {
                
                // Insercion
                case 0: {
                    Vector<DNI> v2(tamVector);
                    Insercion(v2, tamVector, modo);
                    break;
                    
                }
                
                // Burbuja
                case 1: {
                    Vector<DNI> v3(tamVector);
                    Burbuja(v3, tamVector, modo);
                    break;
                }
                // HeapSort
                case 2: {
                    Vector<DNI> v4(tamVector);
                    v4.mostrarVector();
                    HeapSort(v4, tamVector, modo);
                    
                    
                    break;
                }
                // QuickSort
                case 3: {
                    int comparaciones;
                    Vector<DNI> v5(tamVector);
                    QuickSort(v5, 0, tamVector - 1, modo, comparaciones);
                    v5.mostrarVector();
                    break;
                }
                
                // ShellSort
                default: {
                    float alfa = -1;
                    while ((alfa < 0) || (alfa > 1)) {
                        cout << endl << "Introduzca la constante de reduccion (Entre 0 y 1)" << endl;
                        cin >> alfa;
                    }
                    Vector<DNI> v6(tamVector);
                    ShellSort(v6, tamVector, modo, alfa);
                    break;
                }
            }
            break;
        }
        // Modo estadistico
        default: {
            int nPruebas = 0;
            int tamVector = 0;
            int minimo = 0;
            float medio = 0;
            int maximo = 0;
            int sumatorio = 0;
            int comparaciones = 0;
            
            cout << endl << "Introduzca el numero de pruebas" << endl;
            cin >> nPruebas;
            cout << endl << "Introduzca el tamaño del vector" << endl;
            cin >> tamVector;
            
            float alfa = -1;
            while ((alfa < 0) || (alfa > 1)) {
                cout << endl << "Introduzca la constante de reduccion (Entre 0 y 1)" << endl;
                cin >> alfa;
            }
            
            // Bancos de pruebas
            Banco b1(nPruebas, tamVector);
            Banco b2(nPruebas, tamVector);
            Banco b3(nPruebas, tamVector);
            Banco b4(nPruebas, tamVector);
            Banco b5(nPruebas, tamVector);
            
            cout << endl << endl << "                   Numero de Comparaciones";
            cout << endl << "                Minimo       Medio      Maximo" << endl;
            
            // Insersion
            
            for (int a = 0; a < nPruebas; a++) {
                comparaciones = Insercion(b1[a], tamVector, modo);
                
                // Minimo
                if (minimo == 0) {
                    minimo = comparaciones;
                }
                else {
                    if (minimo > comparaciones) {
                        minimo = comparaciones;
                    }
                }
                
                // Maximo
                if (maximo == 0) {
                    maximo = comparaciones;
                }
                else {
                    if (maximo < comparaciones) {
                        maximo = comparaciones;
                    }
                }
                
                // Media
                sumatorio = sumatorio + comparaciones;
            }
            medio = sumatorio / nPruebas;
            
            cout << " Insercion        " << minimo << "          " << medio << "          " << maximo << endl;
            
            // Burbuja 
            minimo = 0;
            maximo = 0;
            sumatorio = 0;
            
            for (int a = 0; a < nPruebas; a++) {
                comparaciones = Burbuja(b2[a], tamVector, modo);
                // Minimo
                if (minimo == 0) {
                    minimo = comparaciones;
                }
                else {
                    if (minimo > comparaciones) {
                        minimo = comparaciones;
                    }
                }
                
                // Maximo
                if (maximo < comparaciones) {
                    maximo = comparaciones;
                }
                
                // Media
                sumatorio = sumatorio + comparaciones;
            }
            medio = sumatorio / nPruebas;
            cout << " Burbuja          " << minimo << "          " << medio << "          " << maximo << endl;
                      
            // HeapSort
            minimo = 0;
            maximo = 0;
            sumatorio = 0;
            
            for (int a = 0; a < nPruebas; a++) {
                comparaciones = HeapSort(b3[a], tamVector, modo);
                
                // Minimo
                if (minimo == 0) {
                    minimo = comparaciones;
                }
                else {
                    if (minimo > comparaciones) {
                        minimo = comparaciones;
                    }
                }
                
                // Maximo
                if (maximo == 0) {
                    maximo = comparaciones;
                }
                else {
                    if (maximo < comparaciones) {
                        maximo = comparaciones;
                    }
                }
                
                // Media
                sumatorio = sumatorio + comparaciones;
            }
            medio = sumatorio / nPruebas;
            
            cout << " HeapSort         " << minimo << "          " << medio << "          " << maximo << endl;
                      
            
            // QuickSort
            minimo = 0;
            maximo = 0;
            sumatorio = 0;
            
            for (int a = 0; a < nPruebas; a++) {
                comparaciones = 0;
                QuickSort(b4[a], 0, tamVector - 1, modo, comparaciones);
                
                // Minimo
                if (minimo == 0) {
                    minimo = comparaciones;
                }
                else {
                    if (minimo > comparaciones) {
                        minimo = comparaciones;
                    }
                }
                
                // Maximo
                if (maximo == 0) {
                    maximo = comparaciones;
                }
                else {
                    if (maximo < comparaciones) {
                        maximo = comparaciones;
                    }
                }
                
                // Media
                sumatorio = sumatorio + comparaciones;
            }
            medio = sumatorio / nPruebas;
            
            cout << " QuickSort        " << minimo << "          " << medio << "          " << maximo << endl;
            
            
            // ShellSort
            minimo = 0;
            maximo = 0;
            sumatorio = 0;
            
            for (int a = 0; a < nPruebas; a++) {
                comparaciones = ShellSort(b5[a], tamVector, modo, alfa);
                // Minimo
                if (minimo == 0) {
                    minimo = comparaciones;
                }
                else {
                    if (minimo > comparaciones) {
                        minimo = comparaciones;
                    }
                }
                
                // Maximo
                if (maximo < comparaciones) {
                    maximo = comparaciones;
                }
                
                // Media
                sumatorio = sumatorio + comparaciones;
            }
            medio = sumatorio / nPruebas;
            cout << " ShellSort        " << minimo << "          " << medio << "          " << maximo << endl;
            break;
        }
    }
    cout << endl << endl;
    return 0;
}
