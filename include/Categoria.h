#ifndef CATEGORIA_H
#define CATEGORIA_H
#include <string>
#include "Produto.h"
#include <map>
using namespace std;
class ProdutoInvalido : public ExecaoCustomizada {
public:
  ProdutoInvalido(char *e) : ExecaoCustomizada(e) {}
};

class CategoriaVazia : public ExecaoCustomizada {
public:
  CategoriaVazia(char *e) : ExecaoCustomizada(e) {}
};

class Categoria {
public:

  Categoria(const string& nome);
  void addProduto(Produto *produto);
  Produto *getProduto(const string &nome);
  map<string, Produto *> getProdutos();
  void removeProduto(const string &produto);
  void setNome(string& Nome);
  string getNome() const;
  void printProdutos();
  ~Categoria();
private:
  string nome_;
  map <string, Produto *> produtos_;
};

#endif // CATEGORIA_H