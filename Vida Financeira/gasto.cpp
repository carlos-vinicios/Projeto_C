#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "datacontrol.h"
#include "filemanager.h"

void writeData(FILE *data, Gasto gasto){
    fprintf(data, "id=%d;", gasto.id);
    fprintf(data, "data=%s;", gasto.data);
    fprintf(data, "desc=%s;", gasto.desc);
    fprintf(data, "valor=%.2f;", gasto.valor);
    fprintf(data, "tipo=%d;", gasto.tipo);
    fprintf(data, "categoria=%d;\n", gasto.categoria);
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
          index++; //garante que v? para o primeiro elemento do dado
          switch (exec) {
            case 1:
                gasto.data = new char[i - index];
                dataCharCol(linha, index, i, gasto.data);
                break;
            case 2:
                gasto.desc = new char[i - index];
                dataCharCol(linha, index, i, gasto.desc);
                break;
            case 3: //pegando o valor
                gasto.valor = dataFloatCol(linha, index, i);
                break;
            case 4:
                gasto.tipo = dataIntCol(linha, index, i);
                break;
            case 5:
                gasto.categoria = dataIntCol(linha, index, i);
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
        return 2;
    }
    if(gasto.valor <= 0){
        return 3;
    }
    if(gasto.tipo < 1 || gasto.tipo > 2){
        return 4;
    }
    if(gasto.categoria < 1 || gasto.categoria > lastId(CategoriaRota)){
        return 5;
    }
    gasto.id = lastId(GastoRota) + 1;
    data = fopen(GastoRota, "a+");
    if(data == NULL){
        return 6;
    }
    writeData(data, gasto);
    fclose(data);
    return 1;
}

int updateGasto(Gasto gasto){
    int lineLen, response;
    char *newLine;
    if(!(strlen(gasto.data) > 0)){
        return 0;
    }
    if(!(strlen(gasto.desc) > 0)){
        return 0;
    }
    if(!(strlen(gasto.data) > 0)){
        return 0;
    }
    if(gasto.valor <= 0){
        return 0;
    }
    if(gasto.tipo < 1 || gasto.tipo > 2){
        return 0;
    }
    if(gasto.categoria < 1 || gasto.categoria > lastId(CategoriaRota)){
        return 0;
    }
    newLine = new char[sizeof(gasto) + 37]; //declara um array de caracteres com o tamanho necessario para armezenar a nova linha
    lineLen = sprintf(newLine, "id=%d;data=%s;desc=%s;valor=%.2f;tipo=%d;categoria=%d;", gasto.id, gasto.data, gasto.desc, gasto.valor, gasto.tipo, gasto.categoria);
    strcat(newLine, "\n");
    response = update(GastoRota, newLine, lineLen, gasto.id);
    if(response)
        return 1;
    return 0;
}

int deleteGasto(int id){ //exclui o Gasto recebido
    int response;
    if(id < 0 || id > lastId(GastoRota))
        return 0;

    response = deletar(GastoRota, id);
    if(response)
        return 1;

    return 0;
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
    position = positionById(id, size, GastoRota);
    if(position < 0){
        gasto.id = -1;
        delete linha;
        return gasto;
    }
    fseek(data, position, SEEK_SET);
    fgets(linha, size, data);
    gasto = gastoDataToStruct(linha);
    delete[] linha;
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
        fgets(linha, size, data);
        gasto = gastoDataToStruct(linha);
        nova = new Gastos();
        nova->gasto = gasto;
        nova->next = NULL;
        if(listGastos->next == NULL){ //se a lista tiver v?zia s? adiciona o item
            listGastos->next = nova;
        }else{ //caso contrario, recebe o valor do prox item, percorre toda a lista at? encontrar o ?ltimo
            temp = listGastos->next;
            while(temp->next != NULL)
                temp = temp->next; //passa para o pr?ximo ponteiro dentro da lista

            temp->next = nova; //o ponteiro est? apontando para a ?ltima posi??o onde ser? colocado o novo
        }
    }
    delete[] linha;
    fclose(data);
    return listGastos;
}

Gastos *listGastosByCategoria(int idCategoria){ //lista os gastos de uma dada categoria
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
    while(fgets(linha, size, data) != NULL){ //pega cada linha transforma em struct Usuario e adiciona na lista de Usuarios
        gasto = gastoDataToStruct(linha);
        if(gasto.categoria == idCategoria){
            nova = new Gastos();
            nova->gasto = gasto;
            nova->next = NULL;
            if(listGastos->next == NULL){ //se a lista tiver v?zia s? adiciona o item
                listGastos->next = nova;
            }else{ //caso contrario, recebe o valor do prox item, percorre toda a lista at? encontrar o ?ltimo
                temp = listGastos->next;
                while(temp->next != NULL)
                    temp = temp->next; //passa para o pr?ximo ponteiro dentro da lista

                temp->next = nova; //o ponteiro est? apontando para a ?ltima posi??o onde ser? colocado o novo
            }
        }
    }
    delete[] linha;
    fclose(data);
    return listGastos;
}

Gastos *filterGastoByMonth(Gastos *listGastos, char *month){ //lista os gastos com base em um mês dado
    Gastos *lista, *nova, *old, *filtered;

    filtered = new Gastos();
    filtered->next = NULL;
    for(lista = listGastos->next; lista != NULL; lista = lista->next){
        if(strstr(lista->gasto.data, month) != NULL){
            nova = new Gastos();
            nova->gasto = lista->gasto;
            nova->next = NULL;
            if(filtered->next == NULL){
                filtered->next = nova;
            }else{
                old = filtered->next;
                while(old->next != NULL)
                    old = old->next; //passa para o pr?ximo ponteiro dentro da lista

                old->next = nova;
            }
        }
    }

    return filtered;
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
                    old = old->next; //passa para o pr?ximo ponteiro dentro da lista

                old->next = nova;
            }
        }
    }
    return filtered;
}

Gastos *filterGastoBetweenValue(Gastos *listGastos, float init_valor, float end_valor){ //lista os recebimentos de Gasto com base em um valor
    Gastos *lista, *filtered, *nova, *old;
    if(end_valor == 0 || end_valor == NULL){ //verifica se o valor final foi passado, caso n?o, seleciona o maior valor da lista para o valor final
        end_valor = 0;
        for(lista = listGastos; lista != NULL; lista = lista->next){
            if(lista->gasto.valor > end_valor){
                end_valor = lista->gasto.valor;
            }
        }
    }
    if(end_valor < init_valor){ //se o valor for menor que o passado, retorna nulo, pois n?o tem como fazer a filtra??o
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
                    old = old->next; //passa para o pr?ximo ponteiro dentro da lista

                old->next = nova;
            }
        }
    }
    return filtered;
}
