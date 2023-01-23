#ifndef FUNCIONAL_TESTS_H
#define FUNCIONAL_TESTS_H
#include <string.h>
#include <iostream>
#include <assert.h>
#include <cmath>

#include "../../src/model.h"

#include "../../src/stock.h"

#include "../../src/flow.h"

using namespace std;
    /**
     * @brief test if the exponential function is working with the Stock, Flow and Model
     * 
     * @return true if it passed the functional test of the exponential function
     * @return false if it isn´t passed the functional test of the exponential function
     */
    bool exponentialFuncionalTest();

    /**
     * @brief test if the logistical function is working with the Stock, Flow and Model
     * 
     * @return true if it passed the functional test of the logistical function
     * @return false if it isn´t passed the functional test of the logistical function
     */
    bool logisticalFuncionalTest();

    /**
     * @brief test a complex Model with more than 2 Stocks and Flows that are interconnected
     * 
     * @return true if it passed the functional test of the complex Model
     * @return false if it isn´t passed the functional test of the complex Model
     */
    bool complexFuncionalTest();

#endif