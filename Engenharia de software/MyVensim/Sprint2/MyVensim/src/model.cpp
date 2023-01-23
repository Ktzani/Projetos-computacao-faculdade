#include "model.h"

Model::Model(){}
Model::Model(double initialTime, double finalTime, int id) : initialTime(initialTime), finalTime(finalTime), ID(id) {} 
Model::Model(const Model& copia) : initialTime(copia.initialTime), finalTime(copia.finalTime), ID(copia.ID) {}
    
Model:: ~Model(){}

Model& Model::operator=(const Model& sto){
    this->currentTime = sto.currentTime;
    this->initialTime = sto.initialTime;
    this->finalTime = sto.finalTime;
    this->ID = sto.ID;

    return *this;
}

    double Model :: getCurrentTime() const{
        return currentTime;
    }
    void Model :: setCurrentTime(double currentTime){
        this->currentTime = currentTime;
    }

    double Model :: getInitialTime() const{
        return initialTime;
    }
    void Model :: setInitialTime(double initialTime){
        this->initialTime = initialTime;
    }

    double Model :: getFinalTime() const{
        return finalTime;
    }
    void Model :: setFinalTime(double finalTime){
        this->finalTime = finalTime;
    }

    int Model :: getId() const {
        return ID;
    }

    void Model :: setId(int id) {
        this->ID = id;
    }

    vector <Stock*> Model :: getStocks() const{
        return stocks;
    }

    vector <Flow*> Model :: getFlows() const{
        return flows;
    }

    void Model :: add(Stock* sto){
        // if (!(*find(stocks.begin(), stocks.end(), sto) == sto)) {
            this->stocks.push_back(sto);
        // }
    }

    void Model :: add(Flow* flu){
        // if (!(*find(flows.begin(), flows.end(), flu) == flu)) {
            this->flows.push_back(flu);
        // }
    }

    void Model :: add(Flow* flu, Stock* source, Stock* destiny){
        this->flows.push_back(flu); 
        this->stocks.push_back(source); 
        this->stocks.push_back(destiny);
    }

    bool Model :: remove(string idStock){
        for (Stock* aux : this->stocks){
            if(aux->getId() == idStock){
                this->stocks.erase(std::remove(this->stocks.begin(), this->stocks.end(), aux), this->stocks.end());
                return true;
            }
        }

        return false;
    }

    bool Model :: remove(int idFlow){
        for (Flow* aux : this->flows){
            if(aux->getId() == idFlow){
                this->flows.erase(std::remove(this->flows.begin(), this->flows.end(), aux), this->flows.end());
                return true;
            }
        }

        return false;
    }

    bool Model :: run(){
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

    void Model :: print_results(){
        for (Stock* elem : stocks){
            cout << elem->getId() << ": " << elem->getInitialValue() << "\n" << endl;
        }
    }