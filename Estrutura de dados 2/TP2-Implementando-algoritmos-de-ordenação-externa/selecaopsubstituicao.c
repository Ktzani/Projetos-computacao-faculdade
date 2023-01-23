#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "selecaopsubstituicao.h"

//Dentro dos métodos baseados em Intercalação nós possuímos duas fases.
void selecaoPorSubstituicao(FILE *arquivo, int quantidadeDeAlunos, int *leitura, int *escrita, int *comparacoes) {
    Fita fitaDeEntrada[FITAS];
    Fita fitaDeSaida[FITAS];
    inicializaFitas(fitaDeEntrada);
    inicializaFitas(fitaDeSaida);
    criaFitas(fitaDeEntrada, fitaDeSaida);
    Aluno basePIntercalar[REGISTROS];
    
    /* 
    1) Começamos criando os blocos inicialmente ordenados. Fazemos uma primeira varredura no
    arquivo inteiro, pega blocos de informações que cabem em memória principal e levam para ser odenados
    na memória principal, é isso que essa função vai fazer agora:
    */
    geraBlocoInicialOrdenado(arquivo, quantidadeDeAlunos, fitaDeEntrada, leitura, escrita, comparacoes);
    
    converte_para_txt(fitaDeEntrada[0].arquivo, quantidadeDeAlunos, "Robson1pG");
    converte_para_txt(fitaDeEntrada[1].arquivo, quantidadeDeAlunos, "Robson2pG");
    converte_para_txt(fitaDeEntrada[2].arquivo, quantidadeDeAlunos, "Robson3pG");
    /*
    Agora a gente intercala, onde o conceito se resumo em pegar os grandes blocos gerados na parte 
    da geração e manipular de forma a gerar um grande bloco ordenado. Isso será explicado posteriormente
    na parte do codigo da intercalação, nesse pequeno bloco que se segue o que acontece é que a gente 
    faz a inversão das fitas, ou seja quando todos os blocos foram ordenados e não há mais fitas de saida
    a serem utilizadas ele inverte as de entrada com as de saída e prossegue até retornar o 0 da intercalacao
    prossigamos para o funcionamento da intercalacao:
    */   
    int inversor = 1, intercalando = 1;
    while(intercalando) {
        if (inversor == 1) {
            intercalando = intercalacaoR(fitaDeEntrada, fitaDeSaida, basePIntercalar, inversor, leitura, escrita, comparacoes);
            inversor = 0;
        }
        else {
            intercalando = intercalacaoR(fitaDeSaida, fitaDeEntrada, basePIntercalar, inversor, leitura, escrita, comparacoes);
            inversor = 1;
        }
    } 
    /*
    No bloco de código seguinte é basicamente a passada do resultado final pro arquivo ordenado usado
    no arquivo principal.
    */
    Aluno reg;
    rewind(arquivo);
    rewind(fitaDeSaida[0].arquivo);
    while(fread(&reg, sizeof(Aluno), 1, fitaDeSaida[0].arquivo) == 1) {
        fwrite(&reg, sizeof(Aluno), 1, arquivo);
    }

    converte_para_txt(fitaDeSaida[0].arquivo, quantidadeDeAlunos, "Robson1pI");
    converte_para_txt(fitaDeSaida[1].arquivo, quantidadeDeAlunos, "Robson2pI");
    converte_para_txt(fitaDeSaida[2].arquivo, quantidadeDeAlunos, "Robson3pI");
}

