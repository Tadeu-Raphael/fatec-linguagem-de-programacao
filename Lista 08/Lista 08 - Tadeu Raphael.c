#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Observa��es: Embora tenha feit a lista sem grandes dificuldades, n�o sei se fiz corretamente porque achei meio ambiguo quando
//era pedido para passar os dados usando ponteiros. N�o sabia se precisava que tudo fosse ponteiro, ou s� o que pedia exatamente.

//O exerc�cio 5 e 6 n�o consegui fazer por ter que fazer calculo com os ponteiros. Estou fazendo algo errado que est� travando.

#define ex5

#ifdef ex1

int main()
{

    setlocale(LC_ALL, "");

    int start;
    char caracter[] = {'b','d','f','h','j','l','m','o','q','s','u','w','y'};

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - N�o\n");

    scanf("%d%*c", &start);

    if(start==1){

            char *valor;
            printf("Insira um valor, ele ser� comparado!\n");
            scanf("%c", &valor);

            for(int cont=0;cont<13;cont++){
                if(valor == caracter[cont]){
                    printf("O valor existe!\n");
                    break;
                }
                if(cont==12){
                    printf("O valor n�o existe!\n");
                }
            }

    }} while(start!=2);

    return 0;
}

#endif // ex1

#ifdef ex2

int main()
{

    setlocale(LC_ALL, "");

    int start;

    struct local{
                char *nome[10];
                char *endereco[30];
                char *cidade[20];
                char *estado[2];
                int *cep;
            };

    struct local lugar1;

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - N�o\n");
    scanf("%d%*c", &start);

    if(start==1){

            printf("Digite os valores do nome, endere�o, cidade, estado e CEP:\n");

            int cont = 0;

            while(cont<5){
                switch(cont){

                    case 0:
                        scanf("%s", &lugar1.nome);
                        cont++;
                        break;

                    case 1:
                        scanf("%s", &lugar1.endereco);
                        cont++;
                        break;

                    case 2:
                        scanf("%s", &lugar1.cidade);
                        cont++;
                        break;

                    case 3:
                        scanf("%s", &lugar1.estado);
                        cont++;
                        break;

                    case 4:
                        scanf("%d", &lugar1.cep);
                        cont++;
                        break;

                }
            }

            printf("\nNome: %s | Mem�ria: %d\n", lugar1.nome, *lugar1.nome);
            printf("Endere�o: %s | Mem�ria: %d\n", lugar1.endereco, *lugar1.endereco);
            printf("Cidade: %s | Mem�ria: %d\n", lugar1.cidade, *lugar1.cidade);
            printf("Estado: %s | Mem�ria: %d\n", lugar1.estado, *lugar1.estado);
            printf("CEP: %i\n", lugar1.cep); //N�o estou consigo retornar o valor da mem�ria aqui.

    }} while(start!=2);

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
    printf("2 - N�o\n");
    scanf("%d%*c", &start);

    char *nome1[10], *nome2[10];

    for(int cont=0; cont<10;cont++){
        nome1[cont] = 0;
        nome2[cont] = 0;
    }

    if(start==1){

            printf("Digite o valor da primeira string: ");
            scanf("%s", &nome1);

            printf("Agora da segunda: ");
            scanf("%s", &nome2);

            for(int cont=0; cont<10; cont++){
                if(nome1[cont] != nome2[cont]){
                    printf("As strings s�o diferentes!\n");
                    break;
                }
                if(cont==9){
                    printf("As string s�o iguais!\n");
                }
            }

    }} while(start!=2);

    return 0;
}

#endif // ex3

#ifdef ex4

int main()
{

    setlocale(LC_ALL, "");

    int start;

    char *char1;
    int *int1;
    long int *long1;
    unsigned int *unsigned1;
    float *float1;
    double double1;
    unsigned long int *unsigned2;
    unsigned char *unsigned3;

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - N�o\n");
    scanf("%d%*c", &start);

    if(start==1){

        printf("Digite os valores pedidos!\n");

        printf("Char: ");
        scanf("%c", &char1);

        printf("Int: ");
        scanf("%d", &int1);

        printf("Long Int: ");
        scanf("%d", &long1);

        printf("Unsigned Int: ");
        scanf("%d", &unsigned1);

        printf("Float: ");
        scanf("%f", &float1);

        printf("Double: ");
        scanf("%d", &double1);

        printf("Unsigned Long Int: ");
        scanf("%d", &unsigned2);

        getchar();
        printf("Unsigned Char: ");
        scanf("%c", &unsigned3);

        printf("Mem�ria: ");
        printf("%p \n", &char1);
        printf("%p \n", &int1);
        printf("%p \n", &long1);
        printf("%p \n", &unsigned1);
        printf("%p \n", &float1);
        printf("%p \n", &double1);
        printf("%p \n", &unsigned2);
        printf("%p \n", &unsigned3);

    }} while(start!=2);

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
    printf("2 - N�o\n");
    scanf("%d%*c", &start);

    if(start==1){

            printf("Comece a digitar valores!\n");

            int *aux1 = 0;
            int *aux2 = 0;
            int *aux3 = 0;
            int *valor;

            while(aux1 == 0){

                scanf("%d", &valor);
                if(*valor >= 0){
                    //aux2 = *aux2 + *valor;
                    aux3++;
                }

                if(*valor < 0){
                    aux1++;
                }

            }

            printf("Saiu do loop");
            printf("%d", aux2);

    }} while(start!=2);

    return 0;
}

#endif // ex5

#ifdef ex6

int main()
{

    setlocale(LC_ALL, "");

    int start;

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - N�o\n");
    scanf("%d%*c", &start);

    if(start==1){

    }} while(start!=2);

    return 0;
}

#endif // ex6
