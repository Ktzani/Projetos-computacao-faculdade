//Gabriel Catizani Faria Oliveira - 20.1.4004
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
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

void menu();

void listadecomandos();

void lerMatriz(int n, int m, int **matrizTabu, FILE *arquivo);
void imprimirTabuleiro(int n, int m, int **matrizTabu);
void coordenadas(int n, int m, int **matrizTabu, char cordcoluna, char cordlinha, int *auxcoluna, int *auxlinhas);

void movimentocima(int n, int m, int **matrizTabu, int auxcoluna, int auxlinhas);
void movimentobaixo(int n, int m, int **matrizTabu, int auxcoluna, int auxlinhas);
void movimentoesquerda(int n, int m, int **matrizTabu, int auxcoluna, int auxlinhas);
void movimentodireita(int n, int m, int **matrizTabu, int auxcoluna, int auxlinhas);
void salvandoJogo(int n, int m, int **matrizTabu, FILE *salva);
void ajuda(int n, int m, int **matrizTabu, int najudas, int argc);

int vitoria(int n, int m, int **matrizTabu);
int derrota(int n, int m, int **matrizTabu);

void lermatrizaleatoria(int n, int m, int **matrizTabu, FILE *arquivoAle);
void copiarMatAlea(int n, int m, int **matrizTabu, FILE *arquivoAle);

