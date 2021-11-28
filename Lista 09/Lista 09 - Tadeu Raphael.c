#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define ex6

//Observações: Nos exercícios, novamente como na lista 8, não sei se fiz 100% corretamente por conta de não entender os enunciados quando
//comentava sobre usar ponteiros.

//Structs Globais

//Exercício 05
struct local{
    char nome[20];
    char endereco[30];
    char cidade[20];
    char estado[2];
    int cep;
};

//Funções Globais

//Exercício 01
int analisarNomes(char x[], char y[]){

    for(int cont=0; cont<20; cont++){
        if(x[cont] != y[cont]){
            printf("São diferentes\n");
            return 0;
        }
        if(cont == 19){
            printf("São iguais\n");
        }
    }

    return 1;
}

//Exercício 02
int operacoes(char selecao, int valorFinal, int valorAtual){

        switch(selecao){

            case 'N':
                printf("Digite um valor: ");
                scanf("%d", &valorAtual);
                valorFinal = valorFinal + valorAtual;
                break;

            case '-':
                printf("Digite um valor: ");
                scanf("%d", &valorAtual);
                valorFinal = valorFinal - valorAtual;
                break;

            case '*':
                printf("Digite um valor: ");
                scanf("%d", &valorAtual);
                valorFinal = valorFinal * valorAtual;
                break;

            case '/':
                printf("Digite um valor: ");
                scanf("%d", &valorAtual);
                valorFinal = valorFinal / valorAtual;
                break;

        }

    return valorFinal;
}

//Exercício 03
void analisarVetor(char valor, char vetor[]){

    for(int cont=0; cont<13; cont++){
        if(valor == vetor[cont]){
            printf("O valor existe no vetor!\n");
            break;
        }
        if(cont == 12){
            printf("O valor não existe no vetor!\n");
        }
    }

}

//Exercício 04
void exibirValores(char char1, int int1, float float1, double double1, long int longInt1){

    printf("Char: %c\n", char1);
    printf("Int: %i\n", int1);
    printf("Float: %f\n", float1);
    printf("Double: %d\n", double1);
    printf("Long Int: %li\n", longInt1);

}

//Exercício 05
struct local inserirDados(struct local lugar1){

    //Limpando vetores
    for(int cont=0; cont<20; cont++){
        lugar1.nome[cont] = 0;
        lugar1.cidade[cont] = 0;
    }

    for(int cont=0; cont<30; cont++){
        lugar1.endereco[cont] = 0;
    }

    for(int cont=0; cont<2; cont++){
        lugar1.estado[cont] = 0;
    }

    printf("Digite o valor do nome: ");
    scanf("%s", &lugar1.nome);

    printf("Digite o endereco: ");
    scanf("%s", &lugar1.endereco);

    printf("Digite a cidade: ");
    scanf("%s", &lugar1.cidade);

    printf("Digite o estado: ");
    scanf("%s", &lugar1.estado);

    printf("Digite o CEP: ");
    scanf("%d", &lugar1.cep);

    printf("\n");

    return lugar1;
}

void exibirDados(struct local lugar1[]){
    for(int cont=0; cont<4;cont++){
        printf("Nome %d: %s\n", cont+1, lugar1[cont].nome);
        printf("Endereço %d: %s\n", cont+1, lugar1[cont].endereco);
        printf("Cidade %d: %s\n", cont+1, lugar1[cont].cidade);
        printf("Estado %d: %s\n", cont+1, lugar1[cont].estado);
        printf("CEP %d: %d\n", cont+1, lugar1[cont].cep);
        printf("\n");
    }
}

//Exercício 06

void procurarDados(struct local lugar1[]){

    char nome[20];

    for(int cont=0; cont<20; cont++){
        nome[cont] = 0;
    }

    printf("Digite um nome e iremos verificar se está na base: ");
    scanf("%s", &nome);

    for(int cont=0; cont<4; cont++){
        for(int cont2=0; cont2<20; cont2++){
            if(lugar1[cont].nome[cont2] != nome[cont2]){
                break;
            }

            if(cont2 == 19){
                printf("O valor %d é igual ao informado!\n", cont+1);
                printf("\n");
            }
        }
    }



}

