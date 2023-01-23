#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenanormal.h"


/*
typedef struct{
    FILE* arquivo;
    int qtdBlocos;
    int* numReg;
} Fita;

typedef struct Aluno{
    long int numero;
    float nota;
    char estado[2];
    char cidade[50];
    char curso[30];
} Aluno;
*/

void inicializaFitas(Fita* fitaEmQuestao) {
    for(int i = 0; i < FITAS; i++) {
        fitaEmQuestao[i].arquivo = NULL;
        fitaEmQuestao[i].qtdBlocos = 0;
        fitaEmQuestao[i].numReg = NULL;
    }
}

void intercala2fcaminhos(FILE *arquivo, int quantidadeDeAlunos, int *contLeitura, int *contEscrita, int *contComp){

    fflush(arquivo);

    rewind(arquivo);

    Aluno *vec = NULL;

    Fita FitasEntrada[FITAS];

    Fita FitasSaida[FITAS];

    int i;

    inicializaFitas(FitasEntrada);
    inicializaFitas(FitasSaida);

    vec = alocaVetor(vec);

    const char* str1 = "FitaEntrada";

    const char* str2 = "FitaSaida";

    char entrada[15];

    char saida[15];

    char *num;
    //char num[10];

    //Abrindo os 40 arquivos, 20 representado cada fita de entrada e 20 representando cada fita de saida
    for(i = 0; i < FITAS; i++){
        asprintf(&num, "%d", i + 1);
        //sprintf(num, "%d", i + 1);

        strcat(strcpy(entrada, str1), num);
        strcat(strcpy(saida, str2), num);

        if((FitasEntrada[i].arquivo = fopen(entrada, "w+b")) == NULL){
            printf ("ERRO na abertura do arquivo \n");
            return;
        }

        if((FitasSaida[i].arquivo = fopen(saida, "w+b")) == NULL){
            printf ("ERRO na abertura do arquivo \n");
            return;
        }
    }

    free(num);


    int cont = 0;
    int j = 0;

    
    //1º FASE: Ordenação dos blocos e os levando para as fitas de entrada
    //printf("%ld %p", sizeof(Aluno), arquivo);

    Aluno reg;

    for(cont = 0; cont < quantidadeDeAlunos; cont += 20){

       
        for(i = 0; i < REGISTROS; i++){ 
            fread(&reg, sizeof(Aluno), 1, arquivo);
            (*contLeitura)++;
            vec[i] = reg;
        }  

        insertionSort(vec, REGISTROS, contComp);

        FitasEntrada[j].qtdBlocos++;
        for(i = 0; i < REGISTROS; i++){
            reg = vec[i];
            fwrite(&reg, sizeof(Aluno), 1, FitasEntrada[j].arquivo);
            (*contEscrita)++;
        } 

        j++;
        if (j == FITAS){

            j = 0;
        }
    }

    int divisaoNaoExata = 0;

    if (quantidadeDeAlunos % REGISTROS != 0){
        
        divisaoNaoExata = 1;
    }

    //Alocando vetor que guarda a quantidade de blocos (de 20 registros) que existem por fita e os inicializando com seus
    //respectivos valores de registros
    for(i = 0; i < FITAS; i++){
        FitasEntrada[i].numReg = alocaBlocos(FitasEntrada[0].qtdBlocos, FitasEntrada[i].numReg);
        FitasSaida[i].numReg = alocaBlocos(FitasSaida[0].qtdBlocos, FitasSaida[i].numReg);

        //Inicializo os blocos de entrada com 20 se tiver registros e 0 caso for vazio
        inicilizaBlocos(&FitasEntrada[i], FitasEntrada[0].qtdBlocos);
        

        //Caso a quantidadede total de registros não seja uma numero divisel por 20, terá uma unica fita com menos registros inicialmente
        if(divisaoNaoExata == 1){

            divisaoNaoExataFunc(&FitasEntrada[0]);
        }
         
        //Inicializo os blocos de saida todos com o valor 0
        inicializaBlocosZerados(&FitasSaida[i], FitasEntrada[0].qtdBlocos);
    }

    //A parti daqui terei que fazer uma recursão para usar os arquivos de saida como de entrada nas proximas intercalaçoes
    //2º FASE: Intercalação 
    intercalacaoPropriamenteDita(arquivo, FitasEntrada, FitasSaida, vec, quantidadeDeAlunos, contLeitura, contEscrita, contComp);


    //Desalocando os vetores que foram alocados dinamicamente, tanto dos blocos e o vetor utilizado para pesquisa
    vec = desalocaVetor(vec);

    for(i = 0; i < FITAS; i++){
       
        FitasEntrada[i].numReg = desalocaBlocos(FitasEntrada[i].numReg);
        FitasSaida[i].numReg = desalocaBlocos(FitasSaida[i].numReg);
    }

    for(i = 0; i < FITAS; i++){
        fclose(FitasEntrada[i].arquivo);
        fclose(FitasSaida[i].arquivo);
    }
}