//Geração dos blocos ordenados, na primeira parte da ordenação
void geraBlocoInicialOrdenado(FILE *arquivo, int quantidadeDeAlunos, Fita *fita, int *leitura, int *escrita, int *comparacoes) {
    //Essa estrutura de heap vai ser aquela que vai ser mandada para memória principal para ser ordenada
    Heap base[REGISTROS];
    int ditaFita = 0; 
    int restoDeAlunos = 0; 
    int contadorDeReg = 0; 
    int nPraMarcar = quantidadeDeAlunos*2; //valor alto so pra nao coincidir com uma possível nota

    //Primeira passada de leitura para ter arquivos para jogar no heap
    for (int i = 0; i < REGISTROS; i++) {
        (*leitura)++;
        fread(&base[i].registro, sizeof(Aluno), 1, arquivo);
        base[i].marcado = base[i].registro.nota;
    }
    
    while (quantidadeDeAlunos != 0) {
       /*
       A segunda variável é quantos registros vão ter nesse heap, ele vai ordenar em forma crescente  
       o heap, precisamos só tratar que o valor que é informado no segundo parâmetro seja igual a quantidade
       de registros que temos dentro do heap
       */
       heapSort(base, REGISTROS - restoDeAlunos, leitura, escrita, comparacoes); 
        /*
        Agora acontece a magica da selecao por substituicao, quando todos os elementos do vetor estao
        marcados, primeiro desmarcamos tudo, logo após damos início a um novo bloco que será posicionado
        em uma nova fita de entrada
        */
        if (taTudoMarcado(base, restoDeAlunos, nPraMarcar) == true) {
            desmarcandoOHeap(base, restoDeAlunos, nPraMarcar);
            fita[ditaFita % REGISTROS].qtdBlocos++;
            /*
            Esse bloco de código que se segue basicamente vai ser a alocação de memória necessária para
            o novo bloco que vai ser criado, tendo em vista que dentro desse if é quando todos os itens
            estão marcados, o if que se segue garante que a variavel alocador tenha o tamanho correto de
            blocos presente em cada fita, e atribui a quantidade certa de registros.
             */
            int* alocadorDeBloco = malloc((ditaFita / FITAS + 1) * sizeof(int));
            if((ditaFita / FITAS + 1) == 1) {
                alocadorDeBloco[0] = contadorDeReg;
                fita[ditaFita % FITAS].numReg = alocadorDeBloco;
            }

            else {
                // Pega todos os registros ja contidos dentro da fita adicionando a quantidade de registros do novo bloco
                for(int i = 0; i < ditaFita / FITAS; i++) {
                    alocadorDeBloco[i] = fita[ditaFita % FITAS].numReg[i];
                }
                alocadorDeBloco[ditaFita / FITAS] = contadorDeReg;
                fita[ditaFita % FITAS].numReg = alocadorDeBloco;
            }
            ditaFita++;
            contadorDeReg = 0;
        }
        /*
        Depois de fazer o heap temos que pegar o menor elemento e jogar dentro da fita de entrada 1
        O que acontece quando o heap não está todo marcado, ou quando é a primeira volta no arquivo?
        Pegamos a primeira posição do heap já ordenado no heapSort, ou seja, o menor valor daquele 
        heap e jogamos ele na fita 1, e lemos mais um jogando pro heapSort de novo mas atente-se ao
        quantidadeDeAlunos-- ele que vai regular até onde o codigo vai, ou seja, até escrever todos os
        alunos nas fitas de entrada.
        Sobre a marcação, quando o elemento que ta entrando é menor que o ultimo que saiu ele é marcado.
        */
        else {
            Heap ultimo = base[0];
            (*escrita)++;
            fwrite(&ultimo.registro, sizeof(Aluno), 1, fita[ditaFita % FITAS].arquivo);
            contadorDeReg++;
            /*
            Nesse bloco que se segue é onde ocorre a marcação onde averiguamos se o item que tá entrando é
            menor que o ultimo, se sim ele é marcado, se nao, da um false nele. O if é para nos atentarmos
            ao fato de que talvez o heap nao tenha 20 registros, para nao dar um vazamento de memória,
            ou seja enquanto houver mais que 20 alunos da pra fazer um heap completo, se não passo pro else
            de baixo
            */

            if (quantidadeDeAlunos - REGISTROS > 0) {
                (*leitura)++;
                fread(&base[0].registro, sizeof(Aluno), 1, arquivo);
                (*comparacoes)++;
                if(base[0].registro.nota < ultimo.registro.nota)
                    base[0].marcado = base[0].registro.nota + nPraMarcar;

                else
                    base[0].marcado = base[0].registro.nota;
            }

            /*
            Quando não tem alunos suficiente pra popular um heapSort de 20 posições ele manipula os que restam
            pegando o último registro e jogando ele pra primeira posição
            */
            else {
                ultimo = base[REGISTROS - restoDeAlunos - 1];
                base[0] = ultimo;
                restoDeAlunos++;
            }
            quantidadeDeAlunos--;
        }    
    }
   fita[ditaFita % FITAS].qtdBlocos++;

    /*
    Aqui ocorre uma tratativa para que a quantidade de registros restantes sejam armazenadas na fita
    mesmo quando a quantidade de alunos ja tenha 
    */
    int* aux = malloc((ditaFita / FITAS + 1) * sizeof(int));
    if((ditaFita / FITAS + 1) == 1) {
        aux[0] = contadorDeReg;
        fita[ditaFita % FITAS].numReg = aux;
    }

    else {
        for(int i = 0; i < ditaFita / FITAS; i++) {
            aux[i] = fita[ditaFita % FITAS].numReg[i];
        }  
        aux[ditaFita / FITAS] = contadorDeReg;
        fita[ditaFita % FITAS].numReg = aux;
    }
}

