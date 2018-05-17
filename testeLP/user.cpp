#include <iostream>
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "datacontrol.h"
#include "filemanager.h"

using namespace std;

void writeData(FILE *data, Usuario user){
    fprintf(data, "id=%d;", user.id);
    fprintf(data, "nome=%s;", user.nome);
    fprintf(data, "password=%s;", user.password);
    fprintf(data, "nasc=%s;", user.nasc);
    fprintf(data, "desc=%s;", user.desc);
    fprintf(data, "renda=%.2f;", user.renda);
    fputc('\n', data);
}

Usuario userDataToStruct(char *linha){
    Usuario user;
    int i, j, index, exec = 0;

    for (i = 0; i < strlen(linha); i++) {
        if(linha[i] == ';'){//procurando pelos campos
          index = i - 1;
          do{
            index--;
          }while(linha[index] != '='); //volta o contador para o primeiro =, significando o inicio do dado
          index++; //garante que vá para o primeiro elemento do dado
          switch (exec) {
            case 1:
              dataCharCol(linha, index, i, user.nome);
              break;
            case 2:
                dataCharCol(linha, index, i, user.password);
                break;
            case 3: //achando o valor da data de nascimento
              dataCharCol(linha, index, i, user.nasc);
              break;
            case 4: //achando o valor da descrição
              dataCharCol(linha, index, i, user.desc);
              break;
            case 5: //pegando o valor da renda
              user.renda = getValor(linha, index, i);
              break;
          }
          exec++;
        }
    }
    user.id = atoi(getId(linha));

    return user;
}


int storeUser(Usuario user){
    FILE *data;
    if(!(strlen(user.nome) > 0)){
        return 0;
    }
    if(!(strlen(user.password) > 0)){
        return 0;
    }
    if(!(strlen(user.nasc) > 0)){
        return 0;
    }
    if(!(strlen(user.desc) > 0)){
        return 0;
    }
    if(user.renda < 0){
        return 0;
    }

    data = fopen(UsuarioRota, "a+");

    if(data == NULL){ //erro na criação do arquivo ou abertura do arquivo
        return 0;
    }

    user.id = lastId(UsuarioRota) + 1;
    writeData(data, user);

    fclose(data); //fecha a conexão com o arquivo
    return 1;
}

int updateUser(Usuario user){
    FILE *data;
    int position, size;
    char *endData;
    if(user.id < (1 || lastId(UsuarioRota))){
        return 0;
    }
    if(!(strlen(user.nome) > 0)){
        return 0;
    }
    if(!(strlen(user.password) > 0)){
        return 0;
    }
    if(!(strlen(user.nasc) > 0)){
        return 0;
    }
    if(!(strlen(user.desc) > 0)){
        return 0;
    }
    if(user.renda < 0){
        return 0;
    }

    data = fopen(UsuarioRota, "r+");

    if(data == NULL){ //erro na criação do arquivo ou abertura do arquivo
        return 0;
    }

    fseek(data, 0, SEEK_END);
    size = ftell(data); //tamanho total do documento

    position = buscaById(user.id, size, UsuarioRota);
    endData = Otd(size, position, UsuarioRota); //resto dos registros após o id dado

    if(endData == NULL){ //caso ocorra algum erro no prcocesso de armazenamento dos registros posteriores, retorna erro
        return 0;
    }
    if(position < 0){//não encontrou o id no arquivo
        return 0;
    }

    fseek(data, position, SEEK_SET); //move o ponteiro para o inicio da linha contendo o id dado

    writeData(data, user);
    fputs(endData, data);
    delete endData;
    fclose(data); //fecha a conexão com o arquivo
    return 1;
}

Usuarios *listAllUsers(){
    FILE *data;
    Usuarios *listUsers, *nova, *temp;
    Usuario user;
    char *linha;
    int size;

    data = fopen(UsuarioRota, "r");
    if(data == NULL){
        listUsers = new Usuarios();
        listUsers->next = NULL;
        return listUsers;
    }
    fseek(data, 0, SEEK_END);
    size = ftell(data);
    rewind(data);
    linha = new char[size * sizeof(char)];

    listUsers = new Usuarios();
    listUsers->next = NULL;
    while(!feof(data)){ //pega cada linha transforma em struct Usuario e adiciona na lista de Usuarios
        fgets(linha, size * sizeof(char), data);
        user = userDataToStruct(linha);
        nova = new Usuarios();
        nova->user = user;
        nova->next = NULL;
        if(listUsers->next == NULL){ //se a lista tiver vázia só adiciona o item
            listUsers->next = nova;
        }else{ //caso contrario, recebe o valor do prox item, percorre toda a lista até encontrar o último
            temp = listUsers->next;
            while(temp->next != NULL)
                temp = temp->next; //passa para o próximo ponteiro dentro da lista

            temp->next = nova; //o ponteiro está apontando para a última posição onde será colocado o novo
        }
    }

    return listUsers;
};

Usuario userById(int id){
    FILE *data;
    Usuario user;
    int position, size;
    char *linha;

    data = fopen(UsuarioRota, "r");

    if(data == NULL){
        user.id = - 1;
        return user;
    }

    fseek(data, 0, SEEK_END);
    size = ftell(data);
    rewind(data);
    linha = new char[size * sizeof(char)];
    position = buscaById(id, size, UsuarioRota);

    if(position < 0){
        user.id = -1;
        delete linha;
        return user;
    }

    fseek(data, position, SEEK_SET);
    fgets(linha, size * sizeof(char), data);

    user = userDataToStruct(linha);

    delete linha;
    return user;
}
