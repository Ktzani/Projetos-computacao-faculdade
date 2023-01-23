#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
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

int main()
{

    int n = 1000;
    int m = 4;

    //alocando a memoria de instruçoes
    int **memoriaInstrucoes = NULL;

    //alocando uma memoria ram

    int tamanho_memoria = 1000;

    int *memoriaDados = NULL;

    int comando;

    int memoriaInstruMulti[500][4];

    /*int opcode; */

    srand(time(NULL));

    memoriaInstrucoes = alocaMemoriaInstrucoes(memoriaInstrucoes, n, m);

    memoriaDados = alocaMemoriaRam(tamanho_memoria, memoriaDados);

    montarRAM(tamanho_memoria, memoriaDados);

    do
    {
        printf ("\n");
        menu();
        printf("\nDigite o comando que vc deseja: ");
        scanf("%d", &comando);

        switch (comando)
        {
        case -1: {

            exit(1);
            break;
        }

        case 0:
        {

            menu();
            break;
        }

        case 1:
        {

            InstruAle(memoriaInstrucoes, memoriaDados);
            break;
        }

        case 2:
        {

            //valores para multiplicaçao
            int conteudoMultiplicando;

            int conteudoMultiplicador;

            int indiceAleatorioMultiplicando = rand() % 1000;

            int indiceAleatorioMultiplicador = rand() % 1000;

            conteudoMultiplicador = memoriaDados[indiceAleatorioMultiplicador];

            conteudoMultiplicando = memoriaDados[indiceAleatorioMultiplicando];

            if (conteudoMultiplicador == 0 || conteudoMultiplicando == 0){

                printf ("\nQualquer numero multiplicado por 0 é igual a 0\n");

                break;
            }

            else {
                printf ("\nMultiplicação entre %d e %d:\n", conteudoMultiplicando, conteudoMultiplicador);
            
                multiplicaInstru(memoriaInstruMulti, conteudoMultiplicando, conteudoMultiplicador, memoriaDados);
            }
            break;
        }

        case 3:
        {

            //valores para divisao

            int conteudoDividendo;

            int conteudoDivisor;

            do
            {

                int indiceAleatorioDividendo = rand() % 1000;

                int indiceAleatorioDivisor = rand() % 1000;

                conteudoDividendo = memoriaDados[indiceAleatorioDividendo];

                conteudoDivisor = memoriaDados[indiceAleatorioDivisor];

            } while (conteudoDividendo < conteudoDivisor); //enquanto o dividendo for menor que o divisor, a divisao não é iniciada

            if (conteudoDivisor == 0){
                
                printf ("Nao existe divisao por zero\n\n");
                break;
            }

            else {
                printf ("Divisao entre %d e %d: (%d/%d)", conteudoDividendo, conteudoDivisor, conteudoDividendo, conteudoDivisor);
                divideInstru(memoriaInstruMulti, conteudoDividendo, conteudoDivisor, memoriaDados);
            }

            break;
        }
        case 4: {

            //Exponenciaçao

            int indiceAleatorioBase = rand() % 1000;

            int indiceAleatorioExpoente = rand() % 1000;

            int base = memoriaDados [indiceAleatorioBase];

            int expoente = memoriaDados [indiceAleatorioExpoente];
            
            if (expoente == 0) {
                printf ("\nExponenciação com base %d e expoente 0:\n", base);
                printf ("Resultado da exponenciação = 1\n\n");

            }

            else {
                printf ("\nExponenciação com base %d e expoente %d:\n", base, expoente);
                expoInstru (memoriaInstruMulti, base, expoente, memoriaDados);
            }

            break;
        }

        case 5:
        {

            //Pitagoras
            
            //int ladomaior; -> o lado maior tem que dar igual a 5 com os valores que estou testando

            int ladob = 3;

            int ladoc = 4;

            printf("\nUm triangulo de lado b = %d e lado c = %d\n", ladob, ladoc);

            pitagorasInstru (memoriaInstrucoes, ladob, ladoc, memoriaDados);

            break;
        }

        case 6: 
        {
            //Raiz quadrada

            int valor;

            int indiceAleatorioValor = rand () % 1000;

            valor = memoriaDados[indiceAleatorioValor]; //temos que encontrar a raiz quadrada desse valor
            
            if(valor == 0){

                printf ("\nNao existe raiz quadrada de 0\n");
                break;
            }
            else {
                printf ("\nRaiz quadrada de %d: \n", valor);
            
                raizquadradaInstru(memoriaInstruMulti, valor, memoriaDados);
            }

            break;
        }

        case 7:{

            //Fatorial

            int numero = rand () % 10 + 2;

            printf ("\nFatorial de %d:\n", numero);

            fatorialInstru(memoriaInstrucoes, numero, memoriaDados);

            break;
        }

        case 8: {

            //Area quadrado

            int lado;

            printf ("\nDigite um valor para o lado do quadrado:\n");
            scanf ("%d", &lado);

            areaquadrado(memoriaInstrucoes, lado, memoriaDados);

            break;
        }

        case 9: {

            //Area retangulo

            int lado1, lado2;

            printf ("\nDigite um valor para o lado maior do retangulo: ");
            scanf ("%d", &lado1);

            printf ("\nDigite um valor para o lado menor do retangulo:");
            scanf ("%d", &lado2);

            arearetangulo (memoriaInstrucoes, lado1, lado2, memoriaDados);

            break;
        }

        case 10: {

            //Area triangulo 

            int base, altura;

            printf ("\nDigite um valor para o base do triangulo: ");
            scanf ("%d", &base);

            printf ("\nDigite um valor para o altura do triangulo:");
            scanf ("%d", &altura);

            areatriangulo(memoriaInstrucoes, base, altura, memoriaDados);

            break;
        }

        case 11: {

            //Area circulo

            int raio;

            printf ("\nDigite um valor para o raio do circulo: ");
            scanf ("%d", &raio);

            areacirculo(memoriaInstruMulti, raio, memoriaDados);

            break;
        }

        case 12: {

            //Area losango

            int diagonalmenor, diagonalmaior;

            printf ("\nDigite um valor para o diagonal menor: ");
            scanf ("%d", &diagonalmenor);

            printf ("\nDigite um valor para o diagonal maior: ");
            scanf ("%d", &diagonalmaior);
            
            arealosango(memoriaInstrucoes, diagonalmenor, diagonalmaior, memoriaDados);

            break;
        }

        case 13: {

            //Area pararelogramo 

            int base, altura;

            printf ("\nDigite um valor para o base do pararelogramo: ");
            scanf ("%d", &base);

            printf ("\nDigite um valor para a altura do pararelogramo: ");
            scanf ("%d", &altura);

            areaparalelogramo (memoriaInstrucoes, base, altura, memoriaDados);

            break;
        }

        case 14: {

            //Area trapezio

            int basemenor, basemaior, altura;

            printf ("\nDigite um valor para o base menor do trapezio: ");
            scanf ("%d", &basemenor);

            printf ("\nDigite um valor para a base maior do trapezio: ");
            scanf ("%d", &basemaior);

            printf ("\nDigite um valor para o altura do trapezio: ");
            scanf ("%d", &altura);

            areatrapezio(memoriaInstrucoes, basemenor, basemaior, altura, memoriaDados);

            break;
        }

        case 15: {
            
            //Comprimento Circulo

            int raio;

            printf ("\nDigite um valor para o raio do circulo: ");
            scanf ("%d", &raio);

            comprimentocirculo(memoriaInstrucoes, raio, memoriaDados);

            break;
        }

        case 16: {

            //Baskara apenas com os valores 1, 5 e 6

            int a, b, c;

            a = 1;

            b = 5;

            c = 6;

            printf ("\nConsidera uma função quadratica ax² + bx + c, onde a = 1, b = 5 e c = 6\n\n");

            printf ("A raizes dessa função sao: \n\n");

            baskara(memoriaInstrucoes, a, b ,c, memoriaDados);

            break;
        }

        case 17: {

            //area de um cubo 

            int lado;

            printf ("\nDigite um valor para o lado do cubo:\n");
            scanf ("%d", &lado);

            areacubo(memoriaInstrucoes, lado, memoriaDados);

            break;


        }
        case 18: {

            //volume de um cubo 

            int lado;

            printf ("\nDigite um valor para o lado do cubo:\n");
            scanf ("%d", &lado);

            volumecubo(memoriaInstrucoes, lado, memoriaDados);

            break;

        }

        case 19: {

            //area de um paralelepipedo 

            int lado1, lado2, lado3;

            printf ("\nDigite um valor para o lado a do paralelepipedo: ");
            scanf ("%d", &lado1);

            printf ("\nDigite um valor para o lado b do paralelepipedo:");
            scanf ("%d", &lado2);

            printf ("\nDigite um valor para o lado c do paralelepipedo:");
            scanf ("%d", &lado3);

            areaParalelepipedo (memoriaInstrucoes, lado1, lado2, lado3, memoriaDados);

            break;

        }
        case 20: {

            //volume de um paralelepipedo 

            int lado1, lado2, lado3;

            printf ("\nDigite um valor para o lado a do paralelepipedo: ");
            scanf ("%d", &lado1);

            printf ("\nDigite um valor para o lado b do paralelepipedo: ");
            scanf ("%d", &lado2);

            printf ("\nDigite um valor para o lado c do paralelepipedo: ");
            scanf ("%d", &lado3);

            volumeParalelepipedo (memoriaInstrucoes, lado1, lado2, lado3, memoriaDados);

            break;

        }

        case 21: {

            //area de um cilindro 

            int raio, altura;

            printf ("\nDigite um valor para o raio do cilindro: ");
            scanf ("%d", &raio);

            printf ("\nDigite um valor para a altura do cilindro:");
            scanf ("%d", &altura);

            areaCilindro (memoriaInstrucoes, raio, altura, memoriaDados);

            break;

        }
        case 22: {

            //volume de um cilindro 

            int raio, altura;

            printf ("\nDigite um valor para o raio do cilindro: ");
            scanf ("%d", &raio);

            printf ("\nDigite um valor para a altura do cilindro: ");
            scanf ("%d", &altura);

            volumeCilindro (memoriaInstrucoes, raio, altura, memoriaDados);

            break;

        }

        case 23: {
            
            //valor absoluto

            int valornegativo;

            do {
                printf ("\nDigite um valor negativo: ");
                scanf ("%d", &valornegativo);   
            } while(valornegativo >= 0);
            valorabsoluto(memoriaInstrucoes, valornegativo, memoriaDados);

        }
        }
    } while (comando != -1); //Assim que o usario digita o comando -1, sai da tela



    memoriaInstrucoes = desalocaMemoriaInstru(memoriaInstrucoes, n);

    memoriaDados = desalocaMemoriaRAM(memoriaDados);
    return 0;
}