#include "funcional_tests.h"
#include <vector>

    double exponencial(Stock* sto){
        return (sto->getInitialValue() * 0.01);
    }

    double logistica(Stock* sto){
        return sto->getInitialValue() * 0.01 * ((1 - sto->getInitialValue()) / 70.0);
    }

    bool exponentialFuncionalTest(){
        printf("Início teste exponential\n\n");
        Model m (0, 100, 0);
    
        Stock source(100, "Pop1");
        Stock destiny(0, "Pop2");
    
        Flow flu(&source, &destiny, 0, exponencial, true);

        m.add(&flu, &source, &destiny);

        m.run();

        double sourceFinalResult;

        double destinyFinalResult;

        for(Stock* elem : m.getStocks()){
            if(elem->getId() == "Pop1"){
                sourceFinalResult = elem->getInitialValue();
            }

            if (elem->getId() == "Pop2"){
                destinyFinalResult = elem->getInitialValue();
            }
        }

        assert(sourceFinalResult == 36.6032);
        assert(destinyFinalResult == 63.3968);

        printf("Fim teste exponential\n");

        return true;
    }

    bool logisticalFuncionalTest(){
        printf("Inicio teste logistical\n");
        Model m (0, 100, 0);
        
        Stock source(100, "P1");
        Stock destiny(10, "P2");
        
        Flow flu(&source, &destiny, 0, logistica, false);
    
        m.add(&flu, &source, &destiny);
    
        m.run();

        double sourceFinalResult;

        double destinyFinalResult;

        for(Stock* elem : m.getStocks()){
            if(elem->getId() == "P1"){
                sourceFinalResult = elem->getInitialValue();
            }

            if (elem->getId() == "P2"){
                destinyFinalResult = elem->getInitialValue();
            }
        }

        assert(sourceFinalResult == 88.2167);
        assert(destinyFinalResult == 21.7833);
    
        printf("Fim teste logistical\n");

        return true;
    }

    bool complexFuncionalTest(){
        printf("Inicio teste complexo\n\n");
    
        Model m (0, 100, 1);

        Stock Q1(100, "Q1");
        Stock Q2(0, "Q2");
        Stock Q3(100, "Q3");
        Stock Q4(0, "Q4");
        Stock Q5(0, "Q5");

        Flow fluF (&Q1, &Q2, 1, logistica, true);
        Flow fluG (&Q1, &Q3, 2, logistica, true);
        Flow fluR (&Q2, &Q5, 3, logistica, true);
        Flow fluT (&Q2, &Q3, 4, logistica, true);
        Flow fluU (&Q3, &Q4, 5, logistica, true);
        Flow fluV (&Q4, &Q1, 6, logistica, true);

        m.add(&fluF);
        m.add(&fluG);
        m.add(&fluR);
        m.add(&fluT);
        m.add(&fluU);
        m.add(&fluV);
        m.add(&Q1);
        m.add(&Q2);
        m.add(&Q3);
        m.add(&Q4);
        m.add(&Q5);

        m.run();

        double q1FinalResult;

        double q2FinalResult;

        double q3FinalResult;

        double q4FinalResult;

        double q5FinalResult;


        for(Stock* elem : m.getStocks()){
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

        
        assert(q1FinalResult == 31.8513);
        assert(q2FinalResult == 18.4003);
        assert(q3FinalResult == 77.1143);
        assert(q4FinalResult == 21.7833);
        assert(q5FinalResult == 16.4612);

        printf("Fim teste complexo\n");

        return true;
    }