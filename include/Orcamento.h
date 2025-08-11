#ifndef ORCAMENTO_H
#define ORCAMENTO_H

#include "Data.h"
#include "Produto.h"
#include <map>

using namespace std;

class Orcamento{

public:
  Orcamento(Data data, unsigned int codigo, map<Produto*, int> produtos);
  Data getData();
  unsigned int getCodigo();
  map<Produto*, int> getProdutos();
  int qtdTotalProdutos();
  float precoTotal();
  bool validaOrcamento();
  void printDados();
private:
  Data data_;
  unsigned int codigo_;
  map<Produto*, int> produtos_por_qtd_;
  map<Produto*, float> produtos_por_preco_;
  string entidade = "Orcamento";
};
#endif // ORCAMENTO_H
