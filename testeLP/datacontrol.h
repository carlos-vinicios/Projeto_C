#ifndef DATA_CONTROL_H
#define DATA_CONTROL_H

#define MAX_NOME 60
#define MAX_DESC 200
#define MAX_PASS 20

struct Usuario{
    int id;
    char nome[MAX_NOME];
    char password[MAX_PASS];
    char nasc[10];
    char desc[MAX_DESC];
    float renda;
};

struct Users {
    Usuario user;
    struct Users *next;
};

typedef struct Users Usuarios; //define uma nova estrutura de dados
const char UsuarioRota[] = "Data\\user_data.txt";

struct Capital {
    int id;
    char data[11];
    char desc[MAX_DESC];
    float valor;
    int id_user;
};

struct capitais {
    Capital capital;
    struct capitais *next;
};

typedef struct capitais Capitais; //define uma nova estrutura de dado para lista de recebimento de capitais
const char CapitalRota[] = "Data\\capital_data.txt";

struct Gasto {
    int id;
    char data[11];
    char desc[MAX_DESC];
    float valor;
    int tipo;
    int id_user;
};

struct gastos {
    Gasto gasto;
    struct gastos *next;
};

typedef struct gastos Gastos; //define uma nova estrutura de dado para lista de gastos
const char GastoRota[] = "Data\\gasto_data.txt";

char *getId(char *linha); //retorna o id da linha

int charToTstmp(char *date); //converte uma data em array de char para "timestamp", criado por mim, com base em uma lógica que da certo

int dataIntCol(char *linha, int inicio, int fim);

void dataCharCol(char *linha, int inicio, int fim, char *campo); //retorna os valores de uma coluna para um certo endereço de char

float dataFloatCol(char *linha, int inicio, int fim);

#endif // DATA_CONTROL_H
