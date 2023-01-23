//Caso 5: Um fluxo conectado à apenas um estoque na origem
Stock source(value);
Flow flu(source, stock *des = null);

//OU

Stock source();
source.SetInitialValue(value);

Flow flu();
flu.connection(source, stock *des = null);
