#ifndef MODEL_IMPL_H
#define MODEL_IMPL_H
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>

#include "handleBody.h"
#include "model.h"

using namespace std;

/**
 * @brief Class responsible for making a Model with all the Inventories and Flows created by the 
 *        user and executing in each of the Flows its functions that will pass values ​​between the Stocks
 *      
 */
class ModelBody : public Body{
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

    static vector<Model*> models;

private:
    // MyModel(const Model&);

    // Model& operator= (const Model&);

    /**
     * @brief Adds a model to the factory
     * 
     * @param m - New Model to the factory
     */
    void add(Model* m);

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

public:


    /**
     * @brief Construct a new Model object
     * 
     */
    // MyModel(double = 0, double = 100, int = 0);

    /**
     * @brief Destroy the Model object
     * 
     */
    // virtual ~MyModel(); 

    ModelBody();

    virtual ~ModelBody();

    static Model* createModel(double initialTime, double finalTime, int id);

    Stock* createStock(double value, string id);

    Flow* createFlow(Stock* source, Stock* destiny,  int id, double (*f) (Stock* sto), bool varBool);

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

class ModelHandle: public Model, public Handle<ModelBody> {
public:
    // MyModel(const Model&);

    // Model& operator= (const Model&);

    ModelHandle(double initialTime = 0, double finalTime = 100, int id = 0){
        pImpl_->setInitialTime(initialTime);
        pImpl_->setFinalTime(finalTime);
        pImpl_->setId(id);
    }

    // ModelHandle(ModelBody* pImpl_1) {
    //     pImpl_ = pImpl_1;
    // }

    virtual ~ModelHandle(){}

    // void add(Model* m) { pImpl_->add(m);}


    // void add(Stock* sto) { pImpl_->add(sto);}


    // void add(Flow* flu) { pImpl_->add(flu);}


    // void add(Flow* flu, Stock* source, Stock* destiny) { pImpl_->add(flu, source, destiny);}


    // static Model* createModel(double initialTime, double finalTime, int id){
    //     Model* m = ModelBody::createModel(initialTime, finalTime, id);
    //     return m;
    // }

    Stock* createStock(double value, string id) {return pImpl_->createStock(value, id);}

    Flow* createFlow(Stock* source, Stock* destiny,  int id, double (*f) (Stock* sto), bool varBool) {return pImpl_->createFlow(source, destiny, id, f, varBool);}

    double getCurrentTime() const {return pImpl_->getCurrentTime();}


    void setCurrentTime(double currentTime) {pImpl_->setCurrentTime(currentTime);}


    double getInitialTime() const {return pImpl_->getInitialTime();}


    void setInitialTime(double initialTime) {pImpl_->setInitialTime(initialTime);}


    double getFinalTime() const {return pImpl_->getFinalTime();}


    void setFinalTime(double finalTime) {pImpl_->setFinalTime(finalTime);}


    int getId() const {return pImpl_->getId();}


    void setId(int id) {pImpl_->setId(id);}


    vector <Stock*> getStocks() const {return pImpl_->getStocks();}


    vector <Flow*> getFlows() const {return pImpl_->getFlows();}


    bool remove(string idStock) {return pImpl_->remove(idStock);}


    bool remove(int idFlow) {return pImpl_->remove(idFlow);}


    bool run() {return pImpl_->run();}


    void print_results() {pImpl_->print_results();}
};


#endif