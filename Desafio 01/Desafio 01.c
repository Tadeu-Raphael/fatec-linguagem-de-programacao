#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Desafio 01 - Grupo 06
//Alunos: Tadeu Raphael & Henrique Berg

// --------------- Vari�veis globais --------------------------

//Cria��o das 2 matrizes
char empresa[3][30];
char telefone[3][12];

//Cria��o de 2 arquivos
FILE *arquivoEmpresa;
FILE *arquivoTelefone;

// --------------- Declara��o das Fun��es Globais -------------

//Fun��o que escreve os dados
//Status: Completa
void escreverDados();

//Fun��o que lista todos os dados dos arquivos
//Status: Completa
void listarDados();

//Fun��o para pesquisar a partir de um nome dado
//Status: Completo
void pesquisarNomeCompleto();

//Fun��o para pesquisar a partir da primeira letra
//Status: Completo
void pesquisarPrimeiraLetra();

//Fun��o para alterar dados
//Status: Completa
void alterarDados();

//Fun��o para excluir dados
//Status: Completa
void excluiDados();

//Fun��o Main()
int main()
{

    setlocale(LC_ALL,"");

    int valor;

    do{

        printf("\n\nDigite a sua op��o\n");
        printf("1 > Entrada de Dados no Arquivo\n");
        printf("2 > Listar Dados do Arquivo\n");
        printf("3 > Pesquisa uma empresa com o nome completo e mostra na tela\n");
        printf("4 > Pesquisa as empresas pela 1a letra e mostra todos na tela\n");
        printf("5 > Altera dados\n");
        printf("6 > Exclui dados\n");
        printf("7 > Sa�da\n\n");

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
            printf("\nDigite um valor v�lido!\n\n");

        }

    } while(valor != 7);

    system("pause");
    return 0;
}

// --------------- Fun��es Globais Completas -------------

//Fun��o que escreve os dados
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

//Fun��o que lista todos os dados dos arquivos
//Status: Completa
void listarDados(){

    int cont;

    arquivoEmpresa = fopen("ArquivoEmpresa.txt", "r");

    for(cont=0;cont<3;cont++){
        fread(empresa[cont], sizeof(empresa[cont]), 1, arquivoEmpresa);
        printf("O valor da empresa %d �: %s\n", cont+1, empresa[cont]);
    }

    fclose(arquivoEmpresa);

    arquivoTelefone = fopen("ArquivoTelefone.txt", "r");

    for(cont=0;cont<3;cont++){
        fread(telefone[cont], sizeof(telefone[cont]), 1, arquivoTelefone);
        printf("O valor do telefone %d �: %s\n", cont+1, telefone[cont]);
    }

    fclose(arquivoTelefone);

}

//Fun��o para pesquisar um nome dentro dos arquivos
//Status: Completo
void pesquisarNomeCompleto(){

    char nome[30];
    getchar();

    //Limpa o vetor
    for(int cont=0;cont<30;cont++){
        nome[cont] = 0;
    }

    printf("Digite um nome de empresa que ser� pesquisado: ");
    gets(nome);

    for(int cont=0;cont<3;cont++){
        for(int cont2=0;cont2<30;cont2++){
            if(nome[cont2] != empresa[cont][cont2]){
                printf("A empresa %d n�o � igual ao valor\n", cont+1);
                break;
            }
            if(cont2 == 29){
                printf("A empresa %d � igual ao valor: %s\n", cont+1, empresa[cont]);
            }
        }
    }

}

//Fun��o para pesquisar a partir de uma letra
//Status: Completo
void pesquisarPrimeiraLetra(){

    char letra;
    int cont;

    printf("Digite uma leta: ");
    getchar();
    letra = getchar();

    for(cont=0;cont<3;cont++){
        if(empresa[cont][0] == letra){
            printf("A empresa %d � igual: %s\n", cont+1, empresa[cont]);
        }
    }

}

//Fun��o para alterar dados
//Status: Completa
void alterarDados(){

    char nome[30];
    getchar();

    //Limpa o vetor
    for(int cont=0;cont<30;cont++){
        nome[cont] = 0;
    }

    printf("Digite um nome de empresa que ser� alterado: ");
    gets(nome);

    arquivoEmpresa = fopen("ArquivoEmpresa.txt", "w");

    for(int cont=0;cont<3;cont++){
        for(int cont2=0;cont2<30;cont2++){
            if(nome[cont2] != empresa[cont][cont2]){
                printf("A empresa %d n�o ser� alterada\n", cont+1);
                break;
            }
            if(cont2 == 29){
                printf("A empresa %d ser� alterada\n", cont+1);
                printf("Digite o novo valor: ");
                gets(empresa[cont]);
            }
        }

        fwrite(empresa[cont], sizeof(empresa[cont]), 1, arquivoEmpresa);
    }

    fclose(arquivoEmpresa);

}

//Fun��o para excluir dados
//Status: Completa
void excluiDados(){

    char nome[30];
    getchar();

    //Limpa o vetor
    for(int cont=0;cont<30;cont++){
        nome[cont] = 0;
    }

    printf("Digite um nome de empresa que ser� excluida: ");
    gets(nome);

    arquivoEmpresa = fopen("ArquivoEmpresa.txt", "w");

    for(int cont=0;cont<3;cont++){
        for(int cont2=0;cont2<30;cont2++){
            if(nome[cont2] != empresa[cont][cont2]){
                printf("A empresa %d n�o ser� excluido\n", cont+1);
                break;
            }
            if(cont2 == 29){
                printf("A empresa %d ser� excluida\n", cont+1);
                for(int cont3=0;cont3<30;cont3++){
                    empresa[cont][cont3] = 0;
                }
            }
        }
        fwrite(empresa[cont], sizeof(empresa[cont]), 1, arquivoEmpresa);
    }

    fclose(arquivoEmpresa);
}

