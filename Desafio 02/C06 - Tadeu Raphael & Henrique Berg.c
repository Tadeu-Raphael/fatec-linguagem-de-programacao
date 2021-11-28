#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Grupo 06:
//          Tadeu Raphael
//          Henrique Berg

// --------------- Estruturas de Dados --------------------------

struct registro{
    char nome[20];
    char cidade[20];
    char celular[20];
    char salario[20];
};

// --------------- Declaração das Funções Globais -------------

//Função de entrada de dados
void entrarDados();

//Função para listar dados cadastrados
void listarDados();

//Função de pesquisa pelo nome
int pesquisarNome();

// Função de pesquisa pela cidade
void pesquisarCidade();

//Função de pesquisa pelo celular
void pesquisarCelular();

//Função de pesquisa pela faixa salarial
void pesquisarFaixa();

//Função de alterar salário pesquisando o nome completo
void alterarSalario();

//Função de alterar dados pesquisando o nome completo
void alterarDados();

//Função de excluir dados pesquisando o nome completo
void excluirDados();

int main()
{

    setlocale(LC_ALL, "");

    struct registro *p2;
    struct registro base;
    int tamanho;

    p2 = &base;
    tamanho = sizeof(base);

    int start;

    do{

       printf("\nSeja bem vindo ao programa! \n");
       printf("1 - Entrar dados \n");
       printf("2 - Listar todos os dados \n");
       printf("3 - Pesquisar pelo nome completo\n");
       printf("4 - Pesquisar pela cidade completa\n");
       printf("5 - Pesquisar pelo celular\n");
       printf("6 - Pesquisar por faixa salarial\n");
       printf("7 - Altera o valor do salário, pesquisando o nome completo\n");
       printf("8 - Altera dados, pesquisando o nome completo\n");
       printf("9 - Exclui dados, pesquisando o nome completo\n");
       printf("10 - Saída pelo usuário\n\n");

       scanf("%d", &start);

       switch(start){

            case 1:
                entrarDados(p2, tamanho);
                break;

            case 2:
                listarDados(p2, tamanho);
                break;

            case 3:
                pesquisarNome(p2, tamanho);
                break;

            case 4:
                pesquisarCidade(p2, tamanho);
                break;

            case 5:
                pesquisarCelular(p2, tamanho);
                break;

            case 6:
                pesquisarFaixa(p2, tamanho);
                break;

            case 7:
                alterarSalario(p2, tamanho);
                break;

            case 8:
                alterarDados(p2, tamanho);
                break;

            case 9:
                excluirDados(p2, tamanho);
                break;

            case 10:
                printf("\nO programa está fechando...\n\n");
                break;

            default:
                printf("\nO valor informado é inválido!\n\n");
                break;
       }
    }while(start != 10);

    system("pause");
    return 0;
}

// --------------- Funções Globais Completas -------------

void entrarDados(struct registro *p2, int tamanho){

    FILE *arquivo;
    int cont = 0;

    //Limpar vetores dos ponteiros
    for(int aux=0; aux<20; aux++){
        p2->nome[aux] = 0;
        p2->cidade[aux] = 0;
        p2->celular[aux] = 0;
        p2->salario[aux] = 0;
    }

    arquivo = fopen("arquivo.txt", "a");

    if (arquivo == NULL){
            printf("Problema ao abrir o arquivo");
            exit(0);
    }

    getchar();
    printf("Nome: ");
    gets(p2->nome);

    printf("Cidade: ");
    gets(p2->cidade);

    printf("Celular: ");
    gets(p2->celular);

    printf("Faixa Salarial: ");
    gets(p2->salario);

    fwrite(p2, tamanho, 1, arquivo);
    fclose(arquivo);

}

void listarDados(struct registro *p2, int tamanho){

    //Inicializa os arquivos
    FILE *arquivo;
    int cont;
    int comprimento;
    int a, aux = 0;

    arquivo = fopen("arquivo.txt", "r");

    for ( ; ; ){

        a = fread(p2, tamanho, 1, arquivo);

        if(a == 0){
            break;
        }

        if(p2->nome[0] != NULL){
            printf("Índice: %d | %s %s %s %s \n", aux+1, p2->nome, p2->cidade, p2->celular, p2->salario);
        }

        aux++;

    }

    fclose(arquivo);

}

int pesquisarNome(struct registro *p2, int tamanho){

    //Inicializa os arquivos
    FILE *arquivo;

    char nomeX[20];
    int cont, letra, a, aux = 0;

    //Limpar Vetor
    for(int aux = 0; aux < 20; aux++){
        nomeX[aux] = 0;
    }

    getchar();
    printf("Digite o nome que será pesquisado: ");
    gets(nomeX);

    arquivo = fopen("arquivo.txt", "r");

    for( ; ; ){

        a = fread(p2, tamanho, 1, arquivo);

        if(a == 0){
            break;
        }

        for(letra = 0; nomeX[letra] != NULL; letra++){
            if (nomeX[letra] != p2->nome[letra]){
                break;
            }
        }

        if(nomeX[letra] == NULL && p2->nome[letra] == NULL){
            printf("Índice %d | %s %s %s %s \n", aux+1, p2->nome, p2->cidade, p2->celular, p2->salario);

            fclose(arquivo);

            return aux;

        }

        aux++;

    }

    printf("Índice não encontrado\n");

    fclose(arquivo);

    return -1;

}

