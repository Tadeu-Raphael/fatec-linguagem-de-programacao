#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

#define ex5


// ----------Váriaveis Globais -------


char letras[] = {'b','d','f','h','j','k','m','o','q','s','u','w','y'};


// ------------ Funções --------------

void pesquisarLetra(char x){

    int cont = 0;
    bool existe = false;

    for(cont=0;cont<14;cont++){
        if(letras[cont] == x){
            printf("O valor está no vetor");
            existe = true;
        }
    }

    if(existe == false){
        printf("Este valor não existia no vetor");
    }

}

int analisarValor(int valor1, int valor2){

    int auxPositivo = 0, auxNegativo = 0;

    if(valor1 == 0){
        printf("Valor 1: -1\n");
    } else if(valor1 > 0){
        printf("Valor 1: 1\n");
        auxPositivo++;
    } else {
        printf("Valor 1: 0\n");
        auxNegativo++;
    }

    if(valor2 == 0){
        printf("Valor 1: -1\n");
    } else if(valor2 > 0){
        printf("Valor 1: 1\n");
        auxPositivo++;
    } else {
        printf("Valor 1: 0\n");
        auxNegativo++;
    }

    if(auxPositivo == 2){
        return valor1 + valor2;
    }

    if(auxNegativo == 2){
        return valor1 * valor2;
    }


    return 0;
}

int somar(int x, int y){
    return x + y;
}

int subtrair(int x, int y){
    return x - y;
}

int multiplicar(int x, int y){
    return x * y;
}

int dividir(int x, int y){
    return x / y;
}

int algoritmosFatorial(int x){

    switch(x){

        case 0:
        return 1;

        case 1:
        return 1;

        default:
        break;

    }

    int fatorial, aux, quantidade;
    char aux2;
    aux = x - 1;
    fatorial = x;

    for(;aux>1;aux--){
        fatorial = fatorial * aux;
    }

    quantidade = numPlaces(fatorial);
    char valor[quantidade];

    sprintf(valor,"%d",fatorial);

    int i, resultado = 0;

    for (i=0;i<quantidade;i++){
        aux2 = (int)(valor[i]);
        resultado = resultado + (aux2 - 48);
    }

    return resultado;
}

//Função para contar o tamanho do número, extraida da internet
int numPlaces (int n) {
    if (n < 0) return numPlaces ((n == INT_MIN) ? INT_MAX: -n);
    if (n < 10) return 1;
    return 1 + numPlaces (n / 10);
}

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
    scanf("%d%*c", &start);

    if(start==1){

        char caracter;

        printf("Digite sua letra e informarei se ela está dentro do vetor: ");
        caracter = getchar();

        pesquisarLetra(caracter);

    }} while(start==1);



    return 0;
}

#endif // ex1

//Exercício 02
#ifdef ex2

int main(){

    setlocale(LC_ALL,"");

    int start;

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%d%*c", &start);

    if(start==1){

        int valor1, valor2, aux;

        printf("Bem vindo ao programa, digite dois valores para analisarmos: ");
        scanf("%d %d", &valor1, &valor2);

        aux = analisarValor(valor1, valor2);

        if(aux != 0){
            printf("O calculo é: %d", aux);
        }

    }} while(start==1);

}

#endif // ex2

//Exercício 03
#ifdef ex3

int main(){

    setlocale(LC_ALL,"");

    int start;

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%d%*c", &start);

    if(start==1){

    int valor1, valor2;

    printf("Digite dois valores inteiros: ");
    scanf("%d %d", &valor1, &valor2);

    printf("Soma: %d\n", somar(valor1, valor2));
    printf("Subtrair: %d\n", subtrair(valor1, valor2));
    printf("Multiplicar: %d\n", multiplicar(valor1, valor2));
    printf("Dividir: %d\n", dividir(valor1, valor2));


    }} while(start==1);

    return 0;
}

#endif // ex3

//Exercício 04
#ifdef ex4

int main(){

    setlocale(LC_ALL,"");

    int start;

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%d%*c", &start);

    if(start==1){

        int valor1, valor2, seletor;

        printf("Digite dois valores inteiros: ");
        scanf("%d %d", &valor1, &valor2);

        do{
            printf("O que você deseja realizar?\n");
            printf("1 > Somar\n");
            printf("2 > Subtrair\n");
            printf("3 > Multiplicar\n");
            printf("4 > Dividir\n");
            scanf("%d", &seletor);

            switch(seletor){

                case 1:
                printf("Soma: %d\n", somar(valor1, valor2));
                break;

                case 2:
                printf("Subtrair: %d\n", subtrair(valor1, valor2));
                break;

                case 3:
                printf("Multiplicar: %d\n", multiplicar(valor1, valor2));
                break;

                case 4:
                printf("Dividir: %d\n", dividir(valor1, valor2));
                break;

                default:
                seletor = 5;
            }
        } while(seletor == 5);

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
    scanf("%d%*c", &start);

    if(start==1){

        int valor;

        printf("Digite um número, e retornaremos um valor: ");
        scanf("%d", &valor);

        printf("A soma de cada número do fatorial deste número é: %d", algoritmosFatorial(valor));

    }} while(start==1);

    return 0;
}

#endif // ex5




