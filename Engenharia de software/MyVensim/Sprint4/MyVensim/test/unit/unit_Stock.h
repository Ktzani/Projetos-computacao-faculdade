#ifndef UNIT_STOCK
#define UNIT_STOCK
#include "../../src/flow_impl.h"
#include "../../src/model_impl.h"
#include "../../src/stock_impl.h"

        void unit_Stock_constructor( void);
        void unit_Stock_destructor( void);
        void unit_Stock_getInitialValue( void);
        void unit_Stock_setInitialValue( void);
        void unit_Stock_getId( void);
        void unit_Stock_setId( void);

        void run_unit_tests_Stock( void );
#endif