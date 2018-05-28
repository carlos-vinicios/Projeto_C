#ifndef FILEMANAGER_H
#define FILEMANAGER_H

int buscaById(int id, int size, const char *arq); //retorna a posi��o do ponteiro do arquivo para o id dado

int lastId(const char *arq); //retorna o �ltimo id documento

char *getId(char *linha); //retorna o id da linha

int charToTstmp(char *date); //converte uma data em array de char para "timestamp", criado por mim, com base em uma l�gica que da certo

int getReferenceId(char *linha, int inicio, int fim);

void dataCharCol(char *linha, int inicio, int fim, char *campo); //retorna os valores de uma coluna para um certo endere�o de char

float getValor(char *linha, int inicio, int fim);

#endif // FILEMANAGER_H
