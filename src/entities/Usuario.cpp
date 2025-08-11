#include "Usuario.h"
#include <iostream>
#include "ExecaoCustomizada.h"
#include <vector>
#include <string>
using namespace std;

Usuario::Usuario(string login, string senha, Permissao *permissao)
{
  login_ = login;
  senha_ = senha;
  permissao_ = permissao;
}

void Usuario::setLogin(string login)
{
  login_ = login;
}

string Usuario::getLogin()
{
  return login_;
}

void Usuario::setSenha(string senha)
{
  senha_ = senha;
  return;
}

string Usuario::getSenha()
{
  return senha_;
}

void Usuario::setPermissao(Permissao *permissao)
{
  permissao_ = permissao;
}

Permissao *Usuario::getPermissao()
{
  return permissao_;
}

bool Usuario::ehPermitido(const string &nome_metodo)
{
  list<string> metodos_nao_permitidos = permissao_->getMetodosNaoPermitidos();
  for(auto it = metodos_nao_permitidos.begin(); it != metodos_nao_permitidos.end(); it++){
    if(nome_metodo == (*it)){
      return false;
    }
  }
  return true;
}

void Usuario::printPermissao(){
  cout << "Permissao " << login_ << endl;
  cout << "\t.Tipo: " << permissao_->getNome() << endl;
  cout << "\t.Metodos nao permitidos:" << endl;
  list<string> metodos = permissao_->getMetodosNaoPermitidos();
  for(auto it = metodos.begin(); it != metodos.end(); it++){
      cout << "\t\t> " << (*it) << endl;
  }
}