void intercalacaoPropriamenteDita (FILE *arquivo, Fita *FitasEntrada, Fita *FitasSaida, Aluno *vec, int quantidadeDeAlunos, int *contLeitura, int *contEscrita, int *contComp){

    Aluno menor;

    int posicaovetor;

    int blocoEntrada = 0;

    int blocoSaida = 0;

    int total = 0;

    int i;

    int j;

    int cont;

    Aluno aux;
    
    //Faço todos os arquivos de entrada apontarem pro inicio deles novamente para começar fase de intercalação
    for(i = 0; i < FITAS; i++){
        rewind(FitasEntrada[i].arquivo);
        rewind(FitasSaida[i].arquivo);
    }

    i = 0;

    //Lembrar: o ponteiro nos arquivos continua nas suas devidas posições apos voltar pra criar um novo vetor com os 20 outros blocos
    //COLOCANDO CADA UM DOS 20 PRIMEIROS BLOCOS NAS FITAS DE SAIDA 

    /*
    for (j = 0; j < FITAS; j++){  
        for(i = 0; i < FitasEntrada[j].qtdBlocos; i++){
            fread(&fita, sizeof(Aluno), 20, FitasEntrada[j].arquivo);
            printf("FITA %d: ", j + 1);
            for(int k = 0; k < REGISTROS; k++){
                
                printf("%.2f ",  fita[k].nota);
            }
            printf("\n");
        } 
    }
    

    for(i = 0; i < FITAS; i++){
        rewind(FitasEntrada[i].arquivo);
        rewind(FitasSaida[i].arquivo);
    }
    */

    i = 0;
    int n;

    /*
    for(int a = 0; a < FITAS; a++){
        for(int m = 0; m < FitasEntrada[a].qtdBlocos; m++){
            printf("Bloco 1 : %d \n", FitasEntrada[a].numReg[m]);
        }
    }8
    */
        
    int numerototalLidas = 0;
    while (numerototalLidas < quantidadeDeAlunos){ 
        for (j = 0; j < REGISTROS; j++){  

            //Coloco a cada posição do vetor o primeiro registro de cada bloco de cada fita de entrada                                                                                                                                                                            
            if (FitasEntrada[j].numReg[blocoEntrada] != 0) {          
                fread(&aux, sizeof(Aluno), 1, FitasEntrada[j].arquivo);
                (*contLeitura)++;  
                vec[j] = aux;                                                                   
                numerototalLidas++; 
                FitasEntrada[j].numReg[blocoEntrada]--; // Reduzo em 1 a posiçao de cada bloco de cada fita 
            }
                
            //Sobrepor os outros valores no vetor para evitar comparaçoes erradas e lixo de memoria no vetor
            else {
                vec[j].nota = 102;
            }
        }   

        /*
        printf("\n");

        for(int a = 0; a < FITAS; a++){
            for(int m = 0; m < FitasEntrada[a].qtdBlocos; m++){
                printf("Bloco 1 : %d \n", FitasEntrada[a].numReg[m]);
            }
        }
        */

       int contador = 0;

        //Quando todos os primeiros blocos tiverem 0 registros, eu paro esse do-while
        do{ 

            //OBS: a posição do vetor retornada representa de onde pegaremos o proximo registro para colocar no vetor
            menor = pesquisaSequencial(vec, &posicaovetor, contComp);

            //printf("%.2lf \n", menor.nota);
            n = posicaovetor; 
            
            //Troco o menor valor do vetor pelo proximo valor dele na fita de entrada, se ainda houver mais valores no bloco
            if(FitasEntrada[n].numReg[blocoEntrada] > 0){ 
                
                fread(&aux, sizeof(Aluno), 1, FitasEntrada[n].arquivo);
                (*contLeitura)++;
                //printf("%.2f ", aux.nota);
                vec[n] = aux;
                numerototalLidas++;
                FitasEntrada[n].numReg[blocoEntrada]--; 
            }

            //Apenas coloco o valor da posiçao do vetor com um numero muito alto para evitar comparaçoes repetidas
            else {
                vec[n].nota = 102.0;
                
            }

            /*
            printf("\n");

            for(int a = 0; a < FITAS; a++){
                for(int m = 0; m < FitasEntrada[a].qtdBlocos; m++){
                    printf("Bloco 1 : %d \n", FitasEntrada[a].numReg[m]);
                }
            }
            */

            //Escrevo o menor valor pegado na pesquisa sequencial na fita de saida i
            fwrite(&menor, sizeof(Aluno), 1, FitasSaida[i].arquivo);
            FitasSaida[i].numReg[blocoSaida]++;
            (*contEscrita)++;

            //printf("Blocos: %d\n", FitasSaida[i].numReg[blocoSaida]);

            //Conto a quantidade registros que ainda tem nos blocos que estao sendo usados, pois se ja tiverem acabados os registros, PARAMOS O WHILE
            total = 0; // Volto para 0, já que a quantidade de registros foi mudada
            for(cont = 0; cont < FITAS; cont++){
            
                total += FitasEntrada[cont].numReg[blocoEntrada]; 
            }
            
            contador++;

        } while(total > 0);

        printf("Contador: %d", contador);
        //Toda vez que terminar esse while, aumento a quantidade de blocos na fita de saida i
        FitasSaida[i].qtdBlocos++;
        
        //Alem disso, reduzo em 1 a quantidade de blocos das fitas de entrada 
        for(cont = 0; cont < FITAS; cont++){
            if (FitasEntrada[cont].qtdBlocos != 0)
                FitasEntrada[cont].qtdBlocos--;
        }

        blocoEntrada++; //Passo para o proximo bloco de cada fita de entrada, para preencher uma nova fita de saida

        i++; //Passo para proxima fita de saida

        //Zerando o valor de i para voltar a colocar os registros na primeira fita de saida e no proximo bloco 
        if (i == FITAS){
            blocoSaida++; //Passo para o proximo bloco de cada fita de saida

            i = 0; //Volto para a primeira fita para preencher o seu proximo bloco
        }
    }

    /*
    for(i = 0; i < FITAS; i++){
        rewind(FitasEntrada[i].arquivo);
        rewind(FitasSaida[i].arquivo);
    }

    
        Aluno fita[100];
        fread(&fita, sizeof(Aluno), 100, FitasSaida[0].arquivo);
        printf("FITA %d: ", 0);
        for(int k = 0; k < 100; k++){
                
            printf("%.2f ",  fita[k].nota);
        }
    */
    
    /*Verifico se todos os itens estão apenas na primeira fita de saida. Se sim, é porque a intercalação a acabou. 
     Caso contrario eu a continuo a intercalaçao recursivamente */

    int totalFita1;
    totalFita1 = 0;
    for(i = 0; i < FitasSaida[0].qtdBlocos; i++){

        totalFita1 += FitasSaida[0].numReg[i];
    }

    printf("TotalFita1: %d\n", totalFita1);
    printf("Quantidade: %d\n", quantidadeDeAlunos);

    Aluno reg;

    //Escrevo a fita de saida ordenada na ultima intercalação para o arquivo principal caso todos registros ja tenham sido ordenados 
    if(totalFita1 == quantidadeDeAlunos){

        rewind(arquivo);
        rewind(FitasSaida[0].arquivo);

        while(fread(&reg, sizeof(Aluno), 1, FitasSaida[0].arquivo) == 1){
            
            fwrite(&reg, sizeof(Aluno), 1, arquivo);
        }
        return;
    }
    getchar();
    intercalacaoPropriamenteDita(arquivo, FitasSaida, FitasEntrada, vec, quantidadeDeAlunos, contLeitura, contEscrita, contComp);
}

