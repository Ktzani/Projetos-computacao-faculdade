#include "model_impl.h"
#include "stock_impl.h"
#include "flow_impl.h"

vector <Model*> ModelBody::models;

ModelBody:: ~ModelBody(){}

ModelBody:: ModelBody(){}

Model* Model::createModel(double initialTime, double finalTime, int id) {
    return ModelBody::createModel(initialTime, finalTime, id);
    // Model *m = (Model*) ModelHandle::createModel(initialTime, finalTime, id);
    // ModelBody::models.push_back(m);
}

Model* ModelBody::createModel(double initialTime, double finalTime, int id) {
    Model* m = new ModelHandle(initialTime, finalTime, id);
    ModelBody::models.push_back(m);
    return m;
}

Flow* ModelBody::createFlow(Stock* source, Stock* destiny,  int id, double (*f) (Stock* sto), bool varBool){
    Flow* flow = new FlowHandle(source, destiny, id, f, varBool);
    add(flow);
    flow->connection(source, destiny);

    return flow;
}


Stock* ModelBody::createStock(double value, string id) {
    Stock* sto = new StockHandle(value, id);
    add(sto);

    return sto;
}

double ModelBody :: getCurrentTime() const{
    return currentTime;
}
    
void ModelBody :: setCurrentTime(double currentTime){
    this->currentTime = currentTime;
}

double ModelBody :: getInitialTime() const{
    return initialTime;
}

void ModelBody :: setInitialTime(double initialTime){
    this->initialTime = initialTime;
}

double ModelBody :: getFinalTime() const{
    return finalTime;
}

void ModelBody :: setFinalTime(double finalTime){
    this->finalTime = finalTime;
}

int ModelBody :: getId() const {
    return ID;
}

void ModelBody :: setId(int id) {
    this->ID = id;
}

vector <Stock*> ModelBody :: getStocks() const{
    return stocks;
}

vector <Flow*> ModelBody :: getFlows() const{
    return flows;
}

void ModelBody :: add(Model* m){
    ModelBody :: models.push_back(m);
}

void ModelBody :: add(Stock* sto){
    // if (!(*find(stocks.begin(), stocks.end(), sto) == sto)) {
        this->stocks.push_back(sto);
    // }
}

void ModelBody :: add(Flow* flu){
    // if (!(*find(flows.begin(), flows.end(), flu) == flu)) {
        this->flows.push_back(flu);
    // }
}

void ModelBody :: add(Flow* flu, Stock* source, Stock* destiny){
    this->flows.push_back(flu); 
    this->stocks.push_back(source); 
    this->stocks.push_back(destiny);
}

bool ModelBody :: remove(string idStock){
    for (Stock* aux : this->stocks){
        if(aux->getId() == idStock){
            this->stocks.erase(std::remove(this->stocks.begin(), this->stocks.end(), aux), this->stocks.end());
            return true;
        }
    }

    return false;
}

bool ModelBody :: remove(int idFlow){
    for (Flow* aux : this->flows){
        if(aux->getId() == idFlow){
            this->flows.erase(std::remove(this->flows.begin(), this->flows.end(), aux), this->flows.end());
            return true;
        }
    }
    return false;
}

bool ModelBody :: run(){
    int i;

    // cout << "ALOUU GUILHERME!" << endl;

    double valorRetirado;
    double valorAdicionado;

    // cout << "INITIAL TIME: "<< getInitialTime() << endl;
    // cout << "FINAL TIME: "<< getFinalTime() << endl;
    for(i = this->initialTime; i < this->finalTime; i++){
        this->currentTime = i;

        // cout << flows.size() << endl;
        for(Flow* elem : flows){
            elem->execute();
        }

        for(Flow* elem : flows){
            valorRetirado = elem->getSource()->getInitialValue() - elem->getLastValue();
            elem->getSource()->setInitialValue(valorRetirado);

            valorAdicionado = elem->getDestiny()->getInitialValue() + elem->getLastValue();
            elem->getDestiny()->setInitialValue(valorAdicionado);

            // cout << elem->getLastValue() << endl;
        }
    }
 
    return true;
}

void ModelBody :: print_results(){
    for (Stock* elem : stocks){
        cout << elem->getId() << ": " << elem->getInitialValue() << "\n" << endl;
    }
}

//---------------------------------------------------

// ModelBody:: ~ModelBody(){
    // ModelBody* m;

    // for(auto elem : models){
    //     if(this == elem){
    //         m = (ModelBody*) elem;
    //         vector<Stock*>::iterator StockIt;
    //         for (StockIt = m->stocks.begin(); StockIt != m->stocks.end(); ++StockIt) {
    //             delete (*StockIt);
    //         }
    //         vector<Flow*>::iterator flowIt;
    //         for (flowIt = m->flows.begin(); flowIt != m->flows.end(); ++flowIt) {
    //             delete (*flowIt);
    //         }

    //         ModelBody::models.erase(std::remove(ModelBody::models.begin(), ModelBody::models.end(), elem), ModelBody::models.end());

    //     }
    // }   
// }

// Model::Model(){}
// ModelBody::ModelBody(double initialTime, double finalTime, int id) : initialTime(initialTime), finalTime(finalTime), ID(id) {} 
// ModelBody::ModelBody(const Model& copia) : initialTime(copia.getInitialTime()), finalTime(copia.getFinalTime()), ID(copia.getId()) {}

// Model& ModelBody::operator=(const Model& m){
//     if(this == &m)
//         return *this;
        
//     this->currentTime = m.getCurrentTime();
//     this->initialTime = m.getInitialTime();
//     this->finalTime = m.getFinalTime();
//     this->ID = m.getId();

//     return *this;
// }
