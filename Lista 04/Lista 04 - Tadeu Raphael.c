#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

//Observação: Assim como na lista 1, unica dúvida foi a forma com que era para ser exibido os vetores no ex2

#define ex1

// ----------------- Funções Globais ----------------

// Função para dar sort no exercício 3
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

#ifdef ex1

int main()
{

    setlocale(LC_ALL, "");

    int start;

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%d%*c", &start);

    if(start==1){

        int matriz[5][5];
        int cont1, cont2, numero;

        printf("Preencha os valores das matrizes: ");

        for(cont1=0;cont1<5;cont1++){
            for(cont2=0;cont2<5;cont2++){
                scanf("%d", &matriz[cont1][cont2]);
            }
        }

        printf("Digite o valor que você quer pesquisar: ");
        scanf("%d", &numero);

        for(cont1=0;cont1<5;cont1++){
            for(cont2=0;cont2<5;cont2++){
                if(numero == matriz[cont1][cont2]){
                    printf("O valor foi encontrado nos indices %d e %d", cont1, cont2);
                    break;
                }
            }
        }
    }} while(start==1);


    return 0;
}

#endif // ex1

#ifdef ex2

int main(){

    setlocale(LC_ALL, "");

    int start;

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%d%*c", &start);

    if(start==1){

        int inteiros[3];
        long int inteirosLongos[3];
        unsigned int naturais[3];
        float racionais[3];
        double dobros[3];

        int cont;

        printf("Digite os inteiros: ");
        for(cont=0;cont<3;cont++){
            scanf("%d", &inteiros[cont]);
        }

        printf("Digite os inteiros longos: ");
        for(cont=0;cont<3;cont++){
            scanf("%ld", &inteirosLongos[cont]);
        }

        printf("Digite os naturais: ");
        for(cont=0;cont<3;cont++){
            scanf("%d", &naturais[cont]);
        }

        printf("Digite os racionais: ");
        for(cont=0;cont<3;cont++){
            scanf("%f", &racionais[cont]);
        }

        printf("Digite os dobros: ");
        for(cont=0;cont<3;cont++){
            scanf("%lf", &dobros[cont]);
        }

        printf("Os valores inteiros foram: %d %d %d\n", inteiros[0], inteiros[1], inteiros[2]);
        printf("Os valores inteiros longos foram: %ld %ld %ld\n", inteirosLongos[0], inteirosLongos[1], inteirosLongos[2]);
        printf("Os valores naturais: %d %d %d\n", naturais[0], naturais[1], naturais[2]);
        printf("Os valores racionais: %f %f %f\n", racionais[0], racionais[1], racionais[2]);
        printf("Os valores dobros: %lf %lf %lf\n", dobros[0], dobros[1], dobros[2]);


    }} while(start==1);

    return 0;
}

#endif // ex2

#ifdef ex3

int main(){

    setlocale(LC_ALL, "");

    int start;

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%d%*c", &start);

    if(start==1){

            int vetorInicial[10], vetorFinal[10];

            printf("Digite 10 números que iremos ordenar e devolver: \n");
            for(int cont=0;cont<10;cont++){
                scanf("%d", &vetorInicial[cont]);
            }

            for(int cont=0;cont<10;cont++){
                vetorFinal[cont] = 0;
            }

            qsort(vetorInicial, 10, sizeof(int), cmpfunc);

            for(int cont=0; cont<10;cont++){
                vetorFinal[cont] = vetorInicial[cont];
            }

            printf("Os valores organizados no novo vetor é: ");
            for(int cont=0; cont<10; cont++){
                printf("%d\n", vetorFinal[cont]);
            }


    }} while(start==1);

    return 0;
}

#endif // ex3

#ifdef ex4

int main(){

    setlocale(LC_ALL, "");

    int start;

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%d%*c", &start);

    if(start==1){

            int vetor1[2][3], vetor2[2][3], vetor3[2][3];

            printf("Digite os valores do primeiro vetor: ");

            for(int cont=0;cont<2;cont++){
                for(int cont2=0;cont2<3;cont2++){
                    scanf("%d", &vetor1[cont][cont2]);
                }
            }a

            printf("Digite os valores do segundo vetor: ");

            for(int cont=0;cont<2;cont++){
                for(int cont2=0;cont2<3;cont2++){
                    scanf("%d", &vetor2[cont][cont2]);
                }
            }

            //Subtrair os valores
            for(int cont=0;cont<2;cont++){
                for(int cont2=0;cont2<3;cont2++){
                    vetor3[cont][cont2] = vetor1[cont][cont2] - vetor2[cont][cont2];
                }
            }

            //Exibir o terceiro vetor
            for(int cont=0;cont<2;cont++){
                for(int cont2=0;cont2<3;cont2++){
                    printf("No indice %d e %d o valor é: %d\n", cont, cont2, vetor3[cont][cont2]);
                }
            }

    }} while(start==1);

    return 0;
}

#endif // ex4

#ifdef ex5


int main(){

    setlocale(LC_ALL, "");

    int start;

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%d%*c", &start);

    if(start==1){

            int tamanho;

            printf("Qual o tamanho do vetor?\n");
            scanf("%d", &tamanho);

            int vetor[tamanho];

            printf("Digite os valores do vetor:\n");

            for(int cont=0; cont<tamanho; cont++){
                scanf("%d", &vetor[cont]);
            }

            int imparesTotal = 0, paresTotal = 0;

            //Analisar Vetor
            for(int cont=0; cont<tamanho;cont++){
                if(vetor[cont] % 2 == 0){
                    paresTotal++;
                } else {
                    imparesTotal++;
                }
            }

            int vetorPares[paresTotal], vetorImpares[imparesTotal];
            int aux = 0;

            //Inserir dados Pares
            for(int cont=0; cont<tamanho;cont++){
                if(vetor[cont] % 2 == 0){
                    vetorPares[aux] = vetor[cont];
                    aux++;
                }
            }

            aux = 0;

            //Inserir dados Impares
            for(int cont=0; cont<tamanho;cont++){
                if(vetor[cont] % 2 != 0){
                    vetorImpares[aux] = vetor[cont];
                    aux++;
                }
            }

            for(int cont=0;cont<paresTotal;cont++){
                printf("Pares: %d\n", vetorPares[cont]);
            }

            for(int cont=0;cont<imparesTotal;cont++){
                printf("Impares: %d\n", vetorImpares[cont]);
            }

    }} while(start==1);

    return 0;
}

#endif // ex5
