#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "datacontrol.h"
#include "filemanager.h"

void writeData(FILE *data, Usuario user){
    fprintf(data, "id=%d;", user.id);
    fprintf(data, "nome=%s;", user.nome);
    fprintf(data, "nasc=%s;", user.nasc);
    fprintf(data, "desc=%s;", user.desc);
    fprintf(data, "renda=%.2f;\n", user.renda);
}

Usuario userDataToStruct(char *linha){
    Usuario user;
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
              user.nome = new char[i - index];
              dataCharCol(linha, index, i, user.nome);
              break;
            //case 2:
                //dataCharCol(linha, index, i, user.password);
                //break;
            case 2: //achando o valor da data de nascimento
              user.nasc = new char[i - index];
              dataCharCol(linha, index, i, user.nasc);
              break;
            case 3: //achando o valor da descrição
              user.desc = new char[i - index];
              dataCharCol(linha, index, i, user.desc);
              break;
            case 4: //pegando o valor da renda
              user.renda = dataFloatCol(linha, index, i);
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
    if(!(strlen(user.nasc) > 0)){
        return 2;
    }
    if(!(strlen(user.desc) > 0)){
        return 3;
    }
    if(user.renda <= 0){
        return 4;
    }
    data = fopen(UsuarioRota, "a+");
    if(data == NULL){ //erro na criação do arquivo ou abertura do arquivo
        system("mkdir \"Data\"");
        data = fopen(UsuarioRota, "a+");
        if(data == NULL){
            return 5;
        }
    }
    user.id = lastId(UsuarioRota) + 1;
    writeData(data, user);
    fclose(data); //fecha a conexão com o arquivo
    return 1;
}

int updateUser(Usuario user){
    int lineLen, response;
    char *newLine;
    if(user.id < (1 || lastId(UsuarioRota))){
        return 0;
    }
    if(!(strlen(user.nome) > 0)){
        return 2;
    }
    if(!(strlen(user.nasc) > 0)){
        return 3;
    }
    if(!(strlen(user.desc) > 0)){
        return 4;
    }
    if(user.renda < 0){
        return 5;
    }
    newLine = new char[sizeof(user) + 29]; //declara um array de caracteres com o tamanho necessario para armezenar a nova linha
    lineLen = sprintf(newLine, "id=%d;nome=%s;nasc=%s;desc=%s;renda=%.2f;", user.id, user.nome, user.nasc, user.desc, user.renda);
    if(user.id < lastId(UsuarioRota)) //caso não seja o último do array, realiza uma quebra de linha
        strcat(newLine, "\n");

    response = update(UsuarioRota, newLine, lineLen, user.id);
    if(response)
        return 1;

    return 6;
}

Usuario userRegistrado(){
    FILE *data;
    Usuario user;
    int size;
    char *linha;
    data = fopen(UsuarioRota, "r");
    if(data == NULL){
        user.id = -1;
        return user;
    }
    fseek(data, 0, SEEK_END);
    size = ftell(data);
    rewind(data);
    linha = new char[size];
    fgets(linha, size, data);
    user = userDataToStruct(linha);
    delete linha;
    return user;
}

//Usuarios *listAllUsers(){
//    FILE *data;
//    Usuarios *listUsers, *nova, *temp;
//    Usuario user;
//    char *linha;
//    int size;
//    data = fopen(UsuarioRota, "r");
//    if(data == NULL){
//        listUsers = new Usuarios();
//        listUsers->next = NULL;
//        return listUsers; //lista vazia
//    }
//    fseek(data, 0, SEEK_END);
//    size = ftell(data);
//    rewind(data);
//    linha = new char[size];
//    listUsers = new Usuarios();
//    listUsers->next = NULL;
//    while(!feof(data)){ //pega cada linha transforma em struct Usuario e adiciona na lista de Usuarios
//        fgets(linha, size * sizeof(char), data);
//        user = userDataToStruct(linha);
//        nova = new Usuarios();
//        nova->user = user;
//        nova->next = NULL;
//        if(listUsers->next == NULL){ //se a lista tiver vázia só adiciona o item
//            listUsers->next = nova;
//        }else{ //caso contrario, recebe o valor do prox item, percorre toda a lista até encontrar o último
//            temp = listUsers->next;
//            while(temp->next != NULL)
//                temp = temp->next; //passa para o próximo ponteiro dentro da lista

//            temp->next = nova; //o ponteiro está apontando para a última posição onde será colocado o novo
//        }
//    }
//    delete linha;
//    return listUsers;
//};
