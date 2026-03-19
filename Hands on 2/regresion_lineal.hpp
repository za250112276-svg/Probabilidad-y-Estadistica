#ifndef regresionlineal_hpp
#define regresionlineal_hpp
#include<vector>
using namespace std;
class regresionlineal{
    vector <double> advertasing;
    vector <double> sales;
    double b0, b1;

    public:
    regresionlineal (vector <double> x, vector <double> y);
    void calcularmodelo ();
    double predecir (double x);
    double getb0 ();
    double getb1 ();

};




#endif 
