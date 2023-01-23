#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "TP1.h"

#include <ctype.h>

// cores e formato de texto
#define ANSI_RESET "\x1b[0m"
#define ANSI_BOLD "\x1b[1m"
#define ANSI_COLOR_BLACK "\x1b[30m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_WHITE "\x1b[37m"
#define ANSI_BG_COLOR_BLACK "\x1b[40m"
#define ANSI_BG_COLOR_RED "\x1b[41m"
#define ANSI_BG_COLOR_GREEN "\x1b[42m"
#define ANSI_BG_COLOR_YELLOW "\x1b[43m"
#define ANSI_BG_COLOR_BLUE "\x1b[44m"
#define ANSI_BG_COLOR_MAGENTA "\x1b[45m"
#define ANSI_BG_COLOR_CYAN "\x1b[46m"
#define ANSI_BG_COLOR_WHITE "\x1b[47m"

// macros para facilitar o uso
#define BOLD(string) ANSI_BOLD string ANSI_RESET
#define BLACK(string) ANSI_COLOR_BLACK string ANSI_RESET
#define BLUE(string) ANSI_COLOR_BLUE string ANSI_RESET
#define RED(string) ANSI_COLOR_RED string ANSI_RESET
#define GREEN(string) ANSI_COLOR_GREEN string ANSI_RESET
#define YELLOW(string) ANSI_COLOR_YELLOW string ANSI_RESET
#define BLUE(string) ANSI_COLOR_BLUE string ANSI_RESET
#define MAGENTA(string) ANSI_COLOR_MAGENTA string ANSI_RESET
#define CYAN(string) ANSI_COLOR_CYAN string ANSI_RESET
#define WHITE(string) ANSI_COLOR_WHITE string ANSI_RESET
#define BG_BLACK(string) ANSI_BG_COLOR_BLACK string ANSI_RESET
#define BG_BLUE(string) ANSI_BG_COLOR_BLUE string ANSI_RESET
#define BG_RED(string) ANSI_BG_COLOR_RED string ANSI_RESET
#define BG_GREEN(string) ANSI_BG_COLOR_GREEN string ANSI_RESET
#define BG_YELLOW(string) ANSI_BG_COLOR_YELLOW string ANSI_RESET
#define BG_BLUE(string) ANSI_BG_COLOR_BLUE string ANSI_RESET
#define BG_MAGENTA(string) ANSI_BG_COLOR_MAGENTA string ANSI_RESET
#define BG_CYAN(string) ANSI_BG_COLOR_CYAN string ANSI_RESET
#define BG_WHITE(string) ANSI_BG_COLOR_WHITE string ANSI_RESET

#define TAB_HOR "\u2501" // ━ (horizontal)
#define TAB_VER "\u2503" // ┃ (vertical)
#define TAB_TL "\u250F"  // ┏ (top-left)
#define TAB_ML "\u2523"  // ┣ (middle-left)
#define TAB_BL "\u2517"  // ┗ (bottom-left)
#define TAB_TJ "\u2533"  // ┳ (top-join)
#define TAB_MJ "\u254B"  // ╋ (middle-join)
#define TAB_BJ "\u253B"  // ┻ (bottom-join)
#define TAB_TR "\u2513"  // ┓ (top-right)
#define TAB_MR "\u252B"  // ┫ (middle-right)
#define TAB_BR "\u251B"  // ┛ (bottom-right)



//PROTOTIPOS DAS FUNÇOES
int **alocaMemoriaInstrucoes(int **memoriaInstru, int n, int m){

    int i;

    memoriaInstru = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {

        memoriaInstru[i] = (int *)malloc(m * sizeof(int));
    }

    if (memoriaInstru == NULL){

        printf ("Falta de memória");
        exit(1);
    }  

    return memoriaInstru;

}

int *alocaMemoriaRam (int tamanhomemoria, int *memoriaRAM){


    memoriaRAM = (int *) malloc (tamanhomemoria * sizeof(int));

    if (memoriaRAM == NULL){

        printf ("Falta de memória");
        exit(1);
    }

    return memoriaRAM;
}

int **desalocaMemoriaInstru (int **memoriaInstru, int n) {
    int i;

    for (i = 0; i < n; i++){

        free(memoriaInstru[i]);
    }

    free(memoriaInstru);

    return NULL;

}

int *desalocaMemoriaRAM(int *memoriaRAM){

    free(memoriaRAM);

    return NULL;
}

void montarRAM(int tamanho_memoria, int *memoriaRAM){

    srand(time(NULL));

    int i;

    for (i = 0; i < tamanho_memoria; i++)
    {

        memoriaRAM[i] = rand() % 20;
    }
}

