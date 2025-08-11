#ifndef PRECO_H
#define PRECO_H
#include "Data.h"
#include "Sessao.h"
#include "Usuario.h"
#include "LogEscrita.h"
#include "LogLeitura.h"
#include "LogAcessoNegado.h"
#include "Logs.h"

class Preco  {
  Data data_alteracao_;
  float novo_valor_;
public:
  Preco(Data data_alteracao, float novo_valor);
  Data getDataAlteracao();
  float getNovoValor();
};

#endif // PRECO_H