/*Gabriel Catizani Faria Oliveira (20.1.4004)
Pablo Martins Coelho (20.1.4113)
Rafael Augusto Freitas Oliveira (20.1.4038)
Robson Novato Lobão (20.1.4018)*/
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "ordenanormal.h"
#include "imprime.h"
#include "quick_sort.h"
#include "selecaopsubstituicao.h"

int main (int argc, const char *argv[]) {
    int metodo = atoi(argv[1]);
    long int quantidade = atoi (argv[2]);
    int situ = atoi (argv[3]);
    int argOpc = 0;

    double tProce = 0.0; 
    double tTotal = 0.0;

    int contLeitura = 0;
    int contEscrita = 0;
    int contComp = 0;

    clock_t Processamento;

    int ordenado;

    FILE *arqReg = NULL;
    char nome[15];

    //Tratando as msg de erro de argumentos
    trataMsgsDeERRO(metodo, quantidade, situ, &argOpc, argc, argv[4]);

    //Converto o arquivo para crescente ou decrescente usando um dos metodo de ordenação criados nesse tp  
    comoConverter(situ, quantidade);

    //vê qual arquivo iremos pegar
    switch (situ) {
        case 1:

            strcpy(nome,"binarioCRE.bin");
            if((arqReg = fopen("binarioCRE.bin", "r+b")) == NULL){
                printf ("ERRO na abertura do arquivo \n");
                return 0;
            }
            break;

        case 2: 
            
            strcpy(nome,"binarioDEC.bin");
            if((arqReg = fopen("binarioDEC.bin", "r+b")) == NULL){
                printf ("ERRO na abertura do arquivo \n");
                return 0;

            }
            break;

        case 3: 
           
            strcpy(nome,"binarioALE.bin");
            if((arqReg = fopen("binarioALE.bin", "r+b")) == NULL){
                printf ("ERRO na abertura do arquivo \n");
                return 0;
            }
            break;
    }  

    ordenado = 0;
    //Imprimindo o registro antes da ordenação
    //if(argOpc == 1 && metodo != 2){
    //    imprimeTUDO(arqReg, ordenado, quantidade);
    //}

    //Identifica qual método de ordenação sera utilizado

    switch (metodo){
        case 1: //METODO 1: Ordenação interna 
            Processamento = clock();
            intercala2fcaminhos(arqReg, quantidade, &contLeitura, &contEscrita, &contComp);
            Processamento = clock() - Processamento;
            break;

        case 2: //METODO 2: Seleção por substituição  
            Processamento = clock();
            selecaoPorSubstituicao(arqReg, quantidade, &contLeitura, &contEscrita, &contComp);
            Processamento = clock() - Processamento;
            break;

        case 3: //MÉTODO 3: Quicksort externo
            Processamento = clock();
            quick_sort(&arqReg, quantidade, nome, &contLeitura, &contEscrita, &contComp);
            Processamento = clock() - Processamento;
            break; 
    }
    
    ordenado = 1;


    //Imprimindo o registro depois da ordenação
    if(argOpc == 1){
        imprimeTUDO(arqReg, ordenado, quantidade);
    }

    tProce = (((double) Processamento)/1000.0);

    tTotal = (tProce)/1000.0;

    imprimirExperimento (contComp, contLeitura, contEscrita, tTotal);

    converte_para_txt(arqReg, quantidade, "ordenado.txt");

    fclose(arqReg);

    //Removendo arquivos binarios após utiliza-los na ordenação
    removeArquivos();
    
    return 0;
}



