#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Desafio 01 - Grupo 06
//Alunos: Tadeu Raphael & Henrique Berg

//Observa��es: Ap�s diversas tentativas em tentar manipular a matriz dentro de um unico arquivo, e falhando v�rias vezes, decidimos
//             passar tudo para arquivos diferentes, dessa forma conseguiamos, ler sem ter problemas.

//Problemas atuais: N�o estou conseguindo manipular tudo de dentro de s� 1 arquivo. A leitura acaba lendo s� o primeiro elemento dos
//                  vetores inseridos. Outro problema recente que descobre � na hora de fazer as compara��es entre uma String e um buffer
//                  retornado do fread

//Modifica��es: Em vez de usar 1 arquivo, estou usando um para cada valor. No exerc�cio 3 e 4 estou fazendo algo mais simples.

// --------------- Vari�veis globais --------------------------

//Cria��o das 2 matrizes
char empresa[3][30];
char telefone[3][12];

// --------------- Declara��o das Fun��es Globais -------------

//Fun��o que escreve os dados
//Status: Completa
void escreverDados(char empresa[3][30],
                   char telefone[3][12],
                   FILE *arquivoEmpresa1,
                   FILE *arquivoEmpresa2,
                   FILE *arquivoEmpresa3,
                   FILE *arquivoTelefone1,
                   FILE *arquivoTelefone2,
                   FILE *arquivoTelefone3);

//Fun��o que lista todos os dados dos arquivos (PRINCIPAL DIFICULDADE PARA MANTER TUDO EM UM ARQUIVO)
//Status: Completa
void listarDados(char empresa[3][30],
                 char telefone[3][12],
                 FILE *arquivoEmpresa1,
                 FILE *arquivoEmpresa2,
                 FILE *arquivoEmpresa3,
                 FILE *arquivoTelefone1,
                 FILE *arquivoTelefone2,
                 FILE *arquivoTelefone3);

//Fun��o para pesquisar a partir de um nome dado
//Status: Problema na compara��o de dados
void pesquisarNomeCompleto(FILE *arquivoEmpresa1,
                           FILE *arquivoEmpresa2,
                           FILE *arquivoEmpresa3);

//Fun��o para pesquisar a partir da primeira letra
//Status: Problema na compara��o de dados
void pesquisarPrimeiraLetra(FILE *arquivoEmpresa1,
                           FILE *arquivoEmpresa2,
                           FILE *arquivoEmpresa3);

//Fun��o para alterar dados
//Status: Completa
void alterarDados(FILE *arquivoEmpresa1,
                 FILE *arquivoEmpresa2,
                 FILE *arquivoEmpresa3,
                 FILE *arquivoTelefone1,
                 FILE *arquivoTelefone2,
                 FILE *arquivoTelefone3);

//Fun��o para excluir dados
//Status: Completa
void excluiDados(FILE *arquivoEmpresa1,
                 FILE *arquivoEmpresa2,
                 FILE *arquivoEmpresa3,
                 FILE *arquivoTelefone1,
                 FILE *arquivoTelefone2,
                 FILE *arquivoTelefone3);

