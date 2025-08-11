#include "Lote.h"
#include <string>

using namespace std;

Lote::Lote(Data dataa, unsigned int num_lote, int qtd_produzida)
{
    Data data = data.dateNow();
    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Lote";
    
    if (loggedUser->ehPermitido("Lote_Lote"))
    {
        data_prod_ = dataa;
        num_lote_ = num_lote;
        qtd_produzida_ = qtd_produzida;
        qtd_atual_ = qtd_produzida;
        string info_antes = "Data Produçao: Vazio; Num Lote: Vazio; Qtd Produzida: Vazio; Qtd Atual: Vazio";
        string info_depois = "DataProducao: " + data_prod_.getData() + "; Num Lote: " + to_string(num_lote) + "; Qtd Produzida: " + "; Qtd Atual: " + to_string(qtd_atual_) + ";";
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

void Lote::subQuantidadeAtual(int &quantidade) { qtd_atual_ = qtd_atual_ - quantidade; }

unsigned int Lote::getNumLote()
{
    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Lote";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Lote_getNumLote"))
    {
        string info_acessada = "Numero Lote";
        LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
        logs->addLog(logleitura);
        return num_lote_;
    }
    else
    {
        string func_negada = "getNumLote";
        LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
       logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

Data Lote::getDataProd()
{
    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Lote";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Lote_getDataProd"))
    {
        string info_acessada = "Data Producao";
        LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
        logs->addLog(logleitura);
        return data_prod_;
    }
    else
    {
        string func_negada = "getDataProd";
        LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
       logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

float Lote::getQuantidadeProduzida()
{
    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Lote";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Lote_getQuantidadeProduzida"))
    {
        string info_acessada = "Quantidade Produzida";
        LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
        logs->addLog(logleitura);
        return qtd_produzida_;
    }
    else
    {
        string func_negada = "getQuantidadeProduzida";
        LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
       logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

int Lote::getQuantidadeAtual()
{
    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Lote";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Lote_getQuantidadeAtual"))
    {
        string info_acessada = "qtd_atual";
        LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
        logs->addLog(logleitura);
        return qtd_atual_;
    }
    else
    {
        string func_negada = "getQuantidadeAtual";
        LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
       logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}