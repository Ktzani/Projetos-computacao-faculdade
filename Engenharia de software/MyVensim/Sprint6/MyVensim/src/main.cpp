#include <iostream>
#include <string>
#include "model.h"
#include "stock_impl.h"
#include "flow.h"
#include "minhasFuncoes.h"
#include "assert.h"
#include "math.h"

#define DEBUGING
#ifdef DEBUGING
    int numHandleCreated = 0;
	int numHandleDeleted = 0;
	int numBodyCreated = 0;
	int numBodyDeleted = 0;
#endif

using namespace std;

int main (){

    printf("Inicio aplicação\n\n");
    
    Model *m = Model::createModel(0, 100, 1);

    m->setFinalTime(100);

    Stock* s1 = m->createStock(10.0, "populacao");
    Stock* s2 = m->createStock(7.90, "Teste")   ;
    cout << "s1: " << s1->getId() << ", s2: " <<  s2->getId() << endl;
    //s1 = s2;
    *s1 = *s2;
    cout << "s1: " << s1->getId() << ", s2: " <<  s2->getId() << endl;    
    cout << "s1: " << s1 << ", s2: " <<  s2 << endl;

    // Fa�a o teste COM e SEM as chaves abaixo
{
    // USANDO OBJETOS HANDLES (DELEGA��O)
    StockHandle s3(7, "tiago"), s4(8, "antonio");
    cout << "s3: " << s3.getId() << ", s4: " <<  s4.getId() << endl;
    s3 = s4;  // comente esta linha e veja que o resultado muda
    cout << "s3: " << s3.getId() << ", s4: " <<  s4.getId() << endl;        
	s3 = s3;
	cout << "s3: " << s3.getId() << ", s4: " <<  s4.getId() << endl;        
}   
    // Monta Modelo
    // Flow* flu1 = m->createFlow(s1, s2, 0, exponencial, true);
    
    // executa o modelo
    // m->run();
    
    // imprime relatorio
    cout << s1->getInitialValue() << endl;
    cout << "Created handles: "  << numHandleCreated << endl;
    cout << "Deleted handles: "  << numHandleDeleted << endl;    
    cout << "Created bodies: "  << numBodyCreated << endl;
    cout << "Deleted bodies: "  << numBodyDeleted << endl;

    printf("\nFim aplicação!!\n\n");

    return EXIT_SUCCESS;
}