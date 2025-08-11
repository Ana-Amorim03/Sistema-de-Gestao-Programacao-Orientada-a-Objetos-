#include "OrdemProducao.h"
#include <iostream>
#include "Sessao.h"
#include "Usuario.h"
#include "LogEscrita.h"
#include "LogLeitura.h"
#include "LogAcessoNegado.h"
#include "Logs.h"
using namespace std;

OrdemProducao::OrdemProducao(Data data_ordem, unsigned int codigo, string prod_alvo, int qtd_produzida)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "OrdemProducao";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("OrdemProducao_OrdemProducao"))
  {
    prod_alvo_ = prod_alvo;
    data_ordem_ = data_ordem;
    codigo_ = codigo;
    qtd_produzida_ = qtd_produzida;
    string info_antes = "Prod_alvo: Vazio; Data_ordem: Vazio; Codigo: Vazio; Quantidade Produzida: Vazio;";
    string info_depois = "Prod_alvo: " + prod_alvo + "; Data_ordem: " + data_ordem.getData() + "; Codigo: " + to_string(codigo) + ";Quantidade Produzida:" + to_string(qtd_produzida) + ";";
    LogEscrita *logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    string func_negada = "Construtor";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

Data OrdemProducao::getDataOrdem()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "OrdemProducao";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("OrdemProducao_getDataOrdem"))
  {
    string info_acessada = "data_ordem";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return data_ordem_;
  }
  else
  {
    string func_negada = "getDataOrdem";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

// int OrdemProducao::getNumLote(){
// return num_lote_//;
//}

string OrdemProducao::getProdAlvo()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "OrdemProducao";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("OrdemProducao_getProdAlvo"))
  {
    string info_acessada = "prod_alvo";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return prod_alvo_;
  }
  else
  {
    string func_negada = "getProdAlvo";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

unsigned int OrdemProducao::getCodigo()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "OrdemProducao";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("OrdemProducao_getCodigo"))
  {
    string info_acessada = "codigo";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return codigo_;
  }
  else
  {
    string func_negada = "getCodigo";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

int OrdemProducao::getQtdProduzida()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "OrdemProducao";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("OrdemProducao_getQtdProduzida"))
  {
    string info_acessada = "qtd_produzida";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return qtd_produzida_;
  }
  else
  {
    string func_negada = "getQtdProduzida";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

void OrdemProducao::printDados()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Ordem Produçao";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("OrdemProducao_printDados"))
  {
    string info_acessada = " Print Ordem Producao";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    cout << "--------- DADOS DA ORDEM DE PRODUÇAO COD: " << codigo_ << " ---------" << endl;
    cout << "Data da Ordem: " << data_ordem_.getData() << endl;
    // cout << "Número do Lote: " << num_lote_ << endl;
    cout << "Produto Alvo: " << prod_alvo_ << endl;
    cout << "Quantidade Produzida: " << qtd_produzida_ << endl;
  }
  else
  {
    string func_negada = "printDados";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}