void menu(){

    printf(RED(BOLD("                                    -            COMANDOS            -\n")));
    printf(RED(BOLD("----------------------------------------------------------------------------------------------------      \n")));
    printf(RED(TAB_VER) GREEN(BOLD("Comando           "))  RED(TAB_VER) MAGENTA(BOLD("O que ele faz?                                                                 " RED(TAB_VER) "\n")));
    printf(RED(BOLD("----------------------------------------------------------------------------------------------------    \n")));
    printf(RED(TAB_VER) GREEN("-1                ")  RED(TAB_VER) MAGENTA("Encerra o programa                                                             " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("0                 ")  RED(TAB_VER) MAGENTA("Veja a tabela de comandos novamente                                            " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("1                 ")  RED(TAB_VER) MAGENTA("Realiza somas e subtrações aleatorias                                          " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("2                 ")  RED(TAB_VER) MAGENTA("Realiza multiplação com os valores aleatorios da memoria                       " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("3                 ")  RED(TAB_VER) MAGENTA("Realiza divisoes com valores aleatorios da memoria                             " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("4                 ")  RED(TAB_VER) MAGENTA("Realiza uma exponencial de acordo com um valor de base e expoente aleatorio    " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("5                 ")  RED(TAB_VER) MAGENTA("Realiza um teorema de pitagoras os lados com valores 3 e 4                     " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("6                 ")  RED(TAB_VER) MAGENTA("Encontra uma raiz quadrada                                                     " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("7                 ")  RED(TAB_VER) MAGENTA("Realiza um fatorial de 1 a 10                                                  " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("8                 ")  RED(TAB_VER) MAGENTA("Encontra a area de um quadrado                                                 " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("9                 ")  RED(TAB_VER) MAGENTA("Encontra a area de um retangulo                                                " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("10                ")  RED(TAB_VER) MAGENTA("Encontra a area de um triangulo                                                " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("11                ")  RED(TAB_VER) MAGENTA("Encontra a area de um circulo                                                  " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("12                ")  RED(TAB_VER) MAGENTA("Encontra a area de um losango                                                  " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("13                ")  RED(TAB_VER) MAGENTA("Encontra a area de um pararelogramo                                            " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("14                ")  RED(TAB_VER) MAGENTA("Encontra a area de um trapezio                                                 " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("15                ")  RED(TAB_VER) MAGENTA("Encontra o comprimento de uma circunferencia                                   " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("16                ")  RED(TAB_VER) MAGENTA("Encontra as raizes de uma funçao quadratica                                    " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("17                ")  RED(TAB_VER) MAGENTA("Encontra a area de um cubo                                                     " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("18                ")  RED(TAB_VER) MAGENTA("Encontra o volume de um cubo                                                   " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("19                ")  RED(TAB_VER) MAGENTA("Encontra a area de um paralelepipedo                                           " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("20                ")  RED(TAB_VER) MAGENTA("Encontra o volume de uma paralelepipedo                                        " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("21                ")  RED(TAB_VER) MAGENTA("Encontra a area de um cilindro                                                 " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("22                ")  RED(TAB_VER) MAGENTA("Encontra o volume de um cilindro                                               " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("23                ")  RED(TAB_VER) MAGENTA("Encontra um valor absoluto                                                     " RED(TAB_VER) "\n"));

    printf(RED(TAB_BL) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_BR) "\n");
}


void InstruAle(int **guarda_memoria, int *memoriadados)

{
    int instrumMemoryAlea[100][4];

    int i;

    srand(time(NULL));

    for (i = 0; i < 99; i++)
    {

        instrumMemoryAlea[i][0] = rand() % 2;
        instrumMemoryAlea[i][1] = rand() % 1000;
        instrumMemoryAlea[i][2] = rand() % 1000;
        instrumMemoryAlea[i][3] = rand() % 1000;

        /* j = 0 {{1 | 400 | 600 | 900}
               j = 1 {0 | 200 | 100 | 50}
               j = 2 {1 | 150 | 700 | 800}}    */
    }

    //HALT:
    instrumMemoryAlea[99][0] = -1;
    instrumMemoryAlea[99][1] = -1;
    instrumMemoryAlea[99][2] = -1;
    instrumMemoryAlea[99][3] = -1;


    maquina (instrumMemoryAlea, memoriadados);
    
}

void maquina(int guarda_memoria[][4], int *memoriaDados)
{

    int contPC;

    int opcode;

    int i;

    int umaInstrucao[4];

    for (contPC = 0; contPC < 405; contPC++)
    {
        for (i = 0; i < 4; i++){
    
         umaInstrucao[i] = guarda_memoria[contPC][i];
        }

        opcode = umaInstrucao[0];

        if (opcode == -1)
        {

            break;
        }

        else
        {

            maquinaOPERACOES(umaInstrucao, memoriaDados);
        }
    }
}

void maquinaOPERACOES(int *umaInstrucao, int *memoriaDados)
{

    int opcode = umaInstrucao[0];
    int end1;
    int end2;
    int endARMAZENA;

    int conteudoend1;
    int conteudoend2;

    switch (opcode)
    {
    case -1:{

        break;
    }

    case 0:
    { //soma

        end1 = umaInstrucao[1]; // LEMBRARRR DE MUDARR ?????w
        end2 = umaInstrucao[2]; // LEMBRARRR DE MUDARR ???

        conteudoend1 = memoriaDados[end1];
        conteudoend2 = memoriaDados[end2];

        int soma = conteudoend1 + conteudoend2;

        endARMAZENA = umaInstrucao[3]; // LEMBRARRR DE MUDARR???

        memoriaDados[endARMAZENA] = soma;

        printf("A soma de %d + %d é igual a %d\n", conteudoend1, conteudoend2, soma);

        break;
    }

    case 1:
    {

        end1 = umaInstrucao[1]; 
        end2 = umaInstrucao[2]; 

        conteudoend1 = memoriaDados[end1];
        conteudoend2 = memoriaDados[end2];

        int subtracao = conteudoend1 - conteudoend2;

        endARMAZENA = umaInstrucao[3]; 

        memoriaDados[endARMAZENA] = subtracao;

        printf("A subtracao de %d - %d é igual a %d\n", conteudoend1, conteudoend2, subtracao);

        break;
    }

    //levar para memoria de dados
    case 2: {
        int conteudo = umaInstrucao[1];
        int endereco = umaInstrucao[2];

        memoriaDados[endereco] = conteudo; /*salva um conteudo que vc pediu para salvar no endereço que 
                                                vc pediu para salvar*/

        break;
    }

    //pegar da memoria de dados;
    case 3: {

        umaInstrucao[1] = memoriaDados[umaInstrucao[2]]; /*pega da memoria de dados um conteudo que vc precisa e
                                                                que tinha guardado*/

        break;
    }
    }
}

void multiplicaInstru (int guarda_memoria[][4], int multiplicando, int multiplicador, int *memoriadedados){

    int multi = multiplicador + 3;

    int i, j;

    int instrumMemorymulti[100][4] ; // = guarda_memoria, porem com 3 instruçoes a mais

    int umaInstrucao[4];

    //leva o multiplicando para posiçao 0 da memoria, subescrevendo que estava la
    umaInstrucao[0] = 2;
    umaInstrucao[1] = multiplicando;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = -1;
    
    for(j = 0; j < 4; j++){
        instrumMemorymulti[0][j] = umaInstrucao[j]; // memoriadedados[0] = multiplicando
    }

    //leva o 0 para posiçao 1 da memoria subescrendo o que estava la
    umaInstrucao[0] = 2;
    umaInstrucao[1] = 0;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    for(j = 0; j < 4; j++){
        instrumMemorymulti[1][j] = umaInstrucao[j]; //mempriadedados[1] = 0
    }

    /* Faz "multiplicador" vezes somas do multiplicando, ou seja, soma o que esta na posiçao 0 com 
    o que esta na posiçao 1 e guarda na posiçao 1, para assim somar novamente com o multiplicando 
    com o novo valor repetidas vezes*/ 
    for(i = 2; i < multiplicador + 2; i++){

        umaInstrucao[0] = 0;
        umaInstrucao[1] = 0;
        umaInstrucao[2] = 1;
        umaInstrucao[3] = 1;

        for (j = 0; j < 4; j++){

            instrumMemorymulti[i][j] = umaInstrucao[j];
        }

    }

    umaInstrucao[0] = -1;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = -1;
    umaInstrucao[3] = -1;

    for(j = 0; j < 4; j++){

        instrumMemorymulti[multi][j] = umaInstrucao[j];
    }


    maquina (instrumMemorymulti, memoriadedados);

    //Trago o resultado da multiplicaçao para imprimi-lo 
    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int resultadoMulti = umaInstrucao[1];

    printf("\n");

    printf("O resultado da multiplicação é igual a %d\n\n", resultadoMulti);

}

void divideInstru (int guarda_memoria[][4], int dividendo, int divisor, int *memoriadados){

    int instrumMemorydivi[5][4];

    int umaInstrucao[4]; 

    int j;

    //primeiro levo os dados que preciso para RAM

    //leva o divisor para posiçao 0 da memoria de dados e subscreve o valor que estava la
    umaInstrucao[0] = 2;
    umaInstrucao[1] = divisor;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = -1;

    for(j = 0; j < 4; j++) {
        instrumMemorydivi[0][j] = umaInstrucao[j]; //memoriadedados[0] = divisor 

    }

    //leva o dividendo para posiçao 1 da memoria de daods e subscreve o valor que estava la
    umaInstrucao[0] = 2;
    umaInstrucao[1] = dividendo;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    for(j = 0; j < 4; j++) {
        instrumMemorydivi[1][j] = umaInstrucao[j]; //memoriadedados[1] = dividendo

    }

    /*variavel de incremento para ajudar na divisao, onde ela vai se somando com 0 (memoriadedados[3] = 0)
    para contar quantas divisoes tiveram ate que o valor que esta no endereço 1 (dividendo) for maior do que esta no
    enredeço 0(divisor)*/

    umaInstrucao[0] = 2;
    umaInstrucao[1] = 1;
    umaInstrucao[2] = 2;
    umaInstrucao[3] = -1;
    
    for(j = 0; j < 4; j++) {
        instrumMemorydivi[2][j] = umaInstrucao[j]; //memoriadedados[2] = 1

    }

    //usado para fazer a soma de quantas divisoes terão
    umaInstrucao[0] = 2;
    umaInstrucao[1] = 0;
    umaInstrucao[2] = 3;
    umaInstrucao[3] = -1;
    
    for(j = 0; j < 4; j++) {
        instrumMemorydivi[3][j] = umaInstrucao[j]; //memoriadedados[3] = 0 

    }

    /*OBS : A soma de varias memorias de dados de endereços 2 com 3 vao gerar o resultado final da divisao, onde essa
    soma se interrompe quando o dividendo for maior que o divisor*/

    

    /*HALT -> opcode = -1 -> Uso esse halt para PARAR a maquina (no caso a funçao maquina na linha 353) 
    nesse primeiro programa de montar a RAM que precisamos nessa divisão */

    umaInstrucao[0] = -1;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = -1; 
    umaInstrucao[3] = -1;

    for (j = 0; j < 4; j ++) {  
        
        instrumMemorydivi[4][j] = umaInstrucao[j];


    }

    maquina(instrumMemorydivi, memoriadados);


    //inicia de verdade a divisao!!!!

    /*trazendo da memoria para comparar os valores que estao no divisor e no dividendo em cada subtraçao
    depois de ja ter pegado os valores nos endereços 0 e 1 da RAM (faço isso, para contar a quantiade 
    de divisoes e realizar as subtraçoes necessarias) */

    //traz da memoriadados[0]
    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 0;   
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadados); /*valor do divisor é trazido 
                                                        e colocado na variavel valor0 */
    int valor0 = umaInstrucao[1]; 


    //traz da memoriadados[1]
    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;   
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadados); /*valor do dividendo inicial é trazido 
                                                        e colocado na variavel valor1 */
    int valor1 = umaInstrucao[1]; 

    /*faz um loop para comparar varias vezes para somar e subtrair varias vezes ate o valor do dividendo 
    for maior que o do divisor */
    
    while (valor1 >= valor0) {

        //SUBTRAÇAO:  o dividendo (que esta em memoriadedados[1]) - o divisor (que esta na memoriadados[0])
        umaInstrucao[0] = 1;
        umaInstrucao[1] = 1;
        umaInstrucao[2] = 0;
        umaInstrucao[3] = 1; /*subcresve o valor que estava no dividendo por uma novo valor que é o resulado 
                                da subtraçao e sera o novo dividendo (em memoriadados[1])*/
        maquinaOPERACOES(umaInstrucao, memoriadados);

        


        /*SOMA : Faz a soma de quantas divisoes estao ocorrendo (que é de acordo com a 
        quantidade de subtraçoes entre o dividendo e o disivosr*/
        umaInstrucao[0] = 0;
        umaInstrucao[1] = 2;
        umaInstrucao[2] = 3;
        umaInstrucao[3] = 3; /*subscreve o valor que esta na posiçao 3 da memoria de dados pela soma de 1 (posiçao 2)+ 
                                o que esta na posiçao 3 */

        maquinaOPERACOES(umaInstrucao, memoriadados); 

        /*traz novamente da memoria de dados o MESMO divisor (o valor do divisor não é alterado, 
        apenas o do dividendo) que esta em memoriadados[0]  */

        umaInstrucao[0] = 3;
        umaInstrucao[1] = -1;
        umaInstrucao[2] = 0;
        umaInstrucao[3] = -1;

        maquinaOPERACOES(umaInstrucao, memoriadados);
        valor0 = umaInstrucao[1];


        /*traz novamente da memoria de dados o NOVO dividendo (o valor do dividendo é alterado a cada subtração) 
        que esta em memoriadados[1]*/
        umaInstrucao[0] = 3;
        umaInstrucao[1] = -1;
        umaInstrucao[2] = 1;
        umaInstrucao[3] = -1;

        maquinaOPERACOES(umaInstrucao, memoriadados);
        valor1 = umaInstrucao[1];
    }

    //traz o resultado da divisao 

        umaInstrucao[0] = 3;
        umaInstrucao[1] = -1;
        umaInstrucao[2] = 3;
        umaInstrucao[3] = -1;

        maquinaOPERACOES(umaInstrucao, memoriadados);
        int resultadoDivi = umaInstrucao[1];

        printf ("\n");

        printf("O resultado da divisão é igual a %d\n", resultadoDivi);
    
}

void expoInstru (int guarda_memoria[][4], int base, int expoente, int *memoriadedados) {

    //2 ^ 3 = 2 * 2 * 2 = (2 + 2 + 2 + 2)

    //4 ^ 2 = 4 * 4 = ( 4 + 4 + 4 + 4)

    //int exp = expoente + 3;

    //int instrumMemoryexpo[exp][4];

    int umaInstrucao[4]; 

    int i, j;

    //leva para memoriadedados[0] o valor da base
    umaInstrucao[0] = 2;
    umaInstrucao[1] = base;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = -1;


    maquinaOPERACOES(umaInstrucao, memoriadedados);

    //leva para memoriadedados[1] o valor 0 para realizar a primeira soma com a base
    umaInstrucao[0] = 2;
    umaInstrucao[1] = 0;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);

    // 2 ^ 3 : 2 * 2 * 2 -> (2 + 2) = 4 * 2 -> (4 + 4) = 8
    // 3 ^ 3 : 3 * 3 * 3 -> (3 + 3 + 3) = 9 * 3 -> (9 + 9 + 9) = 27


    //Vai fazer n somas para de acordo com as soma que ja ocorreram 

    for (i = 0; i < expoente - 1; i++) { /*Sao n expoentes e não n - 1 expoentes, pois passara uma vez 
                                        dentro do primeiro for para realizar uma primeira soma e depois 
                                        colocar valor novo para base*/

        if (i != 0){
            //trazer da memoria o valor da "nova base" criada com as somas 

            umaInstrucao[0] = 3;
            umaInstrucao[1] = -1;
            umaInstrucao[2] = 1;
            umaInstrucao[3] = -1;

            maquinaOPERACOES(umaInstrucao, memoriadedados);
            int novabase = umaInstrucao[1];


            //coloca um novo valor na memoriadados[0] para realizar somas com um "novo valor de base"
            umaInstrucao[0] = 2;
            umaInstrucao[1] = novabase;
            umaInstrucao[2] = 0;
            umaInstrucao[3] = -1;

            maquinaOPERACOES(umaInstrucao, memoriadedados);
        } 

        else {
            umaInstrucao[0] = 0;
            umaInstrucao[1] = 0;
            umaInstrucao[2] = 1;
            umaInstrucao[3] = 1;

            maquinaOPERACOES(umaInstrucao, memoriadedados);
        }

        for (j = 0; j < base - 1; j ++){ /*Serao realizar n base - 1 somas ja que para cada
                                            valor novo de base, sempre há n base - 1 somas*/
            umaInstrucao[0] = 0;
            umaInstrucao[1] = 0;
            umaInstrucao[2] = 1;
            umaInstrucao[3] = 1;

            maquinaOPERACOES(umaInstrucao, memoriadedados);

        }
    }

    //halt 
    umaInstrucao[0] = -1;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = -1;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int resultadoEXPO = umaInstrucao[1];

    printf("\nO valor da expoenciaçao é igual a %d\n\n", resultadoEXPO);


}

void raizquadradaInstru (int guarda_memoria[][4], int valor, int *memoriaDados) {

    int base = 1;

    int instrumMemoryPit[500][4];

    int umaInstrucao[4];

    int resultadomulti = 0;


    umaInstrucao[0] = 2;
    umaInstrucao[1] = base;
    umaInstrucao[2] = 2;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriaDados); //memoriaDados[2] = base

    
    umaInstrucao[0] = 2;
    umaInstrucao[1] = 1;
    umaInstrucao[2] = 3;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriaDados);

    int auxiliar;

    do{

        auxiliar = base;

        printf ("\nMultiplicação entre %d e %d:\n", base, base);

        //uso da funçao de multiplicaçao para fazer a multiplicaçao entre bases (Ex : 1 * 1, 2 * 2, ...)
        multiplicaInstru(instrumMemoryPit, base, base, memoriaDados);

        /*Aumenta em 1 a base para fazer a multiplicaçao com novos valores +1 a mais usando o 
        opcode de soma (0)*/

        umaInstrucao[0] = 0;
        umaInstrucao[1] = 2;
        umaInstrucao[2] = 3;
        umaInstrucao[3] = 2;

        maquinaOPERACOES(umaInstrucao, memoriaDados); //memoriaDados[2] = base + 1;

        //trago da memoria o novo valor da base 
        umaInstrucao[0] = 3;
        umaInstrucao[1] = -1;
        umaInstrucao[2] = 2;
        umaInstrucao[3] = -1;

        maquinaOPERACOES(umaInstrucao, memoriaDados);
        base = umaInstrucao[1];
        
        /* Pego o resultado da multiplicaçao que foi guardado de acordo com a funçao 
        multiplicaçao na memoriaDados[1] */

        umaInstrucao[0] = 3;
        umaInstrucao[1] = -1;
        umaInstrucao[2] = 1;
        umaInstrucao[3] = -1;

        maquinaOPERACOES(umaInstrucao, memoriaDados);
        resultadomulti = umaInstrucao[1];

    }while (resultadomulti < valor);

    if (resultadomulti == valor) {
        printf ("A raiz quadrada de %d = %d\n\n", valor, auxiliar);

        umaInstrucao[0] = 2;
        umaInstrucao[1] = auxiliar;
        umaInstrucao[2] = 1;
        umaInstrucao[3] = -1;

        maquinaOPERACOES(umaInstrucao,memoriaDados);
    }
    else {
        printf ("A raiz quadrada de %d = %d\n\n", valor, auxiliar - 1);

        umaInstrucao[0] = 2;
        umaInstrucao[1] = auxiliar - 1;
        umaInstrucao[2] = 1;
        umaInstrucao[3] = -1;

        maquinaOPERACOES(umaInstrucao,memoriaDados);
    }

}

void pitagorasInstru (int **guarda_memoria, int ladoc, int ladob, int *memoriadedados){

    //a = b ^ 2 + c ^ 2 
    // a = sqrt (4 * 4 + 3 * 3) = sqrt(4 + 4 + 4 + 4 + 3 + 3 + 3)

    int instrumMemoryPit[500][4];
    
    int umaInstrucao[4];
    int i, j;

    int cont = 4; /*começa do 4 pq 4 espaços da memoria de dados ja estao reseservados para o 
                    valores para realizar as somas */

    //soma do lado b (pow (b , 2))
    umaInstrucao[0] = 2;
    umaInstrucao[1] = ladob;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = -1;
    
    for(j = 0; j < 4; j++){
        instrumMemoryPit[0][j] = umaInstrucao[j]; // memoriadedados[0] = lado b
    }

    umaInstrucao[0] = 2;
    umaInstrucao[1] = 0;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    for(j = 0; j < 4; j++){
        instrumMemoryPit[1][j] = umaInstrucao[j]; // memoriadedados[1] = 0
    }   

    //cont = 4;
    //faz a soma 2 vezes
    for(i = 4; i < ladob + 4; i++){

        umaInstrucao[0] = 0;
        umaInstrucao[1] = 0;
        umaInstrucao[2] = 1;
        umaInstrucao[3] = 1;

        cont++; // contador que sera usado para voltar a fazer as somas e guardas na memoria na ordem 
                //de instruçoes da segunda potencia a partir da instruçao que ele parou

        for (j = 0; j < 4; j++){

            instrumMemoryPit[i][j] = umaInstrucao[j];
        }
    }  


    //soma do lado c (pow (c , 2))
    umaInstrucao[0] = 2;
    umaInstrucao[1] = ladoc;
    umaInstrucao[2] = 2;
    umaInstrucao[3] = -1;
    
    for(j = 0; j < 4; j++){
        instrumMemoryPit[2][j] = umaInstrucao[j]; // memoriadedados[2] = ladoc
    }

    umaInstrucao[0] = 2;
    umaInstrucao[1] = 0;
    umaInstrucao[2] = 3;
    umaInstrucao[3] = -1;

    for(j = 0; j < 4; j++){
        instrumMemoryPit[3][j] = umaInstrucao[j]; // memoriadedados[3] = 0
    }

    int cont2 = cont;

    // faz a soma 3 vezes
    for(i = cont ; i < ladoc + cont; i++){

        umaInstrucao[0] = 0;
        umaInstrucao[1] = 2;
        umaInstrucao[2] = 3;
        umaInstrucao[3] = 3;

        cont2 ++; //conta quandos loops ocorreram nessas somas 

        for (j = 0; j < 4; j++){    

            instrumMemoryPit[i][j] = umaInstrucao[j];
        }
    }  


    int ultimainstruHALT = cont2;  /*cont2 é a quantidade de vezes que tiveram somas mais 4 pq 
                                    sao as instruçoes para LEVAR valores para memoriaDados*/

                                    //+ 1 devido a querer pegar a ultima posiçao de todas para colocar o HALT
                                    

    umaInstrucao[0] = -1;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = -1;
    umaInstrucao[3] = -1;

    for(j = 0; j < 4; j++){

        instrumMemoryPit[ultimainstruHALT][4] = umaInstrucao[j];
    }

    maquina (instrumMemoryPit, memoriadedados);



    //trago da memoria o que encontrei para soma da potencia do lado b e soma da potencia do lado c

    //trago da memoria o valor de pow lado b
    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int potencia1 = umaInstrucao[1];

    //trago da memoria o valor da pow lado c
    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 3;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int potencia2 = umaInstrucao[1];
    
    //pot1
    umaInstrucao[0] = 2;
    umaInstrucao[1] = potencia1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados); //memoriaDados[1] = potencia1
    
    //pot2
    umaInstrucao[0] = 2;
    umaInstrucao[1] = potencia2;
    umaInstrucao[2] = 3;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados); //memoriaDados[3] = potencia2


    //soma da potencia 1 + potencia 2
    umaInstrucao[0] = 0;
    umaInstrucao[1] = 1;
    umaInstrucao[2] = 3;
    umaInstrucao[3] = 4;

    maquinaOPERACOES(umaInstrucao, memoriadedados); //potencia 1 + potencia 2

    //trazendo o valor da soma de potencias para utilizar no programa de raiz quadrada
    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 4;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);

    int somasPOT = umaInstrucao[1];

    printf("\nA soma da potencia 1 com soma da potencia 2 do Teorema de Pitagores foi encontrada e é igual a: %d\n\n", somasPOT);

    printf ("Agora faremos a raiz quadrada de %d para saber o VALOR DO LADO do triangulo que queremos\n\n", somasPOT);

    //usarei do programa que criei de "raiz quadrada INSTRUÇOES" para fazer a raiz quadrada dessa soma de potencias
    raizquadradaInstru(instrumMemoryPit, somasPOT, memoriadedados);

}

void fatorialInstru(int **guarda_memoria, int numero, int *memoriadedados ) {

    int umaInstrucao[4];

    int instrumMemoryFatorial[100][4];

    int i, j;

    int novonumero = 0;

    /*Vou realizar a soma inicial com esses dois primeiros numeros que no casos serao iguais e estao 
    na memoriaDados[0] e memoriaDados[1] */
    umaInstrucao[0] = 2;
    umaInstrucao[1] = numero;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = -1;

    for(j = 0; j < 4; j ++) {

        instrumMemoryFatorial[0][j] = umaInstrucao[j]; //memoriaDados[0] = 5
    }


    umaInstrucao[0] = 2;
    umaInstrucao[1] = numero;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    for(j = 0; j < 4; j ++) {

        instrumMemoryFatorial[1][j] = umaInstrucao[j]; //memoriaDados[1] = 5
    }

    //numero auxiliar para reduzir a quantidade de loops, ou seja, a quantidade de somas 
    umaInstrucao[0] = 2;
    umaInstrucao[1] = 1;
    umaInstrucao[2] = 2;
    umaInstrucao[3] = -1;

    for(j = 0; j < 4; j ++) {

        instrumMemoryFatorial[2][j] = umaInstrucao[j]; //memoriaDados[2] = 1
    }


    /*Armazenei o valor do numero na memoria para me permitir trocar o 'numero' que esta 
        em memoriaDados[1] a cada loop para fazer somas corretas*/
    umaInstrucao[0] = 2;
    umaInstrucao[1] = numero;
    umaInstrucao[2] = 3;
    umaInstrucao[3] = -1;

    for(j = 0; j < 4; j ++) {

        instrumMemoryFatorial[3][j] = umaInstrucao[j]; //memoriaDados[3] = 5
    }

    //HALT -> -1 Faço ele para parar a maquina e iniciar realmente o fatorial
    umaInstrucao[0] = -1;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = -1;
    umaInstrucao[3] = -1;
    
    for(j = 0; j < 4; j ++) {

        instrumMemoryFatorial[4][j] = umaInstrucao[j];
    }

    maquina(instrumMemoryFatorial, memoriadedados);

    int auxiliar = numero; // criei isso para não alterar o i no loop abaixo


    //A partir daqui que começa mesmo o fatorial;
    for (i = 0; i < auxiliar - 2; i ++){
        
        j = numero - 2;
        
        while(j > 0){
            umaInstrucao[0] = 0;
            umaInstrucao[1] = 0;
            umaInstrucao[2] = 1;
            umaInstrucao[3] = 1;

            maquinaOPERACOES(umaInstrucao, memoriadedados);

            j--;
        } 

        //Substrai 1 do valor de numero para fazer menos 1 soma no proximo loop de j
        umaInstrucao[0] = 1;
        umaInstrucao[1] = 3;
        umaInstrucao[2] = 2;
        umaInstrucao[3] = 3;

        maquinaOPERACOES(umaInstrucao, memoriadedados); //numero = numero - 1;

        //coloca o novo valor para o numero para realizar a quantidade de somas corretas
        umaInstrucao[0] = 3;
        umaInstrucao[1] = -1;
        umaInstrucao[2] = 3;
        umaInstrucao[3] = -1;
        maquinaOPERACOES(umaInstrucao, memoriadedados); 
        numero = umaInstrucao[1];




        //troco o valor que esta na memoriaDados[0] pelo novo valor encontrado no primeiro loop do j
        //para isso primeiro trago o valor do novo numero
        umaInstrucao[0] = 3;
        umaInstrucao[1] = -1;
        umaInstrucao[2] = 1;
        umaInstrucao[3] = -1;
        maquinaOPERACOES(umaInstrucao, memoriadedados);
        novonumero = umaInstrucao[1];

        /*Agora levo esse novo numero para posiçao 0 da memoria de dados para assim realizar 
        novas somas no loop j */
        umaInstrucao[0] = 2;
        umaInstrucao[1] = novonumero;
        umaInstrucao[2] = 0;
        umaInstrucao[3] = -1;

        maquinaOPERACOES(umaInstrucao, memoriadedados);
    
        
    }   

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    novonumero = umaInstrucao[1];

    printf("\nO fatorial de %d = %d\n\n", auxiliar, novonumero);
}
    
void areaquadrado (int **guarda_memoria, int lado, int *memoriadedados){

    int umaInstrucao[4];
    int resultquadrado = 0;
    int memoriaInstruMulti[500][4];

    multiplicaInstru(memoriaInstruMulti, lado, lado, memoriadedados);

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);
    resultquadrado = umaInstrucao[1];
    

    printf ("A area do quadrado é igual a %d\n\n", resultquadrado);
}

void arearetangulo (int **guarda_memoria, int lado1, int lado2, int *memoriadedados){

    int umaInstrucao[4];
    int resultret = 0;
    int memoriaInstruMulti[500][4];

    multiplicaInstru(memoriaInstruMulti, lado1, lado2, memoriadedados);

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);
    resultret = umaInstrucao[1];
    

    printf ("A area do quadrado é igual a %d\n\n", resultret);
}

void areatriangulo(int **guarda_memoria, int base, int altura, int *memoriadedados) {

    int umaInstrucao[4];
    int resulttrian = 0;
    int memoriaInstruMulti[500][4];

    //chama a funçao multiplicaInstru para fazer a multiplicaçao entre a base e altura 
    multiplicaInstru(memoriaInstruMulti, base, altura, memoriadedados);

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);
    resulttrian = umaInstrucao[1]; //resultado da multiplicaçao entre base e altura 

    
    //chama a funçao divisao para fazer a divisao sobre 2 para encontrar a area do triangulo
    divideInstru(memoriaInstruMulti, resulttrian, 2, memoriadedados);

    //trazemos da memoriaDados[3] o valor da divisao
    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 3; //pegamos a posiçao 3 da memoria de dados, pois é nela que fica armazenado o valor da divisao
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);
    resulttrian = umaInstrucao[1];
    
    printf("\nA area do triangulo = %d\n", resulttrian);
}

void areacirculo(int guarda_memoria[][4], int raio, int *memoriadedados){


    int umaInstrucao[4];

    int resultAreaCirculo;

    int memoriaInstruMulti[500][4];

    multiplicaInstru(memoriaInstruMulti, raio, raio, memoriadedados);

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);
    resultAreaCirculo = umaInstrucao[1];

    multiplicaInstru(memoriaInstruMulti, resultAreaCirculo , 3, memoriadedados);

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);
    resultAreaCirculo = umaInstrucao[1];
    

    printf ("A area do circulo é igual a %d\n\n", resultAreaCirculo);
}

void comprimentocirculo(int **guarda_memoria, int raio, int *memoriadedados){

    int umaInstrucao[4];

    int resultComprimentoCirculo;

    int memoriaInstruMulti[500][4];

    multiplicaInstru(memoriaInstruMulti, raio, 2, memoriadedados);

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);
    resultComprimentoCirculo = umaInstrucao[1];

    multiplicaInstru(memoriaInstruMulti, 3, resultComprimentoCirculo, memoriadedados);

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);
    resultComprimentoCirculo = umaInstrucao[1];
    

    printf ("O comprimento do circulo é igual a %d\n\n", resultComprimentoCirculo);


}

void arealosango(int **guarda_memoria, int diagonalmaior, int diagonalmenor, int *memoriadedados) {

    int umaInstrucao[4];
    int resultlosan = 0;
    int memoriaInstruMulti[500][4];
    //chama a funçao multiplicaInstru para fazer a multiplicaçao entre as diagonais 
    multiplicaInstru(memoriaInstruMulti, diagonalmaior, diagonalmenor, memoriadedados);

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);
    resultlosan = umaInstrucao[1]; //resultado da multiplicaçao entre as diagonais 

    
    //chama a funçao divisao para fazer a divisao sobre 2 para encontrar a area do triangulo
    divideInstru(memoriaInstruMulti, resultlosan, 2, memoriadedados);

    //trazemos da memoriaDados[3] o valor da divisao
    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 3; //pegamos a posiçao 3 da memoria de dados, pois é nela que fica armazenado o valor da divisao
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);
    resultlosan = umaInstrucao[1];
    
    printf("\nA area do losango = %d\n", resultlosan);
}

void areaparalelogramo (int **guarda_memoria, int base, int altura, int *memoriadedados){

    int umaInstrucao[4];
    int resultpara = 0;
    int memoriaInstruMulti[500][4];

    multiplicaInstru(memoriaInstruMulti, base, altura, memoriadedados);

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);
    resultpara = umaInstrucao[1];
    

    printf ("A area do pararalelogramo é igual a %d\n\n", resultpara);
}

void areatrapezio(int **guarda_memoria, int basemenor, int basemaior, int altura, int *memoriadedados ){

    int umaInstrucao[4];
    int resultmulti = 0; 
    int resultrapezio = 0; //resultado da divisao
    int memoriaInstruMulti[500][4];

    umaInstrucao[0] = 2;
    umaInstrucao[1] = basemenor;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);

    umaInstrucao[0] = 2;
    umaInstrucao[1] = basemaior;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);

    umaInstrucao[0] = 0;
    umaInstrucao[1] = 0;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = 2;

    maquinaOPERACOES(umaInstrucao, memoriadedados); //base menor + base maior 

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 2;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int soma = umaInstrucao[1]; //soma = base maior + base menor




    multiplicaInstru(memoriaInstruMulti, soma, altura, memoriadedados); //soma * altura

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);

    resultmulti = umaInstrucao[1]; //resulmulti = soma * altura



    divideInstru(memoriaInstruMulti, resultmulti, 2, memoriadedados); //resulmulti / 2

    
    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 3;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);
 
    resultrapezio = umaInstrucao[1]; // resulttrapezio =  resulmulti / 2

    printf("A area do trapezio = %d\n\n", resultrapezio);
}

