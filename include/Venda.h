#include <map>
#include <string>
#include <vector>
#include "Data.h"

#ifndef VENDA_H
#define VENDA_H

using namespace std;

class Venda{
  Data data_venda_;
  unsigned int codigo_;
  map<string, map<unsigned int, int>> produtos_;
public:
  Venda(const Data data_da_venda,vector<string> produto);
  Data getDataVenda();
  unsigned int getCodigo();
  void addQtdPorLote(const string produto,const unsigned int num_lote, const int qtd);
  map<unsigned int, int> getQtdPorLote(const string produto);
  map<string, map<unsigned int, int>> getProdutos();
  void printDados();
};

#endif // VENDA_H