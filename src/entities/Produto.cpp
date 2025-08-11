#include "Produto.h"
#include <iostream>
#include <string>
#include "Data.h"
#include "Sessao.h"
#include "Usuario.h"
#include "LogEscrita.h"
#include "LogLeitura.h"
#include "LogAcessoNegado.h"
#include "Logs.h"

using namespace std;

Utility s;
unsigned int auxCodigoLote = s.randomCode(10000, 100000);
unsigned int auxCodigoOrdemCompra = s.randomCode(1000, 9999);
unsigned int auxCodigoOrdemProducao = s.randomCode(0, 999);

Produto::Produto(string nome, const unsigned int codigo, Preco *preco_venda,
                 const Data data_criacao, const int tamanho_min_lote, const int estoque_min, map<MateriaPrima *, float> materias_primas)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Produto";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Produto_Produto"))
  {
    tamanho_min_lote_ = tamanho_min_lote;
    nome_ = nome;
    codigo_ = codigo;
    precos_venda_.push_back(preco_venda);
    data_criacao_ = data_criacao;
    estoque_min_ = estoque_min;
    qtd_atual_ = 0;
    materias_primas_ = materias_primas;
    string info_antes = "Tamanho min lote: Vazio; Nome: Vazio; Codigo: Vazio; Preco Venda: Vazio; Data criacao: Vazio; Estoque minimo: Vazio; Quantidade atual: Vazio; Materias Primas: Vazio";
    string info_depois = "Tamanho min lote: " + to_string(tamanho_min_lote) + ";Nome: " + nome + "; Codigo: " + to_string(codigo) +
                         "; Preco Venda: " + to_string(preco_venda->getNovoValor()) + "; Data criacao: " + data_criacao.dateNow().getData() + "; Estoque minimo: " + to_string(estoque_min) +
                         "; Quantidade atual: "
                         "0" +
                         "; Materias Primas: ";
    for (auto it = materias_primas_.begin(); it != materias_primas_.end(); it++)
    {
      info_depois += (it)->first->getNome() + ", ";
    }
    info_depois += ";";
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

void Produto::setNome(const string nome)
{
  nome_ = nome;
}

string Produto::getNome()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Produto";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Produto_getNome"))
  {
    string info_acessada = "Nome";
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

void Produto::setTamanhoMinLote(const int tamanho_min_lote)
{
  tamanho_min_lote_ = tamanho_min_lote;
}

int Produto::getTamanhoMinLote()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Produto";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Produto_getTamanhoMinLote"))
  {
    string info_acessada = "TamanhoMinLote";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return tamanho_min_lote_;
  }
  else
  {
    string func_negada = "getTamanhoMinLote";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

void Produto::setCodigo(const unsigned int codigo)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Produto";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Produto_setCodigo"))
  {
    string info_antes = "Codigo: " + codigo_;
    codigo_ = codigo;
    string info_depois = "Codigo: " + codigo;
    LogEscrita *logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    string func_negada = "setCodigo";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

unsigned int Produto::getCodigo()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Produto";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Produto_getCodigo"))
  {
    string info_acessada = "Codigo";
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

float Produto::getPrecoVendaAtual()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Produto";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Produto_getPrecoVendaAtual"))
  {
    string info_acessada = "preco_venda";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    if (precos_venda_.empty())
    {
      char message[100] = "Preços de Venda esta vazio!";
      throw PrecoInvalido(message);
    }
    auto it = precos_venda_.end();
    it--;
    return (*it)->getNovoValor();
  }
  else
  {
    string func_negada = "getPrecoVendaAtual";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

void Produto::setEstoqueMin(const int estoque_min)
{
  estoque_min_ = estoque_min;
}

int Produto::getEstoqueMin()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Produto";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Produto_getEstoqueMin"))
  {
    string info_acessada = "EstoqueMin";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return estoque_min_;
  }
  else
  {
    string func_negada = "getEstoqueMin";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

int Produto::getQtdAtual()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Produto";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Produto_getQtdAtual"))
  {
    string info_acessada = "qtd_atual";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return qtd_atual_;
  }
  else
  {
    string func_negada = "getQtdAtual";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

void Produto::addPreco(Preco *novo_valor)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Produto";
  Data data = data.dateNow();
  string info_antes;
  string info_depois;
  if (loggedUser->ehPermitido("Produto::addPreco"))
  {
    if (precos_venda_.empty())
    {
      info_antes = "Precos: Vazio;";
    }
    else
    {
      info_antes = "";
      int pos = 1;
      for (auto it = precos_venda_.begin(); it != precos_venda_.end(); it++)
      {
        info_antes += to_string(pos) + " - Preco: " + to_string((*it)->getNovoValor()) + "; ";
      }
    }
    precos_venda_.push_back(novo_valor);
    int pos = 1;
    info_depois = "";
    for (auto it = precos_venda_.begin(); it != precos_venda_.end(); it++)
    {
      info_depois += to_string(pos) + " - Preco: " + to_string((*it)->getNovoValor()) + "; ";
    }
  }

  else
  {
    string func_negada = "addPreco";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

void Produto::subQtdAtual(const int quantidade)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Produto";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Produto_subQtdAtual"))
  {
    string info_acessada = "sub_qtd_atual";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    if (qtd_atual_ > 0)
    {
      qtd_atual_ -= quantidade;
      if ((estoque_min_ - qtd_atual_) > 0)
      {
        Data dataAux = dataAux.dateNow();
        Lote *alcancarEstoqueMin = new Lote(dataAux, auxCodigoLote, (estoque_min_ - qtd_atual_));
        addLoteAtivo(alcancarEstoqueMin);
        auxCodigoLote++;
      }
    }
    // cout <<"embaixo\n";
    else
    {
      char message[100] = "Quantidade atual ja e 0";
      throw QtdAtualInvalida(message);
    }
  }
  else
  {
    string func_negada = "subQtdAtual";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}
