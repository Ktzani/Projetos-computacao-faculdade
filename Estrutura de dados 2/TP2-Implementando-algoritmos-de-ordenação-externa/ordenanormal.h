#ifndef ordenanormal_H
#define ordenanormal_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "imprime.h"

#define REGISTROS 20
#define FITAS 20

void inicializaFitas(Fita* fitaEmQuestao);
void intercala2fcaminhos(FILE *arquivo, int quantidadeDeAlunos, int *contLeitura, int *contEscrita, int *contComp);
void intercalacaoPropriamenteDita (FILE *arquivo, Fita *FitasEntrada, Fita *FitasSaida, Aluno *vec, int quantidadeDeAlunos, int *contLeitura, int *contEscrita, int *contComp);

Aluno *alocaVetor(Aluno *alunos);
Aluno *desalocaVetor(Aluno *alunos);

int *alocaBlocos(int qtdFita1, int *bloco);
int *desalocaBlocos(int *bloco);

void inicilizaBlocos(Fita *fita, int qtdFita1);
void inicializaBlocosZerados(Fita *fita, int qtdFita1);
void divisaoNaoExataFunc (Fita *fita6);

void alocaciaBlocos(Fita *FitasEntrada, Fita *FitasSaida, int divisaoNaoExata);

Aluno pesquisaSequencial(Aluno *vetor, int *posicaoVet, int *contComp);
void insertionSort(Aluno *alunos, int n, int *contComp);

#endif