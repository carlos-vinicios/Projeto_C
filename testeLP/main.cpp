#include <iostream>
#include "datacontrol.h"
#include "user.h"

using namespace std;

void exibe(Usuarios *usuarios)
{
	Usuarios *tmp;
	tmp = usuarios->next;
	printf("Lista:");
	while( tmp != NULL){
		cout << tmp->user.id;
		tmp = tmp->next;
	}

	printf("\n\n");
}


int main()
{
    Usuarios *usuarios;

    usuarios = listAllUsers();

    exibe(usuarios);

    return 0;
}
