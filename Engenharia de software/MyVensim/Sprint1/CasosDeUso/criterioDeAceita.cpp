double value1, value2, value3, value4, value5;
double inicialTime, finalTime;

Model m (inicialTime, finalTime, 1);

Stock Q1(value1, "Q1");
Stock Q2(value2, "Q2");
Stock Q3(value3, "Q3");
Stock Q4(value4, "Q4");
Stock Q5(value5, "Q5");

Flow fluF (&Q1, &Q2, 1);
Flow fluG (&Q1, &Q3, 2);
Flow fluR (&Q2, &Q5, 3);
Flow fluT (&Q2, &Q3, 4);
Flow fluU (&Q3, &Q4, 5);
Flow fluV (&Q4, &Q1, 6);

m.add (&fluF, &Q1, &Q2);
m.add (&fluG, &Q1, &Q3);
m.add (&fluR, &Q2, &Q5);
m.add (&fluT, &Q2, &Q3);
m.add (&fluU, &Q3, &Q4);
m.add (&fluV, &Q4, &Q1);

m.run();

m.print_results();


double value1, value2;
double inicialTime, finalTime;

Model m (inicialTime, finalTime, 2);

Stock pop1(value1, "pop1");
Stock pop2(value2, "pop2");

Flow expo (&pop1, &pop2);

m.add(&expo, &pop1, &pop2);

m.run()

m.print_results();

