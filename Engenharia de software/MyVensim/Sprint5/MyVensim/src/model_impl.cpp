#include "model_impl.h"
#include "stock_impl.h"
#include "flow_impl.h"

vector <Model*> MyModel::models;

// Model::Model(){}
MyModel::MyModel(double initialTime, double finalTime, int id) : initialTime(initialTime), finalTime(finalTime), ID(id) {} 
MyModel::MyModel(const Model& copia) : initialTime(copia.getInitialTime()), finalTime(copia.getFinalTime()), ID(copia.getId()) {}
    
MyModel:: ~MyModel(){
    MyModel* m;

    for(auto elem : models){
        if(this == elem){
            m = (MyModel*) elem;
            vector<Stock*>::iterator StockIt;
            for (StockIt = m->stocks.begin(); StockIt != m->stocks.end(); ++StockIt) {
                delete (*StockIt);
            }
            vector<Flow*>::iterator flowIt;
            for (flowIt = m->flows.begin(); flowIt != m->flows.end(); ++flowIt) {
                delete (*flowIt);
            }

            MyModel::models.erase(std::remove(MyModel::models.begin(), MyModel::models.end(), elem), MyModel::models.end());

        }
    }   
}

Model& MyModel::operator=(const Model& m){
    if(this == &m)
        return *this;
        
    this->currentTime = m.getCurrentTime();
    this->initialTime = m.getInitialTime();
    this->finalTime = m.getFinalTime();
    this->ID = m.getId();

    return *this;
}

Model* Model::createModel(double initialTime, double finalTime, int id) {
    return MyModel::createModel(initialTime, finalTime, id);
}

// void Model::deleteModel(int id) {
//   MyModel::deleteModel(id);
// }

Model* MyModel::createModel(double initialTime, double finalTime, int id) {
    Model* m = new MyModel(initialTime, finalTime, id);
    MyModel::models.push_back(m);
    return m;
}

// void MyModel::deleteModel(int id) {
//     MyModel* m;

//     for(auto elem : models){

//         m = (MyModel*) elem;
//         vector<Stock*>::iterator StockIt;
//         for (StockIt = m->stocks.begin(); StockIt != m->stocks.end(); ++StockIt) {
//             delete (*StockIt);
//         }
//         vector<Flow*>::iterator flowIt;
//         for (flowIt = m->flows.begin(); flowIt != m->flows.end(); ++flowIt) {
//             delete (*flowIt);
//         }
        
//         MyModel::models.erase(std::remove(MyModel::models.begin(), MyModel::models.end(), elem), MyModel::models.end());

//         delete m;
//     }
// }

Flow* MyModel::createFlow(Stock* source, Stock* destiny,  int id, double (*f) (Stock* sto), bool varBool){
    Flow* flow = new MyFlow(source, destiny, id, f, varBool);
    add(flow);
    flow->connection(source, destiny);

    return flow;
}

Stock* MyModel::createStock(double value, string id) {
    Stock* sto = new MyStock(value, id);
    add(sto);

    return sto;
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

void MyModel :: add(Model* m){
    MyModel :: models.push_back(m);
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
