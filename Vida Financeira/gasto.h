#ifndef GASTO_H
#define GASTO_H

int storeGasto(Gasto gasto); //salvar as informa??es de um novo gasto

int updateGasto(Gasto gasto); //altera??o de informa??es de um gasto

int deleteGasto(int id); //exclui o gasto

Gasto gastoById(int id); //carrega as informa??es (gastos) para exibi??o ou edi??o

Gastos *listAllGastos(); //lista todos os gastos

Gastos *listGastoByMonth(char *date); //lista os gastos com base em uma data

Gastos *filterGastosByCategoria(Gastos *listGastos, int idCategoria); //retorna todos os gastos de uma dada categoria

Gastos *filterGastoBetweenDate(Gastos *listGastos, char *initDate, char *endDate); //lista os gastos com base em dois meses dados

Gastos *filterGastoBetweenValue(Gastos *listGastos, float init_value, float end_value); //lista os recebimentos de capital com base em um valor

#endif // GASTO_H
