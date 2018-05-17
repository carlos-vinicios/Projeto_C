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

typedef struct Users Usuarios;
const char UsuarioRota[] = "Data\\user_data.txt";

struct Capital {
    int id;
    char data[10];
    char desc[MAX_DESC];
    float valor;
};

struct capitais {
    Capital capital;
    struct capitais *next;
};

typedef struct capitais Capitais;
const char CapitalRota[] = "Data\\capital_data.txt";

#endif // DATA_CONTROL_H
