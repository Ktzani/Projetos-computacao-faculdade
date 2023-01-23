#include "flow.h"

Flow::Flow(){}
Flow::Flow(Stock* source, Stock* destiny,  int id, double (*f) (Stock* sto), bool varBool) : source(source), destiny(destiny), ID(id), function(f), varBool(varBool) {} 
Flow::Flow(const Flow& copia) : source(copia.source), destiny(copia.destiny), ID(copia.ID), function(copia.function), varBool(copia.varBool){} 
    
Flow:: ~Flow(){}

Flow& Flow::operator=(const Flow& flu){
    if(this == &flu)
        return *this;
        
    this->source = flu.source;
    this->destiny = flu.destiny;
    this->ID = flu.ID;
    this->function = flu.function;

    return *this;
}

void Flow :: connection(Stock* source, Stock* destiny) {
    this->source = source;
    this->destiny = destiny;
}

Stock* Flow :: getSource() const{
    return source;
}

void Flow :: setSource(Stock* source) {
    this->source = source;
}

Stock* Flow :: getDestiny() const{
    return destiny;
}

void Flow :: setDestiny(Stock* destiny){
    this->destiny = destiny;
}

double Flow :: getLastValue() const{
    return lastValue;
}

void Flow :: setLastValue(double lastValue){
    this->lastValue = lastValue;
}

int Flow :: getId() const {
    return ID;
}

void Flow :: setId(int id) {
    this->ID = id;
}

void Flow :: clearSource(){
    source->setId("");
    source->setInitialValue(0);
    source = nullptr;

    delete(source);
}

void Flow :: clearDestiny(){
    destiny->setId("");
    destiny->setInitialValue(0);
    destiny = nullptr;

    delete(destiny);
}

bool Flow :: getVarBool() const {
    return varBool;
}

void Flow :: setVarBool(bool varBool) {
    this->varBool = varBool;
}

void Flow :: execute(){
    double value;
    if(this->varBool){

        value = function(this->getSource());
        this->setLastValue(value);
    } 

    else{
        value = function(this->getDestiny());
        this->setLastValue(value);
    } 
}