void baskara (int **guarda_memoria, int a, int b, int c, int *memoriadedados) {

    int umaInstrucao[4];

    int instrumMemoryBaskara[100][4];

    int multiac;

    int quadradodeb;

    int delta;

    //resolvendo o delta primeiro
    multiplicaInstru(instrumMemoryBaskara, a, c, memoriadedados); // a * c

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    multiac = umaInstrucao[1];

    multiplicaInstru(instrumMemoryBaskara, 4, multiac, memoriadedados); // ac * 4

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    multiac = umaInstrucao[1];

    expoInstru(instrumMemoryBaskara, b, 2, memoriadedados);// b * b

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    quadradodeb = umaInstrucao[1];

    //levo para memoriadedados[0] o valor de multiac
    umaInstrucao[0] = 2;
    umaInstrucao[1] = multiac;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);

    //levo para memoriadedados[1] o valor do quadrado de b
    umaInstrucao[0] = 2;
    umaInstrucao[1] = quadradodeb;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);


    //Subtraçao entre quadradodeb e multiac (memoriadados[1] - memoriadados[0])
    umaInstrucao[0] = 1;
    umaInstrucao[1] = 1;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = 1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);


    //trago da memoria o valor da subtraçao anterior
    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);
    delta = umaInstrucao[1];

    raizquadradaInstru(instrumMemoryBaskara, delta, memoriadedados); //Raiz quadrada de delta

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int raiz = umaInstrucao[1];

    //Agora vou dividir em dois resultaod: um onde a raiz de delta é positiva e outro onde a raiz de delta é negativa

    //levo para memoriadedados[0] o valor da raiz positiva
    umaInstrucao[0] = 2;
    umaInstrucao[1] = raiz;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);

    //levo para memoriadedados[1] o valor da raiz negativa
    umaInstrucao[0] = 2;
    umaInstrucao[1] = -raiz;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);

    //levo para memoriadedados[2] o valor de b
    umaInstrucao[0] = 2;
    umaInstrucao[1] = -b;
    umaInstrucao[2] = 2;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);

    //soma1 
    umaInstrucao[0] = 0;
    umaInstrucao[1] = 0;
    umaInstrucao[2] = 2;
    umaInstrucao[3] = 3;
    maquinaOPERACOES(umaInstrucao, memoriadedados);

    //trago da memoria o valor da primeira soma
    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 3;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int soma1 = umaInstrucao[1]; 

    //soma2
    umaInstrucao[0] = 0;
    umaInstrucao[1] = 1;
    umaInstrucao[2] = 2;
    umaInstrucao[3] = 4;
    maquinaOPERACOES(umaInstrucao, memoriadedados);

    //trago da memoria o valor da segunda soma
    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 4;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int soma2 = umaInstrucao[1]; 


    //faço a multiplicaçao de 2 * a 
    multiplicaInstru(instrumMemoryBaskara, a, 2, memoriadedados);

    //trago da memoria o valor da multiplicaçao entre 2 e a
    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int multia = umaInstrucao[1]; 

    //Primeira raiz 
    divideInstru(instrumMemoryBaskara, -soma1, multia, memoriadedados);

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 3;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int result1 = -umaInstrucao[1];

    printf("\n1ª raiz = %d\n\n", result1);

    //Segunda raiz 
    divideInstru(instrumMemoryBaskara, -soma2, multia, memoriadedados);

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 3;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int result2 = -umaInstrucao[1];

    printf("\n2ª raiz = %d\n", result2);
}   

