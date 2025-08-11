#include "MetodoPagamento.h"
#include "Usuario.h"
#include "Logs.h"
#include "Sessao.h"

using namespace std;


float MetodoPagamento::getValorTotal(){
  string entidade = "MetodoPagamento_getValorTotal";
  string info_acessada = "valor_total_";
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  Data data = data.dateNow();
  if (loggedUser->ehPermitido(entidade))
  {
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    //-----------------------------------------------------------
    return valor_total_;
    //-----------------------------------------------------------
  }
  else
  {
    LogAcessoNegado* lognegado = new LogAcessoNegado(entidade, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
  
}

unsigned int MetodoPagamento::getTipo(){
  return tipo_;
}

//atualmente esta randomico para fins de teste
bool MetodoPagamento::validaPagamento(){
    return true;
}

MetodoPagamento::MetodoPagamento(float valor_total, unsigned int tipo){
  valor_total_ = valor_total;
  tipo_ = tipo;
}