void pesquisarCidade(struct registro *p2, int tamanho){

    //Inicializa os arquivos
    FILE *arquivo;

    char cidadeX[20];
    int cont, letra, a, aux = 0;

    //Limpar Vetor
    for(int aux = 0; aux < 20; aux++){
        cidadeX[aux] = 0;
    }

    getchar();
    printf("Digite a cidade que será pesquisada: ");
    gets(cidadeX);

    arquivo = fopen("arquivo.txt", "r");

    for( ; ; ){

        a = fread(p2, tamanho, 1, arquivo);

        if(a == 0){
            break;
        }

        for(letra = 0; cidadeX[letra] != NULL; letra++){
            if (cidadeX[letra] != p2->cidade[letra]){
                break;
            }
        }

        if(cidadeX[letra] == NULL && p2->cidade[letra] == NULL){
            printf("Índice %d | %s %s %s %s \n", aux+1, p2->nome, p2->cidade, p2->celular, p2->salario);
        }

        aux++;

    }

    fclose(arquivo);

}

void pesquisarCelular(struct registro *p2, int tamanho){

    FILE *arquivo;

    char celularX[20];
    int cont, letra, a, aux = 0;

    //Limpar Vetor
    for(int aux = 0; aux < 20; aux++){
        celularX[aux] = 0;
    }

    getchar();
    printf("Digite a cidade que será pesquisada: ");
    gets(celularX);

    arquivo = fopen("arquivo.txt", "r");

    for( ; ; ){

        a = fread(p2, tamanho, 1, arquivo);

        if(a == 0){
            break;
        }

        for(letra = 0; celularX[letra] != NULL; letra++){
            if (celularX[letra] != p2->celular[letra]){
                break;
            }
        }

        if(celularX[letra] == NULL && p2->celular[letra] == NULL){
            printf("Índice %d | %s %s %s %s \n", aux+1, p2->nome, p2->cidade, p2->celular, p2->salario);
        }

        aux++;

    }

    fclose(arquivo);

}

void pesquisarFaixa(struct registro *p2, int tamanho){

    FILE *arquivo;

    char salarioX[20];
    int cont, letra, a, aux = 0;

    //Limpar Vetor
    for(int aux = 0; aux < 20; aux++){
        salarioX[aux] = 0;
    }

    getchar();
    printf("Digite a cidade que será pesquisada: ");
    gets(salarioX);

    arquivo = fopen("arquivo.txt", "r");

    for( ; ; ){

        a = fread(p2, tamanho, 1, arquivo);

        if(a == 0){
            break;
        }

        for(letra = 0; salarioX[letra] != NULL; letra++){
            if (salarioX[letra] != p2->salario[letra]){
                break;
            }
        }

        if(salarioX[letra] == NULL && p2->salario[letra] == NULL){
            printf("Índice %d | %s %s %s %s \n", aux+1, p2->nome, p2->cidade, p2->celular, p2->salario);
        }

    }

    fclose(arquivo);

}

void alterarSalario(struct registro *p3, int tamanho){

    FILE *arquivo;

    int numRegistro, numBytes;

    numRegistro = pesquisarNome(p3, tamanho);

    if(numRegistro != -1){

        numBytes = tamanho * numRegistro;

        arquivo = fopen("arquivo.txt", "r+");
        fseek(arquivo, numBytes, 0);
        fread(p3, tamanho, 1, arquivo);

        printf("Digite o novo salário: ");
        scanf("%s", &p3->salario);
        fflush(stdin);

        fseek(arquivo, numBytes, 0);
        fwrite(p3, tamanho, 1, arquivo);
        fclose(arquivo);

    } else {

        printf("Algo de errado aconteceu! \n");

    }

}

void alterarDados(struct registro *p2, int tamanho){

    FILE *arquivo;

    int numRegistro, numBytes;

    numRegistro = pesquisarNome(p2, tamanho);

    if(numRegistro != -1){

        numBytes = tamanho * numRegistro;

        arquivo = fopen("arquivo.txt", "r+");
        fseek(arquivo, numBytes, 0);
        fread(p2, tamanho, 1, arquivo);

        printf("Vamos digitar os novos dados! \n");

        printf("Nome: ");
        gets(p2->nome);

        printf("Cidade: ");
        gets(p2->cidade);

        printf("Celular: ");
        gets(p2->celular);

        printf("Faixa salarial: ");
        gets(p2->salario);

        fseek(arquivo, numBytes, 0);
        fwrite(p2, tamanho, 1, arquivo);
        fclose(arquivo);

    } else {

        printf("Algo de errado aconteceu! \n");

    }

}

void excluirDados(struct registro *p2, int tamanho){

    FILE *arquivo;

    int numRegistro, numBytes;

    arquivo = fopen("arquivo.txt", "r+");

    numRegistro = pesquisarNome(p2, tamanho);
    numBytes = tamanho * numRegistro;

    fseek(arquivo, numBytes, 0);
    fread(p2, tamanho, 1, arquivo);

    for(int aux = 0; aux < 20; aux++){
        p2->nome[aux] = NULL;
        p2->cidade[aux] = NULL;
        p2->celular[aux] = NULL;
        p2->salario[aux] = NULL;
    }

    fseek(arquivo, numBytes, 0);
    fwrite(p2, tamanho, 1, arquivo);
    fclose(arquivo);

}
