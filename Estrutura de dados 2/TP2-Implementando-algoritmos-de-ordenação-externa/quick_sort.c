#include <stdio.h>
#include <limits.h>

#include "quick_sort.h"

//Parte principal, que abre os ponteiros de leitura e escrita
void quick_sort(FILE **ArqLi, int quantidade, char *nome, int *leitura, int *escrita, int *comparacoes){

    FILE *ArqEi = NULL,  *ArqLEs = NULL;

    //Aberturas
    ArqLEs = fopen(nome, "r+b");
    if(ArqLEs == NULL){
        printf("Error abertura ArqLEs");
    }

    ArqEi = fopen(nome, "r+b");
     if(ArqEi == NULL){
        printf("Error abertura ArqEi");
    }

    //Erros
    if(ArqLEs == NULL){
        printf("Error 2\n");
        return;
    }

    if(ArqEi == NULL){
        printf("Error 3\n");
        return;
    }

    //chamada da função com os contadores
    QuicksortExterno(ArqLi, &ArqEi, &ArqLEs, 1, quantidade, leitura, escrita, comparacoes);

    //limpando o buffer
    fflush(ArqEi);
    fflush(ArqLEs);

    //fechando os ponteiros auxiliares
    fclose(ArqEi);
    fclose(ArqLEs);

}


void QuicksortExterno(FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, int Esq, int Dir, int *leitura, int *escrita, int *comparacoes){
    int i, j; //limites

    TipoArea Area;//vetor interno

    //verifica se os ponteiros nao se cruzaram
    if((Dir - Esq) < 1){
        return;
    }

    //enche todas as chaver com MAX_INT
    FAVazia(&Area);

    //Faz a partição do arquivo, e ja vai ordenando
    Particao(ArqLi, ArqEi, ArqLEs, Area, Esq, Dir, &i, &j, leitura, escrita, comparacoes);

    //Escolhe sempre o menor subarquivo para ordenar primeiro
    if((i - Esq) < (Dir - j)){
        QuicksortExterno(ArqLi, ArqEi, ArqLEs, Esq, i, leitura, escrita, comparacoes);
        QuicksortExterno(ArqLi, ArqEi, ArqLEs, j, Dir, leitura, escrita, comparacoes);
    }else{
        QuicksortExterno(ArqLi, ArqEi, ArqLEs, j, Dir, leitura, escrita, comparacoes);
        QuicksortExterno(ArqLi, ArqEi, ArqLEs, Esq, i, leitura, escrita, comparacoes);
    }
}

void Particao(FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, TipoArea Area, int Esq, int Dir, int *i, int *j, int *leitura, int *escrita, int *comparacoes){
    //ponteiros, auxiliares, limites, etc
    int Ls = Dir, Es = Dir, Li = Esq, Ei = Esq, NRArea = 0;
    double Linf = INT_MIN, Lsup = INT_MAX;

    short OndeLer = TRUE;
    Aluno UltLido, R;

    //aloca os ponteiros na posição correta
    fseek(*ArqLi, (Li-1) * sizeof(Aluno), SEEK_SET);
    fseek(*ArqEi, (Ei-1)* sizeof(Aluno), SEEK_SET);

    //aloca os limites i e j
    *i = Esq-1;
    *j = Dir+1;

    //enquanto os ponteiros nao se cruzarem
    while(Ls >= Li){

        //enquanto a area tiver uma casa sobrando
        if(NRArea < TAMAREA-1){
            if(OndeLer){//leitura da ponta direta 
                LeSup(ArqLEs, &UltLido, &Ls, &OndeLer, leitura);
            }else {//leitura da ponta esqerda
                LeInf(ArqLi, &UltLido, &Li, &OndeLer, leitura);
            }

            //insere no vetor interno
            InserirArea(&Area, &UltLido, &NRArea, comparacoes);

            continue;
        }

        //caso os ponteiros de leitura e escrita sejam iguais
        if(Ls == Es){
            LeSup(ArqLEs, &UltLido, &Ls, &OndeLer, leitura);
        }else if(Li == Ei){ 
            LeInf(ArqLi, &UltLido, &Li, &OndeLer, leitura);
        }else if(OndeLer){ //caso a ultima leitura tenha sido um LeInf
            LeSup(ArqLEs, &UltLido, &Ls, &OndeLer, leitura);
        }else{ //caso a ultima leitura tenha sido um LeSup
            LeInf(ArqLi, &UltLido, &Li, &OndeLer, leitura);
        }

        //verifica se o ultimo lido ultrapassa o limite superior
        (*comparacoes)++;//contador
        if(UltLido.nota > Lsup){
            *j = Es;
            EscreveMax(ArqLEs, UltLido, &Es, escrita);
            continue;
        } 

        //verifica se o ultimo lido é menor que o limite inferior
        (*comparacoes)++;//contador
        if(UltLido.nota < Linf){
            *i = Ei;
            EscreveMin(ArqEi, UltLido, &Ei, escrita);
            continue;
        }

        //insere no vetor interno e ordena
        InserirArea(&Area, &UltLido, &NRArea, comparacoes);

        //verifica qual harea de escrita é maior 
        if(Ei-Esq < Dir-Es){
            RetiraMin(&Area, &R, &NRArea, comparacoes);
            EscreveMin(ArqEi, R, &Ei, escrita);
            Linf = R.nota;
        }
        else{
            RetiraMax(&Area, &R, &NRArea, comparacoes);
            EscreveMax(ArqLEs, R, &Es, escrita);
            Lsup = R.nota;
        }
    }

    //esvazia os intens do vetor interno
    while(Ei <= Es){
        RetiraMin(&Area, &R, &NRArea, comparacoes);
        EscreveMin(ArqEi, R, &Ei, escrita);
    }
}

