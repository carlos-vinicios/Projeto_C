#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "datacontrol.h"

int positionById(int Id, int size, const char *arq){ //retorna a posição do ponteiro em um arquivo com base em um id, dado
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
        return 0;//caso o arquivo ainda n?o tenha sido criado
    }
    fseek(data, 0, SEEK_END);
    size = ftell(data);
    rewind(data);
    if(size == 0){
        return 0; //caso o arquivo j? tenha sido criado e esteja vazio
    }
    linha = new char[size];
    c1 = 0;
    while(fgets(linha, size, data) != NULL){ //realiza a contagem de linhas
      c1++;
    }
    c1--; //valor correspondente a última linha
    rewind(data);
    c2 = 0;
    while(fgets(linha, size, data) != NULL){ //percorre novamente o arquivo parando na última linha
      if(c1 == c2){
        break;
      }
      c1++;
    }
    id = atoi(getId(linha)); //recebe o id presente na última linha e converte para int
    return id;
}

int update(const char *arq, char *newLine, int lineLen, int id){
    FILE *data;
    int size, first=1;
    char *newTextFile, *linha;
    data = fopen(arq, "r");
    if(data == NULL){
        return 0;
    }
    fseek(data, 0, SEEK_END);
    size = ftell(data);
    rewind(data);
    newTextFile = new char[size+lineLen];
    linha = new char[size];
    while(!feof(data)){
        fgets(linha, size, data);
        if(linha[0] != '\n'){
            if(atoi(getId(linha)) != id){
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
    data = fopen(arq, "w");
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

int deletar(const char *arq, int id){
    FILE *data;
    int size, first =  1;
    char *linha, *newTextFile;
    data = fopen(arq, "r");
    if(data == NULL){
        return 0;
    }
    fseek(data, 0, SEEK_END);
    size = ftell(data);
    rewind(data);
    newTextFile = new char[size];
    linha = new char[size];
    while(!feof(data)){
        fgets(linha, size, data);
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
    data = fopen(arq, "w");
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
