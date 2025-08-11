#include "PedidoCompra.h"

#include "Produto.h"
#include "Logs.h"
#include <vector>
#include <iostream>

using namespace std;

PedidoCompra::PedidoCompra(unsigned int codigo, Data data_pedido, Orcamento *orcamento, string cliente, MetodoPagamento *pagamento){
string entidade = "PedidoCompra_PedidoCompra";
  string info_acessada = "Construcao de Pedido Compra para cod" + to_string(codigo) + " e cliente: " + cliente;
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  Data data = data.dateNow();
if (loggedUser->ehPermitido(entidade))
{
  codigo_ = codigo;
  data_pedido_ = data_pedido;
  orcamento_ = orcamento;
  cliente_ = cliente;
  pagamento_ = pagamento;
  status_ = false;
  LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
  logs->addLog(logleitura);    
}else{
  LogAcessoNegado* lognegado = new LogAcessoNegado(entidade, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char*)"Acesso Negado");
}
}

unsigned int PedidoCompra::getCodigo()
{
  string entidade = "PedidoCompra_getCodigo";
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

Data PedidoCompra::getDataPedido()
{
  string entidade = "PedidoCompra_getDataPedido";
  string info_acessada = "dataPedido_";
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  Data data = data.dateNow();
  if (loggedUser->ehPermitido(entidade))
  {
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    //-----------------------------------------------------------
    return data_pedido_;
    //-----------------------------------------------------------
  }
  else
  {
    LogAcessoNegado* lognegado = new LogAcessoNegado(entidade, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
    
}
Orcamento *PedidoCompra::getOrcamento()
{
  string entidade = "PedidoCompra_getOrcamento";
  string info_acessada = "orcamento_";
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  Data data = data.dateNow();
  if (loggedUser->ehPermitido(entidade))
  {
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    //-----------------------------------------------------------
    return orcamento_;
    //-----------------------------------------------------------
  }
  else
  {
    LogAcessoNegado* lognegado = new LogAcessoNegado(entidade, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}
string PedidoCompra::getCliente()
{
  string entidade = "PedidoCompra_getCliente";
  string info_acessada = "cliente_";
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  Data data = data.dateNow();
  if (loggedUser->ehPermitido(entidade))
  {
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    //-----------------------------------------------------------
    return cliente_;
    //-----------------------------------------------------------
  }
  else
  {
    LogAcessoNegado* lognegado = new LogAcessoNegado(entidade, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
    
}
Data PedidoCompra::getDataPagamento()
{
  string entidade = "PedidoCompra_getDataPagamento";
  string info_acessada = "data_pagamento_";
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  Data data = data.dateNow();
  if (loggedUser->ehPermitido(entidade))
  {
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    //-----------------------------------------------------------
    return data_pagamento_;
    //-----------------------------------------------------------
  }
  else
  {
    LogAcessoNegado* lognegado = new LogAcessoNegado(entidade, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}
void PedidoCompra::gerarVenda()
{
  string entidade = "PedidoCompra_gerarVenda";
  string info_antes = "";
  string info_depois = "";
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  Data data = data.dateNow();
  if (loggedUser->ehPermitido(entidade))
  {
    //-----------------------------------------------------
    if (orcamento_->validaOrcamento() == false)
    {
        string resposta = "";
        do 
        {
          cout << "Orcamento invalido. Deseja validar? sim | nao" << endl;
          cin >> resposta;
        } while ((resposta != "nao") && (resposta != "sim"));

        if (resposta == "nao")
        {
            throw VendaCancelada((char*)"Orcamento invalido!");
        }

        map<Produto *, int> produtos_por_qnt = orcamento_->getProdutos();
        Orcamento* novoOrcamento = new Orcamento(Data::dateNow(),Utility::randomCode(1000,10000) ,produtos_por_qnt);
        orcamento_ = novoOrcamento;
    }

    if (pagamento_->validaPagamento() == false)
    {
        char message[100] = "Erro no pagamento!";
        throw VendaCancelada(message);
    }

    map<Produto *, int> produtos = orcamento_->getProdutos();

    vector<string> lista_produtos_vector;
    // percorre o map de produtos de orcamento
    for (auto it = produtos.begin(); it != produtos.end(); it++)
    {
        Produto *produto = it->first;
        int quantidade_alvo = it->second;
        list<Lote *> lotes = produto->getLotesAtivos();
        for (auto itr = lotes.begin(); itr != lotes.end(); itr++)
        {
            int aux = 1;
            int inicial = (*itr)->getQuantidadeAtual();
            while ((*itr)->getQuantidadeAtual() > 0)
            {
                (*itr)->subQuantidadeAtual(aux);
                if (quantidade_alvo == 0)
                {
                    break;
                }
                quantidade_alvo--;
            }
            //--------------------------------
            info_antes += "Qtd Lote: " + to_string(inicial) + ";";
            info_depois += "Qtd Lote: " + to_string((*itr)->getQuantidadeAtual()) + ";";

            if ((*itr)->getQuantidadeAtual() == 0)
            {     

              info_antes += produto->getNome() + "->LotesInativos {";
                int tempaux = 0;     
                for (auto tempit = produto->getLotesInativos().begin(); tempit != produto->getLotesInativos().end(); tempit++){
                  info_antes += to_string(tempaux) + ":" + to_string((*tempit)->getNumLote()) + "; ";
                  tempaux++;
                }
                info_antes += "}; ";
                //-------------  
                  produto->addLoteInativo(*itr);
                //--------------
                info_depois += produto->getNome() + "->LotesInativos {";
                tempaux = 0;     
                for (auto tempit = produto->getLotesInativos().begin(); tempit != produto->getLotesInativos().end(); tempit++){
                  info_depois += to_string(tempaux) + ":" + to_string((*tempit)->getNumLote()) + "; ";
                  tempaux++;
                }
                info_depois += "}; ";



                info_antes += produto->getNome() + "->LotesAtivos {";
                tempaux = 0;     
                for (auto tempit = produto->getLotesAtivos().begin(); tempit != produto->getLotesAtivos().end(); tempit++){
                  info_antes += to_string(tempaux) + ":" + to_string((*tempit)->getNumLote()) + "; ";
                  tempaux++;
                }
                info_antes += "}; ";
                //-------------
                produto->removeLoteAtivo(*itr);                
                //--------------
                info_depois += produto->getNome() + "->LotesAtivos {";
                tempaux = 0;     
                for (auto tempit = produto->getLotesAtivos().begin(); tempit != produto->getLotesAtivos().end(); tempit++){
                  info_depois += to_string(tempaux) + ":" + to_string((*tempit)->getNumLote()) + "; ";
                  tempaux++;
                }
                info_depois += "}; ";

            }
            if (quantidade_alvo == 0)
            {
                break;
            }
        }
        string nome_produto = produto->getNome();
        lista_produtos_vector.push_back(nome_produto);              


    }

    Venda *venda = new Venda(Data::dateNow(), lista_produtos_vector);


    info_antes += "Venda: Vazio; ";
    //------------------
    venda_ = venda;
    //------------------
    info_depois += "Venda: " + to_string(venda_->getCodigo()) + "; ";
    
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

Venda* PedidoCompra::getVenda(){
  string entidade = "PedidoCompra_getVenda";
  string info_acessada = "venda_";
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  Data data = data.dateNow();
  if (loggedUser->ehPermitido(entidade))
  {
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    //-----------------------------------------------------------
    return venda_;
    //-----------------------------------------------------------
  }
  else
  {
    LogAcessoNegado* lognegado = new LogAcessoNegado(entidade, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
  
}

void PedidoCompra::printDados()
{
    cout << "--------- DADOS DA VENDA COD: " << codigo_ << " ---------" << endl;
    cout << "Status: " << status_ << endl;
    cout << "Cliente: " << cliente_ << endl;
    cout << "Data_pedido: " << data_pedido_.getData() << endl;
    cout << "Data_pagamento:" << (data_pagamento_ == Data()) ? "Nao definido-" : data_pagamento_.getData();
    cout << "\n---------------------------" << endl;
};
