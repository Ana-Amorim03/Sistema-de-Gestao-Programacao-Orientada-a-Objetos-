#ifndef LOTE_H
#define LOTE_H
#include <string>
#include "Data.h"
#include <string>
#include "Sessao.h"
#include "Usuario.h"
#include "LogEscrita.h"
#include "LogLeitura.h"
#include "LogAcessoNegado.h"
#include "Logs.h"
using namespace std;
class Lote{
  
public:
  Lote(Data dataa, unsigned int num_lote, int qtd_produzida);
  
  void subQuantidadeAtual(int& quantidade);
  
  unsigned int getNumLote();
  
  Data getDataProd();
    
  float getQuantidadeProduzida();
  
  int getQuantidadeAtual();
  
//~Lote();

private:
  
  Data data_prod_;
  
  unsigned int num_lote_;
  
  int qtd_produzida_; 
  
  int qtd_atual_;

};
#endif // LOTE_H