int main(int argc, char **argv)
{
    int n;
    int m;
    int **matrizTabu;

    char comando[10];
    char argumentos[10];
    int tamanho = 0;

    char salvaArquivo[30];

    int vit;
    int der;

    int lista;

    int najudas;

    srand(time(NULL));

    menu();

    if (argc >= 2)
    {

        //implementa e abre o arquivo
        FILE *arquivo = fopen(argv[1], "r");

        //lê o m e o n do arquivo texto criado pelo usuario
        fscanf(arquivo, "%d %d", &n, &m);

        matrizTabu = malloc(n * sizeof(int *));

        for (int i = 0; i < n; i++)
        {

            matrizTabu[i] = malloc(m * (sizeof(int)));
        }

        //inicia a funçao lermatriz
        lerMatriz(n, m, matrizTabu, arquivo);

        //Fecha o arquivo
        fclose(arquivo);
    }

    //Coloca valores aleatorios para n e m caso o usario queira jogar um jogo aleatorio
    else 
    {

        n = rand() % 10 + 5;
        m = rand() % 10 + 5;

        matrizTabu = malloc(n * sizeof(int *));

        for (int i = 0; i < n; i++)
        {

            matrizTabu[i] = malloc(m * (sizeof(int)));
        }

        FILE *arquivoAle = fopen("tabuAle.txt", "w");

        lermatrizaleatoria(n, m, matrizTabu, arquivoAle);

        copiarMatAlea(n, m, matrizTabu, arquivoAle);

        fclose(arquivoAle); 
    }

    /*usei o 'do' para sempre que o usuario digitar o comando imprima a tabela novamente, porém
    modificicada*/
    do
    {
        int auxcoluna = 0;
        int auxlinhas = 0;

        printf("\n");
        imprimirTabuleiro(n, m, matrizTabu);

        //imprime o novo tabuleiro toda vez que volta aqui (PODENDO ELE SER imprimirTabuALEA OU NÃO POR MEIO DO USO DOS IFS)

        printf(GREEN(BOLD("\nDigite um comando jogador: ")));
        scanf("%s", comando);
        getchar();

        /*A partir daqui pega o comando digitado pelo usario e aplica sua funçao 
        que foi colocada em cada if ou realiza os comandos dentro do if */

        vit = vitoria(n, m, matrizTabu);

        der = derrota(n, m, matrizTabu);

        //AQUI DENTRO DESSAS CONDIÇÕES DETERMINARA SE O JOGADOR FOI OU NÃO CAMPEAO
        if (vit == 1)
        {
            printf(GREEN(BOLD("\nPARABENSS!! Você ganhouu!!! Você é um campeao =)/a /a\n")));
            printf(GREEN(BOLD("\nAHHH meu heroii!! :)\n")));
            break;
        }

        if (der == 1)
        {
            printf(RED(BOLD("\nVISHHH !! YOUU LOSEE =( !!\n")));
            printf(RED(BOLD("\nUHHHHHHH ")) BG_RED("(vaias)") "\n");
            printf(RED(BOLD("\nTente novamente e seja um campeao(ou nao rsrs)!!\n")));

            printf("\n");
            break;
        }

        /*A partir daqui pega o comando digitado pelo usario e aplica sua funçao 
        que foi colocada em cada if ou realiza os comandos dentro do if */
        if (strcmp(comando, "c") == 0)
        {
            scanf("%s", argumentos);
            getchar();

            coordenadas(n, m, matrizTabu, toupper(argumentos[0]), toupper(argumentos[1]), &auxcoluna, &auxlinhas);
            movimentocima(n, m, matrizTabu, auxcoluna, auxlinhas);
        }
        else if (strcmp(comando, "b") == 0)
        {
            scanf("%s", argumentos); 
            getchar();

            coordenadas(n, m, matrizTabu, toupper(argumentos[0]), toupper(argumentos[1]), &auxcoluna, &auxlinhas);
            movimentobaixo(n, m, matrizTabu, auxcoluna, auxlinhas);
        }
        else if (strcmp(comando, "d") == 0)
        {
            scanf("%s", argumentos);
            getchar();

            coordenadas(n, m, matrizTabu, toupper(argumentos[0]), toupper(argumentos[1]), &auxcoluna, &auxlinhas);
            movimentodireita(n, m, matrizTabu, auxcoluna, auxlinhas);
        }
        else if (strcmp(comando, "e") == 0)
        {
            scanf("%s", argumentos);
            getchar();

            coordenadas(n, m, matrizTabu, toupper(argumentos[0]), toupper(argumentos[1]), &auxcoluna, &auxlinhas);
            movimentoesquerda(n, m, matrizTabu, auxcoluna, auxlinhas);
        }
        else if (strcmp(comando, "ajuda") == 0)
        {
            printf(BLUE("\nQuantas 'n' ajudas você necessita?: "));
            scanf("%d", &najudas);
            getchar();
            ajuda(n, m, matrizTabu, najudas, argc);
        }
        else if (strcmp(comando, "salvar") == 0)
        {

            printf(BLUE("\nDigite o nome pra o arquivo onde você vai salvar seu jogo: "));
            fgets(salvaArquivo, 40, stdin);

            tamanho = strlen(salvaArquivo);

            salvaArquivo[tamanho - 1] = '\0';

            FILE *salva = fopen(salvaArquivo, "w");

            salvandoJogo(n, m, matrizTabu, salva);

            printf("\n" BG_GREEN("JOGO SALVO COM SUCESSO!!") "\n");

            fclose(salva);
        }
        else if (strcmp(comando, "sair") == 0)
        {

            printf(BLUE("\nATE MAISS !! Volte sempree !!\n\n"));
            break;
        }

        /*Esse ultimo 'else' faz a primeira validaçao do comando do usuario, ja que a segunda
        validação é feita dentro de cada "funçao movimento" */

        else
        {

            printf(RED(BOLD("\nComando invalido... digite um comando que exista, por favor, jogador!!!\n")));
            printf(YELLOW(BOLD("\nSe quiser ver a lista de comandos novamente, digite 1, e 2 para continuar o jogo: ")));
            scanf("%d", &lista);
            getchar();

            if (lista == 1)
            {

                listadecomandos();
            }
        }
    } while (strcmp(comando, "sair") != 0);

    for (int i = 0; i < n; i++)
    {
        free(matrizTabu[i]);
    }

    free(matrizTabu);

    return 0;
}