Aluno *alocaVetor(Aluno *alunos){

    alunos = (Aluno*) malloc(REGISTROS * sizeof(Aluno));
  
    if (alunos == NULL){
        printf ("Falta de memoria...\n");
        return 0;
    }

  return alunos;
}

Aluno *desalocaVetor(Aluno *alunos){

    free(alunos);

    return NULL;
}

void insertionSort(Aluno *alunos, int n, int *contComp){
    int i, j;

    Aluno aux;

    for (i = 1; i < n; i++){
        
        aux = alunos[i];

        j = i - 1;

        (*contComp)++;
        while (j >= 0 && aux.nota < alunos[j].nota){
            
            alunos[j + 1] = alunos[j];
            j--;
            (*contComp)++;
        }

        alunos[j + 1] = aux;
    }
}

Aluno pesquisaSequencial(Aluno *vetor, int *posicaoVet, int *contComp){

    Aluno menor = vetor[0];

    int i;

    *posicaoVet = 0;
    
    for(i = 1; i < REGISTROS; i++){
        //printf("%.2lf ", vetor[i].nota);
        (*contComp)++;
        if(vetor[i].nota <= menor.nota){
            menor = vetor[i];
            *posicaoVet = i;
        }
    }
    //printf("\n\n");

    return menor;
}

