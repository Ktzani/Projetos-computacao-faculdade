# ifndef impri_h
# define impri_h

#include <stdio.h>
#include <time.h>

typedef double TChave;

typedef struct{
    FILE* arquivo;
    int qtdBlocos;
    int* numReg;
} Fita;

typedef struct Aluno{
    long int numero;
    float nota;
    char estado_cidade_curso[87];
} Aluno;

void trataMsgsDeERRO(int metodo, long int quantidade, int situ, int *argOpc, int argc, const char* opc);

void converter_para_binario(int quantidade, char entadada[], char nome_saida[]);
void comoConverter(int situ, int quantidade);

void qualMetodo();

void converte_para_txt(FILE *arquivo, int quantidade, char *nome_txt);

void arquivoCresDecres(int quantidade);
void removeArquivos();

void imprimeTUDO (FILE *arg, int orde, long int quantidade);
void imprimirExperimento(int contComp, int contLeitura, int contEscrita, double tTotal);
void imprimeAluno(Aluno a);
void imprimeArquivo(FILE* arq, int quant);

void divideString(const char *entrada, char *saida, int tamanho, int inicio);

#endif