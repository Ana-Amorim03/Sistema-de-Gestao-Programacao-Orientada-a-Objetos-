#include "Categoria.h"
#include <iostream>
#include <utility>
#include "Data.h"
#include "Sessao.h"
#include "Usuario.h"
#include "LogEscrita.h"
#include "LogLeitura.h"
#include "LogAcessoNegado.h"
#include "Logs.h"

using namespace std;

Categoria::Categoria(const string &nome)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Categoria";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Categoria_Categoria"))
  {
    nome_ = nome;
    string info_antes = "Nome: Vazio";
    string info_depois = "Nome: " + nome;
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

void Categoria::addProduto(Produto *produto)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Categoria";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Categoria_addProduto"))
  {
    string info_antes;
    if (produtos_.empty())
    {
      info_antes = "Produto: Vazio";
    }
    else
    {
      int pos = 1;
      for (auto it = produtos_.begin(); it != produtos_.end(); it++)
      {
        info_antes += to_string(pos) + " - Produto: " + (it)->first + "; ";
      }
    }
    produtos_[produto->getNome()] = produto;
    produto->addLoteAtivo((new Lote(Data::dateNow(), Utility::randomCode(1000, 5000), produto->getEstoqueMin())));

    int pos = 1;
    string info_depois;
    for (auto it = produtos_.begin(); it != produtos_.end(); it++)
    {
      info_depois += to_string(pos) + " - Produto: " + (it)->first + "; ";
    }
    LogEscrita *logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    string func_negada = "addProduto";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

map<string, Produto *> Categoria::getProdutos()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Categoria";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Categoria_getProdutos"))
  {
    string info_acessada = "produtos";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return produtos_;
  }
  else
  {
    string func_negada = "getProdutos";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

Produto *Categoria::getProduto(const string &nome)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Categoria";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Categoria_getProduto"))
  {
    string info_acessada = "produto";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    if (produtos_.find(nome) != produtos_.end())
    {
      return produtos_[nome];
    }
    else
    {
      char message[100] = "Nenhum produto possui esse nome!";
      throw ProdutoInvalido(message);
    }
  }
  else
  {
    string func_negada = "getProduto";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

void Categoria::removeProduto(const string &produto)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Categoria";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Categoria_removeProduto"))
  {
    string info_antes = "";
    int pos = 1;
    for (auto it = produtos_.begin(); it != produtos_.end(); it++)
    {
      info_antes += to_string(pos) + " - Produto: " + (it)->first + "; ";
    }
    produtos_.erase(produto);

    pos = 1;
    string info_depois;
    if (produtos_.empty())
    {
      info_depois = "Produto: Vazio";
    }
    else
    {
      for (auto it = produtos_.begin(); it != produtos_.end(); it++)
      {
        info_depois += to_string(pos) + " - Produto: " + (it)->first + "; ";
      }
    }
    LogEscrita *logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    string func_negada = "removeProduto";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

void Categoria::setNome(string &Nome)
{
  nome_ = Nome;
}

string Categoria::getNome() const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Categoria";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Categoria_getNome"))
  {
    string info_acessada = "nome";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return nome_;
  }
  else
  {
    string func_negada = "getNome";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

void Categoria::printProdutos()
{
  {
    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Categoria";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Categoria_printProdutos"))
    {
      string info_acessada = "Produtos";
      LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
      logs->addLog(logleitura);
      if (produtos_.empty())
      {
        char message[100] = "Essa categoria não possui nenhum produto!";
        throw CategoriaVazia(message);
      }
      else
      {
        for (auto it = produtos_.begin(); it != produtos_.end(); it++)
        {
          cout << it->first;
        }
      }
    }
    else
    {
      string func_negada = "printProdutos";
      LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
      logs->addLog(lognegado);
      throw ExecaoAcessoNegado((char *)"Acesso Negado");
    }
  }
}

Categoria::~Categoria()
{
  for (auto it = produtos_.begin(); it != produtos_.end(); it++)
  {
    delete it->second;
  }
}