#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "datacontrol.h"
#include "filemanager.h"

void writeData(FILE *data, Investimento investimento){
    fprintf(data, "id=%d;", investimento.id);
    fprintf(data, "data=%s;", investimento.data);
    fprintf(data, "local=%s;", investimento.local);
    fprintf(data, "valor=%.2f;", investimento.valor);
    fprintf(data, "user=%d;", investimento.id_user);
}

Investimento investimentoDataToStruct(char *linha){
    Investimento investimento;
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
              dataCharCol(linha, index, i, investimento.data);
              break;
            case 2:
                dataCharCol(linha, index, i, investimento.local);
                break;
            case 3: //pegando o valor
              investimento.valor = dataFloatCol(linha, index, i);
              break;
            case 4:
                investimento.id_user = dataIntCol(linha, index, i);
                break;
          }
          exec++;
        }
    }
    investimento.id = atoi(getId(linha));
    return investimento;
}

int storeInvestimento(Investimento investimento){
    FILE *data;
    if(!(strlen(investimento.data) > 0)){
        return 0;
    }
    if(!(strlen(investimento.local) > 0)){
        return 0;
    }
    if(!(strlen(investimento.data) > 0)){
        return 0;
    }
    if(investimento.valor <= 0){
        return 0;
    }
    if(investimento.id_user > lastId(UsuarioRota)){
        return 0;
    }
    data = fopen(InvestimentoRota, "a+");
    if(data == NULL){
        return 0;
    }
    investimento.id = lastId(InvestimentoRota) + 1;
    if(investimento.id != 1){
        fputc('\n', data);
    }
    writeData(data, investimento);
    fclose(data);
    return 1;
}

int updateInvestimento(Investimento investimento){
    char *newLine;
    int lineLen, response;
    if(!(strlen(investimento.data) > 0)){
        return 0;
    }
    if(!(strlen(investimento.local) > 0)){
        return 0;
    }
    if(!(strlen(investimento.data) > 0)){
        return 0;
    }
    if(investimento.valor <= 0){
        return 0;
    }
    if(investimento.id_user > lastId(UsuarioRota)){
        return 0;
    }
    newLine = new char[sizeof(investimento) + 32]; //declara um array de caracteres com o tamanho necessario para armezenar a nova linha
    lineLen = sprintf(newLine, "id=%d;data=%s;local=%s;valor=%.2f;user=%d;", investimento.id, investimento.data, investimento.local, investimento.valor, investimento.id_user);
    if(investimento.id < lastId(InvestimentoRota)) //caso não seja o último do array, realiza uma quebra de linha
        strcat(newLine, "\n");

    response = update(InvestimentoRota, newLine, lineLen, investimento.id);
    if(response)
        return 1;

    return 0;
}

int deleteInvestimento(int id){ //exclui o Investimento recebido
    int response;
    if(id < 0 || id > lastId(InvestimentoRota))
        return 0;
    response = deletar(InvestimentoRota, id);
    if(response)
        return 1;
    return 0;
}

Investimento investimentoById(int id){
    FILE *data;
    Investimento investimento;
    int position, size;
    char *linha;
    data = fopen(InvestimentoRota, "r");
    if(data == NULL){
        investimento.id = - 1;
        return investimento;
    }
    fseek(data, 0, SEEK_END);
    size = ftell(data);
    rewind(data);
    linha = new char[size];
    position = positionById(id, size, InvestimentoRota);
    if(position < 0){
        investimento.id = -1;
        delete linha;
        return investimento;
    }
    fseek(data, position, SEEK_SET);
    fgets(linha, size, data);
    investimento = investimentoDataToStruct(linha);
    delete linha;
    fclose(data);
    return investimento;
}

Investimentos *listAllInvestimentos(){
    FILE *data;
    Investimentos *listInvestimentos, *nova, *temp;
    Investimento investimento;
    char *linha;
    int size;
    data = fopen(InvestimentoRota, "r");
    if(data == NULL){
        listInvestimentos = new Investimentos();
        listInvestimentos->next = NULL;
        return listInvestimentos;
    }
    fseek(data, 0, SEEK_END);
    size = ftell(data);
    rewind(data);
    linha = new char[size];
    listInvestimentos = new Investimentos();
    listInvestimentos->next = NULL;
    while(!feof(data)){ //pega cada linha transforma em struct Usuario e adiciona na lista de Usuarios
        fgets(linha, size, data);
        investimento = investimentoDataToStruct(linha);
        nova = new Investimentos();
        nova->investimento = investimento;
        nova->next = NULL;
        if(listInvestimentos->next == NULL){ //se a lista tiver vázia só adiciona o item
            listInvestimentos->next = nova;
        }else{ //caso contrario, recebe o valor do prox item, percorre toda a lista até encontrar o último
            temp = listInvestimentos->next;
            while(temp->next != NULL)
                temp = temp->next; //passa para o próximo ponteiro dentro da lista

            temp->next = nova; //o ponteiro está apontando para a última posição onde será colocado o novo
        }
    }
    delete linha;
    fclose(data);
    return listInvestimentos;
}

Investimentos *filterInvestimentoByMonth(Investimentos *listInvestimentos, char *month){ //lista os recebimentos de Investimento com base em uma data
    Investimentos *lista, *before, *after;
    after = listInvestimentos->next;
    for(lista = listInvestimentos->next; lista != NULL; lista = lista->next){
        before = after;
        if(strstr(lista->investimento.data, month) == NULL){
            after = lista->next;
        }
        before->next = after->next;
    }
    return listInvestimentos;
}

Investimentos *filterInvestimentoBetweenDate(Investimentos *listInvestimentos, char *initDate, char *endDate){
    Investimentos *lista, *filtered, *nova, *old;
    int inicio, fim;
    inicio = charToTstmp(initDate);
    fim = charToTstmp(endDate);
    if(inicio > fim){ //caso a data final seja menor que a inicial
        return NULL;
    }
    filtered = new Investimentos();
    filtered->next = NULL;
    for(lista = listInvestimentos; lista != NULL; lista = lista->next){
        if(charToTstmp(lista->investimento.data) >= inicio && charToTstmp(lista->investimento.data) <= fim){
            nova = new Investimentos();
            nova->investimento = lista->investimento;
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

Investimentos *filterInvestimentoBetweenValue(Investimentos *listInvestimentos, float init_valor, float end_valor){ //lista os recebimentos de Investimento com base em um valor
    Investimentos *lista, *filtered, *nova, *old;
    if(end_valor == 0 || end_valor == NULL){ //verifica se o valor final foi passado, caso não, seleciona o maior valor da lista para o valor final
        end_valor = 0;
        for(lista = listInvestimentos; lista != NULL; lista = lista->next){
            if(lista->investimento.valor > end_valor){
                end_valor = lista->investimento.valor;
            }
        }
    }
    if(end_valor < init_valor){ //se o valor for menor que o passado, retorna nulo, pois não tem como fazer a filtração
        return NULL;
    }
    filtered = new Investimentos();
    filtered->next = NULL;
    for(lista = listInvestimentos; lista != NULL; lista = lista->next){
        if(lista->investimento.valor >= init_valor && lista->investimento.valor <= end_valor){
            nova = new Investimentos();
            nova->investimento = lista->investimento;
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

