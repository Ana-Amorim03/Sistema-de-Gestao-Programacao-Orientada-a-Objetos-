#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include "Funcionario.h"
#include "Sessao.h"
#include "Usuario.h"
#include "LogEscrita.h"
#include "LogLeitura.h"
#include "LogAcessoNegado.h"
#include "Data.h"
#include "Logs.h"
#include <string>
#include <map>

using namespace std;
class NomeInvalido : public ExecaoCustomizada {
public:
  NomeInvalido(char *e) : ExecaoCustomizada(e) {}
};

class Departamento {

public:
  Departamento(const string &nome);

  void addFuncionario(Funcionario *funcionario);

  void removeFuncionario(const string &nome);

  map<string, Funcionario *> getFuncionarios() const;

  Funcionario* getFuncionario(const string &nome) const;

  void setNome(const string &nome);

  string getNome() const;

  void printFuncionarios() const;

  ~Departamento();

private:
  string nome_;
  map<string, Funcionario *> funcionarios_;
};

#endif // DEPARTAMENTO_H
