#include<iostream>
#include<vector>
#include "Dataset.hpp"

using namespace std;
int main()
{
    vector <double> Dataset = {12.3,15.6,14.2,18.7,21.4,19.5,22.1,17.8,16.4,20.2,};
    Tablafrecuencia tabla (Dataset);
    tabla.calcularfrecuencia ();
    tabla.imprimirtabla ();


    return 0;


}
