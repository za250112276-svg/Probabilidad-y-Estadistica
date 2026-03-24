#include "TablaFrecuencia.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>

TablaFrecuencia::TablaFrecuencia(vector<double> d) {

    datos = d;
    n = datos.size();
}

void TablaFrecuencia::calcularClases() {

    minimo = datos[0];
    maximo = datos[0];

    for(double v : datos) {

        if(v < minimo) minimo = v;
        if(v > maximo) maximo = v;
    }

    k = round(1 + 3.322 * log10(n));

    amplitud = ceil((maximo - minimo) / k);

    limiteInferior.resize(k);
    limiteSuperior.resize(k);
    puntoMedio.resize(k);

    f.resize(k,0);
    Fa.resize(k,0);

    fr.resize(k,0);
    Fra.resize(k,0);

    double li = minimo;

    for(int i=0;i<k;i++) {

        limiteInferior[i] = li;
        limiteSuperior[i] = li + amplitud;

        puntoMedio[i] = (limiteInferior[i] + limiteSuperior[i]) / 2;

        li += amplitud;
    }
}

void TablaFrecuencia::calcularFrecuencias() {

    for(double v : datos) {

        for(int i=0;i<k;i++) {

            if(v >= limiteInferior[i] && v < limiteSuperior[i]) {

                f[i]++;
                break;
            }
        }
    }

    int acumulada = 0;
    double acumuladaRel = 0;

    for(int i=0;i<k;i++) {

        acumulada += f[i];
        Fa[i] = acumulada;

        fr[i] = (double)f[i] / n;

        acumuladaRel += fr[i];
        Fra[i] = acumuladaRel;
    }
}

void TablaFrecuencia::imprimirTabla() {

    cout << "Clase\tLimite\t\tf\tXc\tFa\tfr\tFra\t%\n";

    for(int i=0;i<k;i++) {

        cout << i+1 << "\t" << limiteInferior[i] << "-" << limiteSuperior[i] << "\t" << f[i] << "\t" << puntoMedio[i] << "\t" << Fa[i] << "\t" << fixed << setprecision(2) << fr[i] << "\t" << Fra[i] << "\t" << fr[i]*100 << "%\n" << endl;
    }

    cout << "Total\t\t" << n << "\t\t\t\t1.00\t\t100%\n" << endl;

    cout << "\nMedidas de Tendencia Central\n";

    cout << "Media: " << CalcularMedia() << endl;
    cout << "Mediana: " << CalcularMediana() << endl;
    cout << "Moda: " << CalcularModa() << endl;
}

double TablaFrecuencia::CalcularMedia(){
    double suma=0;
    for(int i=0; i < k; i++){
        suma += f[i] * puntoMedio[i];
    }
    return suma / n;
}

double TablaFrecuencia::CalcularMediana(){
    double mitad = n / 2.0;
    for(int i=0; i < k; i++){
        if(Fa[i] >= mitad){
            double L = limiteInferior[i];
            double FaAnterior = (i==0) ? 0 : Fa[i-1];
            double fm = f[i];
            double c = amplitud;
            return L + ((mitad - FaAnterior) / fm) * c;
        }
    }
    return 0;
}

double TablaFrecuencia::CalcularModa(){
    int index = 0;
    for(int i=1;i < k;i++){
        if(f[i] > f[index]){
            index = i;
        }
    }
    double L = limiteInferior[index];
    double fm = f[index];
    double fAnterior = (index==0) ? 0 : f[index-1];
    double fSiguiente = (index==k-1) ? 0 : f[index+1];
    double c = amplitud;
    return L + ((fm - fAnterior) / ((fm - fAnterior) + (fm - fSiguiente))) * c;
}

