#ifndef CONTRATO_H
#define CONTRATO_H
#include "Cargo.h"
#include "Data.h"
#include "Reajuste.h"
#include "Sessao.h"
#include "Usuario.h"
#include "LogEscrita.h"
#include "LogLeitura.h"
#include "LogAcessoNegado.h"
#include "Logs.h"
#include <vector>

class Contrato {

public:
  Contrato(Data &data_admissao, Cargo *cargo,  float &salario_inicial);

  void setDataDesligamento(Data data_desligamento);

  void addReajuste(Reajuste *reajuste);

  Data getDataAdmissao();

  Data getDataDesligamento() ;

  Data getDataZero() ;

  Cargo *getCargo() ;

  float getSalarioInicial() ;

  float getSalarioAtual() ;

  vector<Reajuste *> getReajustes() ;

  void printReajustes() ;

  void printDados();

  ~Contrato();

private:
  Data data_admissao_;
  Data data_desligamento_;
  Data data_zero_;
  Cargo *cargo_;
  float salario_inicial_;
  float salario_atual_;
  vector<Reajuste *> reajustes_;
};

#endif // CONTRATO_H
