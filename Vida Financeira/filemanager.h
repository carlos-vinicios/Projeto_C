#ifndef FILEMANAGER_H
#define FILEMANAGER_H

int positionById(int id, int size, const char *arq); //retorna a posição do ponteiro do arquivo para o id dado

int lastId(const char *arq); //retorna o último id documento

int update(const char *arq, char *newLine, int lineLen, int id);

int deletar(const char *arq, int id);

#endif // FILEMANAGER_H
