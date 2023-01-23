#include "funcional_tests.h"
#include <vector>

    bool exponentialFuncionalTest(){
        printf("Início teste exponential\n");
        Model *m = new MyModel(0, 100, 0);
    
        Stock *source = new MyStock(100, "Pop1");
        Stock *destiny = new MyStock(0, "Pop2");
    
        Flow *flu = new MyFlow(source, destiny, 0, exponencial, true);

        m->add(flu, source, destiny);

        m->run();

        double sourceFinalResult;

        double destinyFinalResult;

        for(Stock* elem : m->getStocks()){
            if(elem->getId() == "Pop1"){
                sourceFinalResult = elem->getInitialValue();
            }

            if (elem->getId() == "Pop2"){
                destinyFinalResult = elem->getInitialValue();
            }
        }

        assert( fabs(sourceFinalResult - 36.6032) < 0.0001);
        assert( fabs(destinyFinalResult - 63.3968) < 0.0001);

        delete(source);
        delete(destiny);
        delete(flu);
        
        delete(m);

        printf("Fim teste exponential\n\n");

        return true;
    }

    bool logisticalFuncionalTest(){
        printf("Inicio teste logistical\n");
        Model *m = new MyModel(0, 100, 0);
        
        Stock *source = new MyStock(100, "P1");
        Stock *destiny = new MyStock(10, "P2");
        
        Flow *flu = new MyFlow(source, destiny, 0, logistical, false);
    
        m->add(flu, source, destiny);
    
        m->run();

        double sourceFinalResult;

        double destinyFinalResult;

        for(Stock* elem : m->getStocks()){
            if(elem->getId() == "P1"){
                sourceFinalResult = elem->getInitialValue();
            }

            if (elem->getId() == "P2"){
                destinyFinalResult = elem->getInitialValue();
            }
        }

        assert( fabs(sourceFinalResult - 88.2167) < 0.0001);
        assert( fabs(destinyFinalResult - 21.7833) < 0.0001);

        delete(source);
        delete(destiny);
        delete(flu);
        
        delete(m);

    
        printf("Fim teste logistical\n\n");

        return true;
    }

    bool complexFuncionalTest(){
        printf("Inicio teste complexo\n");
    
        Model *m = new MyModel(0, 100, 1);

        Stock *Q1= new MyStock(100, "Q1");
        Stock *Q2= new MyStock(0, "Q2");
        Stock *Q3= new MyStock(100, "Q3");
        Stock *Q4= new MyStock(0, "Q4");
        Stock *Q5= new MyStock(0, "Q5");

        Flow *fluF = new MyFlow(Q1, Q2, 1, exponencial, true);
        Flow *fluG = new MyFlow(Q1, Q3, 2, exponencial, true);
        Flow *fluR = new MyFlow(Q2, Q5, 3, exponencial, true);
        Flow *fluT = new MyFlow(Q2, Q3, 4, exponencial, true);
        Flow *fluU = new MyFlow(Q3, Q4, 5, exponencial, true);
        Flow *fluV = new MyFlow(Q4, Q1, 6, exponencial, true);

        m->add(fluF);
        m->add(fluG);
        m->add(fluR);
        m->add(fluT);
        m->add(fluU);
        m->add(fluV);
        m->add(Q1);
        m->add(Q2);
        m->add(Q3);
        m->add(Q4);
        m->add(Q5);

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

        printf("Fim teste complexo\n\n");

        delete(m);
        
        delete(Q1);
        delete(Q2);
        delete(Q3);
        delete(Q4);
        delete(Q5);

        delete(fluF);
        delete(fluG);
        delete(fluR);
        delete(fluT);
        delete(fluU);
        delete(fluV);
        
        return true;
    }