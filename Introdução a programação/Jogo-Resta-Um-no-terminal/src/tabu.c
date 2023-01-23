#include <stdio.h>
#include <string.h>

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

void lermatriztabu(int n, int m, int matriztabu[][15], FILE *arquivo);
void imprimirTabuleiro(int n, int m, int matriztabu[][15]);

int main(int argc, char **argv)
{

    int n;
    int m;
    int matriztabu[15][15];

    char comando[10];
    int tamanho = 0;

    printf(BLUE("\nBem vindo ao Resta UM!\n" ));

    printf("\n");

    printf(BG_YELLOW("COMO JOGAR:") "\n");

    printf(YELLOW(BOLD("O objetivo do jogo é (como o proprio nome diz) deixar apenas uma peça no tabuleiro.       \n")));
    printf(YELLOW(BOLD("Sempre que você passar uma peça por cima da outra, a peça que está embaixo é retira-      \n")));
    printf(YELLOW(BOLD("da, porémmm CUIIIIDADOO!!!!: você pode ficar sem movimentos se não retirar as peças       \n")));
    printf(YELLOW(BOLD("corretas.\n")));

    printf ("\n");

    printf (RED(BOLD("X = ESPAÇO VAZIO\n")));
    printf (GREEN(BOLD("O = PEÇAS\n")));

    printf(RED(BOLD("                             -            COMANDOS            -\n")));
    printf(RED(BOLD("----------------------------------------------------------------------------------------------        \n")));
    printf(RED(TAB_VER) GREEN(BOLD("Comando    ")) RED(TAB_VER) CYAN(BOLD("Argumento     ")) RED(TAB_VER) MAGENTA(BOLD("O que ele faz?                                                   " RED(TAB_VER) "\n")));
    printf(RED(BOLD("----------------------------------------------------------------------------------------------        \n")));
    printf(RED(TAB_VER) GREEN("c          ") RED(TAB_VER) CYAN("CD            ") RED(TAB_VER) MAGENTA("Move um pino na célula da linha C e coluna D para cima           " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("b          ") RED(TAB_VER) CYAN("CD            ") RED(TAB_VER) MAGENTA("Move um pino na célula da linha C e coluna D para baixo          " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("e          ") RED(TAB_VER) CYAN("CD            ") RED(TAB_VER) MAGENTA("Move um pino na célula da linha C e coluna D para a esquerda     " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("d          ") RED(TAB_VER) CYAN("CD            ") RED(TAB_VER) MAGENTA("Move um pino na célula da linha C e coluna D para a direita      " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("ajuda      ") RED(TAB_VER) CYAN("n             ") RED(TAB_VER) MAGENTA("Seu programa deve sugerir e executar n movimentos para o jogador." RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("salvar     ") RED(TAB_VER) CYAN("out           ") RED(TAB_VER) MAGENTA("Salva o jogo tal como está no momento no arquivo “out.txt”.      " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("sair       ") RED(TAB_VER) CYAN("-             ") RED(TAB_VER) MAGENTA("Encerra o programa (sem salvar as últimas alteracoes).           " RED(TAB_VER) "\n"));

    printf(RED(TAB_BL) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_BR) "\n");

    //implementa e abre o arquivo
    FILE *arquivo = fopen(argv[1], "r");

    //lê o m e o n do arquivo texto criado pelo usuario
    fscanf(arquivo, "%d %d", &n, &m);

    //inicia a funçao lermatriztabu
    lermatriztabu(n, m, matriztabu, arquivo);

    //Fecha o arquivo
    fclose(arquivo);

    imprimirTabuleiro(n, m, matriztabu);

    printf("\nComando: ");
    fgets(comando, 10, stdin);

    tamanho = strlen(comando);

    comando[tamanho - 1] = '\0';

    return 0;
}

void lermatriztabu(int n, int m, int matriztabu[][15], FILE *arquivo)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            fscanf(arquivo, "%d", &matriztabu[i][j]);
        }
    }
}

void imprimirTabuleiro(int n, int m, int matriztabu[][15])
{
    printf("  ");
    for (int i = 0; i < m; i++)
    {
        printf(CYAN(BOLD("%1c ")), i + 65);
    }

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf(CYAN(BOLD("%1c ")), i + 65);
        for (int j = 0; j < m; j++)
        {

            if (matriztabu[i][j] == -1)
            {
                printf("  ");
            }
            else if (matriztabu[i][j] == 0)
            {
                printf(RED(BOLD("X ")));
            }
            else if (matriztabu[i][j] == 1)
            {
                printf(GREEN(BOLD("O ")));
            }
        }
        printf("\n");
    }
}
