#ifndef USUARIO_H
#define USUARIO_H
#include "Permissao.h"
#include <string>
#include <vector>
#include "Data.h"
#include "Logs.h"

using namespace std;

class Usuario {
  string login_;
  string senha_;
  Permissao* permissao_;
public:
  Usuario(string login, string senha, Permissao* permissao);
  void setLogin(string login);
  string getLogin();
  void setSenha(string senha);
  string getSenha();
  void setPermissao(Permissao *permissao);
  Permissao *getPermissao();
  bool ehPermitido(const string&snome_metodo);
  void printPermissao();
};
#endif //USUARIO_H