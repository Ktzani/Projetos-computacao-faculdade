double value;

//OU

//podemos ter um vetor de valores onde cada valor corresponde a um Stock
double value[x]; 

double variavelDeEquacao;

//Caso 1: Apenas um estoque
Model m(inicialTime, finalTime, id);
Stock est(value);
m.add(&est);

//OU

Model m(inicialTime, finalTime, id);
Stock est();
est.SetInitialValue(value);
m.add(&est);


//Caso 2: Apenas um Flow
//OBS: os nulls seriam de onde o Flow sai e aonde ele esta entrando, respectivamente
//Exemplo: Flow flu(saida, entrada);
Model m(inicialTime, finalTime, id);
Flow flu(stock *ori = null, stock *des = null);
m.add(&flu, null, null);

//OU

Model m(inicialTime, finalTime, id);
Flow flu();
flu.connection(stock *ori = null, stock *des = null);
m.add(&flu, null, null);

//Caso 3: Existe apenas um Flow e tem apenas uma entrada. A saida não existe. 
Model m(inicialTime, finalTime, id);
Stock destiny(value);
Flow flu(stock *ori = null, &destiny);
m.add(&flu, null, &destiny);


//OU

Model m(inicialTime, finalTime, id);
Stock destiny();
destiny.SetInitialValue(value);

Flow flu();
flu.connection(stock *ori = null, &destiny);
m.add(&flu, null, &destiny);

//Caso 4: Um fluxo conectado à apenas um estoque na origem
Model m(inicialTime, finalTime, id);
Stock source(value);
Flow flu(&source, stock *des = null);
m.add(&flu, &source, null);

//OU

Model m(inicialTime, finalTime, id);
Stock source();
source.SetInitialValue(value);

Flow flu();
flu.connection(&source, stock *des = null);
m.add(&flu, &source, null);

//Caso 5: Um fluxo conectando dois estoques
Model m(inicialTime, finalTime, id);
Stock source(value1);
Stock destiny(value2);

Flow flu(source, destiny);

m.add(&flu, &source, &destiny);
//OU

Model m(inicialTime, finalTime, id);
Stock source();
Stock destiny();

source.SetInitialValue(value1);
destiny.SetInitialValue(value2);

Flow flu();
Flu.connection(&source, &destiny);

m.add(&flu, &source, &destiny);

//Caso 6: Um estoque que serve de destino a outros dois ou mais sistemas de destino

Model m(inicialTime, finalTime, id);
Stock source(value1);
Stock destinyA(value2);
Stock destinyB(value3);
Stock destinyC(value4);

Flow flu1(&source, &destinyA);
Flow flu2(&source, &destinyB);
Flow flu3(&source, &destinyC);

m.add(&flu1, &source, &destinyA);
m.add(&flu2, &source, &destinyB);
m.add(&flu3, &source, &destinyC);

//OU

Model m(inicialTime, finalTime, id)
Stock source();
Stock destinyA(), destinyB(), destinyC();

source.SetInitialValue(value1);
destinyA.SetInitialValue(value2);
destinyB.SetInitialValue(value3);   
destinyC.SetInitialValue(value4);

Flow flu1(), flu2(), flu3();
flu1.connection(&source, &destinyA), flu2.connection(&source, &destinyB), flu3.connection(&source, &destinyC);

m.add(&flu1, &source, &destinyA);
m.add(&flu2, &source, &destinyB);
m.add(&flu3, &source, &destinyC);


//Caso 7: um estoque que serve de destino para dois outros sistemas ou mais 
Model m(inicialTime, finalTime, id);
Stock destiny(value1);
Stock sourceA(value2);
Stock sourceB(value3);
Stock sourceC(value4);

Flow flu1(&sourceA, &destiny);
Flow flu2(&sourceB, &destiny);
Flow flu3(&sourceC, &destiny);

m.add(&flu1, &sourceA, &destiny);
m.add(&flu2, &sourceB, &destiny);
m.add(&flu3, &sourceC, &destiny);

//OU
Model m(inicialTime, finalTime, id);
Stock destiny();
Stock sourceA(), sourceB(), sourceC();

destiny.SetInitialValue(value1);
sourceA.SetInitialValue(value2);
sourceB.SetInitialValue(value3);   
sourceC.SetInitialValue(value4);

Flow flu1(), flu2(), flu3();

flu1.connection(&sourceA, &destiny), flu2.connection(&sourceB, &destiny), flu3.connection(&sourceC, &destiny);

m.add(&flu1, &sourceA, &destiny);
m.add(&flu2, &sourceB, &destiny);
m.add(&flu3, &sourceC, &destiny);

//Caso 8: Um estoque "ponte" que serve de origem para um determinado fluxo e destino para outro(s);
Model m(inicialTime, finalTime, id);
Stock DesOri(value);

Flow flu1(stock *ori = null, &DesOri);
Flow flu2(&DesOri, stock *des = null);

m.add(&flu1, null, &DesOri)
m.add(&flu2, &DesOri, null);

//OU
Model m(inicialTime, finalTime, id);
Stock DesOri();
DesOri.SetInitialValue(value);

Flow flu1();
Flow flu2();

flu1.connection(stock *ori = null,  &DesOri);
flu2.connection(&DesOri, stock *des = null);

m.add(&flu1, null, &DesOri)
m.add(&flu2, &DesOri, null);

//IMPORTANTE-LEMBRAR: As equações serão executadas dentro do m.run()







