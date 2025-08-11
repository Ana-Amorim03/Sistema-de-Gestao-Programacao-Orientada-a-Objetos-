#include "Permissao.h"
#include "Data.h"
#include "Sessao.h"
#include "Usuario.h"
#include "Logs.h"


using namespace std;

Permissao::Permissao(const string& nome, list<string> permissoes_negadas)
{
    nome_ = nome;
    metodos_nao_permitidos_ = permissoes_negadas;
}



string Permissao::getNome()
{
  return nome_;
}

list<string> Permissao::getMetodosNaoPermitidos()
{
  return metodos_nao_permitidos_;
}

void Permissao::setNome(string nome)
{
    nome_ = nome;
}

void Permissao::addPermissaoMetodo(string nome_metodo)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Permissao";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Produto_addPermissaoMetodo"))
  {
    auto it = metodos_nao_permitidos_.begin();
    for (; it != metodos_nao_permitidos_.end(); it++)
    {
    }
    string info_antes = "";
    if (metodos_nao_permitidos_.empty())
    {
      info_antes += "Metodos nao permitidos: Vazio;";
    }
    else
    {
      int pos = 1;
      for (auto it = metodos_nao_permitidos_.begin(); it != metodos_nao_permitidos_.end(); it++)
      {
        info_antes += to_string(pos) + " - Lote Inativo: " + (*it) + "; ";
      }
    }

    if (it == metodos_nao_permitidos_.end())
    {
      metodos_nao_permitidos_.push_back(nome_metodo);
    }
    string info_depois = "";
    int pos = 1;
    for (auto it = metodos_nao_permitidos_.begin(); it != metodos_nao_permitidos_.end(); it++)
    {
      info_depois += to_string(pos) + " - Metodo nao permitido: " + (*it) + "; ";
    }

    LogEscrita* logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    string func_negada = "addPermissaoMetodo";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
  metodos_nao_permitidos_.push_back(nome_metodo);
}

void Permissao::removePermissaoMetodo(string nome_metodo)
{
  metodos_nao_permitidos_.remove(nome_metodo);
}