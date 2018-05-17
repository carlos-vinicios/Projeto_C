#ifndef USER_H
#define USER_H

int storeUser(Usuario user); //salvar as informações de um novo usuario

int updateUser(Usuario user); //alteração de informações do perfil

Usuario userById(int id); //carrega as informações (dados do usuario) para exibição ou edição

Usuarios *listAllUsers(); //lista todos os capitais

#endif // USER_H
