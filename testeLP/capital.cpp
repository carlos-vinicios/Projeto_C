#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "datacontrol.h"
#include "filemanager.h"

using namespace std;

void writeData(FILE *data, Capital capital){
    fprintf(data, "id=%d;", capital.id);
    fprintf(data, "data=%s;", capital.data);
    fprintf(data, "desc=%s;", capital.desc);
    fprintf(data, "valor=%.2f;", capital.valor);
    fprintf(data, "user=%d;", capital.id_user);
}

int charToTstmp(char *date){ //converte uma data em array de char para "timestamp", criado por mim, com base em uma l�gica que da certo
    int tstmp = 0, i, j = 0, exec = 0;
    char dmy[5] = {'\0','\0','\0','\0','\0'}; //precisa iniciar pois causa erro em execu��es subsequentes

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

    return tstmp; //horas totais de dia, m�s e ano da data passada
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
          index++; //garante que v� para o primeiro elemento do dado
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
            case 4:
                capital.id_user = getReferenceId(linha, index, i);
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
    if(capital.id_user > lastId(UsuarioRota)){
        return 0;
    }

    data = fopen(CapitalRota, "a+");
    if(data == NULL){
        return 0;
    }

    capital.id = lastId(CapitalRota) + 1;
    if(capital.id != 1){
        fputc('\n', data);
    }
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
    if(capital.id_user > lastId(UsuarioRota)){
        return 0;
    }

    data = fopen(CapitalRota, "r+");
    if(data == NULL){
        return 0;
    }
    fseek(data, 0, SEEK_END);
    size = ftell(data);

    position = buscaById(capital.id, size, CapitalRota);
    endData = Otd(size, position, CapitalRota); //resto dos registros ap�s o id dado

    if(endData == NULL){ //caso ocorra algum erro no prcocesso de armazenamento dos registros posteriores, retorna erro
        return 0;
    }
    if(position < 0){//n�o encontrou o id no arquivo
        return 0;
    }

    fseek(data, position, SEEK_SET); //move o ponteiro para o inicio da linha contendo o id dado

    writeData(data, capital);
    fputc('\n', data);
    fputs(endData, data);
    delete endData;
    fclose(data); //fecha a conex�o com o arquivo
    return 1;
}


int deleteCapital(int id){ //exclui o capital recebido
    FILE *data;
    int position, size, first =  1;
    char *linha, *newTextFile, *campo;

    data = fopen(CapitalRota, "r");

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

    data = fopen(CapitalRota, "w");

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
    linha = new char[size];
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
    fclose(data);
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
    linha = new char[size];

    listCapitais = new Capitais();
    listCapitais->next = NULL;
    while(!feof(data)){ //pega cada linha transforma em struct Usuario e adiciona na lista de Usuarios
        fgets(linha, size * sizeof(char), data);
        capital = capitalDataToStruct(linha);
        nova = new Capitais();
        nova->capital = capital;
        nova->next = NULL;
        if(listCapitais->next == NULL){ //se a lista tiver v�zia s� adiciona o item
            listCapitais->next = nova;
        }else{ //caso contrario, recebe o valor do prox item, percorre toda a lista at� encontrar o �ltimo
            temp = listCapitais->next;
            while(temp->next != NULL)
                temp = temp->next; //passa para o pr�ximo ponteiro dentro da lista

            temp->next = nova; //o ponteiro est� apontando para a �ltima posi��o onde ser� colocado o novo
        }
    }

    delete linha;
    fclose(data);
    return listCapitais;
}

Capitais *filterCapitalByMonth(Capitais *listCapitais, char *month){ //lista os recebimentos de capital com base em uma data
    Capitais *lista, *before, *after;
    int pos = 0, exec;

    for(lista = listCapitais; lista != NULL; lista = lista->next){
        if(strstr(lista->capital.data, month) == NULL){
            exec = 0;
            do{
                if(exec == 0){
                    lista = listCapitais;
                }else{
                    lista = lista->next;
                }
                if(exec = pos - 1){
                    before = lista;
                }
                exec++;
            }while(exec <= pos);
            after = lista;
            before->next = after;
        }
        pos++;
    }

    return before;
}

Capitais *filterCapitalBetweenDate(Capitais *listCapitais, char *initDate, char *endDate){
    Capitais *lista, *filtered, *nova, *old;
    int inicio, fim;

    inicio = charToTstmp(initDate);
    fim = charToTstmp(endDate);

    if(inicio > fim){ //caso a data final seja menor que a inicial
        return NULL;
    }

    filtered = new Capitais();
    filtered->next = NULL;
    for(lista = listCapitais; lista != NULL; lista = lista->next){
        if(charToTstmp(lista->capital.data) >= inicio && charToTstmp(lista->capital.data) <= fim){
            nova = new Capitais();
            nova->capital = lista->capital;
            nova->next = NULL;
            if(filtered->next == NULL){
                filtered->next = nova;
            }else{
                old = filtered->next;

                while(old->next != NULL)
                    old = old->next; //passa para o pr�ximo ponteiro dentro da lista

                old->next = nova;
            }
        }
    }

    return filtered;
}

Capitais *filterCapitalBetweenValue(Capitais *listCapitais, float init_valor, float end_valor){ //lista os recebimentos de capital com base em um valor
    Capitais *lista, *filtered, *nova, *old;

    if(end_valor == 0 || end_valor == NULL){ //verifica se o valor final foi passado, caso n�o, seleciona o maior valor da lista para o valor final
        end_valor = 0;
        for(lista = listCapitais; lista != NULL; lista = lista->next){
            if(lista->capital.valor > end_valor){
                end_valor = lista->capital.valor;
            }
        }
    }

    if(end_valor < init_valor){ //se o valor for menor que o passado, retorna nulo, pois n�o tem como fazer a filtra��o
        return NULL;
    }

    filtered = new Capitais();
    filtered->next = NULL;
    for(lista = listCapitais; lista != NULL; lista = lista->next){
        if(lista->capital.valor >= init_valor && lista->capital.valor <= end_valor){
            nova = new Capitais();
            nova->capital = lista->capital;
            nova->next = NULL;
            if(filtered->next == NULL){
                filtered->next = nova;
            }else{
                old = filtered->next;

                while(old->next != NULL)
                    old = old->next; //passa para o pr�ximo ponteiro dentro da lista

                old->next = nova;
            }
        }
    }

    return filtered;
}

