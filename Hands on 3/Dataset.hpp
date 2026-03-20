#ifndef Dataset_hpp
#define Dataset_hpp
#include<vector>
#include<string>

using namespace std;

class Tablafrecuencia
{
private:
    vector <double> datos;
    vector <string> clase;
    vector <int> Frecuencias;
public:
 Tablafrecuencia(vector <double> d);

 void calcularfrecuencia ();

 void imprimirtabla ();

};



#endif
