#ifndef DATA_CONTROL_H
#define DATA_CONTROL_H

//#define MAX_NOME 60
//#define MAX_DESC 200
//#define MAX_PASS 20
//#define MAX_DATA 11

typedef struct _usuario_{
    int id;
    char *nome;
    char *nasc;
    char *desc;
    float renda;
    //char *password;
} Usuario;

//struct Users {
//    Usuario user;
//    struct Users *next;
//};

//typedef struct Users Usuarios; //define uma nova estrutura de dados
const char UsuarioRota[] = "Data/user_data.txt";

typedef struct _capital_ {
    int id;
    char *data;
    char *desc;
    float valor;
//    int id_user;
} Capital;

struct _capitais_ {
    Capital capital;
    struct _capitais_ *next;
};

typedef struct _capitais_ Capitais; //define uma nova estrutura de dado para lista de recebimento de capitais
const char CapitalRota[] = "Data/capital_data.txt";

typedef struct _gasto_ {
    int id;
    char *data;
    char *desc;
    float valor;
    int tipo; // 1 - mensal 2 - rotativo
    int categoria; //categoria do gasto
} Gasto;

struct _Gastos_ {
    Gasto gasto;
    struct _Gastos_ *next;
};

typedef struct _Gastos_ Gastos; //define uma nova estrutura de dado para lista de gastos
const char GastoRota[] = "Data/gasto_data.txt";

typedef struct _categoria_ {
    int id;
    char *nome;
    float total;
} Categoria;

struct _Categorias_ {
    Categoria categoria;
    struct _Categorias_ *next;
};

typedef struct _Categorias_ Categorias;
const char CategoriaRota[] = "Data/categoria_data.bat";

typedef struct _investimento_ { //melhora com o tempo essa estrutura de dados para uma melhor experi?ncia do usuario
    int id;
    char *data;
    char *local;
    float valor;
//    int id_user;
} Investimento;

struct _investimentos_ {
    Investimento investimento;
    struct _investimentos_ *next;
};

typedef struct _investimentos_ Investimentos;
const char InvestimentoRota[] = "Data/investimento_data.txt";

char *getId(char *linha); //retorna o id da linha

int charToTstmp(char *date); //converte uma data em array de char para "timestamp", criado por mim, com base em uma l?gica que da certo

int dataIntCol(char *linha, int inicio, int fim);

void dataCharCol(char *linha, int inicio, int fim, char *campo); //retorna os valores de uma coluna para um certo endere?o de char

float dataFloatCol(char *linha, int inicio, int fim);

#endif // DATA_CONTROL_H
