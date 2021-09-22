#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Desafio 01 - Grupo 06
//Alunos: Tadeu Raphael & Henrique Berg

// --------------- Variáveis globais --------------------------

//Criação das 2 matrizes
char empresa[3][30];
char telefone[3][12];

//Criação de 2 arquivos
FILE *arquivoEmpresa;
FILE *arquivoTelefone;

// --------------- Declaração das Funções Globais -------------

//Função que escreve os dados
//Status: Completa
void escreverDados();

//Função que lista todos os dados dos arquivos
//Status: Completa
void listarDados();

//Função para pesquisar a partir de um nome dado
//Status: Completo
void pesquisarNomeCompleto();

//Função para pesquisar a partir da primeira letra
//Status: Completo
void pesquisarPrimeiraLetra();

//Função para alterar dados
//Status: Completa
void alterarDados();

//Função para excluir dados
//Status: Completa
void excluiDados();

//Função Main()
int main()
{

    setlocale(LC_ALL,"");

    int valor;

    do{

        printf("\n\nDigite a sua opção\n");
        printf("1 > Entrada de Dados no Arquivo\n");
        printf("2 > Listar Dados do Arquivo\n");
        printf("3 > Pesquisa uma empresa com o nome completo e mostra na tela\n");
        printf("4 > Pesquisa as empresas pela 1a letra e mostra todos na tela\n");
        printf("5 > Altera dados\n");
        printf("6 > Exclui dados\n");
        printf("7 > Saída\n\n");

        scanf("%d", &valor);

        switch(valor){

            case 1:
                escreverDados();
            break;

            case 2:
                listarDados();
            break;

            case 3:
                pesquisarNomeCompleto();
            break;

            case 4:
                pesquisarPrimeiraLetra();
            break;

            case 5:
                alterarDados();
            break;

            case 6:
                excluiDados();
            break;

            case 7:
            printf("\nFechando\n\n");
            break;

            default:
            printf("\nDigite um valor válido!\n\n");

        }

    } while(valor != 7);

    system("pause");
    return 0;
}

// --------------- Funções Globais Completas -------------

//Função que escreve os dados
//Status: Completa
void escreverDados(){

    int cont;
    getchar();

    //Limpa os vetores
    for(int cont=0;cont<3;cont++){
        for(int cont2=0;cont2<30;cont2++){
            empresa[cont][cont2] = 0;
            telefone[cont][cont2] = 0;
        }
    }

    arquivoEmpresa = fopen("ArquivoEmpresa.txt", "w");

    for(cont=0;cont<3; cont++){
        printf("Digite o valor da empresa %d: \n", cont+1);
        gets(empresa[cont]);
        fwrite(empresa[cont], sizeof(empresa[cont]), 1, arquivoEmpresa);
    }

    fclose(arquivoEmpresa);

    arquivoTelefone = fopen("ArquivoTelefone.txt", "w");

    for(cont=0;cont<3;cont++){
        printf("Digite o valor do telefone %d: \n", cont+1);
        gets(telefone[cont]);
        fwrite(telefone[cont], sizeof(telefone[cont]), 1, arquivoTelefone);
    }

    fclose(arquivoTelefone);

}

//Função que lista todos os dados dos arquivos
//Status: Completa
void listarDados(){

    int cont;

    arquivoEmpresa = fopen("ArquivoEmpresa.txt", "r");

    for(cont=0;cont<3;cont++){
        fread(empresa[cont], sizeof(empresa[cont]), 1, arquivoEmpresa);
        printf("O valor da empresa %d é: %s\n", cont+1, empresa[cont]);
    }

    fclose(arquivoEmpresa);

    arquivoTelefone = fopen("ArquivoTelefone.txt", "r");

    for(cont=0;cont<3;cont++){
        fread(telefone[cont], sizeof(telefone[cont]), 1, arquivoTelefone);
        printf("O valor do telefone %d é: %s\n", cont+1, telefone[cont]);
    }

    fclose(arquivoTelefone);

}

//Função para pesquisar um nome dentro dos arquivos
//Status: Completo
void pesquisarNomeCompleto(){

    char nome[30];
    getchar();

    //Limpa o vetor
    for(int cont=0;cont<30;cont++){
        nome[cont] = 0;
    }

    printf("Digite um nome de empresa que será pesquisado: ");
    gets(nome);

    for(int cont=0;cont<3;cont++){
        for(int cont2=0;cont2<30;cont2++){
            if(nome[cont2] != empresa[cont][cont2]){
                printf("A empresa %d não é igual ao valor\n", cont+1);
                break;
            }
            if(cont2 == 29){
                printf("A empresa %d é igual ao valor: %s\n", cont+1, empresa[cont]);
            }
        }
    }

}

//Função para pesquisar a partir de uma letra
//Status: Completo
void pesquisarPrimeiraLetra(){

    char letra;
    int cont;

    printf("Digite uma leta: ");
    getchar();
    letra = getchar();

    for(cont=0;cont<3;cont++){
        if(empresa[cont][0] == letra){
            printf("A empresa %d é igual: %s\n", cont+1, empresa[cont]);
        }
    }

}

//Função para alterar dados
//Status: Completa
void alterarDados(){

    char nome[30];
    getchar();

    //Limpa o vetor
    for(int cont=0;cont<30;cont++){
        nome[cont] = 0;
    }

    printf("Digite um nome de empresa que será alterado: ");
    gets(nome);

    arquivoEmpresa = fopen("ArquivoEmpresa.txt", "w");

    for(int cont=0;cont<3;cont++){
        for(int cont2=0;cont2<30;cont2++){
            if(nome[cont2] != empresa[cont][cont2]){
                printf("A empresa %d não será alterada\n", cont+1);
                break;
            }
            if(cont2 == 29){
                printf("A empresa %d será alterada\n", cont+1);
                printf("Digite o novo valor: ");
                gets(empresa[cont]);
            }
        }

        fwrite(empresa[cont], sizeof(empresa[cont]), 1, arquivoEmpresa);
    }

    fclose(arquivoEmpresa);

}

//Função para excluir dados
//Status: Completa
void excluiDados(){

    char nome[30];
    getchar();

    //Limpa o vetor
    for(int cont=0;cont<30;cont++){
        nome[cont] = 0;
    }

    printf("Digite um nome de empresa que será excluida: ");
    gets(nome);

    arquivoEmpresa = fopen("ArquivoEmpresa.txt", "w");

    for(int cont=0;cont<3;cont++){
        for(int cont2=0;cont2<30;cont2++){
            if(nome[cont2] != empresa[cont][cont2]){
                printf("A empresa %d não será excluido\n", cont+1);
                break;
            }
            if(cont2 == 29){
                printf("A empresa %d será excluida\n", cont+1);
                for(int cont3=0;cont3<30;cont3++){
                    empresa[cont][cont3] = 0;
                }
            }
        }
        fwrite(empresa[cont], sizeof(empresa[cont]), 1, arquivoEmpresa);
    }

    fclose(arquivoEmpresa);
}

