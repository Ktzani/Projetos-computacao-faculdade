#ifndef FLOW_H
#define FLOW_H

#include <string>
#include "stock.h"

using namespace std;

/**
 * @brief Flow Interface: Class responsable to make a Flow which is going to pass by it a certain value decided by a function
 * 
 */
class Flow{
public:
    /**
     * @brief Destroy the Flow object
     * 
     */
    virtual ~Flow(){} 

    /**
     * @brief Make the connection of two Stocks
     * 
     * @param source - Where the flow is coming from
     * @param destiny - Where the flow is arriving
     */
    virtual void connection(Stock* source= nullptr, Stock* destiny = nullptr) = 0;

    /**
     * @brief Set the Function object
     * 
     * @param f - function that will be execute with this Flow
     */
    virtual void setFunction(double (*f)(Stock* sto) = nullptr) =0;

    /**
     * @brief Get the Source object
     * 
     * @return Stock* returned the Source of the Flow
     */
    virtual Stock* getSource() const = 0;

    /**
     * @brief Set the Source object
     * 
     * @param source - New Source for the Flow
     */
    virtual void setSource(Stock* source) = 0;

    /**
     * @brief Get the Destiny object
     * 
     * @return Stock* returned the Destiny of the Flow
     */
    virtual Stock* getDestiny() const = 0;

    /**
     * @brief Set the Destiny object
     * 
     * @param destiny - New Destiny for the Flow
     */
    virtual void setDestiny(Stock* destiny) = 0;

    /**
     * @brief Get the Last Value object
     * 
     * @return double returned the last value of the executed function
     */
    virtual double getLastValue() const = 0;

    /**
     * @brief Set the Last Value object
     * 
     * @param lastValue - New lastValue when execute the function for the Flow
     */
    virtual void setLastValue(double lastValue) = 0;

    /**
     * @brief Get the Id object
     * 
     * @return int returned the ID of the Flow, which identifies it
     */
    virtual int getId() const = 0;

    
    /**
     * @brief Set the Id object
     * 
     * @param id - New ID to identifies the Flow
     * 
     */
    virtual void setId(int id) = 0;

    /**
     * @brief Desconnects the source Stock from the Flow
     * 
     */
    virtual void clearSource () = 0;

    /**
     * @brief Desconnects the destiny Stock from the Flow
     * 
     */
    virtual void clearDestiny () = 0;

    /**
     * @brief Get the Var Bool object, which identifies which Stock (source or destiny)
     *        value will be used to execute the function of the Flow
     *        
     * @return true if it's going to use source 
     * @return false if it's going to use destiny
     */
    virtual bool getVarBool() const = 0;

    /**
     * @brief Set the Var Bool object
     * 
     * @param varBool - New bool variable to know who is going to be used in the function
     * 
     */
    virtual void setVarBool(bool varBool) = 0;

    /**
     * @brief Executes the function passed by the Constructor
     *        and save the value of this function in the variable 
     *        lastValue 
     */
    virtual void execute() = 0;
};

#endif