//Algoritmo de heapSort (1a fase)
void heapSort(Heap *heapPropriamenteDito, int n, int *leitura, int *escrita, int *comparacoes) {
    /*
    Algoritmo baseado de:
    https://www.cos.ufrj.br/~rfarias/cos121/aula_09.html
    Para contextualizar os parâmetros são: o heap que será ordenado, e o n funciona como a quantidade
    de registros que será levado em conta na operação. Odenando do menor para o maior todos os elementos
    presentes no heap
    */
    int i = n / 2, pai, filho;
    Heap auxiliar;
    
    while(true) {
        if(i > 0) {
            i--;
            auxiliar = heapPropriamenteDito[i];
        }
        else {
            n--;
            if(n <= 0) {
                return;
            } 
            auxiliar = heapPropriamenteDito[n];
            heapPropriamenteDito[n] = heapPropriamenteDito[0];
        }
        pai = i;
        filho = i * 2 + 1;
        while(filho < n) {
            (*comparacoes)++;
            if((filho + 1 < n) && (heapPropriamenteDito[filho + 1].marcado > heapPropriamenteDito[filho].marcado)) {
                filho++;
            }
            (*comparacoes)++;
            if(heapPropriamenteDito[filho].marcado > auxiliar.marcado) {
                heapPropriamenteDito[pai] = heapPropriamenteDito[filho];
                pai = filho;
                filho = pai * 2 + 1;
            }
            else {
                break;
            }
        }
        heapPropriamenteDito[pai] = auxiliar;
    }
    
}

//Geração dos arquivos de fita (1a fase)
void criaFitas(Fita *fitaDeEntrada, Fita *fitaDeSaida) {
    const char* str1 = "FitaEntrada";
    const char* str2 = "FitaSaida";
    char entrada[15];
    char saida[15];

    //char *num;
    char num[10];

    for(int i = 0; i < FITAS; i++){
        //asprintf(&num, "%d", i + 1);
        sprintf(num, "%d", i + 1);

        strcat(strcpy(entrada, str1), num);
        strcat(strcpy(saida, str2), num);
        if((fitaDeEntrada[i].arquivo = fopen(entrada, "w+b")) == NULL){
            printf ("ERRO na abertura do arquivo \n");
            return;
        }
        if((fitaDeSaida[i].arquivo = fopen(saida, "w+b")) == NULL){
            printf ("ERRO na abertura do arquivo \n");
            return;
        }
    }
}

//Averigua se tá tudo marcado (1a fase)
bool taTudoMarcado(Heap *verificaremos, int nDeAlunosNoHeap, int valorBaseParaMarcar) {
    for(int i = 0; i < REGISTROS - nDeAlunosNoHeap; i++) {
        if(verificaremos[i].marcado <= valorBaseParaMarcar / 2)
            return false;
    }
    return true;
}

//Desmarca todos os registros (1a fase)
void desmarcandoOHeap(Heap *base, int restoDeAlunos, int valorBaseParaDesmarcar) {
    for(int i = 0; i < REGISTROS - restoDeAlunos; i++) {
        base[i].marcado -= valorBaseParaDesmarcar;
    }
}