void areacubo(int **guarda_memoria, int lado, int *memoriadedados){

    //Area cubo = 6 * L^3

    int umaInstrucao[4];

    int instrumMemorycubo[100][4];

    expoInstru(instrumMemorycubo, lado, 2, memoriadedados);

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int cubodolado = umaInstrucao[1];

    multiplicaInstru(instrumMemorycubo, cubodolado, 6, memoriadedados);

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int result = umaInstrucao[1];

    printf ("A area do cubo é igual a %d\n\n", result);

}

void volumecubo (int **guarda_memoria, int lado, int *memoriadedados){

    // L ^ 3
    int umaInstrucao[4];

    int instrumMemorycubo[100][4];

    expoInstru(instrumMemorycubo, lado, 3, memoriadedados);

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int result = umaInstrucao[1];

    printf ("O volume do cubo é igual a %d\n\n", result);


}

void areaParalelepipedo(int **guarda_memoria, int lado1, int lado2, int lado3, int *memoriadedados ){

    // 2 * (ab + ac + bc)
    int umaInstrucao[4];

    int instrumMemorypara[500][4];

    multiplicaInstru(instrumMemorypara, lado1, lado2, memoriadedados);

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int multiab = umaInstrucao[1];

    multiplicaInstru(instrumMemorypara, lado1, lado3, memoriadedados);

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int multiac = umaInstrucao[1];

    multiplicaInstru(instrumMemorypara, lado2, lado3, memoriadedados);
    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int multibc = umaInstrucao[1];

    //trago das memorias para fazer as somas 
    umaInstrucao[0] = 2;
    umaInstrucao[1] = multiab;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);

    umaInstrucao[0] = 2;
    umaInstrucao[1] = multiac;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);

    umaInstrucao[0] = 2;
    umaInstrucao[1] = multibc;
    umaInstrucao[2] = 2;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);

    //soma entre dois lados 
    umaInstrucao[0] = 0;
    umaInstrucao[1] = 0;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = 1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);

    //soma com o 3º lado
    umaInstrucao[0] = 0;
    umaInstrucao[1] = 1;
    umaInstrucao[2] = 2;
    umaInstrucao[3] = 2;
    maquinaOPERACOES(umaInstrucao, memoriadedados);


    //trago da memoria a soma entre todos os lados uma unica vez para multiplicar essa soma por 2
    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 2;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int somatotal = umaInstrucao[1];

    multiplicaInstru(instrumMemorypara, somatotal, 2, memoriadedados);

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int result = umaInstrucao[1];

    printf("A area do paralelepideo é igual a %d\n\n", result);

}

