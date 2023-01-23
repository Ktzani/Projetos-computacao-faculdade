#include <assert.h>
#include "unit_Stock.h"
#include <math.h>

void unit_Stock_constructor( void){
    cout << __func__ << "-> INICIO" << endl;
    Stock *s =  new MyStock();
    assert( s->getInitialValue() == 0);
    assert( s->getId() == "");
    
    //OU

    Stock *s1 = new MyStock(10, "Cano");
    assert( s1->getInitialValue() == 10);
    assert( s1->getId() == "Cano");

    delete s;
    cout << __func__ << "-> FIM" << endl;
}

void unit_Stock_destructor( void){}

void unit_Stock_getInitialValue( void){
    cout << __func__ << "-> INICIO" << endl;
    Stock *s = new MyStock(10);
    assert( s->getInitialValue() == 10 );

    delete s;
    cout << __func__ << "-> FIM" << endl;
}

void unit_Stock_setInitialValue( void ) {
    cout << __func__ << "-> INICIO" << endl;
    Stock *s = new MyStock();

    s->setInitialValue(20);

    assert( s->getInitialValue() == 20);

    delete s;
    cout << __func__ << "-> FIM" << endl;
    
}

void unit_Stock_getId( void){
    cout << __func__ << "-> INICIO" << endl;
    Stock *sto1 = new MyStock(10, "Casa");
    Stock *sto2 = new MyStock(300, "Abastecimento");

    assert ( sto1->getId() == "Casa");
    assert ( sto2->getId() == "Abastecimento");

    delete sto1;
    delete sto2;
    cout << __func__ << "-> FIM" << endl;
}

void unit_Stock_setId( void){
    cout << __func__ << "-> INICIO" << endl;
    Stock *sto1 = new MyStock(10);
    Stock *sto2 = new MyStock(300);

    sto1->setId("Casa");
    sto2->setId("Abastecimento");

    assert ( sto1->getId() == "Casa");
    assert ( sto2->getId() == "Abastecimento");

    delete sto1;
    delete sto2;
    cout << __func__ << "-> FIM" << endl;
}

void run_unit_tests_Stock( void ){
    unit_Stock_constructor();
    unit_Stock_destructor();
    unit_Stock_getInitialValue();
    unit_Stock_setInitialValue();
    unit_Stock_getId();
    unit_Stock_setId();
}
