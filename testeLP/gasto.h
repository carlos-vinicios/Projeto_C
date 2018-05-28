#ifndef GASTO_H
#define GASTO_H

int storeGasto(Gasto gasto); //salvar as informações de um novo gasto

int updateGasto(Gasto gasto); //alteração de informações de um gasto

int deleteGasto(int id); //exclui o gasto

Gasto gastoById(int id); //carrega as informações (gastos) para exibição ou edição

Gastos *listAllGastos(); //lista todos os gastos

Gastos *filterGastoByMonth(Gastos *listGastos, char *date); //lista os gastos com base em uma data

Gastos *filterGastoBetweenDate(Gastos *listGastos, char *initDate, char *endDate); //lista os gastos com base em dois meses dados

Gastos *filterGastoBetweenValue(Gastos *listGastos, float init_value, float end_value); //lista os recebimentos de capital com base em um valor

#endif // GASTO_H
