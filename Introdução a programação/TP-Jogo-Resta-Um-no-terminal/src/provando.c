    
    
#include <stdio.h>

#define TAB_HOR "\u2501"
#define TAB_VER "\u2503"

void menu(){
    printf("Bem vindo ao Resta UM!\n");

    printf ("\nCOMO JOGAR: \n");

    printf ("O objetivo do jogo é (como o proprio nome diz) deixar apenas uma peça no tabuleiro.       \n");
    printf ("Sempre que você passar uma peça por cima da outra, a peça que está embaixo é retira-      \n");
    printf ("da porémmm, CUIIIIDADOO: você pode ficar sem movimentos se não retirar as peças cor-      \n");
    printf ("retas.");

    printf ("                      - INTRUÇOES DE COMANDOS -");
    printf (TAB_HOR "Comando"  TAB_HOR  "Argumento"  TAB_HOR   "O que ele faz?\n");
    printf (TAB_HOR "----------------------------------------------------------------------------------        TAB_HOR\n");
    printf (TAB_HOR "c"      TAB_HOR  "CD"         TAB_HOR   "Move um pino na célula da linha C e coluna D para cima           TAB_HOR\n");
    printf (TAB_HOR b        TAB_HOR  "CD"         TAB_HOR   Move um pino na célula da linha C e coluna D para baixo          TAB_HOR\n");
    printf (TAB_HOR e        TAB_HOR  "CD"        TAB_HOR   Move um pino na célula da linha C e coluna D para a esquerda     TAB_HOR\n");
    printf (TAB_HOR d        TAB_HOR  "CD"         TAB_HOR   Move um pino na célula da linha C e coluna D para a direita      TAB_HOR\n");
    printf (TAB_HOR ajuda    TAB_HOR  "n"          TAB_HOR   "Seu programa deve sugerir e executar n movimentos para o jogador." TAB_HOR\n");
    printf (TAB_HOR salvar   TAB_HOR  "out"        TAB_HOR   Salva o jogo tal como está no momento no arquivo “out.txt”.      TAB_HOR\n");
    printf (TAB_HOR sair     TAB_HOR  -          TAB_HOR   Encerra o programa (sem salvar as últimas alteracoes).           TAB_HOR\n");
}

int main (){

    menu();



}



void salvandoJogo(int n, int m, int matriz[][15]) {

    FILE *salva = fopen("out.txt", "w");

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){

            if (matriz[i][j] == -1){
                fprintf(salva ,"  ");
            }
            else if (matriz[i][j] == 0){
                fprintf (salva, "x ");
            }
            else if (matriz[i][j] == 1){
                fprintf (salva, "O ");
            }
        }
        printf("\n");
        }
}
