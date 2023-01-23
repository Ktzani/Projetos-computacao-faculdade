#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "imprime.h"
#include "selecaopsubstituicao.h" 
#include "quick_sort.h" 
#include "ordenanormal.h"

void trataMsgsDeERRO(int metodo, long int quantidade, int situ, int *argOpc, int argc, const char* opc){

    if (quantidade <= 0){
        printf ("ERRO: o arquivo deve ter no minimo 1 registro\n");
        exit(1);

    }

    if (argc < 4){
        printf("ERRO: Poucos comandos digitados...\n");
        printf("Os argumentos são: ordena <metodo> <quantidade> <situacao> [-P]\n");
        printf ("OBS: [-P] é opcional\n");
        exit(1);
    }

    if (argc > 5){
        printf("ERRO: Muitos comandos digitados...\n");
        printf("Os argumentos são: ordena <metodo> <quantidade> <situacao> [-P]\n");
        printf ("OBS: [-P] é opcional\n");
        exit(1);
    }

    if (metodo < 1 || metodo > 4){

        printf ("ERRO: Argumento (método) inválido!\n");
        printf ("Metodo deve ser digitado como '1' para intercalação balanceada de varios caminhos com algum metodo de ordenação interna, '2' para intercalação balanceada de varios caminhos utilizando a técnica de seleção por substituição, '3' para Quicksort externo\n");
        exit(1);
    }

    if (situ < 1 || situ > 3){
        printf("ERRO: Argumento (situação) inválido!\n");
        printf("Situação deve ser digitada como '1' para arquivo arquivo ordenado ascendentemente , '2' para arquivo ordenado descendentemente e '3' para arquivo desordenado aleatoriamente pelas notas\n");
        exit(1);

    }

     /*vemos se foi ou nao digitado o argumento opcional. Se sim, ele passa a ser 1 (verdadeiro), para mais na frente
    realizarmos a impressao de todas as chaves do arquivo*/
    if(argc == 5){
        if(strcmp(opc ,"[-P]") == 0)
            *argOpc = 1;
        else{
            printf("ERRO: argumento opcional digitado errado!\n.");
            printf("Maneira correta é [-P]\n");
            exit(1);
        }
    } 

}

void converter_para_binario(int quantidade, char entadada[], char nome_saida[]){
    Aluno reg;

    FILE *arquivo_texto = NULL;
    arquivo_texto = fopen(entadada, "r");
    if(arquivo_texto == NULL){
        printf("ERRO rola\n");
        exit(1);
    }

    FILE *saida = NULL;
    saida = fopen(nome_saida, "wb");
    if(saida == NULL){
        printf("ERRO 2\n");
        exit(1);
    }

    for(int i = 0; i < quantidade; i++){
        
        fscanf(arquivo_texto, "%ld %f", &reg.numero, &reg.nota);

        fgets(reg.estado_cidade_curso, 86, arquivo_texto);

        reg.estado_cidade_curso[85] = '\0';

        fwrite(&reg, sizeof(Aluno), 1, saida);
    }

    fclose(arquivo_texto);
    fclose(saida);
}

void comoConverter(int situ, int quantidade){

    switch (situ) {
        case 1:
            converter_para_binario(quantidade, "textoCRE.txt", "binarioCRE.bin");
            break;

        case 2: 
            converter_para_binario(quantidade, "textoDEC.txt", "binarioDEC.bin");
            break;

        case 3: 
            converter_para_binario(quantidade, "textoALE.txt", "binarioALE.bin");
            break;
    }

}

void converte_para_txt(FILE *arquivo, int quantidade, char *nome_txt){
    int i;

    rewind(arquivo);

    FILE *saida = NULL;
    saida = fopen(nome_txt, "w");
    if (saida == NULL){
        printf("ERRO na conversão do arquivo para txt\n");
        exit(1);
    }

    Aluno Reg;
    
    for(i = 0; i < quantidade; i++){
        fread(&Reg, sizeof(Aluno), 1, arquivo);

        fprintf(saida, "%08ld %05.1f%s\n", Reg.numero, Reg.nota, Reg.estado_cidade_curso);
    }

    fclose(saida);
}

