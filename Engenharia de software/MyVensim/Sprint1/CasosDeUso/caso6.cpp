//Caso 6: Um fluxo conectando dois estoques
Stock source(value1);
Stock destiny(value2);

Flow flu(source, destiny);

//OU

Stock source();
Stock destiny();

source.SetInitialValue(value1);
destiny.SetInitialValue(value2);

Flow flu();
Flu.connection(source,destiny);