void volumeParalelepipedo (int **guarda_memoria, int lado1, int lado2, int lado3, int *memoriadedados ){

    // a * b * c
    int umaInstrucao[4];

    int instrumMemorypara[100][4];

    multiplicaInstru(instrumMemorypara, lado1, lado2, memoriadedados);

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int multiab = umaInstrucao[1];

    multiplicaInstru(instrumMemorypara, lado3, multiab, memoriadedados);

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int result = umaInstrucao[1];

    printf("O volume do paralelepideo é igual a %d\n\n", result);
}

void volumeCilindro (int **guarda_memoria, int raio, int altura, int *memoriadedados) {

    //PI * r^2 * h
    int umaInstrucao[4];

    int instrumMemoryCilindro[500][4];

    areacirculo(instrumMemoryCilindro, raio, memoriadedados);

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int areacirc = umaInstrucao[1];

    multiplicaInstru(instrumMemoryCilindro, altura, areacirc, memoriadedados);

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int result = umaInstrucao[1];

    printf("O volume do cilindro é igual a %d\n\n", result);
}

void areaCilindro (int **guarda_memoria, int raio, int altura, int *memoriadedados) {

    // 2 * PI * R * (r + h)
    int umaInstrucao[4];

    int instrumMemoryCilindro[100][4];

    comprimentocirculo(guarda_memoria, raio, memoriadedados);

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int compcirc = umaInstrucao[1];


    umaInstrucao[0] = 2;
    umaInstrucao[1] = raio;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);

    umaInstrucao[0] = 2;
    umaInstrucao[1] = altura;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);

    //soma da altura mais raio
    umaInstrucao[0] = 0;
    umaInstrucao[1] = 0;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = 1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);

    //trazer o valor da soma
    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int somahr = umaInstrucao[1];

    multiplicaInstru(instrumMemoryCilindro, compcirc, somahr, memoriadedados);

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int result = umaInstrucao[1];

    printf("A area do cilindro é igual a %d\n\n", result);
}

void valorabsoluto(int **guarda_memoria, int valornegativo, int *memoriadedados) {

    int umaInstrucao[4];

    umaInstrucao[0] = 2;
    umaInstrucao[1] = valornegativo;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);

    umaInstrucao[0] = 2;
    umaInstrucao[1] = -valornegativo;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);

    for(int i = 0; i < 2; i++){
        umaInstrucao[0] = 0;
        umaInstrucao[1] = 0;
        umaInstrucao[2] = 1;
        umaInstrucao[3] = 0;
        maquinaOPERACOES(umaInstrucao, memoriadedados);
    }

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);

    int result = umaInstrucao[1];

    printf("Valor absoluto de %d = %d\n\n", valornegativo, result);

}