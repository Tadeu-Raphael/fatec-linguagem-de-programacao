#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define ex1

//Observações: No exercício um, para não deixar muito complexo, converti um ano em 365 dias e um mês em 30 dias. Já no ultimo, assim como em outros
//exercícios parecidos, não sabia qual era a forma exata que era para exibir os dados, então exibi como estava exibindo nos outros.

#ifdef ex1

int main()
{

    setlocale(LC_ALL, "");

    struct data{
        int dia;
        int mes;
        int ano;
    };

    int start;

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%d%*c", &start);

    struct data datas[2];

    if(start==1){

        struct data resultado;
        int diasTotais;

        printf("Digite o valor do dia 1\n");
        scanf("%d", &datas[0].dia);

        printf("Digite o valor do mes 1\n");
        scanf("%d", &datas[0].mes);

        printf("Digite o valor do ano 1\n");
        scanf("%d", &datas[0].ano);

        printf("Digite o valor do dia 2\n");
        scanf("%d", &datas[1].dia);

        printf("Digite o valor do mes 2\n");
        scanf("%d", &datas[1].mes);

        printf("Digite o valor do ano 2\n");
        scanf("%d", &datas[1].ano);

        resultado.dia = datas[1].dia - datas[0].dia;
        resultado.mes = (datas[1].mes - datas[0].mes) * 30;
        resultado.ano = (datas[1].ano - datas[0].ano) * 365;

        diasTotais = resultado.dia + resultado.mes + resultado.ano;

        printf("A diferença entre as datas é: %d dias", diasTotais);

    }} while(start==1);

    return 0;
}

#endif // ex1

#ifdef ex2

int main()
{

    setlocale(LC_ALL, "");

    int start;

    struct pessoa {
        char nome[30];
        float peso;
        float altura;
        float imc;
    };

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    printf("3 - Calcular e exibir IMC\n\n");
    scanf("%d%*c", &start);

    struct pessoa pessoa1;

    if(start==1){

        for(int cont=0; cont<30; cont++){
            pessoa1.nome[cont] = 0;
        }

        printf("Insira os dados\n\n");

        printf("Nome:\n");
        scanf("%s", &pessoa1.nome);

        printf("Peso:\n");
        scanf("%f", &pessoa1.peso);

        printf("Altura:\n");
        scanf("%f", &pessoa1.altura);

    }

    if(start==3){

        pessoa1.imc = pessoa1.peso / (pessoa1.altura * pessoa1.altura);

        printf("O IMC é: %f", pessoa1.imc);

    }

    } while(start!=2);

    return 0;
}

#endif // ex2

#ifdef ex3

int main()
{

    setlocale(LC_ALL, "");

    int start;

    struct pessoa {
        char nome[30];
        char endereco[60];
        char cidade[30];
        char estado[2];
        int cep;
    };

    struct pessoa grupo[4];

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%d%*c", &start);

    if(start==1){

        for(int cont=0; cont<4; cont++){
            printf("Digite o nome %d: \n", cont+1);
            scanf("%s", &grupo[cont].nome);
            printf("Digite o endereco %d: \n", cont+1);
            scanf("%s", &grupo[cont].endereco);
            printf("Digite a cidade %d: \n", cont+1);
            scanf("%s", &grupo[cont].cidade);
            printf("Digite o estado %d: \n", cont+1);
            scanf("%s", &grupo[cont].estado);
            printf("Digite o cep %d: \n", cont+1);
            scanf("%d", &grupo[cont].cep);
        }

        printf("\n\n");

        for(int cont=0; cont<4; cont++){
            printf("Nome %d: %s\n", cont+1, grupo[cont].nome);
            printf("Endereço %d: %s\n", cont+1, grupo[cont].endereco);
            printf("Cidade %d: %s\n", cont+1, grupo[cont].cidade);
            printf("Estado %d: %s\n", cont+1, grupo[cont].estado);
            printf("CEP %d: %d\n", cont+1, grupo[cont].cep);
        }



    }} while(start==1);

    return 0;
}

#endif // ex3

#ifdef ex4

int main()
{

    setlocale(LC_ALL, "");

    int start;

    struct valores{
        char letra;
        int inteiro;
        long longo;
        float racional;
        double dobro;
        unsigned char letra2;
        unsigned int inteiro2;
        unsigned long longo2;
    };

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%d%*c", &start);

    struct valores numeros;

    if(start==1){

        printf("Digito o valor do char:\n");
        scanf("%c", &numeros.letra);
        printf("Digito o valor do int:\n");
        scanf("%d", &numeros.inteiro);
        printf("Digito o valor do long:\n");
        scanf("%ld", &numeros.longo);
        printf("Digito o valor do float:\n");
        scanf("%f", &numeros.racional);
        printf("Digito o valor do double:\n");
        scanf("%ld", &numeros.dobro);
        printf("Digito o valor do unsigned char:\n");
        getchar();
        scanf("%c", &numeros.letra2);
        printf("Digito o valor do unsigned int:\n");
        scanf("%d", &numeros.inteiro2);
        printf("Digito o valor do unsigned long:\n\n");
        scanf("%ld", &numeros.longo2);

        printf("Char: %c\n", numeros.letra);
        printf("Int: %d\n", numeros.inteiro);
        printf("Long: %ld\n", numeros.longo);
        printf("Float: %f\n", numeros.racional);
        printf("Double: %ld\n", numeros.dobro);
        printf("Unsigned Char: %c\n", numeros.letra2);
        printf("Unsigned Int: %d\n", numeros.inteiro2);
        printf("Unsigned Long: %ld\n", numeros.longo2);

    }} while(start==1);

    return 0;
}

#endif // ex4
