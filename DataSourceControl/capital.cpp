#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "datacontrol.h"
#include "filemanager.h"

void writeData(FILE *data, Capital capital){
    fprintf(data, "id=%d;", capital.id);
    fprintf(data, "data=%s;", capital.data);
    fprintf(data, "desc=%s;", capital.desc);
    fprintf(data, "valor=%.2f;", capital.valor);
    fprintf(data, "user=%d;", capital.id_user);
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
              capital.valor = dataFloatCol(linha, index, i);
              break;
            case 4:
                capital.id_user = dataIntCol(linha, index, i);
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
    if(!(strlen(capital.data) > 0)){
        return 0;
    }
    if(capital.valor <= 0){
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
    char *newLine;
    int lineLen, response;
    if(!(strlen(capital.data) > 0)){
        return 0;
    }
    if(!(strlen(capital.desc) > 0)){
        return 0;
    }
    if(!(strlen(capital.data) > 0)){
        return 0;
    }
    if(capital.valor <= 0){
        return 0;
    }
    if(capital.id_user > lastId(UsuarioRota)){
        return 0;
    }
    newLine = new char[sizeof(capital) + 32]; //declara um array de caracteres com o tamanho necessario para armezenar a nova linha
    lineLen = sprintf(newLine, "id=%d;data=%s;desc=%s;valor=%.2f;user=%d;", capital.id, capital.data, capital.desc, capital.valor, capital.id_user);
    if(capital.id < lastId(CapitalRota)) //caso não seja o último do array, realiza uma quebra de linha
        strcat(newLine, "\n");

    response = update(CapitalRota, newLine, lineLen, capital.id);
    if(response)
        return 1;

    return 0;
}

int deleteCapital(int id){ //exclui o capital recebido
    int response;
    if(id < 0 || id > lastId(CapitalRota))
        return 0;
    response = deletar(CapitalRota, id);
    if(response)
        return 1;
    return 0;
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
    position = positionById(id, size, CapitalRota);
    if(position < 0){
        capital.id = -1;
        delete linha;
        return capital;
    }
    fseek(data, position, SEEK_SET);
    fgets(linha, size, data);
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
        fgets(linha, size, data);
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
    delete linha;
    fclose(data);
    return listCapitais;
}

Capitais *filterCapitalByMonth(Capitais *listCapitais, char *month){ //lista os recebimentos de capital com base em uma data
    Capitais *lista, *before, *after;
    after = listCapitais->next;
    for(lista = listCapitais->next; lista != NULL; lista = lista->next){
        before = after;
        if(strstr(lista->capital.data, month) == NULL){
            after = lista->next;
        }
        before->next = after->next;
    }
    return listCapitais;
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
                    old = old->next; //passa para o próximo ponteiro dentro da lista

                old->next = nova;
            }
        }
    }
    return filtered;
}

Capitais *filterCapitalBetweenValue(Capitais *listCapitais, float init_valor, float end_valor){ //lista os recebimentos de capital com base em um valor
    Capitais *lista, *filtered, *nova, *old;
    if(end_valor == 0 || end_valor == NULL){ //verifica se o valor final foi passado, caso não, seleciona o maior valor da lista para o valor final
        end_valor = 0;
        for(lista = listCapitais; lista != NULL; lista = lista->next){
            if(lista->capital.valor > end_valor){
                end_valor = lista->capital.valor;
            }
        }
    }
    if(end_valor < init_valor){ //se o valor for menor que o passado, retorna nulo, pois não tem como fazer a filtração
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
                    old = old->next; //passa para o próximo ponteiro dentro da lista

                old->next = nova;
            }
        }
    }
    return filtered;
}
