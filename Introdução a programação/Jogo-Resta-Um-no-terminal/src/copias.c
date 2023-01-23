    else if (strcmp(decisao, "SIM") == 0)
    {
        //pega um tabuleiro imprimirTabuALEA e faz sua primeira impressao;
        imprimirTabuALEA(n, m, matrizTabu);
    }



    //DERROTAAAAAAAAAAAAAAAAAAAAA

            printf(RED(BOLD("\nVISHHH !! YOUU LOSEE =( !!\n")));
            printf(RED(BOLD("\nUHHHHHHH")) BG_RED("(vaias)\n"));
            printf(RED(BOLD("\nTente novamente e seja um campeao(ou nao rsrs)!!\n")));
            break;


                //primeira coisa: perguntar se o usuario quer um jogo dele ou um imprimirTabuALEA!!
    printf("Deseja jogar um jogo aletorio/randomico ou usar um arquivo próprio??\n");
    printf("Digite" BLUE(" (SIM) ") "para tabuleiro aleatorio ou" RED(" (NAO) ") "para jogo proprio!!: ");
    scanf("%s", decisao);

    getchar();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //moviemnto pra cima
            if ((i != 0) && (i != 1)) //verifica se o movimento é valido
            {
                if ((matrizTabu[i][j] == 1) && (matrizTabu[i - 1][j] == 1) && (matrizTabu[i - 2][j] == 0))
                {
                    ;
                    contsugestoes++;
                }
            }

            //movimento pra baixo
            else if ((i != n - 1) && (i != n - 2)) //verifica se o movimento é valido
            {
                if ((matrizTabu[i][j] == 1) && (matrizTabu[i][j + 1] == 1) && (matrizTabu[i][j + 2] == 0))
                {

                    contsugestoes++;
                }
            }

            //movimento pra direita
            else if ((j != m - 1) && (j != m - 2)) //verifica se o movimento é valido
            {
                if ((matrizTabu[i][j] == 1) && (matrizTabu[i + 1][j] == 1) && (matrizTabu[i + 2][j] == 0))
                {

                    contsugestoes++;
                }
            }

            //movimento pra esquerda
            else if ((j != 0) && (j != 1)) //verifica se o movimento é valido
            {
                if ((matrizTabu[i][j] == 1) && (matrizTabu[i - 1][j] == 1) && (matrizTabu[i - 2][j] == 0))
                {

                    contsugestoes++;
                }
            }

            if (contsugestoes = 0)

                return 1;
        }

    }