//Caso 8: um estoque que serve de destino para dois outros sistemas ou mais 

Stock destiny(value1);
Stock sourceA(value2);
Stock sourceB(value3);
Stock sourceC(value4);

Flow flu1(sourceA, destiny);
Flow flu2(sourceB, destiny);
Flow flu3(sourceC, destiny);

//OU

Stock destiny();
Stock sourceA(), sourceB(), sourceC();

destiny.SetInitialValue(value1);
sourceA.SetInitialValue(value2);
sourceB.SetInitialValue(value3);   
sourceC.SetInitialValue(value4);

Flow flu1(), flu2(), flu3();

flu1.connection(sourceA, destiny), flu2.connection(sourceB, destiny), flu3.connection(sourceC, destiny);
