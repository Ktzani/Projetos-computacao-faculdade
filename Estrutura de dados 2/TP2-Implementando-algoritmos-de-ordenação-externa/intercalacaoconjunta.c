#include <stdio.h>
#include <stdlib.h>
#include "ordenanormal.h"

void intercalacaoPropriamenteDita (FILE *arquivo, Fita *FitasEntrada, Fita *FitasSaida, Aluno *vec, int quantidadeDeAlunos){
    Aluno menor;
    int posicaovetor;
    int blocoEntrada = 0;
    int blocoSaida = 0;
    int total = 0;
    int i;
    int j;
    int cont;
    Aluno aux;

    for(i = 0; i < FITAS; i++){
        rewind(FitasEntrada[i].arquivo);
        rewind(FitasSaida[i].arquivo);
    }

    i = 0;
    int n;
    int numerototalLidas = 0;

    while (numerototalLidas < quantidadeDeAlunos){ 
        for (j = 0; j < REGISTROS; j++){
            if (FitasEntrada[j].numReg[blocoEntrada] != 0) { 
                fread(&aux, sizeof(Aluno), 1, FitasEntrada[j].arquivo);
                vec[j] = aux;
                numerototalLidas++;
                FitasEntrada[j].numReg[blocoEntrada]--;
            }
            //Sobrepor os outros valores no vetor para evitar comparaçoes erradas e lixo de memoria no vetor
            else {
                vec[j].nota = 102;
            }
        }   

        //Quando todos os primeiros blocos tiverem 0 registros, eu paro esse do-while
        do{ 

            //OBS: a posição do vetor retornada representa de onde pegaremos o proximo registro para colocar no vetor
            menor = pesquisaSequencial(vec, &posicaovetor); 
            n = posicaovetor; 
            
            //Troco o menor valor do vetor pelo proximo valor dele na fita de entrada, se ainda houver mais valores no bloco
            if(FitasEntrada[n].numReg[blocoEntrada] > 0){ 
                
                fread(&aux, sizeof(Aluno), 1, FitasEntrada[n].arquivo);
                vec[n] = aux;
                numerototalLidas++;
                FitasEntrada[n].numReg[blocoEntrada]--; 
            }

            //Apenas coloco o valor da posiçao do vetor com um numero muito alto para evitar comparaçoes repetidas
            else {
                vec[n].nota = 102;
                
            }

            //Escrevo o menor valor na fita de saida i
            fwrite(&menor, sizeof(Aluno), 1, FitasSaida[i].arquivo);
            FitasSaida[i].numReg[blocoSaida]++;

            //Conto a quantidade registros que ainda tem nos blocos que estao sendo usados, pois se ja tiverem acabados os registros, PARAMOS O WHILE
            total = 0; // Volto para 0, já que a quantidade de registros foi mudada
            for(cont = 0; cont < FITAS; cont++){
            
                total += FitasEntrada[cont].numReg[blocoEntrada]; 
            }
            

        } while(total != 0);

        //Toda vez que terminar esse while, aumento a quantidade de blocos na fita de saida i
        FitasSaida[i].qtdBlocos++;
        
        //Alem disso, reduzo em 1 a quantidade de blocos das fitas de entrada 
        for(cont = 0; cont < FITAS; cont++){
            if (FitasEntrada[cont].qtdBlocos != 0)
                FitasEntrada[cont].qtdBlocos--;
        }

        blocoEntrada++;
        i++;

        //Zerando o valor de i para voltar a colocar os registros na primeira fita de saida e no proximo bloco
        if (i == FITAS){
            blocoSaida++;

            i = 0;
        }
    }

    //Verifico se todos os itens estão apenas na primeira fita de saida. Se sim, é porque a intercalação a acabou. 
    //Caso contrario eu a continuo 

    int totalFita1;
    totalFita1 = 2;
    for(i = 0; i < FitasSaida[0].qtdBlocos; i++){

        totalFita1 += FitasSaida[0].numReg[i];
    }

    printf("TotalFita1: %d\n", totalFita1);
    printf("Quantidade: %d\n", quantidadeDeAlunos);

    Aluno reg;

    if(totalFita1 == quantidadeDeAlunos){

        rewind(arquivo);
        rewind(FitasSaida[0].arquivo);

        while(fread(&reg, sizeof(Aluno), 1, FitasSaida[0].arquivo) == 1){
            
            fwrite(&reg, sizeof(Aluno), 1, arquivo);
        }
        return;
    }
    getchar();
    intercalacaoPropriamenteDita(arquivo, FitasSaida, FitasEntrada, vec, quantidadeDeAlunos);
}