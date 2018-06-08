#ifndef INVESTIMENTO_H
#define INVESTIMENTO_H

int storeInvestimento(Investimento investimento); //salvar as informa��es de um novo recebimento de Investimento

int updateInvestimento(Investimento investimento); //altera��o de informa��es de um recebimento de Investimento

int deleteInvestimento(int id); //exclui o Investimento recebido

Investimento investimentoById(int id); //carrega as informa��es (dados do usuario) para exibi��o ou edi��o

Investimentos *listAllInvestimentos(); //lista todos os Investimentos

Investimentos *filterInvestimentoByMonth(Investimentos *listInvestimentos, char *date); //lista os recebimentos de Investimento com base em uma data

Investimentos *filterInvestimentoBetweenDate(Investimentos *listInvestimentos, char *initDate, char *endDate); //lista os gastos com base em dois meses dados

Investimentos *filterInvestimentoBetweenValue(Investimentos *listInvestimentos, float init_value, float end_value); //lista os recebimentos de Investimento com base em um valor

#endif //INVESTIMENTO_H
