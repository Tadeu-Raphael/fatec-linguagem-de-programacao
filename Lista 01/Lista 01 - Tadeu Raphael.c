#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Imagino que o senhor j� saiba, mas s� ir mudando os exerc�cios por aqui
#define ex1

//Observa��es: No primeiro exerc�cio n�o usei auxiliar por�m n�o sei se est� certo a forma que fiz. J� no segundo, n�o entendi a forma com que era
//para ser exibido, mas exibi de um modo que foi o que entendi.

//Exerc�cio 01
#ifdef ex1

int main()
{

    setlocale(LC_ALL,"");

    int start;

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - N�o\n");
    scanf("%d", &start);

    if(start==1){
    int a, b;

    printf("Digite o valor da vari�vel 1: \n");
    scanf("%d", &a);

    printf("Digite o valor da vari�vel 2: \n");
    scanf("%d", &b);

    printf("Vari�vel 1: %d ", b);
    printf("Vari�vel 2: %d \n", a);
    }} while(start==1);

    return 0;
}

#endif // ex1

//Exerc�cio 02
#ifdef ex2

int main(){

    setlocale(LC_ALL, "");

    int start;

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - N�o\n");
    scanf("%d", &start);

    if(start==1){

        short int a;
        long int b;
        int c;
        float d;
        double e;
        char f;

        printf("Digite um valor short: ");
        scanf("%hd", &a);
        printf("\nDigite um valor long: ");
        scanf("%ld", &b);
        printf("\nDigite um valor int: ");
        scanf("%d", &c);
        printf("\nDigite um valor float: ");
        scanf("%f", &d);
        printf("\nDigite um valor double: ");
        scanf("%lf", &e);
        printf("\nDigite um valor char: ");
        scanf(" %c", &f);

        printf("Short: %hd Long: %ld Int: %d Float: %f Double: %lf Char: %c", a, b, c, d, e, f);
    }}while(start==1);

    return 0;
}

#endif // ex2

//Exerc�cio 03
#ifdef ex3

int main(){

    setlocale(LC_ALL, "");

    int start;

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - N�o\n");
    scanf("%d", &start);

    if(start==1){

        int inicio, segundos, minutos, horas;

        printf("Digite a quantidade total de segundos: ");
        scanf("%d", &inicio);

        if(inicio >= 60){
            minutos = inicio/60;
            if(minutos >= 60){
                horas = minutos/60;
                minutos = minutos % 60;
                segundos = inicio/3600;
            } else {
                horas = 0;
                segundos = minutos % 60;
            }
        } else {
            segundos = inicio;
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
    }}while(start==1);


    return 0;
}

#endif // ex3

//Exerc�cio 04
#ifdef ex4

int main(){

    setlocale(LC_ALL, "");

    int start;

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - N�o\n");
    scanf("%d", &start);

    if(start==1){

        int numero, cont;
        int aux = 100;

        printf("Digite um n�mero e irei dizer o menor multiplicador dele ap�s 100: ");
        scanf("%d", &numero);

        for(cont=1;;cont++){
            if(numero>100){
                break;
            } else{
                numero = numero * cont;
            }
            }

        do{

        if(numero % aux == 0){
            break;
        }

        aux++;

        }while(aux<200);

        printf("O menor n�mero �: %d", aux);

    }}while(start==1);

    return 0;
}

#endif // ex4

//Exerc�cio 05
#ifdef ex5

int main(){

    setlocale(LC_ALL,"");

    int start;

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - N�o\n");
    scanf("%d", &start);

    if(start==1){

        int valor, resto, aux;

        printf("Digite o valor que voc� gostaria de decompor: ");
        scanf("%d", &valor);

        if(valor>=100){
            aux = valor/100;
            resto = valor % 100;
            printf("%d de R$100\n", aux);
            valor = resto;
        }

        if(valor>=50){
            aux = valor/50;
            resto = valor % 50;
            printf("%d de R$50\n", aux);
            valor = resto;
        }

        if(valor>=20){
            aux = valor/20;
            resto = valor % 20;
            printf("%d de R$20\n", aux);
            valor = resto;
        }

        if(valor>=10){
            aux = valor/10;
            resto = valor % 10;
            printf("%d de R$10\n", aux);
            valor = resto;
        }

        if(valor>=5){
            aux = valor/5;
            resto = valor % 5;
            printf("%d de R$5\n", aux);
            valor = resto;
        }

        if(valor>=2){
            aux = valor/2;
            resto = valor % 2;
            printf("%d de R$2\n", aux);
            valor = resto;
        }

        if(valor>=1){
            aux = valor/1;
            resto = valor % 1;
            printf("%d de R$1\n", aux);
            valor = resto;
        }

    }}while(start==1);


    return 0;
}

#endif // ex5
