#include "CartaoCredito.h"
#include "Usuario.h"
#include "Logs.h"
#include "Sessao.h"


using namespace std;

CartaoCredito::CartaoCredito(int qtd_parcelas, int cvv, string num_cartao, float valor_total, unsigned int tipo)
: MetodoPagamento(valor_total, tipo)
{
  string entidade = "CartaoCredito_CartaoCredito";
  string info_antes = "Vazio;";
  string info_depois = "Construido";
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  Data data = data.dateNow();
  if (loggedUser->ehPermitido(entidade))
  {
    //-----------------------------------------------------
    qtd_parcelas_ = qtd_parcelas;
    cvv_ = cvv;
    num_cartao_ = num_cartao;  
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

// void CartaoCredito::setQtdParcelas(int qtd_parcelas){
//   qtd_parcelas_ = qtd_parcelas;
// }

int CartaoCredito::getQtdParcelas(){
  string entidade = "CartaoCredito_getQtdParcelas";
  string info_acessada = "qtd_parcelas_";
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  Data data = data.dateNow();
  if (loggedUser->ehPermitido(entidade))
  {
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    //-----------------------------------------------------------
     return qtd_parcelas_;
    //-----------------------------------------------------------
  }
  else
  {
    LogAcessoNegado* lognegado = new LogAcessoNegado(entidade, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }

 
}

float CartaoCredito::getValorParcela(){
  string entidade = "CartaoCredito_getValorParcela";
  string info_acessada = "valor_parcela_";
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  Data data = data.dateNow();
  if (loggedUser->ehPermitido(entidade))
  {
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    //-----------------------------------------------------------
    return valor_total_ / qtd_parcelas_;
    //-----------------------------------------------------------
  }
  else
  {
    LogAcessoNegado* lognegado = new LogAcessoNegado(entidade, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
  
}
// void CartaoCredito::setCVV(int cvv){
//   cvv_ = cvv;
// }

// int CartaoCredito::getCVV(){
//   return cvv_;
// }

// void CartaoCredito::setNumCartao(string num_cartao){
//   num_cartao_ = num_cartao;
// }

// string CartaoCredito::getNumCartao(){
//   return num_cartao_;
// }