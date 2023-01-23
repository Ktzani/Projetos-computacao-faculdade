//Caso 4: Existe um sistema com fluxo nele mesmo 
Stock destiny(value);
Stock source;
source = destiny; //Nesse caso temos que fazer uma sobrecarga do operador =, onde o value de um será igual o value da outra

Flow flu(source, destiny);

//OU
Stock destiny;
Stock source;

destiny.SetInitialValue(value);
source = destiny;

Flow flu;
flu.connection(destiny, destiny);