#include <assert.h>
#include "unit_tests.h"
#include <math.h>
#include "../../src/minhasFuncoes.h"
#include "../../src/flow_impl.h"
#include "../../src/model_impl.h"
#include "../../src/stock_impl.h"

  void unit_exponencial( void ){
        /*insira o codigo de depuração, que invoca a função global ...minhaFuncao1(...) aqui"*/
        printf("Início teste exponential\n");
        Model *m = Model::createModel(0, 100, 0);
    
        Stock *source = m->createStock(100, "Pop1");
        Stock *destiny = m->createStock(0, "Pop2");
    
        Flow *flu = m->createFlow(source, destiny, 0, exponencial, true);

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

        // Model::deleteModel(0);


        printf("Fim teste exponential\n\n");

  }

  void unit_logistical( void ){
        printf("Início teste logistical\n");
        Model *m = Model::createModel(0, 100, 0);
        
        Stock *source = m->createStock(100, "P1");
        Stock *destiny = m->createStock(10, "P2");
        
        Flow *flu = m->createFlow(source, destiny, 0, logistical, false);
        
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

        // Model::deleteModel(0);
    
        printf("Fim teste logistical\n\n");

  }

  void run_unit_tests_globals( void ){
        unit_logistical();
        unit_exponencial();
  }