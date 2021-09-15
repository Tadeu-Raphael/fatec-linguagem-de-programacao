#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

//Observações: Novamente, não sei exatamente como era para exibir os valores no ex2

#define ex5

// -------------- Variáveis Globais ------------

//Exercício 01
char string1[10];
char string2[10];

//Exercício 02
char nome1[7];
char nome2[7];
char nome3[7];
char nome4[7];
char nome5[7];

//Exercício 05
char palavra[20];

// -----------------Funções Globais ------------

void mudarASCII(char palavra[]){

    int aux[20];

    for(int cont=0; cont<20; cont++){
        if(palavra[cont] != 0){
            aux[cont] = (int)(palavra[cont]);
            aux[cont] = aux[cont] + 1;
            palavra[cont] = (char)(aux[cont]);
            printf("%c", palavra[cont]);
        }
    }
}

//Exercicio 01
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

        printf("Preencha as duas strings.\n");
        printf("String 1: ");
        gets(string1);
        printf("String 2: ");
        gets(string2);


        for(int cont=0; cont<10; cont++){
            if(string1[cont] != string2[cont]){
                printf("As strings são diferentes");
                break;
            }
            if(cont == 9){
                printf("As strings são iguais");
            }
        }


    }} while(start==1);


    return 0;
}

#endif //ex1

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

        printf("Insira 5 nomes\n");
        printf("Nome 1: ");
        gets(nome1);
        printf("Nome 2: ");
        gets(nome2);
        printf("Nome 3: ");
        gets(nome3);
        printf("Nome 4: ");
        gets(nome4);
        printf("Nome 5: ");
        gets(nome5);

        printf("Nome 1: %s\n", nome1);
        printf("Nome 2: %s\n", nome2);
        printf("Nome 3: %s\n", nome3);
        printf("Nome 4: %s\n", nome4);
        printf("Nome 5: %s\n", nome5);

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

            char palavra[25];

            printf("Digite uma palavra e irei deixar em maiúsculo: ");
            gets(palavra);

            for(int cont=0; cont<25; cont++){
                palavra[cont] = toupper(palavra[cont]);
            }

            printf("A palavra maiúscula é: %s", palavra);


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

        char palavra[25];

        printf("Digite uma palavra e irei deixar em minúsculo: ");
        gets(palavra);

        for(int cont=0; cont<25; cont++){
            palavra[cont] = tolower(palavra[cont]);
        }

        printf("A palavra minúsculo é: %s", palavra);

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

    printf("Digite uma palavra e iremos mudar o ASCII dela: ");
    gets(palavra);

    mudarASCII(palavra);

    }} while(start==1);


    return 0;
}

#endif // ex5
