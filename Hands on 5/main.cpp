#include <iostream>
#include <vector>
#include "TablaFrecuencia.hpp"

using namespace std;

int main() {

    vector<double> dataset = {

        25,28,30,32,34,36,38,40,42,44,
        46,48,50,52,54,56,58,60,62,64,
        66,68,70,72,74,76,27,33,41,59,
        67

    };

    TablaFrecuencia tabla(dataset);

    tabla.calcularClases();

    tabla.calcularFrecuencias();

    tabla.imprimirTabla();

    return 0;
}