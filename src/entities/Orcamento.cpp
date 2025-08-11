#include "Orcamento.h"
#include "Usuario.h"
#include "Logs.h"
#include "Sessao.h"
#include <iostream>
using namespace std;

Orcamento::Orcamento(Data data1, unsigned int codigo, map<Produto *, int> produtos){
  string entidade = "Orcamento_Orcamento";
  string info_antes = "Vazio";
  string info_depois = "Construido";
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  Data data = data.dateNow();
  if (loggedUser->ehPermitido(entidade))
  {
    //-----------------------------------------------------
    data_ = data1;
    codigo_ = codigo;
    produtos_por_qtd_ = produtos;
    info_depois += "{";
    
    for (auto it : produtos) {
      produtos_por_preco_[it.first] = it.first->getPrecoVendaAtual();
      info_depois += it.first->getNome() + ", ";
    }
    info_depois += "}";
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


Data Orcamento::getData(){
  return data_;
}
unsigned int Orcamento::getCodigo(){
  string entidade = "Orcamento_getCodigo";
  string info_acessada = "codigo_";
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  Data data = data.dateNow();
  if (loggedUser->ehPermitido(entidade))
  {
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    //-----------------------------------------------------------
    return codigo_;
    //-----------------------------------------------------------
  }
  else
  {
    LogAcessoNegado* lognegado = new LogAcessoNegado(entidade, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }

  
}
map<Produto*, int> Orcamento::getProdutos(){
  return produtos_por_qtd_;
}
int Orcamento::qtdTotalProdutos(){
  string entidade = "Orcamento_qtdTotalProdutos";
  string info_acessada = "produtos_";
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  Data data = data.dateNow();
  if (loggedUser->ehPermitido(entidade))
  {
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    //-----------------------------------------------------------
    int soma = 0;
    for (auto it : produtos_por_qtd_) {
        soma += it.second;
    }
    return soma;
    //-----------------------------------------------------------
  }
  else
  {
    LogAcessoNegado* lognegado = new LogAcessoNegado(entidade, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
  
}
float Orcamento::precoTotal(){
  string entidade = "Orcamento_precoTotal";
  string info_acessada = "produtos_";
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  Data data = data.dateNow();
  if (loggedUser->ehPermitido(entidade))
  {
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    //-----------------------------------------------------------
    float soma = 0.00;
    for (auto it : produtos_por_preco_) {
        soma += it.second;
    }
    return soma;
    //-----------------------------------------------------------
  }
  else
  {
    LogAcessoNegado* lognegado = new LogAcessoNegado(entidade, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }

}
bool Orcamento::validaOrcamento(){
  //chegar se o preco getprecoatual eh igual ao salvo
  for (auto it : produtos_por_preco_) {
    if (it.first->getPrecoVendaAtual() != it.second){
      return false;
    }
  }
  //checar se ainda tema  qtd de itens 
  for (auto it : produtos_por_qtd_) {
    if (it.first->getQtdAtual() != it.second){
      return false;
    }
  }
  
  return true;
}
void Orcamento::printDados(){
  cout << "Imprimindo dados do orcamento" << endl;
  cout << "\tCodigo: " << codigo_ << endl;
  cout << "\tData: " << data_.getData() << endl;
  for(auto it = produtos_por_qtd_.begin(); it != produtos_por_qtd_.end(); it++){
    cout << "\t" << (*it).first->getNome() << ": " << (*it).second  << " unidades" << endl;
  }
}