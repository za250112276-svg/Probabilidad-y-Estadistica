#ifndef dataset_hpp
#define datset_hpp 


class dataset{

    double llueve;
    double nollueve;
    double nublado;
    double nonublado;
    double nubladoperollueve;
    double nubladoperonollueve;
    double nonubladoperonollueve;
    double sinubladoperosillueve;
    double total; 

 
    public:
    dataset();

    void calcularmarginal();
    void calcularcondicional();
    void calcularconjunta();
    void mostrartotal();



};
#endif

