#include <iostream>
#include "user.h"

using namespace std;

int main() {
  struct Usuario usuario;
  int result;

  cout << "Cadastro de usuario" << "\n";

  cin >> usuario.nome;
  cin >> usuario.nasc;
  cin >> usuario.desc;
  cin >> usuario.renda;

  cout << usuario.nome;
  cout << usuario.nasc;
  cout << usuario.desc;
  cout << usuario.renda;

  result = store(usuario);

  if (result) {
    cout << "Salvo com sucesso";
  }else{
    cout << "Erro na gravação";
  }

  return 0;
}
