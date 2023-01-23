#ifndef MODEL_H
#define MODEL_H
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "stock.h"
#include "flow.h"

using namespace std;

/**
 * @brief Class responsible for making a Model with all the Inventories and Flows created by the 
 *        user and executing in each of the Flows its functions that will pass values ​​between the Stocks
 *      
 */
class Model {
protected:

    /**
     * @brief vector which store all the Stocks added in the Model
     * 
     */
    vector <Stock*> stocks;

    /**
     * @brief vector which store all the Flows added in the Model
     * 
     */
    vector <Flow*> flows;

    /**
     * @brief the current time when running the Model
     * 
     */
    double currentTime;

    /**
     * @brief when the model is going to start to run
     * 
     */
    double initialTime;

    /**
     * @brief when the model finalizes the execution
     * 
     */
    double finalTime;

    /**
     * @brief the ID/name which identifies the Model
     * 
     */
    int ID;

private:
    Model(const Model&);

    Model& operator= (const Model&);

public:
    Model();

    /**
     * @brief Construct a new Model object
     * 
     */
    Model(double = 0, double = 100, int = 0);

    /**
     * @brief Destroy the Model object
     * 
     */
    virtual ~Model(); 

    /**
     * @brief Get the Current Time object
     * 
     * @return double 
     */
    double getCurrentTime() const;

    /**
     * @brief Set the Current Time object
     * 
     * @param currentTime - New current time in each execution of the model
     */
    void setCurrentTime(double currentTime);

    /**
     * @brief Get the Initial Time object
     * 
     * @return double returned the Initial time of the execution
     */
    double getInitialTime() const;

    /**
     * @brief Set the Initial Time object
     * 
     * @param initialTime - New initial time of the period of the execution Model
     */
    void setInitialTime(double initialTime);

    /**
     * @brief Get the Final Time object
     * 
     * @return double returned the Final time of the execution
     */

    double getFinalTime() const;

    /**
     * @brief Set the Final Time object
     * 
     * @param finalTime - New final time of the period of the execution Model
     */
    void setFinalTime(double finalTime);

    /**
     * @brief Get the Id object
     * 
     * @return int returned the ID of the Model, which identifies it
     */
    int getId() const;

    /**
     * @brief Set the Id object
     * 
     * @param id - New ID to identifies the Model
     */
    void setId(int id);

    /**
     * @brief Get the Stocks object
     * 
     * @return vector <Stock*> returned all the Stocks added to the Model  
     */
    vector <Stock*> getStocks() const;

    /**
     * @brief Get the Flows object
     * 
     * @return vector <Flow*> returned all the Flows added to the Model  
     */
    vector <Flow*> getFlows() const;

    /**
     * @brief Adds only a Stock to the Model
     * 
     * @param sto - New Stock to the Model
     */
    void add(Stock* sto);

    /**
     * @brief Adds only a Flow to the Model
     * 
     * @param flu - New Flow to the Model
     */
    void add(Flow* flu);

    /**
     * @brief Adds a Flow and its two Stocks to the Model
     * 
     * @param flu - New Flow to the Model
     * @param source - New Stock to the Model (source of the Flow added)
     * @param destiny - New Stock to the Model (destiny of the Flow added)
     */
    void add(Flow* flu, Stock* source, Stock* destiny);

    /**
     * @brief Removes a Stock from the Model by it ID (name)
     * 
     * @return true if the operation of removing the Stock it is sucessful
     * @return false if the operation of removing the Stock it isn't successful
     * 
     * @param idStock - name of the Stock which is going to be removed
     */
    bool remove(string idStock);

    /**
     * @brief Removes a Flow from the Model by it ID (number)
     * 
     * @return true if the operation of removing the Flow it is sucessful
     * @return false if the operation of removing the Flow it isn't successful
     * 
     * @param idFlow - number of the Flow which is going to be removed
     */
    bool remove(int idFlow);

    /**
     * @brief Runs all the functions of the Flows in a certain period of time
     *        and stores the value of each execution in each source and destiny
     * 
     * @return true if the execution of all Flows was successful
     * @return false if the execution of one of the Flows wasn´t successful
     */
    bool run();

    /**
     * @brief prints the value of each Stock with it ID
     * 
     */
    void print_results();
};


#endif