#ifndef FILEMANAGER_H
#define FILEMANAGER_H

int buscaById(int id, int size, const char *arq); //retorna a posição do ponteiro do arquivo para o id dado

char *Otd(int size, int position, const char *arq); //pega todo o resto do arquivo com após uma dada posição

int lastId(const char *arq); //retorna o último id documento

char *getId(char *linha); //retorna o id da linha

int getReferenceId(char *linha, int inicio, int fim);

void dataCharCol(char *linha, int inicio, int fim, char *campo); //retorna os valores de uma coluna para um certo endereço de char

float getValor(char *linha, int inicio, int fim);

#endif // FILEMANAGER_H