void arquivoCresDecres(int quantidade){

    Aluno reg;

    FILE *arquivo;
    FILE *arquivoC;
    FILE *arquivoD;

    int aux1, aux2, aux3;
    aux1 = aux2 = aux3 = 0;

    arquivo = fopen("binarioALE.bin", "rb");
    if(arquivo == NULL){
        printf("ERRO 1\n");
        exit(1);
    }

    arquivoC = fopen("binarioCRE.bin", "w+b");
    if(arquivoC == NULL){
        printf("ERRO 2\n");
        exit(1);
    }

    arquivoD = fopen("binarioDEC.bin", "wb");
    if(arquivoD == NULL){
        printf("ERRO 3\n");
        exit(1);
    }

    while(fread(&reg, sizeof(Aluno), 1, arquivo) == 1){
        fwrite(&reg, sizeof(Aluno), 1, arquivoC);
    }
    
    rewind(arquivoC);

    arquivoC = freopen("binarioCRE.bin", "r+b", arquivoC);
    
    //selecaoPorSubstituicao(arquivoC, quantidade, contLeitura, contEscrita, contComp);
    quick_sort(&arquivoC, quantidade, "binarioCRE.bin", &aux1, &aux2, &aux3);

    arquivoC = freopen("binarioCRE.bin", "rb", arquivoC);

    for (int i = 1; i <= quantidade; i++){
        fseek(arquivoC, sizeof(Aluno) * (quantidade - i), SEEK_SET);
        fread(&reg, sizeof (Aluno), 1, arquivoC);

        fwrite(&reg, sizeof(Aluno), 1, arquivoD);
    }
    
    fclose (arquivo);
    fclose (arquivoC);
    fclose (arquivoD);
}

void imprimeTUDO(FILE *arq, int orde, long int quantidade){
    Aluno reg;
    char estado[3], cidade[51], curso[31];

    rewind(arq);
    fflush(arq);

    for(int i = 0; i < quantidade; i++){
        fread(&reg, sizeof (Aluno), 1, arq); 

        if(!orde){
            printf("\nALUNO %d\n", i+1);
        }else{
            printf("\n%dº Lugar\n", i+1);
        }

        printf("\tNumero de Inscrição: %ld\n", reg.numero);
        printf("\tNota: %.1lf\n", reg.nota);

        divideString(reg.estado_cidade_curso, estado, 2, 1);
        printf("\tEstado: %s\n", estado);

        divideString(reg.estado_cidade_curso, cidade, 49, 4);
        printf("\tCidade: %s\n", cidade);

        divideString(reg.estado_cidade_curso, curso, 29, 55);
        printf("\tCurso: %s\n", curso);

        printf("\n--------------\n");
    }
    


    rewind(arq);
}

/*Imprime os valores dos contadores de transferencias e o tempo de execução tanto da pesquisa quanto do pre-processamento
do metodo utilizado */
void imprimirExperimento(int contComp, int contLeitura, int contEscrita, double tTotal){
    printf("EXPERIMENTO\n");
    printf("Transferencias de leitura: %d\n", contLeitura);
    printf("Transferencias de escrita: %d\n", contEscrita);
    printf("Comparações entre chaves: %d\n", contComp);
    printf("Tempo total: %.3lf s\n", tTotal);
}

void imprimeArquivo(FILE* arq, int quant) {
    Aluno a;
    int i = 1;
    
    rewind(arq);
    while(i <= quant && fread(&a,sizeof(Aluno),1,arq) == 1){
        imprimeAluno(a);
        i++;
    }
            
    rewind(arq);
}

void imprimeAluno(Aluno a){
    char estado[3], cidade[51], curso[31];

    printf("\tNumero de Inscrição: %ld\n", a.numero);
    printf("\tNota: %.1lf\n", a.nota);

    divideString(a.estado_cidade_curso, estado, 2, 1);
    printf("\tEstado: %s\n", estado);

    divideString(a.estado_cidade_curso, cidade, 49, 4);
    printf("\tCidade: %s\n", cidade);

    divideString(a.estado_cidade_curso, curso, 29, 55);
    printf("\tCurso: %s\n", curso);

    printf("\n--------------\n");
}

void removeArquivos(){

    //Removendo arquivos binarios após utiliza-los na ordenação
    remove ("binarioALE.bin");
    remove ("binarioDEC.bin");
    remove ("binarioCRE.bin");

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

        remove(entrada);
        remove(saida);
    }
}

void divideString(const char *entrada, char *saida, int tamanho, int inicio){
    int i;

    for(i = 0; i < tamanho; i++){
        saida[i] = entrada[inicio + i];
    }

    saida[i+1] = '\0';
}