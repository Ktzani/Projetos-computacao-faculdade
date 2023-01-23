#include "unit_Model.h"
#include "../../src/minhasFuncoes.h"
#include <math.h>
#include <assert.h>

void unit_Model_constructor( void){
    cout << __func__ << "-> INICIO" << endl;

    Model *m = new MyModel();

    assert(m->getInitialTime() == 0);
    assert(m->getFinalTime() == 100);
    assert(m->getId() == 0);

    //OU

    Model *m1 = new MyModel(50, 200, 1);

    assert(m1->getInitialTime() == 50);
    assert(m1->getFinalTime() == 200);
    assert(m1->getId() == 1);
    cout << __func__ << "-> FIM" << endl;
    
    delete (m);
    delete (m1);
}

void unit_Model_destructor( void){}

void unit_Model_getCurrentTime( void){
    cout << __func__ << "-> INICIO" << endl;
    Model *m = new MyModel(0, 100, 1);
    Stock *source = new MyStock(100);
    Stock *destiny = new MyStock(400);
    Flow * flu1 = new MyFlow(source, destiny, 1, exponencial, true);
    
    m->add(flu1, source, destiny);

    m->run();

    assert(m->getCurrentTime() == 99);

    delete(m);
    delete(source);
    delete(destiny);
    delete(flu1);
    cout << __func__ << "-> FIM" << endl;

}

void unit_Model_setCurrentTime( void){
    cout << __func__ << "-> INICIO" << endl;
    Model *m = new MyModel(0, 100, 1);

    m->setCurrentTime(50);

    assert(m->getCurrentTime() == 50);

    delete(m);

    cout << __func__ << "-> FIM" << endl;
}

void unit_Model_getInitialTime( void){
    cout << __func__ << "-> INICIO" << endl;
    Model *m = new MyModel(0, 100, 1);

    assert(m->getInitialTime() == 0);

    delete(m);

    cout << __func__ << "-> FIM" << endl;
}

void unit_Model_setInitialTime( void){
    cout << __func__ << "-> INICIO" << endl;
    Model *m = new MyModel();

    m->setInitialTime(0);

    assert(m->getInitialTime() == 0);

    delete(m);

    cout << __func__ << "-> FIM" << endl;
}

void unit_Model_getFinalTime( void){
    cout << __func__ << "-> INICIO" << endl;
    Model *m = new MyModel(0, 100, 1);

    assert(m->getFinalTime() == 100);

    delete(m);

    cout << __func__ << "-> FIM" << endl;
}

void unit_Model_setFinalTime( void){
    cout << __func__ << "-> INICIO" << endl;
    Model *m = new MyModel();

    m->setFinalTime(100);

    assert(m->getFinalTime() == 100);

    delete(m);

    cout << __func__ << "-> FIM" << endl;
}

void unit_Model_getId( void){
    cout << __func__ << "-> INICIO" << endl;
    Model *m = new MyModel(0, 100, 1);

    assert(m->getId() == 1);

    delete(m);

    cout << __func__ << "-> FIM" << endl;
}

void unit_Model_setId( void){
    cout << __func__ << "-> INICIO" << endl;
    Model *m = new MyModel();
     
    m->setId(1);

    assert(m->getId() == 1);

    delete(m);

    cout << __func__ << "-> FIM" << endl;
}

void unit_Model_getStocks( void){
    cout << __func__ << "-> INICIO" << endl;
    Model *m = new MyModel(0, 100, 1);
    Stock *source = new MyStock(100);
    Stock *destiny = new MyStock(400);
    Flow * flu1 = new MyFlow(source, destiny, 1, exponencial, true);
    
    m->add(flu1, source, destiny);

    vector <Stock*> stocks = {source, destiny};

    assert(m->getStocks() == stocks);

    delete(m);
    delete(source);
    delete(destiny);
    delete(flu1);
    
    cout << __func__ << "-> FIM" << endl;
}