//Fun��o Main()
int main()
{

    setlocale(LC_ALL,"");

    FILE *arquivoEmpresa1, *arquivoEmpresa2, *arquivoEmpresa3;
    FILE *arquivoTelefone1, *arquivoTelefone2, *arquivoTelefone3;

    int valor;

    do{

        printf("\n\nDigite a sua op��o\n");
        printf("1 > Entrada de Dados\n");
        printf("2 > Lista todos os dados na tela\n");
        printf("3 > Pesquisa uma empresa com o nome completo e mostra na tela\n");
        printf("4 > Pesquisa as empresas pela 1a letra e mostra todos na tela\n");
        printf("5 > Altera dados\n");
        printf("6 > Exclui dados\n");
        printf("7 > Sa�da\n\n");

        scanf("%d", &valor);

        switch(valor){

            case 1:
                escreverDados(empresa,
                              telefone,
                              arquivoEmpresa1,
                              arquivoEmpresa2,
                              arquivoEmpresa3,
                              arquivoTelefone1,
                              arquivoTelefone2,
                              arquivoTelefone3);
            break;

            case 2:
                listarDados(empresa,
                            telefone,
                            arquivoEmpresa1,
                            arquivoEmpresa2,
                            arquivoEmpresa3,
                            arquivoTelefone1,
                            arquivoTelefone2,
                            arquivoTelefone3);
            break;

            case 3:
                pesquisarNomeCompleto(arquivoEmpresa1,
                                      arquivoEmpresa2,
                                      arquivoEmpresa3);
            break;

            case 4:
                pesquisarPrimeiraLetra(arquivoEmpresa1,
                                       arquivoEmpresa2,
                                       arquivoEmpresa3);
            break;

            case 5:
                alterarDados(arquivoEmpresa1,
                             arquivoEmpresa2,
                             arquivoEmpresa3,
                             arquivoTelefone1,
                             arquivoTelefone2,
                             arquivoTelefone3);
            break;

            case 6:
                excluiDados(arquivoEmpresa1,
                             arquivoEmpresa2,
                             arquivoEmpresa3,
                             arquivoTelefone1,
                             arquivoTelefone2,
                             arquivoTelefone3);
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
void escreverDados(char empresa[3][30],
                   char telefone[3][12],
                   FILE *arquivoEmpresa1,
                   FILE *arquivoEmpresa2,
                   FILE *arquivoEmpresa3,
                   FILE *arquivoTelefone1,
                   FILE *arquivoTelefone2,
                   FILE *arquivoTelefone3){

    int cont;

    //Abrindo arquivos de Empresa
    arquivoEmpresa1 = fopen("ArquivoEmpresa1.txt", "w");
    arquivoEmpresa2 = fopen("ArquivoEmpresa2.txt", "w");
    arquivoEmpresa3 = fopen("ArquivoEmpresa3.txt", "w");

    //Abrindo arquivos de Telefone
    arquivoTelefone1 = fopen("ArquivoTelefone1.txt", "w");
    arquivoTelefone2 = fopen("ArquivoTelefone2.txt", "w");
    arquivoTelefone3 = fopen("ArquivoTelefone3.txt", "w");

    //Digitando nomes empresas
    for(cont=0;cont<3;cont++){
        printf("Nome da empresa %d: ", cont);
        scanf("%s", &empresa[cont]);
    }

    //Digitando telefones
    for(cont=0;cont<3;cont++){
        printf("Telefone %d: ", cont);
        scanf("%s", &telefone[cont]);
    }

    //Escrevendo valores de empresas nos arquivos
    fwrite(empresa[0], sizeof(char), 20, arquivoEmpresa1);
    fwrite(empresa[1], sizeof(char), 20, arquivoEmpresa2);
    fwrite(empresa[2], sizeof(char), 20, arquivoEmpresa3);

    //Escrevendo valores de telefones nos arquivos
    fwrite(telefone[0], sizeof(char), 12, arquivoTelefone1);
    fwrite(telefone[1], sizeof(char), 12, arquivoTelefone2);
    fwrite(telefone[2], sizeof(char), 12, arquivoTelefone3);

    //Fechando arquivos de empresas
    fclose(arquivoEmpresa1);
    fclose(arquivoEmpresa2);
    fclose(arquivoEmpresa3);

    //Fechando arquivos de telefones
    fclose(arquivoTelefone1);
    fclose(arquivoTelefone2);
    fclose(arquivoTelefone3);

}

//Fun��o que lista todos os dados dos arquivos (PRINCIPAL DIFICULDADE PARA MANTER TUDO EM UM ARQUIVO)
//Status: Completa
void listarDados(char empresa[3][30],
                 char telefone[3][12],
                 FILE *arquivoEmpresa1,
                 FILE *arquivoEmpresa2,
                 FILE *arquivoEmpresa3,
                 FILE *arquivoTelefone1,
                 FILE *arquivoTelefone2,
                 FILE *arquivoTelefone3){

    int cont;
    char buffer1[3][30], buffer2[3][12];

    arquivoEmpresa1 = fopen("ArquivoEmpresa1.txt","r");
    arquivoEmpresa2 = fopen("ArquivoEmpresa2.txt","r");
    arquivoEmpresa3 = fopen("ArquivoEmpresa3.txt","r");

    fseek(arquivoEmpresa1,0, SEEK_SET);
    fseek(arquivoEmpresa2,0, SEEK_SET);
    fseek(arquivoEmpresa3,0, SEEK_SET);

    fread(buffer1[0],sizeof(char),30,arquivoEmpresa1);
    fread(buffer1[1],sizeof(char),30,arquivoEmpresa2);
    fread(buffer1[2],sizeof(char),30,arquivoEmpresa3);

    printf("Empresas: %s, %s, %s\n", buffer1[0], buffer1[1], buffer1[2]);

    arquivoTelefone1 = fopen("ArquivoTelefone1.txt", "r");
    arquivoTelefone2 = fopen("ArquivoTelefone2.txt", "r");
    arquivoTelefone3 = fopen("ArquivoTelefone3.txt", "r");

    fseek(arquivoTelefone1,0, SEEK_SET);
    fseek(arquivoTelefone2,0, SEEK_SET);
    fseek(arquivoTelefone3,0, SEEK_SET);

    fread(buffer2[0],sizeof(char),30,arquivoTelefone1);
    fread(buffer2[1],sizeof(char),30,arquivoTelefone2);
    fread(buffer2[2],sizeof(char),30,arquivoTelefone3);

    printf("Telefones: %s, %s, %s\n", buffer2[0], buffer2[1], buffer2[2]);

    fclose(arquivoEmpresa1);
    fclose(arquivoEmpresa2);
    fclose(arquivoEmpresa3);

    fclose(arquivoTelefone1);
    fclose(arquivoTelefone2);
    fclose(arquivoTelefone3);

}

//Fun��o para pesquisar a partir de um nome dado (Problema na compara��o dos dados quando valor sai da fread()
//Status: Problema na compara��o de dados (abandonado)
/*
void pesquisarNomeCompleto(FILE *arquivoEmpresa1,
                           FILE *arquivoEmpresa2,
                           FILE *arquivoEmpresa3){

    char nomeCompleto[30];
    int cont, comparacao;

    printf("Digite o nome completo: ");
    scanf("%s", &nomeCompleto);

    for(cont=0;cont<3;cont++){
        comparacao = strcmp(nomeCompleto, empresa[cont]);
        if(comparacao == 0){
            printf("Empresa: %s | Estava no arquivo 1", empresa[cont]);
        }
    }

    if(comparacao != 0){
            printf("N�o encontrado");
    }

}
*/

//Fun��o para pesquisar um nome dentro dos arquivos
//Status: Completo, por�m precisa ser alimentado pelo primeiro Item para funcionar
void pesquisarNomeCompleto(FILE *arquivoEmpresa1,
                           FILE *arquivoEmpresa2,
                           FILE *arquivoEmpresa3){

    int escolha;
    char valor[30];

    printf("Voc� est� procurando por?\n");
    printf("1 > Empresa\n");
    printf("2 > Telefone\n");
    scanf("%d", &escolha);

    if(escolha == 1){
        printf("Qual indice voc� quer saber?\n");
        escolha = 0;
        scanf("%d", &escolha);
        printf("Essa � a empresa: %s", empresa[escolha-1]);
    }

    if(escolha == 2){
        printf("Qual indice voc� quer saber?");
        escolha = 0;
        scanf("%d", &escolha);
        printf("Esse � o n�mero: %s", empresa[escolha-1]);
    }

}

//Fun��o para pesquisar a partir de uma letra
//Status: Funcionando, por�m precisa ser alimentado pelo primeiro Item
void pesquisarPrimeiraLetra(FILE *arquivoEmpresa1,
                           FILE *arquivoEmpresa2,
                           FILE *arquivoEmpresa3){

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
void alterarDados(FILE *arquivoEmpresa1,
                 FILE *arquivoEmpresa2,
                 FILE *arquivoEmpresa3,
                 FILE *arquivoTelefone1,
                 FILE *arquivoTelefone2,
                 FILE *arquivoTelefone3){

    int escolha;
    char valor[30];

    printf("Voc� quer editar uma empresa ou telefone?\n");
    printf("1 > Empresa\n");
    printf("2 > Telefone\n");
    scanf("%d", &escolha);

    if(escolha == 1){
        printf("Qual indice voc� quer alterar?\n");
        escolha = 0;
        scanf("%d", &escolha);
        printf("Digite o novo valor:\n");
        scanf("%s", &valor);

        switch(escolha){

            case 1:
                arquivoEmpresa1 = fopen("ArquivoEmpresa1.txt","w");
                fwrite(valor, sizeof(char), 30, arquivoEmpresa1);
                printf("Indice 1 editado com sucesso!\n");
                fclose(arquivoEmpresa1);
                break;

            case 2:
                arquivoEmpresa2 = fopen("ArquivoEmpresa2.txt","w");
                fwrite(valor, sizeof(char), 30, arquivoEmpresa2);
                printf("Indice 2 editado com sucesso!\n");
                fclose(arquivoEmpresa2);
                break;

            case 3:
                arquivoEmpresa3 = fopen("ArquivoEmpresa3.txt","w");
                fwrite(valor, sizeof(char), 30, arquivoEmpresa3);
                printf("Indice 3 editado com sucesso!\n");
                fclose(arquivoEmpresa3);
                break;
        }
    }

    if(escolha == 2){
        printf("Qual indice voc� quer editar?");
        escolha = 0;
        scanf("%d", &escolha);
        printf("Digite o novo valor:\n");
        scanf("%s", &valor);

        switch(escolha){

            case 1:
                arquivoTelefone1 = fopen("arquivoTelefone1.txt","w");
                fwrite(valor, sizeof(char), 20, arquivoTelefone1);
                printf("Indice 1 editar com sucesso!\n");
                fclose(arquivoTelefone1);
                break;

            case 2:
                arquivoTelefone2 = fopen("arquivoTelefone2.txt","w");
                fwrite(valor, sizeof(char), 20, arquivoTelefone2);
                printf("Indice 2 editar com sucesso!\n");
                fclose(arquivoTelefone2);
                break;

            case 3:
                arquivoTelefone3 = fopen("arquivoTelefone3.txt","w");
                fwrite(valor, sizeof(char), 20, arquivoTelefone3);
                printf("Indice 3 editar com sucesso!\n");
                fclose(arquivoTelefone3);
                break;
        }
    }

}

//Fun��o para excluir dados
//Status: Completa
void excluiDados(FILE *arquivoEmpresa1,
                 FILE *arquivoEmpresa2,
                 FILE *arquivoEmpresa3,
                 FILE *arquivoTelefone1,
                 FILE *arquivoTelefone2,
                 FILE *arquivoTelefone3){

    int escolha;

    printf("Voc� quer deletar uma empresa ou telefone?\n");
    printf("1 > Empresa\n");
    printf("2 > Telefone\n");
    do{
    scanf("%d", &escolha);
    }while(escolha != 1 && escolha != 2);

    if(escolha == 1){
        printf("Qual indice voc� quer deletar?");
        escolha = 0;
        scanf("%d", &escolha);

        switch(escolha){

            case 1:
                arquivoEmpresa1 = fopen("ArquivoEmpresa1.txt","w");
                fwrite(" ", sizeof(char), 20, arquivoEmpresa1);
                printf("Indice 1 exluido com sucesso!\n");
                fclose(arquivoEmpresa1);
                break;

            case 2:
                arquivoEmpresa2 = fopen("ArquivoEmpresa2.txt","w");
                fwrite(" ", sizeof(char), 20, arquivoEmpresa2);
                printf("Indice 2 exluido com sucesso!\n");
                fclose(arquivoEmpresa2);
                break;

            case 3:
                arquivoEmpresa3 = fopen("ArquivoEmpresa3.txt","w");
                fwrite(" ", sizeof(char), 20, arquivoEmpresa3);
                printf("Indice 3 exluido com sucesso!\n");
                fclose(arquivoEmpresa3);
                break;
        }
    }

    if(escolha == 2){
        printf("Qual indice voc� quer deletar?");
        escolha = 0;
        scanf("%d", &escolha);

        switch(escolha){

            case 1:
                arquivoTelefone1 = fopen("arquivoTelefone1.txt","w");
                fwrite(" ", sizeof(char), 20, arquivoTelefone1);
                printf("Indice 1 exluido com sucesso!\n");
                fclose(arquivoTelefone1);
                break;

            case 2:
                arquivoTelefone2 = fopen("arquivoTelefone2.txt","w");
                fwrite(" ", sizeof(char), 20, arquivoTelefone2);
                printf("Indice 2 exluido com sucesso!\n");
                fclose(arquivoTelefone2);
                break;

            case 3:
                arquivoTelefone3 = fopen("arquivoTelefone3.txt","w");
                fwrite(" ", sizeof(char), 20, arquivoTelefone3);
                printf("Indice 3 exluido com sucesso!\n");
                fclose(arquivoTelefone3);
                break;
        }
    }

}

