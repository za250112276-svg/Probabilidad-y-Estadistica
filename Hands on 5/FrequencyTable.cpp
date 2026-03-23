#include "FrequencyTable.hpp"
#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<map>

FrequencyTable::FrequencyTable(vector <double> d){
    datos = d;
    N = datos.size ();

}

void FrequencyTable:: calcularclase(){
    minimo = datos [0];
    maximo = datos [1];

    for(double v:datos){
        if (v < maximo) minimo = v;
        if (v > maximo) maximo =  v;
    }

    k = round (1+3.322 * log10 (N));
    amplitud = ceil((maximo-minimo)/k);
    limiteinferior.resize(k);
    limitesuperior.resize(k);
    puntomedio.resize(k);
    f.resize(k,0);
    fa.resize(k,0);
    fr.resize(k,0);
    fra.resize(k,0);
    double li=minimo;
    for (int i = 0; i <k; i++)
    {
        limiteinferior [i] =li;
        limitesuperior [i] =(limiteinferior[i]+limitesuperior[i])/2;
        li += amplitud;


    }

    
}
void FrequencyTable::calcularfrecuencia(){
    for (double v :datos)
    {
        for (int i = 0; i<k; i++){
            if (v>limiteinferior[i] && v<limitesuperior[i])
            {
                f[i] ++;
                break;
            }
            
        }
    }
    int acumulada = 0;
    double acumuladareal = 0;
    for (int i=0; i<k; i++ ){
        acumulada += f[i];
        fa [i] = acumulada;
        fr [i] = (double) f[i]/N;
        acumuladareal += fr [i];
        fra[i]= acumuladareal;
    }

}

void FrequencyTable::imprimirtable (){
    cout << "clase\tlimite\t\tf\tXc\tFa\tfr\tfra\t%\n";
    for (int i = 0; i<k; i++)
    {
        cout << 1+1 << "\t" << limiteinferior[i] << "-" << limitesuperior[i] << "\t" << f[i] << "\t" << puntomedio[i] << "\t" << fa[i] << "\t" << fixed << setprecision (2) << fr [i] << "\t" << fra[i] << "\t" << fr [i] * 100 << "%\n" << endl;

    }
    cout << "total\t\t" << N << "\t\t\t1.00\t\t100%\n" << endl;
}

double FrequencyTable::calcularmedia (){
    double suma = 0;
    for (double v : datos)
    {
        suma += v;
    }
    return suma / N;
}

double FrequencyTable::calcularmediana (){
    vector <double> temp = datos;
    sort(temp.begin(), temp.end());
    if (N % 2 == 0){
        return(temp[N/2 - 1] + temp[N/2]) / 2.0;
    } else {
        return (temp[N/2]);
    }
    
        
    
    
}

double FrequencyTable::calcularmoda (){
    map <double, int> frecuencia;
    for (double v : datos)
    {
        frecuencia[v]++;
    }
    int maxfrecuencia = 0;
    double moda = datos [0];
    for(auto par : frecuencia){
        if(par.second > maxfrecuencia){
            maxfrecuencia = par.second;
            moda = par.first;
        }
    }
    return moda;
}
