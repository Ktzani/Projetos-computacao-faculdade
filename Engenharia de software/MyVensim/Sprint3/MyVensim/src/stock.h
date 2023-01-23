#ifndef STOCK_H
#define STOCK_H
#include <string.h>
#include <iostream>

using namespace std;

/**
 * @brief Class responsible for storing a certain value that will be used later to execute functions 
 *        of the Flows and receive the result of these functions incremented or decremented from their values, 
 *        depending on which function is being used and if it is a Source or Destination Stock
 *     
 */

class Stock {
protected:
    /**
     * @brief Current Value of the Stock
     * 
     */
    double value;

    /**
     * @brief ID/Name of the Stock
     * 
     */
    string ID;

private:
    Stock(const Stock&);

    Stock& operator= (const Stock&);

public:
    Stock();

    /**
     * @brief Construct a new Stock object
     * 
     */
    Stock(double = 0, const string = "");

    /**
     * @brief Destroy the Stock object
     * 
     */

    virtual ~Stock(); 

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

#endif