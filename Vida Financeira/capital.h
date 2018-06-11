#ifndef CAPITAL_H
#define CAPITAL_H

int storeCapital(Capital capital); //salvar as informações de um novo recebimento de capital

int updateCapital(Capital capital); //alteração de informações de um recebimento de capital

int deleteCapital(int id); //exclui o capital recebido

Capital capitalById(int id); //carrega as informações (dados do usuario) para exibição ou edição

Capitais *listAllCapitais(); //lista todos os capitais

Capitais *filterCapitalByMonth(Capitais *listCapitais, char *date); //lista os recebimentos de capital com base em uma data

Capitais *filterCapitalBetweenDate(Capitais *listCapitais, char *initDate, char *endDate); //lista os gastos com base em dois meses dados

Capitais *filterCapitalBetweenValue(Capitais *listCapitais, float init_value, float end_value); //lista os recebimentos de capital com base em um valor

#endif // CAPITAL_H
