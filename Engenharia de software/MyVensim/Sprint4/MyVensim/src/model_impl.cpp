#include "model_impl.h"

// Model::Model(){}
MyModel::MyModel(double initialTime, double finalTime, int id) : initialTime(initialTime), finalTime(finalTime), ID(id) {} 
MyModel::MyModel(const Model& copia) : initialTime(copia.getInitialTime()), finalTime(copia.getFinalTime()), ID(copia.getId()) {}
    
MyModel:: ~MyModel(){}

Model& MyModel::operator=(const Model& m){
    if(this == &m)
        return *this;
        
    this->currentTime = m.getCurrentTime();
    this->initialTime = m.getInitialTime();
    this->finalTime = m.getFinalTime();
    this->ID = m.getId();

    return *this;
}

    double MyModel :: getCurrentTime() const{
        return currentTime;
    }
    void MyModel :: setCurrentTime(double currentTime){
        this->currentTime = currentTime;
    }

    double MyModel :: getInitialTime() const{
        return initialTime;
    }
    void MyModel :: setInitialTime(double initialTime){
        this->initialTime = initialTime;
    }

    double MyModel :: getFinalTime() const{
        return finalTime;
    }
    void MyModel :: setFinalTime(double finalTime){
        this->finalTime = finalTime;
    }

    int MyModel :: getId() const {
        return ID;
    }

    void MyModel :: setId(int id) {
        this->ID = id;
    }

    vector <Stock*> MyModel :: getStocks() const{
        return stocks;
    }

    vector <Flow*> MyModel :: getFlows() const{
        return flows;
    }

    void MyModel :: add(Stock* sto){
        // if (!(*find(stocks.begin(), stocks.end(), sto) == sto)) {
            this->stocks.push_back(sto);
        // }
    }

    void MyModel :: add(Flow* flu){
        // if (!(*find(flows.begin(), flows.end(), flu) == flu)) {
            this->flows.push_back(flu);
        // }
    }

    void MyModel :: add(Flow* flu, Stock* source, Stock* destiny){
        this->flows.push_back(flu); 
        this->stocks.push_back(source); 
        this->stocks.push_back(destiny);
    }

    bool MyModel :: remove(string idStock){
        for (Stock* aux : this->stocks){
            if(aux->getId() == idStock){
                this->stocks.erase(std::remove(this->stocks.begin(), this->stocks.end(), aux), this->stocks.end());
                return true;
            }
        }

        return false;
    }

    bool MyModel :: remove(int idFlow){
        for (Flow* aux : this->flows){
            if(aux->getId() == idFlow){
                this->flows.erase(std::remove(this->flows.begin(), this->flows.end(), aux), this->flows.end());
                return true;
            }
        }

        return false;
    }

    bool MyModel :: run(){
        int i;

        double valorRetirado;
        double valorAdicionado;
        for(i = this->initialTime; i < this->finalTime; i++){
            this->currentTime = i;
            for(Flow* elem : flows){
                elem->execute();

            }

            for(Flow* elem : flows){
                valorRetirado = elem->getSource()->getInitialValue() - elem->getLastValue();
                elem->getSource()->setInitialValue(valorRetirado);

                valorAdicionado = elem->getDestiny()->getInitialValue() + elem->getLastValue();
                elem->getDestiny()->setInitialValue(valorAdicionado);
            }
        }

       

        return true;
    }

    void MyModel :: print_results(){
        for (Stock* elem : stocks){
            cout << elem->getId() << ": " << elem->getInitialValue() << "\n" << endl;
        }
    }