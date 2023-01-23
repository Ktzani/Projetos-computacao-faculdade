//Caso 3: Existe apenas um Flow e tem apenas uma entrada. A saida não existe. 
Stock destiny(value);
Flow flu(null, destiny);

//OU

Stock destiny;
destiny.SetInitialValue(value);

Flow flu;
flu.connection(null, destiny);