void menu()
{

    printf("\n" BG_WHITE(BLUE("Bem vindo ao Resta UM!")) "\n");

    printf(BG_YELLOW("COMO JOGAR:") "\n");

    printf(YELLOW(BOLD("O objetivo do jogo é (como o proprio nome diz) deixar apenas uma peça no tabuleiro.       \n")));
    printf(YELLOW(BOLD("Sempre que você passar uma peça por cima da outra, a peça que está embaixo é retira-      \n")));
    printf(YELLOW(BOLD("da, porémmm CUIIIIDADOO!!!!: você pode ficar sem movimentos se não retirar as peças       \n")));
    printf(YELLOW(BOLD("corretas.\n")));

    printf("\n");

    printf(RED(BOLD("X = ESPAÇO VAZIO\n")));
    printf(GREEN(BOLD("O = PEÇAS\n")));

    printf(RED(BOLD("                                         -            COMANDOS            -\n")));
    printf(RED(BOLD("---------------------------------------------------------------------------------------------------------------------      \n")));
    printf(RED(TAB_VER) GREEN(BOLD("Comando          ")) RED(TAB_VER) CYAN(BOLD("Coordenadas(LINHA/COLUNA)      ")) RED(TAB_VER) MAGENTA(BOLD("O que ele faz?                                                   " RED(TAB_VER) "\n")));
    printf(RED(BOLD("---------------------------------------------------------------------------------------------------------------------     \n")));
    printf(RED(TAB_VER) GREEN("c                ") RED(TAB_VER) CYAN("CD                             ") RED(TAB_VER) MAGENTA("Move um pino na célula da linha C e coluna D para cima           " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("b                ") RED(TAB_VER) CYAN("CD                             ") RED(TAB_VER) MAGENTA("Move um pino na célula da linha C e coluna D para baixo          " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("e                ") RED(TAB_VER) CYAN("CD                             ") RED(TAB_VER) MAGENTA("Move um pino na célula da linha C e coluna D para a esquerda     " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("d                ") RED(TAB_VER) CYAN("CD                             ") RED(TAB_VER) MAGENTA("Move um pino na célula da linha C e coluna D para a direita      " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("ajuda            ") RED(TAB_VER) CYAN("n                              ") RED(TAB_VER) MAGENTA("Seu programa deve sugerir e executar n movimentos para o jogador." RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("salvar           ") RED(TAB_VER) CYAN("out                            ") RED(TAB_VER) MAGENTA("Salva o jogo tal como está no momento no arquivo “out.txt”.      " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("sair             ") RED(TAB_VER) CYAN("-                              ") RED(TAB_VER) MAGENTA("Encerra o programa (sem salvar as últimas alteracoes).           " RED(TAB_VER) "\n"));

    printf(RED(TAB_BL) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_BR) "\n");
}

//FUNÇAO PARA CASO O JOGADOR PEÇA OS COMANDOS NOVAMENTE

void listadecomandos()
{
    printf(RED(BOLD("X = ESPAÇO VAZIO\n")));
    printf(GREEN(BOLD("O = PEÇAS\n")));

    printf(RED(BOLD("                                         -            COMANDOS            -\n")));
    printf(RED(BOLD("---------------------------------------------------------------------------------------------------------------------      \n")));
    printf(RED(TAB_VER) GREEN(BOLD("Comando          ")) RED(TAB_VER) CYAN(BOLD("Coordenadas(LINHA/COLUNA)      ")) RED(TAB_VER) MAGENTA(BOLD("O que ele faz?                                                   " RED(TAB_VER) "\n")));
    printf(RED(BOLD("---------------------------------------------------------------------------------------------------------------------     \n")));
    printf(RED(TAB_VER) GREEN("c                ") RED(TAB_VER) CYAN("CD                             ") RED(TAB_VER) MAGENTA("Move um pino na célula da linha C e coluna D para cima           " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("b                ") RED(TAB_VER) CYAN("CD                             ") RED(TAB_VER) MAGENTA("Move um pino na célula da linha C e coluna D para baixo          " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("e                ") RED(TAB_VER) CYAN("CD                             ") RED(TAB_VER) MAGENTA("Move um pino na célula da linha C e coluna D para a esquerda     " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("d                ") RED(TAB_VER) CYAN("CD                             ") RED(TAB_VER) MAGENTA("Move um pino na célula da linha C e coluna D para a direita      " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("ajuda            ") RED(TAB_VER) CYAN("n                              ") RED(TAB_VER) MAGENTA("Seu programa deve sugerir e executar n movimentos para o jogador." RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("salvar           ") RED(TAB_VER) CYAN("out                            ") RED(TAB_VER) MAGENTA("Salva o jogo tal como está no momento no arquivo “out.txt”.      " RED(TAB_VER) "\n"));
    printf(RED(TAB_VER) GREEN("sair             ") RED(TAB_VER) CYAN("-                              ") RED(TAB_VER) MAGENTA("Encerra o programa (sem salvar as últimas alteracoes).           " RED(TAB_VER) "\n"));

    printf(RED(TAB_BL) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_HOR) RED(TAB_BR) "\n");
}

//lê os valores que estao no arquivo e preenche a matrizTabu
void lerMatriz(int n, int m, int **matrizTabu, FILE *arquivo)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            fscanf(arquivo, "%d", &matrizTabu[i][j]);
        }
    }
}

/*colocar as coordenas como colunas e linhas da matriz, ou seja, por meio da tabela ASCII, 
passa as cordenas de letras para numeros para facilitar o uso delas na hora de executar o comando
de movimento */

void coordenadas(int n, int m, int **matrizTabu, char cordlinha, char cordcoluna, int *auxcoluna, int *auxlinhas)
{

    *auxcoluna = cordcoluna - 65; // Vai colocar as letra que representa a coluna como um numero

    *auxlinhas = cordlinha - 65; // Vai colocar as letra que representa a coluna como um numero
}

//Imprime o tabuleiro com sua formataçao colocada e com as cordenadas alfabeticas
void imprimirTabuleiro(int n, int m, int **matrizTabu)
{

    printf("  ");
    for (int j = 0; j < m; j++)
    {
        printf(CYAN(BOLD("%1c ")), j + 65);
    }

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf(CYAN(BOLD("%1c ")), i + 65);
        for (int j = 0; j < m; j++)
        {

            if (matrizTabu[i][j] == -1)
            {
                printf("  ");
            }
            else if (matrizTabu[i][j] == 0)
            {
                printf(RED(BOLD("X ")));
            }
            else if (matrizTabu[i][j] == 1)
            {
                printf(GREEN(BOLD("O ")));
            }
        }
        printf("\n");
    }
}

//FUNÇAO para imprimir o tabuleiro não imprimirTabuALEA

void movimentocima(int n, int m, int **matrizTabu, int auxcoluna, int auxlinhas)
{

    /*o movimento pra cima sempre tem que ter uma casa vazia duas linhas acima do pino o qual 
    vc quer movimentar. Assim, um pino ira para cima e passara por cima de outro pino que sera 
    retirado do tabuleiro
    */
    int i = auxlinhas;
    int j = auxcoluna;

    if ((i != 0) && (i != 1)) //verifica se o movimento é valido
    {
        if ((matrizTabu[i][j] == 1) && (matrizTabu[i - 1][j] == 1) && (matrizTabu[i - 2][j] == 0))
        {

            matrizTabu[i][j] = 0;
            matrizTabu[i - 1][j] = 0;
            matrizTabu[i - 2][j] = 1;
        }
        else
        {

            printf(RED("\nCoordenada invalida: NÃO HÁ ESPAÇOS PARA O PINO MOVIMENTAR OU NÃO HÁ PINO AQUI\n"));
            printf(RED("\nTENTE NOVAMENTE...\n"));
        }
    }
    else
    {
        printf(RED("\nComando invalido: NÃO HÁ ESPAÇOS PARA O PINO MOVIMENTAR\n"));
        printf(RED("\nTENTE NOVAMENTE...\n"));
    }
}

void movimentobaixo(int n, int m, int **matrizTabu, int auxcoluna, int auxlinhas)
{

    /*o movimento pra baixo sempre tem que ter uma casa vazia duas linhas abaixo do pino o qual 
    vc quer movimentar. Assim, um pino ira para baixo e passara por cima de outro pino que sera 
    retirado do tabuleiro.
    */
    int i = auxlinhas;
    int j = auxcoluna;
    if ((i != n - 1) && (i != n - 2)) //verifica se o movimento é valido
    {
        if ((matrizTabu[i][j] == 1) && (matrizTabu[i + 1][j] == 1) && (matrizTabu[i + 2][j] == 0))
        {

            matrizTabu[i][j] = 0;
            matrizTabu[i + 1][j] = 0;
            matrizTabu[i + 2][j] = 1;
        }
        else
        {

            printf(RED("\nCoordenada invalida: NÃO HÁ ESPAÇOS PARA O PINO MOVIMENTAR OU NÃO HÁ PINO AQUI\n"));
            printf(RED("\nTENTE NOVAMENTE...\n"));
        }
    }
    else
    {
        printf(RED("\nComando invalido: NÃO HÁ ESPAÇOS PARA O PINO MOVIMENTAR\n"));
        printf(RED("\nTENTE NOVAMENTE...\n"));
    }
}

void movimentodireita(int n, int m, int **matrizTabu, int auxcoluna, int auxlinhas)
{

    /*o movimento pra direita  sempre tem que ter uma casa vazia duas colunas pra direita do pino o qual 
    vc quer movimentar. Assim, um pino ira para direita e passara por cima de outro pino que sera 
    retirado do tabuleiro.
    */
    int i = auxlinhas;
    int j = auxcoluna;

    if ((j != m - 1) && (j != m - 2)) //verifica se o movimento é valido
    {
        if ((matrizTabu[i][j] == 1) && (matrizTabu[i][j + 1] == 1) && (matrizTabu[i][j + 2] == 0))
        {

            matrizTabu[i][j] = 0;
            matrizTabu[i][j + 1] = 0;
            matrizTabu[i][j + 2] = 1;
        }
        else
        {

            printf(RED("\nCoordenada invalida: NÃO HÁ ESPAÇOS PARA O PINO MOVIMENTAR OU NÃO HÁ PINO AQUI\n"));
            printf(RED("\nTENTE NOVAMENTE...\n"));
        }
    }
    else
    {
        printf(RED("\nComando invalido: NÃO HÁ ESPAÇOS PARA O PINO MOVIMENTAR\n"));
        printf(RED("\nTENTE NOVAMENTE...\n"));
    }
}

void movimentoesquerda(int n, int m, int **matrizTabu, int auxcoluna, int auxlinhas)
{

    /*o movimento pra esquerda sempre tem que ter uma casa vazia duas colunas pra esuqerda do pino o qual 
    vc quer movimentar. Assim, um pino ira para esquerda e passara por cima de outro pino que sera 
    retirado do tabuleiro.
    */
    int i = auxlinhas;
    int j = auxcoluna;

    if ((j != 0) && (j != 1)) //verifica se o movimento é valido
    {
        if ((matrizTabu[i][j] == 1) && (matrizTabu[i][j - 1] == 1) && (matrizTabu[i][j - 2] == 0))
        {

            matrizTabu[i][j] = 0;
            matrizTabu[i][j - 1] = 0;
            matrizTabu[i][j - 2] = 1;
        }
        else
        {

            printf(RED("\nCoordenada invalida: NÃO HÁ ESPAÇOS PARA O PINO MOVIMENTAR OU NÃO HÁ PINO AQUI\n"));
            printf(RED("\nTENTE NOVAMENTE...\n"));
        }
    }
    else
    {
        printf(RED("\nComando invalido: NÃO HÁ ESPAÇOS PARA O PINO MOVIMENTAR\n"));
        printf(RED("\nTENTE NOVAMENTE...\n"));
    }
}

//Salva o jogo num arquivo criado pelo usuario
void salvandoJogo(int n, int m, int **matrizTabu, FILE *salva)
{
    fprintf(salva, "%d %d\n", n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            fprintf(salva, "%2d", matrizTabu[i][j]);
        }
        fprintf(salva, "\n");
    }
}

/*funçao utilizada para imprimir um tabuleiro aleatorio, seja ele com uma posiçao do espçao vazio inicial
diferente ou o tabuleiro em si diferente*/

void lermatrizaleatoria(int n, int m, int **matrizTabu, FILE *arquivoAle)
{
    int formato;
    int contador = 0;
    int diferentenum = 0;

    srand(time NULL);

    formato = 1 + rand() % 2;

    if (formato == 1)
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                matrizTabu[i][j] = 1;
                if (matrizTabu[i][j] == 1)
                {
                    contador++;
                }
            }
        }

        diferentenum = 1 + rand() % (contador - 1);

        contador = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrizTabu[i][j] == 1)
                {
                    contador++;
                    if (diferentenum == contador)
                    {
                        matrizTabu[i][j] = 0;
                    }
                }
            }
        }
    }

    if (formato == 2)
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (((i != j && i != (n + 1 / 2)) && j == (m + 1 / 2)) || ((i > j || i == (n + 1 / 2)) || j == (m + 1 / 2)))
                {
                    matrizTabu[i][j] = 1;
                    if (matrizTabu[i][j] == 1)
                    {
                        contador++;
                    }
                }
                else
                {
                    matrizTabu[i][j] = -1;
                }
            }
        }

        diferentenum = 1 + rand() % (contador - 1);

        contador = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrizTabu[i][j] == 1)
                {
                    contador++;
                    if (diferentenum == contador)
                    {
                        matrizTabu[i][j] = 0;
                    }
                }
            }
        }
    }
}
/*Para funçao 'vitoriaderrota' tive uma grande dificuldade pra resolve-la, porem com a funçao 'ajuda'
criada consegui resolve-la. Primeiro, o contador de quantos pinos sobraram e se sobrar um o jogador vence
Porém, se com o contador de sugestoes da funçao 'ajuda' tiver 0 sugestoes, quer dizer que o jogador perdeu
e o jogo acaba, porem não sei se o raciocinio está correto*/

