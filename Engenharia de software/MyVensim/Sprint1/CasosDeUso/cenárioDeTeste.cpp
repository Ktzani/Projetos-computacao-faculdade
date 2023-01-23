double value1, value2, value3;

double inicialTime, finalTime;

Model m(inicialTime, finalTime, 0)
Stock abastecimento(0, "Estacao de tratamento");
Stock casa(0, "Residencia");
Stock esgoto(0, "Esgoto");

abastecimento.setInitialValue(value1);
casa.setInitialValue(value2);
esgoto.setInitialValue(value3);


Flow aguaLimpa(null, null, 1);
Flow aguaSuja(null, null, 2);

aguaLimpa.connection(&abastecimento, &casa);
aguaSuja.connection(&casa, &esgoto);

m.add(&aguaLimpa, &abastecimento, &casa);
m.add(&aguaSuja, &casa, &esgoto);

m.run()
m.print_results();

