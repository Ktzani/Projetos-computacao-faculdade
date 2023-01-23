#ifndef quick_sort_H
#define quick_sort_H

#include <stdio.h>
#include <stdlib.h>
#include "imprime.h"

#define TAMAREA 20
#define FALSE 0
#define TRUE 1

typedef struct{
    int tam;
    Aluno vetor[TAMAREA];
}TipoArea;

void quick_sort(FILE **ArqLi, int quantidade, char *nome, int *leitura, int *escrita, int *comparacoes);

void QuicksortExterno(FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, int Esq, int Dir, int *leitura, int *escrita, int *comparacoes);

void LeSup(FILE **ArqLEs, Aluno *UltLido, int *Ls, short *OndeLer, int *leitura);

void LeInf(FILE **ArqLi, Aluno *UltLido, int *Li, short *OndeLer, int *leitura);

void InserirArea(TipoArea *Area, Aluno *UltLido, int *NRArea, int *comparacoes);

void EscreveMax(FILE **ArqLEs, Aluno R, int *Es, int *escrita);

void EscreveMin(FILE **ArqEi, Aluno R, int *Ei, int *escrita);

void RetiraMax(TipoArea *Area, Aluno *R, int *NRArea, int *comparacoes);

void RetiraMin(TipoArea *Area, Aluno *R, int *NRArea, int *comparacoes);

void Particao(FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, TipoArea Area, int Esq, int Dir, int *i, int *j, int *leitura, int *escrita, int *comparacoes);

void InsereItem(Aluno *UltLido,TipoArea *Area, int *comparacoes);

int ObterNumCelOcupadas(TipoArea *Area);

void RetiraUltimo(TipoArea *Area, Aluno *R, int *comparacoes);

void RetiraPrimeiro(TipoArea *Area, Aluno *R, int *comparacoes);

void insert_sort(TipoArea *area, int *comparacoes);

void FAVazia(TipoArea *Area);

#endif