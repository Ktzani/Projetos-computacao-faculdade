#include "stock.h"

Stock::Stock(){}
Stock::Stock(double value, string id, bool varBool) : value(value), ID(id) {} 
Stock::Stock(const Stock& copia) : value(copia.value), ID(copia.ID){}
    
Stock:: ~Stock(){}

Stock& Stock::operator= (const Stock& sto){
    this->value = sto.value;
    this->ID = sto.ID;

    return *this;
}

double Stock :: getInitialValue() const{
    return value;
}

void Stock :: setInitialValue(double value){
    this->value = value;
}

string Stock :: getId() const{
    return ID;
}

void Stock :: setId(string id){
    this->ID = id;
}