void unit_Model_getFlows( void){
    cout << __func__ << "-> INICIO" << endl;
    Model *m = new MyModel(0, 100, 1);
    Stock *source1 = new MyStock(100);
    Stock *destiny1 = new MyStock(400);

    Stock *source2 = new MyStock(100);
    Stock *destiny2 = new MyStock(400);

    Flow * flu1 = new MyFlow(source1, destiny1, 1, exponencial, true);
    Flow * flu2 = new MyFlow(source2, destiny2, 2, logistical, false);

    m->add(flu1, source1, destiny1);
    m->add(flu2, source2, destiny2);

    vector <Flow*> flows = {flu1, flu2};

    assert(m->getFlows() == flows);
    cout << __func__ << "-> FIM" << endl;

    delete (m);
    delete (source1);
    delete (destiny1);
    delete (source2);
    delete (destiny2);
    delete (flu1);
    delete (flu2);

}

void unit_Model_add( void){
    cout << __func__ << "-> INICIO" << endl;
    Model *m1 = new MyModel(0, 100, 1);
    Stock *source1 = new MyStock(100);
    Stock *destiny1 = new MyStock(400);

    Flow * flu1 = new MyFlow(source1, destiny1, 1, exponencial, true);

    m1->add(flu1);
    m1->add(source1);
    m1->add(destiny1);

    vector <Stock*> stocks = {source1, destiny1};
    vector <Flow*> flows = {flu1};

    assert(m1->getStocks() == stocks);
    assert(m1->getFlows() == flows);

    //OUU

    Model *m2 = new MyModel(0, 100, 1);
    Stock *source2 = new MyStock(100);
    Stock *destiny2 = new MyStock(400);

    Flow * flu2 = new MyFlow(source2, destiny2, 1, exponencial, true);
    
    m2->add(flu2, source2, destiny2);

    vector <Stock*> stocks2 = {source2, destiny2};

    vector <Flow*> flows2 = {flu2};

    assert(m2->getStocks() == stocks2);
    assert(m2->getFlows() == flows2);

    delete (m1);
    delete (m2);
    delete (source1);
    delete (destiny1);
    delete (source2);
    delete (destiny2);
    delete (flu1);
    delete (flu2);

    cout << __func__ << "-> FIM" << endl;
}

void unit_Model_remove( void){
    cout << __func__ << "-> INICIO" << endl;
    Model *m = new MyModel(0, 100, 1);
    Stock *source = new MyStock(100, "Casa");
    Stock *destiny = new MyStock(400, "Esgoto");
    Flow * flu1 = new MyFlow(source, destiny, 1, exponencial, true);
    
    m->add(flu1, source, destiny);

    m->remove("Casa");
    m->remove("Esgoto");
    m->remove(1);

    assert(m->getStocks().empty() == true);
    assert(m->getFlows().empty() == true);

    delete(m);
    delete(source);
    delete(destiny);
    delete(flu1);
    
    cout << __func__ << "-> FIM" << endl;
}

void unit_Model_run(void){
    cout << __func__ << "-> INICIO" << endl;
    Model *m = new MyModel(0, 100, 0);
        
    Stock *source = new MyStock(100, "P1");
    Stock *destiny = new MyStock(10, "P2");
    
    Flow * flu = new MyFlow(source, destiny, 0, logistical, false);

    m->add(flu, source, destiny);

    m->run();
    
    double sourceFinalResult;
    double destinyFinalResult;
    for(Stock* elem : m->getStocks()){
        if(elem->getId() == "P1"){
            sourceFinalResult = elem->getInitialValue();
        }
        if (elem->getId() == "P2"){
            destinyFinalResult = elem->getInitialValue();
        }
    }
    assert( fabs(sourceFinalResult - 88.2167) < 0.0001);
    assert( fabs(destinyFinalResult - 21.7833) < 0.0001);

    delete(m);
    delete(source);
    delete(destiny);
    delete(flu);
    cout << __func__ << "-> FIM" << endl;
}

void run_unit_tests_Model( void){
    unit_Model_constructor ();
    unit_Model_destructor ();
    unit_Model_getCurrentTime();
    unit_Model_setCurrentTime();
    unit_Model_getInitialTime();
    unit_Model_setInitialTime();
    unit_Model_getFinalTime ();
    unit_Model_setFinalTime ();
    unit_Model_getId ();
    unit_Model_setId ();
    unit_Model_getStocks();
    unit_Model_getFlows ();
    unit_Model_add ();
    unit_Model_remove ();
    unit_Model_run();
}