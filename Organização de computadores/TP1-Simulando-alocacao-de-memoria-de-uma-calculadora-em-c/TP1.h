# ifndef TP1_h
# define TP1_h


//PROTOTIPOS DAS FUNÇOES

int **alocaMemoriaInstrucoes(int **memoriaInstru, int n, int m);

int *alocaMemoriaRam (int tamanho_memoria, int *memoriaRAM);

int *desalocaMemoriaRAM(int *memoriaRAM);

int **desalocaMemoriaInstru (int **memoriaInstru, int n);

void montarRAM (int tamanho_memoria, int *memoriaRAM);

void menu();

void InstruAle(int **guarda_memoria, int *memoriadados);

void multiplicaInstru (int guarda_memoria[][4], int multiplicando, int multiplicador, int *memoriadedados);

void divideInstru (int guarda_memoria[][4], int dividendo, int divisor, int *memoriadedados);

void expoInstru (int guarda_memoria[][4], int base, int expoente, int *memoriadedados);

void pitagorasInstru (int **guarda_memoria, int ladoc, int ladob, int *memoriadedados); 

void raizquadradaInstru (int guarda_memoria[][4], int valor, int *memoriadedados);

void fatorialInstru (int **guarda_memoria, int numero, int *memoriadedados);

void areaquadrado (int **guarda_memoria, int lado, int *memoriadedados);

void arearetangulo (int **guarda_memoria, int lado1, int lado2, int *memoriadedados);

void areatriangulo(int **guarda_memoria, int base, int altura, int *memoriadedados);

void areacirculo(int guarda_memoria[][4], int raio, int *memoriadedados);

void comprimentocirculo(int **guarda_memoria, int raio, int *memoriadedados);

void arealosango(int **guarda_memoria, int diagonalmaior, int diagonalmenor, int *memoriadedados);

void areaparalelogramo (int **guarda_memoria, int base, int altura, int *memoriadedados);

void areatrapezio(int **guarda_memoria, int basemenor, int basemaior, int altura, int *memoriadedados ); 

void baskara (int **guarda_memoria, int a, int b, int c, int *memoriadedados) ;

void areacubo(int **guarda_memoria, int lado, int *memoriadedados);

void volumecubo (int **guarda_memoria, int lado, int *memoriadedados);

void areaParalelepipedo(int **guarda_memoria, int lado1, int lado2, int lado3, int *memoriadedados );

void volumeParalelepipedo (int **guarda_memoria, int lado1, int lado2, int lado3, int *memoriadedados );

void volumeCilindro (int **guarda_memoria, int raio, int altura, int *memoriadedados);

void areaCilindro (int **guarda_memoria, int raio, int altura, int *memoriadedados);

void valorabsoluto(int **guarda_memoria, int valornegativo, int *memoriadedados);

void maquina(int guarda_memoria[][4], int *memoriaDados);

void maquinaOPERACOES(int *umaInstrucao, int *memoriaDados);

#endif