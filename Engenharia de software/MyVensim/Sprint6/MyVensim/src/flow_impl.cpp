#include "flow_impl.h"

// function(copia.getFunction())

// FlowBody::FlowBody(Stock* source, Stock* destiny,  int id, double (*f) (Stock* sto), bool varBool) : source(source), destiny(destiny), ID(id), function(f), varBool(varBool) {} 
// FlowBody::FlowBody(const Flow& copia) : source(copia.getSource()), destiny(copia.getDestiny()), ID(copia.getId()),  varBool(copia.getVarBool()){} 

// Flow& FlowBody::operator=(const Flow& flu){
//     if(this == &flu)
//         return *this;
        
//     this->source = flu.getSource();
//     this->destiny = flu.getDestiny();
//     this->ID = flu.getId();

//     return *this;
// }

void FlowBody :: connection(Stock* source, Stock* destiny) {
    this->source = source;
    this->destiny = destiny;
}

void FlowBody :: setFunction(double (*f) (Stock* sto)){
    this->function = f;
}

Stock* FlowBody :: getSource() const{
    return source;
}

void FlowBody :: setSource(Stock* source) {
    this->source = source;
}

Stock* FlowBody :: getDestiny() const{
    return destiny;
}

void FlowBody :: setDestiny(Stock* destiny){
    this->destiny = destiny;
}

double FlowBody :: getLastValue() const{
    return lastValue;
}

void FlowBody :: setLastValue(double lastValue){
    this->lastValue = lastValue;
}

int FlowBody :: getId() const {
    return ID;
}

void FlowBody :: setId(int id) {
    this->ID = id;
}

void FlowBody :: clearSource(){
    source->setId("");
    source->setInitialValue(0);
    source = nullptr;

}

void FlowBody :: clearDestiny(){
    destiny->setId("");
    destiny->setInitialValue(0);
    destiny = nullptr;

}

bool FlowBody :: getVarBool() const {
    return varBool;
}

void FlowBody :: setVarBool(bool varBool) {
    this->varBool = varBool;
}

void FlowBody :: execute(){
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
