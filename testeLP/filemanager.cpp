#include <iostream>
#include <string.h>
#include "stdlib.h"
#include "stdio.h"

using namespace std;

char *getId(char *linha){
    int i, j, k, index;
    char *id;

    for (i = 0; i < strlen(linha); i++) {
        if(linha[i] == '='){ //quando acha o primeiro igual da linha
            for (j = i; j < strlen(linha); j++) {
                if(linha[j] == ';'){ //vizualiza o primeiro ; marcador de final de valor
                    id = new char[(j-i-1)];
                    index = 0;
                    for (k = i+1; k < j; k++) {
                        id[index] = linha[k];
                        index++;
                    }
                    break;
                }
            }
            break;
        }
    }

    if(id == NULL){ //se não inicializar significa que não achou id algum
        id = new char[1];
        id = "0";
        return id;
    }

    return id;
}

int charToTstmp(char *date){ //converte uma data em array de char para "timestamp", criado por mim, com base em uma lógica que da certo
    int tstmp = 0, i, j = 0, exec = 0;
    char dmy[5] = {'\0','\0','\0','\0','\0'}; //precisa iniciar pois causa erro em execuções subsequentes

    for(i = 0; i < strlen(date); i++){
        if(date[i] != '/'){ //se for diferente do separador, copia para a variavel de auxilio
            dmy[j] = date[i];
            j++;
        }else{
            exec++;
            j = 0;
            switch(exec){
                case 1: //dia
                    tstmp+= atoi(dmy) * 24; //horas de um dia
                    break;
                case 2: //mes
                    tstmp+= atoi(dmy) * 24 * 30; //horas de um mes
                    break;
            }
        }
    }
    tstmp+= atoi(dmy) * 24 * 30 * 12; //horas do um ano

    return tstmp; //horas totais de dia, mês e ano da data passada
}

int getReferenceId(char *linha, int inicio, int fim){
    char *valor;
    int c = 0, i;
    int id;

    valor = new char[fim-inicio+1];
    for(i = inicio; i < fim; i++){
        valor[c] = linha[i];
        c++;
    }

    id = atoi(valor);
    delete valor;
    return id;
}

int buscaById(int Id, int size, const char *arq){
    FILE *data;
    char *linha, *id;
    int position;

    if(size <= 0){
        return 0;
    }

    if(Id <= 0){
        return 0;
    }

    data = fopen(arq, "a+");
    if(data == NULL){ //erro na criação do arquivo ou abertura do arquivo
        return 0;
    }

    rewind(data);
    linha = new char[size];

    while (!feof(data)){
        position = ftell(data);
        fgets(linha, size * sizeof(char), data);
        id = getId(linha); //pega o id de cada linha
        if( atoi(id) == Id ){ //realiza a comparação de valores pegando, transformando o id para char *
            delete linha;
            delete id;
            fclose(data);
            return position;
        }
    }
    delete linha;
    delete id;
    fclose(data);
    return -1;
}

int lastId(const char *arq){ //retorna o útlimo id registrado no arquivo
    FILE *data;
    int id, size, c1, c2;
    char *linha;

    data = fopen(arq, "r");
    if(data == NULL){
        return -1;
    }

    fseek(data, 0, SEEK_END);
    size = ftell(data);
    rewind(data);

    if(size == 0){
        return 0;
    }

    linha = new char[size];

    c1 = 0;
    while(!feof(data)){ //realiza a contagem de linhas
      fgets(linha, size * sizeof(char), data);
      c1++;
    }
    c1--; //valor correspondente a última linha
    rewind(data);

    c2 = 0;
    while(!feof(data)){ //percorre novamente o arquivo parando na última linha
      fgets(linha, size * sizeof(char), data);
      if(c1 == c2){
        break;
      }
      c1++;
    }

    id = atoi(getId(linha)); //recebe o id presente na última linha e converte para int

    return id;
}

void dataCharCol(char *linha, int inicio, int fim, char *campo){
    int j, c = 0;

    for(j = inicio; j < fim; j++){
        campo[c] = linha[j];
        c++;
    }
    campo[c] = '\0';
    return;
}

float getValor(char *linha, int inicio, int fim){ //retorna o valor da renda convertido para float
    char *valor;
    int c = 0, i;
    float valorF;

    valor = new char[fim-inicio+1];
    for(i = inicio; i < fim; i++){
        valor[c] = linha[i];
        c++;
    }

    valorF = strtof(valor, NULL);
    delete valor;
    return valorF;
}
