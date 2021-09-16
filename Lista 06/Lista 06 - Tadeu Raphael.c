#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

//Observações: A lista está feita, porém tem partes incompletas. No exercício 01, não soube fazer a parte dos dias
//No exercicio 3, estou com problemas na subtração e divisão no /= e -= e no exercício 04, só não sei se era exatamente o que fiz

#define ex1

// --------------------- Funções Globais ----------------------

void escolhaC(float c){

    float k, f;

    k = c + 273.15;
    f = (c * 1.8) + 32;

    printf("\nO valor em K é: %f", k);
    printf("\nO valor em F é: %f", f);

}

void escolhaF(float f){

    float c, k;

    k = (f - 32) * 1.8 + 273.15;
    c = (f - 32) * 1.8;

    printf("\nO valor em C é: %f", c);
    printf("\nO valor em K é: %f", k);

}

void escolhaK(float k){

    float c, f;

    c = k - 273.15;
    f = (k - 273.15) * 1.8 + 32;

    printf("\nO valor em C é: %f", c);
    printf("\nO valor em F é: %f", f);

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

            int diaNasc, mesNasc, anoNasc;

            printf("\nDigite o dia que você nasceu: ");
            scanf("%d", &diaNasc);

            printf("\nDigite o mês que você nasceu: ");
            scanf("%d", &mesNasc);

            printf("\nDigite o ano que você nasceu: ");
            scanf("%d", &anoNasc);

            int diaAtual, mesAtual, anoAtual;

            printf("\nDigite o dia de hoje: ");
            scanf("%d", &diaAtual);

            printf("\nDigite o mês de hoje: ");
            scanf("%d", &mesAtual);

            printf("\nDigite o ano de hoje: ");
            scanf("%d", &anoAtual);

            int anos, meses, dias;

            anos = anoAtual - anoNasc;
            meses =(12*anos) + (mesAtual - mesNasc);

            printf("\nValor em anos: %d", anos);
            printf("\nValor em meses: %d", meses);


    }} while(start==1);


    return 0;
}

#endif // ex1

#ifdef ex2


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

        int num1, num2;

        printf("Digite dois números: ");
        scanf("%d", &num1);
        scanf("%d", &num2);

        printf("Somar: %d\n", (num1 + num2));
        printf("Subtrair: %d\n", (num1 - num2));
        printf("Multiplicar: %d\n", (num1 * num2));
        printf("Dividir: %d\n", (num1 / num2));

    }} while(start==1);


    return 0;
}

#endif // ex2

#ifdef ex3


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

        int num1, num2;

        printf("Digite dois números: ");
        scanf("%d", &num1);
        scanf("%d", &num2);

        int somar = num1 += num2;
        printf("Somar: %d\n", somar);

        //Problema
        int subtrair = num1 -= num2;
        printf("Subtrair: %d\n", subtrair);

        printf("Multiplicar: %d\n", (num1 *= num2));

        //Problema
        printf("Dividir: %d\n", (num1/=num2));

    }} while(start==1);


    return 0;
}

#endif // ex3

#ifdef ex4

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

        int num1, num2;
        int temp;
        int valor;

        printf("Digite 2 valores de inteiros: ");
        scanf("%d", &num1);
        scanf("%d", &num2);


        valor = num1 && num2;
        printf("%d\n", valor);
        printf("%x\n\n", valor);

        valor = num1 || num2;
        printf("%d\n", valor);
        printf("%x\n\n", valor);

        valor = num1 ^ num2;
        printf("%d\n", valor);
        printf("%x\n\n", valor);


    }} while(start==1);


    return 0;
}

#endif // ex4

#ifdef ex5


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

            int opcao;
            float valor;

            printf("Digite o valor desejado: \n");
            printf("1 > C para F e K\n");
            printf("2 > F para C e K\n");
            printf("3 > K para C e F\n");

            do{
            scanf("%d", &opcao);
            if(opcao != 1 && opcao != 2 && opcao != 3){
                printf("Selecione um valor válido!");
            }
            }while(opcao != 1 && opcao != 2 && opcao != 3);
            printf("\nDigite o valor: ");
            scanf("%f", &valor);

            switch(opcao){

                case 1:
                escolhaC(valor);
                break;

                case 2:
                escolhaF(valor);
                break;

                case 3:
                escolhaK(valor);
                break;

            }
    }} while(start==1);


    return 0;
}

#endif // ex5
