#include <iostream>
#include <string.h>
#include "datacontrol.h"
#include "gasto.h"

using namespace std;

void exibe(Gastos *gastos)
{
	Gastos *tmp;
	tmp = gastos->next;
	cout << "Lista:\n";
	while( tmp != NULL){
		cout << tmp->gasto.id << "\n";
		cout << tmp->gasto.data << "\n";
		cout << tmp->gasto.id_user << "\n";
		tmp = tmp->next;
		cout << "\n\n\n\n";
	}
}

void cadastra(){
    Gasto gasto;
    int result;

    cin >> gasto.data;
    cin >> gasto.desc;
    cin >> gasto.valor;
    cin >> gasto.tipo;
    cin >> gasto.id_user;

    result = storeGasto(gasto);

    if(result){
        cout << "Cadastro realizado com sucesso";
    }else{
        cout << "Erro";
    }
}

void update(Gasto gasto){
    int result;

    cin >> gasto.data;
    cin >> gasto.desc;
    cin >> gasto.valor;
    cin >> gasto.tipo;
    cin >> gasto.id_user;

    result = updateGasto(gasto);

    if(result){
        cout << "Alteração realizada com sucesso";
    }else{
        cout << "Erro na alteração";
    }
}

void deletar(){
    int result;

    result = deleteGasto(2);

    if(result){
        cout << "Cadastro realizado com sucesso";
    }
}

int main()
{
    Gastos *gastos, *filtrado;

    gastos = listAllGastos();
    filtrado = filterGastoByMonth(gastos, "05/2018");

    exibe(filtrado);

    return 0;
}
