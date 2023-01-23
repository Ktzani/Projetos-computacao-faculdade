#include "unit_Model.h"
#include "../../src/minhasFuncoes.h"
#include <math.h>
#include <assert.h>

void unit_Model_constructor( void){
    cout << __func__ << "-> INICIO" << endl;

    Model *m = new ModelHandle();

    assert(m->getInitialTime() == 0);
    assert(m->getFinalTime() == 100);
    assert(m->getId() == 0);

    //OU

    Model *m1 = new ModelHandle(50, 200, 1);

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
    Model *m = Model::createModel(0, 100, 1);
    Stock *source = m->createStock(100, "sou");
    Stock *destiny = m->createStock(400, "des");

    Flow *flu = m->createFlow(source, destiny, 1, exponencial, true);

    m->run();

    assert(m->getCurrentTime() == 99);

    // Model::deleteModel(1);
    cout << __func__ << "-> FIM" << endl;

}

void unit_Model_setCurrentTime( void){
    cout << __func__ << "-> INICIO" << endl;
    Model *m = new ModelHandle(0, 100, 1);

    m->setCurrentTime(50);

    assert(m->getCurrentTime() == 50);

    delete(m);

    cout << __func__ << "-> FIM" << endl;
}

void unit_Model_getInitialTime( void){
    cout << __func__ << "-> INICIO" << endl;
    Model *m = new ModelHandle(0, 100, 1);

    assert(m->getInitialTime() == 0);

    delete(m);

    cout << __func__ << "-> FIM" << endl;
}

void unit_Model_setInitialTime( void){
    cout << __func__ << "-> INICIO" << endl;
    Model *m = new ModelHandle();

    m->setInitialTime(0);

    assert(m->getInitialTime() == 0);

    delete(m);

    cout << __func__ << "-> FIM" << endl;
}

void unit_Model_getFinalTime( void){
    cout << __func__ << "-> INICIO" << endl;
    Model *m = new ModelHandle(0, 100, 1);

    assert(m->getFinalTime() == 100);

    delete(m);

    cout << __func__ << "-> FIM" << endl;
}

void unit_Model_setFinalTime( void){
    cout << __func__ << "-> INICIO" << endl;
    Model *m = new ModelHandle();

    m->setFinalTime(100);

    assert(m->getFinalTime() == 100);

    delete(m);

    cout << __func__ << "-> FIM" << endl;
}

void unit_Model_getId( void){
    cout << __func__ << "-> INICIO" << endl;
    Model *m = new ModelHandle(0, 100, 1);

    assert(m->getId() == 1);

    delete(m);

    cout << __func__ << "-> FIM" << endl;
}

void unit_Model_setId( void){
    cout << __func__ << "-> INICIO" << endl;
    Model *m = new ModelHandle();
     
    m->setId(1);

    assert(m->getId() == 1);

    delete(m);

    cout << __func__ << "-> FIM" << endl;
}

void unit_Model_getStocks( void){
    cout << __func__ << "-> INICIO" << endl;
    Model *m = Model::createModel(0, 100, 1);
    Stock *source = m->createStock(100, "sou");
    Stock *destiny = m->createStock(400, "des");

    m->createFlow(source, destiny, 1, exponencial, true);

    vector <Stock*> stocks = {source, destiny};

    assert(m->getStocks() == stocks);

    // Model::deleteModel(1);
    
    cout << __func__ << "-> FIM" << endl;
}

void unit_Model_getFlows( void){
    cout << __func__ << "-> INICIO" << endl;
    Model *m =  Model::createModel(0, 100, 1);
    Stock *source1 = m->createStock(100, "sou1");
    Stock *destiny1 = m->createStock(400, "des1");

    Stock *source2 = m->createStock(100, "sou2");
    Stock *destiny2 = m->createStock(400, "des2");

    Flow *flu1 = m->createFlow(source1, destiny1, 1, exponencial, true);
    Flow *flu2 = m->createFlow(source2, destiny2, 2, logistical, false);

    vector <Flow*> flows = {flu1, flu2};

    assert(m->getFlows() == flows);

    // Model::deleteModel(1);

    cout << __func__ << "-> FIM" << endl;
}

void unit_Model_add( void){
    cout << __func__ << "-> INICIO" << endl;
    Model *m1 =  Model::createModel(0, 100, 1);
    Stock *source1 = m1->createStock(100, "sou1");
    Stock *destiny1 = m1->createStock(400, "des1");

    Flow *flu1 = m1->createFlow(source1, destiny1, 1, exponencial, true);

    vector <Stock*> stocks = {source1, destiny1};
    vector <Flow*> flows = {flu1};

    assert(m1->getStocks() == stocks);

    assert(m1->getFlows() == flows);

    //OUU

    Model *m2 =  Model::createModel(0, 100, 2);
    Stock *source2 = m2->createStock(100, "sou1");
    Stock *destiny2 = m2->createStock(400, "des1");

    Flow *flu2 = m2->createFlow(source1, destiny1, 1, exponencial, true);

    vector <Stock*> stocks2 = {source2, destiny2};

    vector <Flow*> flows2 = {flu2};

    assert(m2->getStocks() == stocks2);
    assert(m2->getFlows() == flows2);

    // Model::deleteModel(1);
    // Model::deleteModel(2);

    cout << __func__ << "-> FIM" << endl;
}

void unit_Model_remove( void){
    cout << __func__ << "-> INICIO" << endl;
    Model *m = Model::createModel(0, 100, 1);
    Stock *source = m->createStock(100, "Casa");
    Stock *destiny = m->createStock(400, "Esgoto");

    Flow *flu = m->createFlow(source, destiny, 1, exponencial, true);

    m->remove("Casa");
    m->remove("Esgoto");
    m->remove(1);

    assert(m->getStocks().empty() == true);
    assert(m->getFlows().empty() == true);

    // Model::deleteModel(1);
    
    cout << __func__ << "-> FIM" << endl;
}

void unit_Model_run(void){
    cout << __func__ << "-> INICIO" << endl;
    Model *m = Model::createModel(0, 100, 0);
        
    Stock *source = m->createStock(100, "P1");
    Stock *destiny = m->createStock(10, "P2");
    
    Flow *flu = m->createFlow(source, destiny, 0, logistical, false);

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

    // Model::deleteModel(0);
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