//Intercala os blocos ordenados de forma a ficarem crescentes, na segunda parte da ordenação
int intercalacaoR(Fita* entrada, Fita* saida, Aluno* basePIntercalar, int inversor, int *leitura, int *escrita, int *comparacoes) {
    int valorFita = 0;
    int result;
    //O result determina o numero da fita gerada pelo metodo
    if (inversor == 1) {
        result = FITAS + 1;
    }
    else {
        result = 1;
    }
    int tam = 0;
    /*
    Aqui descobrimos quantas fitas são disponíveis ou seja a quantidade de blocos difere de NULL, e 
    eles vao sendo retirados das fitas até chegar na condicao de parada que é quando o valor da fita se 
    igual a 1, ou seja, apenas uma fita está com os blocos de memórias ativos, isso quer dizer
    que o arquivo foi todo intercalado.
    */
    valorFita = nFitas(entrada);
    if(valorFita == 1) {
        return 0;
    }
    //Move os ponteiros pro começo, para ocorrer a leitura correta das fitas
    for(int i = 0; i < valorFita; i++)
        fseek(entrada[i].arquivo, 0, SEEK_SET);
    int* count = malloc(valorFita * sizeof(int));
    int posicao, continua, valorBase = 0;
    int* aux;
    Aluno menor;

    while(valorFita != 0) {
        /*
        Nessa variavel de count e nesse for que se segue o que ocorre é que é necesário alocar memória 
        para o que chegar das fitas de entrada então é atribuido ao contador o numero de registros
        disponível em cada arquivo
        */
        for(int i = 0; i < valorFita; i++)
            count[i] = entrada[i].numReg[valorBase];
        /*
        Aqui da-se inicio a intercalação realmente, que é o que faz-se a leitura do primeiro item de 
        cada bloco, das n fitas
        */
        for(int i = 0; i < valorFita; i++) {
            (*leitura)++;
            fread(&basePIntercalar[i], sizeof(Aluno), 1, entrada[i].arquivo);
            count[i]--;
        }
        continua = 1;
        if(saida[(result - 1) % FITAS].arquivo != NULL && saida[(result - 1) % FITAS].qtdBlocos != 0)
            continua = 1;
        else
            fseek(saida[(result - 1) % FITAS].arquivo, 0, SEEK_SET);
        //Verifica se tem blocos nas fitas
        if(tam / FITAS == 0) {
            aux = malloc((tam / FITAS + 1) * sizeof(int));
            aux[0] = 0;
            saida[(result - 1) % FITAS].numReg = aux;
        }
        else {
            aux = malloc((tam / FITAS + 1) * sizeof(int));
            for(int i = 0; i < tam / FITAS; i++) {
                aux[i] = saida[(result - 1) % FITAS].numReg[i];
            }
            /*
            Caso tenha blocos na fita, o aux copia tudo o que está no numReg, atribui 0 para
            a ultima posição do aux e numReg é apontado para ele
            */
            aux[tam / FITAS] = 0;
            saida[(result - 1) % FITAS].numReg = aux;
        }

        /*
        Aqui começamos as comparações e o funcionamento da intercalacao propriamente dito, primeiro pegamos
        a menor nota presente no vetor e escreve ele na saida, alem de dar um increase na quantidade de 
        registros da mesma fita de saida.
        */
        while(continua) {
            menor.nota = RAND_MAX;
            posicao = -1;
            for(int i = 0; i < valorFita; i++) {
                (*comparacoes)++;
                if(basePIntercalar[i].nota <= menor.nota && count[i] >= 0) {
                    menor = basePIntercalar[i];
                    posicao = i;
                }
            }
            (*escrita)++;
            fwrite(&menor, sizeof(Aluno), 1, saida[(result - 1) % FITAS].arquivo);
            saida[(result - 1) % FITAS].numReg[tam / FITAS]++;
            /*
            Nesse bloco de código que se segue fazemos a leitura da quantidade de registros presentes
            no bloco e confere se todos foram lidos para dar continuidade a intercalacao ou nao, podendo
            dar inicio a um novo bloco em uma fita, é importante salientar que sempre que ocorre
            a leitura de todos os primeiros blocos das fitas de entrada um novo bloco, possivelmente 
            em uma nova fita é criada.
            */
            if(count[posicao] > 0) {
                (*leitura)++;
                fread(&basePIntercalar[posicao], sizeof(Aluno), 1, entrada[posicao].arquivo);
            }
            count[posicao]--;
            continua = prossiga(count, valorFita);
        }
        /*
        Aqui nós retiramos a quantidade de blocos da entrada e aumentamos na saída, afinal eles foram
        transferidos, aumentamos os contadores que servem para basear posição de fita em suma e quando
        tudo acaba, ou seja a quantidade de blocos da fita acaba (toda lida), ai retornamos 1 para fazer
        a leitura do bloco atual + 1 e continuar a intercalação.
        */
        for(int i = 0; i < valorFita; i++)
            entrada[i].qtdBlocos--;

        saida[(result - 1) % FITAS].qtdBlocos++;
        valorFita = nFitas(entrada);
        result++;
        valorBase++;
        tam++;
    }
    free(count);
    return 1;
}

//Vai retornar a quantidade de fitas (seja entrada ou saída) que não são nulas (2a fase)
int nFitas(Fita* fitas) {
    int fitasPrajogo = 0;
    for(int i = 0; i < FITAS; i++) {
        if(fitas[i].qtdBlocos != 0) {
            fitasPrajogo++;
        }
        else {
            break;
        }   
    }
    return fitasPrajogo;
}

//Função que verifica se todo o bloco foi lido (2a fase)
int prossiga(int *count, int valorFita) {
    int continua = 0;
    for(int i = 0; i < valorFita; i++) {
        if(count[i] < 0) {
            continua++;
        }
    }
    if(continua == valorFita) {
        return 0;
    }  
    else {
        return 1;
    }  
}