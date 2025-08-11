#include "Data.h"
#include "Produto.h"
#include "Lote.h"
#include <list>

#ifndef ORDEM_PRODUCAO
#define ORDEM_PRODUCAO

using namespace std;

class OrdemProducao {
  Data data_ordem_;
  unsigned int codigo_;
  //int num_lote_;
  string prod_alvo_;
  int qtd_produzida_;

public:
  OrdemProducao(Data data_ordem, unsigned int codigo, string prod_alvo, int qtd__produzida);
  Data getDataOrdem();
  unsigned int getCodigo();
  string getProdAlvo();
  int getQtdProduzida();
  void printDados();
};

#endif // ORDEM_PRODUCAO