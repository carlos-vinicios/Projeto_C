#ifndef GASTO_H
#define GASTO_H

int storeGasto(Gasto gasto); //salvar as informações de um novo gasto

int updateGasto(Gasto gasto); //alteração de informações de um gasto

Gastos *listGastoByDate(char *date); //lista os gastos com base em uma data

Gastos *listGastoBetweenDate(char *initDate, char *endDate); //lista os gastos com base em dois meses dados

Gastos *listGastoByValue(float valor); //lista os gastos com base em um valor

#endif // GASTO_H
