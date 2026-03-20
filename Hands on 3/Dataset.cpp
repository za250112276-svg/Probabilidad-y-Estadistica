#include "Dataset.hpp"
#include<iostream>

Tablafrecuencia::Tablafrecuencia (vector <double> d){
    datos = d;
    clase = {"<15", "15-18", "18-21", ">21"};
    Frecuencias = {0,0,0,0};

}
void Tablafrecuencia::calcularfrecuencia() {
    for (double valor:datos)
    {
        if (valor < 15 ) Frecuencias [0] ++;
        else if (valor < 18) Frecuencias [1] ++;
        else if(valor <21) Frecuencias [2] ++;
        else Frecuencias [3] ++;
        
    }
    

}
void Tablafrecuencia::imprimirtabla() {
    int N = datos.size ();
    cout << "Tabla de Frecuencias\n\n";
    cout << "Clase\tf\tfr\t%\n";
    for ( int i = 0; i < clase.size (); i++)
    {
        double fr = (double) Frecuencias [i] / N;
        cout << clase [i] << "\t" << Frecuencias [i] << "\t" << fr << "\t" << fr * 100 << "%" << endl;

    }
    cout << "Total\t" << N << "\t1.00\t100%" << endl;




}