//faz a leitura do item mais a direita do subarquivo selecionado
void LeSup(FILE **ArqLEs, Aluno *UltLido, int *Ls, short *OndeLer, int *leitura){
    fseek(*ArqLEs, (*Ls - 1) * sizeof(Aluno), SEEK_SET);
    fread(UltLido, sizeof(Aluno), 1, *ArqLEs);
    (*Ls)--;
    (*leitura)++;//contador
    *OndeLer = FALSE;
}

//faz a leitura do item mais a esquerda do subarquivo selecionado
void LeInf(FILE **ArqLi, Aluno *UltLido, int *Li, short *OndeLer, int *leitura){
    fread(UltLido, sizeof(Aluno), 1, *ArqLi);
    (*Li)++;
    (*leitura)++;
    *OndeLer = TRUE;
}

//insere um item na area e ordena depois
void InserirArea(TipoArea *Area, Aluno *UltLido, int *NRArea, int *comparacoes){
    InsereItem(UltLido, Area, comparacoes);
    *NRArea = ObterNumCelOcupadas(Area);
}

//escreve no maximo a direita que o ponteiro de escrita se encontra
void EscreveMax(FILE **ArqLEs, Aluno R, int *Es, int *escrita){
    fseek(*ArqLEs, (*Es-1) * sizeof(Aluno), SEEK_SET);
    fwrite(&R, sizeof(Aluno), 1, *ArqLEs);
    (*Es)--;
    (*escrita)++;
}

//escreve no maximo a esquerda que o ponteiro de escrita se encontra
void EscreveMin(FILE **ArqEi, Aluno R, int *Ei, int *escrita){
    fwrite(&R, sizeof(Aluno), 1, *ArqEi);
    (*Ei)++;
    (*escrita)++;
}

//retira a maior chave do vetor interno
void RetiraMax(TipoArea *Area, Aluno *R, int *NRArea, int *comparacoes){
    RetiraUltimo(Area, R, comparacoes);
    *NRArea = ObterNumCelOcupadas(Area);
}

//retira a menor chave do vetor interno
void RetiraMin(TipoArea *Area, Aluno *R, int *NRArea, int *comparacoes){
    RetiraPrimeiro(Area, R, comparacoes);
    *NRArea = ObterNumCelOcupadas(Area);
}

//taca INT_MAX pra simular um vetor vazio
void FAVazia(TipoArea *Area){
    for(int i = 0; i < TAMAREA; i++){
        Area->vetor[i].nota = INT_MAX;
    }
    Area->tam = 0;
}

//insere na arvore e ordena
void InsereItem(Aluno *UltLido,TipoArea *Area, int *comparacoes){
    Area->vetor[Area->tam] = *UltLido;
    Area->tam = Area->tam + 1;

    insert_sort(Area, comparacoes);
}

//retorna o numero de celulas ocupadas
int ObterNumCelOcupadas(TipoArea *Area){
    return Area->tam;
}

//retira o maior item do vetor
void RetiraUltimo(TipoArea *Area, Aluno *R, int *comparacoes){
    if(Area->tam == 0){
        printf("ERRO retira ultimo 0\n");
        return;
    }

    *R = Area->vetor[Area->tam - 1];
    Area->vetor[Area->tam - 1].nota = INT_MAX;

    insert_sort(Area, comparacoes);

    Area->tam = Area->tam - 1;
}

//retira o menor item do vetor
void RetiraPrimeiro(TipoArea *Area, Aluno *R, int *comparacoes){
    if(Area->tam == 0){
        printf("ERRO retira primeiro 0\n");
        return;
    }

    *R= Area->vetor[0];
    Area->vetor[0].nota = INT_MAX;

    insert_sort(Area, comparacoes);

    Area->tam = Area->tam - 1;
}

//metodo de ordenação interna
void insert_sort(TipoArea *area, int *comparacoes){

    Aluno aux;
    int j, i;
    for(i = 1; i < TAMAREA; i++){
        aux = area->vetor[i];
        j = i-1;

        while((j >= 0) && (aux.nota < area->vetor[j].nota)){
            (*comparacoes)++;
            area->vetor[j+1] = area->vetor[j];
            j--;
        }

        area->vetor[j+1] = aux;
    }
}
