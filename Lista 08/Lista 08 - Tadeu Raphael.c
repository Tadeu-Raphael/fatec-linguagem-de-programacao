#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Observações: Embora tenha feit a lista sem grandes dificuldades, não sei se fiz corretamente porque achei meio ambiguo quando
//era pedido para passar os dados usando ponteiros. Não sabia se precisava que tudo fosse ponteiro, ou só o que pedia exatamente.

//O exercício 5 e 6 não consegui fazer por ter que fazer calculo com os ponteiros. Estou fazendo algo errado que está travando.

//Exercícios 5 e 6 foram feitos pelo Henrique Berg

#define ex

#ifdef ex1

int main()
{

    setlocale(LC_ALL, "");

    int start;
    char caracter[] = {'b','d','f','h','j','l','m','o','q','s','u','w','y'};

    do{

    printf("\nBem vindo ao programa! Deseja executar? \n");
    printf("1 - Sim\n");
    printf("2 - Não\n");

    scanf("%d%*c", &start);

    if(start==1){

            char *valor;
            printf("Insira um valor, ele será comparado!\n");
            scanf("%c", &valor);

            for(int cont=0;cont<13;cont++){
                if(valor == caracter[cont]){
                    printf("O valor existe!\n");
                    break;
                }
                if(cont==12){
                    printf("O valor não existe!\n");
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
    printf("2 - Não\n");
    scanf("%d%*c", &start);

    if(start==1){

            printf("Digite os valores do nome, endereço, cidade, estado e CEP:\n");

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

            printf("\nNome: %s | Memória: %d\n", lugar1.nome, *lugar1.nome);
            printf("Endereço: %s | Memória: %d\n", lugar1.endereco, *lugar1.endereco);
            printf("Cidade: %s | Memória: %d\n", lugar1.cidade, *lugar1.cidade);
            printf("Estado: %s | Memória: %d\n", lugar1.estado, *lugar1.estado);
            printf("CEP: %i\n", lugar1.cep); //Não estou consigo retornar o valor da memória aqui.

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
                    printf("As strings são diferentes!\n");
                    break;
                }
                if(cont==9){
                    printf("As string são iguais!\n");
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
    printf("2 - Não\n");
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

        printf("Memória: ");
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

void main(){
    while(1){
        int number = 0;
        int sum = 0;
        float average = 0;
        int quantity = 0;
        int *pNumber = &number;

        while(1){
            printf("Digite um numero: ");
            scanf("%d", pNumber);
            if(*pNumber < 0){
                break;
            }
            sum += *pNumber;
            quantity++;
        }
        if(quantity == 0){
            average = 0;
        }
        else{
            average = sum / quantity;
        }

        printf("A media dos numeros e: %.2f\n", average);
        if(endProgram()){
            printf("\nPrograma finalizado. Obrigado.");
            break;
        }
        else{
            getchar();
        }
    }

}

#endif // ex5

#ifdef ex6

int main(){
    while(1){
        struct Date {
            int day;
            int month;
            int year;
        };

        struct Date dates[2];
        struct Date *pDates = &dates;
        long diffInDays = 0;
        long *pDiffInDays = &diffInDays;
        for(int i = 0; i < 2; i++){
            do{
                printf("Digite o %do dia: ", i+1);
                scanf("%d", &pDates[i].day);
            }while(pDates[i].day <= 0 || pDates[i].day > 31);
            do{
                printf("Digite o %do mes: ", i+1);
                scanf("%d", &pDates[i].month);
            }while(pDates[i].month <= 0 || pDates[i].month > 12);
            do{
                printf("Digite o %do ano: ", i+1);
                scanf("%d", &pDates[i].year);
            }while(pDates[i].year <= 0 || pDates[i].year > 3000);
            printf("Data %d: %d/%d/%d \n", i+1, pDates[i].day, pDates[i].month, pDates[i].year);
        }

        if(pDates[0].year > pDates[1].year){
            if(pDates[0].month > pDates[1].month){
                if(pDates[0].day > pDates[1].day) //Ex 1: 20/4/2018 - 10/3/2017 = 405
                {
                    diffInDays += pDates[0].day - pDates[1].day;
                    diffInDays += 30 * (pDates[0].month - pDates[1].month);
                    diffInDays += 365 * (pDates[0].year - pDates[1].year);
                }
                else{
                    if(pDates[0].day < pDates[1].day){ //Ex 2: 10/4/2018 - 20/3/2017 = 385
                        diffInDays += (pDates[0].day + 30) - pDates[1].day;
                        diffInDays += 30 * (pDates[0].month - pDates[1].month - 1);
                        diffInDays += 365 * (pDates[0].year - pDates[1].year);
                    }
                    else{ //Ex 3: 10/4/2018 - 10/3/2017 = 395
                        diffInDays += 30 * (pDates[0].month - pDates[1].month);
                        diffInDays += 365 * (pDates[0].year - pDates[1].year);
                    }
                }
            }
            else{
                if(pDates[0].day > pDates[1].day) //Ex 4: 20/3/2018 - 10/4/2017 = 340
                {
                    diffInDays += pDates[0].day - pDates[1].day;
                    diffInDays += 30 * ((pDates[0].month + 12) - pDates[1].month);
                    diffInDays += 365 * (pDates[0].year - pDates[1].year - 1);
                }
                else{
                    if(pDates[0].day < pDates[1].day){ //Ex 5: 10/3/2018 - 20/4/2017 = 320
                        diffInDays += (pDates[0].day + 30) - pDates[1].day;
                        diffInDays += 30 * ((pDates[0].month + 12) - pDates[1].month - 1);
                        diffInDays += 365 * (pDates[0].year - pDates[1].year - 1);
                    }
                    else{ //Ex 6: 10/3/2018 - 10/4/2017 = 330
                        diffInDays += 30 * ((pDates[0].month + 12) - pDates[1].month);
                        diffInDays += 365 * (pDates[0].year - pDates[1].year - 1);
                    }
                }
            }
        }
        else{
            if(pDates[0].year < pDates[1].year){
                if(pDates[0].month < pDates[1].month){
                    if(pDates[0].day < pDates[1].day) //Ex 7: 10/3/2018 - 20/4/2019 = 405
                    {
                        diffInDays += pDates[1].day - pDates[0].day;
                        diffInDays += 30 * (pDates[1].month - pDates[0].month);
                        diffInDays += 365 * (pDates[1].year - pDates[0].year);
                    }
                    else{
                        if(pDates[0].day > pDates[1].day){ //Ex 8: 20/3/2018 - 10/4/2019 = 385
                            diffInDays += (pDates[1].day + 30) - pDates[0].day;
                            diffInDays += 30 * (pDates[1].month - pDates[0].month - 1);
                            diffInDays += 365 * (pDates[1].year - pDates[0].year);
                        }
                        else{ //Ex 9: 10/3/2018 - 10/4/2019 = 395
                            diffInDays += 30 * (pDates[1].month - pDates[0].month);
                            diffInDays += 365 * (pDates[1].year - pDates[0].year);
                        }
                    }
                }
                else{
                    if(pDates[0].day < pDates[1].day) //Ex 10: 10/4/2017 - 20/3/2018  = 340
                    {
                        diffInDays += pDates[1].day - pDates[0].day;
                        diffInDays += 30 * ((pDates[1].month + 12) - pDates[0].month);
                        diffInDays += 365 * (pDates[1].year - pDates[0].year - 1);
                    }
                    else{
                        if(pDates[0].day > pDates[1].day){ //Ex 11: 20/4/2017 - 10/3/2018 = 320
                            diffInDays += (pDates[1].day + 30) - pDates[0].day;
                            diffInDays += 30 * ((pDates[1].month + 12) - pDates[0].month - 1);
                            diffInDays += 365 * (pDates[1].year - pDates[0].year - 1);
                        }
                        else{ //Ex 12: 10/4/2017 - 10/3/2018 = 330
                            diffInDays += 30 * ((pDates[1].month + 12) - pDates[0].month);
                            diffInDays += 365 * (pDates[1].year - pDates[0].year - 1);
                        }
                    }
                }
            }
            else{
                if(pDates[0].month > pDates[1].month){
                    if(pDates[0].day > pDates[1].day){  // Ex 13: 20/4/2018 - 10/3/2018 = 40
                        diffInDays += pDates[0].day - pDates[1].day;
                        diffInDays += 30 * (pDates[0].month - pDates[1].month);
                    }
                    else{
                        if(pDates[0].day < pDates[1].day){ // Ex 1=4: 10/4/2018 - 20/3/2018 = 20
                            diffInDays += (pDates[0].day + 30) - pDates[1].day;
                            diffInDays += 30 * (pDates[0].month - pDates[1].month - 1);
                        }
                        else{   // Ex 15 : 10/4/2018 - 10/3/2018 = 30
                            diffInDays += 30 * (pDates[0].month - pDates[1].month);
                        }
                    }
                }
                else{
                    if(pDates[0].day < pDates[1].day){ // Ex 16: 20/3/2018 - 10/4/2018 = 20
                        diffInDays += pDates[1].day - pDates[0].day;
                        diffInDays += 30 * (pDates[1].month - pDates[0].month);
                    }
                    else{
                        if(pDates[0].day > pDates[1].day){ // Ex 17: 10/3/2018 - 20/4/2018 = 40
                            diffInDays += (pDates[1].day + 30) - pDates[0].day;
                            diffInDays += 30 * (pDates[1].month - pDates[0].month - 1);
                        }
                        else{    // Ex 18 : 10/3/2018 - 10/4/2018 = 30
                            diffInDays += 30 * (pDates[1].month - pDates[0].month);
                        }
                    }
                }
            }
        }


        printf("Diferenca entre datas em dias: %ld\n", *pDiffInDays);
        if(endProgram()){
            printf("\nPrograma finalizado. Obrigado.");
            break;
        }
        else{
            getchar();
        }
    }
}

#endif // ex6

int endProgram(){
    int exitOption = 0;
    printf("Voce deseja finalizar o programa? Digite 1 para sim e qualquer numero para nao: ");
    scanf("%d", &exitOption);
    return exitOption == 1 ? 1 : 0;
}
