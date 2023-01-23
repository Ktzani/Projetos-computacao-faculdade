#include "flow_impl.h"

// function(copia.getFunction())

// Flow::Flow(){}
MyFlow::MyFlow(Stock* source, Stock* destiny,  int id, double (*f) (Stock* sto), bool varBool) : source(source), destiny(destiny), ID(id), function(f), varBool(varBool) {} 
MyFlow::MyFlow(const Flow& copia) : source(copia.getSource()), destiny(copia.getDestiny()), ID(copia.getId()),  varBool(copia.getVarBool()){} 
    
MyFlow:: ~MyFlow(){}

Flow& MyFlow::operator=(const Flow& flu){
    if(this == &flu)
        return *this;
        
    this->source = flu.getSource();
    this->destiny = flu.getDestiny();
    this->ID = flu.getId();

    return *this;
}

void MyFlow :: connection(Stock* source, Stock* destiny) {
    this->source = source;
    this->destiny = destiny;
}

Stock* MyFlow :: getSource() const{
    return source;
}

void MyFlow :: setSource(Stock* source) {
    this->source = source;
}

Stock* MyFlow :: getDestiny() const{
    return destiny;
}

void MyFlow :: setDestiny(Stock* destiny){
    this->destiny = destiny;
}

double MyFlow :: getLastValue() const{
    return lastValue;
}

void MyFlow :: setLastValue(double lastValue){
    this->lastValue = lastValue;
}

int MyFlow :: getId() const {
    return ID;
}

void MyFlow :: setId(int id) {
    this->ID = id;
}

void MyFlow :: clearSource(){
    source->setId("");
    source->setInitialValue(0);
    source = nullptr;

}

void MyFlow :: clearDestiny(){
    destiny->setId("");
    destiny->setInitialValue(0);
    destiny = nullptr;

}

bool MyFlow :: getVarBool() const {
    return varBool;
}

void MyFlow :: setVarBool(bool varBool) {
    this->varBool = varBool;
}

void MyFlow :: execute(){
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