void Produto::addLoteAtivo(Lote *lote_ativo)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Produto";
  Data data = data.dateNow();

  if (loggedUser->ehPermitido("Produto_addLoteAtivo"))
  {
    // adiciona ordem de producao
    OrdemProducao *auxordemproducao = new OrdemProducao(lote_ativo->getDataProd(), auxCodigoOrdemProducao, nome_, lote_ativo->getQuantidadeProduzida());
    addOrdemProducao(auxordemproducao);
    auxCodigoOrdemProducao++;
    // processo para gerar lote
    auto it = materias_primas_.begin();
    for (; it != materias_primas_.end(); it++)
    {
      try
      {
        it->first->subQtdAtual((it->second) * (lote_ativo->getQuantidadeProduzida()));
      }
      catch (ExecaoCustomizada &e)
      {
        it->first->addOrdemCompra(new OrdemCompra(Data::dateNow(), Utility::randomCode(1000, 10000), ((it->second) * (lote_ativo->getQuantidadeProduzida()) - (it->first->getQtdAtual())), it->first->getUnidadeMedida()));
        it->first->subQtdAtual((it->second) * (lote_ativo->getQuantidadeProduzida()));
      }
    }
    // caso tente adicionar o mesmo lote mais de uma vez
    auto itr = lotes_ativos_.begin();
    for (; itr != lotes_ativos_.end(); itr++)
    {
      if ((*itr)->getNumLote() == lote_ativo->getNumLote())
      {
        char message[100] = "Esse lote ativo ja existe!";
        throw LoteAtivoInvalido(message);
      }
    }

    // info log
    string info_antes = "Qtd produto: " + to_string(qtd_atual_) + "; ";
    if (lotes_ativos_.empty())
    {
      info_antes += "Lotes Ativos: Vazio;";
    }
    else
    {
      int pos = 1;
      for (auto it = lotes_ativos_.begin(); it != lotes_ativos_.end(); it++)
      {
        info_antes += to_string(pos) + " - Lote Ativo: " + to_string((*it)->getNumLote()) + "; ";
      }
    }

    if (itr == lotes_ativos_.end())
    {
      lotes_ativos_.push_back(lote_ativo);
      qtd_atual_ += lote_ativo->getQuantidadeProduzida();
    }
    // mais sobre log
    string info_depois = "Qtd produto: " + to_string(qtd_atual_) + "; ";
    int pos = 1;
    for (auto it = lotes_ativos_.begin(); it != lotes_ativos_.end(); it++)
    {
      info_depois += to_string(pos) + " - Lote Ativo: " + to_string((*it)->getNumLote()) + "; ";
    }

    LogEscrita *logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    string func_negada = "addLoteAtivo";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

void Produto::addLoteInativo(Lote *lote_inativo)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Produto";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Produto_addLoteInativo"))
  {
    auto it = lotes_inativos_.begin();
    for (; it != lotes_inativos_.end(); it++)
    {
      if ((*it)->getNumLote() == lote_inativo->getNumLote())
      {
        char message[100] = "Essa lote inativo ja existe!";
        throw LoteInativoInvalido(message);
      }
    }
    string info_antes = "";
    if (lotes_inativos_.empty())
    {
      info_antes += "Lotes Inativos: Vazio;";
    }
    else
    {
      int pos = 1;
      for (auto it = lotes_inativos_.begin(); it != lotes_inativos_.end(); it++)
      {
        info_antes += to_string(pos) + " - Lote Inativo: " + to_string((*it)->getNumLote()) + "; ";
      }
    }

    if (it == lotes_inativos_.end())
    {
      lotes_inativos_.push_back(lote_inativo);
    }
    string info_depois = "";
    int pos = 1;
    for (auto it = lotes_inativos_.begin(); it != lotes_inativos_.end(); it++)
    {
      info_depois += to_string(pos) + " - Lote Inativo: " + to_string((*it)->getNumLote()) + "; ";
    }

    LogEscrita *logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    string func_negada = "addLoteInativo";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

void Produto::removeLoteAtivo(Lote *lote_ativo)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Produto";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Produto_removeLoteAtivo"))
  {
    if (!lotes_ativos_.empty())
    {
      string info_antes = "";
      int pos = 1;
      for (auto it = lotes_ativos_.begin(); it != lotes_ativos_.end(); it++)
      {
        info_antes += to_string(pos) + " - Lote Ativo : " + to_string((*it)->getNumLote()) + "; ";
      }

      auto it = lotes_ativos_.begin();
      for (; it != lotes_ativos_.end(); it++)
      {
        if ((*it)->getNumLote() == lote_ativo->getNumLote())
        {
          lotes_ativos_.remove(lote_ativo);
        }
      }
      if (it == lotes_ativos_.end())
      {
        char message[100] = "Esse lote ativo nao existe!";
        throw LoteAtivoInvalido(message);
      }
      string info_depois = "";
      if (lotes_ativos_.empty())
      {
        info_depois = "Categorias: Vazio";
      }
      else
      {
        pos = 1;
        for (auto it = lotes_ativos_.begin(); it != lotes_ativos_.end(); it++)
        {
          info_depois += to_string(pos) + " - Lote Ativo : " + to_string((*it)->getNumLote()) + "; ";
        }
      }
      LogEscrita *logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
      logs->addLog(logescrita);
    }
    else
    {
      throw "Lotes Ativos vazio";
    }
  }
  else
  {
    string func_negada = "removeLoteAtivo";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

void Produto::removeLoteInativo(Lote *lote_inativo)
{
  auto it = lotes_inativos_.begin();
  for (; it != lotes_inativos_.end(); it++)
  {
    if ((*it)->getNumLote() == lote_inativo->getNumLote())
    {
      lotes_inativos_.remove(lote_inativo);
    }
  }
  if (it == lotes_inativos_.end())
  {
    char message[100] = "Essa lote inativo nao existe!";
    throw LoteInativoInvalido(message);
  }
}

vector<Preco *> Produto::getPrecosVenda()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Produto";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Produto_getPrecosVenda"))
  {
    string info_acessada = "PrecosVenda";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    if (precos_venda_.empty())
    {
      char message[100] = "Preços de Venda esta vazio!";
      throw PrecoInvalido(message);
    }
    return precos_venda_;
  }
  else
  {
    string func_negada = "getPrecosVenda";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

Lote *Produto::getLoteAtivo(unsigned int num_lote)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Produto";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Produto_getLoteAtivo"))
  {
    string info_acessada = "LoteAtivo";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    auto it = lotes_ativos_.begin();
    for (; it != lotes_ativos_.end(); it++)
    {
      if ((*it)->getNumLote() == num_lote)
      {
        return *it;
      }
    }
    if (it == lotes_ativos_.end())
    {
      char message[100] = "Essa lote inativo nao existe!";
      throw LoteAtivoInvalido(message);
    }
    return nullptr;
  }
  else
  {
    string func_negada = "getLoteAtivo";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

Lote *Produto::getLoteInativo(unsigned int num_lote)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Produto";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Produto_getLoteInativo"))
  {
    string info_acessada = "LoteInativo";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    auto it = lotes_inativos_.begin();
    for (; it != lotes_inativos_.end(); it++)
    {
      if ((*it)->getNumLote() == num_lote)
      {
        return *it;
      }
    }
    if (it == lotes_inativos_.end())
    {
      char message[100] = "Essa lote inativo nao existe!";
      throw LoteInativoInvalido(message);
    }
    return nullptr;
  }
  else
  {
    string func_negada = "getLoteInativo";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

list<Lote *> Produto::getLotesAtivos()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Produto";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Produto_getLotesAtivos"))
  {
    string info_acessada = "LotesAtivos";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    if (lotes_ativos_.empty())
    {
      char message[100] = "Lotes Ativos esta vazio!";
      throw LoteAtivoInvalido(message);
    }
    return lotes_ativos_;
  }
  else
  {
    string func_negada = "getNLotesAtivos";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

list<Lote *> Produto::getLotesInativos()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Produto";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Produto_getLotesInativos"))
  {
    string info_acessada = "LotesInativos";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    if (lotes_inativos_.empty())
    {
      char message[100] = "Lotes Inativos esta vazio!";
      throw LoteInativoInvalido(message);
    }
    return lotes_inativos_;
  }
  else
  {
    string func_negada = "getLotesInativos";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

void Produto::addOrdemProducao(OrdemProducao *ordem_producao)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Produto";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Produto_addOrdemProducao"))
  {
    auto it = ordem_producao_.find(ordem_producao->getCodigo());
    if (it != ordem_producao_.end())
    {
      char message[100] = "Essa ordem de producao ja existe!";
      throw OrdemProducaoInvalida(message);
    }

    int pos = 1;
    string info_antes = "";
    if (ordem_producao_.empty())
    {
      info_antes = "Ordem Producao: Vazio";
    }
    else
    {
      for (auto it = ordem_producao_.begin(); it != ordem_producao_.end(); it++)
      {
        info_antes += pos + " - Ordem Producao: " + to_string((*it).second->getCodigo()) + "; ";
      }
    }
    ordem_producao->getDataOrdem().printData();
    ordem_producao_[ordem_producao->getDataOrdem()] = ordem_producao;
    pos = 0;
    string info_depois = "";
    for (auto it = ordem_producao_.begin(); it != ordem_producao_.end(); it++)
    {
      info_depois += pos + " - Ordem Producao: " + to_string((*it).second->getCodigo()) + "; ";
    }

    LogEscrita *logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    string func_negada = "addOrdemProducao";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

map<Data, OrdemProducao *> Produto::getOrdensProducao()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Produto";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Produto_getOrdensProducao"))
  {

    if (ordem_producao_.empty())
    {

      char message[100] = "Ordem de Produçao esta vazia!";
      throw OrdemProducaoInvalida(message);
    }
    string info_acessada = "Ordens Producao";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return ordem_producao_;
  }
  else
  {
    string func_negada = "getOrdensProducao";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

OrdemProducao *Produto::getOrdemProducao(Data data_ordem)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Produto";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Produto_getOrdemProducao"))
  {

    auto it = ordem_producao_.find(data_ordem);
    if (it == ordem_producao_.end())
    {

      char message[100] = "Essa ordem de producao nao existe!";
      throw OrdemProducaoInvalida(message);
    }
    string info_acessada = "Ordem Producao";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);

    return it->second;
  }
  else
  {
    string func_negada = "getOrdemProducao";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

void Produto::printOrdemProducao()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Produto";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Produto_printOrdemProducao"))
  {
    string info_acessada = "Ordem Producao";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    if (ordem_producao_.empty())
    {

      char message[100] = "Ordem de Produçao esta vazia!";
      throw OrdemProducaoInvalida(message);
    }
    cout << "Imprimindo ordem de producao" << endl;
    for (auto it = ordem_producao_.begin(); it != ordem_producao_.end(); it++)
    {
      cout << "\tCod: " << it->second->getCodigo() << endl;
      cout << "\tProduto: " << it->second->getProdAlvo() << endl;
      cout << "\tData: " << it->second->getDataOrdem().getData() << endl;
      cout << "\tQuantidade produzida: " << it->second->getQtdProduzida() << endl;
    }
  }
  else
  {
    string func_negada = "printOrdemProducao";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

map<MateriaPrima *, float> Produto::getMateriasPrimas()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Produto";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Produto_getMateriasPrimas"))
  {
    if (materias_primas_.empty())
    {
      char message[100] = "Materias Primas esta vazia!";
      throw MateriaPrimaInvalida(message);
    }

    string info_acessada = "Materias Primas";
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

void Produto::setMateriasPrimas(MateriaPrima *materia_prima, float quantidade)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Produto";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Produto_setMateriasPrimas"))
  {
    string info_antes = "";
    int pos = 1;
    if (materias_primas_.empty())
    {
      info_antes = "Materias Primas: Vazio";
    }
    else
    {
      for (auto it = materias_primas_.begin(); it != materias_primas_.end(); it++)
      {
        info_antes += to_string(pos) + " - MateriaPrima: " + (it)->first->getNome() + "; ";
      }
    }
    materias_primas_.insert({materia_prima, quantidade});
    string info_depois = "";
    pos = 1;
    for (auto it = materias_primas_.begin(); it != materias_primas_.end(); it++)
    {
      info_depois += to_string(pos) + " - MateriaPrima: " + (it)->first->getNome() + "; ";
    }
    LogEscrita *logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    string func_negada = "setMateriasPrimas";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

bool Produto::abaixoEstoqueMin()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Produto";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Produto_abaixoEstoqueMin"))
  {
    string info_acessada = "abaixo_estoque_min";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    if (qtd_atual_ < estoque_min_)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    string func_negada = "abaixoEstoqueMin";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}

void Produto::printMateriaPrima()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Produto";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Produto_printMateriaPrima"))
  {
    for (auto it = materias_primas_.begin(); it != materias_primas_.end(); it++)
    {
      cout << "Nome: " << (it)->first->getNome() << "     Quantidade necessaria: " << (it)->second
           << it->first->getUnidadeMedida() << endl;
    }
    string info_acessada = "Materias Primas do Produto";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
  }
  else
  {
    string func_negada = "printMateriaPrima";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char *)"Acesso Negado");
  }
}
Produto::~Produto()
{
  for (auto it = ordem_producao_.begin(); it != ordem_producao_.end(); it++)
  {
    delete (*it).second;
  }
  for (unsigned it = 0; it < precos_venda_.size(); it++)
  {
    delete precos_venda_[it];
  }
}