#ifndef CAPITAL_H
#define CAPITAL_H

int storeCapital(Capital capital); //salvar as informações de um novo recebimento de capital

int updateCapital(Capital capital); //alteração de informações de um recebimento de capital

int deleteCapital(int id); //exclui o capital recebido

Capital capitalById(int id); //carrega as informações (dados do usuario) para exibição ou edição

Capitais *listAllCapitais(); //lista todos os capitais

Capitais *listByDate(char *data); //lista os recebimentos de capital com base em uma data

Capitais *listByValue(float valor); //lista os recebimentos de capital com base em um valor

#endif // CAPITAL_H
