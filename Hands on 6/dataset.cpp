#include "dataset.hpp"
#include <iostream>

dataset::dataset(){
     llueve = 10;
     nollueve = 8;
     nublado = 9;
     nonublado = 9;
     nubladoperollueve = 7;
     nubladoperonollueve = 6;
     nonubladoperonollueve = 3;
     sinubladoperosillueve = 2;
     total = 18; 

}

void dataset::calcularcondicional(){
    std::cout << "Calculo Condicional\n " << std::endl;
    std::cout << "probabilidad de que si llueva dado que este nublado: " << nubladoperollueve / llueve << std::endl;
    std::cout << "probabilidad de que no llueva dado que este nublado: " << nubladoperonollueve / nollueve << std::endl;
    std::cout << "probabilidad de que no llueva dado que este nublado: " << nonubladoperonollueve / nollueve << std::endl;
    std::cout << "probabilidad de que si llueva dado que este nublado: " << sinubladoperosillueve / llueve << std::endl;
    
    
}
void dataset::calcularmarginal(){
    std::cout << "Calcular marginal\n " << std::endl;
    std::cout << "probabilidad de que si llueva: " << llueve / 18 << std::endl;
    std::cout << "probabilidad de que no llueva: " << nollueve / 18 << std::endl;
    std::cout << "probabilidad de que si llueva: " << nublado / 18 << std:: endl;
    std::cout << "probabilidad de que no llueva: " <<nonublado / 18 << std:: endl;
}
void dataset::calcularconjunta(){
    std::cout << "Calcular conjunta\n " << std::endl;
    std::cout << "probabilidad de que este nublado y si llueva : "  << nubladoperollueve / 18 << std::endl;
    std::cout <<  "probabilidad de que este nublado pero no llueva: " << nubladoperonollueve / 18 << std::endl;
    std::cout << "probabilidad de que este nublado y no llueva: " << nonubladoperonollueve / 18 << std::endl;
    std::cout << "probabilidad de que este nublado y si llueva: " << sinubladoperosillueve / 18 << std::endl;

}
void dataset::mostrartotal(){
    std::cout << "Este es el total\n " << std::endl;
     calcularmarginal();
     calcularcondicional();
     calcularconjunta();
}