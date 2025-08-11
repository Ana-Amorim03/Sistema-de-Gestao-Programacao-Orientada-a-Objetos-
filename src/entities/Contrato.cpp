#include "Contrato.h"
#include "Data.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

Contrato::Contrato(Data &data_admissao, Cargo *cargo,
                    float &salario_inicial)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Contrato";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Contrato_Contrato"))
  {
    data_admissao_ = data_admissao;
    cargo_ = cargo;
    salario_inicial_ = salario_inicial;
    salario_atual_ = salario_inicial;
    string info_antes = "Data admissao: Vazio; Cargo: Vazio; Salario inicial: Vazio";
    string info_depois = "Data admissao: "  + data_admissao.getData() + "Cargo: " + cargo->getNome() + " Salario inicial: " + to_string(salario_inicial);
    LogEscrita* logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    string func_negada = "Construtor";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
  
}


void Contrato::setDataDesligamento(Data data_desligamento) {
  data_desligamento_ = data_desligamento;
}

void Contrato::addReajuste(Reajuste *reajuste) {
  salario_atual_ *= reajuste->getReajuste();
  reajustes_.push_back(reajuste);
}

Data Contrato::getDataAdmissao() {
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Contrato";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Contrato_getDataAdmissao"))
  {
    string info_acessada = "Data Admissao";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return data_admissao_;
  }
  else
  {
    string func_negada = "getDataAdmissao";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
   
  }

Data Contrato::getDataDesligamento()  {
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Contrato";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Contrato_getDataDesligamento"))
  {
    string info_acessada = "Data Desligamento";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return data_desligamento_;
  }
  else
  {
    string func_negada = "getDataDesligamento";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
   
  }

Data Contrato::getDataZero()  { return data_zero_; }

Cargo *Contrato::getCargo()  {
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Contrato";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Contrato_getCargo"))
  {
    string info_acessada = "Cargo";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return cargo_;
  }
  else
  {
    string func_negada = "getCargo";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
  
  }

float Contrato::getSalarioInicial()  {
   Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Contrato";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Contrato_getSalarioInicial"))
  {
    string info_acessada = "Salario Inicial";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return salario_inicial_;
  }
  else
  {
    string func_negada = "getSalarioInicial";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
  
  }

float Contrato::getSalarioAtual()  {
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Contrato";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Contrato_getSalarioAtual"))
  {
    string info_acessada = "Salario Atual";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return salario_atual_;
  }
  else
  {
    string func_negada = "getSalarioAtual";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
  
  }

vector<Reajuste *> Contrato::getReajustes()  { return reajustes_; }

void Contrato::printReajustes()  {
  unsigned i = 1;
  for (auto it = reajustes_.begin(); it != reajustes_.end(); it++, i++) {
    if ((*it) != nullptr) {
      cout << "Reajuste " << i << ": " << fixed << setprecision(2)
           << (*it)->getReajuste() * 100 - 100 << "% ocorreu em ";
      (*it)->getDataOcorrencia().printData();
    }
  }
}

void Contrato::printDados()   {
  cout << "Data Admissao: ";
  data_admissao_.printData();

  if (!(data_desligamento_ == data_zero_)) {
    cout << "Data Desligamento: ";
    data_desligamento_.printData();
  }

  cout << "Cargo: " << cargo_->getNome() << endl;
  cout << "Salario Inicial: " << fixed << setprecision(2) << salario_inicial_
       << endl;
  cout << "Salario Atual: " << fixed << setprecision(2) << salario_atual_
       << endl;

  printReajustes();
}

Contrato::~Contrato() {
 for (unsigned it = 0; it < reajustes_.size(); it++)
  {
    delete reajustes_[it];
  }
}
