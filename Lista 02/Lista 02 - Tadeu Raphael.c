#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define ex1

//Observações: O exercício 02 e 03 fiz um mini joguinho, não sabia se era desta forma que devia ser feito, mas tentei fazer! KKKKKK

//Exercício 01
#ifdef ex1

int main()
{

    setlocale(LC_ALL,"");

    int start;

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%d", &start);

    if(start==1){

        int cont, valor, total, quantidade, media;

        printf("Insira os números, iremos parar quando você informar algum negativo e calcularemos a média: ");

        total = 0;
        quantidade = 0;

        for(cont=0;;cont++){
            scanf("%d", &valor);
            if(valor<0){
                break;
            }
            total = total + valor;
            quantidade++;
        }

        media = total / quantidade;

        printf("Sua média foi: %d", media);

    }} while(start==1);

    return 0;
}

#endif

//Exercício 02
#ifdef ex2

int main(){

    setlocale(LC_ALL, "");

    int start;

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%d", &start);

    if(start==1){

        int valor, aux;

        do{
        printf("Digite um número entre 1 e 99, e o computador descobrirá com MÁGICA! (Garantia de que não tem nenhum truque)\n");
        scanf("%d", &valor);
        }while(valor<1 || valor>99);

        printf("Primeira pergunta! Seu número é par?\n");
        printf("1 > SIM!\n");
        printf("2 > não...\n");
        printf("3 > Talvez\n");
        scanf("%d", &aux);

        printf("Segunda pergunta! Qual era o primeiro número do seu número?\n");
        scanf("%d", &aux);

        printf("Ultima pergunta! Qual a raiz quadrada de 9800765?\n");
        scanf("%d", &aux);

        printf("Seu número era.................................................");
        printf("%d", valor);

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
    scanf("%d", &start);

    if(start==1){

        int valor, aux;

        do{
        printf("Digite um número entre 1 e 99, e o computador descobrirá com MÁGICA! (Garantia de que não tem nenhum truque)\n");
        scanf("%d", &valor);
        }while(valor<1 || valor>99);

        printf("Primeira pergunta! Seu número é par?\n");
        printf("1 > SIM!\n");
        printf("2 > não...\n");
        printf("3 > Talvez\n");
        scanf("%d", &aux);
        switch(aux){

            case 1:
            printf("Ok, obrigado!\n");
            break;

            case 2:
            printf("Poxa...\n");
            break;

            case 3:
            printf("Sério isso?\n");
            break;

            default:
            printf("Você nem escolheu um número dos que te dei!\n");
        }

        printf("Segunda pergunta! Qual era o primeiro número do seu número?\n");
        scanf("%d", &aux);

        printf("Ultima pergunta! Qual a raiz quadrada de 9800765?\n");
        scanf("%d", &aux);

        printf("Seu número era.................................................");
        printf("%d", valor);

    }} while(start==1);


    return 0;
}

#endif // ex3

#ifdef ex4

int main(){

    setlocale(LC_ALL,"");

    int start;

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%d", &start);

    if(start==1){

        int horas, minutos, segundos, aux1, aux2, aux3;

        printf("Digite digite o primeiro horário:\n");
        printf("Horas: ");
        scanf("%d", &horas);

        printf("Minutos: ");
        scanf("%d", &minutos);

        printf("Segundos: ");
        scanf("%d", &segundos);

        aux1 = segundos + (minutos * 60) + (horas * 3600);

        printf("Digite digite o primeiro horário:\n");
        printf("Horas: ");
        scanf("%d", &horas);

        printf("Minutos: ");
        scanf("%d", &minutos);

        printf("Segundos: ");
        scanf("%d", &segundos);

        aux2 = segundos + (minutos * 60) + (horas * 3600);

        aux3 = aux2 - aux1;

        segundos = 0;
        minutos = 0;
        horas = 0;

        if(aux3 >= 60){
                minutos = aux3/60;
                if(minutos >= 60){
                    horas = minutos/60;
                    minutos = minutos % 60;
                    segundos = aux3/3600;
                } else {
                    horas = 0;
                    segundos = minutos % 60;
                }
            } else {
                segundos = aux3;
                minutos = 0;
                horas = 0;
            }

            if(horas > 0){
                printf("%d horas %d minutos e %d segundos", horas, minutos, segundos);
            } else if(minutos > 0){
                printf("%d minutos e %d segundos", minutos, segundos);
            } else {
                printf("%d segundos", segundos);
            }

    }} while(start==1);

    return 0;
}

#endif // ex4

//Exercício 05
#ifdef ex5

int main(){

    setlocale(LC_ALL,"");

    int start;

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%d", &start);

    if(start==1){

        float valor;
        char tipo;

        do{
        printf("Quanto de gasolina você quer?\n");
        scanf("%f", &valor);
        }while(valor<=0);

        do{
        printf("\nQual vai ser o tipo?\n");
        printf("A - Alcool | G - Gasolina\n");
        scanf(" %c", &tipo);
        }while(tipo != 'A' && tipo != 'G');

        switch(tipo){

            case 'A':
                if(valor <= 20){
                    valor = valor * 4.18;
                    valor = valor - (valor * 0.03);
                    printf("O valor com 3 porcento de desconto é: %f", valor);
                } else{
                    valor = valor * 4.18;
                    valor = valor - (valor * 0.05);
                    printf("O valor com 5 porcento de desconto é: %f", valor);
                }
                break;

            case 'G':
                if(valor <= 20){
                    valor = valor * 5.88;
                    valor = valor - (valor * 0.04);
                    printf("O valor com 4 porcento de desconto é: %f", valor);
                } else{
                    valor = valor * 5.88;
                    valor = valor - (valor * 0.06);
                    printf("O valor com 6 porcento de desconto é: %f", valor);
                }
                break;
        }
    }} while(start==1);

    return 0;
}

#endif // ex5
