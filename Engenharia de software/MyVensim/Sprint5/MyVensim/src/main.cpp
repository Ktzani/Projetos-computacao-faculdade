#include <iostream>
#include <string>
#include "model.h"
#include "stock.h"
#include "flow_impl.h"
#include "minhasFuncoes.h"
#include "assert.h"
#include "math.h"

using namespace std;

int main (){

    printf("Inicio aplicação\n\n");
    
    Model *m = Model::createModel(0, 100, 1);

    Stock *Q1= m->createStock(100, "Q1");
    
    Stock *Q2= m->createStock(0, "Q2");
    
    Stock *Q3= m->createStock(100, "Q3");
    
    Stock *Q4= m->createStock(0, "Q4");
    
    Stock *Q5= m->createStock(0, "Q5");

    printf("ALOUU\n");
    
    m->createFlow(Q1, Q2, 1, exponencial, true);
    
    m->createFlow(Q1, Q3, 2, exponencial, true);
    
    m->createFlow(Q2, Q5, 3, exponencial, true);
    
    m->createFlow(Q2, Q3, 4, exponencial, true);
    
    m->createFlow(Q3, Q4, 5, exponencial, true);
    
    m->createFlow(Q4, Q1, 6, exponencial, true);

    m->run();

    double q1FinalResult;

    double q2FinalResult;

    double q3FinalResult;
    
    double q4FinalResult;

    double q5FinalResult;

        for(Stock* elem : m->getStocks()){
            if(elem->getId() == "Q1"){
                q1FinalResult = elem->getInitialValue();
            }

            if (elem->getId() == "Q2"){
                q2FinalResult = elem->getInitialValue();
            }

            if(elem->getId() == "Q3"){
                q3FinalResult = elem->getInitialValue();
            }

            if (elem->getId() == "Q4"){
                q4FinalResult = elem->getInitialValue();
            }

            if (elem->getId() == "Q5"){
                q5FinalResult = elem->getInitialValue();
            }
        }
        
        assert( fabs(q1FinalResult - 31.8513) < 0.0001);
        assert( fabs(q2FinalResult - 18.4003) < 0.0001);
        assert( fabs(q3FinalResult - 77.1143) < 0.0001);
        assert( fabs(q4FinalResult - 56.1728) < 0.0001);
        assert( fabs(q5FinalResult - 16.4612) < 0.0001);
        
        // Model::deleteModel(1);

    printf("Fim aplicação!!");
}