#ifndef selecaosubstituicao_H
#define selecaosubstituicao_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "imprime.h"
#include "ordenanormal.h"

#define REGISTROS 20
#define FITAS 20

typedef struct {
    Aluno registro;
    double marcado;
} Heap;

void criaFitas(Fita *fitaDeEntrada, Fita *fitaDeSaida);

void selecaoPorSubstituicao(FILE *arquivo, int quantidadeDeAlunos, int *leitura, int *escrita, int *comparacoes);
void geraBlocoInicialOrdenado(FILE *arquivo, int quantidadeDeAlunos, Fita *fita, int *leitura, int *escrita, int *comparacoes);
void heapSort(Heap *heapPropriamenteDito, int n, int *leitura, int *escrita, int *comparacoes);
bool taTudoMarcado(Heap *verificaremos, int nDeAlunosNoHeap, int valorBaseParaMarcar);
void desmarcandoOHeap(Heap *base, int restoDeAlunos, int valorBaseParaDesmarcar);

int intercalacaoR(Fita* entrada, Fita* saida, Aluno* basePIntercalar, int inversor, int *leitura, int *escrita, int *comparacoes);
int nFitas(Fita* fitas);
int prossiga(int* count, int numFitas);
#endif