double value;

//Caso 1: Apenas um estoque
Stock est(value);
Model m(&est);

//OU

Model m();
Stock est();
est.SetInitialValue(value);
m.add(&source);