int vitoria(int n, int m, int **matrizTabu)
{

    int contpinos = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrizTabu[i][j] == 1)
                contpinos++;
        }
    }

    if (contpinos == 1)
    {

        return 1; 
    }
    else
        return 0;
}

/*Passei uma grandee dificuldade nessa questao, pois não sabia para onde ir e o que fazer, 
apesar de ja ter ideias de fazer os movimentos de novo dentro da funçao "ajudar". Entao, com 
a ajuda do meu colega Robson Novato, aluno da UFOP ele me deu dicas de como realiza-la, fazendo 
um contador para a quantidade de ajudas possiveis e quando chegar na quantidade de ajudas que o 
usuario pediu o 'for' para de rodar. Em cada ajuda, ela fala os movimentos possiveis de se realizar*/

void ajuda(int n, int m, int **matrizTabu, int najudas, int argc)
{

    int contajudas = 0;

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i != 0) && (i != 1)) //verifica se o movimento é valido
            {
                if ((matrizTabu[i][j] == 1) && (matrizTabu[i - 1][j] == 1) && (matrizTabu[i - 2][j] == 0))
                {
                    printf(YELLOW("Movimento sugerido: %c %c para cima\n"), i + 65, j + 65);
                    matrizTabu[i][j] = 0;
                    matrizTabu[i - 1][j] = 0;
                    matrizTabu[i - 2][j] = 1;
                    imprimirTabuleiro(n, m, matrizTabu);

                    contajudas++;
                }
            }

            //movimento pra baixo
            if ((i != n - 1) && (i != n - 2)) //verifica se o movimento é valido
            {
                if ((matrizTabu[i][j] == 1) && (matrizTabu[i + 1][j] == 1) && (matrizTabu[i + 2][j] == 0))
                {
                    printf(YELLOW("Movimento sugerido: %c %c para baixo\n"), i + 65, j + 65);
                    matrizTabu[i][j] = 0;
                    matrizTabu[i + 1][j] = 0;
                    matrizTabu[i + 2][j] = 1;

                    imprimirTabuleiro(n, m, matrizTabu);

                    contajudas++;
                }
            }

            //movimento pra direita
            if ((j != m - 1) && (j != m - 2)) //verifica se o movimento é valido
            {
                if ((matrizTabu[i][j] == 1) && (matrizTabu[i][j + 1] == 1) && (matrizTabu[i][j + 2] == 0))
                {
                    printf(YELLOW("Movimento sugerido: %c %c para direita\n"), i + 65, j + 65);
                    matrizTabu[i][j] = 0;
                    matrizTabu[i][j + 1] = 0;
                    matrizTabu[i][j + 2] = 1;

                    imprimirTabuleiro(n, m, matrizTabu);

                    contajudas++;
                }
            }

            //movimento pra esquerda
            if ((j != 0) && (j != 1)) //verifica se o movimento é valido
            {
                if ((matrizTabu[i][j] == 1) && (matrizTabu[i][j - 1] == 1) && (matrizTabu[i][j - 2] == 0))
                {
                    printf(YELLOW("Movimento sugerido: %c %c para esquerda\n"), i + 65, j + 65);
                    matrizTabu[i][j] = 0;
                    matrizTabu[i][j - 1] = 0;
                    matrizTabu[i][j - 2] = 1;

                    imprimirTabuleiro(n, m, matrizTabu);

                    contajudas++;
                }

                if (contajudas == najudas)
                    break;
            }
            if (contajudas == najudas)
                break;
        }
        if (contajudas == najudas)
            break;
    }
    contajudas = 0;

    printf (WHITE("\nContinuando... \n"));

}

