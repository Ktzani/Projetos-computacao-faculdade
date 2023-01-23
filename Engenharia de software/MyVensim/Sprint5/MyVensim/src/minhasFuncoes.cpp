#include "minhasFuncoes.h"

double exponencial(Stock* sto){
    return 0.01 * sto->getInitialValue();
}

double logistical(Stock* sto){
    return 0.01 * sto->getInitialValue() * (1 - sto->getInitialValue() / 70) ;
}