#ifndef CARGO_H
#define CARGO_H

#include <string>
#include "Sessao.h"
#include "Usuario.h"
#include "LogEscrita.h"
#include "LogLeitura.h"
#include "LogAcessoNegado.h"
#include "Data.h"
#include "Logs.h"
using namespace std;

class Cargo {

public:
  Cargo(const string &nome);

  void setNome(const string &nome);

  string getNome() const;

  ~Cargo();

private:
  string nome_;
};

#endif // CARGO_H