struct local alterarDados(struct local lugar1){


    return lugar1;
};

struct local excluirDados(struct local lugar1){

    return lugar1;
};



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

        char nome1[20], nome2[20];

        //Limpeza dos vetores
        for(int cont=0;cont<20;cont++){
            nome1[cont] = 0;
            nome2[cont] = 0;
        }

        printf("Digite o nome 1: ");
        scanf("%s", nome1);

        printf("Digite o nome 2: ");
        scanf("%s", nome2);

        analisarNomes(nome1, nome2);


    }} while(start!=2);

    return 0;
}

#endif // ex1

#ifdef ex2

//Observações: Programa funcionando, porém não consegui usar getchar() para parar de duplicar tudo dentro dele.

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

        int valorFinal = 0;
        int valorAtual = 0;
        char selecao;

        printf("Digite os valores, quando inserir o código, iremos calcular o resultado\n");

        while(selecao != '='){
            printf("\nSelecione uma das opções: \n");
            printf("N: Número | -: Subtração | *: Multiplicação | /: Divisão | =: Resultado final\n");

            scanf("%c", &selecao);

            if(selecao != '='){
                valorFinal = operacoes(selecao, valorFinal, valorAtual);
            }

        }

        printf("Valor final: %d", valorFinal);


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
    printf("2 - Não\n");
    scanf("%d%*c", &start);

    if(start==1){

        char valor;

        char vetor[] = {'b','d','f','h','j','k','m','o','q','s','u','w','y'};

        printf("Digite um caracter para analisarmos\n");
        scanf("%c", &valor);

        analisarVetor(valor, vetor);

    }} while(start!=2);

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

        char char1;
        int int1;
        float float1;
        double double1;
        long int longInt1;

        printf("Digite os valores: \n");

        scanf("%c", &char1);
        scanf("%i", &int1);
        scanf("%f", &float1);
        scanf("%d", &double1);
        scanf("%li", &longInt1);

        exibirValores(char1, int1, float1, double1, longInt1);

    }} while(start!=2);

    return 0;
}

#endif // ex4

#ifdef ex5

int main()
{

    setlocale(LC_ALL, "");

    int start;
    int escolha;

    struct local lugar1[4];

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%d%*c", &start);

    if(start==1){

        do{
            printf("Bem vindo, faça sua escolha: \n");
            printf("1 - Inserir dados\n");
            printf("2 - Exibir dados\n");
            printf("3 - Sair\n");

            scanf("%d", &escolha);

            switch(escolha){

                case 1:
                    for(int cont=0; cont<4; cont++){
                       lugar1[cont] = inserirDados(lugar1[cont]);
                    }
                    break;

                case 2:
                    exibirDados(lugar1);
                    break;

                case 3:
                    printf("Saindo... \n");
                    break;

                default:
                    printf("Valor invalido");
                    break;
            }
        } while(escolha != 3);

    }} while(start!=2);

    return 0;
}

#endif // ex5

#ifdef ex6

int main()
{

    setlocale(LC_ALL, "");

    int start;
    int escolha;

    struct local lugar1[4];

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%d%*c", &start);

    if(start==1){

        do{
            printf("Bem vindo, faça sua escolha: \n");
            printf("1 - Inserir dados\n");
            printf("2 - Exibir dados\n");
            printf("3 - Procurar dados\n");
            printf("4 - Alterar dados\n");
            printf("5 - Excluir dados\n");
            printf("6 - Sair\n");

            scanf("%d", &escolha);

            switch(escolha){

                case 1:
                    for(int cont=0; cont<4; cont++){
                       lugar1[cont] = inserirDados(lugar1[cont]);
                    }
                    break;

                case 2:
                    exibirDados(lugar1);
                    break;

                case 3:
                    procurarDados(lugar1);
                    break;

                case 4:
                    //alterarDados(lugar1);
                    break;

                case 5:
                    //excluirDados(lugar1);
                    break;

                case 6:
                    printf("Saindo... \n");
                    break;

                default:
                    printf("Valor invalido");
                    break;
            }
        } while(escolha != 3);

    }} while(start!=2);

    return 0;
}

#endif // ex6
