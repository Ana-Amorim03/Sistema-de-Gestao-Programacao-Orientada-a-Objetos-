#ifndef PERMISSAO_H
#define PERMISSAO_H

#include <string>
#include <list>

using namespace std;

class Permissao{
  string nome_;
  list<string> metodos_nao_permitidos_ = {};
public:
  Permissao(const string& nome,list<string> permissoes_negadas);
  void setNome(string nome);
  string getNome();
  list<string> getMetodosNaoPermitidos();
  void addPermissaoMetodo(string nome_metodo);
  void removePermissaoMetodo(string nome_metodo);
};
#endif