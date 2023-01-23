#ifndef UNIT_MODEL
#define UNIT_MODEL
#include "../../src/flow_impl.h"
#include "../../src/model_impl.h"
#include "../../src/stock_impl.h"

    void unit_Model_constructor( void);
    void unit_Model_destructor( void);
    void unit_Model_getCurrentTime( void);
    void unit_Model_setCurrentTime( void);
    void unit_Model_getInitialTime( void);
    void unit_Model_setInitialTime( void);
    void unit_Model_getFinalTime( void);
    void unit_Model_setFinalTime( void);
    void unit_Model_getId( void);
    void unit_Model_setId( void);
    void unit_Model_getStocks( void);
    void unit_Model_getFlows( void);
    void unit_Model_add( void);
    void unit_Model_remove( void);
    void unit_Model_run(void);
    void run_unit_tests_Model( void);

#endif