#ifndef PRODUTO_H
#define PRODUTO_H

#include "Data.h"
#include "Lote.h"
#include "Preco.h"
#include "MateriaPrima.h"
#include "OrdemProducao.h"
#include "Utility.h"

#include <vector>
#include <list>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class OrdemProducaoInvalida : public ExecaoCustomizada {
public:
 OrdemProducaoInvalida(char *e) : ExecaoCustomizada(e) {}
};

class LoteAtivoInvalido : public ExecaoCustomizada {
public:
 LoteAtivoInvalido(char *e) : ExecaoCustomizada(e) {}
};

class LoteInativoInvalido : public ExecaoCustomizada {
public:
 LoteInativoInvalido(char *e) : ExecaoCustomizada(e) {}
};

class PrecoInvalido : public ExecaoCustomizada {
public:
 PrecoInvalido(char *e) : ExecaoCustomizada(e) {}
};

class MateriaPrimaInvalida : public ExecaoCustomizada {
public:
 MateriaPrimaInvalida(char *e) : ExecaoCustomizada(e) {}
};
class QtdAtualInvalida : public ExecaoCustomizada {
public:
 QtdAtualInvalida(char *e) : ExecaoCustomizada(e) {}
};

class Produto
{
private:
  string nome_;
  int codigo_;
  int qtd_atual_;
  vector<Preco *> precos_venda_ = {};
  int tamanho_min_lote_;
  int estoque_min_;
  Data data_criacao_;
  list<Lote *> lotes_ativos_;
  list<Lote *> lotes_inativos_;
  map<MateriaPrima*, float> materias_primas_;
  map<Data, OrdemProducao*> ordem_producao_;
public:
  Produto(const string nome, const unsigned int codigo, Preco*     
    preco_venda, const Data data_criacao,
    const int tamanho_min_lote, const int estoque_minimo, map<MateriaPrima*, float> materias_primas);
  void setNome(const string nome);
  string getNome();
  void setCodigo(const unsigned int codigo);
  unsigned int getCodigo();
  void subQtdAtual(const int quantidade);
  int getQtdAtual();
  void addPreco(Preco* novo_valor);
  float getPrecoVendaAtual();
  vector<Preco*> getPrecosVenda();
  void setTamanhoMinLote(const int tamanho_min_lote);
  int getTamanhoMinLote();
  void setEstoqueMin(const int estoque_min);
  int getEstoqueMin();
  void addLoteAtivo(Lote *lote_ativo);
  void addLoteInativo(Lote *lote_inativo);
  void removeLoteAtivo(Lote *lote_ativo);
  void removeLoteInativo(Lote *lote_inativo);
  Lote* getLoteAtivo(unsigned int num_lote);
  list<Lote*> getLotesAtivos();
  Lote* getLoteInativo(unsigned int num_lote);
  list<Lote*> getLotesInativos();
  bool abaixoEstoqueMin();
  void addOrdemProducao(OrdemProducao* ordem_producao_);
  map<Data, OrdemProducao*> getOrdensProducao();
  OrdemProducao* getOrdemProducao(Data data_ordem);
  void printOrdemProducao();
  map<MateriaPrima*, float> getMateriasPrimas();
  void setMateriasPrimas(MateriaPrima* materia_prima, float quantidade);
  void printMateriaPrima();
  ~Produto();
};
#endif // PRODUTO_H