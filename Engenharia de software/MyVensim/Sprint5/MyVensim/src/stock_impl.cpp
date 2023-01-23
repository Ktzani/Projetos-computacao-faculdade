#include "stock_impl.h"

// Stock::Stock(){}
MyStock::MyStock(double value, string id) : value(value), ID(id) {} 
MyStock::MyStock(const Stock& copia) : value(copia.getInitialValue()), ID(copia.getId()){}
    
MyStock:: ~MyStock(){}

Stock& MyStock::operator= (const Stock& sto){
    if(this == &sto)
        return *this;
        
    this->value = sto.getInitialValue();
    this->ID = sto.getId();

    return *this;
}

double  MyStock :: getInitialValue() const{
    return value;
}

void MyStock :: setInitialValue(double value){
    this->value = value;
}

string MyStock :: getId() const{
    return ID;
}

void MyStock :: setId(string id){
    this->ID = id;
}
