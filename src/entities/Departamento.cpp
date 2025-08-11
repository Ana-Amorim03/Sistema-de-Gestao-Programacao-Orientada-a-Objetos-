#include "Departamento.h"
#include "Logs.h"
#include <iostream>

Departamento::Departamento(const string &nome)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Departamento";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Departamento_Departamento"))
  {
    nome_ = nome;
    string aux = "Nome: ";
    string info_antes = "Nome: Vazio";
    string info_depois = aux + nome;
    LogEscrita *logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }

  else
  {
    string func_negada = "Construtor";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Departamento::addFuncionario(Funcionario *funcionario)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Departamento";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Departamento_addFuncionario"))
  {
    string info_antes;
    if (funcionarios_.empty())
    {
      info_antes = "funcionario: Vazio";
    }
    else
    {
      int pos = 1;
      for (auto it = funcionarios_.begin(); it != funcionarios_.end(); it++)
      {
        info_antes += to_string(pos) + " - Funcionario: " + (it)->first + "; ";
      }
    }
    auto it = funcionarios_.find(funcionario->getNome());
    if (it != funcionarios_.end())
    {
      char message[100] = "Um funcionario jah possui esse nome!";
      throw NomeInvalido(message);
    }
    funcionarios_[funcionario->getNome()] = funcionario;
    funcionario->setDepartamento(nome_);

    string info_depois = "";
    int pos = 1;
    for (auto it = funcionarios_.begin(); it != funcionarios_.end(); it++)
    {
      info_depois += to_string(pos) + " - Funcionario: " + (it)->first + "; ";
    }
    LogEscrita *logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    string func_negada = "addFuncionario";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Departamento::removeFuncionario(const string &nome)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Departamento";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Departamento_removeFuncionario"))
  {
    if (!funcionarios_.empty())
    {
      auto it = funcionarios_.find(nome);
      if (it == funcionarios_.end())
      {
        char message[100] = "Nenhum funcionario possui essa nome!";
        throw NomeInvalido(message);
      }
      else
      {
        string info_antes = "";
        int pos = 1;
        for (auto it = funcionarios_.begin(); it != funcionarios_.end(); it++)
        {
          info_antes += to_string(pos) + " - Funcionario: " + (it)->first + "; ";
        }
        funcionarios_.erase(it);
        string info_depois = "";
        pos = 1;
        for (auto it = funcionarios_.begin(); it != funcionarios_.end(); it++)
        {
          info_depois += to_string(pos) + " - Funcionario: " + (it)->first + "; ";
        }
        LogEscrita *logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
        logs->addLog(logescrita);
      }
    }
    else
    {
      throw "Funcionarios vazio";
    }
  }
  else
  {
    string func_negada = "removeFuncionario";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

map<string, Funcionario *> Departamento::getFuncionarios() const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Departamento";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Departamento_getFuncionarios"))
  {
    string info_acessada = "map de Funcionarios";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return funcionarios_;
  }
  else
  {
    string func_negada = "getFuncionarios";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

Funcionario *Departamento::getFuncionario(const string &nome) const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Departamento";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Departamento_getFuncionario"))
  {
    auto it = funcionarios_.find(nome);
    if (it == funcionarios_.end())
    {

      char message[100] = "Nenhum funcionario possui essa nome!";
      throw NomeInvalido(message);
    }

    string info_acessada = "funcionario: " + nome;
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return it->second;
  }
  else
  {
    string func_negada = "getFuncionario";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

string Departamento::getNome() const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Departamento";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Departamento_getNome"))
  {
    string info_acessada = "nome departamento";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return nome_;
  }
  else
  {
    string func_negada = "getNome";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Departamento::setNome(const string &nome)
{
  nome_ = nome;
}

void Departamento::printFuncionarios() const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Departamento";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Departamento_printFuncionarios"))
  {
    for (auto it = funcionarios_.begin(); it != funcionarios_.end(); it++)
    {
      cout << "Funcionario: " << it->first << endl;
    }
    string info_acessada = "Funcionarios do Departamento";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
  }
  else
  {
    string func_negada = "printFuncionarios";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

Departamento::~Departamento()
{
 for (auto it = funcionarios_.begin(); it != funcionarios_.end(); it++) {
     delete it->second;
  }
}