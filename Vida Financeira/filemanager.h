#ifndef FILEMANAGER_H
#define FILEMANAGER_H

int positionById(int id, int size, const char *arq); //retorna a posi��o do ponteiro do arquivo para o id dado

int lastId(const char *arq); //retorna o �ltimo id documento

int update(const char *arq, char *newLine, int lineLen, int id);

int deletar(const char *arq, int id);

#endif // FILEMANAGER_H
