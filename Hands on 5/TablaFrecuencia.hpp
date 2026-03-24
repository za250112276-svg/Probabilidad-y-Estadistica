#ifndef TABLAFRECUENCIA_HPP
#define TABLAFRECUENCIA_HPP

#include <vector>

using namespace std;

class TablaFrecuencia {

private:

    vector<double> datos;

    int n;
    int k;

    double minimo;
    double maximo;
    double amplitud;

    vector<double> limiteInferior;
    vector<double> limiteSuperior;
    vector<double> puntoMedio;

    vector<int> f;
    vector<int> Fa;

    vector<double> fr;
    vector<double> Fra;

public:

    TablaFrecuencia(vector<double> d);

    void calcularClases();
    void calcularFrecuencias();
    void imprimirTabla();

    double CalcularMedia();
    double CalcularMediana();
    double CalcularModa();

};

#endif