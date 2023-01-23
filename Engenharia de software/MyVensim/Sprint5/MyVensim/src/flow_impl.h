#ifndef FLOW_IMPL_H
#define FLOW_IMPL_H
#include <string.h>
#include <iostream>
#include "flow.h"
#include "stock.h"

using namespace std;

/**
 * @brief Class responsable to make a Flow which is going to pass by it a certain value decided by a function
 * 
 */
class MyFlow : public Flow{
    
protected:
    /**
     * @brief the source where the flow comes from
     * 
     */
    Stock *source;

    /**
     * @brief the destiny from which the flow arrives
     * 
     */
    Stock *destiny;

    /**
     * @brief the ID/name which identifies the Flow
     * 
     */
    int ID;

    /**
     * @brief the function which is going to be executed by each Flow 
     *        in the Model
     * 
     */
    double (*function) (Stock* sto);

    /**
     * @brief the last value of the executed function
     * 
     */
    double lastValue;

    /**
     * @brief the variable which identifies who is going to be used on
     *        the function (source or destiny)
     * 
     */
    bool varBool;

private:

    /**
     * @brief Construct a new copy Flow object 
     * 
     */
    MyFlow(const Flow&);

    /**
     * @brief Overload of the Assignment operator 
     * 
     * @return Flow& 
     */

    Flow& operator= (const Flow&);

public:
    // Flow();

    /**
     * @brief Construct a new My Flow object"
     * 
     */
    MyFlow(Stock* = nullptr, Stock* = nullptr, int = 0, double (*)(Stock*) = nullptr, bool = true);

    /**
     * @brief Destroy the Flow object
     * 
     */
    virtual ~MyFlow(); 

    /**
     * @brief Make the connection of two Stocks
     * 
     * @param source - Where the flow is coming from
     * @param destiny - Where the flow is arriving
     */
    void connection(Stock* source= nullptr, Stock* destiny = nullptr);

    /**
     * @brief Get the Source object
     * 
     * @return Stock* returned the Source of the Flow
     */
    Stock* getSource() const;

    /**
     * @brief Set the Source object
     * 
     * @param source - New Source for the Flow
     */
    void setSource(Stock* source);

    /**
     * @brief Get the Destiny object
     * 
     * @return Stock* returned the Destiny of the Flow
     */
    Stock* getDestiny() const;

    /**
     * @brief Set the Destiny object
     * 
     * @param destiny - New Destiny for the Flow
     */
    void setDestiny(Stock* destiny);

    /**
     * @brief Get the Last Value object
     * 
     * @return double returned the last value of the executed function
     */
    double getLastValue() const;

    /**
     * @brief Set the Last Value object
     * 
     * @param lastValue - New lastValue when execute the function for the Flow
     */
    void setLastValue(double lastValue);

    /**
     * @brief Get the Id object
     * 
     * @return int returned the ID of the Flow, which identifies it
     */
    int getId() const;

    /**
     * @brief Set the Id object
     * 
     * @param id - New ID to identifies the Flow
     * 
     */
    void setId(int id);

    /**
     * @brief Desconnects the source Stock from the Flow
     * 
     */
    void clearSource ();

    /**
     * @brief Desconnects the destiny Stock from the Flow
     * 
     */
    void clearDestiny ();

    /**
     * @brief Get the Var Bool object, which identifies which Stock (source or destiny)
     *        value will be used to execute the function of the Flow
     *        
     * @return true if it's going to use source 
     * @return false if it's going to use destiny
     */
    bool getVarBool() const ;

    /**
     * @brief Set the Var Bool object
     * 
     * @param varBool - New bool variable to know who is going to be used in the function
     * 
     */
    void setVarBool(bool varBool);

    /**
     * @brief Executes the function passed by the Constructor
     *        and save the value of this function in the variable 
     *        lastValue 
     */
    void execute();
    
};

#endif