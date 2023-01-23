int umaInstrucao[4];

    int instrumMemoryRaiz[100][4];
    int i, j;

    umaInstrucao[0] = 2;
    umaInstrucao[1] = base;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = -1;

    for(j = 0; j < 4; j++) {

        instrumMemoryRaiz[0][j] = umaInstrucao;

    }

    umaInstrucao[0] = 2;
    umaInstrucao[1] = base;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    for(j = 0; j < 4; j++) {

        instrumMemoryRaiz[1][j] = umaInstrucao;

    }

    int contador = 2;

    //do{

        //Caso a base seja 5, serao 4 somas para chegar no valor de 25
        for (i = 2; i < base - 1 + 2; i++){
            umaInstrucao[0] = 0;
            umaInstrucao[1] = 0;
            umaInstrucao[2] = 1;
            umaInstrucao[3] = 1;
            
            for (j = 0; j < 4; j++){
                //trazer da memoria

                instrumMemoryRaiz[i][j] = umaInstrucao;
            }   

            contador++;

            /*umaInstrucao[0] = 3;
            umaInstrucao[1] = -1;
            umaInstrucao[2] = 1;
            umaInstrucao[3] = -1 ;

            maquinaOPERACOES(umaInstrucao,memoriaDados);

            resultadosomas = umaInstrucao[1];

            contador++;*/
        }

    // }while (resultadosomas <= valor);


    int halt = contador + 1; /* +1 pq o contador para no ultimo loop que no caso é a penultimo espaço de 
                            memoria e preciso do ultimo*/

    umaInstrucao[0] = -1;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = -1;
    umaInstrucao[3] = -1;


    for (j = 0; j < 4; j++) {

        instrumMemoryRaiz[halt][j] = umaInstrucao;

    }

    maquina(instrumMemoryRaiz, memoriaDados);

    //trazer da memoria pra printar o resultado da raiz

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    
    maquinaOPERACOES(umaInstrucao, memoriaDados);

    int resultadoRAIZQUADRADA = umaInstrucao[1];

    printf ("\nO resultad da raiz quadrada de %d é igual a %d\n", valor, resultadoRAIZQUADRADA);
}


            do {
                int indiceAleatorioValor = rand () % 1000;

                valor = memoriaDados[indiceAleatorioValor]; //temos que encontrar a raiz quadrada desse valor
            
                suporte = sqrt (valor);
            
            } while (valor % suporte != 0 ); /* faço isso para pegar apenas resultados que sejam inteiros
                                                ja que preciso apenas de raizes que tem resultados inteiros*/
        
        for(j = numero - 2 ; j == 0; j--) {