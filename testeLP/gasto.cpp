#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "datacontrol.h"
#include "filemanager.h"

using namespace std;

void writeData(FILE *data, Gasto gasto){
    fprintf(data, "id=%d;", gasto.id);
    fprintf(data, "data=%s;", gasto.data);
    fprintf(data, "desc=%s;", gasto.desc);
    fprintf(data, "valor=%.2f;", gasto.valor);
    fprintf(data, "tipo=%d;", gasto.tipo);
    fprintf(data, "user=%d;", gasto.id_user);
}

Gasto gastoDataToStruct(char *linha){
    Gasto gasto;
    int i, index, exec = 0;

    for (i = 0; i < strlen(linha); i++) {
        if(linha[i] == ';'){//procurando pelos campos
          index = i - 1;
          do{
            index--;
          }while(linha[index] != '='); //volta o contador para o primeiro =, significando o inicio do dado
          index++; //garante que vá para o primeiro elemento do dado
          switch (exec) {
            case 1:
                dataCharCol(linha, index, i, gasto.data);
                break;
            case 2:
                dataCharCol(linha, index, i, gasto.desc);
                break;
            case 3: //pegando o valor
                gasto.valor = getValor(linha, index, i);
                break;
            case 4:
                gasto.tipo = getReferenceId(linha, index, i);
            case 5:
                gasto.id_user = getReferenceId(linha, index, i);
                break;
          }
          exec++;
        }
    }
    gasto.id = atoi(getId(linha));

    return gasto;
}

int storeGasto(Gasto gasto){
    FILE *data;
    if(!(strlen(gasto.data) > 0)){
        return 0;
    }
    if(!(strlen(gasto.desc) > 0)){
        return 0;
    }
    if(!(strlen(gasto.data) > 0)){
        return 0;
    }
    if(gasto.tipo < 1 || gasto.tipo > 2){
        return 0;
    }
    if(gasto.id_user > lastId(UsuarioRota)){
        return 0;
    }

    data = fopen(GastoRota, "a+");
    if(data == NULL){
        return 0;
    }

    gasto.id = lastId(GastoRota) + 1;
    if(gasto.id != 1){
        fputc('\n', data);
    }
    writeData(data, gasto);
    if(gasto.id == 1){
        fputc('\n', data);
    }
    fclose(data);
    return 1;
}

int updateGasto(Gasto gasto){
    FILE *data;
    int size, first=1, newLen;
    char *newTextFile, *newLine, *linha;
    if(!(strlen(gasto.data) > 0)){
        return 0;
    }
    if(!(strlen(gasto.desc) > 0)){
        return 0;
    }
    if(!(strlen(gasto.data) > 0)){
        return 0;
    }
    if(gasto.tipo < 1 || gasto.tipo > 2){
        return 0;
    }
    if(gasto.id_user > lastId(UsuarioRota)){
        return 0;
    }
    data = fopen(GastoRota, "r");
    if(data == NULL){
        return 0;
    }
    fseek(data, 0, SEEK_END);
    size = ftell(data);
    rewind(data);
    newLine = new char[sizeof(gasto) + 37]; //declara um array de caracteres com o tamanho necessario para armezenar a nova linha
    newLen = sprintf(newLine, "id=%d;data=%s;desc=%s;valor=%.2f;tipo=%d;user=%d;", gasto.id, gasto.data, gasto.desc, gasto.valor, gasto.tipo, gasto.id_user);
    if(gasto.id < lastId(GastoRota)){ //caso não seja o último do array, realiza uma quebra de linha
        strcat(newLine, "\n");
    }
    newTextFile = new char[size+newLen];
    linha = new char[size];
    while(!feof(data)){
        fgets(linha, size * sizeof(char), data);
        if(linha[0] != '\n'){
            if(atoi(getId(linha)) != gasto.id){
                if(first){
                    strcpy(newTextFile, linha);
                    first = 0;
                }else{
                    strcat(newTextFile, linha);
                }
            }else{
                strcat(newTextFile, newLine);
            }
        }
    }

    fclose(data);

    data = fopen(GastoRota, "w");

    if(data == NULL){
        fclose(data);
        delete newLine;
        delete newTextFile;
        delete linha;
        return 0;
    }

    fputs(newTextFile, data);
    delete newLine;
    delete newTextFile;
    delete linha;
    fclose(data);
    return 1;
}

int deleteGasto(int id){ //exclui o Gasto recebido
    FILE *data;
    int size, first=1;
    char *linha, *newTextFile;

    data = fopen(GastoRota, "r");

    if(data == NULL){
        return 0;
    }

    fseek(data, 0, SEEK_END);
    size = ftell(data);
    rewind(data);

    newTextFile = new char[size];
    linha = new char[size];

    while(!feof(data)){
        fgets(linha, size * sizeof(char), data);
        if(linha[0] != '\n'){
            if(atoi(getId(linha)) != id){
                if(first){
                    strcpy(newTextFile, linha);
                    first = 0;
                }else{
                    strcat(newTextFile, linha);
                }
            }
        }
    }

    fclose(data);

    data = fopen(GastoRota, "w");

    if(data == NULL){
        fclose(data);
        delete newTextFile;
        delete linha;
        return 0;
    }

    fputs(newTextFile, data);

    delete newTextFile;
    delete linha;
    fclose(data);

    return 1;
}

