#ifndef UNIT_FLOW
#define UNIT_FLOW
#include "../../src/flow_impl.h"
#include "../../src/model_impl.h"
#include "../../src/stock_impl.h"

        void unit_Flow_constructor( void);
        void unit_Flow_destructor( void);
        void unit_Flow_connection( void);
        void unit_Flow_getSource( void);
        void unit_Flow_getDestiny( void);
        void unit_Flow_setSource( void);
        void unit_Flow_setDestiny( void);
        void unit_Flow_getLastValue( void);
        void unit_Flow_setLastValue( void);
        void unit_Flow_getId( void);
        void unit_Flow_setId( void);
        void unit_Flow_clearSource( void);
        void unit_Flow_clearDestiny( void);
        void unit_Flow_getVarBool( void);
        void unit_Flow_setVarBool( void);
        void unit_Flow_execute(void);

        void run_unit_tests_Flow( void );
#endif