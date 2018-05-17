#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "datacontrol.h"
#include "filemanager.h"

using namespace std;

void writeData(FILE *data, Capital capital){
    fprintf(data, "id=%d;", capital.id);
    fprintf(data, "data=%s;", capital.data);
    fprintf(data, "desc=%s;", capital.desc);
    fprintf(data, "valor=%.2f;", capital.valor);
    fputc('\n', data);
}

Capital capitalDataToStruct(char *linha){
    Capital capital;
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
              dataCharCol(linha, index, i, capital.data);
              break;
            case 2:
                dataCharCol(linha, index, i, capital.desc);
                break;
            case 3: //pegando o valor
              capital.valor = getValor(linha, index, i);
              break;
          }
          exec++;
        }
    }
    capital.id = atoi(getId(linha));

    return capital;
}

int storeCapital(Capital capital){
    FILE *data;
    if(!(strlen(capital.data) > 0)){
        return 0;
    }
    if(!(strlen(capital.desc) > 0)){
        return 0;
    }
    if(capital.data < 0){
        return 0;
    }

    data = fopen(CapitalRota, "a+");
    if(data == NULL){
        return 0;
    }

    capital.id = lastId(CapitalRota) + 1;
    writeData(data, capital);
    fclose(data);
    return 1;
}

int updateCapital(Capital capital){
    FILE *data;
    int size, position;
    char *endData;
    if(!(strlen(capital.data) > 0)){
        return 0;
    }
    if(!(strlen(capital.desc) > 0)){
        return 0;
    }
    if(capital.data < 0){
        return 0;
    }

    data = fopen(CapitalRota, "a+");
    if(data == NULL){
        return 0;
    }
    fseek(data, 0, SEEK_END);
    size = ftell(data);

    position = buscaById(capital.id, size, CapitalRota);
    endData = Otd(size, position, CapitalRota); //resto dos registros após o id dado

    if(endData == NULL){ //caso ocorra algum erro no prcocesso de armazenamento dos registros posteriores, retorna erro
        return 0;
    }
    if(position < 0){//não encontrou o id no arquivo
        return 0;
    }

    fseek(data, position, SEEK_SET); //move o ponteiro para o inicio da linha contendo o id dado

    writeData(data, capital);
    fputs(endData, data);
    delete endData;
    fclose(data); //fecha a conexão com o arquivo
    return 1;
}
//
//int deleteCapital(int id); //exclui o capital recebido
//

Capital capitalById(int id){
    FILE *data;
    Capital capital;
    int position, size;
    char *linha;

    data = fopen(CapitalRota, "r");

    if(data == NULL){
        capital.id = - 1;
        return capital;
    }

    fseek(data, 0, SEEK_END);
    size = ftell(data);
    rewind(data);
    linha = new char[size * sizeof(char)];
    position = buscaById(id, size, CapitalRota);

    if(position < 0){
        capital.id = -1;
        delete linha;
        return capital;
    }

    fseek(data, position, SEEK_SET);
    fgets(linha, size * sizeof(char), data);

    capital = capitalDataToStruct(linha);

    delete linha;
    return capital;
}

Capitais *listAllCapitais(){
    FILE *data;
    Capitais *listCapitais, *nova, *temp;
    Capital capital;
    char *linha;
    int size;

    data = fopen(CapitalRota, "r");
    if(data == NULL){
        listCapitais = new Capitais();
        listCapitais->next = NULL;
        return listCapitais;
    }
    fseek(data, 0, SEEK_END);
    size = ftell(data);
    rewind(data);
    linha = new char[size * sizeof(char)];

    listCapitais = new Capitais();
    listCapitais->next = NULL;
    while(!feof(data)){ //pega cada linha transforma em struct Usuario e adiciona na lista de Usuarios
        fgets(linha, size * sizeof(char), data);
        capital = capitalDataToStruct(linha);
        nova = new Capitais();
        nova->capital = capital;
        nova->next = NULL;
        if(listCapitais->next == NULL){ //se a lista tiver vázia só adiciona o item
            listCapitais->next = nova;
        }else{ //caso contrario, recebe o valor do prox item, percorre toda a lista até encontrar o último
            temp = listCapitais->next;
            while(temp->next != NULL)
                temp = temp->next; //passa para o próximo ponteiro dentro da lista

            temp->next = nova; //o ponteiro está apontando para a última posição onde será colocado o novo
        }
    }

    return listCapitais;
}
//
//Capitais *listByDate(char *data); //lista os recebimentos de capital com base em uma data
//
//Capitais *listByValue(float valor); //lista os recebimentos de capital com base em um valor

