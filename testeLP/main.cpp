#include <iostream>
#include <string.h>
#include "datacontrol.h"
#include "capital.h"

using namespace std;

void exibe(Capitais *capitais)
{
	Capitais *tmp;
	tmp = capitais->next;
	cout << "Lista:\n";
	while( tmp != NULL){
		cout << tmp->capital.id << "\n";
		cout << tmp->capital.data << "\n";
		cout << tmp->capital.id_user << "\n";
		tmp = tmp->next;
		cout << "\n\n\n\n";
	}
}

void cadastra(){
    Capital capital;
    int result;

    cin >> capital.data;
    cin >> capital.desc;
    cin >> capital.valor;
    cin >> capital.id_user;

    result = storeCapital(capital);

    if(result){
        cout << "Cadastro realizado com sucesso";
    }
}

void update(){

}

int main()
{
    Capital capital;
    int result;
//    Capitais *capitais, *filtrado;
//    char date1[] = {"18/05/2018"}, date2[] = {"16/05/2018"};
//
//    capitais = listAllCapitais();
//
//    filtrado = filterCapitalBetweenValue(capitais, 2000, 3500);
//
//    exibe(filtrado);

//    capital.id = 5;
//    strcpy(capital.data, "19/05/2018");
//    strcpy(capital.desc, "Apenas um teste 2");
//    capital.valor = 1452.50;
//    capital.id_user = 5;

    result = deleteCapital(3);

    if(result){
        cout << "Com sucesso";
    }else{
        cout << "Falhou";
    }
    return 0;
}
