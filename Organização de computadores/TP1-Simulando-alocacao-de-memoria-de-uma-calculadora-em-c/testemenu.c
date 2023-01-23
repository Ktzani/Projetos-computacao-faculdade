#include <stdio.h>

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

   
int main () {

    int comando ;
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

    printf(RED(TAB_BL) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_BR) "\n");

    printf("\nDigite o comando que vc deseja: ");
    scanf("%d", &comando);
}