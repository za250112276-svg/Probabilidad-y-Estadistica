#include "regresion_lineal.hpp"


regresionlineal::regresionlineal(vector <double> x, vector <double> y){
   advertasing = x;
    sales = y;
    b0 = 0;
    b1 = 1;
}

void regresionlineal::calcularmodelo (){
    int n = advertasing.size();
    double sumaX = 0;
    double sumaY = 0;
    double sumaX2 = 0;
    double sumaXY = 0;
    for (int i = 0; i < n; i++){
        sumaX += advertasing[i];
        sumaY += sales [i];
        sumaX2 += advertasing [i] * advertasing [i];
        sumaXY += advertasing [i] * sales [i];
    
        
    }
    b1 = (n * sumaXY - sumaX * sumaY)/(n * sumaX2 - sumaX * sumaX);
    b0 = (sumaX2 * sumaY - sumaX * sumaXY)/(n * sumaX2 - sumaX * sumaX);


}
double regresionlineal::predecir (double x){
    return b0 + b1 * x;
}
double regresionlineal::getb0 (){
    return b0;
}
double regresionlineal::getb1 (){
    return b1;
}




    
