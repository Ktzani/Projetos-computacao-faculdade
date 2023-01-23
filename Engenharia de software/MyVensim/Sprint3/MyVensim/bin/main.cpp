#include <iostream>
#include <string>
#include "model.h"
#include "stock.h"
#include "flow.h"

using namespace std;

double exponencial(Stock* sto){
    return 0.01 * sto->getInitialValue();
}

double logistical(Stock* sto){
    return 0.01 * sto->getInitialValue() * (1 - sto->getInitialValue() / 70) ;
}

int main (){

    printf("Inicio aplicação\n\n");
    
    
        Model m (0, 100, 1);

        Stock Q1(100, "Q1");
        Stock Q2(0, "Q2");
        Stock Q3(100, "Q3");
        Stock Q4(0, "Q4");
        Stock Q5(0, "Q5");

        Flow fluF (&Q1, &Q2, 1, exponencial, true);
        Flow fluG (&Q1, &Q3, 2, exponencial, true);
        Flow fluR (&Q2, &Q5, 3, exponencial, true);
        Flow fluT (&Q2, &Q3, 4, exponencial, true);
        Flow fluU (&Q3, &Q4, 5, exponencial, true);
        Flow fluV (&Q4, &Q1, 6, exponencial, true);

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
        m.print_results();
    
    printf("Fim aplicação!!");
}