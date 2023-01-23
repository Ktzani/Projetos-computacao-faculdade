//Caso 7: Um estoque que serve de destino a outros dois ou mais sistemas de destino

Stock source(value1);
Stock destinyA(value2);
Stock destinyB(value3);
Stock destinyC(value4);

Flow flu1(source, destinyA);
Flow flu2(source, destinyB);
Flow flu3(source, destinyC);

//OU

Stock source();
Stock destinyA(), destinyB(), destinyC();

source.SetInitialValue(value1);
destinyA.SetInitialValue(value2);
destinyB.SetInitialValue(value3);   
destinyC.SetInitialValue(value4);

Flow flu1(), flu2(), flu3();

flu1.connection(source, destinyA), flu2.connection(source, destinyB), flu3.connection(source, destinyC);