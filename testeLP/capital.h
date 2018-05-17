#ifndef CAPITAL_H
#define CAPITAL_H

int storeCapital(Capital capital); //salvar as informa��es de um novo recebimento de capital

int updateCapital(Capital capital); //altera��o de informa��es de um recebimento de capital

int deleteCapital(int id); //exclui o capital recebido

Capital capitalById(int id); //carrega as informa��es (dados do usuario) para exibi��o ou edi��o

Capitais *listAllCapitais(); //lista todos os capitais

Capitais *listByDate(char *data); //lista os recebimentos de capital com base em uma data

Capitais *listByValue(float valor); //lista os recebimentos de capital com base em um valor

#endif // CAPITAL_H
