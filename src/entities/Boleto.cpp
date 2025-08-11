#include "Boleto.h"
#include "Usuario.h"
#include "Logs.h"
#include "Sessao.h"
#include <string>

using namespace std;

Boleto::Boleto(Data vencimento, float valor_total, unsigned int tipo, string codigo_de_barras)
: MetodoPagamento(valor_total, tipo){
  string entidade = "Boleto_Boleto";
  string info_antes = "Vazio";
  string info_depois = "{" + vencimento.getData() + ", " + codigo_de_barras + "}";
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  Data data = data.dateNow();
  if (loggedUser->ehPermitido(entidade))
  {
    //-----------------------------------------------------
    vencimento_ = vencimento;
    codigo_de_barras_ = codigo_de_barras;
    //-----------------------------------------------------
    LogEscrita* logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    LogAcessoNegado* lognegado = new LogAcessoNegado(entidade, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }



    
}

void Boleto::setVencimento(Data vencimento){
  vencimento_ = vencimento;
}

Data Boleto::getVencimento(){
  return vencimento_;
}

void Boleto::setCodigoDeBarras(string codigo_de_barras){
  codigo_de_barras_ = codigo_de_barras;
}
string Boleto::getCodigoDeBarras(){
  return codigo_de_barras_;
}