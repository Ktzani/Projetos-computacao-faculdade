#ifndef STOCK_H
#define STOCK_H

#include <string>

using namespace std;

/**
 * @brief Stock Interface: Class responsible for storing a certain value that will be used later to execute functions 
 *    of the Flows and receive the result of these functions incremented or decremented from their values, 
 *    depending on which function is being used and if it is a Source or Destination Stock
 * 
 * 
 */
class Stock{
public:
    /**
     * @brief Destroy the Stock object
     * 
     */
    virtual ~Stock(){} 

    /**
     * @brief Get the Initial Value object
     * 
     * @return double returned value
     */
    virtual double getInitialValue() const = 0;

    /**
     * @brief Set the Initial Value object
     * 
     * @param value New initial Value for the Stock
     * 
     */
    virtual void setInitialValue(double value) = 0;

    /**
     * @brief Get the Id object
     * 
     * @return string returned ID 
     */
    virtual string getId() const = 0;

    /**
     * @brief Set the Id object
     * 
     * @param id New ID for the Stock
     */
    virtual void setId(string id) = 0;
};

#endif