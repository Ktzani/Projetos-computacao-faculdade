#include "unit_Flow.h"
#include "../../src/minhasFuncoes.h"
#include <math.h>
#include <assert.h>

void unit_Flow_constructor( void){

    cout << __func__ << "-> INICIO" << endl;
    Flow *flu = new MyFlow();
    assert(flu->getSource() == nullptr);
    assert(flu->getDestiny() == nullptr);
    assert(flu->getId() == 0);
    assert(flu->getVarBool() == true);

    //OU

    Stock *source = new MyStock(100);
    Stock *destiny = new MyStock(400);
    Flow *flu1 = new MyFlow( source,  destiny, 1, exponencial, true);

    assert(flu1->getSource() == source);
    assert(flu1->getDestiny() == destiny);
    assert(flu1->getId() == 1);
    assert(flu1->getVarBool() == true);

    delete flu;
    delete source;
    delete destiny;
    delete flu1;

    cout << __func__ << "-> FIM" << endl;
}

void unit_Flow_destructor( void){}

void unit_Flow_connection( void){
    cout << __func__ << "-> INICIO" << endl;
    Stock *source = new MyStock(100);
    Stock *destiny = new MyStock(400);

    Flow *flu1 = new MyFlow();

    flu1->connection( source,  destiny);

    assert(flu1->getSource()->getInitialValue() == 100);
    assert(flu1->getDestiny()->getInitialValue() == 400);

    delete source;
    delete destiny;
    delete flu1;

    cout << __func__ << "-> FIM" << endl;
}

void unit_Flow_getSource( void){
    cout << __func__ << "-> FIM" << endl;
    Stock *source = new MyStock(100);

    Flow *flu1 = new MyFlow( source, nullptr);

    assert(flu1->getSource() ==  source);

    delete source;
    delete flu1;
    cout << __func__ << "-> FIM" << endl;
}

void unit_Flow_getDestiny( void){
    cout << __func__ << "-> INICIO" << endl;
    Stock *destiny = new MyStock(400);

    Flow *flu1 = new MyFlow(nullptr,  destiny);

    assert(flu1->getDestiny() ==  destiny);

    delete destiny;
    delete flu1;
    cout << __func__ << "-> FIM" << endl;
}

void unit_Flow_setSource( void){
    cout << __func__ << "-> INICIO" << endl;
    Stock *source = new MyStock(100);

    Flow *flu1 = new MyFlow();

    flu1->setSource( source);

    assert(flu1->getSource() ==  source);
    
    delete source;
    delete flu1;
    cout << __func__ << "-> FIM" << endl;
}

void unit_Flow_setDestiny( void){
    cout << __func__ << "-> INICIO" << endl;
    Stock *destiny = new MyStock(400);

    Flow *flu1 = new MyFlow();

    flu1->setDestiny( destiny);

    assert(flu1->getDestiny() ==  destiny);

    delete destiny;
    delete flu1;
    cout << __func__ << "-> FIM" << endl;
}

void unit_Flow_getLastValue( void) {
    cout << __func__ << "-> INICIO" << endl;
    Stock *source = new MyStock(100);
    Stock *destiny = new MyStock(400);
    Flow *flu1 = new MyFlow( source,  destiny, 1, exponencial, true);

    flu1->execute();

    assert(flu1->getLastValue() == 1);

    flu1->setVarBool(false);

    flu1->execute();

    assert(flu1->getLastValue() == 4);

    delete source;
    delete destiny;
    delete flu1;
    cout << __func__ << "-> FIM" << endl;

}

void unit_Flow_setLastValue( void) {
    cout << __func__ << "-> INICIO" << endl;
    Stock *source = new MyStock(100);
    Stock *destiny = new MyStock(400);
    Flow *flu1 = new MyFlow( source,  destiny, 1, exponencial, true);

    flu1->setLastValue(10);

    assert(flu1->getLastValue() == 10);

    delete source;
    delete destiny;
    delete flu1;

    cout << __func__ << "-> FIM" << endl;
}

