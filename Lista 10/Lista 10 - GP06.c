#define ex4

#include "stdio.h"
#include "locale.h"
#include "time.h"

#ifdef ex1

//Feita por: Henrique Berg e Tadeu Raphael

/*
OBS.: Todos os programa devem ser finalizados pelo usuario.
1 - Escreva um programa para criar e abrir um arquivo texto de nome "arq.txt".
    Receba via teclado diversos caracteres (um por vezes) e armazene-os
    nesse arquivo. O caracter '0' finaliza a entrada de dados. Abra o arquivo
    "arq.txt", leia e imprima na tela todos os caracteres armazenados no
    arquivo (um por vezes).
*/
main(){
    FILE *p;
    char c;
    int count = 0;
    int sizeOfFile = 0;
    if((p = fopen("arq.txt", "w")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    while(1){
        printf("Digite um caractere: ");
        c = getchar();
        if(c == '0'){
            fclose(p);
            break;
        }
        putc(c, p);
        count++;
        getchar();
    }

    if((p = fopen("arq.txt","r"))==NULL)
	{
        printf("erro na abertura do arquivo \n");
        exit(0);
	}

	char result[count];
    fscanf(p,"%s ",result);
    printf("%s", result);
}
#endif // ex1

#ifdef ex2
/*
2 - Escreva um programa para gerenciar uma agenda de contatos. Para cada contato
    armazene o nome, o telefone e o aniversario (dia e mes) em uma estrutura de
    dados. Utilize um vetor de estrutura de 4 elementos como variavel local na
    funcao main(). Utilize ponteiros para passar o vetor de estrutura para
    as funcoes. Sempre que o programa for encerrado, os contatos devem ser
    escritos no arquivo e quando o programa iniciar os contatos devem ser lidos
    do arquivo.
    O programa deve ter as seguintes opcoes:(cada opcao e' um funcao)
    1 - inserir contato
    2 - altera contato
    3 - exclui contato
    4 - pesquisar um contato pelo nome
    5 - listar todos os contatos
    6 - listar os contatos cujo nome inicia com uma letra digitada
    7 - imprimir os aniversariantes do mês.
    8 - saida
*/
struct Contact{
    char name[64];
    char phone[15];
    int birthDay;
    int birthMonth;
    };

FILE *p;
main(){



     struct Contact contact;

    int menuOption = 0;
    while(1){
        printf("1 - Inserir contato | 2 - Alterar contato | 3 - Deletar contato | 4 - Procurar contato pelo nome | 5 - Listar todos os contatos | 6 - Listar contatos que comecam com a letra | 7 - Listar aniversariantes do mes | 8 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &menuOption);
        switch(menuOption){
            case 1:
                insertContact(&contact);
                break;
            case 2:
                updateContact(&contact);
            case 3:
                deleteContact(&contact);
                break;
            case 4:
                getContactByName(&contact);
                break;
            case 5:
                getContacts(&contact);
                break;
            case 6:
                getContactsByInitial(&contact);
                break;
            case 7:
                getBirthdayPeopleOfTheMonth(&contact);
                break;
            case 8:
                break;
            default:
                printf("Desculpe, nao entendi.\n\n");
                break;
        }
        if(menuOption == 8){
            break;
        }
    }
}
void insertContact(struct Contact *contact){
    if((p = fopen("contacts.txt", "a")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    getchar();
    printf("Digite o nome do contato: ");
    gets(contact->name);
    printf("Digite o telefone do contato: ");
    gets(contact->phone);
    printf("Digite o mes do nascimento do contato: ");
    scanf("%d", &contact->birthMonth);
    printf("Digite o dia do nascimento do contato: ");
    scanf("%d", &contact->birthDay);
    fwrite(contact, sizeof(struct Contact), 1, p);
    fclose(p);
}

void updateContact(struct Contact *contact){
    if((p = fopen("contacts.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    char name[64];
    int result;
    int i = 0;
    printf("Digite o nome do contato: ");
    scanf("%s", &name);
    while(fread(contact, sizeof(struct Contact), 1, p)){
        result = areEqual(&name, contact->name);
        if(result == 1){
            *contact->name = '\0';
            fseek(p, sizeof(struct Contact) * i, 0);
            fwrite(contact, sizeof(struct Contact), 1, p);
            break;
        }
        i++;
    }
    getchar();
    printf("Digite o novo nome do contato: ");
    gets(contact->name);
    printf("Digite o novo telefone do contato: ");
    gets(contact->phone);
    printf("Digite o novo  mes do nascimento do contato: ");
    scanf("%d", &contact->birthMonth);
    printf("Digite o novo dia do nascimento do contato: ");
    scanf("%d", &contact->birthDay);
    fwrite(contact, sizeof(struct Contact), 1, p);

    if(result != 1){
        printf("Usuario nao encontrado\n");
    }
    fclose(p);
}

void deleteContact(struct Contact *contact){
    if((p = fopen("contacts.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    char name[64];
    int result;
    int i = 0;
    printf("Digite o nome do contato: ");
    scanf("%s", &name);
    while(fread(contact, sizeof(struct Contact), 1, p)){
        result = areEqual(&name, contact->name);
        if(result == 1){
            *contact->name = '\0';
            fseek(p, sizeof(struct Contact) * i, 0);
            fwrite(contact, sizeof(struct Contact), 1, p);
            break;
        }
        i++;
    }
    if(result != 1){
        printf("Usuario nao encontrado\n");
    }
    fclose(p);
}

void getContactByName(struct Contact *contact){
    if((p = fopen("contacts.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    char name[64];
    int result;
    printf("Digite o nome do contato: ");
    scanf("%s", &name);
    while(fread(contact, sizeof(struct Contact), 1, p)){
        result = areEqual(&name, contact->name);
        if(result == 1){
            printf("%s, %s, %d/%d \n", contact->name, contact->phone, contact->birthDay, contact->birthMonth);
            break;
        }
    }
    if(result != 1){
        printf("Usuario nao encontrado\n");
    }
    fclose(p);
}
void getContacts(struct Contact *contact){
    if((p = fopen("contacts.txt", "r")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    while(fread(contact, sizeof(struct Contact), 1, p)){
        if(*contact->name != '\0'){
            printf("%s, %s, %d/%d \n", contact->name, contact->phone, contact->birthDay, contact->birthMonth);
        }
    }
    fclose(p);
}

void getContactsByInitial(struct Contact *contact){
    if((p = fopen("contacts.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    char initial;
    int result;
    printf("Digite uma letra: ");
    scanf("%s", &initial);
    while(fread(contact, sizeof(struct Contact), 1, p)){
        result = contact->name[0] == initial ? 1 : 0;
        if(result == 1){
            printf("%s, %s, %d/%d \n", contact->name, contact->phone, contact->birthDay, contact->birthMonth);
        }
    }
    if(result != 1){
        printf("Usuario nao encontrado\n");
    }
    fclose(p);
}
void getBirthdayPeopleOfTheMonth(struct Contact *contact){
    time_t s, val = 1;
    struct tm* current_time;
    s = time(NULL);
    current_time = localtime(&s);
    int result;
    if((p = fopen("contacts.txt", "r")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }

    while(fread(contact, sizeof(struct Contact), 1, p)){
        result = contact->birthMonth == current_time->tm_mon + 1 ? 1 : 0;
        if(result == 1){
            printf("%s, %s, %d/%d \n", contact->name, contact->phone, contact->birthDay, contact->birthMonth);
        }
    }

    if(result != 1){
        printf("Usuario nao encontrado\n");
    }
    fclose(p);
}

int areEqual(char *firstString, char *secondString){
    int result = 0;
    int i = 0;
    for(i; firstString[i] != '\0' ||secondString[i] != '\0'; i++){
        if(firstString[i] != secondString[i]){
            result = 4;
            if(firstString[i] == '\0' && secondString[i] != '\0'){
                result = 3;
                break;
            }
            else{
                if(firstString[i] != '\0' && secondString[i] == '\0'){
                    result = 2;
                    break;
                }
            }
        }
        else{
            result = 1;
        }
    }
    return result;
}

#endif // ex2

#ifdef ex3
/*
3 - Escreva um programa para o controle de mercadorias em uma despensa
    domestica. Para cada produto sera' armazenado um codigo numerico, nome
    do produto e quantidade atual numa estrutura de dados. A unica estrutura
    de dados deve ser declarada como variavel local na funcao main(). Escreva
    os itens das mercadorias direto no arquivo. (utilize a funcao fseek quando
    necessario). Nao pode usar vetor de estruturas. Utilize ponteiros.
    O programa deve ter as seguintes opcoes: (cada opcao e' um funcao)
    1 - inclui produtos
    2 - altera produtos
    3 - exclui produtos
    4 - pesquisar uma mercadoria pela descrição
    5 - listar todos os produtos
    6 - listar os produtos não disponíveis.
    7 - alterar a quantidade atual
    8 - saida
*/
struct Product{
    int code;
    char description[255];
    int quantity;
};

FILE *p;
main(){
    struct Product product;
    int menuOption = 0;
    while(1){
        printf("1 - Inserir produto | 2 - Alterar produto | 3 - Retirar produto | 4 - Procurar produto pela descricao | 5 - Listar todos os produtos | 6 - Listar produtos nao disponiveis | 7 - Alterar produto | 8 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &menuOption);
        switch(menuOption){
            case 1:
                insertProduct(&product);
                break;
            case 2:
                updateProduct(&product);
            case 3:
                removeProduct(&product);
                break;
            case 4:
                getProductByDescription(&product);
                break;
            case 5:
                getProducts(&product);
                break;
            case 6:
                getUnavailableProducts(&product);
                break;
            case 7:
                changeQuantityProduct(&product);
            case 8:
                break;
            default:
                printf("Desculpe, nao entendi.\n\n");
                break;
        }
        if(menuOption == 9){
            break;
        }
    }
}
void insertProduct(struct Product *product){
    if((p = fopen("products.txt", "a")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    getchar();
    printf("Digite o codigo do produto: ");
    scanf("%d", &product->code);
    getchar();
    printf("Digite a descricao do produto: ");
    gets(product->description);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &product->quantity);
    fwrite(product, sizeof(struct Product), 1, p);
    fclose(p);
}

void updateProduct(struct Product *product){
    if((p = fopen("products.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    int code = 0;
    int quantity = 0;
    int result, result2;
    int i = 0;
    printf("Digite o codigo do produto: ");
    scanf("%d", &code);
    printf("Digite quanto quer alterar: ");
    scanf("%d", &quantity);

    while(fread(product, sizeof(struct Product), 1, p)){
        result = code == product->code ? 1 : 0;
        if(result == 1){
            result2 = product->quantity >= quantity ? 1 : 0;
            if(result2)
            {
                product->quantity -= quantity;
                fseek(p, sizeof(struct Product) * i, 0);
                fwrite(product, sizeof(struct Product), 1, p);
                break;
            }
            else{
                printf("Você não tem essa quantidade desse produto\n");
            }
        }
        i++;
    }
    getchar();
    printf("Digite qual será o  codigo do produto: ");
    scanf("%d", &product->code);
    getchar();
    printf("Digite qual será a descricao do produto: ");
    gets(product->description);
    printf("Digite qual será a quantidade do produto: ");
    scanf("%d", &product->quantity);
    fwrite(product, sizeof(struct Product), 1, p);


    if(result != 1 && result2 != 0){
        printf("Produto nao encontrado\n");
    }
    fclose(p);
}

void removeProduct(struct Product *product){
    if((p = fopen("products.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    int code = 0;
    int quantity = 0;
    int result, result2;
    int i = 0;
    printf("Digite o codigo do produto: ");
    scanf("%d", &code);
    printf("Digite quanto quer retirar: ");
    scanf("%d", &quantity);

    while(fread(product, sizeof(struct Product), 1, p)){
        result = code == product->code ? 1 : 0;
        if(result == 1){
            result2 = product->quantity >= quantity ? 1 : 0;
            if(result2)
            {
                product->quantity -= quantity;
                fseek(p, sizeof(struct Product) * i, 0);
                fwrite(product, sizeof(struct Product), 1, p);
                break;
            }
            else{
                printf("Você não tem essa quantidade desse produto\n");
            }
        }
        i++;
    }
    if(result != 1 && result2 != 0){
        printf("Produto nao encontrado\n");
    }
    fclose(p);
}

void getProductByDescription(struct Product *product){
    if((p = fopen("products.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    char description[64];
    int result;
    printf("Digite a descrição do produto: ");
    scanf("%s", &description);
    while(fread(product, sizeof(struct Product), 1, p)){
        result = areEqual(&description, product->description);
        if(result == 1){
            printf("%d, %s, %d \n", product->code, product->description, product->quantity);
            break;
        }
    }
    if(result != 1){
        printf("Produto nao encontrado\n");
    }
    fclose(p);
}
void getProducts(struct Product *product){
    if((p = fopen("products.txt", "r")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    while(fread(product, sizeof(struct Product), 1, p)){
        printf("%d, %s, %d \n", product->code, product->description, product->quantity);
    }
    fclose(p);
}

void getUnavailableProducts(struct Product *product){
    if((p = fopen("products.txt", "r")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    while(fread(product, sizeof(struct Product), 1, p)){
        if(product->quantity == 0){
            printf("%d, %s, %d \n", product->code, product->description, product->quantity);
        }
    }
    fclose(p);
}

void changeQuantityProduct(struct Product *product){
    if((p = fopen("products.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    int code = 0;
    int quantity = 0;
    int result, result2;
    int i = 0;
    printf("Digite o codigo do produto: ");
    scanf("%d", &code);
    printf("Digite quanto quer alterar: ");
    scanf("%d", &quantity);

    while(fread(product, sizeof(struct Product), 1, p)){
        result = code == product->code ? 1 : 0;
        if(result == 1){
            result2 = product->quantity >= quantity ? 1 : 0;
            if(result2)
            {
                product->quantity -= quantity;
                fseek(p, sizeof(struct Product) * i, 0);
                fwrite(product, sizeof(struct Product), 1, p);
                break;
            }
            else{
                printf("Você não tem essa quantidade desse produto\n");
            }
        }
        i++;
    }
    getchar();
    printf("Digite qual será a quantidade do produto: ");
    scanf("%d", &product->quantity);
    fwrite(product, sizeof(struct Product), 1, p);


    if(result != 1 && result2 != 0){
        printf("Produto nao encontrado\n");
    }
    fclose(p);
}


int areEqual(char *firstString, char *secondString){
    int result = 0;
    int i = 0;
    for(i; firstString[i] != '\0' ||secondString[i] != '\0'; i++){
        if(firstString[i] != secondString[i]){
            result = 4;
            if(firstString[i] == '\0' && secondString[i] != '\0'){
                result = 3;
                break;
            }
            else{
                if(firstString[i] != '\0' && secondString[i] == '\0'){
                    result = 2;
                    break;
                }
            }
        }
        else{
            result = 1;
        }
    }
    return result;
}

#endif // ex3

#ifdef ex4
/*
4 - Escreva um programa para contrle de um cadastro de clientes. Para cada
    registro sera' armazenado nome, end, cidade, estado, cep numa estrutura
    de dados. A unica estrutura de dados e' uma variavel local na funcao main().
    Escreva os registros direto no arquivo. (utilize a funcao fseek quando
    necessario). Nao pode usar vetor de estruturas. Utilize ponteiros.
    O programa deve ter as seguintes opcoes: (cada opcao e' um funcao)
    1 - inclui registros
    2 - listar todos os registros
    3 - pesquisar registro pelo nome
    4 - altera registro
    5 - exclui registro
    6 - saida
*/

struct User{
    char name[64];
    char address[255];
    char city[64];
    char state[64];
    char zipCode[64];
    };
FILE *p;
main(){

    struct User user;
    int menuOption = 0;

    while(1){
        printf("1 - Inserir usuario | 2 - Listar usuarios | 3 - Procurar usuario | 4 - Alterar usuario | 5 - Deletar usuario | 6 - Sair\n");        printf("Escolha uma opcao: ");
        scanf("%d", &menuOption);
        switch(menuOption){
            case 1:
                insertUser(&user);
                break;
            case 2:
                getUsers(&user);
                break;
            case 3:
                getUserByName(&user);
                break;
            case 4:
                updateUser(&user);
                break;
            case 5:
                removeUser(&user);
                break;
            case 6:
                break;
            default:
                printf("Desculpe, nao entendi.\n\n");
                break;
        }
        if(menuOption == 9){
            break;
        }
    }
}
void insertUser(struct User *user){
    if((p = fopen("users.txt", "a")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    getchar();
    printf("Digite o nome do usuario: ");
    gets(user->name);
    printf("Digite o endereco do usuario: ");
    gets(user->address);
    printf("Digite a cidade do usuario: ");
    gets(user->city);
    printf("Digite o estado do usuario: ");
    gets(user->state);
    printf("Digite o CEP do usuario: ");
    gets(user->zipCode);
    fwrite(user, sizeof(struct User), 1, p);
    fclose(p);
}

void removeUser(struct User *user){
    if((p = fopen("users.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    char name[64];
    int result;
    int i = 0;
    printf("Digite o nome do usuario: ");
    scanf("%s", &name);

    while(fread(user, sizeof(struct User), 1, p)){
        result = areEqual(&name, user->name);
        if(result == 1){
            *user->name = '\0';
            fseek(p, sizeof(struct User) * i, 0);
            fwrite(user, sizeof(struct User), 1, p);
            break;
        }
        i++;
    }
    if(result != 1){
        printf("Usuario nao encontrado\n");
    }
    fclose(p);
}


void updateUser(struct User *user){
    if((p = fopen("users.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    char name[64];
    int result;
    int i = 0;
    printf("Digite o nome do usuario: ");
    scanf("%s", &name);

    while(fread(user, sizeof(struct User), 1, p)){
        result = areEqual(&name, user->name);
        if(result == 1){
            printf("Alterando usuario...\n");
            getchar();
            printf("Digite o nome do usuario: ");
            gets(user->name);
            printf("Digite o endereco do usuario: ");
            gets(user->address);
            printf("Digite a cidade do usuario: ");
            gets(user->city);
            printf("Digite o estado do usuario: ");
            gets(user->state);
            printf("Digite o CEP do usuario: ");
            gets(user->zipCode);
            fseek(p, sizeof(struct User) * i, 0);
            fwrite(user, sizeof(struct User), 1, p);
            break;
        }
        i++;
    }
    if(result != 1){
        printf("Usuario nao encontrado\n");
    }
    fclose(p);
}

void getUserByName(struct User *user){
    if((p = fopen("users.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    char name[64];
    int result;
    printf("Digite a descrição do produto: ");
    scanf("%s", &name);
    while(fread(user, sizeof(struct User), 1, p)){
        result = areEqual(&name, user->name);
        if(result == 1){
            printf("%s, %s, %s, %s, %s \n", user->name, user->address, user->city, user->state, user->zipCode);
            break;
        }
    }
    if(result != 1){
        printf("Produto nao encontrado\n");
    }
    fclose(p);
}
void getUsers(struct User *user){
    if((p = fopen("users.txt", "r")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    while(fread(user, sizeof(struct User), 1, p)){
        if(user->name[0] != '\0'){
            printf("%s, %s, %s, %s, %s \n", user->name, user->address, user->city, user->state, user->zipCode);
        }
    }
    fclose(p);
}

int areEqual(char *firstString, char *secondString){
    int result = 0;
    int i = 0;
    for(i; firstString[i] != '\0' ||secondString[i] != '\0'; i++){
        if(firstString[i] != secondString[i]){
            result = 4;
            if(firstString[i] == '\0' && secondString[i] != '\0'){
                result = 3;
                break;
            }
            else{
                if(firstString[i] != '\0' && secondString[i] == '\0'){
                    result = 2;
                    break;
                }
            }
        }
        else{
            result = 1;
        }
    }
    return result;
}
#endif // ex4

int endProgram(){
    int exitOption = 0;
    printf("Voce deseja finalizar o programa? Digite 1 para sim e qualquer numero para nao: ");
    scanf("%d", &exitOption);
    return exitOption == 1 ? 1 : 0;
}
