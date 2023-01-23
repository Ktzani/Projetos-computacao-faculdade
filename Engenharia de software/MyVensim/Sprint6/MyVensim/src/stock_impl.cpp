#include "stock_impl.h"

// StockHandle::StockHandle(double value, string id) : value(value), ID(id) {} 
// StockHandle::StockHandle(const Stock& copia) : value(copia.getInitialValue()), ID(copia.getId()){}

// Stock& StockHandle::operator= (const Stock& sto){
//     if(this == &sto)
//         return *this;
        
//     this->value = sto.getInitialValue();
//     this->ID = sto.getId();

//     return *this;
// }

StockBody:: ~StockBody(){}

double  StockBody :: getInitialValue() const{
    return value;
}

void StockBody :: setInitialValue(double value){
    this->value = value;
}

string StockBody :: getId() const{
    return ID;
}

void StockBody :: setId(string id){
    this->ID = id;
}
