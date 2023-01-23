#include <iostream>
#include <string>
#include "model_impl.h"
#include "stock_impl.h"
#include "flow_impl.h"
#include "minhasFuncoes.h"

using namespace std;

int main (){

    printf("Inicio aplicação\n\n");
    
    
        MyModel m (0, 100, 1);

        MyStock Q1(100, "Q1");
        MyStock Q2(0, "Q2");
        MyStock Q3(100, "Q3");
        MyStock Q4(0, "Q4");
        MyStock Q5(0, "Q5");

        MyFlow fluF (&Q1, &Q2, 1, exponencial, true);
        MyFlow fluG (&Q1, &Q3, 2, exponencial, true);
        MyFlow fluR (&Q2, &Q5, 3, exponencial, true);
        MyFlow fluT (&Q2, &Q3, 4, exponencial, true);
        MyFlow fluU (&Q3, &Q4, 5, exponencial, true);
        MyFlow fluV (&Q4, &Q1, 6, exponencial, true);

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