#ifndef FrequencyTable_hpp
#define FrequencyTable_hpp
#include<vector>
#include<string>

using namespace std; 

class FrequencyTable
{
private:
    vector <double> datos;
    int N;
    int k;
    double minimo;
    double maximo;
    double amplitud;

    vector <double> limiteinferior;
    vector <double> limitesuperior;
    vector <double> puntomedio;
    vector <int> f;
    vector <int> fa;
    vector <double> fr;
    vector <double> fra;

public:
    FrequencyTable(vector <double> d);
    void calcularclase();
    void calcularfrecuencia();
    void imprimirtable();
};






















#endif