void unit_Flow_getId( void) {
    cout << __func__ << "-> INICIO" << endl;
    Stock *source = new MyStock(100);
    Stock *destiny = new MyStock(400);
    Flow *flu1 = new MyFlow( source,  destiny, 1, exponencial, true);

    assert(flu1->getId() == 1);

    delete source;
    delete destiny;
    delete flu1;
    cout << __func__ << "-> FIM" << endl;
}

void unit_Flow_setId( void) {
    cout << __func__ << "-> INICIO" << endl;
    Stock *source = new MyStock(100);
    Stock *destiny = new MyStock(400);
    Flow *flu1 = new MyFlow( source,  destiny);

    flu1->setId(1);

    assert(flu1->getId() == 1);

    delete source;
    delete destiny;
    delete flu1;
    cout << __func__ << "-> FIM" << endl;
}

void unit_Flow_clearSource( void) {
    cout << __func__ << "-> INICIO" << endl;
    Stock *source = new MyStock(100);
    Stock *destiny = new MyStock(400);
    Flow *flu1 = new MyFlow( source,  destiny);

    flu1->clearSource();

    assert(flu1->getSource() == nullptr);
    assert(flu1->getDestiny() ==  destiny);

    delete source;
    delete destiny;
    delete flu1;
    cout << __func__ << "-> FIM" << endl;
}

void unit_Flow_clearDestiny( void){
    cout << __func__ << "-> INICIO" << endl;
    Stock *source = new MyStock(100);
    Stock *destiny = new MyStock(400);
    Flow *flu1 = new MyFlow( source,  destiny);

    flu1->clearDestiny();

    assert(flu1->getSource() ==  source);
    assert(flu1->getDestiny() == nullptr);

    delete source;
    delete destiny;
    delete flu1;
    cout << __func__ << "-> FIM" << endl;
}

void unit_Flow_getVarBool( void) {
    cout << __func__ << "-> INICIO" << endl;
    Stock *source = new MyStock(100);
    Stock *destiny = new MyStock(400);
    Flow *flu1 = new MyFlow( source,  destiny, 1, exponencial, true);

    assert(flu1->getVarBool() == true);

    delete source;
    delete destiny;
    delete flu1;
    cout << __func__ << "-> FIM" << endl;
}

void unit_Flow_setVarBool( void){
    cout << __func__ << "-> INICIO" << endl;
    Stock *source = new MyStock(100);
    Stock *destiny = new MyStock(400);
    Flow *flu1 = new MyFlow( source,  destiny, 1, exponencial);

    flu1->setVarBool(true);

    assert(flu1->getVarBool() == true);

    delete source;
    delete destiny;
    delete flu1;
    cout << __func__ << "-> FIM" << endl;
}

void unit_Flow_execute(void){
    cout << __func__ << "-> INICIO" << endl;
    Stock *source = new MyStock(100);
    Stock *destiny  = new MyStock(0);
    Flow *flu1 = new MyFlow( source,  destiny, 1, exponencial, true);

    flu1->execute();

    assert(flu1->getLastValue() == 1);

    delete source;
    delete destiny;
    delete flu1;
    cout << __func__ << "-> FIM" << endl;
}

void run_unit_tests_Flow( void ){
    unit_Flow_constructor ();
    unit_Flow_destructor ();
    unit_Flow_connection ();
    unit_Flow_getSource ();
    unit_Flow_getDestiny ();
    unit_Flow_setSource ();
    unit_Flow_setDestiny ();
    unit_Flow_getLastValue ();
    unit_Flow_setLastValue ();
    unit_Flow_getId ();
    unit_Flow_setId ();
    unit_Flow_clearSource ();
    unit_Flow_clearDestiny ();
    unit_Flow_getVarBool ();
    unit_Flow_setVarBool ();
    unit_Flow_execute ();
}