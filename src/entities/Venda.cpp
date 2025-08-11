#include <iostream>
#include "Venda.h"
#include "Logs.h"
#include "Usuario.h"
#include "Sessao.h"


Venda::Venda(const Data data_venda, vector<string> produtos) : data_venda_(data_venda){
  string entidade = "Venda_Venda";
  string info_antes = "Vazio";
  string info_depois = "Construido ";
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  Data data = data.dateNow();
  if (loggedUser->ehPermitido(entidade))
  {
    //-----------------------------------------------------
    for(auto it = produtos.begin(); it != produtos.end(); it++){
      map<unsigned int, int> mapa;
      //tem que ver se ta certo
      produtos_.emplace(*it, mapa);
    }
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


Data Venda::getDataVenda(){
  return data_venda_;
}

unsigned int Venda::getCodigo(){
  string entidade = "Venda_getCodigo";
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

void Venda::addQtdPorLote(const string produto,const unsigned int num_lote, const int qtd){
  produtos_[produto].at(num_lote) = qtd;
}

map<unsigned int, int> Venda::getQtdPorLote(const string produto){
  return produtos_[produto];
}


map<string, map<unsigned int, int>> Venda::getProdutos(){
  string entidade = "Venda::getProdutos";
  string info_acessada = "produtos_";
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  Data data = data.dateNow();
  if (loggedUser->ehPermitido(entidade))
  {
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    //-----------------------------------------------------------
    return produtos_;
    //-----------------------------------------------------------
  }
  else
  {
    LogAcessoNegado* lognegado = new LogAcessoNegado(entidade, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }

}




void Venda::printDados(){
  cout << "Data da venda: " << data_venda_.getData() << "\t";
  cout << "Codigo: " << codigo_ << endl;

  int quantidade = 0;
  for(auto it = produtos_.begin(); it != produtos_.end(); it++){
    for(auto itt = it->second.begin(); itt != it->second.end(); itt++){
      quantidade += itt->second;
    }
    cout << "Produto: " << it->first << "\t Quantidade total vendida: " << quantidade << endl;
    quantidade = 0;
  }
}