//coloca o arquivo
void copiarMatAlea(int n, int m, int **matrizTabu, FILE *arquivoAle)
{
    fprintf(arquivoAle, "%d %d\n", n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            fprintf(arquivoAle, "%2d", matrizTabu[i][j]);
        }
        fprintf(arquivoAle, "\n");
    }
}

/*Antes tinha feito a derrota e vitoria juntos, mas vi que isso não iria funcionar. Logo, aproveitei 
a funçao 'ajuda' para fazer essa funçao derrota. Sempre q voltava no loop do while da funçao main, 
abria essa funçao e conferia se tinha movimentos possiveis para se fazer em todo tabuleiro. Conferia-se
se tinha mais movimentos ou não por meio de um contador('contsugestoes'). Se contsugestoes fosse igual 0,
o codigo continuava a rodar e perguntava o comando novamente pro jogador. Caso não houver mais movimentos
possiveis, o loop é finalizado na funçao main e dá uma mensagem de derrota e o programa se encerra.*/
int derrota(int n, int m, int **matrizTabu)
{

    int contsugestoes = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //moviemnto pra cima
            if ((i != 0) && (i != 1)) //verifica se o movimento é valido
            {
                if ((matrizTabu[i][j] == 1) && (matrizTabu[i - 1][j] == 1) && (matrizTabu[i - 2][j] == 0))
                {

                    contsugestoes++;
                }
            }

            //movimento pra baixo
            if ((i != n - 1) && (i != n - 2)) //verifica se o movimento é valido
            {
                if ((matrizTabu[i][j] == 1) && (matrizTabu[i + 1][j] == 1) && (matrizTabu[i + 2][j] == 0))
                {

                    contsugestoes++;
                }
            }

            //movimento pra direita
            if ((j != m - 1) && (j != m - 2)) //verifica se o movimento é valido
            {
                if ((matrizTabu[i][j] == 1) && (matrizTabu[i][j + 1] == 1) && (matrizTabu[i][j + 2] == 0))
                {

                    contsugestoes++;
                }
            }

            //movimento pra esquerda
            if ((j != 0) && (j != 1)) //verifica se o movimento é valido
            {
                if ((matrizTabu[i][j] == 1) && (matrizTabu[i][j - 1] == 1) && (matrizTabu[i][j - 2] == 0))
                {

                    contsugestoes++;
                }
            }
        }
    }

    if (contsugestoes == 0)

        return 1;
    else

        return 0;
}