int *alocaBlocos(int qtdFita1, int *bloco){

    /*Para todos os blocos das fitas, tanto de saida quanto de entrada, eu aloco a quantidade de blocos da fita 1, pois 
      teremos que nas fitas de entrada os blocos todos tenham o valor inicializado como 0, ate mesmo blocos que já
      sabemos que nao utilizaremos, visto que precisaremos desse valor 0, principalmente para montar cada vetor inicial 
      de 20 registros na fase de intercalação na fase*/
    bloco = (int*) malloc(qtdFita1 * sizeof(int));
  
    if (bloco == NULL){
        printf ("Falta de memoria...\n");
        return 0;
    }

    return bloco;
}

int *desalocaBlocos(int *bloco){

    free(bloco);
    
    return NULL;
}

void inicilizaBlocos(Fita *fita, int qtdFita1){
    int i;

    //O resto é usado para inicializar blocos das fitas de entrada que terão o valor 0
    int resto = qtdFita1 - fita->qtdBlocos;

    for (i = 0; i < fita->qtdBlocos; i++){
        fita->numReg[i] = REGISTROS;

    }

    if (resto == 1){

        fita->numReg[qtdFita1 - 1] = 0;
    } 
}

void divisaoNaoExataFunc (Fita *fita1){

    fita1->numReg[fita1->qtdBlocos - 1] = 5;
}

void inicializaBlocosZerados(Fita *fita, int qtdFita1){
    int i;
    for (i = 0; i < qtdFita1; i++){

        fita->numReg[i] = 0;
    }
}


22.00 24.50 24.50 30.00 102.00 102.00 102.00 102.00 102.00 102.00 102.00 102.00 102.00 102.00 102.00 102.00 102.00 102.00 102.00
Fita 1: 22.00

23.80 24.50 24.50 30.00 102.00 102.00 102.00 102.00 102.00 102.00 102.00 102.00 102.00 102.00 102.00 102.00 102.00 102.00 102.00
Fita 1: 22.00


//Conto a quantidade registros que ainda tem nos blocos que estao sendo usados, pois se ja tiverem acabados os registros, PARAMOS O WHILE
            total = 0; // Volto para 0, já que a quantidade de registros foi mudada
            for(cont = 0; cont < FITAS; cont++){
                
                total += FitasEntrada[cont].numReg[blocoEntrada]; 
            }