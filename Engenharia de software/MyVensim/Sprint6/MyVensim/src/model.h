#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <vector>
#include "stock.h"
#include "flow.h"

using namespace std;

/**
 * @brief Model Interface: Class responsible for making a Model with all the Inventories and Flows created by the 
 *        user and executing in each of the Flows its functions that will pass values ​​between the Stocks
 * 
 */
class Model{
public:
    
    /**
     * @brief Destroy the Model object
     * 
     */
    virtual ~Model(){}

    /**
     * @brief Create a Model object
     * 
     * @param initialTime 
     * @param finalTime 
     * @param id 
     * @return Model* that has been created
     */
    static Model* createModel(double initialTime, double finalTime, int id);

    /**
     * @brief Create a Stock object
     * 
     * @param value 
     * @param id 
     * @return Stock* that has been created
     */
    virtual Stock* createStock(double value, string id) = 0;

    /**
     * @brief Create a Flow object
     * 
     * @param source 
     * @param destiny 
     * @param id 
     * @param f 
     * @param varBool 
     * @return Flow* that has been created
     */
    virtual Flow* createFlow(Stock* source, Stock* destiny,  int id, double (*f) (Stock* sto), bool varBool) = 0;

    /**
     * @brief Get the Current Time object
     * 
     * @return double 
     */
    virtual double getCurrentTime() const = 0;

    /**
     * @brief Set the Current Time object
     * 
     * @param currentTime - New current time in each execution of the model
     */
    virtual void setCurrentTime(double currentTime) = 0;

    /**
     * @brief Get the Initial Time object
     * 
     * @return double returned the Initial time of the execution
     */
    virtual double getInitialTime() const = 0;

    /**
     * @brief Set the Initial Time object
     * 
     * @param initialTime - New initial time of the period of the execution Model
     */
    virtual void setInitialTime(double initialTime) = 0;

    /**
     * @brief Get the Final Time object
     * 
     * @return double returned the Final time of the execution
     */
    virtual double getFinalTime() const = 0;

    /**
     * @brief Set the Final Time object
     * 
     * @param finalTime - New final time of the period of the execution Model
     */
    virtual void setFinalTime(double finalTime) = 0;

    /**
     * @brief Get the Id object
     * 
     * @return int returned the ID of the Model, which identifies it
     */
    virtual int getId() const = 0;

    /**
     * @brief Set the Id object
     * 
     * @param id - New ID to identifies the Model
     */
    virtual void setId(int id) = 0;

    /**
     * @brief Get the Stocks object
     * 
     * @return vector <Stock*> returned all the Stocks added to the Model  
     */
    virtual vector <Stock*> getStocks() const = 0;
    
    /**
     * @brief Get the Flows object
     * 
     * @return vector <Flow*> returned all the Flows added to the Model  
     */
    virtual vector <Flow*> getFlows() const = 0;

    /**
     * @brief Removes a Stock from the Model by it ID (name)
     * 
     * @return true if the operation of removing the Stock it is sucessful
     * @return false if the operation of removing the Stock it isn't successful
     * 
     * @param idStock - name of the Stock which is going to be removed
     */

    virtual bool remove(string idStock) = 0;

    /**
     * @brief Removes a Flow from the Model by it ID (number)
     * 
     * @return true if the operation of removing the Flow it is sucessful
     * @return false if the operation of removing the Flow it isn't successful
     * 
     * @param idFlow - number of the Flow which is going to be removed
     */
    virtual bool remove(int idFlow) = 0;

    /**
     * @brief Runs all the functions of the Flows in a certain period of time
     *        and stores the value of each execution in each source and destiny
     * 
     * @return true if the execution of all Flows was successful
     * @return false if the execution of one of the Flows wasn´t successful
     */
    virtual bool run() = 0;

    /**
     * @brief prints the value of each Stock with it ID
     * 
     */
    virtual void print_results() = 0;

// protected:
//     /**
//      * @brief Adds a model to the factory
//      * 
//      * @param m - New Model to the factory
//      */
//     virtual void add(Model* m) = 0;

//     /**
//      * @brief Adds only a Stock to the Model
//      * 
//      * @param sto - New Stock to the Model
//      */
    
//     virtual void add(Stock* sto) = 0;

//     /**
//      * @brief Adds only a Flow to the Model
//      * 
//      * @param flu - New Flow to the Model
//      */
//     virtual void add(Flow* flu) = 0;

//     /**
//      * @brief Adds a Flow and its two Stocks to the Model
//      * 
//      * @param flu - New Flow to the Model
//      * @param source - New Stock to the Model (source of the Flow added)
//      * @param destiny - New Stock to the Model (destiny of the Flow added)
//      */
//     virtual void add(Flow* flu, Stock* source, Stock* destiny) = 0;

};

#endif