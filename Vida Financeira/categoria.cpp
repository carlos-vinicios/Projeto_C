#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "datacontrol.h"
#include "filemanager.h"
#include "gasto.h"

void writeData(FILE *data, Categoria categoria){
    fprintf(data, "id=%d;", categoria.id);
    fprintf(data, "nome=%s;\n", categoria.nome);
}

Categoria categoriaDataToStruct(char *linha){
    Categoria categoria;
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
              categoria.nome = new char[i - index];
              dataCharCol(linha, index, i, categoria.nome);
              break;
          }
          exec++;
        }
    }
    categoria.id = atoi(getId(linha));
    return categoria;
}

int storeCategoria(Categoria categoria){
    FILE *data;
    if(!(strlen(categoria.nome) > 0))
        return 0;

    data = fopen(CategoriaRota, "a+");
    if(data == NULL)
        return 2;

    categoria.id = lastId(CategoriaRota) + 1;
    writeData(data, categoria);
    fclose(data);
    return 1;
}

int updateCategoria(Categoria categoria){
    char *newLine;
    int lineLen, response;
    if(!(strlen(categoria.nome) > 0))
        return 0;

    newLine = new char[sizeof(categoria) + 32]; //declara um array de caracteres com o tamanho necessario para armezenar a nova linha
    lineLen = sprintf(newLine, "id=%d;nome=%s;\n", categoria.id, categoria.nome);

    response = update(CategoriaRota, newLine, lineLen, categoria.id);
    if(response)
        return 1;

    return 4;
}

int deleteCategoria(int id){ //exclui a Categoria recebido
    int response;
    if(id < 0 || id > lastId(CategoriaRota))
        return 0;
    response = deletar(CategoriaRota, id);
    if(response)
        return 1;
    return 0;
}

Categoria categoriaById(int id){
    FILE *data;
    Categoria categoria;
    int position, size;
    char *linha;
    data = fopen(CategoriaRota, "r");
    if(data == NULL){
        categoria.id = - 1;
        return categoria;
    }
    fseek(data, 0, SEEK_END);
    size = ftell(data);
    rewind(data);
    linha = new char[size];
    position = positionById(id, size, CategoriaRota);
    if(position < 0){
        categoria.id = -1;
        delete linha;
        return categoria;
    }
    fseek(data, position, SEEK_SET);
    fgets(linha, size, data);
    categoria = categoriaDataToStruct(linha);
    delete linha;
    fclose(data);
    return categoria;
}

Categorias *listAllCategorias(){
    FILE *data;
    Categorias *listCategorias, *nova, *temp;
    Categoria categoria;
    char *linha;
    int size;
    data = fopen(CategoriaRota, "r");
    if(data == NULL){
        listCategorias = new Categorias();
        listCategorias->next = NULL;
        return listCategorias;
    }
    fseek(data, 0, SEEK_END);
    size = ftell(data);
    rewind(data);
    linha = new char[size];
    listCategorias = new Categorias();
    listCategorias->next = NULL;
    while(fgets(linha, size, data) != NULL){ //pega cada linha transforma em struct Usuario e adiciona na lista de Usuarios
        categoria = categoriaDataToStruct(linha);
        nova = new Categorias();
        nova->categoria = categoria;
        nova->next = NULL;
        if(listCategorias->next == NULL){ //se a lista tiver vázia só adiciona o item
            listCategorias->next = nova;
        }else{ //caso contrario, recebe o valor do prox item, percorre toda a lista até encontrar o último
            temp = listCategorias->next;
            while(temp->next != NULL)
                temp = temp->next; //passa para o próximo ponteiro dentro da lista

            temp->next = nova; //o ponteiro está apontando para a última posição onde será colocado o novo
        }
    }
    delete linha;
    fclose(data);
    return listCategorias;
}
