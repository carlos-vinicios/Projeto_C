#include "string.h"
#include "stdlib.h"
#include "stdio.h"

char *getId(char *linha){ //retorna o id de uma dada linha
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
        id = new char[2];
        strcpy(id, "0");
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

int dataIntCol(char *linha, int inicio, int fim){ //retorna o id de referencia, caso a linha possua
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

void dataCharCol(char *linha, int inicio, int fim, char *campo){ //retorna o valor de uma coluna para char, recebendo como parametro a referencia da variavel
    int j, c = 0;
    for(j = inicio; j < fim; j++){
        campo[c] = linha[j];
        c++;
    }
    campo[c] = '\0';
    return;
}

float dataFloatCol(char *linha, int inicio, int fim){ //retorna o valor da renda convertido para float
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
