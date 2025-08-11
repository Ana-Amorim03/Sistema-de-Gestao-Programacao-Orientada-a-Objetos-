#include "Categoria.h"
#include "OrdemProducao.h"
#include "Data.h"
#include <map>


#ifndef ESTOQUE_H
#define ESTOQUE_H

using namespace std;

class CategoriaInvalida : public ExecaoCustomizada {
public:
 CategoriaInvalida(char *e) : ExecaoCustomizada(e) {}
};

class MateriaPrimaInvalida1 : public ExecaoCustomizada {
public:
 MateriaPrimaInvalida1(char *e) : ExecaoCustomizada(e) {}
};


class Estoque {
  map<string, Categoria *> categorias_;
  map<string, MateriaPrima *> materias_primas_;

public:
  Estoque();
  void addCategoria(Categoria *categoria);
  map<string, Categoria *> getCategorias();
  Categoria* getCategoria(string nome);
  void printCategorias();
  void removeCategoria(string nome);
  void addMateriaPrima(MateriaPrima *materia_prima);
  map<string, MateriaPrima *> getMateriasPrimas();
  MateriaPrima* getMateriaPrima(string nome);
  void printMateriaPrima();
  void removeMateriaPrima(string nome);
  ~Estoque();
};

#endif 