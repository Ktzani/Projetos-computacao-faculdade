#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "contimpri.h"

void imprimeRegistro(TipoRegistro registro){

    //printf ("DADOS:\n");
    printf ("Chave:  %ld\n", registro.chave);
    /*printf ("Dado 1: %ld\n", registro.dado1);
    printf ("Dado 2: %s\n", registro.dado2);
    printf ("Dado 3: %s\n", registro.dado3);*/

}

//Imprime todasa as chaves de pesquisa do arquivo
void imprimeChaves(FILE *arq){
    TipoRegistro reg;

    int contChave = 1;

    rewind(arq);

    while(fread(&reg, sizeof (TipoRegistro), 1, arq) == 1){

        printf("%dº Chave: %ld\n", contChave, reg.chave);
        contChave++;
    }

    rewind(arq);
}

//Imprime os valores dos contadores de transferencias e o tempo de execução tanto da pesquisa quanto do pre-processamento
//do metodo utilizado
void imprimirExperimento(int contComp, int contTrans, double tPreProce, double tPesquisa, double tTotal){
    //printf("EXPERIMENTO:\n");
    printf("transferencias: %d\n", contTrans);
    printf("comparacoes: %d\n", contComp);
    //printf("Tempo gasto no pre-processamento (em milissegundos): %lf\n", tPreProce);
    //printf("Tempo gasto na pesquisa (em milissegundos): %lf\n", tPesquisa);
    printf("Tempo total: %.3lf s\n", tTotal);
}