Gasto gastoById(int id){
    FILE *data;
    Gasto gasto;
    int position, size;
    char *linha;
    data = fopen(GastoRota, "r");
    if(data == NULL){
        gasto.id = - 1;
        return gasto;
    }
    fseek(data, 0, SEEK_END);
    size = ftell(data);
    rewind(data);
    linha = new char[size];
    position = buscaById(id, size, GastoRota);
    if(position < 0){
        gasto.id = -1;
        delete linha;
        return gasto;
    }
    fseek(data, position, SEEK_SET);
    fgets(linha, size * sizeof(char), data);
    gasto = gastoDataToStruct(linha);
    delete linha;
    fclose(data);
    return gasto;
}

Gastos *listAllGastos(){
    FILE *data;
    Gastos *listGastos, *nova, *temp;
    Gasto gasto;
    char *linha;
    int size;
    data = fopen(GastoRota, "r");
    if(data == NULL){
        listGastos = new Gastos();
        listGastos->next = NULL;
        return listGastos;
    }
    fseek(data, 0, SEEK_END);
    size = ftell(data);
    rewind(data);
    linha = new char[size];
    listGastos = new Gastos();
    listGastos->next = NULL;
    while(!feof(data)){ //pega cada linha transforma em struct Usuario e adiciona na lista de Usuarios
        fgets(linha, size * sizeof(char), data);
        gasto = gastoDataToStruct(linha);
        nova = new Gastos();
        nova->gasto = gasto;
        nova->next = NULL;
        if(listGastos->next == NULL){ //se a lista tiver vázia só adiciona o item
            listGastos->next = nova;
        }else{ //caso contrario, recebe o valor do prox item, percorre toda a lista até encontrar o último
            temp = listGastos->next;
            while(temp->next != NULL)
                temp = temp->next; //passa para o próximo ponteiro dentro da lista

            temp->next = nova; //o ponteiro está apontando para a última posição onde será colocado o novo
        }
    }
    delete linha;
    fclose(data);
    return listGastos;
}

Gastos *filterGastoByMonth(Gastos *listGastos, char *month){ //lista os recebimentos de Gasto com base em uma data
    Gastos *lista, *before, *after;
    after = listGastos->next;
    for(lista = listGastos->next; lista != NULL; lista = lista->next){
        before = after;
        if(strstr(lista->gasto.data, month) == NULL){
            after = lista->next;
        }
        before->next = after->next;
    }
    return listGastos;
}

Gastos *filterGastoBetweenDate(Gastos *listGastos, char *initDate, char *endDate){
    Gastos *lista, *filtered, *nova, *old;
    int inicio, fim;
    inicio = charToTstmp(initDate);
    fim = charToTstmp(endDate);
    if(inicio > fim){ //caso a data final seja menor que a inicial
        return NULL;
    }
    filtered = new Gastos();
    filtered->next = NULL;
    for(lista = listGastos; lista != NULL; lista = lista->next){
        if(charToTstmp(lista->gasto.data) >= inicio && charToTstmp(lista->gasto.data) <= fim){
            nova = new Gastos();
            nova->gasto = lista->gasto;
            nova->next = NULL;
            if(filtered->next == NULL){
                filtered->next = nova;
            }else{
                old = filtered->next;
                while(old->next != NULL)
                    old = old->next; //passa para o próximo ponteiro dentro da lista

                old->next = nova;
            }
        }
    }
    return filtered;
}

Gastos *filterGastoBetweenValue(Gastos *listGastos, float init_valor, float end_valor){ //lista os recebimentos de Gasto com base em um valor
    Gastos *lista, *filtered, *nova, *old;
    if(end_valor == 0 || end_valor == NULL){ //verifica se o valor final foi passado, caso não, seleciona o maior valor da lista para o valor final
        end_valor = 0;
        for(lista = listGastos; lista != NULL; lista = lista->next){
            if(lista->gasto.valor > end_valor){
                end_valor = lista->gasto.valor;
            }
        }
    }
    if(end_valor < init_valor){ //se o valor for menor que o passado, retorna nulo, pois não tem como fazer a filtração
        return NULL;
    }
    filtered = new Gastos();
    filtered->next = NULL;
    for(lista = listGastos; lista != NULL; lista = lista->next){
        if(lista->gasto.valor >= init_valor && lista->gasto.valor <= end_valor){
            nova = new Gastos();
            nova->gasto = lista->gasto;
            nova->next = NULL;
            if(filtered->next == NULL){
                filtered->next = nova;
            }else{
                old = filtered->next;
                while(old->next != NULL)
                    old = old->next; //passa para o próximo ponteiro dentro da lista

                old->next = nova;
            }
        }
    }
    return filtered;
}
