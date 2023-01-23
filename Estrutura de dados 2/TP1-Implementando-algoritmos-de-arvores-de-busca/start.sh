gcc arvoreb.c -c -Wall
gcc arvorebestrela.c -c -Wall
gcc contimpri.c -c -Wall
gcc arvore_binaria.c -c -Wall
gcc principal.c -c -Wall
gcc principal.o arvoreb.o contimpri.o arvore_binaria.o arvorebestrela.o -o play

./play 4 10000 1 67
