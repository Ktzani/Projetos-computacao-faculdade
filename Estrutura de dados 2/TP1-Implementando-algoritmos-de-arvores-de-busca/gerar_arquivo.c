#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int chave;
    long int dado1;
    char dado2[1000];
    char dado3[5000];
}Registro;

Registro geraRegistro(int i){
    Registro temp;

    temp.chave = i;
    temp.dado1 = (long int)(rand() % 100);
    temp.dado2[0] = 65 + (rand() % 26);
    temp.dado2[1] = '\0';
    temp.dado3[0] = 97 + (rand() % 26);
    temp.dado3[1] = '\0';

    return temp;
}

void geraArquivo (int inicio, int fim, char *nome){
    FILE *arquivo = fopen(nome, "wb");
    if(arquivo == NULL){
        printf("ERRO GERAÇÂO \n");
        return;
    }

    int i;
    Registro temp;

    for(i = inicio; i <= fim; i++){  
        temp = geraRegistro(i);
        fwrite(&temp, sizeof(Registro), 1, arquivo);
    }

    printf("Concluido \n");
    fclose(arquivo);
}

void inverteArquivo(char *entra, char *sai, int tam){

    FILE *entrada = fopen(entra, "rb");
    if(entrada == NULL){
        printf("ERRO INVERÇÂO ENTRADA\n");
        return;
    }

    FILE *saida = fopen(sai, "wb");
    if(saida == NULL){
        printf("ERRO INVERÇÂO SAIDA\n");
        return;
    }

    Registro temp;

    int i;
    for(i = 1; i <= tam; i++){
        fseek(entrada,(-1) * sizeof(Registro) * i, SEEK_END);
        fread(&temp, sizeof(Registro), 1, entrada);
        fwrite(&temp, sizeof(Registro), 1, saida);
    }

    fclose(entrada);
    fclose(saida);

    printf("Concluido Inverso\n");
}

void print_arquivo(int n, char *nome){

    FILE *arquivo = NULL;
    arquivo = fopen(nome, "rb");
    if(arquivo == NULL){
        printf("ERRO PRINT\n");
        return;
    }

    Registro temp;

    int i;
    for ( i = 1; i <= n; i++){
    
        fread(&temp, sizeof(Registro), 1, arquivo);
        printf("%-7d %-2ld %c %c |", temp.chave, temp.dado1, temp.dado2[0], temp.dado3[0]);
        //printf("%-7d ", temp.chave);

        if(i % 10 == 0)
            printf("\n");
            
    }

    printf("\n");

    fclose(arquivo);
}

void copia(char *entra, char *sai, int tam){
    FILE *entrada = fopen(entra, "rb");
    if(entrada == NULL){
        printf("ERRO COPIA ENTRADA\n");
        return;
    }

    FILE *saida = fopen(sai, "wb");
    if(saida == NULL){
        printf("ERRO COPIA SAIDA\n");
        return;
    }

    Registro temp;

    int i;
    for(i = 1; i <= tam; i++){
        fread(&temp, sizeof(Registro), 1, entrada);
        fwrite(&temp, sizeof(Registro), 1, saida);
    }

    fclose(entrada);
    fclose(saida);

    printf("Concluido copia\n");
}

void bagunca(char *entrada, char *saida, int tam){

    copia(entrada, saida, tam);

    FILE *arquivo = NULL;
    arquivo = fopen(saida, "r+b");
    if(arquivo == NULL){
        printf("ERRO BAGUNÇA\n");
        return;
    }

    int i, troca1, troca2, inicio = 0, fim, tamanho;
    Registro temp1, temp2;

    if(tam <= 10000){
        tamanho = tam;
    }else{
        tamanho = 10000;
    }

    while(inicio < tam){

        fim = tam - inicio;
        for(i = 1; i <= tamanho; i++){
            troca1 = inicio + rand() % fim;
            troca2 = inicio + rand() % fim;

            fseek(arquivo, sizeof(Registro) * troca1, SEEK_SET);
            fread(&temp1, sizeof(Registro), 1, arquivo);

            fseek(arquivo, sizeof(Registro) * troca2, SEEK_SET);
            fread(&temp2, sizeof(Registro), 1, arquivo);

            fseek(arquivo, sizeof(Registro) * troca1, SEEK_SET);
            fwrite(&temp2, sizeof(Registro), 1, arquivo);

            fseek(arquivo, sizeof(Registro) * troca2, SEEK_SET);
            fwrite(&temp1, sizeof(Registro), 1, arquivo);
        }

        inicio += 25000;
    };

    printf("Concluido bagunça\n");

    fclose(arquivo);
}

int main(){

    srand(time(NULL));

    //Para modificar o tamanho dos arquivos
    //4 arquivos de tamanho = x
    int tamanho = 250000;
    int printar = 0;

    geraArquivo(((tamanho * 0) + 1), (tamanho * 1), "crescente_a");    
    geraArquivo(((tamanho * 1) + 1), (tamanho * 2), "crescente_b");    
    geraArquivo(((tamanho * 2) + 1), (tamanho * 3), "crescente_c");    
    geraArquivo(((tamanho * 3) + 1), (tamanho * 4), "crescente_d");    

    inverteArquivo("crescente_d", "decrescente_a", tamanho);
    inverteArquivo("crescente_c", "decrescente_b", tamanho);
    inverteArquivo("crescente_b", "decrescente_c", tamanho);
    inverteArquivo("crescente_a", "decrescente_d", tamanho);

    bagunca("crescente_a", "aleatorio_a", tamanho);
    bagunca("crescente_b", "aleatorio_b", tamanho);
    bagunca("crescente_c", "aleatorio_c", tamanho);
    bagunca("crescente_d", "aleatorio_d", tamanho);

    if(printar){
        print_arquivo(tamanho,"crescente_a");
        print_arquivo(tamanho,"crescente_b");
        print_arquivo(tamanho,"crescente_c");
        print_arquivo(tamanho,"crescente_d");
        print_arquivo(tamanho,"decrescente_a");
        print_arquivo(tamanho,"decrescente_b");
        print_arquivo(tamanho,"decrescente_c");
        print_arquivo(tamanho,"decrescente_d");
        print_arquivo(tamanho,"aleatorio_a");
        print_arquivo(tamanho,"aleatorio_b");
        print_arquivo(tamanho,"aleatorio_c");
        print_arquivo(tamanho,"aleatorio_d");
    }

    return 0;

}