#ifndef STOCK_IMPL_H
#define STOCK_IMPL_H
#include <string.h>
#include <iostream>
#include "handleBody.h"

#include "stock.h"

using namespace std;

class StockBody: public Body{
protected:
    double value;

    string ID;


public:
    virtual ~StockBody();

    /**
     * @brief Get the Initial Value object
     * 
     * @return double returned value
     */

    double getInitialValue() const;
    
    /**
     * @brief Set the Initial Value object
     * 
     * @param value New initial Value for the Stock
     * 
     */
    void setInitialValue(double value);

    /**
     * @brief Get the Id object
     * 
     * @return string returned ID 
     */
    string getId() const;

    /**
     * @brief Set the Id object
     * 
     * @param id New ID for the Stock
     */
    void setId(string id);
};

/**
 * @brief Class responsible for storing a certain value that will be used later to execute functions 
 *        of the Flows and receive the result of these functions incremented or decremented from their values, 
 *        depending on which function is being used and if it is a Source or Destination Stock
 *     
 */

class StockHandle : public Stock, public Handle<StockBody>{
public:
    
    StockHandle(double value = 0, const string id = ""){
        pImpl_->setInitialValue(value);
        pImpl_->setId(id);
    }

    virtual ~StockHandle(){}

    double getInitialValue() const {return pImpl_->getInitialValue();}

    void setInitialValue(double value) {pImpl_->setInitialValue(value);}

    string getId() const {return pImpl_->getId();}

    void setId(string id) {pImpl_->setId(id);}

};

#endif