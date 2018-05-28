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

#endif // DATA_CONTROL_H
