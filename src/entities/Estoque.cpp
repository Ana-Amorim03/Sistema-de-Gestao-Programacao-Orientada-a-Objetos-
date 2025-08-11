#include "Estoque.h"
#include <iostream>
#include "Data.h"
#include "Sessao.h"
#include "Usuario.h"
#include "LogEscrita.h"
#include "LogLeitura.h"
#include "LogAcessoNegado.h"
#include "Logs.h"

using namespace std;

Estoque::Estoque()
{
  /*   Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Estoque";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Estoque_Estoque"))
    {
      string info_antes = "Estoque: Vazio";
      string info_depois = "Estoque construido";
      LogEscrita *logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
      logs->addLog(logescrita);
    }
    else
    {
      string func_negada = "Construtor";
      LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
      logs->addLog(lognegado);
      throw ExecaoAcessoNegado((char *)"Acesso Negado");
    } */
}

void Estoque::addCategoria(Categoria *categoria)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Estoque";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Estoque_addCategoria"))
  {
    auto it = categorias_.find(categoria->getNome());
    if (it != categorias_.end())
    {
      char message[100] = "Essa categoria ja existe!";
      throw CategoriaInvalida(message);
    }
    string info_antes = "";
    if (categorias_.empty())
    {
      info_antes = "Categorias: Vazio;";
    }
    else
    {
      int pos = 1;
      for (auto it = categorias_.begin(); it != categorias_.end(); it++)
      {
        info_antes += to_string(pos) + " - Categoria: " + (it)->first + "; ";
      }
    }
    categorias_[categoria->getNome()] = categoria;
    string info_depois = "";
    int pos = 1;
    for (auto it = categorias_.begin(); it != categorias_.end(); it++)
    {
      info_depois += to_string(pos) + " - Categoria: " + (it)->first + "; ";
    }

    LogEscrita *logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    string func_negada = "addCategoria";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

map<string, Categoria *> Estoque::getCategorias()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Estoque";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Estoque_getCategorias"))
  {
    string info_acessada = "categorias";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return categorias_;
  }
  else
  {
    string func_negada = "getCategorias";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

Categoria *Estoque::getCategoria(string nome)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Estoque";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Estoque_getCategoria"))
  {
    string info_acessada = "categoria";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    auto it = categorias_.find(nome);
    if (it == categorias_.end())
    {

      char message[100] = "Essa categoria nao existe!";
      throw CategoriaInvalida(message);
    }

    return it->second;
  }
  else
  {
    string func_negada = "getCategoria";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

void Estoque::printCategorias()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Estoque";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Estoque_printCategorias"))
  {
    string info_acessada = "Categorias";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    for (auto it = categorias_.begin(); it != categorias_.end(); it++)
    {
      cout << it->first << endl;
    }
  }
  else
  {
    string func_negada = "printCategorias";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

void Estoque::removeCategoria(string nome)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Estoque";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Estoque_removeCategoria"))
  {
    if (!categorias_.empty())
    {
      auto it = categorias_.find(nome);
      if (it == categorias_.end())
      {
        char message[100] = "Essa categoria nao existe!";
        throw CategoriaInvalida(message);
      }
      else
      {

        string info_antes = "";
        int pos = 1;
        for (auto it = categorias_.begin(); it != categorias_.end(); it++)
        {
          info_antes += to_string(pos) + " - Categoria: " + (it)->first + "; ";
        }
        categorias_.erase(it);

        pos = 1;
        string info_depois = "";
        if (categorias_.empty())
        {
          info_depois = "Categorias: Vazio";
        }
        else
        {
          for (auto it = categorias_.begin(); it != categorias_.end(); it++)
          {
            info_depois += to_string(pos) + " - Categoria: " + (it)->first + "; ";
          }
        }

        LogEscrita *logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
        logs->addLog(logescrita);
      }
    }
    else
    {
      throw "Categoria Vazia";
    }
  }
  else
  {
    string func_negada = "removeCategoria";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

void Estoque::addMateriaPrima(MateriaPrima *materia_prima)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Estoque";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Estoque_addMateriaPrima"))
  {
    auto it = materias_primas_.find(materia_prima->getNome());
    if (it != materias_primas_.end())
    {
      char message[100] = "Essa materia prima ja existe!";
      throw MateriaPrimaInvalida(message);
    }
    string info_antes = "";
    if (materias_primas_.empty())
    {
      info_antes = "Materia Prima: Vazio;";
    }
    else
    {
      int pos = 1;
      for (auto it = materias_primas_.begin(); it != materias_primas_.end(); it++)
      {
        info_antes += to_string(pos) + " - Materia Prima: " + (it)->first + "; ";
      }
    }
    auto itr = materias_primas_.find(materia_prima->getNome());
    if (itr != materias_primas_.end())
    {
      char message[100] = "Essa materia prima ja existe!";
      throw MateriaPrimaInvalida1(message);
    }
    materia_prima->addOrdemCompra(new OrdemCompra(Data::dateNow(), Utility::randomCode(10000, 100000), materia_prima->getEstoqueMin(), materia_prima->getUnidadeMedida()));

    materias_primas_[materia_prima->getNome()] = materia_prima;
    // gera a ordem de compra para quantidade minima de produto
    string info_depois = "";
    int pos = 1;
    for (auto it = materias_primas_.begin(); it != materias_primas_.end(); it++)
    {
      info_depois += to_string(pos) + " - Materia Prima: " + (it)->first + "; ";
    }

    LogEscrita *logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    string func_negada = "addMateriaPrima";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

map<string, MateriaPrima *> Estoque::getMateriasPrimas()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Estoque";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Estoque_getMateriasPrimas"))
  {
    string info_acessada = "materias_primas";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return materias_primas_;
  }
  else
  {
    string func_negada = "getMateriasPrimas";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

MateriaPrima *Estoque::getMateriaPrima(string nome)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Estoque";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Estoque_getMateriaPrima"))
  {
    auto it = materias_primas_.find(nome);
    if (it == materias_primas_.end())
    {
      char message[100] = "Essa materia prima nao existe!";
      throw MateriaPrimaInvalida1(message);
    }

    string info_acessada = "Materia Prima";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return it->second;
  }
  else
  {
    string func_negada = "getMateriaPrima";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

void Estoque::printMateriaPrima()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Estoque";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Estoque_printMateriaPrima"))
  {
    string info_acessada = "Materia Prima";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    for (auto it = materias_primas_.begin(); it != materias_primas_.end(); it++)
    {
      cout << it->first << endl;
    }
  }
  else
  {
    string func_negada = "printMateriaPrima";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

void Estoque::removeMateriaPrima(string nome)
{
  auto it = materias_primas_.find(nome);
  if (it == materias_primas_.end())
  {

    char message[100] = "Essa materia prima nao existe!";
    throw MateriaPrimaInvalida1(message);
  }
  else
  {
    materias_primas_.erase(it);
  }
}
Estoque::~Estoque()
{
  for (auto it = categorias_.begin(); it != categorias_.end(); it++)
  {
    delete it->second;
  }
  for (auto it = materias_primas_.begin(); it != materias_primas_.end(); it++)
  {
    delete it->second;
  }
}
