#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int n;
    int m;
    srand(time(NULL));

    n = rand() % 5 + 5;
    m = rand() % 5 + 5;

    int contador = 0;
    int formato;
    int diferentenum = 0;
    int matrizTabu[100][100];

    srand(time NULL);

    formato = 1 + rand() % (5 - 1);

    if (formato == 1)
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i >= n / 2 && j >= m / 2) || (i <= n / 2 && j <= m / 2))
                {
                    matrizTabu[i][j] = 0;
                    if (matrizTabu[i][j] == 0)
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
                if (matrizTabu[i][j] == 0)
                {
                    contador++;
                    if (diferentenum== contador)
                    {
                        matrizTabu[i][j] = 1;
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
                matrizTabu[i][j] = 0;
                if (matrizTabu[i][j] == 0)
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
                if (matrizTabu[i][j] == 0)
                {
                    contador++;
                    if (diferentenum == contador)
                    {
                        matrizTabu[i][j] = 1;
                    }
                }
            }
        }
    }

    if(formato == 3){

    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){

        if(j % 2 == 0 || i % 2 == 0 ){
          matrizTabu[i][j] = 0;

          if(matrizTabu[i][j]== 0){

            contador++;
          }
        }
        else
        {
          matrizTabu[i][j]= -1;
        }
      }
    }

    diferentenum = 1 + rand() % (contador - 1);
    
    contador = 0;

    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){

        if(matrizTabu[i][j]== 0){

          contador++;

          if(diferentenum == contador){

            matrizTabu[i][j] = 1;
          }
        }
      }
    }
    }

    if (formato == 4)
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (((i != j && i != (n + 1 / 2)) && j == (m + 1 / 2)) || ((i > j || i == (n + 1 / 2)) || j == (m + 1 / 2)))
                {
                    matrizTabu[i][j] = 0;
                    if (matrizTabu[i][j] == 0)
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
                if (matrizTabu[i][j] == 0)
                {
                    contador++;
                    if (diferentenum == contador)
                    {
                        matrizTabu[i][j] = 1;
                    }
                }
            }
        }
    }

    printf("  ");
    for (int j = 0 ; j < m; j++)
    {
        printf("%1c ", j + 65);
    }

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%1c ", i + 65);
        for (int j = 0; j < m; j++)
        {

            if (matrizTabu[i][j] == -1)
            {
                printf("  ");
            }
            else if (matrizTabu[i][j] == 0)
            {
                printf("X ");
            }
            else if (matrizTabu[i][j] == 1)
            {
                printf("O ");
            }
        }
        printf("\n");
    }
}